#ifndef LISTAENEMIGOS_H_INCLUDED
#define LISTAENEMIGOS_H_INCLUDED
#include "enemigo.h"
/**
    \file listaenemigos.h
    \brief Permite controlar listas en las que se encuentren elementos del tipo Enemigo.
*/
/**
    \brief TDA Listaenemigos
 */
typedef struct ListaenemigosRep *Listaenemigos;

/**
  \brief Crea una lista vacia a la que se le pueden ir insertando campos.
  \param n El numero máximo de elementos que se quieren tener.
 */
Listaenemigos Lista_Enemigosgenera(int n);
/**
  \brief Libera la memoria reservada para los enemigos.
  \param l La lista de enemigos que se va a liberar de memoria.
 */
void Lista_Enemilibera (Listaenemigos l);
/**
  \brief Inserta un elemento en la lista.
  \param l La lista de enemigos en la que se quiere insertar el elemento.
  \param e El elemento enemigo que se quiera insertar en la lista.
 */
void Lista_Enemigoinserta (Listaenemigos l, Enemigo e);
/**
  \brief Elimina un elemento de la lista de enemigos.
  \param l La lista de enemigos en la que se quiere eliminar el elemento.
  \param i EL numero del elemento en la lista que se quiere eliminar.
 */
void Lista_Enemigoelimina (Listaenemigos l, int i);
/**
  \brief Dibuja la lista de enemigos en la pantalla.
  \param l La lista de enemigos que se quiere dibujar.
 */
void Lista_Enemigosdibuja (Listaenemigos l);
/**
  \brief Actualiza las posiciones en pantalla de los elementos en la lista de enemigos. Recomendable aplicar antes de dibujar la lista.
  \param l La lista de enemigos cuyas posiciones se quieren actualizar.
 */
void Lista_Enemigosmueve (Listaenemigos l);
/**
  \brief Devuelve el elemento Enemigo de una posición concreta de la lista.
  \param l La lista de enemigos de la que se quiere obtener el enemigo.
  \param n La posicion del enemigo solicitado.
  \return El enemigo solicitado.
 */
Enemigo Lista_Getenemigo (Listaenemigos l, int n);
/**
    \brief Obtiene la posición en la lista de un enemigo concreto y la devuelve.
    \param l La lista de enemigos en la que se encuentra la posicion del enemigo que queremos obtener.
    \return La posición del enemigo.
*/
int Lista_GetenemigoN (Listaenemigos l);

#endif // LISTAENEMIGOS_H_INCLUDED
