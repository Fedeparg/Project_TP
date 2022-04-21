#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
/**
    \file Enemigo.h
    \brief Permite genera, editar y eliminar elementos del tipo Enemigo.
*/
/**
    \brief TDA Enemigo
 */
typedef struct EnemigoRep *Enemigo;

/**
    \brief Genera un elemento del tipo Enemigo.
    \param x El punto de origen de los enemigos en el eje x.
    \param y El punto de origen de los enemigos en el eje y.
    \param r El radio que se quiere tener para los enemigos.
*/
Enemigo Enemigo_Genera (int x, int y, int r);
/**
    \brief Dibuja un elemento del tipo Enemigo en pantalla.
    \param e El enemigo que se quiere dibujar.
*/
void Enemigo_Dibuja (Enemigo e);
/**
    \brief Libera la memoria asignada a un elemento del tipo Enemigo.
    \param e El elemento enemigo que se quiere liberar de memoria.
*/
void Enemigo_Libera (Enemigo e);
/**
    \brief Actualiza la posicion del elemento del tipo Enemigo.
    \param e El enemigo cuya posición se queire actualizar.
*/
void Enemigo_Actualiza (Enemigo e);
/**
    \brief Devuelve la posicion en el eje x de un elemento del tipo Enemigo.
    \param e El elemento Enemigo del que se quiere conocer su coordenada x.
    \return La coordenada en el eje x.
*/
int Enemigo_getx (Enemigo e);
/**
    \brief Devuelve la posicion en el eje y de un elemento del tipo Enemigo.
    \param e El elemento Enemigo del que se quiere conocer su coordenada y.
    \return La coordenada en el eje y.
*/
int Enemigo_gety (Enemigo e);
/**
    \brief Devuelve el radio de un elemento del tipo Enemigo.
    \param e El elemento enemigo del que se quiere conocer su radio.
    \return El radio.
*/
int Enemigo_getr (Enemigo e);

#endif // ENEMIGO_H_INCLUDED
