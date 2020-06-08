#include "ListaExpresiones.h"

void CrearListaExpresiones (ListaExpresiones &l)
{
    l=NULL;
}
boolean EsVacia (ListaExpresiones l)
{
    boolean Bandera=TRUE;
    if(l!=NULL){
        Bandera=FALSE;

    }
    return Bandera;
}
boolean ExisteExpresion (ListaExpresiones l, string s)
{
    boolean Bandera=FALSE;
    ListaExpresiones le=l;
    while(!Bandera && le!=NULL){
        if(Streq(DevolverInfoe(le->infoe),s)){
            Bandera=TRUE;
        }else
            le=le->sig;
    }
    l=le;
    return Bandera;
}
///PRECONDICION: e1 no se puede ingresar
void AgregarArbolaLista (ListaExpresiones &l, ArbolExpresion a)
{
    ///se puede resolver todo en una sola recorrida, pensarlo

    ListaExpresiones le=l, l2=l;
    Expresion e;
    string s,aux;
    Strcrear(s);
    Strcrear(aux);
    NodoLe *ex = new NodoLe;
    int i=1;

    while(le != NULL){
        le=le->sig;
        i++;
    }
    Strcop(s,"e");
    ConvertirString(i,aux);
    Strcon(s,aux);

    CrearExpresion(ex->infoe,s,a);
    ex->sig=NULL;
    le=l;
    if(le==NULL){
        le=ex;
    }else{

        while(l2->sig!=NULL){
            l2=l2->sig;
        }
        l2->sig=ex;
    }
l=le;
}

Expresion BuscarExpresion (ListaExpresiones l, string s)
{
    Expresion e;
    ListaExpresiones le=l;
    while(le!=NULL){
        if(Streq(DevolverInfoe(le->infoe),s)){
            CrearExpresion(e,s,DevolerArbol(le->infoe));
        }
        le=le->sig;
    }
    l=le;
    return e;

}

void MostrarExpresiones (ListaExpresiones l)
{
    while(l!=NULL){
        MostrarExpresion(l->infoe);
        printf("\n");
        l=l->sig;
    }
}
int CantExpresiones (ListaExpresiones l)
{
    int i=0;
    while(l!=NULL){
        i++;
        l=l->sig;
    }
    return i;
}

void eliminarExpresion (ListaExpresiones &l){

    if(l!=NULL){
        eliminarExpresion(l->sig);
        delete l;
        l= NULL;
    }
}
