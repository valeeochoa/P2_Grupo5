#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#define EXITO 1
#define FRACASO 0
#define fail 2



typedef struct {
    char patente[8];
    char marcaYmodelo[61];
    int anioFabr;
    char nombre[51];
    char telefono[16];
    char servicioMec[71];
    float importeServ;
    char fecha[11];

}Vehiculo;


void imprimirVehiculo (Vehiculo vehiculo)
{
    printf("\t%cPatente: %s\n",186,vehiculo.patente);
    printf("\t%cMarca y Modelo: %s\n",186,vehiculo.marcaYmodelo);
    printf("\t%cAnio de fabricacion: %d\n",186,vehiculo.anioFabr);
    printf("\t%cNombre y Apellido: %s\n",186,vehiculo.nombre);
    printf("\t%cTelefono: %s\n",186,vehiculo.telefono);
    printf("\t%cServicio Mecanico: %s\n",186,vehiculo.servicioMec);
    printf("\t%cImporte del Servicio: %f\n",186,vehiculo.importeServ);
    printf("\t%cFecha de fabricacion: %s\n",186,vehiculo.fecha);
    printf("\n");

}

typedef struct{
    float alta_max;         //COSTO MÁX
    float c_ac_alta;          //COSTO ACUMULADO
    float alta_med;         //COSTO MEDIO
    int cant_alta;          //CANTIDAD

    float baja_max;
    float c_ac_baja;
    float baja_med;
    int cant_baja;

    float evo_max;
    float c_ac_evo;
    float evo_med;
    int cant_evo;

    float evo_no_max;
    float c_ac_no_evo;
    float evo_no_med;
    int cant_no_evo;
} costos;

typedef struct {
    costos abb;
    costos libb;
    costos lsobt;
}Tabla;

void reiniciar_struct (Tabla *tabla){
    /// ABB
    tabla->abb.alta_max = 0.0;
    tabla->abb.alta_med = 0.0;
    tabla->abb.c_ac_alta = 0.0;
    tabla->abb.cant_alta = 0;

    tabla->abb.baja_max = 0.0;
    tabla->abb.baja_med = 0.0;
    tabla->abb.c_ac_baja = 0.0;
    tabla->abb.cant_baja = 0;

    tabla->abb.evo_max = 0.0;
    tabla->abb.evo_med = 0.0;
    tabla->abb.c_ac_evo= 0.0;
    tabla->abb.cant_evo = 0;

    tabla->abb.evo_no_max = 0.0;
    tabla->abb.evo_no_med = 0.0;
    tabla->abb.c_ac_no_evo = 0.0;
    tabla->abb.cant_no_evo = 0;

    ///LIBB

    tabla->libb.alta_max = 0.0;
    tabla->libb.alta_med = 0.0;
    tabla->libb.c_ac_alta = 0.0;
    tabla->libb.cant_alta = 0;

    tabla->libb.baja_max = 0.0;
    tabla->libb.baja_med = 0.0;
    tabla->libb.c_ac_baja = 0.0;
    tabla->libb.cant_baja = 0;

    tabla->libb.evo_max = 0.0;
    tabla->libb.evo_med = 0.0;
    tabla->libb.c_ac_evo= 0.0;
    tabla->libb.cant_evo = 0;

    tabla->libb.evo_no_max = 0.0;
    tabla->libb.evo_no_med = 0.0;
    tabla->libb.c_ac_no_evo = 0.0;
    tabla->libb.cant_no_evo = 0;

    ///LSOBT

    tabla->lsobt.alta_max = 0.0;
    tabla->lsobt.alta_med = 0.0;
    tabla->lsobt.c_ac_alta = 0.0;
    tabla->lsobt.cant_alta = 0;

    tabla->lsobt.baja_max = 0.0;
    tabla->lsobt.baja_med = 0.0;
    tabla->lsobt.c_ac_baja = 0.0;
    tabla->lsobt.cant_baja = 0;

    tabla->lsobt.evo_max = 0.0;
    tabla->lsobt.evo_med = 0.0;
    tabla->lsobt.c_ac_evo= 0.0;
    tabla->lsobt.cant_evo = 0;

    tabla->lsobt.evo_no_max = 0.0;
    tabla->lsobt.evo_no_med = 0.0;
    tabla->lsobt.c_ac_no_evo = 0.0;
    tabla->lsobt.cant_no_evo = 0;

}
int compararVehiculos (Vehiculo vehiculo1, Vehiculo vehiculo2)
{
    if( ((strcmp(vehiculo1.patente,vehiculo2.patente) == 0)) &&
        ((strcmp(vehiculo1.marcaYmodelo,vehiculo2.marcaYmodelo) == 0)) &&
        ((vehiculo1.anioFabr == vehiculo2.anioFabr)) &&
        ((strcmp(vehiculo1.nombre,vehiculo2.nombre) == 0)) &&
        ((strcmp(vehiculo1.telefono,vehiculo2.telefono) == 0)) &&
        ((strcmp(vehiculo1.servicioMec,vehiculo2.servicioMec) == 0))&&
        ((vehiculo1.importeServ == vehiculo2.importeServ)) &&
        ((strcmp(vehiculo1.servicioMec,vehiculo2.servicioMec) == 0)) ){

        return EXITO;
    }else
        return FRACASO;
}
#endif // VEHICULO_H_INCLUDED
