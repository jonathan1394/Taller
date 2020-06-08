#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include <stdio.h>
#include "ArbolExpresion.h"

typedef struct {string IDExpresion; //e1
                ArbolExpresion ValorExpresion;
               }Expresion;

//Precondicion E debe existir s debe validar e-num y arbol!=vacio.
 void CrearExpresion (Expresion &e, string id, ArbolExpresion a);
 /*CREA UNA EXPRESION CON DICHO ARBOL*/


//Precondicion E debe existir
 void MostrarExpresion (Expresion e);
 /*IMPRIME LA EXPRESION */
 string DevolverInfoe (Expresion e);
 /*DEVUELVVE ID DE EXPRESION*/
 ArbolExpresion DevolerArbol (Expresion e) ;
/*DEVUELVE EL ARBOL DE LA EXPRESION*/

void CopiarEx(Expresion &e, Expresion e1);
/*COPIA UNA EXPRESION*/

#endif // EXPRESION_H_INCLUDED
