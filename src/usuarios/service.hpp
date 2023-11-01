
#ifndef usuarios_service_hpp
#define usuarios_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"



class usuariosService {

private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<usuariosDb>, m_database); // Inject database component
public:

  oatpp::Object<usuariosDto> createusuarios(const oatpp::Object<usuariosDto>& dto);
  oatpp::Object<usuariosDto> updateusuarios(const oatpp::Object<usuariosDto>& dto);
  oatpp::Object<usuariosDto> getusuariosById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<usuariosDto>>> getAllusuarios(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteusuariosById(const oatpp::String& id);
};

#endif //usuarios_service_hpp
