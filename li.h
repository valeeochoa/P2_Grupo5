#ifndef LI_H_INCLUDED
#define LI_H_INCLUDED
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "vehiculo.h"
#define MAXLIBB 250

//BISECCION: Limite inferior inclusivo, limite superior exclusivo, segmento más grande a la derecha y testigo a izquierda.

typedef struct{
    Vehiculo info;
}nodo;

typedef struct {
    nodo* invertida[250];
    int ultimo;
}listalibb;

void inicializarLIBB(listalibb *libb){
    int i;
    for (i=0; i<=(libb->ultimo); i++){
        free(libb->invertida[i]);
    }
    libb->ultimo = -1;
}

int localizarLIBB(listalibb libb, char buscando[], int *pos, float *celdas_consultadas){
    int li, ls, m, i, costos[libb.ultimo+1];
    float costosAux = 0.0;
    li=0; ls=libb.ultimo+1;
    m=floor((li+ls-2)/2);

    if (libb.ultimo == -1){
        *pos = 0;
        return FRACASO;
    }

    for(i=0;i<=libb.ultimo;i++){
        costos[i] = 0;
    }

    while (li < ls-1){
        if( costos[m] == 0 ){
            costos[m] = 1;
            costosAux+=2.0;
        }
        if (strcmpi(libb.invertida[m]->info.patente,buscando) < 0){
            li=m+1;
        }else{
            ls=m+1;
        }
        m=floor((li+ls-2)/2);
    }

    if( costos[li] == 0 ){
        costos[m] = 1;
        costosAux+=2.0;
    }

    (*celdas_consultadas) = costosAux;

    if (strcmpi(libb.invertida[li]->info.patente,buscando) == 0){
        *pos = li;
        return EXITO;
    }else{
        if( strcmpi(libb.invertida[li]->info.patente,buscando) < 0)
            *pos = ls;
        else
            *pos = ls-1;
        return FRACASO;
    }

}

int evocarLIBB(listalibb libb, char patente[], Vehiculo *vehiculo, float* costogral){
    int i, pos;
    float costosAux = 0.0;
    i = localizarLIBB(libb,patente,&pos,&costosAux);
    if ( i == FRACASO){
        (*costogral) = costosAux;
        return FRACASO;
    }else{
        strcpy(vehiculo->patente,libb.invertida[pos]->info.patente);
        strcpy(vehiculo->marcaYmodelo,libb.invertida[pos]->info.marcaYmodelo);
        vehiculo->anioFabr = libb.invertida[pos]->info.anioFabr;
        strcpy(vehiculo->nombre,libb.invertida[pos]->info.nombre);
        strcpy(vehiculo->telefono,libb.invertida[pos]->info.telefono);
        strcpy(vehiculo->servicioMec,libb.invertida[pos]->info.servicioMec);
        vehiculo->importeServ = libb.invertida[pos]->info.importeServ;
        strcpy(vehiculo->fecha,libb.invertida[pos]->info.fecha);
        (*costogral) = costosAux;
        return EXITO;
    }
}

int perteneceLIBB(Vehiculo vehiculo, listalibb libb){
    int pos, i=0;
    float celdas_consultadas=0.0;
    i = localizarLIBB(libb,vehiculo.patente,&pos,&celdas_consultadas);
    if ( (i = 1) ){
        if( ((strcmpi(vehiculo.patente,libb.invertida[pos]->info.patente) == 0)) &&
            ((strcmpi(vehiculo.marcaYmodelo,libb.invertida[pos]->info.marcaYmodelo) == 0)) &&
            ((vehiculo.anioFabr == libb.invertida[pos]->info.anioFabr)) &&
            ((strcmpi(vehiculo.nombre,libb.invertida[pos]->info.nombre) == 0)) &&
            ((strcmpi(vehiculo.telefono,libb.invertida[pos]->info.telefono) == 0)) &&
            ((strcmpi(vehiculo.servicioMec,libb.invertida[pos]->info.servicioMec) == 0))&&
            ((vehiculo.importeServ == libb.invertida[pos]->info.importeServ)) &&
            ((strcmpi(vehiculo.servicioMec,libb.invertida[pos]->info.servicioMec) == 0)) )

            return EXITO;
        else
            return fail;
    }else
        return FRACASO;
}

