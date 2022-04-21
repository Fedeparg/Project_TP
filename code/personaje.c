#include "personaje.h"
#include "Pantalla.h"
#include <stdlib.h>
#include <stdio.h>

//Estructura del personaje

struct PersonajeRep
{
    int x, y, r, v, state;
};

Personaje Personaje_Crea(int x, int y, int r, int v)
{
    Personaje p = malloc(sizeof(struct PersonajeRep));
    p->x = x;
    p->y = y;
    p->r = r;
    p->v = v;
    p->state = 0;
    return p;
}

void Personaje_Libera (Personaje p)
{
    free(p);
    p->state = 1;
}

void Personaje_Mueve (Personaje p)
{
      if (Pantalla_TeclaPulsada(SDL_SCANCODE_W) && (p->y - p->r > 0))
    {
        p->y = p->y-p->v;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_S)&& (p->y + p->r < Pantalla_Altura()))
    {
        p->y = p->y+p->v;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_D)&& (p->x + p->r < Pantalla_Anchura()))
    {
        p->x = p->x+p->v;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_A)&& (p->x - p->r > 0))
    {
        p->x = p->x-p->v;
    }
}
void Personaje_Dibuja(Personaje p)
{
    Pantalla_ColorTrazo(0, 0, 0, 0);
    Pantalla_ColorRelleno(0, 0, 255, 255);
    Pantalla_DibujaCirculo(p->x, p->y, p->r);
}

int Personaje_getx(Personaje p)
{
    return p->x;
}

int Personaje_gety(Personaje p)
{
    return p->y;
}

int Personaje_getr(Personaje p)
{
    return p->r;
}

int Personaje_getstate (Personaje p)
{
    return p->state;
}
