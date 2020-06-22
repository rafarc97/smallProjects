#include "Logistica.h"



void cargar_lockers(lockers **lo)
{
    char linea[300];
    char *token;
    FILE *f;

    nlockers=0;

    f=fopen("Lockers.txt","a+");

    if(f==NULL)
        puts("Error de apertura");
    else
    {
        rewind(f);
        *lo=malloc(1*sizeof(lockers));

        while(fgets(linea,300,f)!=NULL)
        {
            *lo=(lockers*)realloc((*lo),(nlockers+1)*sizeof(lockers));
            if((*lo)==NULL)
                puts("No hay memoria suficiente");
            else
            {
                token=strtok(linea,"/");
                (*lo)[nlockers].id_locker=atoi(token);
                token=strtok(NULL,"/");
                strcpy((*lo)[nlockers].locali,token);
                token=strtok(NULL,"/");
                strcpy((*lo)[nlockers].prov,token);
                token=strtok(NULL,"/");
                strcpy((*lo)[nlockers].ubicacion,token);
                token=strtok(NULL,"/");
                (*lo)[nlockers].n_comp_total=atoi(token);
                token=strtok(NULL,"\n");
                (*lo)[nlockers].n_comp_ocupados=atoi(token);
                nlockers++;
            }
        }
        fclose(f);
    }
}

void guardar_lockers(lockers **lo)
{
    FILE *f;
    int i;
    f=fopen("Lockers.txt","w+");
    for(i=0; i<nlockers; i++)
        fprintf(f,"%i/%s/%s/%s/%i/%i\n",(*lo)[i].id_locker,(*lo)[i].locali,(*lo)[i].prov,(*lo)[i].ubicacion,(*lo)[i].n_comp_total, (*lo)[i].n_comp_ocupados);
    fclose(f);
}

void cargar_compartimentolockers(comp_lockers **cl)
{


    char linea[500];
    char *token;
    FILE *f;

    f=fopen("CompartimentosLockers.txt","a+");

    if(f==NULL)
        puts("Error de apertura");
    else
    {
        rewind(f);
        *cl=(comp_lockers*)malloc(1*sizeof(comp_lockers));

        while(fgets(linea,500,f)!=NULL)
        {
            *cl=(comp_lockers*)realloc((*cl),(ncomp_lockers+1)*sizeof(comp_lockers));
            if(*cl==NULL)
                puts("No hay memoria suficiente");
            else
            {
                token=strtok(linea,"/");
                //printf("\nToken= %s",token);
                (*cl)[ncomp_lockers].id_locker=atoi(token);

                token=strtok(NULL,"/");
                //printf("\nToken= %s",token);
                (*cl)[ncomp_lockers].n_compartimento=atoi(token);

                token=strtok(NULL,"/");
                //printf("\nToken= %s",token);
                (*cl)[ncomp_lockers].codigo=atoi(token);

                token=strtok(NULL,"/");
                //printf("\nToken= %s",token);
                strcpy((*cl)[ncomp_lockers].estado,token);

                token=strtok(NULL,"/");
                //printf("\nToken= %s",token);
                strcpy((*cl)[ncomp_lockers].fch_ocup,token);

                token=strtok(NULL,"\n");
                //printf("\nToken= %s",token);
                strcpy((*cl)[ncomp_lockers].fch_ca,token);

                ncomp_lockers++;
            }
        }
        fclose(f);
    }

}

void guardar_comp_lockers(comp_lockers **cl)
{
    FILE *f;
    int i;
    f=fopen("CompartimentosLockers.txt","w+");
    for(i=0; i<ncomp_lockers; i++)
        fprintf(f,"%i/%i/%i/%s/%s/%s\n",(*cl)[i].id_locker,(*cl)[i].n_compartimento,(*cl)[i].codigo,(*cl)[i].estado, (*cl)[i].fch_ocup, (*cl)[i].fch_ca);
    fclose(f);
}

void incrementar_fecha_locker(comp_lockers **cl, int incremento, char fechayhora[9],int i)
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

    strcpy((*cl)[i].fch_ca,fechayhora);
    return;
}

