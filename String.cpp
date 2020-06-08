#include "String.h"

void Strdestruir (string &s)
{
delete [] s;
s = NULL;
}

void Strcrear (string &s)
{
s = new char[MAX];
s[0] = '\0';
}

int Strlar (string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
void Print (string s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        printf("%c",s[i]);
        i++;
    }
}
void Scan (string &s)
{
string aux = new char[MAX];
int i=0;
char c;
scanf ("%c", &c);
while ((c!= '\n' && i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
aux[i] = '\0';
Strcop (s,aux);
Strdestruir (aux);
}


boolean Streq (string s1, string s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i]){
            iguales = FALSE;
        }
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

void Strcop (string &s1, string s2)
{
    int i = 0;
    int largo = Strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void Strcon (string &s1, string s2)
{
    int i = Strlar(s1);
    int j = 0;
    int largo = Strlar(s2);
    while ((i + j < MAX - 1) && (j < largo))
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

boolean NoEsNumero (string s)
{
    int i=0;
    boolean bandera=FALSE;
    if(s[0]=='-'){
        i=1;
    }
    while(s[i] != '\0' && !bandera){
        if(s[i]<48 || s[i]> 57){
            bandera=TRUE;
        }
    i++;
    }

    return bandera;
}
///PRECONDICION: Debe de ser un String con valores numericos
int ConvertirInt (string s)
{
    int i=0;
    int numero=0;
    boolean Negativo=FALSE;
    if(s[0]=='-'){
        i=1;
        Negativo=TRUE;
    }
        if(!NoEsNumero(s)){
            while(s[i] != '\0'){
                switch (s[i]){
                case '1': numero+=1;
                break;
                case '2': numero+=2;
                break;
                case '3': numero+=3;
                break;
                case '4': numero+=4;
                break;
                case '5': numero+=5;
                break;
                case '6': numero+=6;
                break;
                case '7': numero+=7;
                break;
                case '8': numero+=8;
                break;
                case '9': numero+=9;
                break;
                }
            i++;
            numero*=10;
            }
            numero=numero/10;
        }

        if(Negativo==TRUE){
           numero=numero*(-1);
        }
    return numero;
}
void ConvertirString (int num, string &S)
{
    int j=0, i=0, modulo=0;
    string aux;
    string retorno;
    Strcrear(aux);
    Strcrear(retorno);
    if(num==0){
    Strcon(retorno,"0");
    i++;
    }
    if(num<99999999){
        while(num > 0){
            modulo= num % 10;

        switch (modulo)
            {
            case 1: Strcon(aux,"1");
            break;
            case 2: Strcon(aux,"2");
            break;
            case 3: Strcon(aux,"3");
            break;
            case 4: Strcon(aux,"4");
            break;
            case 5: Strcon(aux,"5");
            break;
            case 6: Strcon(aux,"6");
            break;
            case 7: Strcon(aux,"7");
            break;
            case 8: Strcon(aux,"8");
            break;
            case 9: Strcon(aux,"9");
            break;
            case 0: Strcon(aux,"0");
            break;
            }
            num=num/10;
            j++;
        }
    }
j--;
    while(j>=0){
        retorno[i]=aux[j];
        j--;
        i++;
    }

    retorno[i]='\0';
    Strcop(S,retorno);
}

boolean ValidarExpresion(string s)
{
    boolean bandera=TRUE;

    int i=0;
    while(s[i]!='\0' && bandera){
        if(s[0]=='e'){
            bandera=TRUE;
       }else{
            bandera=EsNumero(s[i]);
       }
    i++;
    }
    return bandera;
}

boolean EsNumero(char c)
{
    boolean bandera=FALSE;
        switch (c){
            case '1': bandera=TRUE;
            break;
            case '2': bandera=TRUE;
            break;
            case '3': bandera=TRUE;
            break;
            case '4': bandera=TRUE;
            break;
            case '5': bandera=TRUE;
            break;
            case '6': bandera=TRUE;
            break;
            case '7': bandera=TRUE;
            break;
            case '8': bandera=TRUE;
            break;
            case '9': bandera=TRUE;
            break;
        }
            return bandera;
}
boolean ValidarArchivo(string s)
{
    string AUX;
    Strcrear(AUX);
    boolean Bandera=FALSE;
    int P, i=0;

    P=posicionPunto(s);
    if(P<Strlar(s)){
        Strcortar(AUX,s,P+1);
    }
    if(AlfaNumerico(AUX) && (s[P] == '.' &&  s[P+1] == 'd' && s[P+2] == 'a' && s[P+3] == 't' && s[P+4] == '\0')){
          Bandera=TRUE;
    }
    //printf("%s",AUX);
    //MostrarBoolean(AlfaNumerico(AUX));
    return Bandera;
}

int posicionPunto(string s)
{
int i=0;
boolean bandera=TRUE;

while(s[i]!='\0' && bandera){
    if(s[i]=='.'){
        bandera=FALSE;
    }else{
    i++;
    }
}
    if(bandera){
        i=0;
    }

return i;
}
///PRECONDICION: Fin y ini debe ser >= a largo del string
void Strcut(string &s1,string s2, int ini, int fin){
    string aux;
    Strcrear(aux);
    int j=0, i=ini;
    while(s2[i]!='\0' && i<fin){
        aux[j]=s2[i];
        i++;
        j++;
    }
    aux[j]='\0';
    Strcop(s1,aux);
}
///PRECONDICION: num debe ser >= a largo del string
void Strcortar(string &s1,string s2, int num){
    string aux;
    Strcrear(aux);
    int i=0;
    while(s2[i]!='\0' && i<num-1){
        aux[i]=s2[i];
        i++;
    }
    aux[i]='\0';
    Strcop(s1,aux);
}

boolean AlfaNumerico(string s)
{
    int i=0;
    boolean bandera=TRUE;
    while(s[i]!='\0' && bandera==TRUE){
        if(!((s[i]>=48 && s[i]<=57) || (s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90))){
            bandera=FALSE;
        }
    i++;
    }
    return bandera;
}
///PRECONDICION: Debe de existir el archivo
boolean ArchivoVacio (string nomArch)
{
 boolean archivoVacio = FALSE;
 FILE * f = fopen (nomArch, "rb");
 int buffer;
 fread (&buffer, sizeof(int), 1, f);
 if (feof(f))
 archivoVacio = TRUE    ;
 fclose (f);
 return archivoVacio;
}

boolean ExisteArch (string nomArch)
{
 boolean existeArchivo = TRUE;
 FILE * f = fopen (nomArch, "rb");
 if (f == NULL)
    existeArchivo = FALSE;
  else
    fclose(f);
 return existeArchivo;
}
