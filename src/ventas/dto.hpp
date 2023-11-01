#ifndef negocio_dto_hpp
#define negocio_dto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ListaProdVentaDto : public oatpp::DTO {
  
  DTO_INIT(ListaProdVentaDto, DTO)

  DTO_FIELD(String, id_lista_pv, "id_lista_pv");
  DTO_FIELD(String, id_producto, "id_producto");
  DTO_FIELD(Float64, cantidad, "cantidad");
  DTO_FIELD(Float64, precio_total, "precio_total");
  DTO_FIELD(String, id_venta, "id_venta");

};

class VentaDto : public oatpp::DTO {
  
  DTO_INIT(VentaDto, DTO)

  DTO_FIELD(String, id_venta, "id_venta");
  DTO_FIELD(UInt32, factura, "factura");
  DTO_FIELD(String, id_empresa, "id_empresa");
  DTO_FIELD(String, fecha_venta, "fecha_venta");
  DTO_FIELD(String, hora_venta, "hora_venta");
  DTO_FIELD(String, id_cliente, "id_cliente");
  DTO_FIELD(Float64, monto_total, "monto_total");
  DTO_FIELD(Float64, pago, "pago");
  DTO_FIELD(Float64, cambio, "cambio");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* negocio_dto_hpp */