void pe_asignar_locker(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl, int aux_pedido)
{

    //pido un pedido -
    //compruebo si ese pedido existe -
    //compruebo si el pedido es tipo locker (existe tipo: casa o locker) -
    //con el id_cliente de ese pedido, recorro la estructura cliente hasta dar con el, guardamos la posicion. -
    //recorremos locker en busca de uno que tenga la misma localidad que la del cliente -
    //ese locker tiene que tener compartimentos libres. guardamos la posiciones en un vector. -

    //Asignar compartimentos a cada producto del pedido: (por pedido, un compartimento)
    //Cojo el id_locker, lo busco ese ID en comp-lockers, miro si tiene algun compartimento con un bucle en comp_lockers,
    //En los productos del pedido, les asigno ese cod_locker a cada producto, y el estado de ese producto pasa a ser enPreparacion
    //y ese compartimento pasa a estar ocupado
    //
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    char fechayhora[9];
    strftime(fechayhora, 100, "%d%m%Y", tm);


    int op,i,aux_locker,aux_codigo=0;
    int p1=-1,p2=-1,p3=-1,p4=-1,p5=0; // puertas logicas
    char aux_localidad[20];

    //meto en poslockerDisp los lockers disponibles
    int posLockerDisp[nlockers+1];
    int j = 0;



    p1 = pe_existe_pedido(pe,aux_pedido); // p1 tiene la posicion de ese pedido
    if ( strcmp( (*pe)[p1].lugar_entrega,"locker" ) == 0 )
    {
        p2=1;
    }

    if(p2==-1)
    {
        system("cls");
        printf("Este ID Pedido no es valido para asignarle un locker.\n");
        return;
    }
    else// A PARTIR DE AQUI ES EL MENU ASGINAR
    {



        for (i=0; i<ncliente; i++)
        {
            if( (*pe)[p1].id_cliente == (*c)[i].id )
            {
                strcpy(aux_localidad,(*c)[i].loc); //tenemos la localidad del cliente del pedido introducido
            }
        }

        //Lista lockers disponibles
        for(i = 0; i < nlockers; i++)
        {
            if( (( (*lo)[i].n_comp_ocupados) < ((*lo)[i].n_comp_total)) &&(  (strcmp( aux_localidad, (*lo)[i].locali ))==0   )     )
            {
                printf("ID LOCKER= %i    LOCALIDAD= %s",(*lo)[i].id_locker,(*lo)[i].locali);
                posLockerDisp[j] = i; //guardo la pos. de los lockers disponibles y que coincidan con la localidad
                j++;
                p3=0;
            }

        }


    }

    if(	p3==0)
    {
        do
        {

            do
            {
                system("cls");
                printf("\nMenu de Asignaciones-Locker para los pedidos de ESIZON");
                printf("\nLocker disponibles para asignar en este pedido: ");
                printf("\n---------------------------------------------");
                for(i=0; i<j; i++)
                {
                    printf("\n%i.- ID Locker: %i",i+1,(*lo)[posLockerDisp[i]].id_locker);
                }

                printf("\n---------------------------------------------\n");

                printf("\nIntroduce un ID Locker: ");
                fflush(stdin);
                scanf("%i",&aux_locker);




//Miro si el locker introducido por teclado se encuentra en lockers disponibles
                for(i=0; i<j; i++)
                {
                    if ( aux_locker == (*lo)[posLockerDisp[i]].id_locker )
                    {
                        p4=1; //ya tenemos el id_locker
                    }
                }
                if(p4==-1)
                {
                    system("cls");
                }




            }
            while(p4==-1 );

            //
            //buscamos un comp. vacio con el id_locker: (aux_locker)
            for(i=0; i<ncomp_lockers && p5==0; i++)
            {

                if( (*cl)[i].id_locker==aux_locker)
                {
                    if( (strcmp((*cl)[i].estado,"vacio")==0) )
                    {
                        strcpy((*cl)[i].estado,"ocupado"); // solo para un compartimento

                        incrementar_fecha_locker(cl,15,(*cl)[i].fch_ocup,i);
                        strcpy((*cl)[i].fch_ocup,fechayhora);
                        aux_codigo = (*cl)[i].codigo;
                        p5=1;
                    }

                }

            }
//
        }
        while(p5==0);
        locker_compartimentos_act(cl,lo,aux_locker);
//Para cada producto del pedido, le insertamos el codigo del comportimento.
        for(i=0; i<nt_prodpedidos; i++)
        {
            if(aux_pedido==(*ppe)[i].id_pedido)
            {
                (*ppe)[i].cod_locker=aux_codigo;
            }
        }

        //asigno ese id locker al pedido (p1).
        (*pe)[p1].id_locker = aux_locker;
        guardar_prod_pedidos(ppe);
        guardar_pedidos(pe);
        guardar_comp_lockers(cl);
        guardar_lockers(lo);

        //system("cls");
        printf("\n\nLocker asignado correctamente.");


    }
    else
    {
        system("cls");
        printf("No hay lockers disponibles en su localidad.\n");

    }
    return;
}

