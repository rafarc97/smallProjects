#include "Descuentos.h"

/*

----HASTA AQUÍ TODO HECHO-----

Y en el caso de la creación de un nuevo código promocional, éste deberá
ser asignado a todos los clientes.*/



//sin * te refieres a la dir de una estructura
//con 1 * a la dir de la variable de una estructura
//con 2 * al valor de la variable de una estructura




//Por supuesto podrá asignar a un cliente determinado un cheque
//regalo.


void add_desc_clien(descliente **desc)
{

    ndescliente++;
    *desc=(descliente*)realloc((*desc),(ndescliente+1)*sizeof(descliente));


    printf("Introduce los datos del descuento del cliente: \n");

    printf("Id. Descuento: \n");
    scanf("%i", &desc[ndescliente]->id);
    printf("Id. Cliente: \n");
    scanf("%s", &desc[ndescliente]->cod);
    printf("Fecha asignación: \n");
    scanf("%i", &desc[ndescliente]->fch_as);
    printf("Fecha caducidad: \n");
    scanf("%i", &desc[ndescliente]->fch_ca);
    printf("Aplicabilidad: \n");
    scanf("%i", &desc[ndescliente]->apl);

    guardar_descliente(desc);

}



/*Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados
y modificaciones de estos descuentos.*/


void alta_des(descuentos **des)
{

    ndescuentos++;
    *des=(descuentos*)realloc((*des),(ndescuentos+1)*sizeof(descuentos));

    printf("Introduce los datos del descuento:\n");

    printf("Id. Código:");
    scanf("%i", des[ndescuentos]->id_promo);
    //printf("%i", des[ndescuentos]->id_promo);
    printf("\nDescripción:");
    scanf("%s", des[ndescuentos]->descr);
    printf("\nTipo:");
    scanf("%s", &des[ndescuentos]->tipo_cod);
    printf("\nEstado: ");
    scanf("%i", &des[ndescuentos]->estado);
    printf("\nImporte:");
    scanf("%f", &des[ndescuentos]->importe);
    printf("\nAplicabilidad:");
    scanf("%s", &des[ndescuentos]->aplic);

    guardar_descuentos(des);

}

void baja_des(descuentos **des)
{

    int i;
    int aux2 = 0;

    int idpromo, status;
    float import;
    char descripcion[100], tipocod[8], aplicable[8];

    while (aux2 == 0)
    {
        if ((i = busqueda_des(des)) >= 0)
        {

            //Intercambiamos valores
            idpromo = (*des)[i].id_promo;
            (*des)[i] = (*des)[ndescuentos-1];
            (*des)[i].id_promo = idpromo;


            ndescuentos--;
            *des=(descuentos*)realloc((*des),(ndescuentos+1)*sizeof(descuentos));

            aux2 = 1;
        }
        else
        {
            printf("Introduce correctamente el Id. Código.\n");
        }
    }

    guardar_descuentos(&des);
}

/*Devuelve -1 si no encuentra el código de descuento recibido por parámetros,
y su pos en la que se encuentra si lo encuentra*/



/*Devuelve -1 si no encuentra el código de descuento recibido por parámetros,
y su pos en la que se encuentra si lo encuentra*/



void modificar_des(descuentos **des)
{

    int i;
    int aux = 0, aux2 = 0;
    int campo;
    while (aux == 0)
    {

        printf("Indica el numero correspondiente al campo a modificar: \n");
        printf("1. Id. Código\n 2. Descripción\n 3. Tipo\n 4. Estado\n 5. Importe\n 6. Aplicabilidad\n");
        scanf("%i", &campo);

        if ((campo < 0) || (campo > 6))
            printf("Introduce un numero correcto\n");
        else
            aux = 1;
    }

    while (aux2 == 0)
    {
        if ((i = busqueda_des(des)) >= 0)
        {
            switch (campo)
            {
            case 1:
                printf("Nuevo Id. Código:");
                scanf("%i", des[i]->id_promo);
                aux2 = 1;
                break;
            case 2:
                printf("Nueva Descripción:");
                scanf("%s", des[i]->descr);
                aux2 = 1;
                break;
            case 3:
                printf("Nuevo Tipo:");
                scanf("%s", des[i]->tipo_cod);
                aux2 = 1;
                break;
            case 4:
                printf("Nuevo Estado:");
                scanf("%i", des[i]->estado);
                aux2 = 1;
                break;
            case 5:
                printf("Nuevo Importe:");
                scanf("%f", des[i]->importe);
                aux2 = 1;
                break;
            case 6:
                printf("Nueva Aplicabilidad:");
                scanf("%s", des[i]->aplic);
                aux2 = 1;
                break;
            default:
                printf("Error\n");
            }
        }
        else
        {
            printf("Introduce correctamente el Id. Código.\n");
        }
    }
}


//FUNCIONA
void listar_des(descuentos **des)
{
    for(int i = 0; i < ndescuentos; i++)
        printf(" Id. Código: %i\n Descripción: %s\n Tipo: %s\n Estado: %i\n Importe: %.2f\n Aplicabilidad: %s\n\n\n", (*des)[i].id_promo, (*des)[i].descr, (*des)[i].tipo_cod, (*des)[i].estado, (*des)[i].importe, (*des)[i].aplic);
}

/*Además también podrá generar los listados de
clientes que tienen asignado algún cheque regalo/código promocional*/

