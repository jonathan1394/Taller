#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED
#include "Parentesis.h"
#include "TipoTermino.h"
#include "Operador.h"

typedef struct { TipoTermino tipo;
                 int numeroTermino;
                    union { int numero;
                            Operador ope;
                            Parentesis parent;
                            char x;
                        } dato;
               } Termino;

TipoTermino DevolverTipoTermino (Termino t);
/*DEVUELVE EL TIPO DE TERMINO */
int DevolverInt (Termino t);
/*DEVUELVE EL VALOR INT DE TERMINO */
char DevolverChar (Termino t);
/*DEUELVVE EL VALOR CHAR DE TERMINO*/
Operador DevolverOperador (Termino t);
/*DEVUELVE EL TIPO OPERADOR DE TERMINO*/
Parentesis DevolverParentesis (Termino t);
/*DEVUELVE PARENTESIS DE TERMINO*/
void MostrarTermino (Termino t);
/*IMPRIME EL TERMINO*/
void CrearVar (Termino &t);
/*CREA UN TERMINO VARIABLE*/
void CrearNum (Termino &t, int num);
/*CREA UN TERMINO NUMERO*/
void CrearSum(Termino &t);
/*CREA UN TERMINO CON OPERADOR SUM*/
void CrearProd (Termino &t);
/*CREA UN TERMINO CON OPERADOR PRODUCT*/
void CrearParentA (Termino &t);
/*CREA UN TERMINO CON PARENTESIS ABIERTO*/
void CrearParentC (Termino &t);
/*CREA UN TERMINO CON PARENTESIS CERRADO*/
void agregarNumeroTermino(int num, Termino &t);
/*AGREGA NUMERO DE TERMINO*/
int DevolverNumeroTermino(Termino t);
/*DEVUELVE NUMERO DE TERMINO*/
#endif // TERMINO_H_INCLUDED
