#ifndef INVENTARIO_CONTROLLER_hpp
#define INVENTARIO_CONTROLLER_hpp

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Controlador REST para el inventario.
 */
class InventarioController : public oatpp::web::server::api::ApiController {
public:
  InventarioController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  InventarioService m_inventarioService; // Servicio de inventario.

public:
  /**
   * Método para crear una instancia compartida del controlador.
   */
  static std::shared_ptr<InventarioController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inyección del componente ObjectMapper.
  ){
    return std::make_shared<InventarioController>(objectMapper);
  }

  /*
 __________________  ENPOINTS CATEGORIAS _____________________________
*/

  /**
 * Endpoint para obtener una categoría por su ID.
 */
ENDPOINT_INFO(getCategoriaById) {
  info->summary = "Obtiene una categoría por su ID";
  info->addResponse<Object<CategoriaDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la categoría";
}
ENDPOINT("GET", "inventario/categorias/{id}", getCategoriaById,
         PATH(String, id))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.getCategoriaById(id));
}

/**
 * Endpoint para obtener todas las categorías del inventario.
 */
  ENDPOINT("GET", "inventario/categorias/offset/{offset}/limit/{limit}", getAllCategorias,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.getAllCategorias(offset, limit));
  }

/**
 * Endpoint para crear una nueva categoría en el inventario.
 */
ENDPOINT_INFO(postCategoria) {
  info->summary = "Crea una nueva categoría en el inventario";
  info->addConsumes<Object<CategoriaDto>>("application/json");
  info->addResponse<Object<CategoriaDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("POST", "inventario/categorias", postCategoria,
         BODY_DTO(Object<CategoriaDto>, categoriaDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.createCategoria(categoriaDto));
}

/**
 * Endpoint para actualizar una categoría existente en el inventario.
 */
ENDPOINT_INFO(putCategoria) {
  info->summary = "Actualiza una categoría existente en el inventario";
  info->addConsumes<Object<CategoriaDto>>("application/json");
  info->addResponse<Object<CategoriaDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la categoría";
}
ENDPOINT("PUT", "inventario/categorias", putCategoria,
         BODY_DTO(Object<CategoriaDto>, categoriaDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.updateCategoria(categoriaDto));
}

/**
 * Endpoint para eliminar una categoría del inventario.
 */
ENDPOINT_INFO(deleteCategoria) {
  info->summary = "Elimina una categoría del inventario";
  info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la categoría";
}
ENDPOINT("DELETE", "inventario/categorias/{id}", deleteCategoria,
         PATH(String, id))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.deleteCategoriaById(id));
}


/*
 __________________  ENPOINTS PRODUCTOS _____________________________
*/

  /**
   * Endpoint para obtener un producto por su ID.
   */
  ENDPOINT_INFO(getProductoById) {
    info->summary = "Obtiene un producto por su ID";
    info->addResponse<Object<ProductoDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->pathParams["id"].description = "ID del producto";
  }
  ENDPOINT("GET", "inventario/productos/{id}", getProductoById,
           PATH(String, id))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.getProductoById(id));
  }

  /**
   * Endpoint para obtener todos los productos del inventario.
   */
  ENDPOINT("GET", "inventario/productos/offset/{offset}/limit/{limit}", getAllProductos,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.getAllProductos(offset, limit));
  }

  /**
   * Endpoint para crear un nuevo producto en el inventario.
   */
  ENDPOINT_INFO(postProducto) {
    info->summary = "Crea un nuevo producto en el inventario";
    info->addConsumes<Object<ProductoDto>>("application/json");
    info->addResponse<Object<ProductoDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "inventario/productos", postProducto,
           BODY_DTO(Object<ProductoDto>, productoDto))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.createProducto(productoDto));
  }

  /**
   * Endpoint para actualizar un producto existente en el inventario.
   */
  ENDPOINT_INFO(putProducto) {
    info->summary = "Actualiza un producto existente en el inventario";
    info->addConsumes<Object<ProductoDto>>("application/json");
    info->addResponse<Object<ProductoDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->pathParams["id"].description = "ID del producto";
  }
  ENDPOINT("PUT", "inventario/productos", putProducto,
           BODY_DTO(Object<ProductoDto>, productoDto))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.updateProducto(productoDto));
  }

  /**
   * Endpoint para eliminar un producto del inventario.
   */
  ENDPOINT_INFO(deleteProducto) {
    info->summary = "Elimina un producto del inventario";
    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->pathParams["id"].description = "ID del producto";
  }
  ENDPOINT("DELETE", "inventario/productos/{id}", deleteProducto,
           PATH(String, id))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.deleteProductoById(id));
  }


