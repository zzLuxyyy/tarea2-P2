#include "../include/socio.h"
#include <string.h> //strcpy
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
    printf("Fecha de alta: ");
    imprimirTFecha(socio->fechaAlta);
    printf("Géneros favoritos: ");
    for (int i = 0; i < socio->topegenerosfavoritos; i++)
    {
        printf("%d ", socio->generosfavoritos[i]);
    }
    printf("\n");
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
    return socio->nombre;
}

char *apellidoTSocio(TSocio socio)
{
    return socio->apellido;
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
        if (socio->generosfavoritos[i] == idGenero) // El error estaba en *tope*generosfavoritos.
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
    TSocio copia = crearTSocio(socio->ci, socio->nombre, socio->apellido, 1, 1, 1);
    liberarTFecha(copia->fechaAlta);
    copia->fechaAlta = copiarTFecha(fechaAltaTSocio(socio));

    for (int i = 0; i < socio->topegenerosfavoritos; i++)
    {
        agregarGeneroFavoritoTSocio(copia, socio->generosfavoritos[i]);
    }

    return copia;
}
