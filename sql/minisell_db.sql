PGDMP     :                    {            minisellpos    14.7    14.7 /    E           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            F           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            G           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            H           1262    24603    minisellpos    DATABASE     o   CREATE DATABASE minisellpos WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'Spanish_Latin America.1252';
    DROP DATABASE minisellpos;
                postgres    false                        3079    24918 	   uuid-ossp 	   EXTENSION     ?   CREATE EXTENSION IF NOT EXISTS "uuid-ossp" WITH SCHEMA public;
    DROP EXTENSION "uuid-ossp";
                   false            I           0    0    EXTENSION "uuid-ossp"    COMMENT     W   COMMENT ON EXTENSION "uuid-ossp" IS 'generate universally unique identifiers (UUIDs)';
                        false    2            �            1259    24625    category    TABLE     �   CREATE TABLE public.category (
    id_category character varying(256) NOT NULL,
    name_category character varying(150),
    metter_category numeric(250,0)
);
    DROP TABLE public.category;
       public         heap    postgres    false            �            1259    24743    cliente    TABLE     ;  CREATE TABLE public.cliente (
    id_cliente character varying(256) NOT NULL,
    dni_cliente character varying(50),
    nombre_cliente character varying(150),
    apellido_cliente character varying(150),
    telefono character varying(50),
    direccion character varying(256),
    email character varying(256)
);
    DROP TABLE public.cliente;
       public         heap    postgres    false            �            1259    24689    compra    TABLE       CREATE TABLE public.compra (
    id_compra character varying(256) NOT NULL,
    fecha_compra character varying(25),
    id_producto character varying(256),
    cantidad_producto numeric(256,0),
    precio_compra numeric(256,0),
    id_proveedor character varying(256)
);
    DROP TABLE public.compra;
       public         heap    postgres    false            �            1259    24611    empresa    TABLE       CREATE TABLE public.empresa (
    id_empresa character varying(256) NOT NULL,
    dni_empresa character varying(50),
    nombre_rs character varying(256),
    address character varying(256),
    telephone character varying(25),
    email character varying(256)
);
    DROP TABLE public.empresa;
       public         heap    postgres    false            �            1259    24677 
   inventario    TABLE     �   CREATE TABLE public.inventario (
    id_inventario character varying(256) NOT NULL,
    fecha_inventario character varying(25),
    id_lista_producto character varying(256)
);
    DROP TABLE public.inventario;
       public         heap    postgres    false            �            1259    24707    lista_prod_venta    TABLE     �   CREATE TABLE public.lista_prod_venta (
    id_lista_pv character varying(256) NOT NULL,
    id_producto character varying(256),
    cantidad numeric(256,0),
    precio_total numeric(256,0),
    id_venta character varying(256)
);
 $   DROP TABLE public.lista_prod_venta;
       public         heap    postgres    false            �            1259    24665    lista_producto    TABLE     �   CREATE TABLE public.lista_producto (
    id_lista_producto character varying(256) NOT NULL,
    id_producto character varying(256),
    cantidad_producto numeric(256,0),
    precio_total numeric(256,0)
);
 "   DROP TABLE public.lista_producto;
       public         heap    postgres    false            �            1259    24630    producto    TABLE     �   CREATE TABLE public.producto (
    id_producto character varying(256) NOT NULL,
    serial_producto numeric(256,0),
    cat_producto character varying(256),
    desc_producto character varying(256),
    precio_producto numeric(256,0)
);
    DROP TABLE public.producto;
       public         heap    postgres    false            �            1259    24618 	   proveedor    TABLE       CREATE TABLE public.proveedor (
    id_proveedor character varying(256) NOT NULL,
    dni_proveedor character varying(256),
    nombre_rs character varying(256),
    email character varying(256),
    telephone character varying(50),
    address character varying(256)
);
    DROP TABLE public.proveedor;
       public         heap    postgres    false            �            1259    24604    users    TABLE       CREATE TABLE public.users (
    id_user character varying(256) NOT NULL,
    username character varying(50),
    email character varying(256),
    password character varying(256),
    type_user character varying(50),
    token character varying(256) DEFAULT 123456
);
    DROP TABLE public.users;
       public         heap    postgres    false            �            1259    24731    venta    TABLE     g  CREATE TABLE public.venta (
    id_venta character varying(256) NOT NULL,
    factura numeric(256,0),
    id_empresa character varying(256),
    fecha_venta character varying(25),
    hora_venta character varying(25),
    id_cliente character varying(256),
    monto_total numeric(256,0),
    pago_cliente numeric(256,0),
    cambio_cliente numeric(256,0)
);
    DROP TABLE public.venta;
       public         heap    postgres    false            ;          0    24625    category 
   TABLE DATA           O   COPY public.category (id_category, name_category, metter_category) FROM stdin;
    public          postgres    false    213   �;       B          0    24743    cliente 
   TABLE DATA           x   COPY public.cliente (id_cliente, dni_cliente, nombre_cliente, apellido_cliente, telefono, direccion, email) FROM stdin;
    public          postgres    false    220   <       ?          0    24689    compra 
   TABLE DATA           v   COPY public.compra (id_compra, fecha_compra, id_producto, cantidad_producto, precio_compra, id_proveedor) FROM stdin;
    public          postgres    false    217   �<       9          0    24611    empresa 
   TABLE DATA           `   COPY public.empresa (id_empresa, dni_empresa, nombre_rs, address, telephone, email) FROM stdin;
    public          postgres    false    211   �<       >          0    24677 
   inventario 
   TABLE DATA           X   COPY public.inventario (id_inventario, fecha_inventario, id_lista_producto) FROM stdin;
    public          postgres    false    216   E=       @          0    24707    lista_prod_venta 
   TABLE DATA           f   COPY public.lista_prod_venta (id_lista_pv, id_producto, cantidad, precio_total, id_venta) FROM stdin;
    public          postgres    false    218   b=       =          0    24665    lista_producto 
   TABLE DATA           i   COPY public.lista_producto (id_lista_producto, id_producto, cantidad_producto, precio_total) FROM stdin;
    public          postgres    false    215   =       <          0    24630    producto 
   TABLE DATA           n   COPY public.producto (id_producto, serial_producto, cat_producto, desc_producto, precio_producto) FROM stdin;
    public          postgres    false    214   �=       :          0    24618 	   proveedor 
   TABLE DATA           f   COPY public.proveedor (id_proveedor, dni_proveedor, nombre_rs, email, telephone, address) FROM stdin;
    public          postgres    false    212   �=       8          0    24604    users 
   TABLE DATA           U   COPY public.users (id_user, username, email, password, type_user, token) FROM stdin;
    public          postgres    false    210   />       A          0    24731    venta 
   TABLE DATA           �   COPY public.venta (id_venta, factura, id_empresa, fecha_venta, hora_venta, id_cliente, monto_total, pago_cliente, cambio_cliente) FROM stdin;
    public          postgres    false    219   O?       �           2606    24629    category pk_id_category 
   CONSTRAINT     t   ALTER TABLE ONLY public.category
    ADD CONSTRAINT pk_id_category PRIMARY KEY (id_category) INCLUDE (id_category);
 A   ALTER TABLE ONLY public.category DROP CONSTRAINT pk_id_category;
       public            postgres    false    213            �           2606    24749    cliente pk_id_cliente 
   CONSTRAINT     p   ALTER TABLE ONLY public.cliente
    ADD CONSTRAINT pk_id_cliente PRIMARY KEY (id_cliente) INCLUDE (id_cliente);
 ?   ALTER TABLE ONLY public.cliente DROP CONSTRAINT pk_id_cliente;
       public            postgres    false    220            �           2606    24695    compra pk_id_compra 
   CONSTRAINT     l   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT pk_id_compra PRIMARY KEY (id_compra) INCLUDE (id_compra);
 =   ALTER TABLE ONLY public.compra DROP CONSTRAINT pk_id_compra;
       public            postgres    false    217            �           2606    24617    empresa pk_id_empresa 
   CONSTRAINT     p   ALTER TABLE ONLY public.empresa
    ADD CONSTRAINT pk_id_empresa PRIMARY KEY (id_empresa) INCLUDE (id_empresa);
 ?   ALTER TABLE ONLY public.empresa DROP CONSTRAINT pk_id_empresa;
       public            postgres    false    211            �           2606    24683    inventario pk_id_inventario 
   CONSTRAINT     |   ALTER TABLE ONLY public.inventario
    ADD CONSTRAINT pk_id_inventario PRIMARY KEY (id_inventario) INCLUDE (id_inventario);
 E   ALTER TABLE ONLY public.inventario DROP CONSTRAINT pk_id_inventario;
       public            postgres    false    216            �           2606    24671 #   lista_producto pk_id_lista_producto 
   CONSTRAINT     �   ALTER TABLE ONLY public.lista_producto
    ADD CONSTRAINT pk_id_lista_producto PRIMARY KEY (id_lista_producto) INCLUDE (id_lista_producto);
 M   ALTER TABLE ONLY public.lista_producto DROP CONSTRAINT pk_id_lista_producto;
       public            postgres    false    215            �           2606    24713    lista_prod_venta pk_id_lista_pv 
   CONSTRAINT     |   ALTER TABLE ONLY public.lista_prod_venta
    ADD CONSTRAINT pk_id_lista_pv PRIMARY KEY (id_lista_pv) INCLUDE (id_lista_pv);
 I   ALTER TABLE ONLY public.lista_prod_venta DROP CONSTRAINT pk_id_lista_pv;
       public            postgres    false    218            �           2606    24636    producto pk_id_producto 
   CONSTRAINT     t   ALTER TABLE ONLY public.producto
    ADD CONSTRAINT pk_id_producto PRIMARY KEY (id_producto) INCLUDE (id_producto);
 A   ALTER TABLE ONLY public.producto DROP CONSTRAINT pk_id_producto;
       public            postgres    false    214            �           2606    24624    proveedor pk_id_proveedor 
   CONSTRAINT     x   ALTER TABLE ONLY public.proveedor
    ADD CONSTRAINT pk_id_proveedor PRIMARY KEY (id_proveedor) INCLUDE (id_proveedor);
 C   ALTER TABLE ONLY public.proveedor DROP CONSTRAINT pk_id_proveedor;
       public            postgres    false    212            �           2606    24610    users pk_id_user 
   CONSTRAINT     e   ALTER TABLE ONLY public.users
    ADD CONSTRAINT pk_id_user PRIMARY KEY (id_user) INCLUDE (id_user);
 :   ALTER TABLE ONLY public.users DROP CONSTRAINT pk_id_user;
       public            postgres    false    210            �           2606    24737    venta pk_id_venta 
   CONSTRAINT     h   ALTER TABLE ONLY public.venta
    ADD CONSTRAINT pk_id_venta PRIMARY KEY (id_venta) INCLUDE (id_venta);
 ;   ALTER TABLE ONLY public.venta DROP CONSTRAINT pk_id_venta;
       public            postgres    false    219            �           2606    24750    venta fk_id_cliente    FK CONSTRAINT     �   ALTER TABLE ONLY public.venta
    ADD CONSTRAINT fk_id_cliente FOREIGN KEY (id_cliente) REFERENCES public.cliente(id_cliente) NOT VALID;
 =   ALTER TABLE ONLY public.venta DROP CONSTRAINT fk_id_cliente;
       public          postgres    false    219    220    3236            �           2606    24738    venta fk_id_empresa    FK CONSTRAINT        ALTER TABLE ONLY public.venta
    ADD CONSTRAINT fk_id_empresa FOREIGN KEY (id_empresa) REFERENCES public.empresa(id_empresa);
 =   ALTER TABLE ONLY public.venta DROP CONSTRAINT fk_id_empresa;
       public          postgres    false    211    3218    219            �           2606    24684    inventario fk_id_lista_producto    FK CONSTRAINT     �   ALTER TABLE ONLY public.inventario
    ADD CONSTRAINT fk_id_lista_producto FOREIGN KEY (id_lista_producto) REFERENCES public.lista_producto(id_lista_producto);
 I   ALTER TABLE ONLY public.inventario DROP CONSTRAINT fk_id_lista_producto;
       public          postgres    false    215    3226    216            �           2606    24672    lista_producto fk_id_producto    FK CONSTRAINT     �   ALTER TABLE ONLY public.lista_producto
    ADD CONSTRAINT fk_id_producto FOREIGN KEY (id_producto) REFERENCES public.producto(id_producto);
 G   ALTER TABLE ONLY public.lista_producto DROP CONSTRAINT fk_id_producto;
       public          postgres    false    214    3224    215            �           2606    24696    compra fk_id_producto    FK CONSTRAINT     �   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT fk_id_producto FOREIGN KEY (id_producto) REFERENCES public.producto(id_producto);
 ?   ALTER TABLE ONLY public.compra DROP CONSTRAINT fk_id_producto;
       public          postgres    false    214    3224    217            �           2606    24714    lista_prod_venta fk_id_producto    FK CONSTRAINT     �   ALTER TABLE ONLY public.lista_prod_venta
    ADD CONSTRAINT fk_id_producto FOREIGN KEY (id_producto) REFERENCES public.producto(id_producto);
 I   ALTER TABLE ONLY public.lista_prod_venta DROP CONSTRAINT fk_id_producto;
       public          postgres    false    218    214    3224            �           2606    24701    compra fk_id_proveedor    FK CONSTRAINT     �   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT fk_id_proveedor FOREIGN KEY (id_proveedor) REFERENCES public.proveedor(id_proveedor);
 @   ALTER TABLE ONLY public.compra DROP CONSTRAINT fk_id_proveedor;
       public          postgres    false    212    217    3220            �           2606    24755    lista_prod_venta fk_id_venta    FK CONSTRAINT     �   ALTER TABLE ONLY public.lista_prod_venta
    ADD CONSTRAINT fk_id_venta FOREIGN KEY (id_venta) REFERENCES public.venta(id_venta) NOT VALID;
 F   ALTER TABLE ONLY public.lista_prod_venta DROP CONSTRAINT fk_id_venta;
       public          postgres    false    218    219    3234            ;      x������ � �      B   t   x����  ��Q����E8~�p�����l��</�|2B�9�$�Ȉ��_�8������*C�:�-�VY��#�u/U��$���V�G߹�����=�mU�I)���#      ?      x������ � �      9   �   x��α�0��ڞ"\d��w�J������A�%c#@Kū?�A\�,�oC����3;�΀�ѩ�FK��dmj*��e�Hy>�2�:�Z��m��\��4S��|�u��B1��6�蓃"a����3׵�����Z� ��G      >      x������ � �      @      x������ � �      =      x������ � �      <      x������ � �      :   f   x�%�1�  ����9��/H�e�KDGG1#�M���C(8�~0�L5�g�B	Mt���S����#G���\2�M�5����Nߨ���X��cNәD=+��<��      8     x�]�Kj�1������,ٻf�E�P(�-��<J�@z�*!�P-$!�|���Czi�BC�PsWi�-yq��y���c~D��f/�ݪ�.����]�ZJ�F�3T�X�m2&��S�D����0��6�mz�<Ʌ�0���o��Q���RA�Ae�-wf���Ec��Dx�Zm¥`�v���n8=\Č��񴹁�L!W�h���ĦH3�S)��pӜ�&��W�>�q����$Xt����6���	(5h�q�~��Af�dr%]�W˲�:Ys]      A      x������ � �     