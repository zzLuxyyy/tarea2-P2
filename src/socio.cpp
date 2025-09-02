#include "../include/socio.h"

struct rep_socio {
int ci;
char nombre[MAX_NOMBRE_SOCIO];
char apellido[MAX_APELLIDO_SOCIO];
Tfecha fechaAlta;
int generosfavoritos [MAX_GENEROS_FAvORITOS];
int topegenerosfavoritos;
};
 
TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta){

Tsocio nuevosocio = rep_socio;
nuevosocio->ci = ci;
strpcy(nuevosocio->nombre, nombre)
strpcy(nuevosocio->apellido, apellido)
nuevosocio->fechaAlta = crearTFecha(nat diaAlta, nat mesAlta, nat anioAlta)
nuevosocio->topegenerosfavoritos = 0;

    return rep_socio;
}

void imprimirTSocio(TSocio socio){



    // Función que imprime la información del socio en el siguiente formato (donde los géneros favoritos
// se imprimen en el orden en el que fueron agregados):
//
printf ("Socio <%d \n>: <%s \n> <%s \n>", socio->ci, socio->nombre, socio->apellido); // Socio <CI>: <nombre> <apellido>
printf ("Fecha de alta: <>") // Fecha de alta: <Fecha de Alta> //me tengo q ir
// Géneros favoritos: <id genero favorito 1> <id genero favorito 2> ... <id genero favorito n> 
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso 
}

void liberarTSocio(TSocio &socio){
}

int ciTSocio(TSocio socio){
    return 0;
}

char* nombreTSocio(TSocio socio){
    return NULL;
}

char* apellidoTSocio(TSocio socio){
    return NULL;
}

TFecha fechaAltaTSocio(TSocio socio){
    return NULL;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    return 0;
}

TSocio copiarTSocio(TSocio socio){
    return NULL;
}
