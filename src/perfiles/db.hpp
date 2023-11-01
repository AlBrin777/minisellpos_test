#ifndef perfiles_db_hpp
#define perfiles_db_hpp

#include "dto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * perfilesDb client definitions.
 */
class perfilesDb : public oatpp::orm::DbClient {
public:

  perfilesDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

  }

  QUERY(createCliente,
        "INSERT INTO public.cliente"
        "(id_cliente, dni_cliente, nombre_cliente, apellido_cliente, direccion, telefono, email) VALUES "
        "(uuid_generate_v4(), :cliente.dni_cliente, :cliente.nombre_cliente, :cliente.apellido_cliente, :cliente.telefono, :cliente.direccion, :cliente.email)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<clienteDto>, cliente))

  QUERY(updateCliente,
        "UPDATE public.cliente "
        "SET "
        "dni_cliente=:cliente.dni_cliente, "
        "nombre_cliente=:cliente.nombre_cliente, "
        "apellido_cliente=:cliente.apellido_cliente, "
        "telefono=:cliente.telefono, "
        "direccion=:cliente.direccion, "
        "email=:cliente.email "
        "WHERE "
        " id_cliente=:cliente.id_cliente "
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<clienteDto>, cliente))

  QUERY(getClienteById,
        "SELECT id_cliente, nombre_cliente, apellido_cliente, direccion, telefono, email, dni_cliente FROM public.cliente WHERE id_cliente=:id_cliente;",
        PREPARE(true),
        PARAM(oatpp::String, id_cliente))

  QUERY(getAllClientes,
        "SELECT id_cliente, nombre_cliente, apellido_cliente, direccion, telefono, email, dni_cliente FROM public.cliente LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteClienteById,
        "DELETE FROM public.cliente WHERE id_cliente=:id_cliente;",
        PREPARE(true),
        PARAM(oatpp::String, id_cliente))


  QUERY(createEmpresa,
        "INSERT INTO public.empresa"
        "(id_empresa, dni_empresa, nombre_rs, address, telephone, email) VALUES "
        "(uuid_generate_v4(), :empresa.dni_empresa, :empresa.nombre_rs, :empresa.address, :empresa.telephone, :empresa.email)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<empresaDto>, empresa))

  QUERY(updateEmpresa,
        "UPDATE public.empresa "
        "SET "
        "dni_empresa=:empresa.dni_empresa, "
        "nombre_rs=:empresa.nombre_rs, "
        "address=:empresa.address, "
        "telephone=:empresa.telephone, "
        "email=:empresa.email "
        "WHERE "
        " id_empresa=:empresa.id_empresa "
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<empresaDto>, empresa))

  QUERY(getEmpresaById,
        "SELECT id_empresa, nombre_rs, address, telephone, email, dni_empresa FROM public.empresa WHERE id_empresa=:id_empresa;",
        PREPARE(true),
        PARAM(oatpp::String, id_empresa))

  QUERY(getAllEmpresas,
        "SELECT id_empresa, nombre_rs, address, telephone, email, dni_empresa FROM public.empresa LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteEmpresaById,
        "DELETE FROM public.empresa WHERE id_empresa=:id_empresa;",
        PREPARE(true),
        PARAM(oatpp::String, id_empresa))


  QUERY(createProveedor,
        "INSERT INTO public.proveedor"
        "(id_proveedor, dni_proveedor, nombre_rs, email, telephone, address) VALUES "
        "(uuid_generate_v4(), :proveedor.dni_proveedor, :proveedor.nombre_rs, :proveedor.email, :proveedor.telephone, :proveedor.address)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<proveedorDto>, proveedor))

  QUERY(updateProveedor,
        "UPDATE public.proveedor "
        "SET "
        "dni_proveedor=:proveedor.dni_proveedor, "
        "nombre_rs=:proveedor.nombre_rs, "
        "email=:proveedor.email, "
        "telephone=:proveedor.telephone, "
        "address=:proveedor.address "
        "WHERE "
        " id_proveedor=:proveedor.id_proveedor "
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<proveedorDto>, proveedor))

  QUERY(getProveedorById,
        "SELECT id_proveedor, dni_proveedor, nombre_rs, email, telephone, address FROM public.proveedor WHERE id_proveedor=:id_proveedor;",
        PREPARE(true),
        PARAM(oatpp::String, id_proveedor))

  QUERY(getAllProveedores,
        "SELECT id_proveedor, dni_proveedor, nombre_rs, email, telephone, address FROM public.proveedor LIMIT :limit OFFSET :offset;",
        PREPARE(true),
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteProveedorById,
        "DELETE FROM public.proveedor WHERE id_proveedor=:id_proveedor;",
        PREPARE(true),
        PARAM(oatpp::String, id_proveedor))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //perfiles_db_hpp