#include "Expresion.h"

void CrearExpresion (Expresion &e, string id, ArbolExpresion a)
{
    e.IDExpresion=id;
    e.ValorExpresion=a;
}

void MostrarExpresion (Expresion e)
{
    Print(e.IDExpresion);
    printf(" : ");
    MostrArbol(e.ValorExpresion);


}

string DevolverInfoe (Expresion e)
{
    return e.IDExpresion;
}

ArbolExpresion DevolerArbol (Expresion e)
{
    ArbolExpresion aux;
    CrearArbol(aux);
    CopiarArbol(e.ValorExpresion,aux);
    return aux;
}
///PRECONDICION: LA expresion debe de estar cargada
void CopiarEx(Expresion &e, Expresion e1){

    Strcop(e.IDExpresion,e1.IDExpresion);
    CopiarArbol(e1.ValorExpresion,e.ValorExpresion);
}
