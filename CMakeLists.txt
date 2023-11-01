cmake_minimum_required(VERSION 3.1)

set(project_name MINISELL) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)
if(MSVC)
  add_compile_options(/bigobj)
endif()
add_library(${project_name}-lib
        
        libs/ConfigDto.hpp
        libs/PageDto.hpp
        libs/StatusDto.hpp

        ## login module
        src/login/controller.hpp
        src/login/db.hpp
        src/login/service.hpp
        src/login/service.cpp

        ## usuarios module
        src/usuarios/controller.hpp
        src/usuarios/db.hpp
        src/usuarios/dto.hpp
        src/usuarios/service.hpp
        src/usuarios/service.cpp

        ## licencia module
        src/licencia/controller.hpp
        src/licencia/db.hpp
        src/licencia/dto.hpp
        src/licencia/service.hpp
        src/licencia/service.cpp

        ## perfiles module
        src/perfiles/controller.hpp
        src/perfiles/db.hpp
        src/perfiles/dto.hpp
        src/perfiles/service.hpp
        src/perfiles/service.cpp

        ## inventario module
        src/inventario/controller.hpp
        src/inventario/db.hpp
        src/inventario/dto.hpp
        src/inventario/service.hpp
        src/inventario/service.cpp

        ## compras module
        src/compras/controller.hpp
        src/compras/db.hpp
        src/compras/dto.hpp
        src/compras/service.hpp
        src/compras/service.cpp

        ## ventas module
        src/ventas/controller.hpp
        src/ventas/db.hpp
        src/ventas/dto.hpp
        src/ventas/service.hpp
        src/ventas/service.cpp
        
        ## MAIN ##
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp
        src/ServiceComponent.hpp
        src/Tools.hpp
        src/Tools.cpp
)

target_include_directories(${project_name}-lib PUBLIC src)

## link libs

find_package(oatpp              1.3.0 REQUIRED)
# find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
# Rutas de los encabezados de la biblioteca oatpp
# include_directories(${PROJECT_SOURCE_DIR}/lib/oatpp/includes)
# link_directories(${PROJECT_SOURCE_DIR}/lib/oatpp/lib)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        # PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
        PUBLIC nlohmann_json::nlohmann_json
)

add_definitions(
        # Path to swagger-ui resources #
        # -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

#################################################################
## add executables

add_executable(${project_name}-exe
        src/App.cpp
)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
)
target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

enable_testing()
add_test(project-tests ${project_name}-test)
