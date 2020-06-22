
#include "Menu.h"



int interfaz(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl)
{
    int fin = 0;
    system("cls");

    switch((*usu)->tipo)
    {
    case 1://cliente
        fin = menu_cliente(c, ap, tr, usu, ca, pr, dev, des, desc, pe, ppe, lo, cl);
        break;
    case 2://administrador
        fin = menu_administrador(c, ap, tr, usu, ca, pr, dev, des, desc, pe, ppe, lo, cl);
        break;
    case 3://proveedor
        fin = menu_proveedor(c, ap, tr, usu, ca, pr, dev, des, desc, pe, ppe, lo, cl);
        break;
    case 4://transportista
        fin = menu_transportista(c, ap, tr, usu, ca, pr, dev, des, desc, pe, ppe, lo, cl);
        break;
    }

    return fin;
}



int menu_cliente(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl)
{
    int op, id, aux, p1, fin = 0;
    int *pos;
    char nombre[200];
    do
    {
        system("cls");
        printf("\n\n----------------------MENU----------------------\n\n");
        printf("\n1.- Perfil \n2.- Productos \n3.- Descuentos \n4.- Pedidos \n5.- Devoluciones \n6.- Salir del sistema\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
        if(0>=op|| op>6)
        {
            printf("\nESTA OPCION NO EXISTE\n");
            system("Pause");
        }
    }
    while(0>=op|| op>6);


    switch(op)
    {
    case 1://perfil
        modificar_clientes(c, usu);
        break;
    case 2://productos
        do
        {
            system("cls");
            printf("\n\n----------------------PRODUCTOS----------------------\n\n");
            printf("\n1.- Buscar por categoria \n2.- Buscar producto\n3.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            if(0>=op|| op>3)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>3);
        do
        {
            p1 = 0;
            switch(op)
            {
            case 1:
                listado_categorias(ca);
                printf("Introduzca el id de categoria: ");
                scanf("%i", &id);
                pos = busqueda_prodcatg(pr, ca, id);
                break;
            case 2:
                printf("\nIntroduzca el nombre del producto: ");
                scanf("%s", &nombre);
                pos = busqueda_producto(nombre, pr);
                break;
            case 3:
                p1 = 1;
                break;
            }

            for(int i = 1; i <= pos[0]; i++)
            {
                printf("\nId: %i\nNombre: %s\nCantidad: %i\nPrecio: %f",(*pr)[pos[i]].id_prod, (*pr)[pos[i]].descrp, (*pr)[pos[i]].stock, (*pr)[pos[i]].importe);
            }

            printf("\nIntroduzca el id de producto que quiere agregar a su cesta ( 0 para salir ): ");
            scanf("%i", &aux);
            if(aux != 0)
            {
                for(int c = 1; c <= pos[0]; c++)
                {

                    if(aux-1 == pos[c])
                    {
                        p1 = 1;
                    }
                }
                llenar_cesta(aux);
            }
            else
            {
                p1 = 1;
            }
        }
        while(p1 == 0);
        break;
    case 3://descuentos
        listar_descuentos_cliente(desc, (*usu)->id);
        break;
    case 4://pedidos // falta conseguir el cod de locker para esilocker


        do
        {
            system("cls");
            printf("\n\n----------------------PEDIDOS----------------------\n\n");
            printf("\n1.- Ver tus pedidos \n2.- Realizar pedido \n3.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");

            switch(op)
            {
            case 1:
                consultar_estado(pe,ppe,(*usu)->id);
                break;
            case 2:
                if(cesta[0] != -1)
                {
                    listado_cesta(pr);
                    dar_alta_pedidos(pe, ppe, c, des, usu, pr, desc, lo, cl, tr);
                }
                else
                {
                    printf("\nNo tiene productos en la cesta para pedir");
                }
                break;
            case 3:
                break;
            }
            if(0>=op|| op>3)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>3);
        break;
    case 5://devoluciones

        do
        {
            system("cls");
            printf("\n\n----------------------DEVOLUCIONES----------------------\n\n");
            printf("\n1.- Ver tus devoluciones \n2.- Realizar devoluciones \n3.- Enviar devolucion\n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");

            switch(op)
            {
            case 1:
                dev_seguimiento(dev, pe, usu, c);
                break;
            case 2:
                dev_alta_cliente(dev, pe, ppe, usu, c);
                break;
            case 3:
                dev_enviar(dev, pe, usu, c);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>3);
        break;
    case 6://salir sistema
        fin = 1;
        break;
    }
    return fin;
}





int menu_administrador(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl)
{
    int op, id, aux, p1, auxd;
    int fin = 0;
    int *pos;
    char nombre[200];
    do
    {
        system("cls");
        printf("\n\n----------------------MENU----------------------\n\n");
        printf("\n1.- Perfil \n2.- Clientes \n3.- Proveedores \n4.- Productos \n5.- Categoria \n6.- Pedidos\n7.- Transportistas\n8.- Descuentos\n9.- Devoluciones\n10.- Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
        if(0>=op|| op>10)
        {
            printf("\nESTA OPCION NO EXISTE\n");
            system("Pause");
        }
    }
    while(0>=op|| op>10);


    switch(op)
    {
    case 1://perfil
        modificar_administradores(ap, usu);
        break;
    case 2://Clientes
        do
        {
            system("cls");
            printf("\n\n----------------------CLIENTES----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");

            switch(op)
            {
                listado_clientes(c);
            case 1:
                registrar_cliente(c, usu);
                break;
            case 2:
                modificar_clientes(c, usu);
                break;
            case 3:
                eliminar_cliente(c, usu);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 3://proveedores
        do
        {
            system("cls");
            printf("\n\n----------------------PROVEEDORES----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            listado_prov(ap);
            switch(op)
            {
            case 1:
                registrar_prov(ap, usu);
                break;
            case 2:
                modificar_proveedores(ap, usu);
                break;
            case 3:
                eliminar_prov(ap, usu);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 4://Productos
        do
        {
            system("cls");
            printf("\n\n----------------------PRODUCTOS----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            switch(op)
            {
            case 1:
                registrar_producto(pr, ca, ap, usu);
                break;
            case 2:
                modificar_producto(pr, ca);
                break;
            case 3:
                eliminar_producto(pr);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }

        }
        while(0>=op|| op>4);
        break;
    case 5://categorias
        do
        {
            system("cls");
            printf("\n\n----------------------CATEGORIAS----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            listado_categorias(ca);
            switch(op)
            {
            case 1:
                registrar_categoria(ca);
                break;
            case 2:
                modificar_categoria(ca);
                break;
            case 3:
                eliminar_categorias(ca, pr);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 6://pedidos
        do
        {
            system("cls");
            printf("\n\n----------------------PEDIDOS----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Asignar transportistas\n5.- Asignar lockers\n6.- Listar pedidos\n 7.-Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            switch(op)
            {
            case 1:
                dar_alta_pedidos(pe, ppe, c, des, usu, pr, desc, lo, cl, tr);
                break;
            case 2:
                //modificar
                pe_modificar(pe, c);
                pe_modificar_prod(ppe, pe, c);
                break;
            case 3:
                //dar de baja pedidos
                dar_baja_pedidos(pe, ppe, c);
                break;
            case 4:
                pe_asignar_trans_admin(pe, ppe, c, tr);
                break;
            case 5:
                pe_asignar_locker_admin(pe, ppe, c, lo, cl);
                break;
            case 6:
                pe_listar_admin(pe, c);
                break;
            case 7:
                break;
            }
            if(0>=op|| op>7)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 7://transportistas
        do
        {
            system("cls");
            printf("\n\n----------------------TRANSPORTISTAS----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            listado_categorias(ca);
            switch(op)
            {
            case 1:
                registrar_transport(tr, usu);
                break;
            case 2:
                modificar_transportistas(tr, usu);
                break;
            case 3:
                eliminar_transport(tr, usu);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 8://descuentos
        do
        {
            system("cls");
            printf("\n\n----------------------DESCUENTOS----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Buscar descuento\n5.- Listado descuento-cliente\n6.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            listado_categorias(ca);
            switch(op)
            {
                listar_des(des);
            case 1:
                alta_des(des);
                break;
            case 2:
                modificar_des(des);
                break;
            case 3:
                baja_des(des);
                break;
            case 4:
                auxd = busqueda_des(des);
                    printf(" Id. Código: %i\n Descripción: %s\n Tipo: %s\n Estado: %i\n Importe: %.2f\n Aplicabilidad: %s\n\n\n", (*des)[auxd].id_promo, (*des)[auxd].descr, (*des)[auxd].tipo_cod, (*des)[auxd].estado, (*des)[auxd].importe, (*des)[auxd].aplic);
                break;
            case 5:
                printf("Introdizca una Id de cliente para buscar sus descuentos");
                scanf("%i", &id);
                listar_descuentos_cliente(desc, id);
                break;
            case 6:
                break;
            }
            if(0>=op|| op>6)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 9://devoluciones
        do
        {
            system("cls");
            printf("\n\n----------------------DEVOLUCIONES----------------------\n\n");
            printf("\n1.- Dar de alta \n2.- Modificar \n3.- Dar de baja \n4.- Salir\nElija una opcion: ");
            fflush(stdin);
            scanf("%i", &op);
            system("cls");
            listado_categorias(ca);
            switch(op)
            {
                dev_listar(dev, pe);
            case 1:
                dev_alta_admin(dev, pe, ppe, usu, c);
                break;
            case 2:
                dev_modificar(dev, pe);
                break;
            case 3:
                dev_baja_admin(dev, pe, ppe, usu, c);
                break;
            case 4:
                break;
            }
            if(0>=op|| op>4)
            {
                printf("\nESTA OPCION NO EXISTE\n");
                system("Pause");
            }
        }
        while(0>=op|| op>4);
        break;
    case 10://salir sistema
        fin = 1;
        break;
    }
    return fin;
}




int menu_proveedor(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl)
{
    int op, id, aux, p1, fin = 0;
    int *pos;
    char nombre[200];
    do
    {
        system("cls");
        printf("\n\n----------------------MENU----------------------\n\n");
        printf("\n1.- Perfil \n2.- Productos \n3.- Pedidos \n4.- Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
        if(0>=op|| op>6)
        {
            printf("\nESTA OPCION NO EXISTE\n");
            system("Pause");
        }
    }
    while(0>=op|| op>4);


    switch(op)
    {
    case 1://perfil
        modificar_proveedores(ap, usu);
        break;
    case 2://productos
        modificar_producto(pr, ca, usu);
        break;
    case 3://pedidos
        listar_pedidos_proveedor(pe, ppe, pr, usu);
        pe_asignar_locker_proveedor(pe, ppe, c, lo, cl, usu, pr);
        break;
    case 4://salir del sistema
        fin = 1;
        break;
    }
    return fin;
}


int menu_transportista(cliente **c, adminprov **ap, transport **tr, usuario **usu, catg **ca, prod **pr, devoluciones **dev, descuentos **des, descliente **desc, pedidos **pe, prod_pedidos **ppe, lockers **lo, comp_lockers **cl)
{
    int op, id, aux, p1, fin = 0;
    int *pos;
    char nombre[200];
    do
    {
        system("cls");
        printf("\n\n----------------------MENU----------------------\n\n");
        printf("\n1.- Perfil \n2.- Retornos \n3.- Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%i", &op);
        system("cls");
        if(0>=op|| op>6)
        {
            printf("\nESTA OPCION NO EXISTE\n");
            system("Pause");
        }
    }
    while(0>=op|| op>4);


    switch(op)
    {
    case 1://perfil
        modificar_transportistas(tr, usu);
        break;
    case 2://repartos
        estado_pedido(pe, ppe, tr, (*usu)->id);
        break;
    case 3://salir del sistema
        fin = 1;
        break;
    }
    printf("fin-");
    system("Pause");
    return fin;
}


void presentacion()
{
    printf("\n\n");
    printf("             XXXXXX\n");
    printf("             X\n");
    printf("             X\n");
    printf("             XXXX\n");
    printf("             X\n");
    printf("             X\n");
    printf("             XXXXXX");

    Sleep(100);
    system("cls");
//system("color 79");

    printf("\n\n");
    printf("             XXXXXX  XXXXXX\n");
    printf("             X       X\n");
    printf("             X       X\n");
    printf("             XXXX    XXXXXX\n");
    printf("             X            X\n");
    printf("             X            X\n");
    printf("             XXXXXX  XXXXXX");

    Sleep(100);
    system("cls");
//system("color 7d");

    printf("\n\n");
    printf("             XXXXXX  XXXXXX  XXXXXX\n");
    printf("             X       X         XX\n");
    printf("             X       X         XX\n");
    printf("             XXXX    XXXXXX    XX\n");
    printf("             X            X    XX\n");
    printf("             X            X    XX\n");
    printf("             XXXXXX  XXXXXX  XXXXXX");

    Sleep(100);
    system("cls");
//system("color 79");

    printf("\n\n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX\n");
    printf("             X       X         XX          X \n");
    printf("             X       X         XX        X   \n");
    printf("             XXXX    XXXXXX    XX     XXXXXX \n");
    printf("             X            X    XX      X     \n");
    printf("             X            X    XX     X      \n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX");

    Sleep(100);
    system("cls");
//system("color 7d");

    printf("\n\n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX   XXXXXX \n");
    printf("             X       X         XX          X   X      X\n");
    printf("             X       X         XX        X     X      X\n");
    printf("             XXXX    XXXXXX    XX     XXXXXX   X      X\n");
    printf("             X            X    XX      X       X      X\n");
    printf("             X            X    XX     X        X      X\n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX   XXXXXX ");

    Sleep(100);
    system("cls");
//system("color 79");

    printf("\n\n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX   XXXXXX    XX      X\n");
    printf("             X       X         XX          X   X      X   X X     X\n");
    printf("             X       X         XX        X     X      X   X  X    X\n");
    printf("             XXXX    XXXXXX    XX     XXXXXX   X      X   X   X   X\n");
    printf("             X            X    XX      X       X      X   X    X  X\n");
    printf("             X            X    XX     X        X      X   X     X X\n");
    printf("             XXXXXX  XXXXXX  XXXXXX  XXXXXXXX   XXXXXX    X      XX ");

    Sleep(600);
    system("cls");
    system("color 0f");

    printf("\n\n               REALIZADOR POR:\n");

    printf("                      +---------------------------------+\n");
    printf("                      |                                 |\n");
    printf("                      |    Alejandro Arias Casquero     |\n");
    printf("                      |  Sergio Cabeza de Vaca Montero  |\n");
    printf("                      |    Rafael Rodriguez Calvente    |\n");
    printf("                      |                                 |\n");
    printf("                      +---------------------------------+\n");

    system("pause");
    system("cls");

    return;
}








