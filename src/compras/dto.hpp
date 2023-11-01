#ifndef COMPRAS_DTO_HPP
#define COMPRAS_DTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ComprasDto : public oatpp::DTO{
DTO_INIT(ComprasDto, DTO)

DTO_FIELD(String, id_compra, "id_compra");
DTO_FIELD(String, fecha_compra, "fecha_compra");
DTO_FIELD(String, id_producto, "id_producto");
DTO_FIELD(Float64, cantidad_producto, "cantidad_producto");
DTO_FIELD(Float64, precio_compra, "precio_compra");

};

#include OATPP_CODEGEN_END(DTO)

#endif