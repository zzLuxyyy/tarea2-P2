#include "../include/socio.h"
#include <string.h> //lo necesitamos si o si para usar strcpy
#include <stdio.h>

struct rep_socio
{
    int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    int generosfavoritos[MAX_GENEROS_FAVORITOS];
    int topegenerosfavoritos;
};

TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta)
{
    TSocio nuevoSocio = new rep_socio; // Faltaba agregar new

    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    nuevoSocio->topegenerosfavoritos = 0;

    return nuevoSocio; // Estabas retornando rep_socio lo cual es incorrecto porque es un struct.
}

// Función que imprime la información del socio en el siguiente formato
void imprimirTSocio(TSocio socio)
{
    printf("Socio <%d>: <%s> <%s>\n", socio->ci, socio->nombre, socio->apellido);
    printf("Fecha de alta: <%u/%u/%u>\n", socio->fechaAlta->dia, socio->fechaAlta->mes, socio->fechaAlta->anio);
    printf("Géneros favoritos: ");
    for (int i = 0 < topegenerosfavoritos; i++;)

    {
        printf("<$d>", generosfavoritos[i]); // si esto funciona es 1 milagro
    }
}

void liberarTSocio(TSocio &socio)
{
    liberarTFecha(socio->fechaAlta);
    delete socio;
    socio = NULL;
}

int ciTSocio(TSocio socio)
{
    return socio->ci;
}

char *nombreTSocio(TSocio socio)
{
    return NULL;
}

char *apellidoTSocio(TSocio socio)
{
    return NULL;
}

TFecha fechaAltaTSocio(TSocio socio)
{
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero)
{
    if (socio->topegenerosfavoritos < MAX_GENEROS_FAVORITOS)
    {
        socio->generosfavoritos[socio->topegenerosfavoritos] = idGenero;
        socio->topegenerosfavoritos++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero)
{
    for (int i = 0; i < socio->topegenerosfavoritos; i++)
    {
        if (socio->topegenerosfavoritos[i] == idGenero)
        {
            return true;
        }
    }
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio)
{
    return socio->topegenerosfavoritos;
}

TSocio copiarTSocio(TSocio socio)
{
    TSocio copia = crearTSocio(socio->ci, socio->nombre, socio->apellido, socio->fechaAlta->dia, socio->fechaAlta->mes, socio->fechaAlta->anio);

    for (int i = 0; i < socio->topegenerosfavoritos; i++)
    {
        agregarGeneroFavoritoTSocio(copia, socio->generosfavoritos[i]);
        {
        }
        return copia;
    }
}
