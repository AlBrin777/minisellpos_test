
#ifndef LICCENCIA_CONTROLLER_HPP
#define LICCENCIA_CONTROLLER_HPP

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * licencia REST controller.
 */
class licenciaController : public oatpp::web::server::api::ApiController {
public:
  licenciaController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  licenciaService m_licenciaService; // Create licencia service.
public:

  static std::shared_ptr<licenciaController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<licenciaController>(objectMapper);
  }
  ENDPOINT("POST", "licencia", validateLicencia,
           BODY_DTO(Object<licenciaDto>, info))
    {
     return createDtoResponse(Status::CODE_200, m_licenciaService.validateLicencia(info));
    }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* LICCENCIA_CONTROLLER_HPP */
