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


// Función que imprime la información del socio en el siguiente formato 
void imprimirTSocio(TSocio socio){

printf ("Socio <%d>: <%s> <%s>\n", socio->ci, socio->nombre, socio->apellido);
printf("Fecha de alta: <%u/%u/%u>\n", socio->fechaAlta->dia, socio->fechaAlta->mes, socio->fechaAlta->anio); 
printf("Géneros favoritos: " )
    for int i=0 < topegenerosfavoritos, i++; {
        printf("<$d>", generosfavoritos[i])  //si esto funciona es 1 milagro
}
}


void liberarTSocio(TSocio &socio){
    liberartfecha (socio->fechaAlta);
    delete socio;
    socio=NULL;
}

int ciTSocio(TSocio socio){
    return socio->ci;
}

char* nombreTSocio(TSocio socio){
    return NULL;
}

char* apellidoTSocio(TSocio socio){
    return NULL;
}

TFecha fechaAltaTSocio(TSocio socio){
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
    if (socio->topegenerosfaoritos < MAX_GENEROS_FAVORITOS){
        socio->generosfavoritos[socio->topegenerosfavoritos] = idgenero;
        socio->topegenerosfaoritos++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    for (i = 0, i < socio->topegenerosfaoritos, i++) {
        if socio->topegenerosfaoritos[i] == idgenero {
            return true
        }
    }
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    return socio->topegenerosfavoritos;
}

TSocio copiarTSocio(TSocio socio){
    Tsocio copia = crearTSocio(socio->ci, socio->nombre, socio->apellido, socio->fechaAlta->dia, socio->fechaAlta->mes, socio->fechaAlta->anio)

    for (i = 0, i < socio->topegenerosfavoritos, i++){
        agregarGeneroFavoritoTSocio(copia, socio->generosfavoritos[i]){
    }       
    return copia;
}
}
