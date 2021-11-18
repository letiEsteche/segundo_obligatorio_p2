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
