#ifndef ARBOLEXPRESION_H_INCLUDED
#define ARBOLEXPRESION_H_INCLUDED
#include <stdio.h>
#include "Termino.h"
#include "ListaString.h"

typedef struct NodoExpresion{ Termino InfoExpresion;
                                NodoExpresion *hizq;
                                NodoExpresion *hder;
                            }NodoE;
typedef NodoE * ArbolExpresion;

void CrearArbol (ArbolExpresion &a);
/*CREA UN NUEVO ARBOL*/

void AgregarTermino (ArbolExpresion &a, Termino t);
/*AGREGA DATO A CADA TERMINO*/



void MostrArbol (ArbolExpresion a);
/*MUESTRA ARBOL*/

void CopiarArbol (ArbolExpresion a, ArbolExpresion &b);
/*COPIA ARBOL A OTRO ARBOL*/

int CantNodos (ArbolExpresion a);
/*DEVUELVE CANTIDAD DE NODOS DE UN ARBOL EN INT*/

void EliminarArbol (ArbolExpresion &a);
/*ELIMINA EL ARBOL*/

boolean ArbolEq(ArbolExpresion a, ArbolExpresion b);
///Comprara Arboles*/

void BajarArbol (FILE * Archivo, ArbolExpresion a);
/**/

void LevantArbol (FILE * Archivo, ArbolExpresion &a);
/**/
void Levantar_AUX(ArbolExpresion &a, Termino t);
/**/
void AgregarParentesisIZQ (ArbolExpresion &a);
/*AGREGA PARENTESIS HIZQUIERDO*/

void AgregarParentesisDER (ArbolExpresion &a);
/*AGREGA PARENTESIS DERECHO*/

int evaluarArbol (ArbolExpresion a, int valor);
/*EVALUA ARBOL CON DETERMINADO INT Y RESUELVE EXPRESION DEVOLVIENDO INT*/

void AgregarMas (ArbolExpresion &a,ArbolExpresion s1,ArbolExpresion s2 );
/*AGREGA '+' A EL ARBOL PARA LA SUM*/

void AgregarProd (ArbolExpresion &a,ArbolExpresion s1,ArbolExpresion s2 );
/*AGREGA '*' A EL ARBOL PARA EL PROD*/

void EnumerarArbol(ArbolExpresion &a, int &ID);
/*ENUMERA EL ARBOL*/

#endif // ARBOLEXPRESION_H_INCLUDED
