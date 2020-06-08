#include "ListaString.h"
#include "String.h"


void CrearListaString (ListaString &ls)
{
    ls=NULL;
}
void AgregarString (ListaString &ls, string s)
{
    ListaString AUXls;
    NodoLs *AUX = new NodoLs;
    Strcrear(AUX->infos);
    Strcop(AUX->infos,s);
    AUX->sig=NULL;

    if(ls==NULL){
        ls=AUX;
    }else{
        AUXls=ls;
        while(AUXls->sig != NULL){
            AUXls=AUXls->sig;
        }
        AUXls->sig=AUX;
    }

}
///PRECONDICION: String debe de estar cargado
void PartirString (string s, ListaString &ls)
{

    int i=0, j=0, fin=0;;
    string AUX;
    Strcrear(AUX);
    boolean P_letra=TRUE;
while(s[i]!='\0'){
    if(s[i]!=' ' && P_letra==TRUE){
        j=i;
        P_letra=FALSE;
    }
    if(s[i]==' ' && P_letra== FALSE){
        Strcut(AUX,s,j,i);
        AgregarString(ls,AUX);
        P_letra=TRUE;
        fin=i;
    }
    i++;
}
i--;
if(s[i]==' '){
    while(s[i]==' '){
        i--;
    }
}
i++;
if(i!=fin){
    Strcut(AUX,s,j,i);
    AgregarString(ls,AUX);
}
}
///PRECONDICION: pos no debe ser > a CantStrings
void DevolverString (string &s, ListaString ls, int pos)
{
    ListaString p=ls;
    int i=0;
    while(p!=NULL){
        if(i==pos){
            Strcop(s,p->infos);
        }else{
            p=p->sig;
        }
        i++;
    }

}
int CantStrings (ListaString ls)
{
    int i=0;
    ListaString l=ls;
    while(l!=NULL){
        i++;
        l=l->sig;
    }
    return i;
}

void EliminarListaString (ListaString &ls){
       if(ls!=NULL){
        EliminarListaString(ls->sig);
        Strdestruir(ls->infos);
        delete ls;
        ls = NULL;
       }

}
