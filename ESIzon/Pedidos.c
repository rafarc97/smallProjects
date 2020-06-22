#include "Pedidos.h"


void dar_alta_complocker(comp_lockers **cl, lockers **lo, int locker)
{

    ncomp_lockers++;

    *cl=(comp_lockers*)realloc((*cl),(ncomp_lockers+1)*sizeof(comp_lockers));

    system("cls");
    listado_lockers(lo, (*lo)[locker].locali);

    (*cl)[ncomp_lockers].id_locker = locker;

    (*cl)[ncomp_lockers].n_compartimento = ncomp_lockers + 1;

    (*cl)[ncomp_lockers].codigo = ncomp_lockers + 1;

    strcpy((*cl)[ncomp_lockers].estado, "vacio");

    strcpy((*cl)[ncomp_lockers].fch_ocup, "00000000");
    strcpy((*cl)[ncomp_lockers].fch_ca, "00000000");

    (*lo)[locker].n_comp_ocupados++;

    guardar_lockers(lo);
    guardar_comp_lockers(cl);
    return;
}


void listado_lockers(lockers **lo, char *ciudad)
{
    int op = 0;
    int i;
    printf("\n\n----------------------Lockers de %s----------------------\n\n", ciudad);
    for( i = 0; i < nlockers; i++)
    {
        if((strcmp ((*lo)[i].locali, ciudad) == 0) && ((*lo)[i].n_comp_total > (*lo)[i].n_comp_ocupados))
        {
            printf("%i/%s\n",(*lo)[i].id_locker, (*lo)[i].prov, (*lo)[i].n_comp_total, (*lo)[i].n_comp_ocupados);
            op = 1;
        }
    }
    if(op == 0)
    {
        printf("\n\nNO HAY LOCKERS EN ESTA CIUDAD\n");
    }
    return;
}

int val_codprom(descuentos **des)
{

    int aux = 0, aux2 = 0;
    int i;



    while (aux == 0)
    {
        if ((i = busqueda_des(des)) >= 0)
        {
            if (!(strcmp((*des)[i].estado,"Activo")))
                aux2 = 1;
            else if (!(strcmp((*des)[i].estado,"NoActivo")))
                aux2 = 0;
            else
            {
                printf("El campo 'Estado' contiene errores... No se puede saber la validez"
                       "del código de descuento introducido");
            }
            aux = 1;
        }
        else
            printf("Código de descuento no encontrado en la Base de Datos...\n");
    }
    return aux2;
}

int busqueda_des(descuentos **des)
{
    //Devuelve la pos del id. descuento si lo encuentra y -1 si no
    int aux = -1;
    int a,i;

    printf("Introduce el Id. Código Descuento: ");
    scanf("%i", &a);
    for (i = 0; i < ndescuentos; i++)
    {
        if (((*des)[i].id_promo) == a)
        {
            aux = i;
            i = ndescuentos+1;
        }
    }
    return aux;
}

int busqueda_cliente(descliente **desc,int cliente)
{
//Devuelve la pos del id. cliente si lo encuentra y -1 si no
    int aux = -1;
    int a,i;

    printf("Introduce el codigo: ");
    fflush(stdin);
    scanf("%i",&a);

    for (i = 0; i < ndescliente; i++)
    {
        if (((*desc)[i].id) == cliente && (*desc)[i].cod==a )
        {
            aux = i;
            i = ndescliente;
        }
    }
    return aux;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------

void cargar_pedidos(pedidos **pe)
{

    char linea[200];
    char *token;
    FILE *f;
    nt_pedidos=0;
    f=fopen("Pedidos.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *pe=malloc(1*sizeof(pedidos));

        while(fgets(linea,200,f)!=NULL)
        {
            *pe=(pedidos*)realloc((*pe),(nt_pedidos+1)*sizeof(pedidos));

            if((*pe)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*pe)[nt_pedidos].id_pedido=atoi(token);

                token=strtok(NULL,"/");//leer entre barras del fichero y lo guarda en la variable token.
                strcpy((*pe)[nt_pedidos].fch_ped,token);

                token=strtok(NULL,"/");
                (*pe)[nt_pedidos].id_cliente=atoi(token);

                token=strtok(NULL,"/");
                strcpy((*pe)[nt_pedidos].lugar_entrega,token);

                token=strtok(NULL,"/");
                (*pe)[nt_pedidos].id_locker=atoi(token);

                token=strtok(NULL,"/");
                (*pe)[nt_pedidos].cheque=atoi(token);

                token=strtok(NULL,"\n");
                (*pe)[nt_pedidos].promo=atoi(token);


                nt_pedidos++;
            }
        }
        fclose(f);
    }
}

