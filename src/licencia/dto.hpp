#ifndef LICENCIA_DTO_HPP
#define LICENCIA_DTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class licenciaDto : public oatpp::DTO {

DTO_INIT(licenciaDto, DTO)

DTO_FIELD(String, id_license);
DTO_FIELD(String, dni, "dni");
DTO_FIELD(String, name, "name");
DTO_FIELD(String, telephone, "telephone");
DTO_FIELD(String, email, "email");
DTO_FIELD(String, serial_buy, "serial_buy");
DTO_FIELD(String, code_activation, "code_activation");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* LICENCIA_DTO_HPP */