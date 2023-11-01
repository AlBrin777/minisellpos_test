#ifndef LICENCIA_DB_HPP
#define LICENCIA_DB_HPP

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**

licenciaDb client definitions.
*/
class licenciaDb : public oatpp::orm::DbClient {
public:
  licenciaDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }

QUERY(getLicence,
      "SELECT * FROM public.license"
      " WHERE "
      "dni=:lic.dni AND "
      "name=:lic.name AND "
      "telephone=:lic.telephone AND "
      "email=:lic.email AND "
      "serial_buy=:lic.serial_buy AND "
      "code_activation=:lic.code_activation; ",
      PREPARE(true),
      PARAM(oatpp::Object<licenciaDto>, lic))
};
#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif // LICENCIA_DB_HPP