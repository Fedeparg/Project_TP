#ifndef LISTABALAS_H_INCLUDED
#define LISTABALAS_H_INCLUDED
#include "bala.h"
/**
    \file listabalas.h
    \brief Permite controlar listas en las que se encuentren elementos del tipo Bala.
*/
/**
    \brief TDA Listabalas
 */
typedef struct ListabalasRep *Listabalas;

/**
  \brief Crea una lista vacia a la que se le pueden ir insertando campos.
 */
Listabalas Lista_Balasgenera();
/**
  \brief Libera la memoria reservada para las balas.
  \param l La lista de balas que se va a liberar de memoria.
 */
void Lista_Balaslibera (Listabalas l);
/**
  \brief Inserta un elemento en la lista.
  \param l La lista de balas en la que se quiere insertar el elemento.
  \param b El elemento bala que se quiera insertar en la lista.
 */
void Lista_Balainserta (Listabalas l, Bala b);
/**
  \brief Obtiene la lista y avanza un elemento en ella.
  \param l La lista de balas en la que se quiere avanzar.
  \return La lista de balas empezando por el elemento siguiente.
 */
Listabalas Lista_Getbalasig (Listabalas l);
/**
  \brief Devuelve el elemento actual de la lista.
  \param l La lista de balas de la que se quiere obtener el elemento.
  \return  El elemento Bala de la lista que se pidio.
 */
Bala Lista_Getbala(Listabalas l);
/**
  \brief Elimina los elementos de la lista que se encuentren fuera de la pantalla, reduciendo asi el consumo de memoria innecesaria.
  \param l La lista de balas de la que se quieren limpiar los elementos de fuera de la pantalla.
 */
void Lista_Balalimpia (Listabalas l);
/**
  \brief Elimina un elemento de la lista de balas.
  \param l La lista de balas en la que se quiere eliminar el elemento.
 */
void Lista_Balaelimina (Listabalas l);
/**
  \brief Dibuja la lista de balas en la pantalla.
  \param l La lista de balas que se quiere dibujar.
 */
void Dibuja_Listabalas (Listabalas l);
/**
  \brief Actualiza las posiciones de la lista de balas. Recomendable aplicar antes de dibujar la lista.
  \param l La lista de balas cuyas posiciones se quieren actualizar.
 */
void Mueve_Listabalas (Listabalas l);

#endif // LISTABALAS_H_INCLUDED