void pe_asignar_locker_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl)
{
    //pido un pedido -
    //compruebo si ese pedido existe -
    //compruebo si el pedido es tipo locker (existe tipo: casa o locker) -
    //con el id_cliente de ese pedido, recorro la estructura cliente hasta dar con el, guardamos la posicion. -
    //recorremos locker en busca de uno que tenga la misma localidad que la del cliente -
    //ese locker tiene que tener compartimentos libres. guardamos la posiciones en un vector. -

    //Asignar compartimentos a cada producto del pedido: (por pedido, un compartimento)
    //Cojo el id_locker, lo busco ese ID en comp-lockers, miro si tiene algun compartimento con un bucle en comp_lockers,
    //En los productos del pedido, les asigno ese cod_locker a cada producto, y el estado de ese producto pasa a ser enPreparacion
    //y ese compartimento pasa a estar ocupado
    //

    int op,i,aux_locker,aux_pedido,aux_codigo=0;
    int p1=-1,p2=-1,p3=-1,p4=-1,p5=0; // puertas logicas
    char aux_localidad[20];

    //meto en poslockerDisp los lockers disponibles
    int posLockerDisp[nlockers+1];
    int j = 0;


    printf("\nMenu de Asignaciones-Locker para los pedidos de ESIZON");
    pe_listar_admin(pe, c);
    printf("\nIntroduce un ID Pedido tipo locker: ");
    scanf("%i",&aux_pedido);

    p1 = pe_existe_pedido(pe,aux_pedido); // p1 tiene la posicion de ese pedido
    if ( strcmp( (*pe)[p1].lugar_entrega,"locker" ) == 0 )
    {
        p2=1;
    }

    if(p2==-1)
    {
        system("cls");
        printf("Este ID Pedido no es valido para asignarle un locker.\n");
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
            pe_asignar_locker_admin(pe,ppe,c,lo,cl);
        }
    }
    else// A PARTIR DE AQUI ES EL MENU ASGINAR
    {



        for (i=0; i<ncliente; i++)
        {
            if( (*pe)[p1].id_cliente == (*c)[i].id )
            {
                strcpy(aux_localidad,(*c)[i].loc); //tenemos la localidad del cliente del pedido introducido
            }
        }

        //Lista lockers disponibles
        for(i = 0; i < nlockers; i++)
        {
            if( (( (*lo)[i].n_comp_ocupados) < ((*lo)[i].n_comp_total)) &&(  (strcmp( aux_localidad, (*lo)[i].locali ))==0   )     )
            {
                printf("ID LOCKER= %i    LOCALIDAD= %s",(*lo)[i].id_locker,(*lo)[i].locali);
                posLockerDisp[j] = i; //guardo la pos. de los lockers disponibles y que coincidan con la localidad
                j++;
                p3=0;
            }

        }


    }

    if(	p3==0)
    {
        do
        {

            do
            {
                system("cls");
                printf("\nMenu de Asignaciones-Locker para los pedidos de ESIZON");
                printf("\nLocker disponibles para asignar en este pedido: ");
                printf("\n---------------------------------------------");
                for(i=0; i<j; i++)
                {
                    printf("\n%i.- ID Locker: %i",i+1,(*lo)[posLockerDisp[i]].id_locker);
                }

                printf("\n---------------------------------------------\n");

                printf("\nIntroduce un ID Locker: ");
                fflush(stdin);
                scanf("%i",&aux_locker);




//Miro si el locker introducido por teclado se encuentra en lockers disponibles
                for(i=0; i<j; i++)
                {
                    if ( aux_locker == (*lo)[posLockerDisp[i]].id_locker )
                    {
                        p4=1; //ya tenemos el id_locker
                    }
                }
                if(p4==-1)
                {
                    system("cls");
                }
            }
            while(p4==-1 );

            //
            //buscamos un comp. vacio con el id_locker: (aux_locker)
            for(i=0; i<ncomp_lockers && p5==0; i++)
            {

                if( (*cl)[i].id_locker==aux_locker)
                {
                    if( (strcmp((*cl)[i].estado,"vacio")==0) )
                    {
                        strcpy((*cl)[i].estado,"ocupado"); // solo para un compartimento
                        aux_codigo = (*cl)[i].codigo;
                        p5=1;
                    }
                }
            }
//
        }
        while(p5==0);
        locker_compartimentos_act(cl,lo,aux_locker);
//Para cada producto del pedido, le insertamos el codigo del comportimento.
        for(i=0; i<nt_prodpedidos; i++)
        {
            if(aux_pedido==(*ppe)[i].id_pedido)
            {
                (*ppe)[i].cod_locker=aux_codigo;
            }
        }

        //asigno ese id locker al pedido (p1).
        (*pe)[p1].id_locker = aux_locker;
        guardar_prod_pedidos(ppe);
        guardar_pedidos(pe);
        guardar_comp_lockers(cl);
        guardar_lockers(lo);

        system("cls");
        printf("\n\nLocker asignado correctamente.");
        return;

    }
    else
    {
        system("cls");
        printf("No hay lockers disponibles en su localidad.\n");
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
            pe_asignar_locker_admin(pe,ppe,c,lo,cl);
        }
        return;
    }
}