//FUNCIONA
void listar_desc(descliente **desc)
{
    char hola[15];

    for (int i = 0; i < ndescliente; i++){

        if((*desc)[i].apl == 1)
        {
            printf("hola");
            strcpy(hola, "aplicable");
        }
        else
        {
            strcpy(hola, "no aplicable");
        }
    printf(" Id. Código Cliente: %i\n Id Código Descuento: %s\n Fecha de Asignación: %i\n Fecha de Caducidad: %i\n Aplicabilidad: %s\n\n\n", (*desc)[i].id, (*desc)[i].cod, (*desc)[i].fch_as, (*desc)[i].fch_ca, hola);
    }
}


/*así como los listados de clientes que han hecho uso de algún cheque regalo/código
promocional.*/

//FUNCIONA
void listar_desc_usados(descliente **desc)
{

    for(int i = 0; i < ndescliente; i++)
    {
        if((*desc)[i].apl == 1)
            printf("Id. Código Cliente: %i\n Id Código Descuento: %s\n Fecha de Asignación: %i\n Fecha de caducidad: %i\n Aplicabilidad : %s\n\n\n", (*desc)[i].id, (*desc)[i].cod, (*desc)[i].fch_as, (*desc)[i].fch_ca, "aplicable");
    }
}





//DESCUENTOS PROVEEDOR
/*Mediante esta opción el cliente podrá consultar todos los códigos promocionales y
cheques regalo que tiene asignados.*/


//FUNCIONA
void list_todos_desc_cada_cliente(descliente **desc)
{

    int i;
    int aux2 = 0;

    while (aux2 == 0)
    {
        if ((i = busqueda_cliente(desc)) >= 0)
        {
            for(int j = i; j < ndescliente; j++)
            {
                if((*desc)[i].id == (*desc)[j].id)
                    printf("%s\n", (*desc)[j].cod);
            }

        }
        else
        {
            printf("Introduce correctamente el Id. Código.\n");
        }
        aux2 = 1;
    }
}


void listar_descuentos_cliente(descliente **desc,int id_cliente)
{
	int i;
	for(i=0; i<ndescliente;i++)
	{
		if((*desc)[i].id == id_cliente)
		{
			printf("\nId. Código Cliente: %i\n Id Código Descuento: %i\n Fecha de Asignación: %i\n Fecha de caducidad: %i\n Aplicabilidad: %s\n\n\n", (*desc)[i].id, (*desc)[i].cod, (*desc)[i].fch_as, (*desc)[i].fch_ca, (*desc)[i].apl);
		}
	}
	system("Pause");
}




/*CARGAS Y GUARDAS DESCUENTOS Y DESCLIENTES*/

//FUNCIONA
void cargar_descuentos(descuentos **des)
{

    char linea[500];
    char *token;
    FILE *f;

    ndescuentos=0;


    f=fopen("Descuentos.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *des=malloc(1*sizeof(descuentos));

        while(fgets(linea,500,f)!=NULL)
        {
            *des=(descuentos*)realloc((*des),(ndescuentos+1)*sizeof(descuentos));

            if((*des)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*des)[ndescuentos].id_promo=atoi(token);
                //leer entre barras del ficharo y lo guarda en la variable token.
                token=strtok(NULL,"/");
                strcpy((*des)[ndescuentos].descr,token);
                token=strtok(NULL,"/");
                strcpy((*des)[ndescuentos].tipo_cod,token);
                token=strtok(NULL,"/");
                strcpy((*des)[ndescuentos].estado,token);
                token=strtok(NULL,"/");
                (*des)[ndescuentos].importe=atof(token);
                token=strtok(NULL,"\n");
                strcpy((*des)[ndescuentos].aplic,token);
                ndescuentos++;
            }
        }
        fclose(f);
    }
}

void guardar_descuentos(descuentos **des)
{
    FILE *f;
    f=fopen("Descuentos.txt","w+");
    for(int i=0; i<ndescuentos; i++)
    {
        fprintf(f,"%i/%s/%s/%i/%.2f/%s\n",(*des)[i].id_promo,(*des)[i].descr,(*des)[i].tipo_cod,(*des)[i].estado,(*des)[i].importe, (*des)[i].aplic);
    }
    fclose(f);
}

//FUNCIONA
void cargar_descliente(descliente **desc) //CAMBIO ENTERO
{

    char linea[120];
    char *token;
    FILE *f;

    ndescliente=0;

    f=fopen("DescuentosClientes.txt","a+");

    if(f==NULL)
        puts("Error de apertura");
    else
    {
        rewind(f);
        *desc=(descliente*)malloc(1*sizeof(descliente));

        while(fgets(linea,120,f)!=NULL)
        {

            *desc=(descliente*)realloc((*desc),(ndescliente+1)*sizeof(descliente));

            if((*desc)==NULL)
                puts("No hay memoria suficiente");
            else
            {
                token=strtok(linea,"/");
                (*desc)[ndescliente].id=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                (*desc)[ndescliente].cod=atoi(token);
                token=strtok(NULL,"/");
                (*desc)[ndescliente].fch_as=atoi(token);
                token=strtok(NULL,"/");
                (*desc)[ndescliente].fch_ca=atoi(token);
                token=strtok(NULL,"\n");
                strcpy((*desc)[ndescliente].apl,token);
                ndescliente++;
            }
        }
        fclose(f);
    }
}

void guardar_descliente(descliente **desc) //CAMBIO ENTERO
{

    FILE *f;
    int i;
    f=fopen("DescuentosClientes.txt","w+");
    for(i=0; i<ndescliente; i++)
        fprintf(f,"%i/%i/%i/%i/%s\n",(*desc)[i].id,(*desc)[i].cod,(*desc)[i].fch_as,(*desc)[i].fch_ca,(*desc)[i].apl);

    fclose(f);
}
