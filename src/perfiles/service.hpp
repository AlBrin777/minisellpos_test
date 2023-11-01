#ifndef perfiles_service_hpp
#define perfiles_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"



class perfilesService {

private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<perfilesDb>, m_database); // Inyectar componente de la base de datos
public:

  oatpp::Object<clienteDto> createCliente(const oatpp::Object<clienteDto>& dto);
  oatpp::Object<clienteDto> updateCliente(const oatpp::Object<clienteDto>& dto);
  oatpp::Object<clienteDto> getClienteById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<clienteDto>>> getAllClientes(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteClienteById(const oatpp::String& id);


  oatpp::Object<empresaDto> createEmpresa(const oatpp::Object<empresaDto>& dto);
  oatpp::Object<empresaDto> updateEmpresa(const oatpp::Object<empresaDto>& dto);
  oatpp::Object<empresaDto> getEmpresaById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<empresaDto>>> getAllEmpresas(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteEmpresaById(const oatpp::String& id);


  oatpp::Object<proveedorDto> createProveedor(const oatpp::Object<proveedorDto>& dto);
  oatpp::Object<proveedorDto> updateProveedor(const oatpp::Object<proveedorDto>& dto);
  oatpp::Object<proveedorDto> getProveedorById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<proveedorDto>>> getAllProveedores(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteProveedorById(const oatpp::String& id);

};

#endif //perfiles_service_hpp