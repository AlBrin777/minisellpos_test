#ifndef LICENCIA_SERVICE_HPP
#define LICENCIA_SERVICE_HPP

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class licenciaService {

private:
typedef oatpp::web::protocol::http::Status Status;
private:
OATPP_COMPONENT(std::shared_ptr<licenciaDb>, m_database); // Inject database component
public:
   oatpp::Object<licenciaDto> validateLicencia(const oatpp::Object<licenciaDto>& dto);
};

#endif // LICENCIA_SERVICE_HPP