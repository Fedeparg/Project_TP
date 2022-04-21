#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
/**
    \file personaje.h
    \brief Permite controlar listas en las que se encuentren elementos del tipo Bala.
*/
/**
    \brief TDA Personaje
 */
typedef struct PersonajeRep *Personaje;

/**
    \brief Genera un elemento del tipo Personaje.
    \param x El punto de origen del personaje en el eje x.
    \param y El punto de origen del personaje en el eje y.
    \param r El radio que se quiere tener para el personaje.
    \param v Velocidad a la que se quiere que el personaje se desplace (en pixels).
*/
Personaje Personaje_Crea(int x, int y, int r, int v);
/**
    \brief Libera la memoria asignada al elemento del tipo Personaje.
    \param p El elemento Personaje que se quiere liberar de memoria.
*/
void Personaje_Libera (Personaje p);
/**
    \brief Actualiza la posicion del elemento del tipo Personaje.
    \param p El elemento Personaje cuya posicion se quiere actualizar.
*/
void Personaje_Mueve (Personaje p);
/**
    \brief Dibuja el elemento Personaje por pantalla.
    \param p El elemento Personaje que se quiere dibujar.
*/
void Personaje_Dibuja(Personaje p);
/**
    \brief Devuelve la posicion en el eje x del Personaje.
    \param p El elemento Personaje del que se quiere conocer su coordenada x.
    \return La coordenada en el eje x.
*/
int Personaje_getx(Personaje p);
/**
    \brief Devuelve la posicion en el eje y del Personaje.
    \param p El elemento Personaje del que se quiere conocer su coordenada y.
    \return La coordenada en el eje y.
*/
int Personaje_gety(Personaje p);
/**
    \brief Devuelve el radio del Personaje.
    \param p El elemento Personaje del que se quiere conocer su radio.
    \return El radio.
*/
int Personaje_getr(Personaje p);
/**
    \brief Devuelve el estado del personaje. 0 si no ha sido impactado por un enemigo. 1 si ha sido impactado.
    \param p El elemento Personaje del que se quiere obtener su estado.
    \return El estado.
*/
int Personaje_getstate (Personaje p);

#endif // PERSONAJE_H_INCLUDED
