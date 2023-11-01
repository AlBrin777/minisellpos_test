
#ifndef login_service_hpp
#define login_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/server/interceptor/RequestInterceptor.hpp"



class loginService {

private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<LoginDb>, m_database); // Inject database component
public:
  oatpp::Object<usuariosDto> authenticate(const oatpp::Object<usuariosDto>& dto);
  oatpp::Object<usuariosDto> confirmToken(const oatpp::String& token, const oatpp::String& username);
  oatpp::Object<usuariosDto> updateToken(const oatpp::String& username, const oatpp::String& token);
  oatpp::Object<usuariosDto> getUsernameByToken(const oatpp::String& token);
};

#endif //login_service_hpp
