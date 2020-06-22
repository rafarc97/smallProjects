#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Menu.h"

//cabecera: cargar_clientes(cliente **c, usuario **usu)
//precondición:
//postcondición:
void cargar_clientes(cliente **c,usuario **usu);

//cabecera: guardar_cliente(cliente **c)
//precondición:
//postcondición:
void guardar_cliente(cliente **c);

//cabecera: void cargar_productos(prod **pr
//precondicion:
//postcondicion:
void cargar_productos(prod **pr);

//cabecera: void guardar_productos(prod **pr)
//precondicion:
//postcondicion:
void guardar_productos(prod **pr);

//cabecera: void cargar_lockers(lockers **lo);
//precondición: recibe la estructura lockers
//postcondición: carga los datos de los ficheros
void cargar_lockers(lockers **lo);

//cabecera: void guardar_lockers(lockers **lo);
//precondición: recibe la estructura lockers
//postcondición: guarda los datos en el fichero
void guardar_lockers(lockers **lo);

//cabecera: void cargar_compartimentolockers(comp_lockers **cl);
//precondición: recibe la estructura comp_lockers
//postcondición: carga los datos del fichero
void cargar_compartimentolockers(comp_lockers **cl);

//cabecera: void guardar_comp_lockers(comp_lockers **cl);
//precondición: recibe la estructura comp_lockers
//postcondición: gaurda los datos en el fichero
void guardar_comp_lockers(comp_lockers **cl);

//cabecera: void cargar_descuentos(descuentos **des);
//precondición: recibe la estructura descuentos
//postcondición: carga los datos del fichero correspondiente
void cargar_descuentos(descuentos **des);

//cabecera: void guardar_descuentos(descuentos **des);
//precondición: recibe la estructura descuentos
//postcondición: guarda los datos en el fichero correspondiente
void guardar_descuentos(descuentos **des);

//cabecera: void cargar_descliente(descliente **desc);
//precondición: recibe la estructura descliente
//postcondición: carga los datos del fichero correspondiente
void cargar_descliente(descliente **desc);

//cabecera: void guardar_descliente(descliente **desc);
//precondición: recibe la estructura descliente
//postcondición: guarda los datos en el fichero correspondiente
void guardar_descliente(descliente **desc);

//cabecera: void cargar_transportista(transportistas **tr);
//precondición: recibe la estructura transportistas
//postcondición: carga los datos del fichero
void cargar_transportista(transportistas **tr);
void guardar_transportistas(transportistas **tr);

//precondición: recibe la estructura comp_lockers,lockers y un entero
//postcondición: actualiza el almacenamiento de ese locker.
void locker_compartimentos_act(comp_lockers **cl, lockers **lo,int locker);

//cabecera: int val_codprom(descuentos **des);
//precondición: recibe la estructura descuentos
//postcondición: devuelve 1 si el descuento está activo y 0 si no
int val_codprom(descuentos **des);

//cabecera: int busqueda_des(descuentos **des);
//precondición: recibe la estructura descuentos
//postcondición: devuelve -1 si no encuentra el descuento o un entero mayor que -1 con la posición dentro de la estructura descuentos correspondiente al descuento que se busca
int busqueda_des(descuentos **des);

//cabecera: int busqueda_cliente(descliente **desc);
//precondición: recibe la estructura descliente
//postcondición: devuelve -1 si no encuentra el descuento del cliente o un entero mayor que -1 con la posición dentro de la estructura descliente del que se busca
int busqueda_cliente(descliente **desc,int cliente);

void listado_lockers(lockers **lo, char *ciudad);
//---------------------------------------------------------------------------------------------------

//NOTAS IMPORTANTES:
//Las funciones que necesitan el (ID cliente) del cliente que este utilizando el sistema,
//se pasan como parametros para utilizarlas dentro de la funcion. Estas funciones seran marcadas para reconocerlas facilmente.


void prueba_impresion(pedidos **pe,prod_pedidos **ppe);




//------------FUNCIONES SISTEMA------------


//precondicion: Pasarle un ID_pedido (entero)
//postcondicion: si pos!=-1 ese pedido existe, si pos==-1 ese pedidp no existe
//cabecera:
int pe_existe_pedido(pedidos **pe,int pedido);

//precondicion: Pasarle un ID_pedido (entero)
//postcondicion: devuelvo un vector con los indices de las estructuras pord_pedidos para saber donde estan los  productos de ese pedido.
//cabecera:
int pe_existe_producto(prod_pedidos **ppe,int pedido);

