#include "../include/fecha.h"

struct rep_fecha
{
    nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = NULL;
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    delete fecha;
    fecha = NULL;
}

void imprimirTFecha(TFecha fecha)
{

    printf("%u/%u/%u\n", fecha->dia, fecha->mes, fecha->anio);
}

TFecha copiarTFecha(TFecha fecha)
{
    if (fecha == NULL)
        return NULL; // por si no me llegan a pasar ninguna fecha
    else
        return crearTFecha(fecha->dia, fecha->mes, fecha->anio);
}

// Funciones auxiliares que voy a crear para aumentar Tfecha
bool esBisiesto(nat anio)
{
    if ((anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0))
        return true; // si es multiplo de 4 y no de 100, o de 400 es bisiesto

    return false;
}
static nat diasMes(nat mes, nat anio)
{
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return esBisiesto(anio) ? 29 : 28;

    default:
        return 31;
    }
}

void aumentarTFecha(TFecha &fecha, nat dias)
{
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio))
    { // cambio en aumentar, para que sea mas eficiente en numeros grandes
        nat diasDelMes = diasMes(fecha->mes, fecha->anio);
        fecha->dia -= diasDelMes;
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;
    return res;
}
