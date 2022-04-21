#include <stdlib.h>
#include "enemigo.h"
#include <time.h>
#include "Pantalla.h"

//ESTRUCTURA DE LOS ENEMIGOS

struct EnemigoRep
{
    int x;
    int y;
    int r;
    int vx;
    int vy;
};

Enemigo Enemigo_Genera (int x, int y, int r)
{
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->x = x;
    e->y = y;
    e->r = r;
    e->vx = 5;
    e->vy = 5;
    return e;
}
void Enemigo_Dibuja (Enemigo e)
{
    Pantalla_ColorTrazo(0,0,0,0);
    Pantalla_ColorRelleno(255, 0, 0, 255);
    Pantalla_DibujaCirculo(e->x, e->y, e->r);
}
void Enemigo_Libera (Enemigo e)
{
    free(e);
}
void Enemigo_Actualiza (Enemigo e)
{
    e->x = e->x + e->vx;
    e->y = e->y + e->vy;
    if(e->x-e->r < 0) e->vx = rand()%20;
    else if(e->y-e->r < 0) e->vy = rand()%20;
    else if(e->x + e->r > Pantalla_Anchura()) e->vx = -rand()%20;
    else if(e->y + e->r > Pantalla_Altura()) e->vy = -rand()%20;
}
int Enemigo_getx (Enemigo e)
{
    return e->x;
}
int Enemigo_gety (Enemigo e)
{
    return e->y;
}
int Enemigo_getr (Enemigo e)
{
    return e->r;
}
