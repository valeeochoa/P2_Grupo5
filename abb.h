#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "vehiculo.h"

//estructura arbol

typedef struct n{
    Vehiculo info;
    struct n *hd;
    struct n *hi;
} Nodo;

typedef struct Nodo{

       Nodo* raiz;
       Nodo* cursor;
       Nodo* anterior;
}abb;

void inicializarABB(Nodo* auxiliar) //es recursivo
{
        if ( auxiliar != NULL ){

            if (auxiliar->hi!=NULL){
                inicializarABB(auxiliar->hi);
            }
            if(auxiliar->hd!=NULL){
                inicializarABB(auxiliar->hd);
            }
            free(auxiliar);
        }
        //fin if auxiliar
}

int localizacionABB(abb* arbol, char patente [], float *costosL){
/// al pasar la raiz como * se queda actualizado las ult posiciones del cursor y anterior, y no es necesario pasarlas por parametros
    float costosAux = 0.0;
    (*arbol).cursor = arbol->raiz;
    (*arbol).anterior = arbol->raiz;

    while((arbol->cursor != NULL) && (strcmpi(arbol->cursor->info.patente, patente) != 0)) {

        if(strcmpi(arbol->cursor->info.patente, patente)>0 ){
            //lo que tiene cursor es mas grande de lo q busco
            (*arbol).anterior = arbol->cursor;
            (*arbol).cursor = arbol->cursor->hi;
        }  else {
            //lo que tiene cursor es mas chico de lo q busco
            (*arbol).anterior = arbol->cursor;
            (*arbol).cursor = arbol->cursor->hd;
        }
        costosAux += 1.0; //consulta del while

    }

    if(arbol->cursor != NULL){
            costosAux += 1.0; //sale del while porque lo encontro por la tanto se suma un costo de celda consultada mas
            (*costosL) = costosAux; //paso por parametro el costo
        return EXITO;
    } else {
        (*costosL) = costosAux; //paso por parametro
        return FRACASO;
    }

}

int altaABB(abb *arbol, Vehiculo nuevo, float *costosA){
    float costosAux = 0.0, costos = 0.0;
 Nodo *auxiliar = (Nodo*)malloc(sizeof(Nodo));
    if (auxiliar == NULL) return fail; //no hay espacio

        else {
        if(localizacionABB(arbol, nuevo.patente, &costos) == FRACASO){
            auxiliar->info = nuevo;
            auxiliar->hd = NULL;
            auxiliar->hi = NULL;
                costosAux = 2.0; // dos modificaciones de punteros a null a sus hijos
            if(arbol->raiz == NULL){ //esta vacio
                arbol->raiz = auxiliar;
                costosAux +=1.0; //modificacion de puntero de la raiz
                (*costosA) = costosAux;
                return EXITO;
            }
            else if(strcmpi(arbol->anterior->info.patente, auxiliar->info.patente) > 0 ){
                    //si lo que tengo en anterior es mas grande de lo q busco
                arbol->anterior->hi = auxiliar;
            } else {
                arbol->anterior->hd = auxiliar;
            }
                costosAux += 1.0; //modificacion de un solo lado del hijo o izquierdo o derecho
                (*costosA)=costosAux; //paso por parametros el nuevo valor
                return EXITO;
        } else{
            //lo encontro en la localizacion
            free(auxiliar);
            return FRACASO;
        }
    }

}

