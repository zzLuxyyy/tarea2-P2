
#include "../include/abbLibros.h"

struct rep_abbLibros {
    int tope;
};

TABBLibros crearTABBLibrosVacio(){
    TABBLibros nuevoTABBLibro = new rep_abbLibros;
    nuevoTABBLibro->tope = 0;
    return nuevoTABBLibro;
    // Creo que falta lo del arbol binario
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
}

void imprimirTABBLibros(TABBLibros abbLibros){
}

void liberarTABBLibros(TABBLibros &abbLibros){
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn){
    return false;
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    return NULL;
}

nat alturaTABBLibros(TABBLibros abbLibros){
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    return NULL;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn){
}

int cantidadTABBLibros(TABBLibros abbLibros){
    return 0;
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    return NULL;
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    return NULL;
}