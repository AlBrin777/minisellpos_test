
#ifndef ServiceComponent_hpp
#define ServiceComponent_hpp

#include "../libs/ConfigDto.hpp"
#include "ErrorHandler.hpp"

#include "login/service.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"

//**************ADITIONAL**********************************//
#include "oatpp/web/server/interceptor/ResponseInterceptor.hpp"
#include "oatpp/web/server/interceptor/RequestInterceptor.hpp"
#include "oatpp/web/server/interceptor/AllowCorsGlobal.hpp"
// #include <iostream>
#include <sstream>
// #include <stdio.h>
//***********************************************************

//***************************START-MIDDLEWARE*************************//
class AuthMiddleware : public oatpp::web::server::interceptor::RequestInterceptor{
    private:
      loginService m_loginService;
    public:
      std::shared_ptr<OutgoingResponse> 
      intercept(const std::shared_ptr<IncomingRequest> &request) override
      {
          auto path = request->getStartingLine().path.toString();
          auto method = request->getStartingLine().method.toString();
          auto contexto = request->getConnection()->getInputStreamContext().getProperties().getAll();
          auto fullPath = method + " " + path;

          printf("\n");
          OATPP_LOGI("SE SOLICITO: " + fullPath + " DESDE", " %s", (contexto["peer_address"].getData()));
          auto x = contexto["peer_address"].getData();
          auto headers = request->getHeaders().getAll_Unsafe();
        if( (strcmp(path->c_str(), "/login") == 0) ||  (strcmp(path->c_str(), "/usuarios") == 0) ){
          OATPP_LOGI("PATH", " %s", path->c_str());
          OATPP_LOGI("RequestInterceptor", " _____Login condition___");
          return nullptr;
        }

        auto token = request->getHeader("Token");
        auto username = request->getHeader("User");
        if (token->c_str()!="" && username->c_str()!="") {
          OATPP_LOGI("PATH", " %s", path->c_str());
          OATPP_LOGI("TOKEN", " %s", token->c_str());
          OATPP_LOGI("USERNAME", " %s", username->c_str());

          auto confirmToken = m_loginService.confirmToken(token->c_str(), username->c_str());

          if(strcmp(confirmToken->token->c_str(), token->c_str())  == 0){
            return nullptr;
          }else{
            return false;
          }
        } else {
          return false;
        }
          

      }
};
//***************************END-MIDDLEWARE***************************//

//***************************START-responseInterceptor**************//
class responseInterceptor : public oatpp::web::server::interceptor::ResponseInterceptor{
  private:
    loginService m_loginService;
  public:
    std::shared_ptr<OutgoingResponse> intercept(const std::shared_ptr<IncomingRequest> &request, const std::shared_ptr<OutgoingResponse> &response) override
    {
        oatpp::String user = request->getHeader("user");
        response->putHeader("Access-Control-Allow-Headers", "User, Token'"); // checka si la peticion es de tipo options y envia esto... para permitir q se envien cabeceras extras
        auto contexto = request->getConnection()->getInputStreamContext().getProperties().getAll();
        OATPP_LOGI("SE HA RESPONDIDO A REMOTE_ADDRESS: ", "%s", (contexto["peer_address"].getData()));
        auto path = request->getStartingLine().path.toString();
        auto method = request->getStartingLine().method.toString();
        if( (strcmp(path->c_str(), "/login") == 0) ||  (strcmp(path->c_str(), "/usuarios") == 0) ){
          OATPP_LOGI("ResponseInterceptor", " _____Login condition___");
          return response;
        }
        auto token = request->getHeader("Token");
        auto username = m_loginService.getUsernameByToken(token->c_str());
        if (token->c_str()!="" && username->username->c_str()!="") {
            auto tokenUpdated = m_loginService.updateToken(username->username->c_str(), token->c_str());
            response->putOrReplaceHeader("User", username->username->c_str());
            response->putOrReplaceHeader("Token", tokenUpdated->token->c_str());
            auto newtoken = response->getHeader("Token");
            OATPP_LOGI("NUEVO TOKEN", " %s", newtoken->c_str());
            OATPP_LOGI("PETICIÓN", " _____FINALIZADA____");
            return response;
        } else {
          return false;
        }
    }
};
//***************************END-responseInterceptor****************//

class ServiceComponent {
public:
  
  /**
   *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)
  ([] {
    auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
    mapper->getSerializer()->getConfig()->useBeautifier = true;
    mapper->getSerializer()->getConfig()->escapeFlags = 0;
    return mapper;
  }());
  
  /**
   *  Create ConnectionProvider component which listens on the port
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)
  ([] 
  {
    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component
    return oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", config->port, oatpp::network::Address::IP_4}, true);
  }
  ());
  
  /**
   *  Create Router component
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)
  ([] 
  {
    return oatpp::web::server::HttpRouter::createShared();
  }
  ());
  
  /**
   *  Create ConnectionHandler component which uses Router component to route requests
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)
  ([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper); // get ObjectMapper component

    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    //******** ADD MIDDLEWARE TO SERVICE_COMPONENT *********//
    connectionHandler->addResponseInterceptor(std::make_shared<oatpp::web::server::interceptor::AllowCorsGlobal>("*", "GET, POST, PUT, DELETE, OPTIONS", "DNT, User-Agent, X-Requested-With, If-Modified-Since, Cache-Control, Content-Type, Range, Authorization, User, Token", "1728000"));
     
    // /*Add myResponseInterceptor */
    connectionHandler->addResponseInterceptor(std::make_shared<responseInterceptor>());
     
    // //******* ADDED MIDDLEWARE ************//
     connectionHandler->addRequestInterceptor(std::make_shared<AuthMiddleware>());
     //*****ADDED MIDDLEWARE************//

    connectionHandler->addRequestInterceptor(std::make_shared<oatpp::web::server::interceptor::AllowOptionsGlobal>());
    connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
   
    return connectionHandler;
  }());

};

#endif /* ServiceComponent_hpp */

// if( (strcmp(method->c_str(), "PUT")==0) && (strcmp(path->c_str(), "/usuarios")==0)  ){}
