#include <stdio.h>
#include <stdlib.h>
#include "bala.h"
#include "listabalas.h"
#include "Pantalla.h"

struct ListabalasRep
{
    Bala b;
    struct ListabalasRep * sig;
};
Listabalas Lista_Balasgenera()
{
    Listabalas l = malloc(sizeof(struct ListabalasRep));
    l -> sig = NULL;
    return l;
}
void Lista_Balaslibera (Listabalas l)
{
    while (l->sig !=NULL)
    {
        Listabalas eliminado = l->sig;
        l->sig = l->sig->sig;
        free(eliminado);
    }
    free(l);
}
void Lista_Balainserta (Listabalas l, Bala b)
{
    Listabalas nuevo = malloc(sizeof (struct ListabalasRep));
    nuevo->b = b;
    nuevo->sig = l->sig;
    l->sig = nuevo;
}
Listabalas Lista_Getbalasig (Listabalas l)
{
    return l->sig;
}
Bala Lista_Getbala(Listabalas l)
{
    return l->sig->b;
}
void Lista_Balalimpia (Listabalas l)
{
    while ( l->sig != NULL )
    {
        if( (0>Bala_getx(l->sig->b) || Pantalla_Anchura()<Bala_getx(l->sig->b) ) || (0>Bala_gety(l->sig->b) || Pantalla_Altura()<Bala_gety(l->sig->b)))
        {
            Listabalas eliminado = l->sig;
            l->sig = eliminado->sig;
            Bala_Libera(eliminado->b);
            free(eliminado);
        }
        else
        {
            l = l->sig;
        }
    }
}
void Lista_Balaelimina (Listabalas l)
{
    Listabalas eliminado = l->sig;
    l->sig = eliminado->sig;
    Bala_Libera(eliminado->b);
    free(eliminado);
}
void Dibuja_Listabalas(Listabalas l)
{
    Listabalas actual = l->sig;
    while ( actual != NULL )
    {
        Bala_Dibuja( actual->b );
        actual = actual->sig;
    }
}
void Mueve_Listabalas (Listabalas l)
{
    Listabalas actual = l->sig;
    while ( actual != NULL )
    {
        Bala_Actualiza( actual->b );
        actual = actual->sig;
    }
}

