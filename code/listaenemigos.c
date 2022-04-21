#include <stdlib.h>
#include "listaenemigos.h"
#include "enemigo.h"

struct ListaenemigosRep
{
    Enemigo *e;
    int max, n;
};

Listaenemigos Lista_Enemigosgenera(int max)
{
    Listaenemigos l = malloc(sizeof(struct ListaenemigosRep));
    l->e = malloc(sizeof(Enemigo) * max);
    l->n = 0;
    l->max = max;
    for (int i = 0; i<max; i++)
    {
        l->e[i] = NULL;
    }
    return l;
}
void Lista_Enemigolibera (Listaenemigos l)
{
    for (int i = 0; i < l->max; i++ )
    {
        Enemigo_Libera(l->e[i]);
    }
    free(l);
}
void Lista_Enemigoinserta (Listaenemigos l, Enemigo e)
{
    if (l->n == l->max) return;
    int i = 0;
    while (l->e[i] != NULL) i++;
    l->e[i] = e;
    l->n++;
}
void Lista_Enemigoelimina (Listaenemigos l, int i)
{
    Enemigo eliminar = l->e[i];
    l->e[i] = l->e[l->n-1];
    free(eliminar);
    l->e[l->n-1] = NULL;
    l->n--;
}
void Lista_Enemigosdibuja (Listaenemigos l)
{
    for (int i = 0; i < l->max; i++)
    {
        if (l->e[i] != NULL) Enemigo_Dibuja(l->e[i]);
    }
}
void Lista_Enemigosmueve (Listaenemigos l)
{
        for (int i = 0; i < l->max; i++)
    {
        if (l->e[i] != NULL) Enemigo_Actualiza(l->e[i]);
    }
}
Enemigo Lista_Getenemigo (Listaenemigos l, int n)
{
    return l->e[n];
}
int Lista_GetenemigoN (Listaenemigos l)
{
    return l->n;
}
