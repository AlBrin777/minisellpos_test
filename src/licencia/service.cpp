#include "service.hpp"

oatpp::Object<licenciaDto> licenciaService::validateLicencia(const oatpp::Object<licenciaDto>& dto){
    OATPP_LOGI("Servicio LLICENCIA", "Validando licencia...");
    auto dbResult = m_database->getLicence(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Licencia Invalida");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<licenciaDto>>>();
    OATPP_ASSERT_HTTP(result->size()==1, Status::CODE_500, "Unknown error");
    OATPP_LOGI("Servicio LLICENCIA", "_________Licencia validada___________");
    return result[0];
}