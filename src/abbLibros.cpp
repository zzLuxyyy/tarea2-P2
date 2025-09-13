
#include "../include/abbLibros.h"

struct nodoABB
{
    // Struct del nodo para el arbol binario de busqueda.
    TLibro libro;
    nodoABB *izq;
    nodoABB *der;
};

struct rep_abbLibros
{
    nodoABB *raiz;
    int cantidad;
};

TABBLibros crearTABBLibrosVacio()
{
    TABBLibros nuevoABB = new rep_abbLibros;
    nuevoABB->raiz = NULL;
    nuevoABB->cantidad = 0;
    return nuevoABB;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro)
{
}

void imprimirAux(nodoABB *nodo)
{
    if (nodo != NULL)
    {
        imprimirAux(nodo->izq);
        imprimirTLibro(nodo->libro);
        imprimirAux(nodo->der);
    }
}

void imprimirTABBLibros(TABBLibros abbLibros)
{
    imprimirAux(abbLibros->raiz);
}

void liberarArbol(nodoABB* &nodo) {
    if (nodo != NULL) {
        liberarArbol(nodo->izq);
        liberarArbol(nodo->der);
        liberarTLibro(nodo->libro);
        delete nodo;
        nodo = NULL;
    }
}

void liberarTABBLibros(TABBLibros &abbLibros)
{
    liberarArbol(abbLibros->raiz);
    delete abbLibros;
    abbLibros = NULL;
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn)
{
    return false;
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn)
{
    return NULL;
}

nat alturaTABBLibros(TABBLibros abbLibros)
{
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros)
{
    return NULL;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn)
{
}

int cantidadTABBLibros(TABBLibros abbLibros)
{
    return abbLibros->cantidad;
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res)
{
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n)
{
    return NULL;
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero)
{
    return NULL;
}