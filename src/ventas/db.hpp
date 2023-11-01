#ifndef negocio_db_hpp
#define negocio_db_hpp

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * negocioDb client definitions.
 */
class negocioDb : public oatpp::orm::DbClient {
public:

  negocioDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }

  QUERY(createListaProdVenta,
        "INSERT INTO lista_prod_venta"
        "(id_lista_pv, id_producto, cantidad, precio_total, id_venta) VALUES "
        "(uuid_generate_v4(), :listaProdVenta.id_producto, :listaProdVenta.cantidad, :listaProdVenta.precio_total, :listaProdVenta.id_venta)"
        "RETURNING *;",
        PREPARE(true), // prepare statement!
        PARAM(oatpp::Object<ListaProdVentaDto>, listaProdVenta))

  QUERY(updateListaProdVenta,
        "UPDATE lista_prod_venta "
        "SET "
        "id_producto=:listaProdVenta.id_producto, "
        "cantidad=:listaProdVenta.cantidad, "
        "precio_total=:listaProdVenta.precio_total, "
        "id_venta=:listaProdVenta.id_venta "
        "WHERE "
        " id_lista_pv=:listaProdVenta.id_lista_pv "
        "RETURNING *;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::Object<ListaProdVentaDto>, listaProdVenta))

  QUERY(getListaProdVentaById,
        "SELECT id_lista_pv,id_producto,cantidad,precio_total,id_venta FROM lista_prod_venta WHERE id_lista_pv=:id_lista_pv;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::String, id_lista_pv))

  QUERY(getAllListaProdVenta,
        "SELECT id_lista_pv,id_producto,CAST(cantidad AS REAL),CAST(precio_total AS REAL),id_venta FROM lista_prod_venta LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteListaProdVentaById,
        "DELETE FROM lista_prod_venta WHERE id_lista_pv=:id_lista_pv;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::String, id_lista_pv))

  QUERY(createVenta,
        "INSERT INTO venta"
        "(id_venta, factura, id_empresa, fecha_venta, hora_venta, id_cliente, monto_total, pago, cambio) VALUES "
        "(uuid_generate_v4(), :venta.factura, :venta.id_empresa, :venta.fecha_venta, :venta.hora_venta, :venta.id_cliente, :venta.monto_total, :venta.pago, :venta.cambio)"
        "RETURNING *;",
        PREPARE(true), // prepare statement!
        PARAM(oatpp::Object<VentaDto>, venta))

  QUERY(updateVenta,
        "UPDATE venta "
        "SET "
        "factura=:venta.factura, "
        "id_empresa=:venta.id_empresa, "
        "fecha_venta=:venta.fecha_venta, "
        "hora_venta=:venta.hora_venta, "
        "id_cliente=:venta.id_cliente, "
        "monto_total=:venta.monto_total, "
        "pago=:venta.pago, "
        "cambio=:venta.cambio "
        "WHERE "
        " id_venta=:venta.id_venta "
        "RETURNING *;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::Object<VentaDto>, venta))

  QUERY(getVentaById,
        "SELECT id_venta,factura,id_empresa,fecha_venta,hora_venta,id_cliente,monto_total,pago,cambio FROM venta WHERE id_venta=:id_venta;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::String, id_venta))

  QUERY(getAllVentas,
        "SELECT id_venta,factura,id_empresa,fecha_venta,hora_venta,id_cliente,CAST(monto_total AS REAL),CAST(pago AS REAL),CAST(cambio AS REAL) FROM venta LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteVentaById,
        "DELETE FROM venta WHERE id_venta=:id_venta;",
        PREPARE(true), //<-- prepare statement!
        PARAM(oatpp::String, id_venta))
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //negocio_db_hpp
