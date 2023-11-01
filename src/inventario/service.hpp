#ifndef inventario_service_hpp
#define inventario_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class InventarioService {

private:
  typedef oatpp::web::protocol::http::Status Status;

private:
  OATPP_COMPONENT(std::shared_ptr<inventarioDb>, m_database); // Inject database component for "categoria" table

public:

  oatpp::Object<CategoriaDto> createCategoria(const oatpp::Object<CategoriaDto>& dto);
  oatpp::Object<CategoriaDto> updateCategoria(const oatpp::Object<CategoriaDto>& dto);
  oatpp::Object<CategoriaDto> getCategoriaById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<CategoriaDto>>> getAllCategorias(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteCategoriaById(const oatpp::String& id);

  oatpp::Object<ProductoDto> createProducto(const oatpp::Object<ProductoDto>& dto);
  oatpp::Object<ProductoDto> updateProducto(const oatpp::Object<ProductoDto>& dto);
  oatpp::Object<ProductoDto> getProductoById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<ProductoDto>>> getAllProductos(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteProductoById(const oatpp::String& id);

  oatpp::Object<ListaProductoDto> createListaProducto(const oatpp::Object<ListaProductoDto>& dto);
  oatpp::Object<ListaProductoDto> updateListaProducto(const oatpp::Object<ListaProductoDto>& dto);
  oatpp::Object<ListaProductoDto> getListaProductoById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<ListaProductoDto>>> getAllListaProductos(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteListaProductoById(const oatpp::String& id);

  oatpp::Object<InventarioDto> createInventario(const oatpp::Object<InventarioDto>& dto);
  oatpp::Object<InventarioDto> updateInventario(const oatpp::Object<InventarioDto>& dto);
  oatpp::Object<InventarioDto> getInventarioById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<InventarioDto>>> getAllInventario(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteInventarioById(const oatpp::String& id);

};

#endif // inventario_service_hpp