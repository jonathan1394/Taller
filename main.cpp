#include <stdio.h>
#include "ListaString.h"
#include "ListaExpresiones.h"

int main()
{
    Termino t;
    int aux=0, Enumerador=0, mark=0;
    Expresion e,f,g;
    ArbolExpresion a,b,c;
    CrearArbol(a);
    CrearArbol(b);
    CrearArbol(c);
    ListaString ls;
    CrearListaString(ls);
    ListaExpresiones le;
    CrearListaExpresiones(le);
    string s, Primero, Segundo, Tercero, sino;
    Strcrear(s);
    Strcrear(Primero);
    Strcrear(Segundo);
    Strcrear(Tercero);
    Strcrear(sino);
    boolean Salir=FALSE;
    FILE * Archivo;


    do{
        mark=0;
        Print("Ingrese un comando:\n");
        Scan(s);
        PartirString(s,ls);
        DevolverString(Primero,ls,0);


        /// COMANDO QUIT
        if(Streq(Primero,"quit") || Streq(Primero,"QUIT")){
            EliminarArbol(a);
            eliminarExpresion(le);
            Salir=TRUE;
            mark=1;
        }

        /// COMANDO CREAR
        if(Streq(Primero,"create") || Streq(Primero,"CREATE")){
            if(CantStrings(ls)==2){
                DevolverString(Segundo,ls,1);
                    if(!NoEsNumero(Segundo) || Streq(Segundo,"x") || Streq(Segundo,"X")){
                        if(!NoEsNumero(Segundo)){
                                CrearNum(t,ConvertirInt(Segundo));
                                AgregarTermino(a,t);
                                AgregarArbolaLista(le,a);
                                printf("Resultado : ");
                                printf("e%d:",CantExpresiones(le));
                                MostrArbol(a);
                                printf("\n");

                        }else{
                                CrearVar(t);
                                AgregarTermino(a,t);
                                AgregarArbolaLista(le,a);
                                printf("Resultado : ");
                                printf("e%d:",CantExpresiones(le));
                                MostrArbol(a);
                                printf("\n");
                        }
                    }else{
                        printf("ERROR: El segundo Parametro debe ser un numero o \"x\"!!\n");
                    }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        ///COMANDO SUM
        if(Streq(Primero,"sum") || Streq(Primero,"SUM")){
            if(CantStrings(ls)==3){
            DevolverString(Segundo,ls,1);
            DevolverString(Tercero,ls,2);

                    if(ValidarExpresion(Segundo) && ValidarExpresion(Tercero)){
                        if(ExisteExpresion(le,Segundo) || ExisteExpresion(le,Tercero)){
                            if(ExisteExpresion(le,Segundo)){
                                if(ExisteExpresion(le,Tercero)){
                                    e=BuscarExpresion(le,Segundo);
                                    f=BuscarExpresion(le,Tercero);
                                    b=DevolerArbol(e);
                                    c=DevolerArbol(f);
                                    AgregarMas(a,b,c);
                                    AgregarArbolaLista(le,a);
                                    printf("Resultado: e%d:",CantExpresiones(le));
                                    MostrArbol(a);
                                    printf("\n");


                                }else{
                                    printf("ERROR: La segunda expresion no existe!!\n");
                                }
                            }else{
                                printf("ERROR: La primera expresion no existe!!\n");
                            }
                        }else{
                            printf("ERROR: Las expresiones no existen\n");
                        }
                    }else{
                        printf("ERROR: Debe ingresar una expresion del tipo e1,e2,e3,etc!!\n");
                    }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        /// COMANDO PRODUCT
        if(Streq(Primero,"product") || Streq(Primero,"PRODUCT")){
            if(CantStrings(ls)==3){
                DevolverString(Segundo,ls,1);
                DevolverString(Tercero,ls,2);

                    if(ValidarExpresion(Segundo) && ValidarExpresion(Tercero)){
                        if(ExisteExpresion(le,Segundo) || ExisteExpresion(le,Tercero)){
                            if(ExisteExpresion(le,Segundo)){
                                if(ExisteExpresion(le,Tercero)){
                                    e=BuscarExpresion(le,Segundo);
                                    f=BuscarExpresion(le,Tercero);
                                    b=DevolerArbol(e);
                                    c=DevolerArbol(f);
                                    AgregarProd(a,b,c);
                                    AgregarArbolaLista(le,a);
                                    printf("Resultado: e%d:",CantExpresiones(le));
                                    MostrArbol(a);
                                    printf("\n");
                                }else{
                                    printf("ERROR: La segunda expresion no existe!!\n");
                                }
                            }else{
                                printf("ERROR: La primera expresion no existe!!\n");
                            }
                        }else{
                            printf("ERROR: Las expresiones no existen\n");
                        }
                    }else{
                        printf("ERROR: Debe ingresar una expresion del tipo e1,e2,e3,etc!!\n");
                    }
            }else{
                printf("ERROR: Cantidad de parametros incorrecta!!\n");
            }
            mark=1;
    }

        ///COMANDO EQUALS
        if(Streq(Primero,"equals") || Streq(Primero,"EQUALS")){
            if(CantStrings(ls)==3){
            DevolverString(Segundo,ls,1);
            DevolverString(Tercero,ls,2);

                    if(ValidarExpresion(Segundo) && ValidarExpresion(Tercero)){
                            if(ExisteExpresion(le,Segundo)){
                                if(ExisteExpresion(le,Tercero)){
                                    e=BuscarExpresion(le,Segundo);
                                    f=BuscarExpresion(le,Tercero);
                                    b=DevolerArbol(e);
                                    c=DevolerArbol(f);
                                    printf("Resultado : ");
                                    if(ArbolEq(b,c)){
                                        printf("Las expresiones son iguales\n");
                                    }else{
                                        printf("Las expresiones NO son iguales\n");
                                    }
                                }else{
                                    printf("ERROR: La segunda expresion no existe!!\n");
                                }
                            }else{
                                printf("ERROR: La primera expresion no existe!!\n");
                            }
                    }else{
                        printf("ERROR: Debe ingresar una expresion del tipo e1,e2,e3,etc!!\n");
                    }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        /// COMANDO SHOW
        if(Streq(Primero,"show") || Streq(Primero,"SHOW")){
            if(CantStrings(ls)==1){
                if(!EsVacia(le)){
                    printf("Resultado:\n");
                    MostrarExpresiones(le);
                }else{
                   printf("ERROR: No existen expresiones guardadas!!\n");
                }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        ///COMANDO EVAL
        if(Streq(Primero,"eval") || Streq(Primero,"EVAL")){
            if(CantStrings(ls)==3){
            DevolverString(Segundo,ls,1);
            DevolverString(Tercero,ls,2);
                if(ValidarExpresion(Segundo)){
                    if(ExisteExpresion(le,Segundo)){
                        if(!NoEsNumero(Tercero)){
                            e=BuscarExpresion(le,Segundo);
                            a=DevolerArbol(e);
                            aux=0;
                            aux=ConvertirInt(Tercero);
                            printf("El resultado de la Expresion es:%d \n",evaluarArbol(a,aux));
                        }else{
                            printf("ERROR: El trcer parametro debe ser un numero!!\n");
                        }

                    }else{
                        printf("ERROR: La expresion no existe!!\n");
                    }
                }else{
                    printf("ERROR: Debe ingresar una expresion del tipo e1,e2,e3,etc!!\n");
                }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        ///COMANDO SAVE
        if(Streq(Primero,"save") || Streq(Primero,"SAVE")){
            if(CantStrings(ls)==3){
            DevolverString(Segundo,ls,1);
            DevolverString(Tercero,ls,2);
            if(ValidarExpresion(Segundo)){
                if(ExisteExpresion(le,Segundo)){
                    if(ValidarArchivo(Tercero)){
                        e=BuscarExpresion(le,Segundo);
                        a=DevolerArbol(e);
                        Enumerador=0;
                        EnumerarArbol(a,Enumerador);
                        if(ExisteArch(Tercero)){
                            printf("El archivo ya existe, desea sobrescribirlo: S=Si N=No\n");
                            Scan(sino);
                            if(Streq(sino,"s") || Streq(sino,"S")){
                                Archivo=fopen(Tercero,"wb");
                                BajarArbol(Archivo,a);
                                fclose(Archivo);
                                printf("Resultado: %s almacenada correctamente en %s\n", Segundo,Tercero);
                            }
                        }else{
                                Archivo=fopen(Tercero,"wb");
                                BajarArbol(Archivo,a);
                                fclose(Archivo);
                                printf("Resultado: %s almacenada correctamente en %s\n", Segundo,Tercero);
                        }
                    }else{
                        printf("ERROR: No ha ingresado un nombre de archivo valido!!\n");
                    }
                }else{
                    printf("ERROR: La expresion no existe!!\n");
                }
            }else{
                printf("ERROR: debe ingresar una expresion del tipo e1,e2,e3,etc!!\n");
            }
           }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
           }
           EliminarArbol(a);
           mark=1;
        }

        ///COMANDO LOAD
        if(Streq(Primero,"load") || Streq(Primero,"LOAD")){
            if(CantStrings(ls)==2){
                DevolverString(Segundo,ls,1);
                if(ValidarArchivo(Segundo)){
                    if(ExisteArch(Segundo))
                {
                    EliminarArbol(b);
                    Archivo=fopen(Segundo,"rb");
                    LevantArbol(Archivo,b);
                    fclose(Archivo);
                    AgregarArbolaLista(le,b);
                    printf("Resultado : ");
                    printf("e%d: ",CantExpresiones(le));
                    MostrArbol(b);
                    printf("\n");
                }else{
                        printf("ERROR: No ha ingresado un nombre de archivo valido!!\n");
                    }

                }else{
                    printf("ERROR: No ha ingresado un nombre de archivo valido!!\n");
                }
            }else{
                printf("ERROR: Cantidad de parametros Incorrecta!!\n");
            }
            mark=1;
        }

        printf("\n");
        if(mark==0)
            printf("ERROR: Usted no ha ingresado ningun comando valido por favor vuelva a intentarlo!\n");
        EliminarListaString(ls);
    }while(!Salir);
}
