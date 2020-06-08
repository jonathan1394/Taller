#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>
#include "Boolean.h"
const int MAX = 80;
typedef char * string;

//Precondicion: s debe existir
void Strcrear (string &s);
/*Crea un String vacio*/

//Precondicion: s debe existir
void Strdestruir (string &s);
/*destrulle un string*/

//Precondicion: s debe existir
int Strlar (string s);
/*DEVUELVE LARGO DEL STRING*/

//Precondicion: s debe existir
void Print (string s);
/*IMPRIME EL STRING POR PANTALLA*/
void Scan (string &s);
/*LEE EL STRING DESDE TECLADO*/

boolean Streq (string s1, string s2);
/*DETERMINA SI STRRINGS S1 Y S2 SON IGUALES*/

//Precondicion: s1 y s2 deben existir
void Strcop (string &s1, string s2);
/*COPIA CONTENIDO DEL STRING S2 EN S1*/
void Strcon (string &s1, string s2);
/*CONCATENA EL CONTENIDO DE S2 AL FINAL DE S1*/
boolean NoEsNumero (string s);
/*VERIFICA SI EL STRING NO ES NUMERO*/
int ConvertirInt (string s);
/*CONVIERTE STRING A INT*/
void ConvertirString (int num, string &s);
/*CONVIERTE int a string*/
boolean ValidarExpresion(string s);
/*VALIDA SI EXPRESION ES VALIDA *e1*e2*e3*/
boolean EsNumero(char c);
//indica si un Char puede ser transformado a int

//Precondicion: s debe existir y debe estar cargado
boolean ValidarArchivo(string s);
/*VALIDA SI ES NOMBREARCHIVO.DAT*/
int posicionPunto(string s);
//retorna la pocicion de un punto
void Strcut(string &s1,string s2, int ini, int fin);
// corta un string desde un inicio y final.
void Strcortar(string &s1,string s2, int num);
//crea un string partido
boolean AlfaNumerico(string s);
/*VALIDA SI EL STRING ES ALFANUMERICO*/
boolean ArchivoVacio (string nomArch);
/*VERIFICA SI EL ARCHIVO ES VACIO DEVUELVVE T O F*/
boolean ExisteArch (string nomArch);
/*VERIFICA SI EXISTE EL ARCHIVO DEVUELVVE T O F*/
#endif // STRING_H_INCLUDED
