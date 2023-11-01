#ifndef comprasController_hpp
#define comprasController_hpp

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Compras REST controller.
 */
class ComprasController : public oatpp::web::server::api::ApiController {
public:
  ComprasController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  ComprasService m_comprasService; // Create compras service.
public:

  static std::shared_ptr<ComprasController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<ComprasController>(objectMapper);
  }

  ENDPOINT_INFO(createCompra) {
    info->summary = "Crear nueva compra";

    info->addConsumes<Object<ComprasDto>>("application/json");

    info->addResponse<Object<ComprasDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "compras", createCompra,
           BODY_DTO(Object<ComprasDto>, compraDto))
  {
    return createDtoResponse(Status::CODE_200, m_comprasService.createCompra(compraDto));
  }

  ENDPOINT_INFO(updateCompra) {
    info->summary = "Actualizar compra por ID";

    info->addConsumes<Object<ComprasDto>>("application/json");

    info->addResponse<Object<ComprasDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["compraId"].description = "Identificador de la compra";
  }
  ENDPOINT("PUT", "compras", updateCompra,
           BODY_DTO(Object<ComprasDto>, compraDto),
           PATH(String, compraId))
  {
    return createDtoResponse(Status::CODE_200, m_comprasService.updateCompra(compraDto));
  }

  ENDPOINT_INFO(getCompraById) {
    info->summary = "Obtener una compra por ID";

    info->addResponse<Object<ComprasDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["compraId"].description = "Identificador de la compra";
  }
  ENDPOINT("GET", "compras/{compraId}", getCompraById,
           PATH(String, compraId))
  {
    return createDtoResponse(Status::CODE_200, m_comprasService.getCompraById(compraId));
  }

  ENDPOINT_INFO(getcompras) {
    info->summary = "get all stored compras";

    info->addResponse<oatpp::Object<comprasPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "compras/offset/{offset}/limit/{limit}", getcompras,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_comprasService.getAllCompras(offset, limit));
  }

  ENDPOINT_INFO(deleteCompraById) {
    info->summary = "Eliminar una compra por ID";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["compraId"].description = "Identificador de la compra";
  }
  ENDPOINT("DELETE", "compras/{compraId}", deleteCompraById,
           PATH(String, compraId))
  {
    return createDtoResponse(Status::CODE_200, m_comprasService.deleteCompraById(compraId));
  }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* comprasController_hpp */