#include "service.hpp"

oatpp::Object<ListaProdVentaDto> negocioService::createListaProdVenta(const oatpp::Object<ListaProdVentaDto>& dto) {
  OATPP_LOGI("Servicio negocio", " Creando lista_prod_venta...");
  auto dbResult = m_database->createListaProdVenta(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProdVentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> lista_prod_venta creado <-----------------");
  return result[0];
}

oatpp::Object<ListaProdVentaDto> negocioService::updateListaProdVenta(const oatpp::Object<ListaProdVentaDto>& dto) {
  OATPP_LOGI("Servicio negocio", " Modificando lista_prod_venta...");
  auto dbResult = m_database->updateListaProdVenta(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProdVentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> lista_prod_venta modificado <-----------------");
  return result[0];
}

oatpp::Object<ListaProdVentaDto> negocioService::getListaProdVentaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio negocio", " Buscando lista_prod_venta por ID...");
  auto dbResult = m_database->getListaProdVentaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "lista_prod_venta not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProdVentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> lista_prod_venta encontrado <-----------------");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<ListaProdVentaDto>>> negocioService::getAllListaProdVenta(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio negocio", " Consultando todas las lista_prod_venta...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllListaProdVenta(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProdVentaDto>>>();
  auto page = PageDto<oatpp::Object<ListaProdVentaDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio negocio", "--------------> lista_prod_venta encontrados: %d <-----------------", page->count);
  return page;
}

oatpp::Object<StatusDto> negocioService::deleteListaProdVentaById(const oatpp::String& listaProdVentaId) {
  OATPP_LOGI("Servicio negocio", " Eliminando lista_prod_venta...");
  auto dbResult = m_database->deleteListaProdVentaById(listaProdVentaId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "lista_prod_venta was successfully deleted";
  return status;
}

oatpp::Object<VentaDto> negocioService::createVenta(const oatpp::Object<VentaDto>& dto) {
  OATPP_LOGI("Servicio negocio", " Creando venta...");
  auto dbResult = m_database->createVenta(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<VentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> Venta creado <-----------------");
  return result[0];
}

oatpp::Object<VentaDto> negocioService::updateVenta(const oatpp::Object<VentaDto>& dto) {
  OATPP_LOGI("Servicio negocio", " Modificando venta...");
  auto dbResult = m_database->updateVenta(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<VentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> Venta modificado <-----------------");
  return result[0];
}

oatpp::Object<VentaDto> negocioService::getVentaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio negocio", " Buscando venta por ID...");
  auto dbResult = m_database->getVentaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "venta not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<VentaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio negocio", "--------------> Venta encontrado <-----------------");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<VentaDto>>> negocioService::getAllVentas(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio negocio", " Consultando todas las ventas...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllVentas(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<VentaDto>>>();
  auto page = PageDto<oatpp::Object<VentaDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio negocio", "--------------> Ventas encontradas: %d <-----------------", page->count);
  return page;
}

oatpp::Object<StatusDto> negocioService::deleteVentaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio negocio", " Eliminando venta...");
  auto dbResult = m_database->deleteVentaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "venta was successfully deleted";
  return status;
}

