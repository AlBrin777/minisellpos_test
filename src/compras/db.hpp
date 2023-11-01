#ifndef compras_db_hpp
#define compras_db_hpp

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * ComprasDb client definitions.
 */
class ComprasDb : public oatpp::orm::DbClient {
public:

  ComprasDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }
QUERY(createCompra,
        "INSERT INTO compras"
        "(id_compra, fecha_compra, id_producto, cantidad_producto, precio_compra) VALUES "
        "(uuid_generate_v4(), :compra.fecha_compra, :compra.id_producto, :compra.cantidad_producto, :compra.precio_compra)"
        "RETURNING *;",
        PREPARE(true), // Prepared statement!
        PARAM(oatpp::Object<ComprasDto>, compra))

  QUERY(updateCompra,
        "UPDATE compras "
        "SET "
        "fecha_compra=:compra.fecha_compra, "
        "id_producto=:compra.id_producto, "
        "cantidad_producto=:compra.cantidad_producto, "
        "precio_compra=:compra.precio_compra "
        "WHERE "
        " id_compra=:compra.id_compra "
        "RETURNING *;",
        PREPARE(true), //<-- Prepared statement!
        PARAM(oatpp::Object<ComprasDto>, compra))

  QUERY(getCompraById,
        "SELECT id_compra, fecha_compra, id_producto, cantidad_producto, precio_compra FROM compras WHERE id_compra=:id_compra;",
        PREPARE(true), //<-- Prepared statement!
        PARAM(oatpp::String, id_compra))

  QUERY(getAllCompras,
        "SELECT id_compra, fecha_compra, id_producto, cantidad_producto, precio_compra FROM compras LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- Prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteCompraById,
        "DELETE FROM compras WHERE id_compra=:id_compra;",
        PREPARE(true), //<-- Prepared statement!
        PARAM(oatpp::String, id_compra))
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //compras_db_hpp