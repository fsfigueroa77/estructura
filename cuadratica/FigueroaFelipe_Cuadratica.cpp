//LIBRERIAS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
//PROTOTIPO DE FUNCIONES
void ingreso_coeficientes(int& coea, int& coeb, int& coec);
void operaciones(int& coea, int& coeb, int& coec, float& disc, float& sol1, float& sol2);
void impresion_resultados(float& disc, float& sol1, float& sol2);
//FUNCION MAIN
int main()
{
    //DECLARACION DE VARIABLES
    int Coea = 0; //coeficiente "a"
    int Coeb = 0; //coeficiente "b"
    int Coec = 0; //coeficiente "c"
    float Disc = 0; //discriminante
    float Sol1 = 0; //solucion 1
    float Sol2 = 0; //solucion 2
    //DECLARACION DE FUNCIONES
    ingreso_coeficientes(Coea, Coeb, Coec);
    operaciones(Coea, Coeb, Coec, Disc, Sol1, Sol2);
    impresion_resultados(Disc, Sol1, Sol2);
    
    printf("ax^2 + bx + c = 0");
    
    return(0);
}

//DESARROLLO DE FUNCIONES

void ingreso_coeficientes(int& coea, int& coeb, int& coec)
{
    int auxi = 0;
    //INGRESO DEL VALOR DE "A"
    printf("\nIngrese el valor del coeficiente a: ");
    gets(auxi);
    coea = atoi(auxi);
    //INGRESO DEL VALOR DE "B"
    printf("\nIngrese el valor del coeficiente b: ");
    gets(auxi);
    coeb = atoi(auxi);
    //INGRESO DEL VALOR DE "C"
    printf("\nIngrese el valor del coeficiente c: ");
    gets(auxi);
    coec = atoi(auxi);
}

void operaciones(int& coea, int& coeb, int& coec, float& disc, float& sol1, float& sol2)
{
    //CALCULO DEL DISCRIMINANTE
    float disc = sqrt( pow(coeb, 2) - (4 * coea * coec) );
    //CALCULO DE LAS SOLUCIONES
    float sol1 = (-num2 - disc) / (2 * num1);
    float sol2 = (-num2 + disc) / (2 * num1);
}

void impresion_resultados(float& disc, float& sol1, float& sol2)
{
    if(disc == 0){
        
    }
    printf("\nLas soluciones de la ecuacion es: ");
    printf("\nx_1 = ");
    printf("\nx_2 = ");
}
