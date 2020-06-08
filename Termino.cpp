#include "Termino.h"
#include "TipoTermino.h"
#include "Parentesis.h"
#include "Operador.h"

TipoTermino DevolverTipoTermino (Termino t){
    TipoTermino R;
    switch(t.tipo){
        case NUMERO     : R = NUMERO;
                          break;
        case OPERADOR   : R = OPERADOR;
                          break;
        case PARENTESIS : R = PARENTESIS;
                          break;
        case VARIABLE   : R = VARIABLE;
                          break;
    }

        return R;
}

int DevolverInt (Termino t){
    int aux;
    if( DevolverTipoTermino(t) == NUMERO){
        aux= t.dato.numero;
    }else{
        printf("El termino no contiene un INT");
        aux=0;
    }
    return aux;
}

char DevolverChar (Termino t){
    char aux;
    if( DevolverTipoTermino(t) == VARIABLE){
        aux= t.dato.x;
    }else{
        printf("El termino no contiene una VARIABLE");
        aux =' ';
    }
    return aux;
}

Operador DevolverOperador (Termino t){
    Operador aux;
    if( t.tipo == OPERADOR){
        if (t.dato.ope==SUMA){
        aux=SUMA;
        }else{
        aux=PRODUCTO;
        }
    }else{
        printf("El termino no contiene un operador");
    }
    return aux;
}

Parentesis DevolverParentesis (Termino t){
    Parentesis aux;
    if( DevolverTipoTermino(t) == PARENTESIS){
        if (DParentesis(t.dato.parent) == ABREPAREN){
            aux=ABREPAREN;
        }else{
            aux=CIERRAPAREN;
        }
    }else{
        printf("El termino no contiene un Parentesis");

    }
    return aux;
}

void MostrarTermino (Termino t){
    switch(DevolverTipoTermino(t)){
    case PARENTESIS : if(DParentesis(t.dato.parent)==ABREPAREN)
                        printf("(");
                      if(DParentesis(t.dato.parent)==CIERRAPAREN)
                        printf(")");
    break;
    case OPERADOR : if(DOperador(t.dato.ope)==SUMA)
                        printf("+");
                    if(DOperador(t.dato.ope)==PRODUCTO)
                        printf("*");
    break;
    case VARIABLE : printf("%c",DevolverChar(t));
    break;
    case NUMERO: printf("%d",DevolverInt(t));
    break;
    }
}

void CrearVar (Termino &t){
    t.tipo=VARIABLE;
    t.dato.x='x';
}
/**/
void CrearNum (Termino &t, int num){
    t.tipo=NUMERO;
    t.dato.numero=num;
}
/**/
void CrearSum(Termino &t){
    t.tipo=OPERADOR;
    t.dato.ope=SUMA;
}
/**/
void CrearProd (Termino &t){
    t.tipo=OPERADOR;
    t.dato.ope=PRODUCTO;
}
/**/
void CrearParentA (Termino &t){
    t.tipo=PARENTESIS;
    t.dato.parent=ABREPAREN;
}
/**/
void CrearParentC (Termino &t){
    t.tipo=PARENTESIS;
    t.dato.parent=CIERRAPAREN;
}

void agregarNumeroTermino(int num, Termino &t){
    t.numeroTermino=num;
}

int DevolverNumeroTermino(Termino t){
return t.numeroTermino;
}
