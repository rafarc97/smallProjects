#ifndef _LOGISTICA
#define _LOGISTICA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Menu.h"



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


//precondicion: pasarle un pedido y las estructuras inicializadas-
//postcondicion: asignar un transportista a un pedido
//cabecera:
void pe_asignar_trans(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr,int aux_pedido);

//precondicion: pasarle un pedido y las estructuras inicializadas-
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl, int aux_pedido);

//precondicion: Estructura inicializada, pasarle un incremento, fecha a incrementar y la posicion del campo.
//postcondicion: incrementar la fecha acorde al incremento para el locker.
//cabecera:
void incrementar_fecha_locker(comp_lockers **cl, int incremento, char fechayhora[9],int i);

//precondicion: estructuras inicializadas
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl);

//precondicion: estructuras inicializadas
//postcondicion: asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
//cabecera:
void pe_asignar_locker_proveedor(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl,usuario **usu,prod **pr);

//precondicion: estructuras inicializadas
//postcondicion: El admin asigna un transportista a un pedido del sistema, respecto la localidad.
//cabecera:
void pe_asignar_trans_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr);


//precondición: recibe la estructura comp_lockers,lockers y un entero
//postcondición: actualiza el almacenamiento de ese locker.
//cabecera:
void locker_compartimentos_act(comp_lockers **cl, lockers **lo,int locker);

//precondición: recibe la estructura,lockers y una ciudad
//postcondición: lista los lockers de la ciudad pasada.
//cabecera:
void listado_lockers(lockers **lo, char *ciudad);

//precondición: recibe la estructuras inicializadas y un id locker
//postcondición: dar de alta un locker un nuevo compartimento del locker recibido.
//cabecera:
void dar_alta_complocker(comp_lockers **cl, lockers **lo, int locker);


#endif

