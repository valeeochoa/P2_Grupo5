//************************************GRUPO 5***********************************************
//INTEGRANTES: Valentina Ochoa y Vanina Muñoz
/**
    Conclusión: A la hora de realizar la respectiva comparación entre las listas presentadas, abb, libb y lsobt
    podemos observar que los arboles son mucho más óptimos en sus costos de altas y bajas con respecto a las
    otras estructuras, pero en cambio al observar el evocar es mas costoso a comparacion de las listas.
    Si lo que buscamos es realizar multiples consultas en nuestro sistema nos conviene implementar la lsobt ya que
    su tipo de busqueda, binaria con triseccion, es mucho menos costosa que las anteriores.
    La lista invertida si bien al usar nodos los costos son menores, en las altas y bajas, considerablemente
    con respecto de la lsobt, pero aun asi no llega a ser tan optimo como con los arboles.

    Resultados de la comparacion:
                 ___________________________________________________________
                |                      |           |           |            |
                |                      |   ABB     |   LIBB    |   LSOBT    |
                |______________________|___________|___________|____________|
                | Alta                 |           |           |            |
                |    Costo Maximo      |  3.00     |   42.00   |   63.00    |
                |    Costo Promedio    |  3.00     |   5.04    |   7.56     |
                |______________________|___________|___________|____________|
                | Baja                 |           |           |            |
                |    Costo Maximo      |  2.50     |   40.00   |   60.00    |
                |    Costo Promedio    |  1.52     |   17.93   |   26.90    |
                |______________________|___________|___________|____________|
                | Evocar exitoso       |           |           |            |
                |    Costo Maximo      |  14.00    |   14.00   |   6.00     |
                |    Costo Promedio    |  6.96     |   11.49   |   4.86     |
                |______________________|___________|___________|____________|
                | Evocar fracaso       |           |           |            |
                |    Costo Maximo      |  9.00     |   14.00   |   6.00     |
                |    Costo Promedio    |  6.00     |   11.08   |   5.58     |
                |______________________|___________|___________|____________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
///LISTAS
#include "abb.h"
#include "li.h"
#include "lsobt.h"

void limpiar_estructuras(Tabla *tabla, listalibb *li, listasobt *lsobt, abb *arbol){

    reiniciar_struct(tabla);

    inicializarABB(arbol->raiz);
    arbol->raiz = NULL;

    inicializarLIBB(li);
    inicializarLSOBT(lsobt);
}

int main(){

    Vehiculo v, auxV;
    Tabla tabla;

    //declaracion de listas
    listalibb libb;
    libb.ultimo=-1;
    inicializarLIBB(&libb);

    listasobt lsobt;
    inicializarLSOBT(&lsobt);

    abb arbol;
    arbol.raiz=NULL;

    inicializarABB(arbol.raiz);

    ///inicializaciones
    limpiar_estructuras(&tabla,&libb,&lsobt,&arbol);

    //variables
    int op = 0, op_menu = 0, op_menu2 = 0, exito, resp=1, contador=0;
    float vacio=0.0;
    do{
        system("cls");
        printf("\n\n");
        printf("\n\t\t\t\t\t  Sistema de servicios 'El Bolido'  \n\n" //poner nombre del sistema
               "\t      _________________________________________________________________________________________________\n"

               "\n\t\t   < 1 > Administrar estructura \t  < 2 > Comparar estructura \t  < 3 > Salir\n"
               "\n\t\t      OPCION: ");
        scanf("%d", &op_menu);
        getchar();

        while (op_menu<1 || op_menu>3){
            printf( "\n\n\t\t\t\t    ________________________\n"
                    "\t\t\t\t   |                        |\n"
                    "\t\t\t\t   |   Ingreso incorrecto   |\n"
                    "\t\t\t\t   |   Intente nuevamente   |\n"
                    "\t\t\t\t   |________________________|\n");
            Sleep(1800);
            system("cls");
            printf("\n\t\t\t\t\t  Sistema de servicios 'El Bolido'  \n\n" // poner nombre del servicio
               "\t      _________________________________________________________________________________________________\n"

               "\n\t\t   < 1 > Administrar estructura \t  < 2 > Comparar estructura \t  < 3 > Salir\n"
               "\n\t\t      OPCION: ");
            scanf("%d", &op_menu);
            getchar();
        }

        switch(op_menu){
        case 1: //Administrar estructura

            do{
                printf("\n\n");
                system("pause");
                system("cls");
                printf("\n\t\t\t\t     \n\n"
                       "\t___________________________________________________________________________________\n\n"
                       /*menu opciones*/
                       "\t\t\tAdministrar estructura:  \n\n"
                       "\t\t\t< 1 > Arbol Binario de Busqueda \n\n"
                       "\t\t\t< 2 > Lista Invertida con Busqueda Binaria por Biseccion\n\n"
                       "\t\t\t< 3 > Lista Secuencial Ordenada con Busqueda Binaria por Triseccion \n\n"
                       "\t\t\t< 4 > Volver al menu principal \n\n"
                       "\t___________________________________________________________________________________\n");

                printf("\n\n\t\t\tOPCION: ");
                scanf("%d", &op);
                getchar();

                switch(op){
                    case 1: case 2: case 3:
                        do{
                            printf("\n\n");
                            system("pause");
                            system("cls");
                            printf("\n\t\t\t\t     \n\n"
                                   "\t___________________________________________________________________________________\n\n"
                                   /*menu opciones*/
                                   "\t\t\t< 1 > Ingreso de nuevos vehiculos \n\n"
                                   "\t\t\t< 2 > Eliminar vehiculos existentes\n\n"
                                   "\t\t\t< 3 > Determinar si a un vehiculo se le ha realizado servicio mecanico\n\n"
                                   "\t\t\t< 4 > Consultar informacion de un vehiculo \n\n"
                                   "\t\t\t< 5 > Mostrar vehiculos \n\n"
                                   "\t\t\t< 6 > Volver al menu anterior \n\n"
                                   "\t___________________________________________________________________________________\n");

                            printf("\n\n\t\t\tOPCION: ");
                            scanf("%d", &op_menu2);
                            getchar();

                            switch(op_menu2){
                            case 1: // INGRESO DE VEHICULOS***********************************************************
                            // ***************************************************************************************
                                system("cls");
                                printf("\n\n\t1. Ingresar Vehiculos..\n\n");
                                printf("PARA EL VEHICULO QUE DESEA CARGAR");     //PEDIDO DE DATOS

                                printf("\n*Ingrese la Patente: ");
                                fflush(stdin);
                                fgets(v.patente, 52, stdin);
                                v.patente[strlen(v.patente)-1] = '\0';

                                /*//pasandolo a mayuscula

                                for(i=0; v.patente[i] != '\0'; i++){
                                    v.patente[i]=toupper(v.patente[i]);
                                }*/

                                printf("*Ingrese la Marca y el Modelo (se tomaran hasta 60 caracteres): ");
                                fflush(stdin);
                                fgets(v.marcaYmodelo, 52, stdin);
                                v.marcaYmodelo[strlen(v.marcaYmodelo)-1] = '\0';

                                do{
                                    printf("*Ingrese el anio de fabricacion: ");
                                    fflush(stdin);
                                    scanf("%d",&v.anioFabr);
                                    if( (v.anioFabr > 2023)||(v.anioFabr < 1) ){
                                        printf("\nERROR: valor no admitido, vuelva a ingresar el anio\n");
                                    }
                                }while((v.anioFabr > 2023) || (v.anioFabr < 1));

                                printf("*Ingrese el Nombre y Apellido (se tomaran hasta 50 caracteres): ");
                                fflush(stdin);
                                fgets(v.nombre, 52, stdin);
                                v.nombre[strlen(v.nombre)-1] = '\0';

                                printf("Ingrese el Numero de Telefono (se tomaran hasta 15 caracteres): ");
                                fflush(stdin);
                                fgets(v.telefono,17,stdin);
                                v.telefono[strlen(v.telefono)-1] = '\0';

                                printf("*Ingrese el Servicio Mecanico (se tomaran hasta 70 caracteres): ");
                                fflush(stdin);
                                fgets(v.servicioMec, 52, stdin);
                                v.servicioMec[strlen(v.servicioMec)-1] = '\0';

                                do{
                                    printf("Ingrese el Importe del Servicio: ");
                                    fflush(stdin);
                                    scanf("%f",&v.importeServ);
                                    if( v.importeServ < 1 ){
                                        printf("ERROR: el importe del servicio no puede ser negativo o nulo\n");
                                    }
                                }while( v.importeServ < 1 );

                                printf("Ingrese la fecha en que se realizo el servicio (se tomaran hasta 10 caracteres): ");
                                fflush(stdin);
                                fgets(v.fecha,22,stdin);
                                v.fecha[strlen(v.fecha)-1] = '\0';

                                //************************REALIZAR ALTAS DE LAS NUEVAS LISTAS********************
                                switch( op ){
                                    case 1:
                                        switch(altaABB(&arbol,v, &vacio)){
                                            case 0: printf("\n<<<ERROR: EL VEHICULO YA ESTABA CARGADO EN LA ESTRUCTURA.>>>\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO.>>>\n");break;
                                            case 2:printf("\n<<<NO HAY MAS ESPACIO PARA NUEVOS VEHICULOS>>>\n");break;
                                        }
                                        break;
                                    case 2:
                                        switch(altaLIBB(&libb,v,&vacio)){
                                            case 0: printf("\n<<<ERROR: EL VEHICULO YA ESTABA CARGADO EN LA ESTRUCTURA.>>>\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO.>>>\n");break;
                                            case 2:printf("\n<<<NO HAY MAS ESPACIO PARA NUEVOS VEHICULOS>>>\n");break;
                                        }
                                        break;
                                    case 3:
                                        switch(altaLSOBT(&lsobt,v,&vacio)){
                                            case 0: printf("\n<<<ERROR: EL VEHICULO YA ESTABA CARGADO EN LA ESTRUCTURA.>>>\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO.>>>\n");break;
                                            case 2:printf("\n<<<NO HAY MAS ESPACIO PARA NUEVOS VEHICULOS>>>\n");break;
                                        }
                                        break;
                                    system("pause");
                                }
                                break;
                            case 2:// BAJA DE VEHICULOS*****************************************************************
                            // *****************************************************************************************
                                switch(op){
                                case 1:
                                    if (arbol.raiz == NULL){
                                        printf("NO ES POSIBLE ELIMINAR EL VEHICULO.\n");
                                        printf("<<<LA LISTA SE ENCUENTRA VACIA.>>>\n\n");
                                        break;
                                    }else{
                                        printf("\n*Ingrese la patente del vehiculo a eliminar: ");
                                        fflush(stdin);
                                        fgets(v.patente, 52, stdin);
                                        v.patente[strlen(v.patente)-1] = '\0';
                                        printf("\n");

                                        switch(bajaABB(v,&arbol,&vacio,1)){
                                            case 0: printf("<<<EL VEHICULO SOLICITADO A DAR DE BAJA NO EXISTE>>>\n\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO>>>\n\n");break;
                                            case 2:printf("\n<<<NO FUE POSIBLE REALIZAR LA BAJA DEL VENDEDOR>>>\n\n");break;
                                        }
                                    }
                                    break;
                                case 2:
                                    if (libb.ultimo == -1){
                                        printf("NO ES POSIBLE ELIMINAR EL VEHICULO.\n");
                                        printf("<<<LA LISTA SE ENCUENTRA VACIA.>>>\n\n");
                                        break;
                                    }else{
                                        printf("\n*Ingrese la patente del vehiculo a eliminar: ");
                                        fflush(stdin);
                                        fgets(v.patente, 52, stdin);
                                        v.patente[strlen(v.patente)-1] = '\0';
                                        printf("\n");
                                        switch(bajaLIBB(&libb,v,&vacio,1)){
                                            case 0: printf("<<<EL VEHICULO SOLICITADO A DAR DE BAJA NO EXISTE>>>\n\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO>>>\n\n");break;
                                            case 2:printf("\n<<<NO FUE POSIBLE REALIZAR LA BAJA DEL VENDEDOR>>>\n\n");break;
                                        }
                                    }
                                    break;
                                case 3:
                                    if (lsobt.ultimo == -1){
                                        printf("NO ES POSIBLE ELIMINAR EL VEHICULO.\n");
                                        printf("<<<LA LISTA SE ENCUENTRA VACIA.>>>\n\n");
                                        break;
                                    }else{
                                        printf("\n*Ingrese la patente del vehiculo a eliminar: ");
                                        fflush(stdin);
                                        fgets(v.patente, 52, stdin);
                                        v.patente[strlen(v.patente)-1] = '\0';
                                        printf("\n");
                                        switch(bajaLSOBT(&lsobt,v,&vacio,1)){
                                            case 0: printf("<<<EL VEHICULO SOLICITADO A DAR DE BAJA NO EXISTE>>>\n\n");break;
                                            case 1: printf("\n<<<OPERACION REALIZADA CON EXITO>>>\n\n");break;
                                            case 2:printf("\n<<<NO FUE POSIBLE REALIZAR LA BAJA DEL VENDEDOR>>>\n\n");break;
                                        }
                                    }
                                    break;
                                }
                                system("pause");
                                system("cls");
                                break;

                            case 3: //CONSULTAR SI A UN VEHICULO SE LE HIZO SERVICIO MECANICO ***************************************
                            // ******************************************************************************************************
                                printf("\n3.Determinar si a un vehiculo se le hizo servicio mecanico");
                                /**Pedido de datos*/
                                printf("\n\n*Ingrese la Patente: ");
                                fflush(stdin);
                                fgets(v.patente, 52, stdin);
                                v.patente[strlen(v.patente)-1] = '\0';


                                printf("*Ingrese la Marca y el Modelo (se tomaran hasta 60 caracteres): ");
                                fflush(stdin);
                                fgets(v.marcaYmodelo, 52, stdin);
                                v.marcaYmodelo[strlen(v.marcaYmodelo)-1] = '\0';

                                do{
                                    printf("*Ingrese el anio de fabricacion: ");
                                    fflush(stdin);
                                    scanf("%d",&v.anioFabr);
                                    if( (v.anioFabr > 2023)||(v.anioFabr < 1) ){
                                        printf("\nERROR: valor no admitido, vuelva a ingresar el anio\n");
                                    }
                                }while((v.anioFabr > 2023) || (v.anioFabr < 1));

                                printf("*Ingrese el Nombre y Apellido (se tomaran hasta 50 caracteres): ");
                                fflush(stdin);
                                fgets(v.nombre, 52, stdin);
                                v.nombre[strlen(v.nombre)-1] = '\0';

                                printf("Ingrese el Numero de Telefono (se tomaran hasta 15 caracteres): ");
                                fflush(stdin);
                                fgets(v.telefono,17,stdin);
                                v.telefono[strlen(v.telefono)-1] = '\0';

                                printf("*Ingrese el Servicio Mecanico (se tomaran hasta 70 caracteres): ");
                                fflush(stdin);
                                fgets(v.servicioMec, 52, stdin);
                                v.servicioMec[strlen(v.servicioMec)-1] = '\0';

                                do{
                                    printf("Ingrese el Importe del Servicio: ");
                                    fflush(stdin);
                                    scanf("%f",&v.importeServ);
                                    if( v.importeServ < 1 ){
                                        printf("ERROR: el importe del servicio no puede ser negativo o nulo\n");
                                    }
                                }while( v.importeServ < 1 );

                                printf("Ingrese la fecha en que se realizo el servicio (se tomaran hasta 10 caracteres): ");
                                fflush(stdin);
                                fgets(v.fecha,22,stdin);
                                v.fecha[strlen(v.fecha)-1] = '\0';

                                switch(op){
                                case 1:
                                    exito = perteneceABB(v, &arbol);
                                    switch(exito){
                                        case EXITO: printf("\nSE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n");break;
                                        case fail: printf("\nNO SE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n"); break;
                                        case FRACASO: printf("\nNO SE ENCONTRO EL VEHICULO EN EL SISTEMA\n");break;
                                    }

                                break;

                                case 2:
                                    exito=perteneceLIBB(v,libb);
                                    switch(exito){
                                        case EXITO: printf("\nSE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n");break;
                                        case fail: printf("\nNO SE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n"); break;
                                        case FRACASO: printf("\nNO SE ENCONTRO EL VEHICULO EN EL SISTEMA\n");break;
                                    }

                                break;

                                case 3:
                                    exito=perteneceLSOBT(v,lsobt);
                                    switch(exito){
                                        case EXITO: printf("\nSE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n");break;
                                        case fail: printf("\nNO SE LE REALIZO EL SERVICIO MECANICO PEDIDO AL VEHICULO\n"); break;
                                        case FRACASO: printf("\nNO SE ENCONTRO EL VEHICULO EN EL SISTEMA\n");break;
                                    }

                                break;

                                }
                                //system("pause");
                                //system("cls");
                            break;

                            case 4: //CONSULTAR INFORMACION DE UN VEHICULO **********************************************************
                            // ******************************************************************************************************
                                printf("\n4.Consultar la informacion de un vehiculo:");
                                printf("\n\n*Ingrese la Patente: ");
                                fflush(stdin);
                                fgets(v.patente, 52, stdin);
                                v.patente[strlen(v.patente)-1] = '\0';


                                switch(op){
                                    case 1: exito=evocacionABB(&arbol, v.patente, &auxV, &vacio); break;
                                    case 2: exito=evocarLIBB(libb, v.patente, &auxV, &vacio); break;
                                    case 3: exito=evocarLSOBT(lsobt, v.patente, &auxV, &vacio); break;
                                }

                                switch(exito){
                                    case EXITO:
                                        printf("\n\tSe encontro la patente del vehiculo: \n");
                                        imprimirVehiculo(auxV);
                                    break;

                                    case FRACASO:
                                        printf("\n\tNo se encontro informacion asociada a la patente %s\n ", v.patente);
                                    break;
                                }
                            break;

                            case 5: //MOSTRAR VEHICULOS *****************************************************************************
                            // ******************************************************************************************************
                                switch(op){
                                case 1:
                                        system("cls");
                                        printf("\n\n\n\t5. Mostrar estructura..\n\n");
                                        arbol.cursor=arbol.raiz;
                                        arbol.anterior=arbol.raiz;
                                        recorrido_abb_preordenABB((arbol.raiz), contador, &resp);
                                        system("pause");
                                        system("cls");

                                    break;
                                case 2:
                                    if (libb.ultimo == -1){
                                        printf("LA LISTA SE ENCUENTRA VACIA.\n\n");
                                        system("pause");
                                        system("cls");
                                    }else{
                                        system("cls");
                                        printf("\n\n\n\t5. Mostrar estructura..\n\n");
                                        mostrar_listaLIBB(libb);
                                    }
                                    break;
                                case 3:
                                    if (lsobt.ultimo == -1){
                                        printf("LA LISTA SE ENCUENTRA VACIA.\n\n");
                                        system("pause");
                                        system("cls");
                                    }else{
                                        system("cls");
                                        printf("\n\n\n\t5. Mostrar estructura..\n\n");
                                        mostrar_listaLSOBT(lsobt);
                                    }
                                    break;
                                }
                                break;
                            case 6: break;
                            default:printf("<<<Accion invalida, ingrese una opcion del 1 al 6>>>\n\n");break;
                            }

                        }while(op_menu2 != 6);

                        break;


                    case 4: break;
                    default:printf("<<<Accion invalida, ingrese una opcion del 1 al 5>>>\n\n");break;
                }

            }while (op != 4);

        break;
        case 2:{   ///COMPARAR ESTRUCTURAS

            limpiar_estructuras(&tabla,&libb,&lsobt,&arbol);
            int operaciones;
            operaciones = lecturaOperaciones(&tabla, &libb, &lsobt, &arbol);

                system("pause");
                system("cls");
                printf("\n\n\t\t\t  ___________________________________________________________\n"
                           "\t\t\t |                      |           |           |            |\n"
                           "\t\t\t |                      |   ABB     |   LIBB    |   LSOBT    |\n"
                           "\t\t\t |______________________|___________|___________|____________|\n"
                           "\t\t\t | Alta                 |           |           |            |\n"
                           "\t\t\t |    Costo Maximo      |  %.2f     |   %.2f   |   %.2f    |\n"
                           "\t\t\t |    Costo Promedio    |  %.2f     |   %.2f    |   %.2f     |\n"
                           "\t\t\t |______________________|___________|___________|____________|\n"
                           "\t\t\t | Baja                 |           |           |            |\n"
                           "\t\t\t |    Costo Maximo      |  %.2f     |   %.2f   |   %.2f    |\n"
                           "\t\t\t |    Costo Promedio    |  %.2f     |   %.2f   |   %.2f    |\n"
                           "\t\t\t |______________________|___________|___________|____________|\n"
                           "\t\t\t | Evocar exitoso       |           |           |            |\n"
                           "\t\t\t |    Costo Maximo      |  %.2f    |   %.2f   |   %.2f     |\n"
                           "\t\t\t |    Costo Promedio    |  %.2f     |   %.2f   |   %.2f     |\n"
                           "\t\t\t |______________________|___________|___________|____________|\n"
                           "\t\t\t | Evocar fracaso       |           |           |            |\n"
                           "\t\t\t |    Costo Maximo      |  %.2f     |   %.2f   |   %.2f     |\n"
                           "\t\t\t |    Costo Promedio    |  %.2f     |   %.2f   |   %.2f     |\n"
                           "\t\t\t |______________________|___________|___________|____________|\n\n\n",
                           tabla.abb.alta_max, tabla.libb.alta_max,tabla.lsobt.alta_max,
                            tabla.abb.alta_med, tabla.libb.alta_med, tabla.lsobt.alta_med,
                            tabla.abb.baja_max, tabla.libb.baja_max, tabla.lsobt.baja_max,
                            tabla.abb.baja_med, tabla.libb.baja_med, tabla.lsobt.baja_med,
                            tabla.abb.evo_max, tabla.libb.evo_max, tabla.lsobt.evo_max,
                            tabla.abb.evo_med,tabla.libb.evo_med, tabla.lsobt.evo_med,
                             tabla.abb.evo_no_max, tabla.libb.evo_no_max,tabla.lsobt.evo_no_max,
                             tabla.abb.evo_no_med, tabla.libb.evo_no_med,tabla.lsobt.evo_no_med);
                system("pause");

        }
        break; ///fin



        }///fin switch op menu

    }while (op_menu!=3);

    //system("pause");
    system("cls");
    printf("\n\t___________________________________________________________________________________\n"
           "\n\t\t\t\t   Gracias por utilizar el Sistema       "
           "\n\n\t\t\t\t          OCHOA-MUNOZ     "
           "\n\t___________________________________________________________________________________\n\n");

    return 0;
}

