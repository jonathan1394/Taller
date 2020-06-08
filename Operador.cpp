#include "Operador.h"

void MOperador(Operador o)
{
    switch(o)
    {
        case PRODUCTO : printf("producto");
                        break;
        case SUMA     : printf("suma");
                        break;
    }
}

void CSuma(Operador &o){
    o=SUMA;
}
void CProducto(Operador &o){
    o=PRODUCTO;
}

Operador DOperador(Operador o){
    Operador AUX;
    if(o==SUMA)
        AUX=SUMA;
    if(o==PRODUCTO)
        AUX=PRODUCTO;
    return AUX;
}