void cargar_prod_pedidos(prod_pedidos **ppe)
{
    // doble asterisco= modificar
    char linea[200];
    char *token;
    FILE *f;
    nt_prodpedidos=0;


    f=fopen("ProductosPedidos.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *ppe=malloc(1*sizeof(prod_pedidos));

        while(fgets(linea,200,f)!=NULL)

        {

            *ppe=(prod_pedidos*)realloc((*ppe),(nt_prodpedidos+1)*sizeof(prod_pedidos));

            if((*ppe)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                //leer entre barras del fichero y lo guarda en la variable token.
                token=strtok(linea,"/");
                (*ppe)[nt_prodpedidos].id_pedido=atoi(token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                (*ppe)[nt_prodpedidos].id_prod=atoi(token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                (*ppe)[nt_prodpedidos].unidades=atoi(token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                strcpy((*ppe)[nt_prodpedidos].fech_entr,token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                (*ppe)[nt_prodpedidos].importe=atof(token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                strcpy((*ppe)[nt_prodpedidos].estado,token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");
                (*ppe)[nt_prodpedidos].id_trans=atoi(token);
                //printf("\ntoken: %s",token);

                token=strtok(NULL,"/");

                (*ppe)[nt_prodpedidos].cod_locker=atoi(token);
                //printf("\ntoken: %s",token);


                token=strtok(NULL,"\n");
                //printf("\ntoken: %s",token);
                strcpy((*ppe)[nt_prodpedidos].fech_entrdev,token);
                //printf("\nHOLA A TODOS");


                nt_prodpedidos++;
            }
        }
        fclose(f);
    }
}

void guardar_pedidos(pedidos **pe)
{
    FILE *f;
    int i;
    f=fopen("Pedidos.txt","w+");
    for(i=0; i<nt_pedidos; i++)
    {
        fprintf(f,"%i/%s/%i/%s/%i/%i/%i\n",(*pe)[i].id_pedido,(*pe)[i].fch_ped,(*pe)[i].id_cliente, (*pe)[i].lugar_entrega,(*pe)[i].id_locker,(*pe)[i].cheque, (*pe)[i].promo );
    }
    fclose(f);
}

void guardar_prod_pedidos(prod_pedidos **ppe)
{

    FILE *f;
    int i;
    f=fopen("ProductosPedidos.txt","w+");
    for(i=0; i<nt_prodpedidos; i++)
    {
        fprintf(f,"%i/%i/%i/%s/%f/%s/%i/%i/%s\n",(*ppe)[i].id_pedido,(*ppe)[i].id_prod,(*ppe)[i].unidades,(*ppe)[i].fech_entr,(*ppe)[i].importe,(*ppe)[i].estado,(*ppe)[i].id_trans,(*ppe)[i].cod_locker,(*ppe)[i].fech_entrdev );
    }
    fclose(f);
}

void prueba_impresion(pedidos **pe,prod_pedidos **ppe)
{
    int i;

    for ( i=0; i<nt_prodpedidos ; i++)
    {
        printf("PEDIDOS %i/%s/%i/%s/%i/%i/%i\n",(*pe)[i].id_pedido,(*pe)[i].fch_ped,(*pe)[i].id_cliente, (*pe)[i].lugar_entrega,(*pe)[i].id_pedido, (*pe)[i].id_locker,(*pe)[i].cheque, (*pe)[i].promo );
        puts("");
        printf("PROD_PEDIDOS %i/%i/%i/%i/%s/%f/%s/%i/%i\n",(*ppe)[i].id_pedido,(*ppe)[i].id_prod,(*ppe)[i].id_trans,(*ppe)[i].unidades,(*ppe)[i].fech_entr,(*ppe)[i].importe,(*ppe)[i].estado,(*ppe)[i].cod_locker,(*ppe)[i].fech_entrdev );

    }

}

void listar_pedidos_cliente(pedidos **pe,int cliente) //cliente
{
    int i,coincide=0;
    if (cliente<=0)
    {
        printf("\nEl ID del cliente no es valido.");
    }
    else
    {
        printf("\nPedidos del cliente: %i ",cliente);
        printf("\n--------------------------------------------");
        for(i=0; i<nt_pedidos; i++)
        {
            if(cliente==(*pe)[i].id_cliente) //comprobamos que el cliente este en pedidos
            {

                printf("\n ID Pedido: %i\n Fecha del pedido: %s\n Lugar de entrega: %s\n ID Locker: %i\n Cheque regalo: %i\n Codigo promocional: %i\n\n ", (*pe)[i].id_pedido, (*pe)[i].fch_ped, (*pe)[i].lugar_entrega,(*pe)[i].id_locker,(*pe)[i].cheque,(*pe)[i].promo);

                coincide=1;
            }

        }
        if(coincide==0)
        {
            printf("\nNo ha realizado ningun pedido en Esizon.");

        }
        printf("\n--------------------------------------------");
        system("Pause");
    }


}

void consultar_estado(pedidos **pe,prod_pedidos **ppe,int cliente)  //cliente
{
    int i,coincide=0,res=0;
    int *pos,*p1;
    if (cliente<=0)
    {
        printf("\nEl ID del cliente no es valido.");
    }
    else
    {
        printf("\nPedidos del cliente: %i ",cliente);
        printf("\n--------------------------------------------");

        for(i=0; i<nt_pedidos; i++)
        {
            if(cliente==(*pe)[i].id_cliente) //comprobamos que el cliente este en pedidos
            {

                printf("\n ID Pedido: %i\n Fecha del pedido: %s\n Lugar de entrega: %s\n ID Locker: %i\n Cheque regalo: %i\n Codigo promocional: %i\n\n ", (*pe)[i].id_pedido, (*pe)[i].fch_ped, (*pe)[i].lugar_entrega,(*pe)[i].id_locker,(*pe)[i].cheque,(*pe)[i].promo);
                coincide=1;
            }


        }
        if(coincide==0)
        {
            printf("\nNo ha realizado ningun pedido en Esizon.");

        }
        printf("\n--------------------------------------------");
        do
        {
            printf("\n1.- Consultar pedido\n2.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i",&res);
        }
        while(res<=0 || res>2);

        if(res==1)
        {
            printf("\nIntroduzca el ID_pedido que desea consultar: ");
            fflush(stdin);
            scanf("%i",&res);
            p1 = pe_existe_cliente(pe,cliente);
            printf("\n--------------------------------------------");
            if(p1[0]!=-1)
            {
                pos = pe_existe_producto(ppe, (*pe)[p1[1]].id_pedido);
                for(i=1; i<=pos[0] ; i++)
                {
                    printf("\n ID Pedido: %i\n ID Prod: %i\n Unidades: %i\n Fecha de entrega: %s\n Importe: %.2f\n Estado: %s\n ID Transportista: %i\n Codigo locker: %i\n Fecha de devolucion: %s\n\n", (*ppe)[pos[i]].id_pedido, (*ppe)[pos[i]].id_prod,(*ppe)[pos[i]].unidades,(*ppe)[pos[i]].fech_entr,(*ppe)[pos[i]].importe,(*ppe)[pos[i]].estado,(*ppe)[pos[i]].id_trans,(*ppe)[pos[i]].cod_locker,(*ppe)[pos[i]].fech_entrdev);

                }
                printf("\n--------------------------------------------");
            }
        }

    }
    printf("\n");
    system("Pause");
    return;
}
void pe_listar_admin(pedidos **pe,cliente **c) // admin
{
    int index=0;
    int i;
    for(i = 0; i < nt_pedidos; i++)
    {
        index++;
        printf("\n%i.- ID Pedido: %i	e-mail: %s",index,(*pe)[i].id_pedido,(*c)[(*pe)[i].id_cliente-1].mail);
    }

}

int listar_pedidos_proveedor(pedidos **pe, prod_pedidos **ppe, prod **pr, usuario **usu)
{
    int *v1;
    int c = 1,i,j,p2;
    int pos[1000];
    pos[0] = -1;
    int ultra[1000];
    ultra[0] = -1;

    v1 = producto_gestor((*usu)->id,pr); //typical vector

    for( i = 1; i <= v1[0]; i++)
    {
        for( j = 0; j < nt_prodpedidos; j++)
        {
            if( (*pr)[i].id_prod == (*ppe)[j].id_prod )
            {
                pos[c] = j;
                c++;
            }
        }

    }
    if(c != 1)
    {
        pos[0] = c - 1;
    }
    if(pos[0]!=-1)
    {
        printf("\n--------------------------------------------");
        for(i=1 ; i<=pos[0] ; i++)
        {
            p2 = pe_existe_pedido(pe,(*ppe)[pos[i]].id_pedido);
            ultra[i]= p2;
            printf("\n ID Pedido: %i\n Fecha del pedido: %s\n Lugar de entrega: %s\n ID Locker: %i\n Cheque regalo: %i\n Codigo promocional: %i\n\n ", (*pe)[p2].id_pedido, (*pe)[p2].fch_ped, (*pe)[p2].lugar_entrega,(*pe)[p2].id_locker,(*pe)[p2].cheque,(*pe)[p2].promo);

        }
        ultra[0]=pos[0];
        printf("\n--------------------------------------------\n");
        system("Pause");
    }
    else
    {
        printf("\n--------------------------------------------");
        printf("\nLos productos de este proveedor no se encuentran en ningun pedido.");
        printf("\n--------------------------------------------\n");
        system("Pause");
    }



    return ultra;
}

int pe_existe_pedido(pedidos **pe,int pedido)
{
    int i,pos=-1;
    //printf("DEVOL= %i",devol);
    //devol++;
    for(i=0; i<nt_pedidos ; i++)
    {
        if(pedido==(*pe)[i].id_pedido)
        {
            pos=i; // en esta pos guardamos la posicion en la estructura del id_pedido de devoluciones
        }
    }
    return pos;
    //si pos!=-1 esa devolucion existe
    //si pos==-1 esa devolucion no existe
}

int pe_existe_cliente(pedidos **pe,int aux_cliente)
{
    //meto en un vector las posiciones de la estructura en el cual se encuentra el cliente.
    int c = 1;
    int i;
    int pos[1000];
    pos[0] = -1;
    for( i= 0; i < nt_pedidos; i++)
    {
        if(aux_cliente==(*pe)[i].id_cliente)
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

int pe_existe_producto(prod_pedidos **ppe,int pedido)
{
    //meto en un vector las posiciones de la estructura prod_pedidos en la cual se encuentra el producto.
    int c = 1;
    int i;
    int pos[1000];
    pos[0] = -1;
    for( i= 0; i < nt_prodpedidos; i++)
    {
        if(pedido==(*ppe)[i].id_pedido)
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

void pe_modificar(pedidos **pe, cliente **c)// admin
{
    int pedido,cliente,op,seguir=0,salida=0;
    int pos1,pos2;
    int *vec;
    int puerta_cliente=0;

    listado_clientes(c);
    do
    {
        printf("\nDesea modificar el pedido de un cliente en concreto?\n1.-SI\n2.-NO\nElija una opcion: ");
        scanf("%i",&op);
    }
    while((0>op || op>2));

    if(op==1)
    {
        printf("\nIntroduzca el ID del cliente: ");
        scanf("%i",&cliente);

        pos1=pe_existe_cliente(pe,cliente);
        vec=pos1;
        //printf("vec[0]= %i",vec[0]);
        if(vec[0]==-1)
        {
            puerta_cliente=0;
        }
        else
        {
            puerta_cliente=1;
            system("cls");
            listar_pedidos_cliente(pe,cliente);
        }
    }
    else
    {
        puerta_cliente=1;
    }



    if(puerta_cliente==1)
    {
        printf("\nIntroduzca el ID del pedido que desea modificar: ");
        scanf("%i",&pedido);
        pos2=pe_existe_pedido(pe,pedido);
        printf("pos2= %i",pos2);
        if(pos2==-1)
        {
            do
            {
                printf("\nLa ID Pedido introducida no es valida.");
                printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                fflush(stdin);
                scanf("%i", &op);
                system("cls");
            }
            while(0>op|| op>2);

            if(op == 1)
            {
                pe_modificar(pe, c);
            }
        }
        else //MENU PRINCIPAL DONDE SE EJECUTARAN TODOS LOS CAMBIOS
        {
            // en pos2 tenemos la posicion del pedido que queremos modificar


            do
            {

                do
                {
                    printf("\nQue dato desea modificar del pedido: %i\n1.- ID Cliente\n2.- Lugar de entrega\n3.- ID Locker\n4.- Cheque\n5.- promo\nElija una opcion: ",(*pe)[pos2].id_pedido);
                    scanf("%i", &op);
                }
                while(0>op || op>5);
                switch(op)
                {
                case 1:
                {
                    printf("\nID Cliente actual: %i",(*pe)[pos2].id_cliente);
                    printf("\nIntroduzca la nueva ID Cliente para este pedido: ");
                    scanf("%i",&(*pe)[pos2].id_cliente);
                    break;
                }
                case 2:
                {
                    printf("\nID Lugar de entrega actual: %s",(*pe)[pos2].lugar_entrega);
                    printf("\nIntroduzca el nuevo lugar de entrega para este pedido (casa o locker): ");
                    gets((*pe)[pos2].lugar_entrega);
                    break;
                }
                case 3:
                {
                    printf("\nID ID locker actual: %i",(*pe)[pos2].id_locker);
                    printf("\nIntroduzca la nueva ID locker para este pedido: ");
                    scanf("%i",&(*pe)[pos2].id_locker);
                    break;
                }
                case 4:
                {
                    printf("\nID Cheque actual: %i",(*pe)[pos2].cheque);
                    printf("\nIntroduzca el cheque para este pedido: ");
                    scanf("%i",&(*pe)[pos2].cheque);
                    break;
                }
                case 5:
                {
                    printf("\nID Codigo promocional actual: %i",(*pe)[pos2].promo);
                    printf("\nIntroduzca el nuevo codigo promocional para este pedido: ");
                    scanf("%i",&(*pe)[pos2].promo);
                    break;
                }
                }
                guardar_pedidos(pe);
                printf("\n---");
                do
                {
                    printf("\n\nDesea modificar algun otro campo de este pedido:\n1.- SI\n2.- NO\nElija una opcion: ");
                    scanf("%i",&seguir);

                }
                while(0>seguir|| seguir>2);

                if(seguir==1)
                {
                    salida=1;
                }
                else
                {
                    salida=0;
                }


            }
            while(salida==1);

        }
    }
    else
    {
        do
        {
            printf("\nLa ID Cliente introducida no es valida.");
            printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);

        if(op == 1)
        {
            pe_modificar(pe, c);
        }
    }

    do
    {
        system("cls");
        printf("\n1.- Modificar otro pedido\n2.- Cerrar menu de modificaciones\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
    }
    while(0>op|| op>2);

    if(op == 1)
    {
        pe_modificar(pe, c);
    }


}

void pe_modificar_prod(prod_pedidos **ppe,pedidos **pe,cliente **c)// admin
{
    int op,sc,pedido,i,p1=0,pos,pos2,cont;
    int seguir,salida;
    int pos_prod[1000];
    int ff=1;
    //Introduce un pedido del sistema
    pe_listar_admin(pe,c);
    printf("\n\nIntroduzca el ID Pedido del producto que desea modificar: ");
    fflush(stdin);
    scanf("%i",&pedido);
    pos2=pe_existe_pedido(pe,pedido);
    if(pos2==-1)
    {
        do
        {
            printf("\nLa ID Pedido introducida no es valida.");
            printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>op|| op>2);

        if(op == 1)
        {
            pe_modificar_prod(ppe,pe,c);
        }
    }
    else //MENU PRINCIPAL DONDE SE EJECUTARAN TODOS LOS CAMBIOS
    {
        // en pos2 tenemos la posicion del pedido que queremos modificar

        do
        {



            system("cls");
            printf("\nProductos pertenecientes del pedido %i: ",pedido);
            printf("\n-------------------------------------------------");
            cont=1;
            for (i=0; i<nt_prodpedidos; i++)
            {
                if(pedido==(*ppe)[i].id_pedido)
                {
                    printf("\n%i.- Producto: %i     Unidades: %i     Importe: %f",cont,(*ppe)[i].id_prod,(*ppe)[i].unidades,(*ppe)[i].importe);
                    pos_prod[ff]=i;
                    ff++;

                    cont++;
                }
            }
            pos_prod[0]=ff-1; //cantidad de productos en ese pedido
            printf("\n-------------------------------------------------");


            printf("\nIndique el producto que desea modificar: ");
            fflush(stdin);
            scanf("%i",&sc);









            for(i=1; i<=pos_prod[0]; i++)
            {
                if(sc==(*ppe)[pos_prod[i]].id_prod)
                {
                    //si el producto introducido por teclado coincide con algun id_producto de los pedidos guardados en el vector
                    p1=1;
                    pos=pos_prod[i];
                    printf("\nsc %i",sc);
                }
            }

        }
        while(p1==0);

        do
        {
            do
            {
                //system("cls");
                printf("\nQue dato desea modificar del producto pedido: %i\n1.- Unidades\n2.- importe\n3.- estado\n4.- ID transportista\n5.- Codigo locker\nElija una opcion: ",sc);
                fflush(stdin);
                scanf("%i", &op);



            }
            while(0>op || op>5);

            switch(op)
            {
            case 1:
            {
                printf("\nUnidades actuales: %i",(*ppe)[pos].unidades);
                printf("\nIntroduzca una nueva cantidad para este producto: ");
                fflush(stdin);
                scanf("%i",&(*ppe)[pos].unidades);
                break;
            }
            case 2:
            {
                printf("\nImporte actual: %f",(*ppe)[pos].importe);
                printf("\nIntroduzca el nuevo importe: ");
                fflush(stdin);
                scanf("%f",&(*ppe)[pos].importe);
                break;
            }
            case 3:
            {
                printf("\nEstado actual: %s",(*ppe)[pos].estado);
                printf("\nIntroduzca el nuevo estado para este producto: ");
                fflush(stdin);
                gets((*ppe)[pos].estado);
                break;
            }
            case 4:
            {
                printf("\nID Transportista actual: %i",(*ppe)[pos].id_trans);
                printf("\nIntroduzca el ID del nuevo transportista: ");
                fflush(stdin);
                scanf("%i",&(*ppe)[pos].id_trans);
                break;
            }
            case 5:
            {
                printf("\nCodigo locker actual: %i",(*ppe)[pos].cod_locker);
                printf("\nIntroduzca el nuevo codigo locker: ");
                fflush(stdin);
                scanf("%i",&(*ppe)[pos].cod_locker);
                break;
            }

            }
            guardar_prod_pedidos(ppe);

            do
            {
                printf("\n\nDesea modificar algun otro campo de este producto-pedido:\n1.- SI\n2.- NO\nElija una opcion: ");
                scanf("%i",&seguir);

            }
            while(0>seguir|| seguir>2);

            if(seguir==1)
            {
                salida=1;
            }
            else
            {
                salida=0;
            }
        }
        while(salida==1);

    }


    do
    {
        guardar_prod_pedidos(ppe);
        system("cls");

        printf("\n1.- Modificar otro producto-pedido\n2.- Cerrar menu de modificaciones\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
    }
    while(0>op|| op>2);

    if(op == 1)
    {
        pe_modificar_prod(ppe,pe,c);
    }
    return;
}

void dar_baja_pedidos(pedidos **pe,prod_pedidos **ppe,cliente **c) //admin
{


    int aux_pedido,pos,op;
    int i=0,j=0;
    int *vec;

    printf("\n|DAR BAJA PEDIDOS|\n");
    pe_listar_admin(pe,c);
    printf("\n---------------------------------------------------------------------------------------------------");

    printf("\nIntroduce el ID Pedido: ");
    scanf("%i", &aux_pedido);

    pos=pe_existe_pedido(pe,aux_pedido);
    vec=pe_existe_producto(ppe,aux_pedido);

    if(pos==-1)
    {
        system("cls");
        printf("Este ID no esta registrado como pedido\n");
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
            system("cls");
            dar_baja_pedidos(pe,ppe,c);
        }
    }
    else// A PARTIR DE AQUI ES EL MENU PARA BORRAR.
    {

        nt_pedidos--; //borramos el ultimo objeto guardado mochila tras el intercambio.
        (*pe)[pos] = (*pe)[nt_pedidos];
        *pe=(pedidos*)realloc((*pe),(nt_pedidos+1)*sizeof(pedidos));


        while(j<=vec[0])
        {

            j++;
            nt_prodpedidos--;
            (*ppe)[vec[j]]=(*ppe)[nt_prodpedidos];  //intercambio con la posicion que vamos a eliminar y la ult.
            *ppe=(prod_pedidos*)realloc((*ppe),(nt_prodpedidos+1)*sizeof(prod_pedidos));

        }

        guardar_pedidos(pe);
        guardar_prod_pedidos(ppe);
        printf("\nPedido borrado con exito.");
    }
}

void dar_alta_pedidos(pedidos **pe,prod_pedidos **ppe, cliente **c,descuentos **des, usuario **usu,  prod **pr, descliente **desc, lockers **lo,comp_lockers **cl, transportistas **tr) //admin
{



    int op, tempi, tempp,salir=0,res;
    int pos_desc;
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    char auxm[2],auxyear[4],fechayhora[9];
    int nomore=0;
    int pos,i=1,j,sum=1;
    int vec[ncesta];
    int vec_cant[ncesta];
    int p1,asignar=0;

    vec[0]=0;
    strftime(fechayhora, 100, "%d%m%Y", tm);

    nt_pedidos++;
    *pe=(pedidos*)realloc((*pe),(nt_pedidos+1)*sizeof(pedidos));




//-----------------------PEDIDO--------------
    tempi = (*usu)->id;
    tempp = (*usu)->pos;

    do
    {
        if((*usu)->tipo==2) //si es admin
        {
            printf("\nBienvenido al menu de dar de alta pedidos para Administradores Esizon.\n");
            listado_clientes(c);

            printf("\nIntroduce el ID cliente(0 para salir): ");
            fflush(stdin);
            scanf("%i",&res);

            buscar_cliente((*c)[res-1].mail, c, usu);
            if(res==0)
            {
                salir=1;
            }
        }
        else //si es cliente
        {
            res = (*usu)->id;
        }
    }
    while((*usu)->pos==-1 && salir==0);


    (*pe)[nt_pedidos-1].id_cliente = res ;
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    tempi = res;
    if(res!=0)
    {


// --------------------------
        (*pe)[nt_pedidos-1].id_pedido = nt_pedidos;
// --------------------------

        strcpy((*pe)[nt_pedidos-1].fch_ped,fechayhora);

// --------------------------

        do
        {
            printf("\nIndique el lugar de entrega\n1.- Casa\n2.- Locker\n3.- Cancelar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i",&res);
            if(res==3)
            {
                salir=1;
            }
        }
        while(res<=0 || res>3);
        if(salir!=1)
        {
            switch(res)
            {
            case 1:
                strcpy((*pe)[nt_pedidos-1].lugar_entrega,"casa");
                break;
            case 2:
                strcpy((*pe)[nt_pedidos-1].lugar_entrega,"locker");
                asignar=1;
                break;
            }

// --------------------------
            system("cls");
            printf("Indique si tiene algun cheque\n1.- Si\n2.- No\nElija una opcion: ");
            fflush(stdin);
            scanf("%i",&res);
            if(res==1)
            {
                pos_desc = busqueda_cliente(desc,tempi);
                if(pos_desc!=-1)
                {
                    printf("\nCheque aplicado correctamente.");
                    (*pe)[nt_pedidos-1].cheque = (*desc)[pos_desc].cod;
                }
                else
                {
                    printf("\nCheque no valido.\n");
                    (*pe)[nt_pedidos-1].cheque = 0;
                }
            }
            else
            {
                (*pe)[nt_pedidos-1].cheque = 0;
            }
// --------------------------
            system("cls");
            printf("Indique si tiene algun codigo promocional\n1.- Si\n2.- No\nElija una opcion:");
            fflush(stdin);
            scanf("%i",&res);
            if(res==1)
            {
                pos_desc = busqueda_cliente(desc,tempi);
                if(pos_desc!=-1)
                {
                    printf("\codigo promocional aplicado correctamente.");
                    (*pe)[nt_pedidos-1].promo = (*desc)[pos_desc].cod;
                }
                else
                {
                    printf("\ncodigo promocional no valido.\n");
                    (*pe)[nt_pedidos-1].promo = 0;
                }
            }
            else
            {
                (*pe)[nt_pedidos-1].promo = 0;
            }

//--------------------------



//-----------------------PRODUCTOS DEL PEDIDO--------------

//Crear tantos nt_prodpedidos como cesta[0] existan.( excepcion )
//A cada uno de estos nt_prodpedidos le asigno el ID_pedido de (*pe)[nt_pedidos-1].id_pedido

            //compruebo cuantos id productos disntos existen
            //voy metiendo uno a uno en vec
            //cada vez que coincida el (id de la cesta) == (el id de vec[i]) --> vec_cant[i]++



            for(i=1; i<=cesta[0]; i++)
            {

                p1 = 0;
                for(j = 0; j <= vec[0]; j++)
                {

                    if(vec[j+1] == (*pr)[cesta[i]].id_prod)
                    {
                        vec_cant[j+1] = vec_cant[j+1] + 1;
                        p1 = 1;
                    }
                }
                if(p1 == 0)
                {
                    vec[j] = (*pr)[cesta[i]].id_prod;
                    vec[0] = vec[0] + 1;
                    vec_cant[j] = 1;
                }

            }

            for(i=1; i<=vec[0]; i++)
            {
                if( ((*pr)[vec[i]-1].stock - vec_cant[i] ) < 0)
                {
                    vec_cant[i] = 0;
                }
            }

            for(i=1; i<=vec[0]; i++)
            {
                if(vec_cant[i] !=0)
                {
                    nt_prodpedidos++;
                    *ppe=(prod_pedidos*)realloc((*ppe),(nt_prodpedidos+1)*sizeof(prod_pedidos));
                    (*ppe)[nt_prodpedidos-1].id_pedido = (*pe)[nt_pedidos-1].id_pedido;

                    (*ppe)[nt_prodpedidos-1].id_prod = vec[i];
                    pos = buscar_producto((*pr)[vec[i]-1].descrp,pr);
                    //pos es la posicion de memoria dentro de la estructura productos de este producto sacado de la cesta.
                    incrementar_fecha(ppe,(*pr)[pos].compromiso,fechayhora);//modificara el campo (*ppe)[nt_prodpedidos-1].fech_ent
                    strcpy((*ppe)[nt_prodpedidos-1].estado,"enPreparacion");
                    (*ppe)[nt_prodpedidos-1].id_trans = 0;
                    (*ppe)[nt_prodpedidos-1].cod_locker = 0;
                    strcpy((*ppe)[nt_prodpedidos-1].fech_entrdev,"00000000");
                    (*ppe)[nt_prodpedidos-1].unidades = vec_cant[i];
                    (*pr)[vec[i]-1].stock = (*pr)[vec[i]-1].stock - vec_cant[i]; //Actualiza el stock de dicho producto.
                    (*ppe)[nt_prodpedidos-1].importe = ((*pr)[pos].importe) * ((*ppe)[nt_prodpedidos-1].unidades);

                }
            }
            if(asignar==1)
            {
                pe_asignar_locker(pe,ppe,c,lo,cl,(*pe)[nt_pedidos-1].id_pedido);
            }

            pe_asignar_trans(pe,ppe,c,tr,(*pe)[nt_pedidos-1].id_pedido);
            guardar_pedidos(pe);
            guardar_prod_pedidos(ppe);
        }
    }
    cargar_pedidos(pe);
    cargar_prod_pedidos(ppe);
    return;
}

void recogida_pedido(pedidos **pe,prod_pedidos **ppe,lockers **lo,comp_lockers **cl,int cliente)
{
    int i,res,salida=0,pos;
    do
    {
        system("cls");
        printf("\nIntroduzca el codigo de su Locker(0 para salir): ");
        fflush(stdin);
        scanf("%i",&res);

        for (i=0; i<ncomp_lockers ; i++)
        {
            if(res==(*cl)[i].codigo)
            {
                salida = 1;
                pos=i;
            }
        }

    }
    while(salida==0 && res!=0);

    printf("\nEl compartimento(%i) se ha abierto.",(*cl)[i].n_compartimento);

    for(i=0; i<nt_prodpedidos ; i++)
    {
        if( (*ppe)[i].cod_locker == (*cl)[pos].codigo )
        {
            strcpy((*ppe)[i].estado,"entregado");
        }

    }
    printf("\nGracias por utilizar nuestros servicios.");
    return;
}

void incrementar_fecha(prod_pedidos **ppe, int incremento, char fechayhora[9])
{
    char auxd[2],auxm[2],auxyear[4];
    int dia,mes,year, suma, max;
    int div[2];

    auxd[0]=fechayhora[0];
    auxd[1]=fechayhora[1];

    auxm[0]=fechayhora[2];
    auxm[1]=fechayhora[3];

    auxyear[0]=fechayhora[4];
    auxyear[1]=fechayhora[5];
    auxyear[2]=fechayhora[6];
    auxyear[3]=fechayhora[7];

    dia = atoi(auxd);
    mes = atoi(auxm);
    year = atoi(auxyear);
    suma = dia + incremento;

    div[0] = suma / 10;
    div[1] = suma % 10;

    switch(( mes % 2) + 2)
    {
    case 2:
        if(mes == 2)
        {
            max = 28;
        }
        else
        {
            max = 30;
        }
        break;
    case 3:
        max = 31;
        break;
    }

    if(suma <= max)
    {
        fechayhora[0] = div[0] + '0';
        fechayhora[1] = div[1] + '0';
        fechayhora[2] = auxm[0];
        fechayhora[3] = auxm[1];
        fechayhora[4] = auxyear[0];
        fechayhora[5] = auxyear[1];
        fechayhora[6] = auxyear[2];
        fechayhora[7] = auxyear[3];
    }
    else
    {

        div[0] = (suma - max)/10;
        div[1] = (suma - max)%10;
        fechayhora[0] = div[0] + '0';
        fechayhora[1] = div[1] + '0';
        switch(mes)
        {
        case 9:
            fechayhora[2] = '1';
            fechayhora[3] = '0';
            break;
        case 12:
            fechayhora[2] = '0';
            fechayhora[3] = '1';
            fechayhora[4] = auxyear[0];
            fechayhora[5] = auxyear[1];
            if(auxyear[3] == 9)
            {
                fechayhora[6] = auxyear[2] + 1;
                fechayhora[7] = '0';
            }
            else
            {
                fechayhora[6] = auxyear[2];
                fechayhora[7] = auxyear[3] + 1;
            }
            break;
        default:
            fechayhora[2] = auxm[0];
            fechayhora[3] = auxm[1] + 1;
            fechayhora[4] = auxyear[0];
            fechayhora[5] = auxyear[1];
            fechayhora[6] = auxyear[2];
            fechayhora[7] = auxyear[3];
            break;
        }
    }

    strcpy((*ppe)[nt_prodpedidos-1].fech_entr,fechayhora);
    return;
}


void estado_pedido(pedidos **pe,prod_pedidos **ppe,transportistas **tr, int aux_trans) //transportista // pasar por parametro el id de ese transportista
{
    //mostrar lista de pedidos asignados a ese transportista, seleccione un pedido
    //Preguntarle en que estdo se encuentra: enPreparaci�n/enviado/enReparto/enLocker/entregado/devuelto
    //volver a preguntar si quiere hacer algo mas
    //guardar prod_pedidos

    int c = 1,op,op2,res,i,j,aux_pedido;
    int p1=0,p2=0,nop=0;

    int p[1000];
    int pos[1000];
    pos[0] = -1;
    p[0] = -1;

    for( i=0; i<nt_prodpedidos; i++)
    {

        if(aux_trans==(*ppe)[i].id_trans && p[c-1]!=(*ppe)[i].id_pedido) //si coincide el id_trans
        {
            p[c] = (*ppe)[i].id_pedido;
            pos[c]= i;
            c++;
            nop=1;
        }


    }
    if(c != 1)
    {
        p[0] = c - 1; //id pedido del grupo
        pos[0]= c - 1; //posiciones de los pedidos

    }

    //una vez tengo el vector con los pedidos correspondientes al transportista
    //se los muestro en una lista

    //CONTEMPLAR OPCION DE TRANSPORTISTA SIN PEDIDOS ASIGNADOS if()
    if(nop==1)
    {


        do
        {

            system("cls");
            printf("Bienvenido al menu de seguimiento para Transportistas Esizon.");
            printf("\nPedidos asignados:\n ");
            printf("\n-------------------------------------------------");
            for (i=0; i<pos[0] ; i++)
            {
                printf("\n%i.- ID Pedido: %i     	Estado: %s",i+1,(*ppe)[pos[i+1]].id_pedido,(*ppe)[pos[i+1]].estado);
            }
            printf("\n-------------------------------------------------\n\n");
            printf("\n1.- Actualizar \n2.- Cerrar menu de seguimiento\nElija una opcion: ");
            fflush(stdin);
            scanf("%i",&op);

        }
        while(0>op|| op>2);

        if(op==1) //MENU ACTUALIZAR
        {
            printf("\nQue pedido desea actualizar: ");
            fflush(stdin);
            scanf("%i",&res);
            for(i=0; i<pos[0]; i++)
            {
                if(res==p[i])
                {
                    p2=1;
                }
            }

            if(p2==0)
            {
                do
                {
                    system("cls");
                    printf("\nEl ID pedido introducido no es valido.");
                    printf("\n1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                    fflush(stdin);
                    scanf("%i", &op);
                    system("cls");
                }
                while(0>op|| op>2);

                if(op == 1)
                {
                    system("cls");
                    estado_pedido(pe,ppe,tr,aux_trans);
                }
                return;
            }
            else
            {
                do
                {
                    printf("\n1.- Enviado\n2.- En reparto\n3.- En locker\n4.- Entregado\n5.- Devuelto\nSeleccione el estado en el que se encuentra el pedido actualmente: ");
                    fflush(stdin);
                    scanf("%i",&op2);
                }
                while(0>op2 || op>5);

                switch(op2)
                {
                case 1:
                {

                    for	(i=0; i<nt_prodpedidos; i++)
                    {
                        if(res==(*ppe)[i].id_pedido)
                        {
                            //cambiamos el estado al de la opcion 1.
                            strcpy((*ppe)[i].estado,"enviado");
                        }
                    }
                    break;
                }
                case 2:
                {
                    for	(i=0; i<nt_prodpedidos; i++)
                    {
                        if(res==(*ppe)[i].id_pedido)
                        {
                            //cambiamos el estado al de la opcion 2.
                            strcpy((*ppe)[i].estado,"EnReparto");
                        }
                    }
                    break;
                }
                case 3:
                {
                    for	(i=0; i<nt_prodpedidos; i++)
                    {
                        if(res==(*ppe)[i].id_pedido)
                        {
                            //cambiamos el estado al de la opcion 3.
                            strcpy((*ppe)[i].estado,"enLocker");
                        }
                    }
                    break;
                }
                case 4:
                {
                    for	(i=0; i<nt_prodpedidos; i++)
                    {
                        if(res==(*ppe)[i].id_pedido)
                        {
                            //cambiamos el estado al de la opcion 4.
                            strcpy((*ppe)[i].estado,"entregado");
                        }
                    }
                    break;
                }
                case 5:
                {
                    for	(i=0; i<nt_prodpedidos; i++)
                    {
                        if(res==(*ppe)[i].id_pedido)
                        {
                            //cambiamos el estado al de la opcion 5.
                            strcpy((*ppe)[i].estado,"devuelto");
                        }
                    }
                    break;
                }


                }
                guardar_prod_pedidos(ppe);
                printf("\nHemos guardado con exito su modificacion.\nEsizon le desea un buen dia :)");
            }
        }
        else
        {
            system("cls");
            printf("\nEsizon le desea un buen dia :)");
            return;
        }

    }
    else
    {
        system("cls");
        printf("Bienvenido al menu de seguimiento para Transportistas Esizon.");
        printf("\n\nUsted no tiene ningun pedido asignado.");
        printf("\nEsizon le desea un buen dia :)");
    }
}



