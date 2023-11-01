
#ifndef login_db_hpp
#define login_db_hpp

#include "../usuarios/dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * loginDb client definitions.
 */
class LoginDb : public oatpp::orm::DbClient {
public:

  LoginDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {
  }

  QUERY(confirmUser, 
  "SELECT username, token FROM public.users WHERE username=:user.username AND password=:user.password",
  PREPARE(true),
  PARAM(oatpp::Object<usuariosDto>, user)
  )

  QUERY(confirmToken,
  "SELECT username, token FROM public.users WHERE token=:token AND username=:username",
  PREPARE(true),
  PARAM(oatpp::String, token),
  PARAM(oatpp::String, username)
  )

  QUERY(updateToken,
  "UPDATE public.users SET token = uuid_generate_v1() WHERE username=:username AND token=:actualToken RETURNING *;",
  PREPARE(true),
  PARAM(oatpp::String, username),
  PARAM(oatpp::String, actualToken)
  )
  QUERY(getUsernameByToken,
  "SELECT username FROM public.users WHERE token=:token;",
  PREPARE(true),
  PARAM(oatpp::String, token))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //login_db_hpp
