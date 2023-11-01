#ifndef negocio_service_hpp
#define negocio_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

#include "dto.hpp"

class negocioService {

private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<negocioDb>, m_database); // Inject database component
public:

  oatpp::Object<ListaProdVentaDto> createListaProdVenta(const oatpp::Object<ListaProdVentaDto>& dto);
  oatpp::Object<ListaProdVentaDto> updateListaProdVenta(const oatpp::Object<ListaProdVentaDto>& dto);
  oatpp::Object<ListaProdVentaDto> getListaProdVentaById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<ListaProdVentaDto>>> getAllListaProdVenta(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteListaProdVentaById(const oatpp::String& id);

  oatpp::Object<VentaDto> createVenta(const oatpp::Object<VentaDto>& dto);
  oatpp::Object<VentaDto> updateVenta(const oatpp::Object<VentaDto>& dto);
  oatpp::Object<VentaDto> getVentaById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<VentaDto>>> getAllVentas(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteVentaById(const oatpp::String& id);
};

#endif //negocio_service_hpp