int altaLIBB(listalibb *libb, Vehiculo v, float *costoA){
    int posaux = libb->ultimo, pos;
    float costoAux = 0.0, celdas_consultadas=0.0;

    if(libb->ultimo < MAXLIBB-1){ //TIENE LUGAR
        Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
        if(aux==NULL) return fail; //NO TIENE MEMORIA/LUGAR
        else {
            if(EXITO == localizarLIBB(*libb,v.patente,&pos,&celdas_consultadas)){
                free(aux);
                return FRACASO; //LO ENCONTRE, NO SE PUEDE DAR DE ALTA
            }else{
                while(posaux>=pos){
                    //CORRIMIENTOS DE DIRECCIONES
                    libb->invertida[posaux+1]=libb->invertida[posaux];
                    costoAux += 1.00; //solo se corre la direccion de los punteros
                    posaux--;
                }
                (*costoA)=costoAux;
                aux->info = v;
                libb->invertida[pos]=aux;
                libb->ultimo++;
                return EXITO; //NO LO ENCONTRO Y DIO DE ALTA
            }
        }
    }
    else return fail; //NO SE PUDO DAR DE ALTA, ARREGLO LLENO
}


int bajaLIBB(listalibb *libb, Vehiculo v, float *costoB, int tipo){ //op menu
    int confirm = 0, pos;
    float costoAux =0.0,celdas_consultadas=0.0;
    if (localizarLIBB(*libb, v.patente,&pos ,&celdas_consultadas) == FRACASO){
        return FRACASO; // NO LO ENCUENTRA -> NO SE DA DE BAJA
    }else{
        if(tipo == 1){ //entro en administracion
            /**CONFIRMACION DE LA BAJA**/
            printf("\n\tVEHICULO A ELIMINAR: \n");
            imprimirVehiculo(libb->invertida[pos]->info);
            printf("\n\n\n\t¿Desea eliminarlo?");
            printf("\n\n\n\t1- SI         2- NO");
            printf("\n\n\tOPCI0N: ");
            scanf("%d", &confirm);
            while (confirm<1 || confirm>2)
            {
                printf( "\n\n\t\t\t\t    ________________________\n"
                        "\t\t\t\t   |                        |\n"
                        "\t\t\t\t   |   Ingreso incorrecto   |\n"
                        "\t\t\t\t   |   Intente nuevamente   |\n"
                        "\t\t\t\t   |________________________|\n");
                printf("\n\n\n\t¿Desea eliminarlo?");
                printf("\n\n\n\t1- SI         2- NO");
                printf("\n\n\tOPCI0N: ");
                scanf("%d", &confirm);
            }
        }else { //comparacion estructura
            confirm=compararVehiculos(v,libb->invertida[pos]->info);
        }

        if(confirm == 1){
            free(libb->invertida[pos]);
            while( pos < libb->ultimo ){
                //MODIFICACION DE LA ESTRUCTURA PARA REFLEJAR LA BAJA DEL VEHICULO
                libb->invertida[pos] = libb->invertida[pos+1];
                costoAux += 1.00;//solo se corre la direccion de los punteros
                pos++;
            }
            (*costoB)=costoAux;
            libb->ultimo--;
            return EXITO; //se dio de baja
        }else {
            return fail; //"NO se dio de baja"
        }
    }
}

void mostrar_listaLIBB(listalibb libb){
    int i,c=0, resp=1;
    for (i=0; i<=libb.ultimo; i++){
        printf("\nPOSICION: %d\n",i);

        imprimirVehiculo(libb.invertida[i]->info);
        printf("\n");
        c++;
        if ((c%3)==0){
            printf("\n¿Desea continuar imprimiendo?");
            printf("\n\n\n\t< 1 > SI        < 2 > NO");
            printf("\n\n\tOPCION: ");
            scanf("%d", &resp);
            if (resp == 2) break;
        }
    }
}
#endif // LI_H_INCLUDED

