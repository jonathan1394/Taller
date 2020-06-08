#include "Parentesis.h"

void MParentesis (Parentesis p)
{
    switch(p)
    {
        case ABREPAREN: printf("(");
            break;
        case CIERRAPAREN: printf(")");
            break;
    }
}

void CParentesisA(Parentesis &p){
    p=ABREPAREN;
}

void CParentesisC(Parentesis &p){
    p=CIERRAPAREN;
}

Parentesis DParentesis(Parentesis p){
    Parentesis AUX;
    if(p==ABREPAREN)
        AUX=ABREPAREN;
    if(p==CIERRAPAREN)
        AUX=CIERRAPAREN;
    return AUX;
}
