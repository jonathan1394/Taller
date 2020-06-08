#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

//Precondicion: b tiene que existir
void CargarBoolean (boolean &b);
/*CARGA TRUE O FALSE A UNA VARIABLE BOOLEAN*/
//Precondicion: b tiene que existir y tiene que estar cargado
void MostrarBoolean (boolean b);
/*MUESTRA TRUE O FALSE DE UNA VARIABLE BOOLEAN*/


#endif // BOOLEAN_H_INCLUDED
