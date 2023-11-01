#ifndef usuariosDto_hpp
#define usuariosDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class usuariosDto : public oatpp::DTO {
  
  DTO_INIT(usuariosDto, DTO)

  DTO_FIELD(String, id_user);
  DTO_FIELD(String, username, "username");
  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, password, "password");
  DTO_FIELD(String, type_user, "type_user");
  DTO_FIELD(String, token, "token");

};


#include OATPP_CODEGEN_END(DTO)

#endif /* usuariosDto_hpp */