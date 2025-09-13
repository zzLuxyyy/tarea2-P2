
#include "../include/lseSocios.h"

struct nodo
{
	TSocio socio;
	nodo *sig;
};

struct rep_lseSocios
{
	nodo *primero;
	nat cantidad;
};

TLSESocios crearTLSESociosVacia()
{
	TLSESocios nueva = new rep_lseSocios;
	nueva->primero = NULL;
	nueva->cantidad = 0;
	return nueva;
}

bool esVaciaTLSESocios(TLSESocios lseSocios)
{
    return lseSocios->primero == NULL;
}

void imprimirTLSESocios(TLSESocios lseSocios)
{	
    printf("Lista de Socios:\n");
	nodo* actual = lseSocios->primero;
    while (actual != NULL) {
        imprimirTSocio(actual->socio);
        actual = actual->sig;
    }
}

void liberarTLSESocios(TLSESocios &lseSocios)
{
	nodo *actual = lseSocios->primero;
	while (actual != NULL)
	{
		nodo *aBorrar = actual;
		actual = actual->sig;
		liberarTSocio(aBorrar->socio);
		delete aBorrar;
	}
	delete lseSocios;
	lseSocios = NULL;
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio)
{
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci)
{
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci)
{
	return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n)
{
	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios)
{
	return lseSocios->cantidad;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci)
{
	nodo *actual = lseSocios->primero;
	nodo *anterior = NULL;

	while (actual != NULL && ciTSocio(actual->socio) != ci)
	{
		anterior = actual;
		actual = actual->sig;
	}

	if (actual != NULL)
	{
		if (anterior == NULL)
		{
			lseSocios->primero = actual->sig;
		}
		else
		{
			anterior->sig = actual->sig;
		}

		liberarTSocio(actual->socio);
		delete actual;
		lseSocios->cantidad--;
	}
}