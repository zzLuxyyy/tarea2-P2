#include "../include/fecha.h"

struct rep_fecha {
    nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    delete fecha;
    fecha = NULL;
}

void imprimirTFecha(TFecha fecha) {
    
    printf("%u/%u/%u\n", fecha->dia, fecha->mes, fecha->anio);
}

TFecha copiarTFecha(TFecha fecha) {
    if (fecha == NULL)
        return NULL; // por si no me llegan a pasar ninguna fecha
    else
        return crearTFecha(fecha->dia, fecha->mes, fecha->anio);
}

void aumentarTFecha(TFecha &fecha, nat dias) {
}

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    return res;
}
