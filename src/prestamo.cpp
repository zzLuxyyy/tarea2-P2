
#include "../include/prestamo.h"


struct rep_prestamo {
  Tsocio socio
  Tlibro libro
  Tfecha fechaDevolucion
  Tfecha fechaRetiro
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro){
  Tprestamo nuevoprestamo = new rep_prestamo
  nuevoprestamo->socio = socio;
  nuevoprestamo->libro = libro;
  nuevoprestamo->fechaRetiro = fechaRetiro;
  nuevoprestamo->fechaDevolucion = NULL;

  return nuevoprestamo;
}
 
void imprimirTPrestamo(TPrestamo prestamo){
  printf("Préstamo de libro <%s> a <%s> <%s>.", tituloTlibro(prestamo->libro), nombreTsocio(prestamo->socio), apellidoTsocio(prestamo->socio));  // 
// <fecha retiro>
// <fecha devolución>
//
// Si la fecha de devolución es NULL, en lugar de '<fecha devolución>' se imprime 'No retornado'.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso    
}

void liberarTPrestamo(TPrestamo &prestamo){
}

TSocio socioTPrestamo(TPrestamo prestamo){
  return NULL;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  return NULL;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  return NULL;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  return NULL;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  return false;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion){
}

TPrestamo copiarTPrestamo(TPrestamo prestamo){
  return NULL;
}