void pe_asignar_locker_proveedor(pedidos **pe, prod_pedidos **ppe, cliente **c, lockers **lo, comp_lockers **cl,usuario **usu,prod **pr)
{
    //pido un pedido -
    //compruebo si ese pedido existe -
    //compruebo si el pedido es tipo locker (existe tipo: casa o locker) -
    //con el id_cliente de ese pedido, recorro la estructura cliente hasta dar con el, guardamos la posicion. -
    //recorremos locker en busca de uno que tenga la misma localidad que la del cliente -
    //ese locker tiene que tener compartimentos libres. guardamos la posiciones en un vector. -

    //Asignar compartimentos a cada producto del pedido: (por pedido, un compartimento)
    //Cojo el id_locker, lo busco ese ID en comp-lockers, miro si tiene algun compartimento con un bucle en comp_lockers,
    //En los productos del pedido, les asigno ese cod_locker a cada producto, y el estado de ese producto pasa a ser enPreparacion
    //y ese compartimento pasa a estar ocupado
    //

    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    char fechayhora[9];
    strftime(fechayhora, 100, "%d%m%Y", tm);

    int op,i,aux_locker,aux_pedido,aux_codigo=0;
    int p1=-1,p2=-1,p3=-1,p4=-1,p5=0; // puertas logicas
    int *ultra;
    char aux_localidad[20];

    //meto en poslockerDisp los lockers disponibles
    int posLockerDisp[nlockers+1];
    int j = 0;

    //PRUEBAS
    (*usu)->id = 1;
    (*usu)->pos = 0;
    (*usu)->tipo = 3;

    do
    {
        system("cls");
        printf("\nMenu de Asignaciones-Locker para los pedidos de ESIZON");
        ultra =  listar_pedidos_proveedor(pe, ppe, pr, usu);

        printf("\nIntroduce un ID Pedido tipo locker(0 para salir): ");
        scanf("%i",&aux_pedido);
        printf("\nultra = %i",ultra[0]);
        for(i=1 ; i<=ultra[0] ; i++)
        {

            if((*pe)[ultra[i]].id_pedido==aux_pedido)
            {
                p1=ultra[i];

            }
        }



    }
    while(p1==-1 && aux_pedido!=0);
    if(ultra[0]!=-1)
    {
        if ( strcmp( (*pe)[p1].lugar_entrega,"locker" ) == 0 )
        {
            p2=1;
        }

        if(p2==-1)
        {
            system("cls");
            printf("Este ID Pedido no es valido para asignarle un locker.\n");
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
                pe_asignar_locker_admin(pe,ppe,c,lo,cl);
            }
        }
        else// A PARTIR DE AQUI ES EL MENU ASGINAR
        {



            for (i=0; i<ncliente; i++)
            {
                if( (*pe)[p1].id_cliente == (*c)[i].id )
                {
                    strcpy(aux_localidad,(*c)[i].loc); //tenemos la localidad del cliente del pedido introducido
                }
            }

            //Lista lockers disponibles
            for(i = 0; i < nlockers; i++)
            {
                if( (( (*lo)[i].n_comp_ocupados) < ((*lo)[i].n_comp_total)) &&(  (strcmp( aux_localidad, (*lo)[i].locali ))==0   )     )
                {
                    printf("ID LOCKER= %i    LOCALIDAD= %s",(*lo)[i].id_locker,(*lo)[i].locali);
                    posLockerDisp[j] = i; //guardo la pos. de los lockers disponibles y que coincidan con la localidad
                    j++;
                    p3=0;
                }

            }


        }

        if(	p3==0)
        {
            do
            {

                do
                {
                    system("cls");
                    printf("\nMenu de Asignaciones-Locker para los pedidos de ESIZON");
                    printf("\nLocker disponibles para asignar en este pedido: ");
                    printf("\n---------------------------------------------");
                    for(i=0; i<j; i++)
                    {
                        printf("\n%i.- ID Locker: %i",i+1,(*lo)[posLockerDisp[i]].id_locker);
                    }

                    printf("\n---------------------------------------------\n");

                    printf("\nIntroduce un ID Locker: ");
                    fflush(stdin);
                    scanf("%i",&aux_locker);




//Miro si el locker introducido por teclado se encuentra en lockers disponibles
                    for(i=0; i<j; i++)
                    {
                        if ( aux_locker == (*lo)[posLockerDisp[i]].id_locker )
                        {
                            p4=1; //ya tenemos el id_locker
                        }
                    }
                    if(p4==-1)
                    {
                        system("cls");
                    }




                }
                while(p4==-1 );

                //
                //buscamos un comp. vacio con el id_locker: (aux_locker)
                for(i=0; i<ncomp_lockers && p5==0; i++)
                {

                    if( (*cl)[i].id_locker==aux_locker)
                    {
                        if( (strcmp((*cl)[i].estado,"vacio")==0) )
                        {
                            strcpy((*cl)[i].estado,"ocupado"); // solo para un compartimento
                            incrementar_fecha_locker(cl,15,(*cl)[i].fch_ocup,i);
                            strcpy((*cl)[i].fch_ocup,fechayhora);
                            aux_codigo = (*cl)[i].codigo;

                            p5=1;
                        }

                    }

                }
//
            }
            while(p5==0);
            locker_compartimentos_act(cl,lo,aux_locker);
//Para cada producto del pedido, le insertamos el codigo del comportimento.
            for(i=0; i<nt_prodpedidos; i++)
            {
                if(aux_pedido==(*ppe)[i].id_pedido)
                {
                    (*ppe)[i].cod_locker=aux_codigo;
                }
            }

            //asigno ese id locker al pedido (p1).
            (*pe)[p1].id_locker = aux_locker;
            guardar_prod_pedidos(ppe);
            guardar_pedidos(pe);
            guardar_comp_lockers(cl);
            guardar_lockers(lo);

            system("cls");
            printf("\n\nLocker asignado correctamente.");

        }
        else
        {
            system("cls");
            printf("No hay lockers disponibles en su localidad.\n");
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
                pe_asignar_locker_admin(pe,ppe,c,lo,cl);
            }

        }
    }
    return;
}

