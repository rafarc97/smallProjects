
#include "DatosUsuarios.h"


void cargar_clientes(cliente **c, usuario **usu)
{
    char linea[240];
    char *token;
    FILE *f;

    ncliente=0;


    f=fopen("Clientes.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *c = malloc(1 * sizeof(cliente));
        *usu=malloc(1 * sizeof(usuario));
        while(fgets(linea,240,f)!=NULL)
        {
            *c=(cliente*)realloc((*c),(ncliente+1)*sizeof(cliente));

            if((*c)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*c)[ncliente].id=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*c)[ncliente].nom,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].apell,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].dir,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].loc,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].prov,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].mail,token);
                token=strtok(NULL,"/");
                strcpy((*c)[ncliente].pass,token);
                token=strtok(NULL,"\n");
                (*c)[ncliente].cartera=atof(token);
                ncliente++;
            }
        }
        fclose(f);
    }
}

void guardar_cliente(cliente **c)
{
    FILE *f;
    int i;
    f=fopen("Clientes.txt","w+");
    for(i=0; i<ncliente; i++)
    {
        fprintf(f,"%i/%s/%s/%s/%s/%s/%s/%s/%.2f\n",(*c)[i].id,(*c)[i].nom,(*c)[i].apell,(*c)[i].dir,(*c)[i].loc,(*c)[i].prov,(*c)[i].mail,(*c)[i].pass,(*c)[i].cartera);
    }
    fclose(f);
}


void cargar_adminprov(adminprov **ap)
{

    char linea[120];
    char *token;
    FILE *f;

    nadminprov=0;


    f=fopen("AdminProv.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *ap=malloc(1*sizeof(adminprov));

        while(fgets(linea,120,f)!=NULL)
        {
            *ap=(adminprov*)realloc((*ap),(nadminprov+1)*sizeof(adminprov));

            if((*ap)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*ap)[nadminprov].id_empr=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*ap)[nadminprov].name_empr,token);
                token=strtok(NULL,"/");
                strcpy((*ap)[nadminprov].mail,token);
                token=strtok(NULL,"/");
                strcpy((*ap)[nadminprov].pass,token);
                token=strtok(NULL,"\n");
                strcpy((*ap)[nadminprov].type,token);

                nadminprov++;
            }
        }
        fclose(f);
    }
}

void guardar_adminprov(adminprov **ap)
{
    FILE *f;
    int i;
    f=fopen("AdminProv.txt","w+");
    for(i=0; i<nadminprov; i++)
    {
        fprintf(f,"%i/%s/%s/%s/%s\n",(*ap)[i].id_empr,(*ap)[i].name_empr,(*ap)[i].mail,(*ap)[i].pass,(*ap)[i].type);
    }
    fclose(f);
}



void cargar_transportista(transport **tr)
{

    char linea[70];
    char *token;
    FILE *f;

    ntransport=0;


    f=fopen("Transportista.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *tr=malloc(1*sizeof(transport));

        while(fgets(linea,70,f)!=NULL)
        {
            *tr=(transport*)realloc((*tr),(ntransport+1)*sizeof(transport));

            if((*tr)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"/");
                (*tr)[ntransport].id_trans=atoi(token);
                token=strtok(NULL,"/");//leer entre barras del ficharo y lo guarda en la variable token.
                strcpy((*tr)[ntransport].mail,token);
                token=strtok(NULL,"/");
                strcpy((*tr)[ntransport].pass,token);
                token=strtok(NULL,"/");
                strcpy((*tr)[ntransport].nomb_emp,token);
                token=strtok(NULL,"\n");
                strcpy((*tr)[ntransport].city,token);
                ntransport++;
            }
        }
        fclose(f);
    }
}

void guardar_transportista(transport **tr)
{
    FILE *f;
    int i;
    f=fopen("Transportista.txt","w+");
    for(i=0; i<ntransport; i++)
    {
        fprintf(f,"%i/%s//%s/%s/%s\n",(*tr)[i].id_trans, (*tr)[i].mail, (*tr)[i].pass, (*tr)[i].nomb_emp, (*tr)[i].city);
    }
    fclose(f);
}



