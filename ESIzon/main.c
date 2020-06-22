



#include "Productos_Categorias.h"
#include "DatosUsuarios.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    //estructuras
    prod *pr;
    catg *ca;
    transport *tr;
    adminprov *ap;
    cliente *c;
    usuario *usu;
    descliente *desc;
    descuentos *des;
    lockers *lo;
    comp_lockers *cl;
    pedidos *pe;
    prod_pedidos *ppe;
    devoluciones *dev;
    int fin = 0;
    //fin estructuras ------------------------ sin terminar

    //cargar
    cargar_clientes(&c, &usu);
    cargar_productos(&pr);
    cargar_categorias(&ca);
    cargar_transportista(&tr);
    cargar_adminprov(&ap);
    cargar_descliente(&des);
    cargar_descuentos(&des);
    cargar_lockers(&lo);
    cargar_compartimentolockers(&cl);
    cargar_pedidos(&pe);
    cargar_prod_pedidos(&ppe);
    cargar_devoluciones(&dev);

    //fin cargar ----------------------------- sin terminar
    presentacion();
//inicio de sesion
    iniciar_sesion(&c, &ap, &tr, &usu);
    while( fin == 0 )//bucle para interfaz
    {
        fin = interfaz(&c, &ap, &tr, &usu, &ca, &pr, &dev, &des, &desc, &pe, &ppe, &lo, &cl);
    }
    return 0;
}
