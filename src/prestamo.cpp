
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
  nuevoprestamo->fechaRetiro = copiarTFecha(fechaRetiro);
  nuevoprestamo->fechaDevolucion = NULL;

  return nuevoprestamo;
}

void imprimirTPrestamo(TPrestamo prestamo)
{
  printf("Préstamo de libro <%s> a <%s> <%s>.\n",
         tituloTLibro(prestamo->libro),
         nombreTSocio(prestamo->socio),
         apellidoTSocio(prestamo->socio));
  printf("Fecha de retiro: ");
  imprimirTFecha(prestamo->fechaRetiro);
  printf("Fecha de devolución: ");
  if (prestamo->fechaDevolucion != NULL)
  {
    imprimirTFecha(prestamo->fechaDevolucion);
  }
  else
  {
  }
}
void liberarTPrestamo(TPrestamo &prestamo)
{
  if (prestamo->fechaRetiro != NULL)
  {
    liberarTFecha(prestamo->fechaRetiro);
  }
  if (prestamo->fechaDevolucion != NULL)
  {
    liberarTFecha(prestamo->fechaDevolucion);
  }
  delete prestamo;
  prestamo = NULL;
}

TSocio socioTPrestamo(TPrestamo prestamo)
{
  return NULL;
}

TFecha fechaRetiroTPrestamo(TPrestamo prestamo)
{
  return prestamo->fechaRetiro;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo)
{
  return prestamo->fechaDevolucion;
}

TLibro libroTPrestamo(TPrestamo prestamo)
{
  return prestamo->libro;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo)
{
return prestamo->fechaDevolucion != NULL;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion)
{
  if (prestamo->fechaDevolucion != NULL) {
        liberarTFecha(prestamo->fechaDevolucion);
    }
    
    prestamo->fechaDevolucion = fechaDevolucion;
}

TPrestamo copiarTPrestamo(TPrestamo prestamo) {
  
  TPrestamo copia = crearTPrestamo(prestamo->socio, prestamo->libro, prestamo->fechaRetiro);

  if (prestamo->fechaDevolucion != NULL) {
    copia->fechaDevolucion = copiarTFecha(prestamo->fechaDevolucion);
   }
    
    return copia;
}