#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED
#include <stdio.h>

typedef enum {PRODUCTO, SUMA} Operador;


void MOperador (Operador o);
/*MUESTRA TIPO OPERADOR PRODUCTO O SUMA*/

void CSuma(Operador &o);
/*CREA OPERADOR TIPO SUMA*/

void CProducto(Operador &o);
/*CREA OPERADOR TIPO PRODUCTO*/

Operador DOperador(Operador o);
/*DEVUELVE OPERADOR*/

#endif // OPERADOR_H_INCLUDED
