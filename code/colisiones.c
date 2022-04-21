#include "colisiones.h"
#include <math.h>
#include "bala.h"
#include "enemigo.h"
#include "listabalas.h"
#include "listaenemigos.h"
#include "personaje.h"

int Colision (int x1, int x2, int y1, int y2, int r1, int r2)
{
    int distancia = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
    if ( distancia < r1 + r2 ) return 1;
    return 0;
}
int Colision_Personajeenemigo (Personaje p, Enemigo e)
{
    return Colision(Personaje_getx(p), Enemigo_getx(e), Personaje_gety(p), Enemigo_gety(e), Personaje_getr(p), Enemigo_getr(e));
}
void Colision_Personajeenemigos (Personaje p, Listaenemigos le)
{
    int i = 0;
    while (i < Lista_GetenemigoN(le))
    {
        if (Colision_Personajeenemigo(p, Lista_Getenemigo(le, i)))
        {
            Personaje_Libera(p);
        }
        else
        {
            i++;
        }
    }
}
int Colision_BalaEnemigo (Bala b, Enemigo e)
{
    return Colision(Bala_getx(b), Enemigo_getx(e), Bala_gety(b), Enemigo_gety(e), Bala_getr(b), Enemigo_getr(e));
}
void Colision_BalasEnemigos (Listabalas lb, Listaenemigos le)
{
    Bala b;
    int i = 0;
    int colisionados;
    while (Lista_Getbalasig(lb) != NULL)
    {
        b = Lista_Getbala(lb);
        colisionados = 0;
        i = 0;
        while (i < Lista_GetenemigoN(le) && !colisionados)
        {
            if ( Colision_BalaEnemigo(b, Lista_Getenemigo(le, i)))
            {
                Lista_Balaelimina(lb);
                Lista_Enemigoelimina(le, i);
                colisionados = 1;
            }
            else i++;
        }
        if (!colisionados) lb = Lista_Getbalasig(lb);
    }
}
