#include "service.hpp"

oatpp::Object<clienteDto> perfilesService::createCliente(const oatpp::Object<clienteDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Creando cliente...");
  auto dbResult = m_database->createCliente(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<clienteDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Cliente creado <-----------------");
  return result[0];
}

oatpp::Object<clienteDto> perfilesService::updateCliente(const oatpp::Object<clienteDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Modificando cliente...");
  auto dbResult = m_database->updateCliente(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<clienteDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Cliente modificado <-----------------");
  return result[0];
}

oatpp::Object<clienteDto> perfilesService::getClienteById(const oatpp::String& id) {
  OATPP_LOGI("Servicio perfiles", " Buscando cliente por ID...");
  auto dbResult = m_database->getClienteById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Cliente no encontrado");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<clienteDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Cliente encontrado <-----------------");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<clienteDto>>> perfilesService::getAllClientes(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio perfiles", " Consultando todos los clientes...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllClientes(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<clienteDto>>>();
  auto page = PageDto<oatpp::Object<clienteDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio perfiles", "--------------> Clientes encontrados: %d <-----------------", items->size());
  return page;
}

oatpp::Object<StatusDto> perfilesService::deleteClienteById(const oatpp::String& id) {
  OATPP_LOGI("Servicio perfiles", " Eliminando cliente...");
  auto dbResult = m_database->deleteClienteById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Cliente eliminado exitosamente";
  return status;
}


oatpp::Object<empresaDto> perfilesService::createEmpresa(const oatpp::Object<empresaDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Creando empresa...");
  auto dbResult = m_database->createEmpresa(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<empresaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Empresa creada <-----------------");
  return result[0];
}

oatpp::Object<empresaDto> perfilesService::updateEmpresa(const oatpp::Object<empresaDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Modificando empresa...");
  auto dbResult = m_database->updateEmpresa(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<empresaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Empresa modificada <-----------------");
  return result[0];
}

oatpp::Object<empresaDto> perfilesService::getEmpresaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio perfiles", " Buscando empresa por ID...");
  auto dbResult = m_database->getEmpresaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Empresa no encontrada");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<empresaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Empresa encontrada <-----------------");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<empresaDto>>> perfilesService::getAllEmpresas(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio perfiles", " Consultando todas las empresas...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllEmpresas(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<empresaDto>>>();
  auto page = PageDto<oatpp::Object<empresaDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio perfiles", "--------------> Empresas encontradas: %d <-----------------", items->size());
  return page;
}

oatpp::Object<StatusDto> perfilesService::deleteEmpresaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio perfiles", " Eliminando empresa...");
  auto dbResult = m_database->deleteEmpresaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Empresa eliminada exitosamente";
  return status;
}


oatpp::Object<proveedorDto> perfilesService::createProveedor(const oatpp::Object<proveedorDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Creando proveedor...");
  auto dbResult = m_database->createProveedor(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<proveedorDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio perfiles", "--------------> Proveedor creado <-----------------");
  return result[0];
}

oatpp::Object<proveedorDto> perfilesService::updateProveedor(const oatpp::Object<proveedorDto>& dto) {
  OATPP_LOGI("Servicio perfiles", " Modificando proveedor...");
  auto dbResult = m_database->updateProveedor(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<proveedorDto>>>();
OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
OATPP_LOGI("Servicio perfiles", "--------------> Proveedor modificado <-----------------");
return result[0];
}

oatpp::Object<proveedorDto> perfilesService::getProveedorById(const oatpp::String& id) {
OATPP_LOGI("Servicio perfiles", " Buscando proveedor por ID...");
auto dbResult = m_database->getProveedorById(id);
OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Proveedor no encontrado");
auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<proveedorDto>>>();
OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
OATPP_LOGI("Servicio perfiles", "--------------> Proveedor encontrado <-----------------");
return result[0];
}

oatpp::Object<PageDto<oatpp::Object<proveedorDto>>> perfilesService::getAllProveedores(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
OATPP_LOGI("Servicio perfiles", " Consultando todos los proveedores...");
oatpp::UInt32 countToFetch = limit;
if(limit > 10) {
countToFetch = 10;
}
auto dbResult = m_database->getAllProveedores(offset, countToFetch);
OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<proveedorDto>>>();
auto page = PageDto<oatpp::Object<proveedorDto>>::createShared();
page->offset = offset;
page->limit = countToFetch;
page->count = items->size();
page->items = items;
OATPP_LOGI("Servicio perfiles", "--------------> Proveedores encontrados: %d <-----------------", items->size());
return page;
}

oatpp::Object<StatusDto> perfilesService::deleteProveedorById(const oatpp::String& id) {
OATPP_LOGI("Servicio perfiles", " Eliminando proveedor...");
auto dbResult = m_database->deleteProveedorById(id);
OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
auto status = StatusDto::createShared();
status->status = "OK";
status->code = 200;
status->message = "Proveedor eliminado exitosamente";
return status;
}