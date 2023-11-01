#include "AppComponent.hpp"
#include "DatabaseComponent.hpp"
#include "ServiceComponent.hpp"

#include "login/controller.hpp"
#include "usuarios/controller.hpp"
#include "perfiles/controller.hpp"
#include "inventario/controller.hpp"
#include "compras/controller.hpp"
#include "ventas/controller.hpp"
#include "licencia/controller.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include <iostream>

void run(const oatpp::base::CommandLineArguments& args) {

  AppComponent appComponent(args);
  DatabaseComponent databaseComponent;
  ServiceComponent serviceComponent;

  auto router = serviceComponent.httpRouter.getObject();


  oatpp::web::server::api::Endpoints docEndpoints;
  docEndpoints.append(router->addController(loginController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(usuariosController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(perfilesController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(InventarioController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(ComprasController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(negocioController::createShared())->getEndpoints());
  docEndpoints.append(router->addController(licenciaController::createShared())->getEndpoints());



  /* create server */
  oatpp::network::Server server(serviceComponent.serverConnectionProvider.getObject(), serviceComponent.serverConnectionHandler.getObject());
  OATPP_LOGD("Server", "Running on port %s...", serviceComponent.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());
  server.run();
}

int main(int argc, const char **argv) {

  oatpp::base::Environment::init();

  run(oatpp::base::CommandLineArguments(argc, argv));

  oatpp::base::Environment::destroy();

  return 0;

}