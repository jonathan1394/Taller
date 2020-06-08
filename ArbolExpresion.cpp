#include "ArbolExpresion.h"


void CrearArbol (ArbolExpresion &a){
    a=NULL;
}

void AgregarTermino (ArbolExpresion &a, Termino t)
{
    ArbolExpresion ab;
    NodoE *AUX=new NodoE;

    switch(DevolverTipoTermino(t)){
        case(VARIABLE): CrearVar(AUX->InfoExpresion);
                        AUX->hizq=NULL;
                        AUX->hder=NULL;
                        break;
        case (NUMERO):CrearNum(AUX->InfoExpresion,DevolverInt(t));
                        AUX->hizq=NULL;
                        AUX->hder=NULL;
                        break;
        case (PARENTESIS): if(DevolverParentesis(t)==ABREPAREN){
                                CrearParentA(AUX->InfoExpresion);
                            }else{
                                CrearParentC(AUX->InfoExpresion);
                            }
                            AUX->hizq=NULL;
                            AUX->hder=NULL;
                            break;
        case(OPERADOR): if(DevolverOperador(t)==SUMA){
                            CrearSum(AUX->InfoExpresion);
                        }else{
                            CrearProd(AUX->InfoExpresion);
                        }
                        AUX->hizq=NULL;
                        AUX->hder=NULL;
                        break;
    }
         a=AUX;
}


///PRECONDICION: El arbol no debe de estar vacio
void MostrArbol (ArbolExpresion a)
{
        ArbolExpresion ab=a;
    if(ab!=NULL){
        MostrArbol(ab->hizq);
        if(DevolverTipoTermino(ab->InfoExpresion)==OPERADOR){
            printf(" ");
            MostrarTermino(ab->InfoExpresion);
            printf(" ");
        }else{
            MostrarTermino(ab->InfoExpresion);
        }
        MostrArbol(ab->hder);
    }
}
///PRECONDICION: b debe de estar vacio
void CopiarArbol (ArbolExpresion a, ArbolExpresion &b)
{
    ArbolExpresion AB=a;

    if(AB!=NULL){
        AgregarTermino(b,AB->InfoExpresion);
        CopiarArbol(AB->hizq,b->hizq);
        CopiarArbol(AB->hder,b->hder);
    }else
        b=NULL;
    a=AB;
}

int CantNodos (ArbolExpresion a)
{
    if(a == NULL)
        return 0;
    else
        return 1 + CantNodos(a->hizq) + CantNodos(a->hder);
}
void EliminarArbol (ArbolExpresion &a)
{
    if(a!=NULL){
        EliminarArbol(a->hizq);
        EliminarArbol(a->hder);
        delete a;
        a=NULL;
    }
}

boolean ArbolEq(ArbolExpresion a, ArbolExpresion b){

if(a==NULL && b==NULL){
    return TRUE;
}

if(a!=NULL && b==NULL){
    return FALSE;

}

if(a==NULL && b!=NULL){
    return FALSE;

}

if(a!=NULL && b!=NULL){
if(DevolverTipoTermino(a->InfoExpresion)==DevolverTipoTermino(b->InfoExpresion)){
    switch(DevolverTipoTermino(a->InfoExpresion)){
           case (OPERADOR):if(DevolverOperador(a->InfoExpresion)!=DevolverOperador(b->InfoExpresion)){
                                return FALSE;
                            }
                            else
                            {
                                if(ArbolEq(a->hizq,b->hizq)==FALSE || ArbolEq(a->hder,b->hder)==FALSE)
                                   return FALSE;
                                else
                                    return TRUE;
                            }
            break;
           case (VARIABLE):if(DevolverChar(a->InfoExpresion)!=DevolverChar(b->InfoExpresion)){
                                return FALSE;
                            }
                            else
                            {
                                if(ArbolEq(a->hizq,b->hizq)==FALSE || ArbolEq(a->hder,b->hder)==FALSE)
                                   return FALSE;
                                else
                                    return TRUE;
                            }
            break;
            break;
           case (PARENTESIS):if(DevolverParentesis(a->InfoExpresion)!=DevolverParentesis(b->InfoExpresion)){
                                return FALSE;
                            }
                            else
                            {
                                if(ArbolEq(a->hizq,b->hizq)==FALSE || ArbolEq(a->hder,b->hder)==FALSE)
                                   return FALSE;
                                else
                                    return TRUE;
                            }
            break;



            break;
           case (NUMERO):if(DevolverInt(a->InfoExpresion)!=DevolverInt(b->InfoExpresion)){
                                return FALSE;
                            }
                            else
                            {
                                 if(ArbolEq(a->hizq,b->hizq)==FALSE || ArbolEq(a->hder,b->hder)==FALSE)
                                   return FALSE;
                                else
                                    return TRUE;

                            }
            break;
                    }

           }else{
                    return FALSE;
                }

}
return TRUE;

}

