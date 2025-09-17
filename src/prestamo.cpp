
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
  printf("Préstamo de libro %s a %s %s. \n",
         tituloTLibro(prestamo->libro),
         nombreTSocio(prestamo->socio),
         apellidoTSocio(prestamo->socio));
  imprimirTFecha(prestamo->fechaRetiro);
// Elimine los printf porque no formaban parte del formato pedido.
 /*
  if (prestamo->fechaDevolucion != NULL)
  {
    imprimirTFecha(prestamo->fechaDevolucion);
  }
  else
  {
    printf("No retornado\n"); // faltaba esta linea.
  }
*/
  // Reemplace el bloque anterior por este if-else que usa la funcion fueRetornadoTPrestamo
 if (fueRetornadoTPrestamo(prestamo))
  {
    imprimirTFecha(prestamo->fechaDevolucion);
  }
  else
  {
    printf("No retornado\n"); // faltaba esta linea.
  }
}

void liberarTPrestamo(TPrestamo &prestamo)
{
  if (prestamo != NULL)
  {
    liberarTFecha(prestamo->fechaRetiro);
    if (prestamo->fechaDevolucion != NULL)
    {
      liberarTFecha(prestamo->fechaDevolucion);
    }
    // Liberar también el socio y el libro
    //liberarTSocio(prestamo->socio);
    //liberarTLibro(prestamo->libro);
    
    delete prestamo;
    prestamo = NULL;
  }
}

TSocio socioTPrestamo(TPrestamo prestamo)
{
  return prestamo->socio;
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
  if (prestamo->fechaDevolucion != NULL)
  {
    liberarTFecha(prestamo->fechaDevolucion);
  }
  prestamo->fechaDevolucion = fechaDevolucion; 
}

TPrestamo copiarTPrestamo(TPrestamo prestamo)
{
  TPrestamo copia = new rep_prestamo;
  copia->socio = copiarTSocio(prestamo->socio);
  copia->libro = copiarTLibro(prestamo->libro);
  copia->fechaRetiro = copiarTFecha(prestamo->fechaRetiro);
  if (fueRetornadoTPrestamo(prestamo))
  {
    copia->fechaDevolucion = copiarTFecha(prestamo->fechaDevolucion);
  }
  else
  {
    copia->fechaDevolucion = NULL;
  }
  return copia;
}