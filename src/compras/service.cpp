#include "service.hpp"

  oatpp::Object<ComprasDto> ComprasService::createCompra(const oatpp::Object<ComprasDto>& dto) {
    OATPP_LOGI("ComprasService", "Creando compra...");
    auto dbResult = m_database->createCompra(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ComprasDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    OATPP_LOGI("ComprasService", "--------------> Compra creada <-----------------");
    return result[0];
  }

  oatpp::Object<ComprasDto> ComprasService::updateCompra(const oatpp::Object<ComprasDto>& dto) {
    OATPP_LOGI("ComprasService", "Modificando compra...");
    auto dbResult = m_database->updateCompra(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ComprasDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    OATPP_LOGI("ComprasService", "--------------> Compra modificada <-----------------");
    return result[0];
  }

  oatpp::Object<ComprasDto> ComprasService::getCompraById(const oatpp::String& id) {
    OATPP_LOGI("ComprasService", "Buscando compra por ID...");
    auto dbResult = m_database->getCompraById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Compra not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ComprasDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    OATPP_LOGI("ComprasService", "--------------> Compra encontrada <-----------------");
    return result[0];
  }

  oatpp::Object<PageDto<oatpp::Object<ComprasDto>>> ComprasService::getAllCompras(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
    OATPP_LOGI("ComprasService", "Consultando todas las compras...");
    oatpp::UInt32 countToFetch = limit;
    if(limit > 10) {
      countToFetch = 10;
    }
    auto dbResult = m_database->getAllCompras(offset, countToFetch);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ComprasDto>>>();
    auto page = PageDto<oatpp::Object<ComprasDto>>::createShared();
    page->offset = offset;
    page->limit = countToFetch;
    page->count = items->size();
    page->items = items;
    OATPP_LOGI("ComprasService", "--------------> Compras encontradas: %d <-----------------", page->count);
    return page;
  }

  oatpp::Object<StatusDto> ComprasService::deleteCompraById(const oatpp::String& compraId) {
    OATPP_LOGI("ComprasService", "Eliminando compra...");
    auto dbResult = m_database->deleteCompraById(compraId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Compra eliminada correctamente";
    return status;
  }