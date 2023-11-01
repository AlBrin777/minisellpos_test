#ifndef compras_service_hpp
#define compras_service_hpp

#include "db.hpp"

#include "../../libs/PageDto.hpp"
#include "../../libs/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"



class ComprasService {

private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<ComprasDb>, m_database); // Inject database component
public:

  oatpp::Object<ComprasDto> createCompra(const oatpp::Object<ComprasDto>& dto);
  oatpp::Object<ComprasDto> updateCompra(const oatpp::Object<ComprasDto>& dto);
  oatpp::Object<ComprasDto> getCompraById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<ComprasDto>>> getAllCompras(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteCompraById(const oatpp::String& id);
};

#endif //compras_service_hpp