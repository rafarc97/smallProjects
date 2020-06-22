
#ifndef _DATOSUSUARIOS
#define _DATOSUSUARIOS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Menu.h"





//fin variables

//cabecera: cargar_clientes(cliente **c, usuario **usu)
//precondici�n:
//postcondici�n:
void cargar_clientes(cliente **c, usuario **usu);

//cabecera: guardar_cliente(cliente **c)
//precondici�n:
//postcondici�n:
void guardar_cliente(cliente **c);

//cabecera: cargar_adminprov(adminprov **ap)
//precondici�n:
//postcondici�n:
void cargar_adminprov(adminprov **ap);

//cabecera: guardar_adminprov(adminprov **ap)
//precondici�n:
//postcondici�n:
void guardar_adminprov(adminprov **ap);

//cabecera: cargar_adminprov(adminprov **ap)
//precondici�n:
//postcondici�n:
void cargar_adminprov(adminprov **ap);

//cabecera: cargar_transportista(transport **tr)
//precondici�n:
//postcondici�n:
void cargar_transportista(transport **tr);

//cabecera: guardar_transportista(transport **tr)
//precondici�n:
//postcondici�n:
void guardar_transportista(transport **tr);

//cabecera: iniciar_sesion( cliente **c, adminprov **ap, transport **tr, usuario **usu )
//precondici�n: todas las estructuras de tipos de usuarios
//postcondici�n: rellena la estructura usuario y da paso a las demas funciones
void iniciar_sesion( cliente **c, adminprov **ap, transport **tr, usuario **usu );

//cabecera: void acceder_cuenta(cliente **c, adminprov **ap, transport **tr, usuario **usu)
//precondici�n: se necesita introducir correo y contrase�a
//postcondici�n: comprueba que el perfil existe
void acceder_cuenta(cliente **c, adminprov **ap, transport **tr, usuario **usu);

//cabecera: void tipo_usuario(usuario **usu)
//precondici�n: pide el tipo de usuario que inicia sesion
//postcondici�n: rellena el campo tipo de la estructura usuario
void tipo_usuario(usuario **usu);

//cabecera: void buscar_cliente(char* mail, cliente **c, usuario **usu)
//precondici�n: necesita una cadena para comparar con la estructura de clientes
//postcondici�n: solo pasa por la funcion si existe el cliente indicado
void buscar_cliente(char* mail, cliente **c, usuario **usu);

//cabecera: void buscar_adminprov(char* mail, adminprov **ap, usuario **usu)
//precondici�n: necesita una cadena para comparar con la estructura de adminprov
//postcondici�n: solo pasa por la funcion si existe el adminprov indicado
void buscar_adminprov(char* mail, adminprov **ap, usuario **usu);

//cabecera: void buscar_transport(char* mail, transport **tr, usuario **usu)
//precondici�n: necesita una cadena para comparar con la estructura de transport
//postcondici�n: solo pasa por la funcion si existe el transport indicado
void buscar_transport(char* mail, transport **tr, usuario **usu);

//cabecera: void modificar_clientes(cliente **c, usuario **usu)
//precondici�n:
//postcondici�n: da la posibilidad de modificar cualquier campo de clientes
void modificar_clientes(cliente **c, usuario **usu);

//cabecera: void modificar_administradores(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: da la posibilidad de modificar cualquier campo de administradores
void modificar_administradores(adminprov **ap, usuario **usu);

//cabecera: void modificar_proveedores(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: da la posibilidad de modificar cualquier campo de proveedores
void modificar_proveedores(adminprov **ap, usuario **usu);

//cabecera: void modificar_transportistas(transport **tr, usuario **usu)
//precondici�n:
//postcondici�n: da la posibilidad de modificar cualquier campo de transportistas
void modificar_transportistas(transport **tr, usuario **usu);

//cabecera: void comprobar_pass (char* pass)
//precondici�n: recibe la contrase�a correcta
//postcondici�n: da la posibilidad de reintentar o cerrar el programa
void comprobar_pass (char* pass);

//cabecera: void listado_clientes(cliente **c)
//precondici�n:
//postcondici�n: lista clientes
void listado_clientes(cliente **c);

//cabecera: void listado_admin(adminprov **ap)
//precondici�n:
//postcondici�n: lista administadores
void listado_admin(adminprov **ap);

//cabecera: void listado_prov(adminprov **ap)
//precondici�n:
//postcondici�n: lista proveedores
void listado_prov(adminprov **ap);

//cabecera: void listado_transport(transport **tr)
//precondici�n:
//postcondici�n: lista transportistas
void listado_transport(transport **tr);

//cabecera: void registrar_cliente(cliente **c, usuario **usu)
//precondici�n:
//postcondici�n: crea una nueva estructura clientes
void registrar_cliente(cliente **c, usuario **usu);

//cabecera: void eliminar_cliente(cliente **c, usuario **usu)
//precondici�n:
//postcondici�n: elimina una estructura cliente
void eliminar_cliente(cliente **c, usuario **usu);

//cabecera: void registrar_admin(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: crea una nueva estructura adminprov con tipo admin
void registrar_admin(adminprov **ap, usuario **usu);

//cabecera: void eliminar_admin(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: elimina una estructura adminprov con tipo admin
void eliminar_admin(adminprov **ap, usuario **usu);

//cabecera: void registrar_prov(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: crea una estructura adminprov con tipo prov
void registrar_prov(adminprov **ap, usuario **usu);

//cabecera: void eliminar_prov(adminprov **ap, usuario **usu)
//precondici�n:
//postcondici�n: elimina una estructura adminprov con tipo prov
void eliminar_prov(adminprov **ap, usuario **usu);

//cabecera: void registrar_transport(transport **tr, usuario **usu)
//precondici�n:
//postcondici�n: crea una estructura transportista
void registrar_transport(transport **tr, usuario **usu);

//cabecera: void eliminar_transport(transport **tr, usuario **usu)
//precondici�n:
//postcondici�n: elimina una estructura transportista
void eliminar_transport(transport **tr, usuario **usu);








#endif
//opcion para acceder a cada tipo de usuario por separado