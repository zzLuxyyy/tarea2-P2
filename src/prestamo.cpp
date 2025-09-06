
#include "../include/prestamo.h"

struct rep_prestamo
{
  TSocio socio;
  TLibro libro;
  TFecha fechaDevolucion;
  TFecha fechaRetiro;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro)
{
  TPrestamo nuevoprestamo = new rep_prestamo;
  nuevoprestamo->socio = socio;
  nuevoprestamo->libro = libro;
  nuevoprestamo->fechaRetiro = fechaRetiro;
  nuevoprestamo->fechaDevolucion = NULL;

  return nuevoprestamo;
}

void imprimirTPrestamo(TPrestamo prestamo)
{
  printf("Préstamo de libro <%s> a <%s> <%s>.", tituloTLibro(prestamo->libro), nombreTSocio(prestamo->socio), apellidoTSocio(prestamo->socio)); //
  // <fecha retiro>
  // <fecha devolución>
  //
  // Si la fecha de devolución es NULL, en lugar de '<fecha devolución>' se imprime 'No retornado'.
  /* Requisitos específicos de la implementación solicitada: */
  // Debe ejecutar en O(1) peor caso
  printf("Fecha de retiro: ");
  //imprimirTFecha(prestamo->fechaRetiroTPrestamo);
  printf("Título: %s\n", l->titulo);
  printf("Nombre: %s %s\n", l->nombre);
  printf("Apellido: %s\n", l->apellido);

  // EN CONTSTRUCCIÓN!!
}

void liberarTPrestamo(TPrestamo &prestamo)
{
}

TSocio socioTPrestamo(TPrestamo prestamo)
{
  return NULL;
}

TFecha fechaRetiroTPrestamo(TPrestamo prestamo)
{
  return NULL;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo)
{
  return NULL;
}

TLibro libroTPrestamo(TPrestamo prestamo)
{
  return NULL;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo)
{
  return false;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion)
{
}

TPrestamo copiarTPrestamo(TPrestamo prestamo)
{
  return NULL;
}