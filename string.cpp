#include "string.h"

void strcrear(string &s)
{
    s = new char[1];
    s[0]='\0';
}

void strdestruir(string &s)
{
    delete[] s;
    s = NULL;
}

int strlar(string s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}

void strcop(string &s1, string s2)
{
    int largo = strlar(s2);
    delete[] s1;
    s1 = new char [largo + 1];
    int i=0;
    while(s2[i] != '\0')
    {
        s1[i]= s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan(string &s)
{
    string aux;
    char letra;
    int i = 0;
    aux = new char[MAX-1];
    fflush(stdin);
    scanf("%c", &letra);
    while((letra != '\n')&&(i < MAX - 1)){
        aux[i] = letra;
        i++;
        scanf("%c",&letra);
    } aux[i]='\0';

    strcop(s, aux);
    delete [] aux;
}

void print(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c", s[i]);
        i++;
    }
}

void eliminarString(string &str) {
    delete[] str;
    str = NULL;
}

int tamanioString(string str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void copiarString(string str, string &copia) {
    eliminarString(copia);
    copia = new char[tamanioString(str)];
    int i = 0;
    while (str[i] != '\0') {
        copia[i] = str[i];
        i++;
    }
    copia[i] = '\0';
}

void escribirString(string s, FILE * archivo) {
    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, archivo);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, archivo);
}

void leerString(string &s, FILE * archivo) {
    string aux = new char[MAX];

    int i = 0;

    fread(&aux[i], sizeof(char), 1, archivo);
    while (aux[i] != '\0') {
        i++;
        fread(&aux[i], sizeof(char), 1, archivo);
    }
    copiarString(aux, s);
    eliminarString(aux);
}
