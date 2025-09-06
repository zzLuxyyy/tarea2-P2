
#include "../include/lseSocios.h"

struct rep_lseSocios {
	TSocio socios[MAX_SOCIOS]; // EN CONSTRUCCIÓN!
	int tope;
};

TLSESocios crearTLSESociosVacia(){
    return NULL;
}

bool esVaciaTLSESocios(TLSESocios lseSocios){
	return false;
}

void imprimirTLSESocios(TLSESocios lseSocios){
	
}

void liberarTLSESocios(TLSESocios &lseSocios){
	for (int i = 0; i < lseSocios->tope; i++)
        {
            liberarTLSESocios(lseSocios->socios[i]);
        }
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
    return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	return 0;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
	int i = 0;
	while (i<lseSocios->tope && TSocio(ci->socios[i] != ci))
	{
		i++;
	} 

	liberarTLSESocios(lseSocios->socios[i]);
	lseSocios->socios[i] = lseSocios->socios[lseSocios->tope -1];
	lseSocios->tope--;

	// EN CONSTRUCCIÓN!
}