//precondicion: Pasarle un ID_cliente (entero)
//postcondicion: devuelvo un vector con los indices de las estructuras pedidos para saber donde estan los  productos de ese cliente.
//cabecera:
int pe_existe_cliente(pedidos **pe,int aux_cliente);


//precondicion: pasarle un pedido
//postcondicion: listar todos los pedidos
//cabecera:
void pe_asignar_trans(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr,int aux_pedido);

//precondicion: Pasarle un id_pedido, la realiza el sistema cuando se da de alta un pedido
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl, int aux_pedido);

//precondicion: Estructura inicializada, pasarle un incremento, fecha a incrementar y la posicion del campo.
//postcondicion: incrementar la fecha acorde al incremento para el locker.
//cabecera:
void incrementar_fecha_locker(comp_lockers **cl, int incremento, char fechayhora[9],int pos);

//------------FUNCIONES ADMIN------------



//precondicion: estructuras inicializadas
//postcondicion: Eliminar un pedido
//cabecera:
void dar_baja_pedidos(pedidos **pe, prod_pedidos **ppe, cliente **c);

//precondicion: estructuras inicializadas
//postcondicion: crea un pedido, con sus correspondientes productos asignados a el.
//cabecera:
void dar_alta_pedidos(pedidos **pe,prod_pedidos **ppe, cliente **c,descuentos **des, usuario **usu,  prod **pr, descliente **desc, lockers **lo,comp_lockers **cl, transportistas **tr);

//precondicion: estructuras inicializadas
//postcondicion: Modificar algun campo de un pedido en concreto.
//cabecera:
void pe_modificar(pedidos **pe, cliente **c);

//precondicion: estructuras inicializadas
//postcondicion: Modificar algun campo de un producto pedido en concreto.
//cabecera:
void pe_modificar_prod(prod_pedidos **ppe,pedidos **pe,cliente **c);

//precondicion: estructuras inicializadas
//postcondicion: listar todos los pedidos
//cabecera:
void pe_listar_admin(pedidos **pe,cliente **c);

//precondicion: estructuras inicializadas,
//postcondicion: listar todos los pedidos
//cabecera:
void pe_listar_estado_admin(pedidos **pe); // PENDIENTE

//precondicion: estructuras inicializadas
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl);

//precondicion: estructuras inicializadas
//postcondicion: listar todos los pedidos
//cabecera:
void pe_asignar_trans_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr);

//precondicion: Estructura inicializada, pasarle un incremento, fecha a incrementar y la posicion del campo.
//postcondicion: incrementar la fecha acorde al incremento para el locker.
//cabecera:
void incrementar_fecha(prod_pedidos **ppe, int incremento, char fechayhora[9]);

//------------FUNCIONES CLIENTES------------

//precondicion: estructuras inicializadas
//postcondicion:El cliente visualizara una lista de sus pedidos realizados en la plataforma.
//cabecera:
void listar_pedidos_cliente(pedidos **pe,int cliente); // PASAR LA ID

//precondicion: estructuras inicializadas
//postcondicion:El cliente visualizara una lista de sus pedidos realizados en la plataforma.
//cabecera:void listar_pedidos_cliente(pedidos *pe,prod_pedidos **ppe,int cliente)
void consultar_estado(pedidos **pe ,prod_pedidos **ppe,int cliente);// PASAR LA ID

//precondicion: estructuras inicializadas
//postcondicion:
//cabecera:void listar_pedidos_cliente(pedidos *pe,prod_pedidos **ppe,int cliente)
void recogida_pedido(pedidos **pe,prod_pedidos **ppe,lockers **lo,comp_lockers **cl,int cliente);// PASAR LA ID

//------------FUNCIONES TRANSPORTISTAS------------

//precondicion: pasarle por parametro su id_trans
//postcondicion: cambiar el estado de los productos pedidos.
//cabecera:
void estado_pedido(pedidos **pe,prod_pedidos **ppe,transportistas **tr,int aux_trans);

//------------FUNCIONES PROVEEDORES------------

//precondicion: estructuras inicializadas
//postcondicion: listar todos los pedidos de ese proveedor.
//cabecera:
int listar_pedidos_proveedor(pedidos **pe, prod_pedidos **ppe, prod **pr, usuario **usu);

//precondicion: estructuras inicializadas
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker_proveedor(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl,usuario **usu,prod **pr);
	/*
	-Acceder únicamente a la información de los pedidos de productos que
 	él mismo suministra.

	-Gestionar el estado de dichos pedidos de productos,
 	asignar lockers, etc.
	*/








//MENU

#endif
