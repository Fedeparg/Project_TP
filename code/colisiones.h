#ifndef COLISIONES_H_INCLUDED
#define COLISIONES_H_INCLUDED
#include "bala.h"
#include "enemigo.h"
#include "listabalas.h"
#include "listaenemigos.h"
#include "personaje.h"
/**
    \file colisiones.h
    \brief Se encarga de comprobar las colisiones entre distintos elementos.
*/
/**
    \brief Se encarga de comprobar una colision generica entre dos elementos.
    \param x1 La posicion x del primer elemento.
    \param y1 La posicion y del primer elemento.
    \param r1 El radio del primer elemento.
    \param x2 La posicion x del segundo elemento.
    \param y2 La posicion y del segundo elemento.
    \param r2 El radio del segundo elemento.
    \return 0 si no hay colision. 1 si hay colision.
*/
int Colision (int x1, int y1, int r1, int x2, int y2, int r2);
/**
    \brief Comprueba la colision entre el personaje y un enemigo.
    \param p El personaje.
    \param e Un enemigo.
    \return 0 si no hay colision. 1 si hay colision.
*/
int Colision_Personajeenemigo (Personaje p, Enemigo e);
/**
    \brief Comprueba la colision entre el personaje y toda una lista de enemigos.
    \param p El personaje.
    \param le La lista de enemigos a comparar.
*/
void Colision_Personajeenemigos (Personaje p, Listaenemigos le);
/**
    \brief Comprueba la colision entre una bala y un enemigo.
    \param b La bala.
    \param e El enemigo.
    \return 0 si no hay colision. 1 si hay colision.
*/
int Colision_BalaEnemigo (Bala b, Enemigo e);
/**
    \brief Comprueba la colision entre la lista de balas y la de enemigos.
    \param lb La lista de balas a comparar.
    \param le La lista de enemigos a comparar.
*/
void Colision_BalasEnemigos (Listabalas lb, Listaenemigos le);

#endif // COLISIONES_H_INCLUDED
