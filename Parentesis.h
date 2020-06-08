#ifndef PARENTESIS_H_INCLUDED
#define PARENTESIS_H_INCLUDED
#include <stdio.h>

typedef enum {ABREPAREN, CIERRAPAREN} Parentesis;


void MParentesis (Parentesis p);
/*IMPRIME TIPO PARENTESIS SI ABRE O CIERRA*/

void CParentesisA(Parentesis &p);
/*CARGA PARENTESIS ABIERTO*/

void CParentesisC(Parentesis &p);
/*CARGA PARENTESIS CERRADO*/

Parentesis DParentesis(Parentesis p);
/*RETORNA PARENTESIS ABIERTO O CERRADO*/
#endif // PARENTESIS_H_INCLUDED
