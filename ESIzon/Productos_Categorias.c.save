#include "Productos_Categorias.h"


void cargar_categorias(catg **cat)
{

    char linea[100];
    char *token;
    FILE *f;

    ncatg=0;


    f=fopen("Categorias.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *cat=malloc(1*sizeof(catg));

        while(fgets(linea,100,f)!=NULL)
        {
            *cat=(catg*)realloc((*cat),(ncatg+1)*sizeof(catg));

            if((*cat)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*cat)[ncatg].id_cat=atoi(token);
                token=strtok(NULL,"\n");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*cat)[ncatg].descr,token);
                ncatg++;
            }
        }
        fclose(f);
    }
}

void guardar_categorias(catg **cat)
{
    FILE *f;
    int i;
    f=fopen("Categorias.txt","w+");
    for(i=0; i<ncatg; i++)
    {
        fprintf(f,"%i/%s\n", (*cat)[i].id_cat, (*cat)[i].descr);
    }
    fclose(f);
}

void cargar_productos(prod **pr)
{

    char linea[100];
    char *token;
    FILE *f;

    nprod=0;
    ncesta = 1;
    cesta[0] = -1;

    f=fopen("Productos.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *pr=malloc(1*sizeof(prod));

        while(fgets(linea,100,f)!=NULL)
        {
            *pr=(prod*)realloc((*pr),(nprod+1)*sizeof(prod));

            if((*pr)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*pr)[nprod].id_prod=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*pr)[nprod].descrp,token);
                token=strtok(NULL,"/");
                (*pr)[nprod].id_categoria=atoi(token);
                token=strtok(NULL,"/");
                (*pr)[nprod].id_gestor=atoi(token);
                token=strtok(NULL,"/");
                (*pr)[nprod].stock=atoi(token);
                token=strtok(NULL,"/");
                (*pr)[nprod].compromiso=atoi(token);
                token=strtok(NULL,"\n");
                (*pr)[nprod].importe=atof(token);
                nprod++;
            }
        }
        fclose(f);
    }
}

void guardar_productos(prod **pr)
{
    FILE *f;
    int i;
    f=fopen("Productos.txt","w+");
    for(i=0; i<nprod; i++)
    {
        fprintf(f,"%i/%s/%i/%i/%i/%i/%.2f\n",(*pr)[i].id_prod, (*pr)[i].descrp, (*pr)[i].id_categoria, (*pr)[i].id_gestor, (*pr)[i].stock, (*pr)[i].compromiso, (*pr)[i].importe);
    }
    fclose(f);
}


// estoy metiendo la variable antes de comprobarla por eso entra en el if

int busqueda_producto(char* nombre, prod **pr) //devuelve la posicion de memoria del vector pos
{
    int c = 1;
    int pos[1000];
    pos[0] = -1;
    for(int i= 0; i < nprod; i++)
    {
        if(strstr((*pr)[i].descrp, nombre) != NULL)
        {
            pos[c] = i;
            c++;
        }
    }
    if(c != 1)
    {
        pos[0] = c - 1;
    }
    c = pos;
    return c;
}

int buscar_producto(char* nombre, prod **pr)// devuelve la posicion del vector
{
    int c = -1;
    for(int i= 0; i < nprod; i++)
    {
        if( strcmp((*pr)[i].descrp, nombre) == 0 )
        {
            c = i;
        }
    }
    return c;
}


