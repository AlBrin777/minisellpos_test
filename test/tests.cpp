
#include "oatpp-test/UnitTest.hpp"
#include <iostream>

namespace {

class Test : public oatpp::test::UnitTest {
public:
  Test() : oatpp::test::UnitTest("[MyTest]")
  {}

  void onRun() override {
    OATPP_LOGD(TAG, "Hello Test");
    // TODO write correct  tests
  }
};

void runTests() {
  OATPP_RUN_TEST(Test);
}

}

int main() {

  oatpp::base::Environment::init();

  runTests();

  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::base::Environment::getObjectsCount() == 0);

  oatpp::base::Environment::destroy();

  return 0;
}

  // ENDPOINT("GET", "testEP", getResource,
  //          AUTHORIZATION(std::shared_ptr<oatpp::web::server::handler::DefaultBasicAuthorizationObject>, authObject, m_basicAuthHandler)) 
  // {
  //   authObject->userId = "lodfa";
  //   authObject->password = "1234";
  //   OATPP_ASSERT_HTTP(authObject->userId=="lodfa" && authObject->password == "1234", Status::CODE_401, "Unauthorized");
  //   return createResponse(Status::CODE_200, "OK");
  // }

  //   ENDPOINT("GET", "testEPone", getBearerAuthResource,
  //          AUTHORIZATION(std::shared_ptr<oatpp::web::server::handler::DefaultBearerAuthorizationObject>, authObject, m_bearerAuthHandler /* qualifier */)) 
  // {
  //   authObject->token ="1111";
  //   OATPP_ASSERT_HTTP(authObject->token == "1111", Status::CODE_401, "Unauthorized");
  //   return createResponse(Status::CODE_200, "OK");
  // }
  
  //   ENDPOINT("POST", "testEPtwo", getBearerAuthResourceTwo,
  //          BODY_DTO(Object<usuariosDto>, user),
  //          AUTHORIZATION(std::shared_ptr<oatpp::web::server::handler::DefaultBearerAuthorizationObject>, authObject, m_bearerAuthHandler /* qualifier */)) 
  // {
  //   auto token = m_loginService.getToken(user->token);
  //   std::ostringstream tokenStr;
  //   tokenStr << token->token->c_str();
  //   OATPP_ASSERT_HTTP(authObject->token == tokenStr.str(), Status::CODE_401, "Unauthorized");
  //   return createResponse(Status::CODE_200, "OK");
  // }
  
// #ifndef loginController_hpp
// #define loginController_hpp
// #include <string>
// #include <sstream>
// #include "service.hpp"

// #include "oatpp/web/server/api/ApiController.hpp"
// #include "oatpp/parser/json/mapping/ObjectMapper.hpp"
// #include "oatpp/core/macro/codegen.hpp"
// // #include "oatpp/web/server/interceptor/RequestInterceptor.hpp"
//  #include "oatpp/web/server/handler/AuthorizationHandler.hpp"
// //using namespace oatpp::web::server::handler;
// #include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
// /**
//  * login REST controller.
//  */

// class loginController : public oatpp::web::server::api::ApiController {
// public:
  
//   loginController(const std::shared_ptr<ObjectMapper>& objectMapper)
//     : oatpp::web::server::api::ApiController(objectMapper)
//   {

//   }
// private:
//   std::shared_ptr<AuthorizationHandler> m_basicAuthHandler = std::make_shared<oatpp::web::server::handler::BasicAuthorizationHandler>("my-realm");
//   std::shared_ptr<AuthorizationHandler> m_bearerAuthHandler = std::make_shared<oatpp::web::server::handler::BearerAuthorizationHandler>("my-realm");
//   loginService m_loginService; // Create login service.
// public:

//   static std::shared_ptr<loginController> createShared(
//     OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
//   ){
//     return std::make_shared<loginController>(objectMapper);
//   }
  
//   ENDPOINT("POST", "login", login,
//     BODY_DTO(Object<usuariosDto>, loginInfo)) 
//   {
//     return createDtoResponse(Status::CODE_200, m_loginService.authenticate(loginInfo));
//   }

// };


// #include OATPP_CODEGEN_END(ApiController) //<- End Codegen



// #endif /* loginController_hpp */
