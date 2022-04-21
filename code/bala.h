#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include "Pantalla.h"
/**
    \file Bala.h
    \brief Permite genera, editar y eliminar elementos del tipo Bala.
*/
/**
    \brief TDA Bala
 */
typedef struct BalaRep *Bala;

/**
    \brief Genera un elemento del tipo Bala.
    \param ox El punto de origen de las balas en el eje x.
    \param oy El punto de origen de las balas en el eje y.
    \param dx El punto de destino de las balas en el eje x.
    \param dy El punto de destino de las balas en el eje y.
    \param r El radio que se quiere tener para las balas.
*/
Bala Bala_Genera (int ox, int oy, int dx, int dy, int r);
/**
    \brief Dibuja un elemento del tipo Bala en pantalla.
    \param b La bala que se quiere dibujar.
*/
void Bala_Dibuja (Bala b);
/**
    \brief Actualiza la posicion del elemento del tipo Bala.
    \param b La bala cuya posición se queire actualizar.
*/
void Bala_Actualiza (Bala b);
/**
    \brief Libera la memoria asignada a un elemento del tipo Bala.
    \param b El elemento bala que se quiere liberar de memoria.
*/
void Bala_Libera (Bala b);
/**
    \brief Devuelve la posicion en el eje x de un elemento del tipo Bala.
    \param b El elemento bala del que se quiere conocer su coordenada x.
    \return La coordenada en el eje x.
*/
int Bala_getx(Bala b);
/**
    \brief Devuelve la posicion en el eje y de un elemento del tipo Bala.
    \param b El elemento bala del que se quiere conocer su coordenada y.
    \return La coordenada en el eje y.
*/
int Bala_gety(Bala b);
/**
    \brief Devuelve el radio de un elemento del tipo Bala.
    \param b El elemento bala del que se quiere conocer su radio.
    \return El radio.
*/
int Bala_getr(Bala b);



#endif // BALA_H_INCLUDED