/*
 __________________  ENPOINTS LISTA DE PRODUCTOS _____________________________
*/

  ENDPOINT_INFO(getListaProductoById) {
  info->summary = "Obtiene una lista de productos por su ID";
  info->addResponse<Object<ListaProductoDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la lista de productos";
}
ENDPOINT("GET", "inventario/listas-productos/{id}", getListaProductoById,
         PATH(String, id))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.getListaProductoById(id));
}

ENDPOINT_INFO(getAllListaProductos) {
    info->summary = "get all stored ListaProducto";
    info->addResponse<oatpp::Object<listaProductoPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("GET", "inventario/listas-productos/offset/{offset}/limit/{limit}", getAllListaProductos,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
{
    return createDtoResponse(Status::CODE_200, m_inventarioService.getAllListaProductos(offset, limit));
}

ENDPOINT_INFO(postListaProducto) {
  info->summary = "Crea una nueva lista de productos en el inventario";
  info->addConsumes<Object<ListaProductoDto>>("application/json");
  info->addResponse<Object<ListaProductoDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("POST", "inventario/listas-productos", postListaProducto,
         BODY_DTO(Object<ListaProductoDto>, listaProductoDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.createListaProducto(listaProductoDto));
}

ENDPOINT_INFO(putListaProducto) {
  info->summary = "Actualiza una lista de productos existente en el inventario";
  info->addConsumes<Object<ListaProductoDto>>("application/json");
  info->addResponse<Object<ListaProductoDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la lista de productos";
}
ENDPOINT("PUT", "inventario/listas-productos", putListaProducto,
         BODY_DTO(Object<ListaProductoDto>, listaProductoDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.updateListaProducto(listaProductoDto));
}

ENDPOINT_INFO(deleteListaProducto) {
  info->summary = "Elimina una lista de productos del inventario";
  info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  info->pathParams["id"].description = "ID de la lista de productos";
}
ENDPOINT("DELETE", "inventario/listas-productos/{id}", deleteListaProducto,
         PATH(String, id))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.deleteListaProductoById(id));
}


/*
 __________________  ENPOINTS INVENTARIO 'Report' _____________________________
*/

ENDPOINT_INFO(postInventario) {
  info->summary = "Crea un nuevo inventario";
  info->addConsumes<Object<InventarioDto>>("application/json");
  info->addResponse<Object<InventarioDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("POST", "inventario/inventario_report", postInventario,
         BODY_DTO(Object<InventarioDto>, inventarioDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.createInventario(inventarioDto));
}

ENDPOINT("GET", "inventario/inventario_report/offset/{offset}/limit/{limit}", getAllInventario,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_inventarioService.getAllInventario(offset, limit));
  }

ENDPOINT_INFO(putInventario) {
  info->summary = "Actualiza el inventario completo";
  info->addConsumes<Object<InventarioDto>>("application/json");
  info->addResponse<Object<InventarioDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("PUT", "inventario/inventario_report", putInventario,
         BODY_DTO(Object<InventarioDto>, inventarioDto))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.updateInventario(inventarioDto));
}

ENDPOINT_INFO(deleteInventario) {
  info->summary = "Elimina todos los productos del inventario";
  info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
  info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
}
ENDPOINT("DELETE", "inventario/inventario_report", deleteInventario, 
        PATH(String, id))
{
  return createDtoResponse(Status::CODE_200, m_inventarioService.deleteInventarioById(id));
}

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* InventarioController_hpp */