void iniciar_sesion(cliente **c, adminprov **ap, transport **tr, usuario **usu)
{
    int op;
    do
    {
        system("cls");
        printf("1.- Iniciar sesion\n2.- Crear cuenta como cliente\n3.- Cerrar\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
    }
    while(0>op|| op>3);
    switch(op)
    {

    case 1:
        tipo_usuario(usu);
        acceder_cuenta(c, ap, tr, usu);
        break;
    case 2:
        registrar_cliente(c, usu);
        break;
    case 3:
        exit(-1);
        break;
    }
    return;
}

void buscar_cliente(char* mail, cliente **c, usuario **usu)
{
    (*usu)->pos = -1;

    for(int i= 0; i < ncliente; i++)
    {
        if(strcmp(mail, (*c)[i].mail) == 0)
        {
            (*usu)->pos = i;
            (*usu)->id = (*c)[i].id;
            i = ncliente + 1;
        }
    }
    return;
}

void buscar_adminprov(char* mail, adminprov **ap, usuario **usu)
{
    (*usu)->pos = -1;

    for(int i= 0; i< nadminprov; i++ )
    {
        if(strcmp(mail, (*ap)[i].mail) == 0)
        {
            if(strcmp((*ap)[i].type, "admin") == 0)
            {
                (*usu)->pos = i;
                (*usu)->id = (*ap)[i].id_empr;
                (*usu)->tipo = 2;
            }
            if(strcmp((*ap)[i].type, "prov") == 0)
            {
                (*usu)->pos = i;
                (*usu)->id = (*ap)[i].id_empr;
                (*usu)->tipo = 3;
            }
            i = nadminprov + 1;
        }
    }
    return;
}

void buscar_transport(char* mail, transport **tr, usuario **usu)
{
    (*usu)->pos = -1;

    for(int i= 0; i< ntransport; i++ )
    {
        if(strcmp(mail, (*tr)[i].mail) == 0)
        {
            (*usu)->pos = i;
            (*usu)->id = (*tr)[i].id_trans;
            i = ntransport + 1;
        }
    }
    return;
}


void tipo_usuario(usuario **usu)
{
    do
    {
        system("cls");
        printf("1.- Cliente\n2.- Administrador\n3.- Proveedor\n4.- Transportista\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &(*usu)->tipo);
    }
    while( 0>(*usu)->tipo || (*usu)->tipo>4);
    return;
}


void acceder_cuenta(cliente **c, adminprov **ap, transport **tr, usuario **usu)
{

    int op;
    char mail[50];
    char user[15];
    system("cls");
    printf("\nIntroduzca su email: ");
    fflush(stdin);
    scanf("%s", mail);

    switch((*usu)->tipo)
    {
    case 1:
        buscar_cliente(mail, c, usu);
        strcpy(user, "cliente");
        break;
    case 2:
        buscar_adminprov(mail, ap, usu);
        if((*usu)->tipo != 2)
        {
            strcpy(user, "administrador");
            (*usu)->pos = -1;
        }
        break;
    case 3:
        buscar_adminprov(mail, ap, usu);
        if((*usu)->tipo != 3)
        {
            strcpy(user, "proveedor");
            (*usu)->pos = -1;
        }
        break;
    case 4:
        buscar_transport(mail, tr, usu);
        if((*usu)->tipo != 4)
        {
            strcpy(user, "transportista");
            (*usu)->pos = -1;
            break;
        }
    }
    if((*usu)->pos != -1)
    {
        switch((*usu)->tipo)
        {
        case 1:
            comprobar_pass((*c)[(*usu)->pos].pass);
            break;
        case 2:
        case 3:
            comprobar_pass((*ap)[(*usu)->pos].pass);
            break;
        case 4:
            comprobar_pass((*tr)[(*usu)->pos].pass);
            break;

        }
    }
    else
    {
        system("cls");
        printf("Este correo no esta registrado como %s\n", user);
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
            tipo_usuario(usu);
            acceder_cuenta(c, ap, tr, usu);
        }
        if(op == 2)
        {
            exit(-1);
        }
    }
    return;
}



void comprobar_pass (char* pass)
{
    char c[20];
    int op;
    system("cls");
    printf("\nIntroduzca su contraseña: ");
    scanf("%s", c);
    if(strcmp(pass, c) != 0)
    {
        system("cls");
        printf("Esta contraseña no es correcta\n");

        do
        {
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>=op || op>2);
        if(op == 1)
        {
            comprobar_pass(pass);
        }
        if(op == 2)
        {
            exit(-1);
        }
    }
    return;
}



void modificar_clientes(cliente **c, usuario **usu)
{
    int op, tempi, tempp;
    float saldo;
    char mail[50];

    tempi = (*usu)->id;
    tempp = (*usu)->pos;

    if((*usu)->tipo == 2)
    {
        listado_clientes(c);
        printf("Introduce el correo que quiere modificar: ");
        scanf("%s", mail);
        buscar_cliente(mail, c, usu);
        if((*usu)->pos == -1)
        {
            system("cls");
            printf("Este correo no esta registrado como cliente\n");
            do
            {
                printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
                fflush(stdin);
                scanf("%i", &op);
                system("cls");
            }
            while(0>=op|| op>2);
            if(op == 1)
            {
                (*usu)->id = tempi;
                (*usu)->pos = tempp;
                modificar_clientes(c, usu);
            }
            else
            {
                (*usu)->id = tempi;
                (*usu)->pos = tempp;
                return;
            }
        }
    }
    do
    {
        do
        {
            system("cls");
            printf("\n\n----------------------PERFIL----------------------\n\n");
            printf("\n1.- Nombre: %s\n2.- Apellido: %s\n3.- Direccion: %s\n4.- Localidad: %s\n5.- Provincia: %s\n6.- Correo: %s\n7.- Contraseña: %s\n8.- Cartera: %.2f\n9.- Salir\nElija una opcion: ", (*c)[(*usu)->pos].nom,(*c)[(*usu)->pos].apell, (*c)[(*usu)->pos].dir, (*c)[(*usu)->pos].loc, (*c)[(*usu)->pos].prov, (*c)[(*usu)->pos].mail, (*c)[(*usu)->pos].pass, (*c)[(*usu)->pos].cartera);
            fflush(stdin);
            scanf("%i", &op);
            switch(op)
            {
            case 1:
                printf("Introduce nuevo nombre: ");
                scanf("%s", &(*c)[(*usu)->pos].nom);
                break;
            case 2:
                printf("Introduce nuevo apellido: ");
                scanf("%s", &(*c)[(*usu)->pos].apell);
                break;
            case 3:
                printf("Introduce nueva direccion: ");
                scanf("%s", &(*c)[(*usu)->pos].dir);
                break;
            case 4:
                printf("Introduce nueva localidad: ");
                scanf("%s", &(*c)[(*usu)->pos].loc);
                break;
            case 5:
                printf("Introduce nueva provincia: ");
                scanf("%s", &(*c)[(*usu)->pos].prov);
                break;
            case 6:
                printf("Introduce nuevo correo: ");
                scanf("%s", &(*c)[(*usu)->pos].mail);
                break;
            case 7:
                printf("Introduce nueva contraseña: ");
                scanf("%s", &(*c)[(*usu)->pos].pass);
                break;
            case 8:
                printf("Introduzca cuanto dinero quiere añadir a su cartera: +  ");
                scanf("%f", &saldo);
                (*c)[(*usu)->pos].cartera = saldo + (*c)[(*usu)->pos].cartera;
                break;
            }

        }
        while(0>=op || op>9);
        system("cls");
        printf("1.- Modificar otro dato\n2.- cerrar\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
    }
    while(op==1);

    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    guardar_cliente(c);
    return;
}


void modificar_proveedores(adminprov **ap, usuario **usu)
{
    int op, tempi, tempp, tempt;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    tempt = (*usu)->tipo;
    if((*usu)->tipo == 2)
    {
        printf("Introduce el correo que quiere modificar: ");
        scanf("%s", mail);
        buscar_adminprov(mail, ap, usu);
    }
    if((*usu)->pos == -1)
    {
        system("cls");
        printf("Este correo no esta registrado como proveedor\n");
        do
        {
            printf("1.- Reintentar\n2.- Cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
        }
        while(0>=op|| op>2);
        if(op == 1)
        {
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            (*usu)->tipo = tempt;
            modificar_proveedores(ap, usu);
        }
        else
        {
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            (*usu)->tipo = tempt;
            return;
        }
    }
    else
    {
        do
        {
            do
            {
                system("cls");
                printf("\n\n----------------------Proveedor----------------------\n\n");
                printf("\n1.- Nombre de Empresa: %s\n2.- Correo: %s\n3.- Contraseña: %s\n4.- Salir\nElija una opcion: ", (*ap)[(*usu)->pos].name_empr, (*ap)[(*usu)->pos].mail, (*ap)[(*usu)->pos].pass);
                fflush(stdin);
                scanf("%i", &op);
                switch(op)
                {
                case 1:
                    printf("Introduce nuevo nombre de empresa: ");
                    scanf("%s", &(*ap)[(*usu)->pos].name_empr);
                    break;
                case 2:
                    printf("Introduce nuevo correo: ");
                    scanf("%s", &(*ap)[(*usu)->pos].mail);
                    break;
                case 3:
                    printf("Introduce nueva contraseña: ");
                    scanf("%s", &(*ap)[(*usu)->pos].pass);
                    break;
                case 4:
                    break;
                }
            }
            while(0>=op || op>4);
            system("cls");
            printf("1.- Modificar otro dato\n2.- cerrar\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
        }
        while(op == 1);

        (*usu)->id = tempi;
        (*usu)->pos = tempp;
        (*usu)->tipo = tempt;
        guardar_adminprov(ap);
    }
    return;
}

void modificar_administradores(adminprov **ap, usuario **usu)
{
    int op;
    do
    {
        do
        {
            system("cls");
            printf("\n\n----------------------ADMINISTRADOR----------------------\n\n");
            printf("\n1.- Nombre: %s\n2.- Correo: %s\n3.- Contraseña: %s\n", (*ap)[(*usu)->pos].name_empr,(*ap)[(*usu)->pos].mail,(*ap)[(*usu)->pos].pass);
            printf("4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            switch(op)
            {
            case 1:
                printf("Introduce nuevo nombre : ");
                scanf("%s", &(*ap)[(*usu)->pos].name_empr);
                break;
            case 2:
                printf("Introduce nuevo correo: ");
                scanf("%s", &(*ap)[(*usu)->pos].mail);
                break;
            case 3:
                printf("Introduce nueva contraseña: ");
                scanf("%s", &(*ap)[(*usu)->pos].pass);
                break;
            case 4:
                break;
            }
            guardar_adminprov(ap);
        }
        while(0>=op || op>4);
        system("cls");
        printf("1.- Modificar otro dato\n2.- cerrar\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
    }
    while(0>=op || op>2);
    return;
}


void modificar_transportistas(transport **tr, usuario **usu)
{
    int op, tempi, tempp;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    if((*usu)->tipo == 2)
    {
        listado_transport(tr);

        printf("Introduce el correo que quiere modificar: ");
        scanf("%s", mail);
        buscar_transport(mail, tr, usu);
        if((*usu)->pos != -1)
        {
            system("cls");
            printf("Este correo no esta registrado como transportista\n");
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
                (*usu)->id = tempi;
                (*usu)->pos = tempp;
                modificar_transportistas(tr, usu);
            }
            if(op == 2)
            {
                (*usu)->id = tempi;
                (*usu)->pos = tempp;
            }
            else
            {
                (*usu)->id = tempi;
                (*usu)->pos = tempp;
                return;
            }
        }
    }
    do
    {
        do
        {
            system("cls");
            printf("\n\n----------------------Proveedor----------------------\n\n");
            printf("\n1.- Nombre de Empresa: %s\n2.- Correo: %s\n3.- Contraseña: %s\n4.- Ciudad\n5.- Salir\nElija una opcion: ", (*tr)[(*usu)->pos].nomb_emp, (*tr)[(*usu)->pos].mail, (*tr)[(*usu)->pos].pass, (*tr)[(*usu)->pos].city);
            fflush(stdin);
            scanf("%i", &op);
            switch(op)
            {
            case 1:
                printf("Introduce nuevo nombre de empresa: ");
                scanf("%s", &(*tr)[(*usu)->pos].nomb_emp);
                break;
            case 2:
                printf("Introduce nuevo apellido: ");
                scanf("%s", &(*tr)[(*usu)->pos].mail);
                break;
            case 3:
                printf("Introduce nueva contraseña: ");
                scanf("%s", &(*tr)[(*usu)->pos].pass);
                break;
            case 4:
                printf("Introduce nueva ciudad: ");
                scanf("%s", &(*tr)[(*usu)->pos].city);
                break;
            case 5:
                break;
            }
            guardar_transportista(tr);
        }
        while(0>=op || op>4);
        system("cls");
        printf("1.- Modificar otro dato\n2.- cerrar\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
    }
    while(op == 1);
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    return;
}


void listado_clientes(cliente **c)
{
    printf("\n\n----------------------Clientes----------------------\n\n");
    for(int i = 0; i < ncliente; i++)
    {
        printf("%i/%s/%s/%s/%s/%s/%s/%s/%f\n",(*c)[i].id,(*c)[i].nom,(*c)[i].apell,(*c)[i].dir,(*c)[i].loc,(*c)[i].prov,(*c)[i].mail,(*c)[i].pass,(*c)[i].cartera);
    }
    return;
}

void listado_admin(adminprov **ap)
{
    printf("\n\n----------------------Administradores----------------------\n\n");
    for(int i = 0; (( i < nadminprov )) ; i++)
    {
        if( strcmp((*ap)[i].type, "admin") == 0 )
        {
            printf("%i/%s/%s/%s\n",(*ap)[i].id_empr,(*ap)[i].name_empr,(*ap)[i].mail,(*ap)[i].pass);
        }
    }
    return;
}



void listado_prov(adminprov **ap)
{
    printf("\n\n----------------------Proveedores----------------------\n\n");
    for(int i = 0; (( i < nadminprov )) ; i++)
    {
        if( strcmp((*ap)[i].type, "prov") == 0 )
        {
            printf("%i/%s/%s/%s\n",(*ap)[i].id_empr,(*ap)[i].name_empr,(*ap)[i].mail,(*ap)[i].pass);
        }
    }
    return;
}


void listado_transport(transport **tr)
{
    printf("\n\n----------------------Transportistas----------------------\n\n");
    for(int i = 0; i < ntransport; i++)
    {
        printf("%i/%s/%s/%s/%s\n",(*tr)[i].id_trans, (*tr)[i].mail, (*tr)[i].pass, (*tr)[i].nomb_emp, (*tr)[i].city);
    }
    return;
}




//dar de alta y de baja todo


void registrar_cliente(cliente **c, usuario **usu)
{
    float saldo;
    char mail[50];
    int tempi, tempp;
    ncliente++;
    *c=(cliente*)realloc((*c),(ncliente+1)*sizeof(cliente));

    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    system("cls");
    do
    {
        if((*usu)->pos != tempp)
        {
            system("cls");
            printf("Este correo ya esta en uso\n");
        }
        printf("Introduce nuevo correo: ");
        scanf("%s", mail);
        buscar_cliente(mail, c, usu);

    }
    while( (*usu)->pos != -1 );

    strcpy((*c)[ncliente-1].mail, mail);

    printf("Introduce nueva contraseña: ");
    scanf("%s", &(*c)[ncliente-1].pass);
    system("cls");
    printf("Introduce nuevo nombre: ");
    scanf("%s", &(*c)[ncliente-1].nom);
    system("cls");
    printf("Introduce nuevo apellido: ");
    scanf("%s", &(*c)[ncliente-1].apell);
    system("cls");
    printf("Introduce nueva direccion: ");
    scanf("%s", &(*c)[ncliente-1].dir);
    system("cls");
    printf("Introduce nueva localidad: ");
    scanf("%s", &(*c)[ncliente-1].loc);
    system("cls");
    printf("Introduce nueva provincia: ");
    scanf("%s", &(*c)[ncliente-1].prov);
    system("cls");
    printf("Introduzca cuanto dinero quiere añadir a su cartera: +");
    scanf("%f", &saldo);
    (*c)[ncliente-1].cartera = 0;
    (*c)[ncliente-1].cartera = saldo + (*c)[ncliente].cartera;
    (*c)[ncliente-1].id = ncliente;
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    guardar_cliente(c);
    return;
}

void eliminar_cliente(cliente **c, usuario **usu)
{

    int tempi, tempp, op;
    cliente aux;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    printf("Introduce el correo que quiere eliminar: ");
    scanf("%s", mail);
    buscar_cliente(mail, c, usu);
    if((*usu)->pos == -1)
    {
        system("cls");
        printf("Este correo no esta registrado como cliente\n");
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
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            eliminar_cliente(c, usu);
        }
    }
    else
    {
        ncliente--;
        (*c)[ncliente].id = (*c)[(*usu)->pos].id;
        (*c)[(*usu)->pos] = (*c)[ncliente];

        *c=(cliente*)realloc((*c),(ncliente+1)*sizeof(cliente));
        guardar_cliente(c);
    }

    (*usu)->id = tempi;
    (*usu)->pos = tempp;

    return;
}



void registrar_admin(adminprov **ap, usuario **usu)
{
    int tempi, tempp;
    char mail[50];
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    nadminprov++;
    *ap=(adminprov*)realloc((*ap),(nadminprov+1)*sizeof(adminprov));
    system("cls");
    do
    {
        if((*usu)->pos != tempp)
        {
            printf("Este correo ya esta en uso\n");
        }
        printf("Introduce nuevo correo: ");
        scanf("%s", mail);
        buscar_adminprov(mail, ap, usu);

    }
    while( (*usu)->pos != -1 );

    strcpy((*ap)[nadminprov-1].mail, mail);

    printf("Introduce nueva contraseña: ");
    scanf("%s", &(*ap)[nadminprov-1].pass);
    system("cls");
    (*ap)[nadminprov-1].id_empr = nadminprov;
    strcpy((*ap)[nadminprov-1].type, "admin");
    system("cls");
    printf("Introduce nuevo nombre de empresa: ");
    scanf("%s", &(*ap)[nadminprov-1].name_empr);
    system("cls");

    (*usu)->id = tempi;
    (*usu)->pos = tempp;

    guardar_adminprov(ap);
    return;
}






void eliminar_admin(adminprov **ap, usuario **usu)
{

    int tempi, tempp, op;
    adminprov aux;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    printf("Introduce el correo que quiere eliminar: ");
    fflush(stdin);
    gets(mail);
    buscar_adminprov(mail, ap, usu);
    if((*usu)->pos != -1 && strcmp((*ap)[(*usu)->pos].type, "admin") == 0 )
    {
        system("cls");
        printf("Este correo no esta registrado como administrador\n");
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
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            eliminar_admin(ap, usu);
        }
    }
    else
    {
        nadminprov--;
        (*ap)[nadminprov].id_empr = (*ap)[(*usu)->pos].id_empr;
        (*ap)[(*usu)->pos] = (*ap)[nadminprov];

        *ap=(adminprov*)realloc((*ap),(nadminprov+1)*sizeof(adminprov));
        guardar_adminprov(ap);
    }

    (*usu)->id = tempi;
    (*usu)->pos = tempp;

    return;
}






void registrar_prov(adminprov **ap, usuario **usu)
{
    int tempi, tempp, tempt;
    char mail[50];
    tempi= (*usu)->pos;
    tempp = (*usu)->pos;
    tempt = (*usu)->tipo;
    nadminprov++;
    *ap=(adminprov*)realloc((*ap),(nadminprov+1)*sizeof(adminprov));
    system("cls");
    do
    {
        if((*usu)->pos != tempp)
        {

            printf("Este correo ya esta en uso\n");
        }
        printf("Introduce nuevo correo: ");
        fflush(stdin);
        gets(mail);
        buscar_adminprov(mail, ap, usu);

    }
    while( (*usu)->pos != -1 );

    strcpy((*ap)[nadminprov-1].mail, mail);

    (*ap)[nadminprov-1].id_empr = nadminprov;
    strcpy((*ap)[nadminprov-1].type, "prov");

    printf("Introduce nuevo nombre de empresa: ");
    scanf("%s", &(*ap)[nadminprov-1].name_empr);

    printf("Introduce nueva contraseña: ");
    scanf("%s", &(*ap)[nadminprov-1].pass);
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    (*usu)->tipo = tempt;
    guardar_adminprov(ap);
    return;
}




void eliminar_prov(adminprov **ap, usuario **usu)
{
    int tempi, tempp, tempt, op;
    adminprov aux;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    tempt = (*usu)->tipo;
    printf("Introduce el correo que quiere eliminar: ");
    fflush(stdin);
    gets(mail);
    buscar_adminprov(mail, ap, usu);
    if((*usu)->pos == -1)
    {
        system("cls");
        printf("Este correo no esta registrado como administrador\n");
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
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            (*usu)->tipo = tempt;
            eliminar_prov(ap, usu);
        }
    }
    else
    {

        nadminprov--;
        (*ap)[nadminprov].id_empr = (*ap)[(*usu)->pos].id_empr;
        (*ap)[(*usu)->pos] = (*ap)[nadminprov];

        *ap=(adminprov*)realloc((*ap),(nadminprov+1)*sizeof(adminprov));
        guardar_adminprov(ap);
    }

    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    (*usu)->tipo = tempt;

    return;
}


void registrar_transport(transport **tr, usuario **usu)
{
    int tempi, tempp, tempt;
    char mail[50];
    ntransport++;
    *tr=(transport*)realloc((*tr),(ntransport+1)*sizeof(transport));

    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    tempt = (*usu)->tipo;
    system("cls");
    do
    {
        if((*usu)->pos != tempp)
        {
            system("cls");
            printf("Este correo ya esta en uso\n");
        }
        printf("Introduce nuevo correo: ");
        fflush(stdin);
        gets(mail);
        buscar_transport(mail, tr, usu);

    }
    while( (*usu)->pos != -1 );

    strcpy((*tr)[ntransport-1].mail, mail);

    printf("Introduce nueva contraseña: ");
    scanf("%s", &(*tr)[ntransport-1].pass);
    system("cls");
    printf("Introduce nuevo nombre de empresa: ");
    scanf("%s", &(*tr)[ntransport-1].nomb_emp);
    system("cls");
    printf("Introduce nueva ciudad de reparto: ");
    scanf("%s", &(*tr)[ntransport-1].city);
    system("cls");
    (*tr)[ntransport-1].id_trans = ntransport;
    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    (*usu)->tipo = tempt;
    guardar_transportista(tr);
    return;
}


void eliminar_transport(transport **tr, usuario **usu)
{

    int tempi, tempp, tempt, op;
    transport aux;
    char mail[50];
    tempi = (*usu)->id;
    tempp = (*usu)->pos;
    tempt = (*usu)->tipo;
    printf("Introduce el correo que quiere eliminar: ");
    scanf("%s", mail);
    buscar_transport(mail, tr, usu);
    if((*usu)->pos != -1)
    {
        system("cls");
        printf("Este correo no esta registrado como tranportista\n");
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
            (*usu)->id = tempi;
            (*usu)->pos = tempp;
            (*usu)->tipo = tempt;
            eliminar_transport(tr, usu);
        }
    }
    else
    {
        ntransport--;
        (*tr)[ntransport].id_trans = (*tr)[(*usu)->pos].id_trans;
        (*tr)[(*usu)->pos] = (*tr)[ntransport];

        *tr=(transport*)realloc((*tr),(ntransport+1)*sizeof(transport));
        guardar_transportista(tr);
    }

    (*usu)->id = tempi;
    (*usu)->pos = tempp;
    (*usu)->tipo = tempt;

    return;
}




