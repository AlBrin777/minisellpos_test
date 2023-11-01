
#include "service.hpp"

oatpp::Object<usuariosDto> usuariosService::createusuarios(const oatpp::Object<usuariosDto>& dto) {
  OATPP_LOGI("Servicio usuarios", " Creando usuario...");
  auto dbResult = m_database->createusuarios(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio usuarios", "--------------> Usuario creado <-----------------");
  return result[0];

}

oatpp::Object<usuariosDto> usuariosService::updateusuarios(const oatpp::Object<usuariosDto>& dto) {
  OATPP_LOGI("Servicio usuarios", " Modificando usuario...");
  auto dbResult = m_database->updateusuarios(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio usuarios", "--------------> Usuario modificado <-----------------");

  return result[0];

}

oatpp::Object<usuariosDto> usuariosService::getusuariosById(const oatpp::String& id) {
  OATPP_LOGI("Servicio usuarios", " Buscando usuario por ID...");
  auto dbResult = m_database->getusuariosById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "usuarios not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio usuarios", "--------------> Usuario encontrado <-----------------");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<usuariosDto>>> usuariosService::getAllusuarios(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio usuarios", " Consultando todos los usuarios...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllusuarios(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<usuariosDto>>>();
  auto page = PageDto<oatpp::Object<usuariosDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio usuarios", "--------------> Usuarios encontrados: %d <-----------------", page->count);
  return page;
}

oatpp::Object<StatusDto> usuariosService::deleteusuariosById(const oatpp::String& usuariosId) {
  OATPP_LOGI("Servicio usuarios", " Eliminando usuario...");
  auto dbResult = m_database->deleteusuariosById(usuariosId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "usuarios was successfully deleted";
  return status;
}
  // for (int i = 0; i < items->size(); i++)
  // {
  //   items[i]->dtoCliente = clienServi.getClienteById(items[i]->id_cliente);
  //   items[i]->dtoProducto = produServi.getProductoById(items[i]->id_producto);
  // }