#ifndef DEVOLUCIONES_H
#define DEVOLUCIONES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Menu.h"


//---------------------------------

void cargar_pedidos(pedidos **pe);
void guardar_devoluciones(devoluciones **dev);
void cargar_devoluciones(devoluciones **dev);
//VARIABLES

int ndevoluciones; // cantidad de devoluciones

int nt_pedidos;
int nt_prodpedidos; // numero de estructuras de prod_pedidos

int ncliente;
int nadminprov;
int ntransport;

int puerta_listar;
int puerta_alta; // =1 se puede dar de alta. =0 NO se puede dar de alta.






/* -----------------------------------------------------------FUNCIONES DE OTROS MODULOS----------------------------------------*/

/* -----------------------------------------------------------FUNCIONES DE OTROS MODULOS---------------------------------------- */

/* -----------------------------------------------------------FUNCIONES DONDE SE UTILIZAN OTROS MODULOS-------------------------*/

//precondicion: el cliente debe haber realizado un pedido
//postcondicion: dar de alta una devolucion
//cabecera: void dev_alta_cliente(devoluciones **de,usuario **usu,cliente **c)
void dev_alta_cliente(devoluciones **de,pedidos **pe,prod_pedidos **ppe,usuario **usu,cliente **c);


//precondicion:Debe existir algun cliente en el sistema con pedidos
//postcondicion: dar de alta una devolucion
//cabecera: void dev_alta_cliente(devoluciones **de,usuario **usu,cliente **c)
void dev_alta_admin(devoluciones **de,pedidos **pe,prod_pedidos **ppe,usuario **usu,cliente **c);


//precondicion: pasar un id_cliente
//postcondicion:
//cabecera: dev_existe_cliente(pedidos **pe,int cliente);
int dev_existe_cliente(pedidos **pe,int aux_cliente);


//precondicion:Debe existir alguna devolucion
//postcondicion: dar de baja una devolucion
//cabecera: dev_baja_admin(devoluciones **dev,pedidos **pe,prod_pedidos **ppe,usuario **usu,cliente **c);
void dev_baja_admin(devoluciones **dev,pedidos **pe,prod_pedidos **ppe,usuario **usu,cliente **c);

/* -----------------------------------------------------------FUNCIONES DONDE SE UTILIZAN OTROS MODULOS----------------------------*/

//---------------
//FUNCIONES CLIENTES:
//---------------

//precondicion:
//postcondicion:cliente podra ver el estado de su devolucion/es
//cabecera:
void dev_seguimiento(devoluciones **dev,pedidos **pe,usuario **usu,cliente **c);

//precondicion: el cliente debe haber dado de alta algun pedido
//postcondicion: el cliente podra ver las devoluciones que han sido aceptadas
//cabecera:
void dev_enviar(devoluciones **dev,pedidos **pe,usuario **usu,cliente **c);


//---------------
//FUNCIONES ADMINS
//---------------

//precondicion: pasar un id_pedido
//postcondicion: si pos!=-1 ese pedido existe en dev. si pos==-1 ese pedido no se ha devuelto.
//cabecera: dev_existe_cliente(pedidos **pe,int cliente);
int dev_existe_devolucion(devoluciones **dev,int devol);

//precondicion: pasar un id_pedido
//postcondicion: si pos!=-1 ese pedido existe en dev. si pos==-1 ese pedido no se ha devuelto.
//cabecera: dev_existe_cliente(pedidos **pe,int cliente);
int dev_existe_devolucion_seguimiento(devoluciones **dev,int devol);

//precondicion: pasar como parametro actual un id_pedido
//postcondicion: devuelve 1 si el estado del pedido es "pendiente".
//cabecera:
int dev_pendiente(devoluciones **dev, pedidos **pe,int id_aux_pedido);

//precondicion: pasar como parametro actual un id_pedido
//postcondicion: devuelve 1 si el estado del pedido es "recibido".
//cabecera:
int dev_enviado(devoluciones **dev, pedidos **pe,int id_aux_pedido);

//precondicion: pasar como parametro actual un id_pedido
//postcondicion: devuelve 1 si el estado del pedido es "aceptado".
//cabecera:
int dev_aceptado(devoluciones **dev, pedidos **pe,int id_aux_pedido);

//precondicion: pasar como parametro actual un id_pedido
//postcondicion: devuelve la posicion dentro de la estructura devoluciones
int dev_pendiente_recibido_posicion(devoluciones **dev, pedidos **pe,int id_aux_pedido);

//precondicion:
//postcondicion: el admin visualizara todas las devoluciones del sistema.
//cabecera:
void dev_listar(devoluciones **dev,pedidos **pe);


//precondicion: existir al menos una devolucion en el sistema.
//postcondicion: dar de baja una devolucion.
//cabecera:
void dev_baja(devoluciones **de);

//precondicion:0
//postcondicion: modificar el estado de la dev(aceptada,recibido...)
//si es aceptada la fecha aceptacion y fecha de caducidad se actualiza.
//cabecera:
void dev_modificar(devoluciones **de,pedidos **pe);

//precondicion: pasar un cliente y un pedido
//postcondicion: 1 si el pedido y el cliente coinciden, 0 si no.
//cabecera:
int dev_cliente_pedidos(int pedido,int cliente,pedidos **pe);

#endif
