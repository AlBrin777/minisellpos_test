
#ifndef usuarios_db_hpp
#define usuarios_db_hpp

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * usuariosDb client definitions.
 */
class usuariosDb : public oatpp::orm::DbClient {
public:

  usuariosDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }
QUERY(createusuarios,
        "INSERT INTO users"
        "(id_user, username, email, password, type_user, token) VALUES "
        "(uuid_generate_v4(), :user.username, :user.email, :user.password, :user.type_user, uuid_generate_v1())"
        "RETURNING *;",
        PREPARE(true), // usuarios prepared statement!
        PARAM(oatpp::Object<usuariosDto>, user))

  QUERY(updateusuarios,
        "UPDATE users "
        "SET "
        "username=:user.username, "
        "email=:user.email, "
        "password=:user.password, "
        "type_user=:user.type_user "
        "WHERE "
        " id_user=:user.id_user "
        "RETURNING *;",
        PREPARE(true), //<-- usuarios prepared statement!
        PARAM(oatpp::Object<usuariosDto>, user))

  QUERY(getusuariosById,
        "SELECT id_user,username,email,type_user FROM users WHERE id_user=:id_user;",
        PREPARE(true), //<-- usuarios prepared statement!
        PARAM(oatpp::String, id_user))

  QUERY(getAllusuarios,
        "SELECT id_user,username,email,type_user FROM users LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- usuarios prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteusuariosById,
        "DELETE FROM users WHERE id_user=:id_user;",
        PREPARE(true), //<-- usuarios prepared statement!
        PARAM(oatpp::String, id_user))
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //usuarios_db_hpp