void registrar_producto(prod **pr, catg **ca, adminprov **ap, usuario **usu)
{
    int aux = 0;
    int id, op;
    char name[100];
    nprod++;
    *pr=(prod*)realloc((*pr),(nprod+1)*sizeof(prod));
    system("cls");
    printf("Introduce un nuevo nombre de producto: ");
    fflush(stdin);
    gets(name);
    aux = buscar_producto(name, pr);
    strcpy((*pr)[nprod-1].descrp, name);
    if( aux != -1)
    {
        do
        {
            system("cls");
            printf("Este nombre de producto ya existe");
            printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);
        if(op == 1)
        {
            nprod--;
            *pr=(prod*)realloc((*pr),(nprod+1)*sizeof(prod));
            registrar_producto(pr,ca, ap, usu);
        }
    }
    else
    {

        system("cls");
        listado_categorias(ca);
        printf("Introduzca el ID de la categoria a la que pertenece este producto: ");
        fflush(stdin);
        scanf("%i", &id);
        aux = buscar_categoria((*ca)[id-1].descr, ca);

        if(aux == -1)
        {
            do
            {
                system("cls");
                printf("Este id de categoria no existe");
                printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                fflush(stdin);
                scanf("%i", &op);
                system("cls");
            }
            while(0>op|| op>2);
            if(op == 1)
            {
                registrar_categoria(ca);
            }
        }
        else
        {

            (*pr)[nprod-1].id_categoria = id;
            (*pr)[nprod-1].id_gestor = (*ap)[(*usu)->pos].id_empr;
            printf("Introduce el stock de este producto: ");
            scanf("%i", &(*pr)[nprod-1].stock);
            system("cls");

            printf("Introduce el nº maximo de dias que garantiza para la entrega del producto: ");
            scanf("%i", &(*pr)[nprod-1].compromiso);
            system("cls");

            printf("Introduce el precio del producto (Indique los decimales con punto): ");
            scanf("%f", &(*pr)[nprod-1].importe);
            system("cls");

            (*pr)[nprod-1].id_prod = nprod;

            guardar_productos(pr);
        }
    }
    return;
}

