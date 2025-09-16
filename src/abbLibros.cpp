
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


void insertarLibroAux(nodoABB* &nodo, TLibro libro) {
    if (nodo == NULL) {
        nodo = new nodoABB;
        nodo->libro = libro;
        nodo->izq = NULL;
        nodo->der = NULL;
    } else {
        if (isbnTLibro(libro) < isbnTLibro(nodo->libro)) {
            insertarLibroAux(nodo->izq, libro);
        } else {
            insertarLibroAux(nodo->der, libro);
        }
    }
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro) {
    insertarLibroAux(abbLibros->raiz, libro);
    abbLibros->cantidad++; }


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


// auxiliar para buscar si existe un libro
bool existeLibroAux(nodoABB* nodo, int isbn) {
    if (nodo == NULL) {
        return false;
    } else {
        int isbnActual = isbnTLibro(nodo->libro);
        if (isbn == isbnActual) {
            return true;
        } else if (isbn < isbnActual) {
            return existeLibroAux(nodo->izq, isbn);
        } else {
            return existeLibroAux(nodo->der, isbn);
        }
    }
}

//función principal 
bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn) {
    return existeLibroAux(abbLibros->raiz, isbn);
}

//auxiliar para obtener un libro
TLibro obtenerLibroAux(nodoABB* nodo, int isbn) {
    if (nodo == NULL) {
        return NULL;
    } else {
        int isbnActual = isbnTLibro(nodo->libro);
        if (isbn == isbnActual) {
            return nodo->libro;
        } else if (isbn < isbnActual) {
            return obtenerLibroAux(nodo->izq, isbn);
        } else {
            return obtenerLibroAux(nodo->der, isbn);
        }
    }
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn) {
    return obtenerLibroAux(abbLibros->raiz, isbn);
}

nat alturaAux(nodoABB* nodo) {
    if (nodo == NULL) {
        return 0;
    } else {
        nat alturaIzq = alturaAux(nodo->izq);
        nat alturaDer = alturaAux(nodo->der);
        if (alturaIzq > alturaDer) {
            return 1 + alturaIzq;
        } else 
        { return 1 + alturaDer; }
    }
}

nat alturaTABBLibros(TABBLibros abbLibros) {
    return alturaAux(abbLibros->raiz);
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros) {
    nodoABB* actual = abbLibros->raiz;
    //el max esta en eñ nodo más a la derecha 
    while (actual->der != NULL) {
        actual = actual->der;
    }
    return actual->libro;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn)

{

}

int cantidadTABBLibros(TABBLibros abbLibros)
{
    return abbLibros->cantidad;
}

void obtenerNesimoLibroTABBLibrosAux(nodoABB* nodo, int n, int &k, TLibro &res) {
    if (nodo != NULL && res == NULL) { 
        // subarbol izquierdo
        obtenerNesimoLibroTABBLibrosAux(nodo->izq, n, k, res);

        if (res == NULL) { // si no lo encontramos en el izq
            
            k++; 
            if (k == n) {
                
                res = nodo->libro;
            }
        }
        
        if (res == NULL) { // no se encontro 
    //subarbol derecho
            obtenerNesimoLibroTABBLibrosAux(nodo->der, n, k, res);
        }
    }
}


TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n) {
    int k = 0; 
    TLibro res = NULL;
    obtenerNesimoLibroTABBLibrosAux(abbLibros->raiz, n, k, res);
    return res;
}


void filtradoAux(nodoABB* nodo, int genero, TABBLibros &filtrado) {
    if (nodo != NULL) {
        if (idGeneroTLibro(nodo->libro) == genero) {
            insertarLibroTABBLibros(filtrado, copiarTLibro(nodo->libro));
        }
        filtradoAux(nodo->izq, genero, filtrado);
        filtradoAux(nodo->der, genero, filtrado);
    }
}


TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    TABBLibros filtrado = crearTABBLibrosVacio();
    filtradoAux(abbLibros->raiz, genero, filtrado);
    return filtrado;
}
