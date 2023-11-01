
#ifndef loginController_hpp
#define loginController_hpp
#include <string>
#include <sstream>
#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"
// #include "oatpp/web/server/interceptor/RequestInterceptor.hpp"
 #include "oatpp/web/server/handler/AuthorizationHandler.hpp"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * login REST controller.
 */

class loginController : public oatpp::web::server::api::ApiController {
public:
  
  loginController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {

  }
private:
  loginService m_loginService; // Create login service.
public:

  static std::shared_ptr<loginController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<loginController>(objectMapper);
  }
  
  ENDPOINT("POST", "login", login,
    BODY_DTO(Object<usuariosDto>, loginInfo)) 
  {
    auto result = m_loginService.authenticate(loginInfo);
    auto response = createDtoResponse(Status::CODE_200, result);
    response->putOrReplaceHeader("User", result->username);
    response->putOrReplaceHeader("Token", result->token);
    return response;
  }

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen



#endif /* loginController_hpp */
