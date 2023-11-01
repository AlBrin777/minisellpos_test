#ifndef page_dto_hpp
#define page_dto_hpp

#include "../src/usuarios/dto.hpp"
#include "../src/perfiles/dto.hpp"
#include "../src/inventario/dto.hpp"
#include "../src/compras/dto.hpp"
#include "../src/ventas/dto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PageDto : public oatpp::DTO {

  DTO_INIT(PageDto, DTO)

  DTO_FIELD(UInt32, offset);
  DTO_FIELD(UInt32, limit);
  DTO_FIELD(UInt32, count);
  DTO_FIELD(Vector<T>, items);

};

//PAGE USUARIOS MOD
class usuariosPageDto : public PageDto<oatpp::Object<usuariosDto>> {

  DTO_INIT(usuariosPageDto, PageDto<oatpp::Object<usuariosDto>>)

};

//PAGE PERFILES MOD
class clientePageDto : public PageDto<oatpp::Object<clienteDto>> {

  DTO_INIT(clientePageDto, PageDto<oatpp::Object<clienteDto>>)

};

class empresaPageDto : public PageDto<oatpp::Object<empresaDto>> {

  DTO_INIT(empresaPageDto, PageDto<oatpp::Object<empresaDto>>)

};

class proveedorPageDto : public PageDto<oatpp::Object<proveedorDto>> {

  DTO_INIT(proveedorPageDto, PageDto<oatpp::Object<proveedorDto>>)

};

//PAGE INVENTARIO MOD
class categoriaPageDto : public PageDto<oatpp::Object<CategoriaDto>> {
  DTO_INIT(categoriaPageDto, PageDto<oatpp::Object<CategoriaDto>>)
};

class productoPageDto : public PageDto<oatpp::Object<ProductoDto>> {
  DTO_INIT(productoPageDto, PageDto<oatpp::Object<ProductoDto>>)
};

class listaProductoPageDto : public PageDto<oatpp::Object<ListaProductoDto>> {
  DTO_INIT(listaProductoPageDto, PageDto<oatpp::Object<ListaProductoDto>>)
};

class inventarioPageDto : public PageDto<oatpp::Object<InventarioDto>> {
  DTO_INIT(inventarioPageDto, PageDto<oatpp::Object<InventarioDto>>)
};

//PAGE COMPRAS MOD
class comprasPageDto : public PageDto<oatpp::Object<ComprasDto>>{
  DTO_INIT(comprasPageDto, PageDto<oatpp::Object<ComprasDto>>)
};

//PAGE VENTAS MOD
class listaProdVentasPageDto : public PageDto<oatpp::Object<ListaProdVentaDto>>{
  DTO_INIT(listaProdVentasPageDto, PageDto<oatpp::Object<ListaProdVentaDto>>)
};
class ventaPageDto : public PageDto<oatpp::Object<VentaDto>> {
  DTO_INIT(ventaPageDto, PageDto<oatpp::Object<VentaDto>>)
};
#include OATPP_CODEGEN_END(DTO)

#endif //page_dto_hpp