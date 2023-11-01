#ifndef negocioController_hpp
#define negocioController_hpp

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * negocio REST controller.
 */
class negocioController : public oatpp::web::server::api::ApiController {
public:
  negocioController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  negocioService m_negocioService; // Create negocio service.
public:

  static std::shared_ptr<negocioController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<negocioController>(objectMapper);
  }
  
  ENDPOINT("POST", "lista_prod_venta", createListaProdVenta,
           BODY_DTO(Object<ListaProdVentaDto>, listaProdVentaDto))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.createListaProdVenta(listaProdVentaDto));
  }
  
  
  ENDPOINT("PUT", "lista_prod_venta", putListaProdVenta,
           BODY_DTO(Object<ListaProdVentaDto>, listaProdVentaDto))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.updateListaProdVenta(listaProdVentaDto));
  }
  

  ENDPOINT("GET", "lista_prod_venta/{listaProdVentaId}", getListaProdVentaById,
           PATH(String, listaProdVentaId))
  {  
      
    return createDtoResponse(Status::CODE_200, m_negocioService.getListaProdVentaById(listaProdVentaId));
  }
  
  
  ENDPOINT("GET", "lista_prod_venta/offset/{offset}/limit/{limit}", getAllListaProdVenta,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.getAllListaProdVenta(offset, limit));
  }
  
  
  ENDPOINT("DELETE", "lista_prod_venta/{listaProdVentaId}", deleteListaProdVenta,
           PATH(String, listaProdVentaId))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.deleteListaProdVentaById(listaProdVentaId));
  }

  ENDPOINT("POST", "venta", createVenta,
           BODY_DTO(Object<VentaDto>, ventaDto))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.createVenta(ventaDto));
  }
  
  
  ENDPOINT("PUT", "venta", putVenta,
           BODY_DTO(Object<VentaDto>, ventaDto))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.updateVenta(ventaDto));
  }
  
  ENDPOINT("GET", "venta/{ventaId}", getVentaById,
           PATH(String, ventaId))
  {  
      
    return createDtoResponse(Status::CODE_200, m_negocioService.getVentaById(ventaId));
  }
  
  
  ENDPOINT("GET", "venta/offset/{offset}/limit/{limit}", getAllVentas,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.getAllVentas(offset, limit));
  }
  
  ENDPOINT("DELETE", "venta/{ventaId}", deleteVenta,
           PATH(String, ventaId))
  {
    return createDtoResponse(Status::CODE_200, m_negocioService.deleteVentaById(ventaId));
  }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* negocioController_hpp */
