#ifndef inventario_db_hpp
#define inventario_db_hpp

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

/**
 * inventarioDb client definitions.
 */
class inventarioDb : public oatpp::orm::DbClient {
public:

  inventarioDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }

  QUERY(createCategoria,
        "INSERT INTO categoria"
        "(id_category, name_category, metter_category) VALUES "
        "(uuid_generate_v4(), :category.name_category, :category.metter_category)"
        "RETURNING "
        "name_category, "
        "metter_category "
        ";",
        PREPARE(true),
        PARAM(oatpp::Object<CategoriaDto>, category))

  QUERY(createProducto,
        "INSERT INTO public.producto(id_producto, cat_producto, desc_producto, serial_producto) VALUES(uuid_generate_v4(), :product.cat_producto, :product.desc_producto, :product.serial_producto);",
        PREPARE(true),
        PARAM(oatpp::Object<ProductoDto>, product))

  QUERY(createListaProducto,
        "INSERT INTO lista_producto"
        "(id_lista_producto, id_producto, cantidad_producto, precio_total, precio_unitario) VALUES "
        "(uuid_generate_v4(), :list.id_producto, :list.cantidad_producto, :list.precio_total, :list.precio_unitario)"
        "RETURNING "
        "id_lista_producto, "
        "id_producto, "
        "CAST(cantidad_producto AS REAL), "
        "CAST(precio_unitario AS REAL), "
        "CAST(precio_total AS REAL)"
        ";",
        PREPARE(true),
        PARAM(oatpp::Object<ListaProductoDto>, list))

  QUERY(createInventario,
        "INSERT INTO inventario"
        "(id_inventario, fecha_inventario, id_lista_producto) VALUES "
        "(uuid_generate_v4(), :inv.fecha_inventario, :inv.id_lista_producto)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<InventarioDto>, inv))

  QUERY(updateCategoria,
        "UPDATE categoria "
        "SET "
        "name_category=:category.name_category, "
        "metter_category=:category.metter_category "
        "WHERE "
        " id_category=category.id_category "
        "RETURNING "
        "name_category, "
        "CAST(metter_category AS REAL)"
        ";",
        PREPARE(true),
        PARAM(oatpp::Object<CategoriaDto>, category))

  QUERY(updateProducto,
        "UPDATE producto "
        "SET "
        "serial_producto=:product.serial_producto, "
        "cat_producto=:product.cat_producto, "
        "desc_producto=:product.desc_producto "
        "WHERE "
        "id_producto=product.id_producto "
        "RETURNING "
        "CAST(serial_producto AS INTEGER),"
        "cat_producto,"
        "desc_producto "
        ";",
        PREPARE(true),
        PARAM(oatpp::Object<ProductoDto>, product))

  QUERY(updateListaProducto,
        "UPDATE lista_producto "
        "SET "
        "cantidad_producto=:list.cantidad_producto, "
        "precio_unitario=:list.precio_unitario, "
        "precio_total=:list.precio_total "
        "WHERE "
        " id_lista_producto=list.id_lista_producto "
        "RETURNING "
        "CAST(cantidad_producto AS REAL), "
        "CAST(precio_unitario AS REAL), "
        "CAST(precio_total AS REAL)"
        ";",
        PREPARE(true),
        PARAM(oatpp::Object<ListaProductoDto>, list))

  QUERY(updateInventario,
        "UPDATE inventario "
        "SET "
        "fecha_inventario=:inv.fecha_inventario, "
        "id_lista_producto=:inv.id_lista_producto "
        "WHERE "
        " id_inventario=inv.id_inventario "
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<InventarioDto>, inv))

  QUERY(getCategoriaById,
        "SELECT id_category, name_category, metter_category FROM categoria WHERE id_category=:id_category;",
        PREPARE(true),
        PARAM(oatpp::String, id_category))

  QUERY(getProductoById,
        "SELECT id_producto, serial_producto, cat_producto, desc_producto FROM producto WHERE id_producto=:id_producto;",
        PREPARE(true),
        PARAM(oatpp::String, id_producto))

  QUERY(getListaProductoById,
        "SELECT id_lista_producto, id_producto, cantidad_producto, precio_total, precio_unitario FROM lista_producto WHERE id_lista_producto=:id_lista_producto;",
        PREPARE(true),
        PARAM(oatpp::String, id_lista_producto))

  QUERY(getInventarioById,
        "SELECT id_inventario, fecha_inventario, id_lista_producto FROM inventario WHERE id_inventario=:id_inventario;",
        PREPARE(true),
        PARAM(oatpp::String, id_inventario))

  QUERY(getAllCategorias,
        "SELECT id_category, name_category, metter_category FROM categoria LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getAllProductos,
        "SELECT id_producto, serial_producto, cat_producto, desc_producto FROM producto LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getAllListaProductos,
        "SELECT "
        "id_lista_producto, "
        "id_producto, "
        "CAST(cantidad_producto AS REAL), "
        "CAST(precio_total AS REAL), "
        "CAST(precio_unitario AS REAL)"
        " FROM public.lista_producto LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getAllInventarios,
        "SELECT id_inventario, fecha_inventario, id_lista_producto FROM inventario LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteCategoriaById,
        "DELETE FROM categoria WHERE id_category=:id_category;",
        PREPARE(true),
        PARAM(oatpp::String, id_category))

  QUERY(deleteProductoById,
        "DELETE FROM producto WHERE id_producto=:id_producto;",
        PREPARE(true),
        PARAM(oatpp::String, id_producto))

  QUERY(deleteListaProductoById,
        "DELETE FROM lista_producto WHERE id_lista_producto=:id_lista_producto;",
        PREPARE(true),
        PARAM(oatpp::String, id_lista_producto))

  QUERY(deleteInventarioById,
        "DELETE FROM inventario WHERE id_inventario=:id_inventario;",
        PREPARE(true),
        PARAM(oatpp::String, id_inventario))
};

#include OATPP_CODEGEN_END(DbClient)

#endif /* inventario_db_hpp */