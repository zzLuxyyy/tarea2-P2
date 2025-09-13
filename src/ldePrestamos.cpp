#include "../include/ldePrestamos.h"

struct nodoDoble
{
    TPrestamo prestamo;
    nodoDoble *sig;
    nodoDoble *ant;
};

struct rep_ldePrestamos
{   
    nodoDoble *primero;
    nodoDoble *ultimo;
    nat tope;
};

TLDEPrestamos crearTLDEPrestamosVacia()
{
    TLDEPrestamos nuevoPrestamo = new rep_ldePrestamos;
    nuevoPrestamo->primero = NULL;
    nuevoPrestamo->ultimo = NULL;
    nuevoPrestamo->tope = 0;
    return nuevoPrestamo;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo)
{
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos)
{
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
}

nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    return ldePrestamos->tope;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    return NULL;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos)
{
    if (ldePrestamos->ultimo == NULL) return NULL;
    return ldePrestamos->ultimo->prestamo;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n)
{
    return NULL;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio)
{
    return NULL;
}
