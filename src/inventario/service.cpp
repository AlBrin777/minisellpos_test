#include "service.hpp"

// Implementación de funciones para Categoria
oatpp::Object<CategoriaDto> InventarioService::createCategoria(const oatpp::Object<CategoriaDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Creando categoria...");
  auto dbResult = m_database->createCategoria(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<CategoriaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Categoria creada___");
  return result[0];
}

oatpp::Object<CategoriaDto> InventarioService::updateCategoria(const oatpp::Object<CategoriaDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Modificando categoria...");
  auto dbResult = m_database->updateCategoria(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<CategoriaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Categoria Modificada___");
  return result[0];
}

oatpp::Object<CategoriaDto> InventarioService::getCategoriaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Buscando categoria por ID...");
  auto dbResult = m_database->getCategoriaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "usuarios not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<CategoriaDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Categoria encontrada___");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<CategoriaDto>>> InventarioService::getAllCategorias(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio Inventario", "Listando categorias...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllCategorias(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<CategoriaDto>>>();
  auto page = PageDto<oatpp::Object<CategoriaDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio Inventario", "___Categorias listada___");
  return page;
}

oatpp::Object<StatusDto> InventarioService::deleteCategoriaById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Eliminando categoria por ID...");
  auto dbResult = m_database->deleteCategoriaById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Categorias was successfuly deleted";
  OATPP_LOGI("Servicio Inventario", "___Continua eliminada___");
  return status;
}

// Implementación de funciones para Producto
oatpp::Object<ProductoDto> InventarioService::createProducto(const oatpp::Object<ProductoDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Creando producto...");
  auto dbResult = m_database->createProducto(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Producto creado___");
  return result[0];
}

oatpp::Object<ProductoDto> InventarioService::updateProducto(const oatpp::Object<ProductoDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Modificando producto...");
  auto dbResult = m_database->updateProducto(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Producto modificado___");
  return result[0];
}

oatpp::Object<ProductoDto> InventarioService::getProductoById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Buscando producto por ID...");
  auto dbResult = m_database->getProductoById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "producto not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Producto encontrado___");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<ProductoDto>>> InventarioService::getAllProductos(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio Inventario", "Listando productos...");
  oatpp::UInt32 countToFetch = limit;
  if(limit > 10) {
    countToFetch = 10;
  }
  auto dbResult = m_database->getAllProductos(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ProductoDto>>>();
  auto page = PageDto<oatpp::Object<ProductoDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio Inventario", "___Productos listados___");
  return page;
}

oatpp::Object<StatusDto> InventarioService::deleteProductoById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Eliminando producto por ID...");
  auto dbResult = m_database->deleteProductoById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Producto was successfuly deleted";
  OATPP_LOGI("Servicio Inventario", "___Producto eliminado___");
  return status;
}

// Implementación de funciones para lista de productos
oatpp::Object<ListaProductoDto> InventarioService::createListaProducto(const oatpp::Object<ListaProductoDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Creando lista de productos...");
  auto dbResult = m_database->createListaProducto(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Lista de productos creada___");
  return result[0];
}

oatpp::Object<ListaProductoDto> InventarioService::updateListaProducto(const oatpp::Object<ListaProductoDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Modificando lista de productos...");
  auto dbResult = m_database->updateListaProducto(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Lista de productos modificada___");
  return result[0];
}

oatpp::Object<ListaProductoDto> InventarioService::getListaProductoById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Buscando lista de productos por ID...");
  auto dbResult = m_database->getListaProductoById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "lista de productos not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProductoDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Lista de productos encontrada___");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<ListaProductoDto>>> InventarioService::getAllListaProductos(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio Inventario", "Listando listas de productos...");
  auto dbResult = m_database->getAllListaProductos(offset, limit);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ListaProductoDto>>>();
  auto page = PageDto<oatpp::Object<ListaProductoDto>>::createShared();
  page->offset = offset;
  page->limit = limit;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio Inventario", "___Listas de productos listadas___");
  return page;
}

oatpp::Object<StatusDto> InventarioService::deleteListaProductoById(const oatpp::String& id) {
  OATPP_LOGI("Servicio Inventario", "Eliminando lista de productos por ID...");
  auto dbResult = m_database->deleteListaProductoById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Lista de productos was successfuly deleted";
  OATPP_LOGI("Servicio Inventario", "___Lista de productos eliminada___");
  return status;
}

// Implementación de funciones para informe de inventario
oatpp::Object<InventarioDto> InventarioService::createInventario(const oatpp::Object<InventarioDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Creando reporte de Inventario...");
  auto dbResult = m_database->createInventario(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<InventarioDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "___Reporte de Inventario Creado___");
  return result[0];
}

oatpp::Object<InventarioDto> InventarioService::updateInventario(const oatpp::Object<InventarioDto>& dto) {
  OATPP_LOGI("Servicio Inventario", "Modificando reporte de Inventario...");
  auto dbResult = m_database->updateInventario(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<InventarioDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  OATPP_LOGI("Servicio Inventario", "____Reporte de Inventario Modificado___");
  return result[0];
}

oatpp::Object<InventarioDto> InventarioService::getInventarioById(const oatpp::String& id){
  OATPP_LOGI("Servicio Inventario", "Buscando reporte de Inventariopor ID");
  auto dbResult = m_database->getInventarioById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Reporte de Inventario Not Found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<InventarioDto>>>();
  OATPP_LOGI("Servicio Inventario", "____ Reporte de Inventario Encontrado____");
  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<InventarioDto>>> InventarioService::getAllInventario(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  OATPP_LOGI("Servicio Inventario", "Listando reportes de Inventario...");
  auto dbResult = m_database->getAllInventarios(offset, limit);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<InventarioDto>>>();
  auto page = PageDto<oatpp::Object<InventarioDto>>::createShared();
  oatpp::UInt32 countToFetch = limit;
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;
  OATPP_LOGI("Servicio Inventario", "___Reportes de Inventario Listado___");
  return page;
}

oatpp::Object<StatusDto> InventarioService::deleteInventarioById(const oatpp::String& id){
  OATPP_LOGI("Servicio inventario", "Eliminando Reporte de Inventario...");
  auto dbResult = m_database->deleteInventarioById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Reporte de inventario was successfuly deleted";
  OATPP_LOGI("Servicio inventario", "___Reporte de Inventario Eliminado___");
  return status;
}