void locker_compartimentos_act(comp_lockers **cl, lockers **lo,int locker)
{
    //me meto en cada locker, luego, dentro de cada una cuento los compartimentos totales y los ocupados
    //guardo esos datos en la estructura y guardo LOCKERS

    int i,j,ocu=0,tot=0,pos;

    for(i=0; i<ncomp_lockers; i++)
    {
        if( (*cl)[i].id_locker==locker)
        {
            if( (strcmp((*cl)[i].estado,"ocupado")==0) )
            {
                ocu++;
                tot++;
            }
            else
                tot++;
        }

    }

    for (i=0; i<nlockers; i++)
    {
        if((*lo)[i].id_locker==locker)
        {
            pos=i;
        }
    }
    (*lo)[pos].n_comp_total=tot;
    (*lo)[pos].n_comp_ocupados=ocu;

    return;

}

void pe_asignar_trans(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr, int aux_pedido)
{
// asignación de transportistas a los productos pedidos en
// función de la dirección del cliente y ciudad de reparto.

//Elijo un pedido, una vez tengamos esa id_pedido, buscamos el cliente de ese pedido
//buscamos en prod_pedidos hasta dar con esa id.
//Buscamos transportistas con la misma localidad que el cliente.

    int op,i,aux_trans;
    int p1=-1,p3=-1,p4=1,p5=0; // puertas logicas
    char aux_localidad[20];

    //meto en poslockerDisp los lockers disponibles
    int posTransDisp;




    p1 = pe_existe_pedido(pe,aux_pedido); // p1 tiene la posicion de ese pedido


    if(p1!=-1)            // A PARTIR DE AQUI ES EL MENU ASGINAR
    {

        for (i=0; i<ncliente; i++)
        {
            if( (*pe)[p1].id_cliente == (*c)[i].id )
            {
                strcpy(aux_localidad,(*c)[i].loc); //tenemos la localidad del cliente del pedido introducido
            }
        }

        //transp disponible
        for(i = 0; i < ntransportistas; i++)
        {
            if(  (strcmp( aux_localidad, (*tr)[i].city ))==0   )
            {
                posTransDisp = i; //guardo la pos. de los lockers disponibles y que coincidan con la localidad
                p3=0;
            }

        }

        //Los productos del pedido no deben tener transportista asignado
        for(i=0; i<nt_prodpedidos; i++)
        {
            if(aux_pedido==(*ppe)[i].id_pedido)
            {
                p4=1;
                if((*ppe)[i].id_trans==0)
                {
                    p4=0;
                }

            }
        }

        if(p3==0 && p4==0)
        {
            for(i=0; i<nt_prodpedidos; i++)
            {
                if(aux_pedido==(*ppe)[i].id_pedido)
                {
                    (*ppe)[i].id_trans=(*tr)[posTransDisp].id_trans;
                }
            }
            guardar_prod_pedidos(ppe);

        }
    }
    return;
}

