/*
DESARROLLADOR: FELIPE FIGUEROA CEVALLOS
TEMA: PROGRAMA QUE PIDE LOS COEFICIENTES DE UNA ECUACION CUADRATICA Y MUESTRA SUS RAICES
*/
//ARCHIVOS CABECERA
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdio>
//PROTOTIPO DE FUNCIONES
void ajustar_ventana(int ancho, int alto);
void pantalla_bienvenida();
void presentacion();
void ingreso_valores(int (&coef)[3]);
void operaciones(int (&coef)[3], float &disc, float &sol1, float &sol2);
void operaciones_imaginarias(int (&coef)[3], float &disc, float &srea, float &sima);
void impresion_resultados(float &disc, float &sol1, float &sol2, float &srea, float &sima, int (&coef)[3]);
void repeticion(bool &repe);
void cuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
bool verificacion(char *cade);
char* imprimir_coeficiente(int coef);
void despedida();
//CONSTANTE GLOBAL
int CONT = 4; //VARIABLE QUE DA LA POSICION en 'y' de la cordenada en pantalla
//FUNCION MAIN
int main()
{
	SetConsoleTitle("FELIPE SANTIAGO FIGUEROA CEVALLOS");
	ajustar_ventana(78, 24);
	pantalla_bienvenida();
	//DECLARACION DE VARIABLES
	int Coef[3];
	bool Repe = true;
	float Disc;
    float Sol1;
    float Sol2;
    float Srea;
    float Sima; 
	//DESARROLLO DEL PROGRAMA
	while(Repe)
	{	
		presentacion();
		ingreso_valores(Coef);
		operaciones(Coef, Disc, Sol1, Sol2);
		operaciones_imaginarias(Coef, Disc, Srea, Sima);
		impresion_resultados(Disc, Sol1, Sol2, Srea, Sima, Coef);
		repeticion(Repe);		
	}
	despedida();
	return(0);
}
//DESARROLLO DE FUNCIONES
void pantalla_bienvenida()
{
	system("color 9E");
	cuadro(0, 0, 78, 24);
	cuadro(16, 7, 61, 16);
	gotoxy(27, 9); printf("UNIVERSIDAD DE GUAYAQUIL");
	gotoxy(18, 10); printf("FACULTAD DE CIENCIAS MATEMATICAS Y FISICAS");
	gotoxy(25, 11); printf("TECNOLOGIA DE LA INFORMACION");
	gotoxy(23, 12); printf("FELIPE SANTIAGO FIGUEROA CEVALLOS");
	gotoxy(31, 13); printf("SEGUNDO SEMESTRE");
	gotoxy(33, 14); printf("TIN-S-VE-2-9");
	gotoxy(43, 23); printf("Presione [ENTER] para continuar...");
	getch();
}
void ajustar_ventana(int ancho, int alto) //AJUSTA EL TAMANIO DE LA PANTALLA DE EJECUCION
{
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);    
    COORD bufferSize;
    bufferSize.X = ancho + 1;
    bufferSize.Y = alto + 1;
    SetConsoleScreenBufferSize(hConsola, bufferSize);
    SMALL_RECT windowSize = {0, 0, ancho, alto};
    SetConsoleWindowInfo(hConsola, TRUE, &windowSize);
}
void presentacion() //FUNCION QUE DA DISENIO AL PROGRAMA
{
	system("cls");
	system("color E0");
	cuadro(0, 0, 78, 24);
	cuadro(1, 1, 77, 3);
	gotoxy(10, 2); printf("PROGRAMA PARA OBTENER LAS RAICES DE UNA ECUACION CUADRATICA\n"); 
}
void ingreso_valores(int (&coef)[3]) //FUNCION QUE PIDE LOS VALORES DE LOS COEFICIENTES DE LA ECUACION CUADRATICA
{
	CONT = 4;
	gotoxy(2, ++CONT); printf("Ax^2 + Bx + C = 0\n");
	char letr[3] = {'A', 'B', 'C'};
	char auxi[10];
	gotoxy(2, ++CONT); printf("Ingrese valores enteros para los coeficientes:\n");	
	for(int i = 0; i < 3; i++)
	{
		bool veri = true;
		while(veri)
		{
			gotoxy(2, ++CONT); printf("%c = ", letr[i]);
			gets(auxi);
			if(verificacion(auxi))
			{
				coef[i] = atoi(auxi);
				veri = false;
			}
			else
			{
				gotoxy(2, ++CONT); printf("Ingreso no valido. Intente nuevamente.\n");
			}
		}
	}
}
void operaciones(int (&coef)[3], float &disc, float &sol1, float &sol2) //FUNCION QUE REALIZA LAS OPERACIONES DE LA FORMULA GENERAL SI EL DISCRIMINANTE ES MAYOR O IGUAL A 0
{
    //CALCULO DEL DISCRIMINANTE
    disc = pow(coef[1], 2) - (4 * coef[0] * coef[2]);
    //CALCULO DE LAS SOLUCIONES
    sol1 = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
    sol2 = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
}
void operaciones_imaginarias(int (&coef)[3], float &disc, float &srea, float &sima) //FUNCION QUE REALIZA LAS OPERACIONES DE LA FORMULA GENERAL SI EL DISCRIMINANTE ES MENOR QUE 0
{
	srea = (-1.0f * coef[1]) / (2.0f * coef[0]);
	sima = (sqrt(-disc)) / (2 * coef[0]);	
}
void impresion_resultados(float &disc, float &sol1, float &sol2, float &srea, float &sima, int (&coef)[3]) //FUNCION QUE MUESTRA LOS RESULTADOS DE LOS CALCULOS
{
    CONT = 4;
	presentacion();	
	gotoxy(2, ++CONT); printf("La ecuacion %sx^2 %sx %s = 0\n", imprimir_coeficiente(coef[0]), imprimir_coeficiente(coef[1]), imprimir_coeficiente(coef[2]));
	if(disc < 0)
    {
        gotoxy(2, ++CONT); printf("Raices diferentes X1 <> X2");
        gotoxy(2, ++CONT); printf("X1 = %.2f + %.2fi", srea, sima);
        gotoxy(2, ++CONT); printf("X2 = %.2f - %.2fi", srea, sima);
    }
    else if(disc == 0)
    {
        gotoxy(2, ++CONT); printf("Raices Iguales X1=X2");
        gotoxy(2, ++CONT); printf("X = %.2f", sol1);
    }
    else if(coef[0] == 0)
    {
    	gotoxy(2, ++CONT); printf("No es cuadratica (A no debe ser igual a 0).");
	}
    else
    {
        gotoxy(2, ++CONT); printf("Raices Imaginaria");
        gotoxy(2, ++CONT); printf("X1 = %.2f", sol1);
        gotoxy(2, ++CONT); printf("X2 = %.2f", sol2);
    }
    free(imprimir_coeficiente(coef[0]));
    free(imprimir_coeficiente(coef[1]));
    free(imprimir_coeficiente(coef[2]));
    gotoxy(2, 23); printf("Presione [ENTER] para continuar...");
    getche();
}
void repeticion(bool &repe) //FUNCION QUE PREGUNTA AL USUARIO SI SE REPETIRA EL PROGRAMA O NO
{
	CONT = 4;
	presentacion();
	char auxi[3];
	int nume = 0;
	while(nume < 1 || nume > 2)
	{
		gotoxy(2, ++CONT); printf("Desea ingresar una nueva ecuacion.");
		gotoxy(2, ++CONT); printf("[1] Si");
		gotoxy(2, ++CONT); printf("[2] No");
		gotoxy(2, ++CONT); printf("Elija una opcion: ");
		gets(auxi);
		nume = atoi(auxi);
		if(nume < 1 || nume > 2)
		{
			gotoxy(2, ++CONT); printf("Opcion no valida. Elija nuevamente.");
		}		
	}
	if(nume == 1)
	{
		repe = true;
	}
	else
	{
		repe = false;
	}	
}
void cuadro(int x1,int y1,int x2,int y2) //FUNCION QUE IMPRIME UN CUADRO
{
	int i;
	
	for (i=x1;i<x2;i++)
	{
		gotoxy(i,y1); printf("\304");
		gotoxy(i,y2); printf("\304");
	}	
	for (i=y1;i<y2;i++)
	{
		gotoxy(x1,i); printf("\263");
		gotoxy(x2,i); printf("\263");
	}	
	gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
void gotoxy(int x,int y) //FUNCION QUE TRASLADA EL CURSOR A LA UBICACION MARCADA POR LAS CORDENADAS DE LOS VALORES QUE SE PASAN COMO PARAMETROS
{  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
bool verificacion(char *cade) //FUNCION QUE VALIDA SI LO INGRESADO HA SIDO UN NUMERO
{
	bool veri = true;
	int i = 0;
	if(cade[0] == '-')
	{
		i = 1;
	}	
	for(i; cade[i] != '\0'; i++)
	{
		if(!isdigit(cade[i]))
		{
			veri = false;
			break;
		}
	}	
	return(veri);
}
char* imprimir_coeficiente(int coef) //FUNCION QUE MUESTRA DENTRO DE LA ECUACION LOS VALORES DE LOS COEFICIENTES LUEGO DE HABERLOS INGRESADO
{
	char* resultado = (char*)malloc(12);
	if(coef < 0)
	{
		sprintf(resultado, "- %d", -coef);
		return(resultado);
	}
	else
	{
		sprintf(resultado, "+ %d", coef);
		return(resultado);
	}
}
void despedida() //FUNCION QUE IMPRIME UN MENSAJE DE DESPEDIDA
{
	system("cls");
	system("color 9E");
	cuadro(0, 0, 78, 24);
	gotoxy(25, 12); printf("GRACIAS POR USAR EL PROGRAMA");
	getch();
}
