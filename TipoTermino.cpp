#include "TipoTermino.h"

 void MTT (TipoTermino f)
 {
  switch (f)
  {
        case NUMERO     : printf ("Numero");
                          break;
        case OPERADOR   : printf ("Operador");
                          break;
        case PARENTESIS : printf ("Parentesis");
                          break;
        case VARIABLE   : printf ("Variable");
                          break;
  }
 }
 void CTTNumero (TipoTermino &t){
    t=NUMERO;
 }

void CTTOperador (TipoTermino &t){
    t=OPERADOR;
}

void CTTParentesis (TipoTermino &t){
    t=PARENTESIS;
}

void CTTVariable(TipoTermino &t){
    t=VARIABLE;
}

TipoTermino DTT(TipoTermino t){
  TipoTermino AUX;
  switch (t)
  {
        case NUMERO     : CTTNumero(AUX);
                          break;
        case OPERADOR   : CTTOperador(AUX);
                          break;
        case PARENTESIS : CTTParentesis(AUX);
                          break;
        case VARIABLE   : CTTVariable(AUX);
                          break;
  }
  return AUX;
}

