#include "Productos.h"

void cargar_productos(t_productos **pr)
{

    char linea[100];
    char *token;
    FILE *f;

    nproductos=0;


    f=fopen("Productos.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *pr=malloc(1*sizeof(productos));

        while(fgets(linea,100,f)!=NULL)
        {
            *pr=(productos*)realloc((*pr),(nproductos+1)*sizeof(productos));

            if((*pr)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*pr)[nproductos].id_prod=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*pr)[nproductos].descrp,token);
                token=strtok(NULL,"/");
                (*pr)[nproductos].id_categoria=atoi(token);
                token=strtok(NULL,"/");
                (*pr)[nproductos].id_gestor=atoi(token);
                token=strtok(NULL,"\n");
                (*pr)[nproductos].stock=atoi(token);
                token=strtok(NULL,"\n");
                (*pr)[nproductos].compromiso=atoi(token);
                token=strtok(NULL,"\n");
                (*pr)[nproductos].importe=atoi(token);
                nproductos++;
            }
        }
        fclose(f);
    }
}

void guardar_productos(productos *pr)
{
    FILE *f;
    int i;
    f=fopen("Productos.txt","w+");
    for(i=0; i<nproductos; i++)
    {
        fprintf(f,"%i/%s/%i/%i/%i/%i/%f\n",pr[i].id_prod,pr[i].id_categoria,pr[i].id_gestor,pr[i].stock,pr[i].compromiso, pr[i].importe);
    }
    fclose(f);
}