//#include "oatpp/web/server/handler/ErrorHandler.hpp"
#include "oatpp/web/protocol/http/outgoing/ResponseFactory.hpp"
//#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/interceptor/RequestInterceptor.hpp"
//#include "oatpp/core/Types.hpp"
//#include "oatpp/web/protocol/http/Http.hpp"

using namespace oatpp;

class AuthenticationMiddleware : public oatpp::web::server::interceptor::RequestInterceptor {
public:
  typedef oatpp::web::protocol::http::Status Status;
  typedef oatpp::web::protocol::http::outgoing::ResponseFactory resfact;

  std::shared_ptr<OutgoingResponse> intercept(const std::shared_ptr<IncomingRequest>& request) override {
    const auto authorizationHeader = request->getHeader(oatpp::web::protocol::http::Header::AUTHORIZATION);
    // Verificar si el usuario está autenticado
    if (!isAuthenticated(request)) {
      // Si el usuario no está autenticado, redirigirlo a la página de inicio de sesión
      auto response = resfact::createResponse(Status::CODE_302, "Redirecting to login page");
      response->putHeader("LOCATION", "/login");
      return response;
    } else {
      // Si el usuario está autenticado, continuar con la solicitud
      return oatpp::web::server::interceptor::RequestInterceptor::intercept(request);
    }
  }

private:
  bool isAuthenticated(const std::shared_ptr<IncomingRequest>& request) {
    // Aquí deberías implementar la lógica para verificar si el usuario está autenticado
    // Por ejemplo, podrías verificar si el token de autenticación se encuentra en el encabezado "Authorization" de la solicitud
    auto authHeader = request->getHeader(oatpp::web::protocol::http::Header::AUTHORIZATION);
    if (authHeader && authHeader->find("Bearer ") == 0) {
      auto token = authHeader->substr(7);
      // Aquí deberías verificar si el token es válido y corresponde a un usuario autenticado
      // Si el token es válido, retorna verdadero
      // Si el token no es válido, retorna falso
      return true;
    } else {
      return false;
    }
  }
};