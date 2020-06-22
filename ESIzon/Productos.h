#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	int id_prod;
	char descrp[100];
	int id_categoria;
	int id_gestor;
	int stock;
	int compromiso;
	float importe;
}t_productos;

//VARIABLES

int nproductos;

#endif