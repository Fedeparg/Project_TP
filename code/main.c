#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "bala.h"
#include "personaje.h"
#include "listabalas.h"
#include "listaenemigos.h"
#include "enemigo.h"
#include "colisiones.h"


/**
    \file main.c
    \brief Archivo en el que se ejecuta todo el juego. Desde un mini
    tutorial, hasta la pantalla de puntuacion.
*/
int main (int argc, char *argv[])
{
/**
    \brief Peparaciones previas.
    Se inicializan todas las listas, archivos y variables necesarias para que el programa funcione correctamente mas delante.
*/
    Listabalas lb = Lista_Balasgenera();
    Listaenemigos le = Lista_Enemigosgenera(10);
    double mx, my, t_check;
    int t_actual, t_bala, t_puntuacion = 0, t_refer, puntuacionrec, aux_textofinal, seedenemigos;
    char puntuacion[15], puntuacionanterior[25];
    FILE *record;
    Imagen bg = Pantalla_ImagenLee("bg.bmp", 0);


/**
    \brief Pantalla de inicio.
    Se muestra una imagen con unas instrucciones basicas sobre el juego. No se interactua con el usuario.
*/
    Pantalla_Crea("Launcher", 1280, 720);
    int end = 0;
    while (Pantalla_Activa() && end != 1)
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) end = 1;
        Pantalla_ColorTrazo(0, 0, 0, 255);
        Pantalla_ColorRelleno(0,0,0,200);
        Pantalla_DibujaImagen(bg, 0, 0, Pantalla_Anchura(), Pantalla_Altura());
        Pantalla_Actualiza();
        Pantalla_Espera(10);
    }
    Pantalla_ImagenLibera(bg);
    Pantalla_Libera();

/**
    \brief Pantalla de juego.
    La pantalla en la que se ejecutan todas las operaciones de juego.
*/

    Pantalla_Crea("Game", 1280, 720);
    end = 0;
    t_refer = time(NULL);
    t_bala = time(NULL);
    Personaje p = Personaje_Crea(Pantalla_Anchura()/2, Pantalla_Altura()/2, 25, 12);
    while (Pantalla_Activa() && end != 1)
    {
        t_actual = time(NULL);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) end = 1;
        Pantalla_ColorTrazo(0, 0, 0, 255);
        Pantalla_ColorRelleno(0,0,0,200);
        Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(), Pantalla_Altura());
        Pantalla_RatonCoordenadas(&mx, &my);

// DIBUJAR COSAS :)

        //ENEMIGOS

        if (le)
        {
            seedenemigos = rand()%100;
            if (seedenemigos<2)
            {
                Enemigo e = Enemigo_Genera(rand()%Pantalla_Anchura()-40, rand()%Pantalla_Altura()-40, 40);
                Lista_Enemigoinserta(le, e);
            }
            Lista_Enemigosmueve(le);
            Lista_Enemigosdibuja(le);
        }

        //BALAS

        if (lb)
        {
            Lista_Balalimpia(lb);
            Mueve_Listabalas(lb);
            Dibuja_Listabalas(lb);
        }
        if (Pantalla_RatonBotonPulsado(SDL_BUTTON_LEFT))
        {
            t_check = difftime(t_actual, t_bala);
            if (t_check >= 1)
            {
                Bala b = Bala_Genera(Personaje_getx(p), Personaje_gety(p), mx, my, 10);
                Lista_Balainserta(lb,b);
                t_bala = time(NULL);
            }
        }


        //PERSONAJE

        Personaje_Mueve(p);
        Personaje_Dibuja(p);
        Colision_Personajeenemigos(p, le);

        //COLISIONES

        Colision_BalasEnemigos(lb, le);

//PUNTUACION

        t_puntuacion = difftime(t_actual, t_refer);
        sprintf(puntuacion, "Puntuacion: %d",t_puntuacion);
        Pantalla_ColorTrazo(0,255,0,255);
        Pantalla_DibujaTexto(puntuacion, 1100, 50);

//FIN DEL JUEGO

        if (Personaje_getstate(p) == 1) end = 1;

//ACTUALIZACION DE PANTALLA

        Pantalla_Actualiza();
        Pantalla_Espera(20);
    }

//LIBERACION DE MEMORIA

    Lista_Balaslibera(lb);
    Personaje_Libera(p);
    Pantalla_Libera();

/**
    \brief Pantalla de puntuacion.
    En esta pantalla solo se muestra la puntuacion obtenida, indicando si
    es un nuevo record o no. En caso de no serlo, se muestra el record
    existente.
*/


    Pantalla_Crea("Puntuacion", 1280, 720);
    end = 0;
    t_puntuacion = t_puntuacion;
    record = fopen("record.txt", "r");
    fscanf(record, "%d", &puntuacionrec);
    if (t_puntuacion > puntuacionrec)
    {
        fclose(record);
        record = fopen("record.txt", "w");
        fprintf(record, "%d", t_puntuacion);
        aux_textofinal = 1;
    }
    else
    {
        aux_textofinal = 0;
    }
    fclose(record);
    sprintf(puntuacionanterior, "Mejor puntuacion: %d", puntuacionrec);
    while (Pantalla_Activa() && end != 1)
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) end = 1;
        Pantalla_ColorTrazo(0, 0, 0, 255);
        Pantalla_ColorRelleno(0, 0, 0, 200);
        Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(), Pantalla_Altura());
        Pantalla_ColorTrazo(0, 255, 0, 255);
        Pantalla_ColorRelleno(0, 255, 0, 200);
        if (aux_textofinal == 1)
        {
            Pantalla_DibujaTexto("NUEVO RECORD!!!", Pantalla_Anchura()/2-50, Pantalla_Altura()/2-50);
        }
        else
        {
            Pantalla_DibujaTexto(puntuacionanterior, Pantalla_Anchura()/2-50, Pantalla_Altura()/2-50);
        }
        Pantalla_DibujaTexto(puntuacion, Pantalla_Anchura()/2-50, Pantalla_Altura()/2);
        Pantalla_Actualiza();
        Pantalla_Espera(10);
    }
    Pantalla_Libera();

//FINALIZACION DE PROGRAMA
    return 0;
}
