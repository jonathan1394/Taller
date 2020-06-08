#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include "String.h"

typedef struct NodoString{ string infos;
                           NodoString * sig;
                         }NodoLs;
typedef NodoLs * ListaString;

void CrearListaString (ListaString &ls);
/*CREA LISTA*/

void AgregarString (ListaString &ls, string s);
/*AGREGA STRING A LISTA*/

void PartirString (string s, ListaString &ls);
/*PARTE STRING EN DIFERENTES STRING GUARDA EN LA LISTA STRING*/

void DevolverString (string &s, ListaString ls, int pos);
/*DEVUELVE UN STRING DE LA LISTA*/

int CantStrings (ListaString ls);
/*DEVUELVE CANTIDAD STRINGS DE LA LISTA*/

void EliminarListaString (ListaString &ls);
/*ELIMINA LA LISTA de string*/

#endif // LISTASTRING_H_INCLUDED