///PRECONDICION:el archivo debe estar abierto en modo "rb".
void BajarArbol (FILE * Archivo, ArbolExpresion a)
{
    if(a!=NULL){
        fwrite(&(a->InfoExpresion),sizeof(Termino),1,Archivo);
        BajarArbol(Archivo,a->hizq);
        BajarArbol(Archivo,a->hder);
    }
}
///PRECONDICION: a debe ser vacio
void LevantArbol (FILE * Archivo, ArbolExpresion &a)
{
    Termino t;
    ArbolExpresion AB=a;
    fread(&t,sizeof(Termino),1,Archivo);
    while(!feof(Archivo)){
        Levantar_AUX(AB,t);
        fread(&t,sizeof(Termino),1,Archivo);
    }
    a=AB;
}

void Levantar_AUX(ArbolExpresion &a, Termino t){
    if(a==NULL){
        AgregarTermino(a,t);
        agregarNumeroTermino(DevolverNumeroTermino(t),a->InfoExpresion);
    }else{
        if(DevolverNumeroTermino(t) < DevolverNumeroTermino(a->InfoExpresion)){
            Levantar_AUX(a->hizq,t);
        }else{
            Levantar_AUX(a->hder,t);
        }
    }
}

void AgregarParentesisIZQ (ArbolExpresion &a)
{
    NodoE *AUX=new NodoE;
    if(a->hizq!=NULL){
        AgregarParentesisIZQ(a->hizq);
    }else{
        CrearParentA(AUX->InfoExpresion);
        AUX->hizq=NULL;
        AUX->hder=NULL;
        a->hizq=AUX;
    }
}

void AgregarParentesisDER (ArbolExpresion &a)
{
    NodoE *AUX=new NodoE;

    if(a->hder!=NULL){
        AgregarParentesisDER(a->hder);
    }else{
        CrearParentC(AUX->InfoExpresion);
        AUX->hizq=NULL;
        AUX->hder=NULL;
        a->hder=AUX;
    }
}

int evaluarArbol (ArbolExpresion a, int valor)
{
    ArbolExpresion ab=a;
    int i=0;
    if(DevolverTipoTermino(ab->InfoExpresion)==OPERADOR){
        if(DevolverOperador(ab->InfoExpresion)==SUMA){
            i=evaluarArbol(ab->hizq,valor)+ evaluarArbol(ab->hder,valor);
        }else{
            i=evaluarArbol(ab->hizq,valor)*evaluarArbol(ab->hder,valor);
        }
    }

    if(DevolverTipoTermino(ab->InfoExpresion)==VARIABLE){
        i=valor;
    }
    if(DevolverTipoTermino(ab->InfoExpresion)==NUMERO){
        i=DevolverInt(ab->InfoExpresion);
    }
return i;
}

void AgregarMas (ArbolExpresion &a,ArbolExpresion s1,ArbolExpresion s2 )
{
    ArbolExpresion ab=a;
    NodoE *aux=new NodoE;
    CrearSum(aux->InfoExpresion);
    CopiarArbol(s1,aux->hizq);
    AgregarParentesisIZQ(aux);
    CopiarArbol(s2,aux->hder);
    AgregarParentesisDER(aux);
    a=aux;
}

void AgregarProd (ArbolExpresion &a,ArbolExpresion s1,ArbolExpresion s2 )
{
    ArbolExpresion ab=a;
    NodoE *aux=new NodoE;
    CrearProd(aux->InfoExpresion);
    CopiarArbol(s1,aux->hizq);
    AgregarParentesisIZQ(aux);
    CopiarArbol(s2,aux->hder);
    AgregarParentesisDER(aux);
    a=aux;
}
///PRECONDICION: El arbol no debe ser vacio
void EnumerarArbol(ArbolExpresion &a, int &ID){
if(a!=NULL){
    EnumerarArbol(a->hizq,ID);
    agregarNumeroTermino(ID,a->InfoExpresion);
    ID++;
    EnumerarArbol(a->hder,ID);
}
}
