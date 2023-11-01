#ifndef InventarioDto_hpp
#define InventarioDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

// DTO para la categoría
class CategoriaDto : public oatpp::DTO {
  DTO_INIT(CategoriaDto, DTO)

  DTO_FIELD(String, id_category, "id_category");
  DTO_FIELD(String, name_category, "name_category");
  DTO_FIELD(String, metter_category, "metter_category");
};

// DTO para el producto
class ProductoDto : public oatpp::DTO {
  DTO_INIT(ProductoDto, DTO)

  DTO_FIELD(String, id_producto, "id_producto");
  DTO_FIELD(String, cat_producto, "cat_producto");
  DTO_FIELD(String, desc_producto, "desc_producto");
  DTO_FIELD(String, serial_producto, "serial_producto");
};

// DTO para la lista de productos
class ListaProductoDto : public oatpp::DTO {
  DTO_INIT(ListaProductoDto, DTO)

  DTO_FIELD(String,  id_lista_producto, "id_lista_producto");
  DTO_FIELD(String,  id_producto, "id_producto");
  DTO_FIELD(Float64, cantidad_producto, "cantidad_producto");
  DTO_FIELD(Float64, precio_total, "precio_total");
  DTO_FIELD(Float64, precio_unitario, "precio_unitario");
};

// DTO para el inventario
class InventarioDto : public oatpp::DTO {
  DTO_INIT(InventarioDto, DTO)

  DTO_FIELD(String, id_inventario, "id_inventario");
  DTO_FIELD(String, fecha_inventario, "fecha_inventario");
  DTO_FIELD(String, id_lista_producto, "id_lista_producto");
};

#include OATPP_CODEGEN_END(DTO)

#endif /* InventarioDto_hpp */