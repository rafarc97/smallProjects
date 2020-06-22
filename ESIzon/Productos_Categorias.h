


#ifndef _PRODUCTOS_CATEGORIAS
#define _PRODUCTOS_CATEGORIAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "Menu.h"




//cabecera: void cargar_categorias(catg **cat)
//precondicion:
//postcondicion:
void cargar_categorias(catg **cat);

//cabecera:void guardar_categorias(catg **cat)
//precondicion:
//postcondicion:
void guardar_categorias(catg **cat);

//cabecera: void cargar_productos(prod **pr
//precondicion:
//postcondicion:
void cargar_productos(prod **pr);

//cabecera: void guardar_productos(prod **pr)
//precondicion:
//postcondicion:
void guardar_productos(prod **pr);

//cabecera: int busqueda_producto(char* nombre, prod **pr)
//precondicion: es necesario una cadena con la que comparar y la estructura producto
//postcondicion: devuelve la direccion de memoria de un vector de enteros donde la posicion 0 es la cantidad de coincidencias encontradas y
//el resto del vector son las posiciones en el vector productos de las coincidencias, si no encuentra la primera posicion 0 del vector es -1
int busqueda_producto(char* nombre, prod **pr);

//cabecera: int buscar_producto(char* nombre, prod **pr)
//precondicion: es necesario una cadena con la que comparar y la estructura categoria
//postcondicion: devuelve la posicion en el vector de estucturas producto de la coincidencia completa, si no encuentra devuelve -1
int buscar_producto(char* nombre, prod **pr);

//cabecera: void registrar_producto(prod **pr, catg **ca, adminprov **ap, usuario **usu)
//precondicion:
//postcondicion:
void registrar_producto(prod **pr, catg **ca, adminprov **ap, usuario **usu);

//cabecera: void eliminar_producto(prod **pr)
//precondicion:
//postcondicion: elimina el producto
void eliminar_producto(prod **pr);

//cabecera: void modificar_producto(prod **pr, catg **ca, usuario **usu);
//precondicion:
//postcondicion: modifica las estructura producto
void modificar_producto(prod **pr, catg **ca, usuario **usu);

//cabecera: int busqueda_categoria(char* nombre, catg **ca)
//precondicion: es necesario una cadena con la que comparar y la estructura categoria
//postcondicion: devuelve la direccion de memoria de un vector de enteros donde la posicion 0 es la cantidad de coincidencias encontradas y
//el resto del vector son las posiciones en el vector categorias de las coincidencias, si no encuentra la primera posicion 0 del vector es -1
int busqueda_categoria(char* nombre, catg **ca);

//cabecera: int buscar_categoria(char* nombre, catg **ca)
//precondicion: es necesario una cadena con la que comparar y la estructura categoria
//postcondicion: devuelve la posicion en el vector de estucturas categoria de la coincidencia completa, si no encuentra devuelve -1
int buscar_categoria(char* nombre, catg **ca);

//cabecera: void listado_categorias(catg **ca)
//precondicion:
//postcondicion: crea un listado de todas las categorias
void listado_categorias(catg **ca);

//cabecera: void listado_productos(prod **pr, int *vec)
//precondicion: esta funcion se enlaza con la funcion de busqueda_productos, dado que trabaja con un vector del cual la posicion 0 indica la cantidad de elementos que debe listar y
// el resto del vector son las posiciones de los productos en el vector de estructuras de productos, si la posicion 0 del vector es -1 se hace un listado de todos los productos
//postcondicion: crea unn listado de todos los productos indicados
void listado_productos(prod **pr, int *vec);

//cabecera: void categoria_producto(prod **pr, int cat, int op)
//precondicion: recibe la id de categoria que se va a eliminar y la id de la ultima categoria
//postcondicion: asigna la id correcta a los productos despues de eliminar una categoria, significando 0 que no tiene categoria asignada
void categoria_producto(prod **pr, int cat, int op);

//cabecera: void registrar_categoria(catg **ca, adminprov **ap, usuario **usu)
//precondicion:
//postcondicion: registra una categoria
void registrar_categoria(catg **ca);

//cabecera: void eliminar_categorias(catg **ca, prod **pr)
//precondicion:
//postcondicion: elimina la categoria
void eliminar_categorias(catg **ca, prod **pr);

//cabecera: void modificar_categoria(catg **ca, prod **pr)
//precondicion:
//postcondicion: modifica el nombre de una categoria
void modificar_categoria(catg **ca);

//cabecera: void llenar_cesta(int posp)
//precondicion: se le envia la posicion del producto en la estructura
//postcondicion: se añade el producto a la cesta
void llenar_cesta(int posp);

//cabecera: void listado_cesta(prod **pr)
//precondicion:
//postcondicion: muestra los productos de la cesta en pantalla
void listado_cesta(prod **pr);

//cabecera: int busqueda_prodcatg(prod **pr, catg **ca, int id)
//precondicion: la id de categoria y estructuras de prod y catg
//postcondicion: devuelve la direccion de memoria de un vector cuyo primer valos es la cantidad encontrada,
//si no encuentra nada es igual a -1, y los demas valores son las posiciones de los productos en el vector de estructuras de productos
int busqueda_prodcatg(prod **pr, catg **ca, int id);





#endif
