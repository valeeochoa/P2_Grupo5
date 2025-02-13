#ifndef LSOBT_H_INCLUDED
#define LSOBT_H_INCLUDED
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "vehiculo.h"
#define MAXLSOBT 250

//TRISECCIÓN *** Limite Inferior y Superior INCLUSIVOS - Segmento más grande a izquierda

typedef struct{
    Vehiculo triseccion[250];
    int ultimo; //significa la pos, con la lista vacia vale -1

}listasobt;

void inicializarLSOBT(listasobt *lsobt){
    lsobt->ultimo = -1;
}

int localizarLSOBT(listasobt lsobt, char patente[], int *pos, float* celdas_consultadas){
    float costosAux = 0.0;
    int li, ls, m;
    li = 0; ls = lsobt.ultimo;
    m = ceil((li + ls)/2);

    if(lsobt.ultimo == -1){
        *pos = 0;
        return FRACASO;
    }

    while( (li <= ls) && (strcmpi(lsobt.triseccion[m].patente,patente)!=0) ){
        costosAux++;
        if( strcmpi(lsobt.triseccion[m].patente,patente) < 0 ) {
            li = m+1;
        }
        else ls = m-1;
        m = ceil((li + ls)/2.0);
    }

    if(li<=ls){
        costosAux++;//consulta del while, en el caso de que lo encontro
        *pos = m;
        (*celdas_consultadas) = costosAux;
        return EXITO;
    }else{
        *pos = ls+1;
        (*celdas_consultadas) = costosAux;
        return FRACASO;
    }
}

int evocarLSOBT(listasobt lsobt, char patente[], Vehiculo *vehiculo, float* costogral){
    int i, pos;
    float costosAux = 0.0;
    i = localizarLSOBT(lsobt,patente,&pos,&costosAux);
    if ( i == FRACASO){
        (*costogral) = costosAux;
        return FRACASO;
    }else{
        strcpy(vehiculo->patente,lsobt.triseccion[pos].patente);
        strcpy(vehiculo->marcaYmodelo,lsobt.triseccion[pos].marcaYmodelo);
        vehiculo->anioFabr = lsobt.triseccion[pos].anioFabr;
        strcpy(vehiculo->nombre,lsobt.triseccion[pos].nombre);
        strcpy(vehiculo->telefono,lsobt.triseccion[pos].telefono);
        strcpy(vehiculo->servicioMec,lsobt.triseccion[pos].servicioMec);
        vehiculo->importeServ = lsobt.triseccion[pos].importeServ;
        strcpy(vehiculo->fecha,lsobt.triseccion[pos].fecha);
        (*costogral) = costosAux;
        return EXITO;
    }
}

int perteneceLSOBT(Vehiculo vehiculo, listasobt lsobt){
    int pos, i=0;
    float celdas_consultadas=0.0;
    i = localizarLSOBT(lsobt,vehiculo.patente,&pos,&celdas_consultadas);
    if ( (i = 1) ){
        if( ((strcmpi(vehiculo.patente,lsobt.triseccion[pos].patente) == 0)) &&
            ((strcmpi(vehiculo.marcaYmodelo,lsobt.triseccion[pos].marcaYmodelo) == 0)) &&
            ((vehiculo.anioFabr == lsobt.triseccion[pos].anioFabr)) &&
            ((strcmpi(vehiculo.nombre,lsobt.triseccion[pos].nombre) == 0)) &&
            ((strcmpi(vehiculo.telefono,lsobt.triseccion[pos].telefono) == 0)) &&
            ((strcmpi(vehiculo.servicioMec,lsobt.triseccion[pos].servicioMec) == 0))&&
            ((vehiculo.importeServ == lsobt.triseccion[pos].importeServ)) &&
            ((strcmpi(vehiculo.servicioMec,lsobt.triseccion[pos].servicioMec) == 0)) )

            return EXITO;
        else
            return fail;
    }else
        return FRACASO;
}

int altaLSOBT(listasobt *lsobt, Vehiculo v, float *costoA){
    int pos, posaux;
    float celdas_consultadas=0;
    float costoAux = 0.0;
    posaux = lsobt->ultimo;
    if(localizarLSOBT(*lsobt,v.patente,&pos,&celdas_consultadas) == EXITO ){
        return FRACASO;
    }else{
        if (lsobt->ultimo < MAXLSOBT-1){
            while( posaux >= pos ){   //MODIFICACION DE LA ESTRUCTURA PARA REFLEJAR EL ALTA DEL VENDEDOR
                lsobt->triseccion[posaux+1] = lsobt->triseccion[posaux];
                costoAux += 1.5 ;
                posaux--;
            }

            (*costoA)=costoAux;
            lsobt->triseccion[pos] = v;   //PARA NO PERDER EL ULTIMO ELEMENTO
            lsobt->ultimo++;    //ACTUALIZACION DEL ULTIMO
            return EXITO;
        }else{
            return fail;
        }
    }
}

int bajaLSOBT(listasobt *lsobt, Vehiculo v, float* costoB, int tipo){
    int pos, confirm;
    float celdas_consultadas=0;
    float costoAux = 0.0;
    if(localizarLSOBT(*lsobt,v.patente,&pos,&celdas_consultadas) == 0){  //LOCALIZACION PARA VER SI EXISTE UN VEHICULO CON ESA PATENTE
        return FRACASO;
    } else{
        if (tipo==1){
            imprimirVehiculo(lsobt->triseccion[pos]);
            do{
                printf("\nDESEA ELIMINAR AL VEHICULO DE LA PATENTE %s?\n",lsobt->triseccion[pos].patente);     //CONFIRMACION DE BAJADA POR EL USUARIO
                printf("1) SI     2) NO\n");
                printf("Opcion: ");
                fflush(stdin);
                scanf("%d",&confirm);
                if((confirm != 1)&&(confirm != 2)){
                    printf("<<<Accion invalida, ingrese 1 o 2>>>\n\n");
                }
            }while((confirm != 1)&&(confirm != 2));
        }else{
            confirm = compararVehiculos(v,lsobt->triseccion[pos]);
        }

        if(confirm == 1){
            while( pos < lsobt->ultimo ){   //MODIFICACION DE LA ESTRUCTURA PARA REFLEJAR LA BAJA DEL VENDEDOR
                lsobt->triseccion[pos] = lsobt->triseccion[pos+1];
                costoAux += 1.5;
                pos++;
            }
            (*costoB) = costoAux;
            lsobt->ultimo--;    //ACTUALIZACION DEL ULTIMO
            return EXITO;
        }else{
            return fail;
        }
    }
}

void mostrar_listaLSOBT(listasobt lsobt){
    int i,c=0,resp=1;
    for (i=0; i<=lsobt.ultimo; i++){
        printf("\nPOSICION: %d\n",i);
        imprimirVehiculo(lsobt.triseccion[i]);
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

#endif // LSOBT_H_INCLUDED
