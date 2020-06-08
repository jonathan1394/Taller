#include "Boolean.h"

void CargarBoolean (boolean &b)
{
    char c;
    printf ("Ingrese T para TRUE o F para FALSE: \n");
    fflush (stdin);
    scanf ("%c", &c);
    if (c == 'T' || c == 't')
        b = TRUE;
    if(c == 'F' || c == 'f')
        b = FALSE;
    if(c!='F' && c!='f' && c != 'T' && c != 't'){
        printf("La tecla ingresada no es correcta");
    }
}

void MostrarBoolean (boolean b)
{
    if (b)
        printf ("TRUE");
    else
        printf ("FALSE");
}