void modificar_producto(prod **pr, catg **ca, usuario **usu)
{

    int op, pos, posp, posc, id, check = 0;
    int *vec;
    int aux[3];
    aux[0] = -1;
    char name[100];

    if((*usu)->tipo == 3)
    {
        vec = producto_gestor((*usu)->id, pr);
    }

    listado_productos(pr, aux);

    printf("Introduce el nombre del producto: ");
    fflush(stdin);
    gets(name);
    pos = buscar_producto(name, pr);

    if((*usu)->tipo == 2)
    {
        vec = aux;
        vec[0] = 1;
        vec[1] = pos;
    }

    for(int cont = 1; cont <= vec[0] && check == 0; cont++)
    {
        if(pos == vec[cont])
        {
            check = 1;
        }
    }
    if(pos == -1 && check == 0)
    {
        system("cls");
        printf("\n No se encuentra este producto");
    }
    else
    {
        do
        {
            do
            {
                system("cls");
                printf("\n1.- Nombre de producto: %s\n2.- ID de categoria: %i\n3.- Stock: %i\n4.- Compromiso de entrega: %i\n5.- Precio: %.2f\n6.- Salir\nElija una opcion: ", (*pr)[pos].descrp, (*pr)[pos].id_categoria, (*pr)[pos].stock, (*pr)[pos].compromiso, (*pr)[pos].importe);
                fflush(stdin);
                scanf("%i", &op);
                switch(op)
                {
                case 1:
                    printf("Introduce un nuevo nombre de producto: ");
                    fflush(stdin);
                    gets(name);
                    posp = buscar_producto(name, pr);
                    printf("%i", pos);
                    printf("%s", (*pr)[pos].descrp);

                    if( posp != -1)
                    {
                        do
                        {
                            system("cls");
                            printf("Este nombre de producto ya existe");
                            printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                            fflush(stdin);
                            scanf("%i", &op);
                            system("cls");
                        }
                        while(0>op|| op>2);
                        if(op == 1)
                        {
                            modificar_producto(pr, ca, usu);
                        }
                    }
                    else
                    {
                        strcpy((*pr)[pos].descrp, name);
                    }
                    break;
                case 2:
                    listado_categorias(ca);
                    printf("Introduce un nuevo ID de categoria: ");
                    scanf("%i", &id);
                    posc = buscar_categoria((*ca)[id-1].descr, ca);

                    if(posc == -1)
                    {
                        do
                        {
                            system("cls");
                            printf("Este id de categoria no existe");
                            printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                            fflush(stdin);
                            scanf("%i", &op);
                            system("cls");
                        }
                        while(0>op|| op>2);
                        if(op == 1)
                        {
                            modificar_producto(pr, ca, usu);
                        }
                    }
                    else
                    {
                        (*pr)[pos].id_categoria = (*ca)[posc].id_cat;
                    }
                    break;
                case 3:
                    printf("Introduce el stock disponible: ");
                    scanf("%i", &(*pr)[pos].stock);
                    break;
                case 4:
                    printf("Introduce el nuevo compromiso de entrega: ");
                    scanf("%i", &(*pr)[pos].compromiso);
                    break;
                case 5:
                    printf("Introduce nuevo precio: ");
                    scanf("%f", &(*pr)[pos].importe);
                    break;
                case 6:
                    break;
                }
            }
            while(0>=op || op>6);

            system("cls");
            printf("\n1.- Modificar otro dato\n2.- cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            guardar_productos(pr);
        }
        while(op==1);
    }
    printf("aqui");
    system("Pause");
    return;
}




void eliminar_producto(prod **pr)
{

    int op, c;
    int lis[0];
    int id;
    lis[0] = -1;
    listado_productos(pr, lis);
    printf("Introduce el ID del producto que quiere eliminar: ");
    fflush(stdin);
    scanf("%i", &id);
    id--;
    c = buscar_producto((*pr)[id].descrp, pr);
    system("cls");
    if( c == -1)
    {
        do
        {
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);

        if(op == 1)
        {
            eliminar_producto(pr);
        }
    }
    else
    {
        nprod--;
        (*pr)[nprod].id_prod = id+1;
        (*pr)[id] = (*pr)[nprod];

        *pr=(prod*)realloc((*pr),(nprod+1)*sizeof(prod));
        guardar_productos(pr);
    }
    return;
}



void registrar_categoria(catg **ca)
{
    int aux = 0;
    int op;
    char name[100];
    ncatg++;
    *ca=(catg*)realloc((*ca),(ncatg+1)*sizeof(catg));
    system("cls");
    printf("Introduce un nuevo nombre de categoria: ");
    fflush(stdin);
    gets(name);
    aux = buscar_categoria(name, ca);
    if  ( aux == -1 )
    {
        strcpy((*ca)[ncatg-1].descr, name);
    }
    else
    {
        do
        {
            system("cls");
            printf("Esta categoria ya esta registrada\n");
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);
        if(op == 1)
        {
            ncatg--;
            *ca=(catg*)realloc((*ca),(ncatg+1)*sizeof(catg));
            registrar_categoria(ca);
        }
    }


    (*ca)[ncatg-1].id_cat = ncatg;

    guardar_categorias(ca);

    return;
}



void eliminar_categorias(catg **ca, prod **pr)
{
    int op, c;
    int id;

    printf("Introduce el ID de la categoria que quiere eliminar: ");
    fflush(stdin);
    scanf("%i", &id);
    id--;
    c = buscar_categoria((*ca)[id].descr, ca);
    system("cls");
    if( c == -1)
    {
        do
        {
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);

        if(op == 1)
        {
            eliminar_categorias(ca, pr);
        }
    }
    else
    {

        ncatg--;
        categoria_producto(pr, (id+1), 0);
        categoria_producto(pr, (*ca)[nprod-1].id_cat, id+1);

        (*ca)[ncatg].id_cat = id+1;
        (*ca)[id] = (*ca)[ncatg];
        *ca=(catg*)realloc((*ca),(ncatg+1)*sizeof(catg));

        guardar_categorias(ca);
        guardar_productos(pr);
    }
    return;
}


void modificar_categoria(catg **ca)
{
    int op, c;
    int id;

    printf("Introduce el ID de la categoria que quiere modificar: ");
    fflush(stdin);
    scanf("%i", &id);
    id--;
    c = buscar_categoria((*ca)[id].descr, ca);
    system("cls");
    if( c == -1)
    {
        do
        {
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);
        if(op == 1)
        {
            modificar_categoria(ca);
        }
    }
    else
    {
        printf("Introduzca el nuevo nombre de la categoria: ");
        scanf("%s",(*ca)[id].descr);
        guardar_categorias(ca);
    }
    return;

}



void categoria_producto(prod **pr, int cat, int op)
{
    for(int i= 0; i < nprod; i++)
    {
        if((*pr)[i].id_categoria == cat)
        {
            (*pr)[i].id_categoria = op;
        }
    }
    return ;
}




int busqueda_categoria(char* nombre, catg **ca)
{
    int c = 1;
    int pos[1000];
    pos[0] = -1;
    for(int i= 0; i < ncatg; i++)
    {
        if(strstr((*ca)[i].descr, nombre) != NULL)
        {
            pos[c] = i;
            c++;
        }
    }
    if(c != 1)
    {
        pos[0] = c - 1;
    }
    c = pos;
    return c;
}

int buscar_categoria(char* nombre, catg **ca)
{
    int c = -1;
    for(int i= 0; i < ncatg; i++)
    {
        if(strcmp((*ca)[i].descr, nombre) == 0)
        {
            c = i;
        }
    }

    return c;
}


void listado_categorias(catg **ca)
{
    printf("\n\n----------------------Categorias----------------------\n\n");
    for(int i = 0; i < ncatg; i++)
    {
        printf("%i/%s\n",(*ca)[i].id_cat,(*ca)[i].descr);
    }
    return;
}


void listado_productos(prod **pr, int *vec)
{
    printf("\n\n----------------------Productos----------------------\n\n");

    if(vec[0] == -1)
    {
        for(int i = 0; i < nprod; i++)
        {
            printf("%i/%s/%i/%i/%i/%i/%.2f\n",(*pr)[i].id_prod, (*pr)[i].descrp, (*pr)[i].id_categoria, (*pr)[i].id_gestor, (*pr)[i].stock, (*pr)[i].compromiso, (*pr)[i].importe);
        }

    }
    else
    {
        for(int i = 1; i <= vec[0]; i++)
        {
            printf("%i/%s/%i/%i/%i/%i/%.2f\n",(*pr)[vec[i]].id_prod, (*pr)[vec[i]].descrp, (*pr)[vec[i]].id_categoria, (*pr)[vec[i]].id_gestor, (*pr)[vec[i]].stock, (*pr)[vec[i]].compromiso, (*pr)[vec[i]].importe);
        }
    }
    return;
}

int busqueda_prodcatg(prod **pr, catg **ca, int id)
{
    int c = 1;
    int pos[1000];
    pos[0] = -1;
    for(int i= 0; i < nprod; i++)
    {
        if((*pr)[i].id_categoria == id)
        {
            pos[c] = i;
            c++;
        }
    }
    if(c != 1)
    {
        pos[0] = c - 1;
    }
    c = pos;
    return c;
}

void llenar_cesta(int posp)
{
    cesta[0] = ncesta;
    cesta[ncesta] = posp-1;
    ncesta++;
}

void listado_cesta(prod **pr)
{
    system("cls");
    printf("\n\n----------------------TU CESTA----------------------\n\n");
    for(int i = 1; i <= cesta[0]; i++)
    {
        printf("%s/%f\n",(*pr)[cesta[i]].descrp,(*pr)[cesta[i]].importe);
    }
    return;
}

int producto_gestor(int id, prod **pr)
{
    int c = 1;
    int pos[1000];
    pos[0] = -1;
    for(int i= 0; i < nprod; i++)
    {
        if((*pr)[i].id_gestor == id)
        {
            pos[c] = i;
            c++;
        }
    }
    if(c != 1)
    {
        pos[0] = c - 1;
    }
    c = pos;
    return c;
}



