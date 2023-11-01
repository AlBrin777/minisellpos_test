#ifndef perfilesController_hpp
#define perfilesController_hpp

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * perfiles REST controller.
 */
class perfilesController : public oatpp::web::server::api::ApiController {
public:
  perfilesController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  perfilesService m_perfilesService; // Creamos el servicio de perfiles.
public:

  static std::shared_ptr<perfilesController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inyectamos el componente objectMapper aquí como parámetro predeterminado
  ){
    return std::make_shared<perfilesController>(objectMapper);
  }
  
  ENDPOINT_INFO(createCliente) {
    info->summary = "Crear nuevo cliente";

    info->addConsumes<Object<clienteDto>>("application/json");

    info->addResponse<Object<clienteDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "perfiles/cliente", createCliente,
           BODY_DTO(Object<clienteDto>, ClienteDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.createCliente(ClienteDto));
  }
  
  
  ENDPOINT_INFO(putCliente) {
    info->summary = "Actualizar cliente por identificador de cliente";

    info->addConsumes<Object<clienteDto>>("application/json");

    info->addResponse<Object<clienteDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_cliente"].description = "Identificador de cliente";
  }
  ENDPOINT("PUT", "perfiles/cliente", putCliente,
           BODY_DTO(Object<clienteDto>, ClienteDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.updateCliente(ClienteDto));
  }
  
  
  ENDPOINT_INFO(getClienteById) {
    info->summary = "Obtener un cliente por identificador de cliente";

    info->addResponse<Object<clienteDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_cliente"].description = "Identificador de cliente";
  }
  ENDPOINT("GET", "perfiles/cliente/{id_cliente}", getClienteById,
           PATH(String, id_cliente))
  {  
    return createDtoResponse(Status::CODE_200, m_perfilesService.getClienteById(id_cliente));
  }
  
  
  ENDPOINT_INFO(getClientes) {
    info->summary = "Obtener todos los clientes almacenados";

    info->addResponse<oatpp::Object<clientePageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "perfiles/cliente/offset/{offset}/limit/{limit}", getClientes,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.getAllClientes(offset, limit));
  }
  
  
  ENDPOINT_INFO(deleteCliente) {
    info->summary = "Eliminar cliente por identificador de cliente";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_cliente"].description = "Identificador de cliente";
  }
  ENDPOINT("DELETE", "perfiles/cliente/{id_cliente}", deleteCliente,
           PATH(String, id_cliente))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.deleteClienteById(id_cliente));
  }
  
  // Repetimos las mismas operaciones para los perfiles de empresa y proveedor:

  // Operaciones para perfiles de empresa
  
  ENDPOINT_INFO(createEmpresa) {
    info->summary = "Crear nueva empresa";

    info->addConsumes<Object<empresaDto>>("application/json");

    info->addResponse<Object<empresaDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "perfiles/empresa", createEmpresa,
           BODY_DTO(Object<empresaDto>, EmpresaDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.createEmpresa(EmpresaDto));
  }
  
  
  ENDPOINT_INFO(putEmpresa) {
    info->summary = "Actualizar empresa por identificador de empresa";

    info->addConsumes<Object<empresaDto>>("application/json");

    info->addResponse<Object<empresaDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_empresa"].description = "Identificador de empresa";
  }
  ENDPOINT("PUT", "perfiles/empresa", putEmpresa,
           BODY_DTO(Object<empresaDto>, EmpresaDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.updateEmpresa(EmpresaDto));
  }
  
  
  ENDPOINT_INFO(getEmpresaById) {
    info->summary = "Obtener una empresa por identificador de empresa";

    info->addResponse<Object<empresaDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_empresa"].description = "Identificador de empresa";
  }
  ENDPOINT("GET", "perfiles/empresa/{id_empresa}", getEmpresaById,
           PATH(String, id_empresa))
  {  
    return createDtoResponse(Status::CODE_200, m_perfilesService.getEmpresaById(id_empresa));
  }
  
  
  ENDPOINT_INFO(getEmpresas) {
    info->summary = "Obtener todas las empresas almacenadas";

    info->addResponse<oatpp::Object<empresaPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "perfiles/empresa/offset/{offset}/limit/{limit}", getEmpresas,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.getAllEmpresas(offset, limit));
  }
  
  
  ENDPOINT_INFO(deleteEmpresa) {
    info->summary = "Eliminar empresa por identificador de empresa";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_empresa"].description = "Identificador de empresa";
  }
  ENDPOINT("DELETE", "perfiles/empresa/{id_empresa}", deleteEmpresa,
           PATH(String, id_empresa))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.deleteEmpresaById(id_empresa));
  }
  
  // Operaciones para perfiles de proveedor
  
  ENDPOINT_INFO(createProveedor) {
    info->summary = "Crear nuevo proveedor";

    info->addConsumes<Object<proveedorDto>>("application/json");

    info->addResponse<Object<proveedorDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "perfiles/proveedor", createProveedor,
           BODY_DTO(Object<proveedorDto>, ProveedorDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.createProveedor(ProveedorDto));
  }
  
  ENDPOINT("PUT", "perfiles/proveedor", putProveedor,
           BODY_DTO(Object<proveedorDto>, ProveedorDto))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.updateProveedor(ProveedorDto));
  }
  
  
  ENDPOINT_INFO(getProveedorById) {
    info->summary = "Obtener un proveedor por identificador de proveedor";

    info->addResponse<Object<proveedorDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_proveedor"].description = "Identificador de proveedor";
  }
  ENDPOINT("GET", "perfiles/proveedor/{id_proveedor}", getProveedorById,
           PATH(String, id_proveedor))
  {  
    return createDtoResponse(Status::CODE_200, m_perfilesService.getProveedorById(id_proveedor));
  }
  
  
  ENDPOINT_INFO(getProveedores) {
    info->summary = "Obtener todos los proveedores almacenados";

    info->addResponse<oatpp::Object<proveedorPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "perfiles/proveedor/offset/{offset}/limit/{limit}", getProveedores,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.getAllProveedores(offset, limit));
  }
  
  
  ENDPOINT_INFO(deleteProveedor) {
    info->summary = "Eliminar proveedor por identificador de proveedor";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["id_proveedor"].description = "Identificador de proveedor";
  }
  ENDPOINT("DELETE", "perfiles/proveedor/{id_proveedor}", deleteProveedor,
           PATH(String, id_proveedor))
  {
    return createDtoResponse(Status::CODE_200, m_perfilesService.deleteProveedorById(id_proveedor));
  }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* perfilesController_hpp */