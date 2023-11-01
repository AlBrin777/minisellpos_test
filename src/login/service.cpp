#include "service.hpp"

oatpp::Object<usuariosDto> loginService::authenticate(const oatpp::Object<usuariosDto>& dto){
     OATPP_LOGI("Servicio login", " Comprobando credenciales...'");
     auto dbResult = m_database->confirmUser(dto);
     OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
     auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
     OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
     OATPP_LOGI("Servicio login", "----------------->AUTENTICADO<---------------------'");
     return result[0];
}

oatpp::Object<usuariosDto> loginService::confirmToken(const oatpp::String& token, const oatpp::String& username){
     OATPP_LOGI("Servicio confirmar token", " Confirmando token...'");
     auto dbResult = m_database->confirmToken(token, username);
     OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
     auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
     OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
     OATPP_LOGI("Servicio confirmar token", "-------------->TOKEN CORRECTO<----------------'");
     return result[0];
}

oatpp::Object<usuariosDto> loginService::updateToken(const oatpp::String& username, const oatpp::String& actualToken){
     OATPP_LOGI("Servicio modificar token", " Modificando token...'");
     auto dbResult = m_database->updateToken(username, actualToken);
     OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
     auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
     OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
     OATPP_LOGI("Servicio modificar token", "-------------->TOKEN MODIFICADO<----------------'");
     return result[0];
}
oatpp::Object<usuariosDto> loginService::getUsernameByToken(const oatpp::String& token) {
  OATPP_LOGI("Servicio usuarios", " Buscando usuario por Token...");
  auto dbResult = m_database->getUsernameByToken(token->c_str());
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "usuario not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio usuarios", "--------------> Usuario encontrado <-----------------");
  return result[0];
}
