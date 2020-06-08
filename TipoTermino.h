#ifndef TIPOTERMINO_H_INCLUDED
#define TIPOTERMINO_H_INCLUDED
#include <stdio.h>

typedef enum {NUMERO, OPERADOR, PARENTESIS, VARIABLE} TipoTermino;


void MTT (TipoTermino t);
/* IMPRIMER EL TIPO DE TERMINO */

void CTTNumero (TipoTermino &t);
/*CREA UN TIPO DE TERMINO NUMERO*/

void CTTOperador (TipoTermino &t);
/*CREA UN TIPO DE TERMINO OPERADOR*/

void CTTParentesis (TipoTermino &t);
/*CREA UN TIPO DE TERMINO PARENTESIS*/

void CTTVariable(TipoTermino &t);
/*CREA UN TIPO DE TERMINO VARIABLE*/

TipoTermino DTT(TipoTermino t);
/*DEVUELVE TIPO DE TERMINO*/

#endif // TIPOTERMINO_H_INCLUDED
