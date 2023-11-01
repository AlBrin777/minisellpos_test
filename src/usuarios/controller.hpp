
#ifndef usuariosController_hpp
#define usuariosController_hpp

#include "service.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * usuarios REST controller.
 */
class usuariosController : public oatpp::web::server::api::ApiController {
public:
  usuariosController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  usuariosService m_usuariosService; // Create usuarios service.
public:

  static std::shared_ptr<usuariosController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<usuariosController>(objectMapper);
  }
  
  ENDPOINT_INFO(createusuarios) {
    info->summary = "Create new usuarios";

    info->addConsumes<Object<usuariosDto>>("application/json");

    info->addResponse<Object<usuariosDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "usuarios", createusuarios,
           BODY_DTO(Object<usuariosDto>, UsuariosDto))
  {
    return createDtoResponse(Status::CODE_200, m_usuariosService.createusuarios(UsuariosDto));
  }
  
  
  ENDPOINT_INFO(putusuarios) {
    info->summary = "Update usuarios by usuariosId";

    info->addConsumes<Object<usuariosDto>>("application/json");

    info->addResponse<Object<usuariosDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["usuariosId"].description = "usuarios Identifier";
  }
  ENDPOINT("PUT", "usuarios", putusuarios,
           BODY_DTO(Object<usuariosDto>, UsuarioDto))
  {
    return createDtoResponse(Status::CODE_200, m_usuariosService.updateusuarios(UsuarioDto));
  }
  
  
  ENDPOINT_INFO(getusuariosById) {
    info->summary = "Get one usuarios by usuariosId";

    info->addResponse<Object<usuariosDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["usuariosId"].description = "usuarios Identifier";
  }
  ENDPOINT("GET", "usuarios/{usuariosId}", getusuariosById,
           PATH(String, usuariosId))
  {  
      
    return createDtoResponse(Status::CODE_200, m_usuariosService.getusuariosById(usuariosId));
  }
  
  
  ENDPOINT_INFO(getusuarios) {
    info->summary = "get all stored usuarios";

    info->addResponse<oatpp::Object<usuariosPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "usuarios/offset/{offset}/limit/{limit}", getusuarios,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_usuariosService.getAllusuarios(offset, limit));
  }
  
  
  ENDPOINT_INFO(deleteusuarios) {
    info->summary = "Delete usuarios by usuariosId";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["usuariosId"].description = "usuarios Identifier";
  }
  ENDPOINT("DELETE", "usuarios/{usuariosId}", deleteusuarios,
           PATH(String, usuariosId))
  {
    return createDtoResponse(Status::CODE_200, m_usuariosService.deleteusuariosById(usuariosId));
  }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* usuariosController_hpp */
