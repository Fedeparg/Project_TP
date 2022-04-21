#include "bala.h"
#include "Pantalla.h"
#include <math.h>
#include <stdlib.h>

//ESTRUCTURA DE LAS BALAS

struct BalaRep
{
    float x, y, vx, vy;
    int r;
};

Bala Bala_Genera(int ox, int oy, int dx, int dy, int r)
{
    Bala b = malloc(sizeof(struct BalaRep));
    b->x = ox;
    b->y = oy;
    b->r = r;
    float modulo = sqrt(pow(dx-ox,2)+pow(dy-oy,2));
    b->vx = (dx-ox)/modulo;
    b->vy = (dy-oy)/modulo;
    return b;
}

void Bala_Actualiza (Bala b)
{
    b->x = b->x + 20*(b->vx);
    b->y = b->y + 20*(b->vy);
}
void Bala_Dibuja(Bala b)
{
    Pantalla_ColorTrazo(0,0,0,0);
    Pantalla_ColorRelleno(255, 255, 0, 255);
    Pantalla_DibujaCirculo(b->x, b->y, b->r);
}
void Bala_Libera (Bala b)
{
    free(b);
}
int Bala_getx (Bala b)
{
    return b->x;
}
int Bala_gety (Bala b)
{
    return b->y;
}
int Bala_getr(Bala b)
{
    return b->r;
}