int lecturaOperaciones (Tabla *tabla, listalibb *libb, listasobt *lsobt, abb *arbol){

    //limpiar_estructuras(tabla, libb, lsobt, arbol);

    int operacion = 0, x = 0;
    float costoGeneral = 0.0;
    Vehiculo vehiculo;
    FILE* fp ;
    if ((fp = fopen ("Operaciones.txt","r")) == NULL){
        return FRACASO;
    }else{
        if(fgetc(fp) != EOF){
            rewind(fp);
            while (!(feof(fp) )){
                fscanf(fp, "%d",&operacion);
                if (operacion == 1 || operacion == 2){
                    fscanf(fp, " %[^\n]",vehiculo.patente);
                    /*//pasando a mayusculas
                    for(i=0; vehiculo.patente[i] != '\0'; i++){
                        vehiculo.patente[i]=toupper(vehiculo.patente[i]);
                    }*/
                    fscanf(fp, " %[^\n]",vehiculo.marcaYmodelo);
                    fscanf(fp,"%d",&vehiculo.anioFabr);
                    fscanf(fp, " %[^\n]",vehiculo.nombre);
                    fscanf(fp, " %[^\n]",vehiculo.telefono);
                    fscanf(fp, " %[^\n]",vehiculo.servicioMec);
                    fscanf(fp,"%f",&vehiculo.importeServ);
                    fscanf(fp, " %[^\n]",vehiculo.fecha);
                    fgetc(fp);
                }
                switch(operacion){
                case 1:{
                    costoGeneral = 0.0;
                    if ((altaABB(arbol, vehiculo ,&costoGeneral)) == EXITO){
                        tabla->abb.c_ac_alta = tabla->abb.c_ac_alta + costoGeneral;
                        tabla->abb.cant_alta++;
                        if (tabla->abb.alta_max < costoGeneral){
                            tabla->abb.alta_max = costoGeneral;
                        }
                    }
                    if (libb->ultimo < 250){
                        costoGeneral = 0.0;
                        if ((altaLIBB(libb, vehiculo, &costoGeneral)) == EXITO){
                            tabla->libb.c_ac_alta = tabla->libb.c_ac_alta + costoGeneral;
                            tabla->libb.cant_alta++;
                            if (tabla->libb.alta_max < costoGeneral){
                                tabla->libb.alta_max = costoGeneral;
                            }
                        }
                    }
                    if (lsobt->ultimo < 250){
                        costoGeneral = 0.0;
                        if ((altaLSOBT(lsobt, vehiculo, &costoGeneral)) == EXITO){
                            tabla->lsobt.c_ac_alta = tabla->lsobt.c_ac_alta + costoGeneral;
                            tabla->lsobt.cant_alta++;
                            if (tabla->lsobt.alta_max < costoGeneral){
                                tabla->lsobt.alta_max = costoGeneral;
                            }

                        }
                    }
                }
                break;
                case 2:{
                    if (arbol->raiz != NULL){
                        costoGeneral = 0.0;
                        if ((bajaABB(vehiculo,arbol, &costoGeneral, 2)) == EXITO){
                            tabla->abb.cant_baja++;
                            tabla->abb.c_ac_baja = tabla->abb.c_ac_baja + costoGeneral;
                            if (tabla->abb.baja_max < costoGeneral){
                                tabla->abb.baja_max = costoGeneral;
                            }
                        }
                    }
                    if (libb->ultimo != -1){
                        costoGeneral = 0.0;
                        if ((bajaLIBB(libb, vehiculo, &costoGeneral, 2)) == EXITO){
                            tabla->libb.cant_baja++;
                            tabla->libb.c_ac_baja = tabla->libb.c_ac_baja + costoGeneral;
                            if (tabla->libb.baja_max < costoGeneral){
                                tabla->libb.baja_max = costoGeneral;
                            }
                        }
                    }
                    if (lsobt->ultimo != -1){
                        costoGeneral = 0.0;
                        if ((bajaLSOBT(lsobt, vehiculo, &costoGeneral,2)) == EXITO){
                            tabla->lsobt.cant_baja++;
                            tabla->lsobt.c_ac_baja =tabla->lsobt.c_ac_baja + costoGeneral;
                            if (tabla->lsobt.baja_max < costoGeneral){
                                tabla->lsobt.baja_max = costoGeneral;
                            }
                        }
                    }
                }
                break;
                case 3:{
                    fscanf(fp," %[^\n]",vehiculo.patente);
                    /*//pasando a mayusculas
                    for(i=0; vehiculo.patente[i] != '\0'; i++){
                        vehiculo.patente[i]=toupper(vehiculo.patente[i]);
                    }*/
                    fgetc(fp);

                    if ((*arbol).raiz != NULL){
                        costoGeneral = 0;
                        x = evocacionABB(arbol, vehiculo.patente, &vehiculo, &costoGeneral);
                        if ( ((x) == (EXITO)) ){
                            tabla->abb.cant_evo++;
                            tabla->abb.c_ac_evo = tabla->abb.c_ac_evo + costoGeneral;
                            if (tabla->abb.evo_max < costoGeneral){
                                tabla->abb.evo_max = costoGeneral;
                            }
                        }else{
                            tabla->abb.cant_no_evo++;
                            tabla->abb.c_ac_no_evo = tabla->abb.c_ac_no_evo + costoGeneral;
                            if (tabla->abb.evo_no_max < costoGeneral){
                                tabla->abb.evo_no_max = costoGeneral;
                            }
                        }
                    }else{
                        tabla->abb.cant_no_evo++;
                    }
                    if (libb->ultimo != -1){
                        costoGeneral = 0;
                        x = evocarLIBB(*libb, vehiculo.patente, &vehiculo, &costoGeneral);
                        if ( ((x) == (EXITO)) ){
                            tabla->libb.cant_evo++;
                            tabla->libb.c_ac_evo = tabla->libb.c_ac_evo + costoGeneral;
                            if (tabla->libb.evo_max < costoGeneral){
                                tabla->libb.evo_max = costoGeneral;
                            }
                        }else{
                            tabla->libb.cant_no_evo++;
                            tabla->libb.c_ac_no_evo = tabla->libb.c_ac_no_evo + costoGeneral;
                            if (tabla->libb.evo_no_max < costoGeneral){
                                tabla->libb.evo_no_max = costoGeneral;
                            }
                        }
                    }else{
                        tabla->libb.cant_no_evo++;
                    }
                    if (lsobt->ultimo != -1){
                        costoGeneral = 0;
                        x = evocarLSOBT(*lsobt, vehiculo.patente, &vehiculo, &costoGeneral);
                        if (x == EXITO){
                            tabla->lsobt.cant_evo++;
                            tabla->lsobt.c_ac_evo = tabla->lsobt.c_ac_evo + costoGeneral;
                            if (tabla->lsobt.evo_max < costoGeneral){
                                tabla->lsobt.evo_max = costoGeneral;
                            }
                        }else{
                            tabla->lsobt.cant_no_evo++;
                            tabla->lsobt.c_ac_no_evo =tabla->lsobt.c_ac_no_evo + costoGeneral;
                            if (tabla->lsobt.evo_no_max < costoGeneral){
                                tabla->lsobt.evo_no_max = costoGeneral;
                            }
                        }
                    }else{
                        tabla->lsobt.cant_no_evo++;
                    }
                }
                break;
                default: return 0;
                }
            }

        }
        fclose(fp) ;
        //esfuerzo medio en altas

        /*printf("\ncantidad de altas: ");
        printf("\nLIBB = %d", tabla->libb.cant_alta);
        printf("\nABB = %d", tabla->abb.cant_alta);
        printf("\nLSOBT = %d", tabla->lsobt.cant_alta);

        printf("\ncantidad de bajas:");
        printf("\nLIBB = %d", tabla->libb.cant_baja);
        printf("\nABB = %d", tabla->abb.cant_baja);
        printf("\nLSOBT = %d", tabla->lsobt.cant_baja);

        printf("\ncantidad de evocar EXITOSO:");
        printf("\nLIBB = %d", tabla->libb.cant_evo);
        printf("\nABB = %d", tabla->abb.cant_evo);
        printf("\nLSOBT = %d", tabla->lsobt.cant_evo);

        printf("\ncantidad de evocar FRACASO:");
        printf("\nLIBB = %d", tabla->libb.cant_no_evo);
        printf("\nABB = %d", tabla->abb.cant_no_evo);
        printf("\nLSOBT = %d \n", tabla->lsobt.cant_no_evo);*/

        tabla->abb.alta_med = tabla->abb.c_ac_alta / tabla->abb.cant_alta;
        tabla->libb.alta_med = tabla->libb.c_ac_alta / tabla->libb.cant_alta;
        tabla->lsobt.alta_med = tabla->lsobt.c_ac_alta / tabla->lsobt.cant_alta;


        //Esfuerzo medio en bajas

        tabla->abb.baja_med = tabla->abb.c_ac_baja / tabla->abb.cant_baja;
        tabla->libb.baja_med = tabla->libb.c_ac_baja / tabla->libb.cant_baja;
        tabla->lsobt.baja_med = tabla->lsobt.c_ac_baja / tabla->lsobt.cant_baja;

        //Esfuerzo medio en evocaciones exito

        tabla->abb.evo_med = tabla->abb.c_ac_evo / tabla->abb.cant_evo;
        tabla->libb.evo_med = tabla->libb.c_ac_evo / tabla->libb.cant_evo;
        tabla->lsobt.evo_med = tabla->lsobt.c_ac_evo / tabla->lsobt.cant_evo;

        //Esfuerzo medio en evocaciones fracaso

        tabla->abb.evo_no_med = tabla->abb.c_ac_no_evo / tabla->abb.cant_no_evo;
        tabla->libb.evo_no_med = tabla->libb.c_ac_no_evo / tabla->libb.cant_no_evo;
        tabla->lsobt.evo_no_med = tabla->lsobt.c_ac_no_evo / tabla->lsobt.cant_no_evo;


        return EXITO;
    }
}
