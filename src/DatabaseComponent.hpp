#ifndef databasecomponent_HPP
#define databasecomponent_HPP

#include "../libs/ConfigDto.hpp"
#include "login/db.hpp"
#include "usuarios/db.hpp"
#include "perfiles/db.hpp"
#include "inventario/db.hpp"
#include "compras/db.hpp"
#include "ventas/db.hpp"
#include "licencia/db.hpp"

class DatabaseComponent {
public:
  
    /**
   * Create database licencia
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<licenciaDb>, info)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);

    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create MyClient database client */
    return std::make_shared<licenciaDb>(executor);

  }());

  /**
   * Create database usuarios
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<LoginDb>, loginDb)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);

    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create MyClient database client */
    return std::make_shared<LoginDb>(executor);

  }());

  /**
   * Create database usuarios
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<usuariosDb>, userDb)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);

    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create MyClient database client */
    return std::make_shared<usuariosDb>(executor);

  }());

  /**
   * Create database perfiles
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<perfilesDb>, perfilesDb_)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);

    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create perfilesDb database client */
    return std::make_shared<perfilesDb>(executor);

  }());

    /**
   * Create database Inventario
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<inventarioDb>, inventarioDb_)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);
    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create inventarioDb database client */
    return std::make_shared<inventarioDb>(executor);

  }());

      /**
   * Create database Compras
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<ComprasDb>, comprasDb_)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);
    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create ComprasDb database client */
    return std::make_shared<ComprasDb>(executor);

  }());

        /**
   * Create database venta
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<negocioDb>, negocioDb_)([] {

    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

    /* Create database-specific ConnectionProvider */
    auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

    /* Create database-specific ConnectionPool */
    auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                          10 /* max-connections */,
                                                                          std::chrono::seconds(5) /* connection TTL */);
    /* Create database-specific Executor */
    auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

    /* Create ventaDb database client */
    return std::make_shared<negocioDb>(executor);

  }());

};

#endif //DATABASECOMPONENT_HPP