void recorrido_abb_preordenABB(Nodo* auxiliar, int contador, int *resp) //es recursivo
{
    if (((contador+1) % 10) == 0 && *resp!=2)
    {
            printf("\n\n\tDesea continuar imprimiendo? \n");
            printf("\n\n\n\t< 1 > SI        < 2 > NO");
            printf("\n\n\tOPCION: ");
            scanf("%d", &(*resp));
        while (*resp <1 || *resp >2)
        {
            printf( "\n\n\t\t\t\t    ________________________\n"
                    "\t\t\t\t   |                        |\n"
                    "\t\t\t\t   |   Ingreso incorrecto   |\n"
                    "\t\t\t\t   |   Intente nuevamente   |\n"
                    "\t\t\t\t   |________________________|\n");
            printf("\n\n\tDesea continuar imprimiendo? \n");
            printf("\n\n\n\t< 1 > SI        < 2 > NO");
            printf("\n\n\tOPCION: ");
            scanf("%d", &(*resp));
        }
    }
    if  ( (*resp) != 2 ){
        if ( auxiliar != NULL )
        {
            printf("\n\t-------------------- \n");
            imprimirVehiculo(auxiliar->info);
            printf("\n\tHijo izquierdo: ");
            if((auxiliar->hi) != NULL)
            {
              printf("%s\n", auxiliar->hi->info.patente);
            }
            else printf("No tiene");

            printf("\n\tHijo Derecho: ");

            if((auxiliar->hd)!=NULL)
            {
               printf("%s\n",auxiliar->hd->info.patente);

            }
            else printf("No tiene");


            if (auxiliar->hi!=NULL )
            {
                recorrido_abb_preordenABB(auxiliar->hi, contador+1, resp);
            }
            if(auxiliar->hd!=NULL)
            {
                recorrido_abb_preordenABB(auxiliar->hd, contador+1, resp);
            }
        }//fin if aux
        else
            printf("\n\tNo se ha ingresado ningun vendedor..");
    }
}

int bajaABB(Vehiculo vehi, abb* arbol, float *costosB, int tipo){
    int resp;
    float costosAux =0.0, costos = 0.0;
    if(localizacionABB(arbol, vehi.patente, &costos) == EXITO){ ///Lo encontro y puede dar el de baja
        if(tipo == 1 ){//administrar estructura
         ///Confirmacion de la baja
            printf("\n\n\tSe encontro el Vendedor:\n");
                 imprimirVehiculo(arbol->cursor->info);
            printf("\n\n\n\t¿Desea eliminarlo?");
            printf("\n\n\n\t< 1 > SI        < 2 > NO");
            printf("\n\n\tOPCION: ");
            scanf("%d", &resp);

            while (resp <1 || resp >2){

                printf( "\n\n\t\t\t\t    ________________________\n"
                        "\t\t\t\t   |                        |\n"
                        "\t\t\t\t   |   Ingreso incorrecto   |\n"
                        "\t\t\t\t   |   Intente nuevamente   |\n"
                        "\t\t\t\t   |________________________|\n");
                printf("\n\n\n\t¿Desea eliminarlo?");
                printf("\n\n\n\t1- SI         2- NO");
                printf("\n\n\tOPCION: ");
                scanf("%d", &resp);

            } //fin del control
        }
        else {
            resp = compararVehiculos(arbol->cursor->info, vehi);
        }
        if (resp == 1){
        ///caso 1 sin hijos
        if ((arbol->cursor->hi == NULL) && (arbol->cursor->hd == NULL)){
            if (arbol->cursor == arbol->raiz){ ///si lo quiere eliminar la raiz
                free((void*)arbol->raiz);
                arbol->raiz = NULL;

            }else if(strcmpi(arbol->cursor->info.patente, arbol->anterior->info.patente)>0){
                arbol->anterior->hd = NULL ;
                free((void*)arbol->cursor);
                }
                else{
                    arbol->anterior->hi = NULL ;
                    free((void*)arbol->cursor);
                }
            //se modifica un solo puntero en ambos casos del if
            costosAux += 1.0;
        } //fin caso 1

        ///2do caso- 1 solo hijo
        else if ((arbol->cursor->hi == NULL) && (arbol->cursor->hd != NULL) ){
            if(arbol->cursor == arbol->raiz){ /// si quiere eliminar la raiz
                arbol->raiz = arbol->cursor->hd;
                free(arbol->cursor);
            }
            else if(strcmpi(arbol->cursor->info.patente, arbol->anterior->info.patente)>0){
                arbol->anterior->hd = arbol->cursor->hd; ///Asigno el hijo derecho del cursor al hijo derecho del anterior
                free(arbol->cursor);
                }
            else {  ///sino el cursor se encuentra a la izquierda del anterior
                arbol->anterior->hi = arbol->cursor->hd; ///asigno el hijo derecho del cursor al hijo izquierdo del anterior
                free(arbol->cursor);
                }
            //en este caso tambien hay una sola modificacion de punteros
            costosAux += 1.0;
        }

        ///3er caso
        else if ((arbol->cursor->hi!= NULL) && (arbol->cursor->hd == NULL)) { //igual al anterior solo que el cursor tiene hijo en el izquierdo
            if(arbol->cursor == arbol->raiz){
                arbol->raiz = arbol->cursor->hi;
                free(arbol->cursor);
            } else if(strcmpi(arbol->cursor->info.patente, arbol->anterior->info.patente)>0){
                arbol->anterior->hd = arbol->cursor->hi;
                free(arbol->cursor);
            }
            else {
                    arbol->anterior->hi = arbol->cursor->hi;
                    free(arbol->cursor);
                }
        //en ambos casos solo se modifica un puntero
            costosAux += 1.0;
        }

        ///4to caso con dos hijos
        else if ((arbol->cursor->hi != NULL) && (arbol->cursor->hd != NULL)){
            ///metodo de reemplazo el menor de los mayores
            Nodo* aux = arbol->cursor;
            Nodo* aux_ant = aux;
            aux = aux->hd;
            while (aux->hi !=NULL){
                //recorre hasta encontrar el menor de los mayores
                aux_ant = aux;
                aux = aux->hi;
            }
            //asigna los hijos
            if (aux_ant != arbol->cursor)
                aux_ant->hi = aux->hd;
            else
                aux_ant->hd = aux->hd;

            if (arbol->cursor == arbol->raiz){
                arbol->raiz->info = aux->info; //reemplazo
            }
            else {
                    arbol->cursor->info = aux->info;
            }
                //politica de reemplazo cuesta 1.5 -> entonces
                costosAux += 2.5;
                //como se utiliza auxiliares no hay corrimientos extras
            free(aux);
            aux = NULL;
        }
        (*costosB) = costosAux; //Actualizacion por parametro
        return EXITO;
        } else if(resp == 2) return fail; //se encontro y no se elimino
    } else return FRACASO; //no lo encontro
}