void pe_asignar_trans_admin(pedidos **pe, prod_pedidos **ppe, cliente **c, transportistas **tr)
{
    // asignación de transportistas a los productos pedidos en
// función de la dirección del cliente y ciudad de reparto.

//Elijo un pedido, una vez tengamos esa id_pedido, buscamos el cliente de ese pedido
//buscamos en prod_pedidos hasta dar con esa id.
//Buscamos transportistas con la misma localidad que el cliente.

    int op,i,aux_trans,aux_pedido;
    int p1=-1,p3=-1,p4=-1,p5=0; // puertas logicas
    char aux_localidad[20];
    int posTransDisp=-1;



    printf("\nMenu de Asignaciones-Transportistas para los pedidos de ESIZON");
    pe_listar_admin(pe, c);
    printf("\nIntroduce un ID Pedido: ");
    fflush(stdin);
    scanf("%i",&aux_pedido);

    p1 = pe_existe_pedido(pe,aux_pedido); // p1 tiene la posicion de ese pedido

    if(p1==-1)
    {
        system("cls");
        printf("\nMenu de Asignaciones-Transportistas para los pedidos de ESIZON");
        printf("\n\nEste ID Pedido no es valido.\n");
        system("cls");
        printf("Este ID Pedido no es valido para asignarle un locker.\n");
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
            pe_asignar_trans_admin(pe,ppe,c,tr);
        }
        return;
    }
    else// A PARTIR DE AQUI ES EL MENU ASGINAR
    {



        for (i=0; i<ncliente; i++)
        {
            if( (*pe)[p1].id_cliente == (*c)[i].id )
            {
                strcpy(aux_localidad,(*c)[i].loc); //tenemos la localidad del cliente del pedido introducido

            }
        }

        //transp disponible
        for(i = 0; i < ntransportistas; i++)
        {
            if(  (strcmp(aux_localidad,(*tr)[i].city))==0  ) //posible condicion extra
            {
                posTransDisp = i;
                p3=0;
            }

        }

        for(i=0; i<nt_prodpedidos; i++)
        {
            if(aux_pedido==(*ppe)[i].id_pedido)
            {
                p4=1;
                if((*ppe)[i].id_trans==0)
                {
                    p4=0;
                }

            }
        }

        if(p3==0 && p4==0)
        {
            for(i=0; i<nt_prodpedidos; i++)
            {
                if(aux_pedido==(*ppe)[i].id_pedido)
                {
                    (*ppe)[i].id_trans=(*tr)[posTransDisp].id_trans;
                }
            }
            guardar_prod_pedidos(ppe);
            system("cls");
            printf("\nMenu de Asignaciones-Transportistas para los pedidos de ESIZON");
            printf("\nTransportista asignado con exito.\nQue tenga un buen dia :)");
            return;
        }
        else
        {
            if(p3==-1)
            {
                system("cls");
                printf("\nMenu de Asignaciones-Transportistas para los pedidos de ESIZON");
                printf("\nNo hay transportistas disponibles en la localidad del cliente: %s.\n",aux_localidad);

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
                    pe_asignar_trans_admin(pe,ppe,c,tr);
                }
                return;
            }
            if(p4==1)
            {
                system("cls");
                printf("\nMenu de Asignaciones-Transportistas para los pedidos de ESIZON");
                printf("\nEste pedido ya tiene asignado un transportista.\n");
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
                    pe_asignar_trans_admin(pe,ppe,c,tr);
                }
                return;
            }

        }
    }
}


