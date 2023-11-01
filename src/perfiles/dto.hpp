#ifndef perfilesDto_hpp
#define perfilesDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class clienteDto : public oatpp::DTO {
  
  DTO_INIT(clienteDto, DTO)

  DTO_FIELD(String, id_cliente);
  DTO_FIELD(String, dni_cliente, "dni_cliente");
  DTO_FIELD(String, nombre_cliente, "nombre_cliente");
  DTO_FIELD(String, apellido_cliente, "apellido_cliente");
  DTO_FIELD(String, telefono, "telefono");
  DTO_FIELD(String, direccion, "direccion");
  DTO_FIELD(String, email, "email");

};

class empresaDto : public oatpp::DTO {
  
  DTO_INIT(empresaDto, DTO)

  DTO_FIELD(String, id_empresa);
  DTO_FIELD(String, dni_empresa, "dni_empresa");
  DTO_FIELD(String, nombre_rs, "nombre_rs");
  DTO_FIELD(String, address, "address");
  DTO_FIELD(String, telephone, "telephone");
  DTO_FIELD(String, email, "email");

};

class proveedorDto : public oatpp::DTO {
  
  DTO_INIT(proveedorDto, DTO)

  DTO_FIELD(String, id_proveedor);
  DTO_FIELD(String, dni_proveedor, "dni_proveedor");
  DTO_FIELD(String, nombre_rs, "nombre_rs");
  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, telephone, "telephone");
  DTO_FIELD(String, address, "address");

};




#include OATPP_CODEGEN_END(DTO)

#endif /* perfilesDto_hpp */