int evocacionABB(abb* arbol,char patente[], Vehiculo *vehiculo, float* costos){
    float costosAux=0.0;
    if(localizacionABB(arbol, patente, &costosAux) == EXITO){
        strcpy(vehiculo->patente,arbol->cursor->info.patente);
        strcpy(vehiculo->marcaYmodelo,arbol->cursor->info.marcaYmodelo);
        vehiculo->anioFabr = arbol->cursor->info.anioFabr;
        strcpy(vehiculo->nombre,arbol->cursor->info.nombre);
        strcpy(vehiculo->telefono,arbol->cursor->info.telefono);
        strcpy(vehiculo->servicioMec,arbol->cursor->info.servicioMec);
        vehiculo->importeServ = arbol->cursor->info.importeServ;
        strcpy(vehiculo->fecha,arbol->cursor->info.fecha);

         (*costos) = costosAux;
         return EXITO;
    } else {
        (*costos)=costosAux;
        return FRACASO;
        }
}

int perteneceABB(Vehiculo vehiculo, abb* arbol){
    int i=0;
    float celdas_consultadas = 0.0;
    i = localizacionABB(arbol, vehiculo.patente, &celdas_consultadas);
    if ( (i == EXITO) ){
        if( ((strcmpi(vehiculo.patente,arbol->cursor->info.patente) == 0)) &&
            ((strcmpi(vehiculo.marcaYmodelo,arbol->cursor->info.marcaYmodelo) == 0)) &&
            ((vehiculo.anioFabr == arbol->cursor->info.anioFabr)) &&
            ((strcmpi(vehiculo.nombre,arbol->cursor->info.nombre) == 0)) &&
            ((strcmpi(vehiculo.telefono,arbol->cursor->info.telefono) == 0)) &&
            ((strcmpi(vehiculo.servicioMec,arbol->cursor->info.servicioMec) == 0))&&
            ((vehiculo.importeServ == arbol->cursor->info.importeServ)) &&
            ((strcmpi(vehiculo.servicioMec,arbol->cursor->info.servicioMec) == 0)) ){

            return EXITO;
        }else
            return fail;
    }else
        return FRACASO;
}



#endif // ABB_H_INCLUDED
