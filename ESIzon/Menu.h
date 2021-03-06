
#ifndef _MENU
#define _MENU
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

typedef struct
{
    int id_cat;
    char descr[100];
} catg;

typedef struct
{
    int id_prod;
    char descrp[100];
    int id_categoria;
    int id_gestor;
    int stock;
    int compromiso;
    float importe;
} prod;


typedef struct
{
    int id;
    char nom[30];
    char apell[30];
    char dir[50];
    char loc[20];
    char prov[20];
    char mail[50];
    char pass[15];
    float cartera;
} cliente;

typedef struct
{

    int  id_empr;
    char name_empr[30];
    char mail[50];
    char pass[30];
    char type[10];

} adminprov;

typedef struct
{
    int id;
    int pos;
    int tipo; //1.-Cliente     2.-Admin   3.-Proveedor    4.-Transportistas

} usuario;

typedef struct
{
    int id_trans;
    char mail[50];
    char pass[15];
    char nomb_emp[30];
    char city[25];
} transport;


typedef struct
{
    int id_pedido;
    char fch_ped[9];
    int id_cliente;
    char lugar_entrega[30];
    int id_locker;
    int cheque;
    int promo;
} pedidos;

typedef struct
{
    int id_pedido;
    int id_prod;
    int unidades;
    char fech_entr[9];
    float importe;
    char estado[15];
    int id_trans;
    int cod_locker;
    char fech_entrdev[9];
} prod_pedidos;

int nt_pedidos; // numero de estructuras de pedidos
int nt_prodpedidos; // numero de estructuras de prod_pedidos

//taquillas de los pedidos donde se van a entregar o se han entregado los productos
typedef struct
{
    int id_locker; //Id. Locker
    int n_compartimento; //Nº compartimento
    int codigo; //Código locker
    char estado[30]; //Ocupado/Vacio
    char fch_ocup[9]; //Fecha ocupacion
    char fch_ca[9]; //Fecha caducidad
} comp_lockers;
int ncomp_lockers;

typedef struct
{
    int id_locker; //Id. Locker
    char locali[30]; //Localidad
    char prov[30]; //Provincia
    char ubicacion[30]; //Ubicación
    int n_comp_total; //Nº total de compartimentos
    int n_comp_ocupados; //Nº de compartimentos ocupados
} lockers;
int nlockers;

typedef struct
{
    int id_trans;
    char email[30];
    char psswd[30];
    char nomb_emp[30];
    char city[30];
} transportistas;
int ntransportistas;

typedef struct
{
    int id_promo; //cambiar caracteres
    char descr[100];
    char tipo_cod[30];
    char estado[30];
    float importe;
    char aplic[30];
} descuentos;
int ndescuentos;

typedef struct
{
    int id;
    int cod;
    int fch_as;
    int fch_ca;
    char apl[30];
} descliente;
int ndescliente;


typedef struct
{
    int id_pedido;
    int id_prod;
    char fech_dev[9];
    char motivo[100];
    char estado[20];
    char fech_acep[9];
    char fech_cad[9];
} devoluciones;



//variables

int ncatg;
int nprod;
int cesta[1000];
int ncesta;
int ncliente;
int nadminprov;
int ntransport;




////////////////////////////////////////////////////

//cabecera: void guardar_productos(prod **pr)
//precondicion:
//postcondicion: cuando las acciones han terminado devuelve 1
int interfaz(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl);

//cabecera: void guardar_productos(prod **pr)
//precondicion:
//postcondicion: cuando las acciones han terminado devuelve 1
int menu_cliente(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl);

//cabecera: void guardar_productos(prod **pr)
//precondicion:
//postcondicion:
int menu_administrador(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl);

//cabecera: int menu_proveedor(adminprov **ap, usuario **usu, prod **pr, catg **ca)
//precondicion: necesita todas las estructuras
//postcondicion: cuando las acciones han terminado devuelve 1
int menu_proveedor(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl);

//cabecera: void presentacion()
//precondicion:
//postcondicion: Muestra una bonita presentacion
void presentacion();


#endif
