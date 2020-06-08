#ifndef ListaExpresionesresiones_H_INCLUDED
#define ListaExpresionesresiones_H_INCLUDED
#include "Expresion.h"

typedef struct NodoExpresiones{ Expresion infoe;
                                NodoExpresiones * sig;
                            }NodoLe;
typedef NodoLe * ListaExpresiones;

void CrearListaExpresiones (ListaExpresiones &l);
/*CREA LISTA DE EXPRESIONES*/
boolean EsVacia (ListaExpresiones l);
/*VERIICA SI LA LISTA ES VACIA DEVUELVE T O F*/
boolean ExisteExpresion (ListaExpresiones l, string s);
/*RECORRE LA LISTA Y VERIFICA SI EXISTE LA EXPRESION*/
void AgregarArbolaLista (ListaExpresiones &l, ArbolExpresion a);
/*AGREGA ARBOL A UNA EXPRESION EN LA LISTA*/
Expresion BuscarExpresion (ListaExpresiones l, string s); /* HACERLO FUNCION string? */
/*BUSCA EXPRESION DENTRO DE LA LISTA */
void MostrarExpresiones (ListaExpresiones l);
/*MUESTRA TODAS LAS EXPRESIONES DE LA LISTA*/
int CantExpresiones (ListaExpresiones l);
/*DEVUELVE LA CANTIDAD DE EXPRESIONES DE LA LISTA*/
void eliminarExpresion (ListaExpresiones &l);
/*ELIMINA LA LISTA DE EXPRESIONES*/
#endif // ListaExpresionesresiones_H_INCLUDED
