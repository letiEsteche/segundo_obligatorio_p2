#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"

const int MAX = 80;
typedef char*string;

//strcrear crea un string vacío (solo con el carácter ‘\0’)
void strcrear(string &s);


//strdestruir libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(string &s);

//strcop recibe dos strings y copia el segundo en el primero.
void strcop(string &s1, string s2);

//strlar devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes
//del carácter nulo.
int strlar(string s);

//scan lee un string desde el teclado. Se tomarán en cuenta los primeros 79 caracteres
//significativos en caso de que el largo del string sea mayor o igual a 80. Un string
//finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.
void scan(string &s);

//print despliega un string por pantalla.
void print(string s);

void eliminarString(string &str);

int tamanioString(string str);

void copiarString(string str, string &copia);

void escribirString(string s, FILE * archivo);

void leerString(string &s, FILE * archivo);


#endif // STRING_H_INCLUDED
