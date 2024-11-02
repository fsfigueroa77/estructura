/*
Tarea de ecuacion cuadratica Version Final
Hecho por: 
Felipe Figueroa Cevallos
Fuentes
video de youtube: https://www.youtube.com/watch?app=desktop&v=H2BZqEPVKYE
ChatGPT
*/
//LIBRERIAS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdio>
//PROTOTIPO DE FUNCIONES
void ajustar_ventana(int ancho, int alto);
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
//CONSTANTE GLOBAL
int CONT = 4; //variable que da la posicion en 'y' de la cordenada en pantalla
//FUNCION MAIN
int main()
{
	ajustar_ventana(78, 24); //llamada de funcion que regula el tamaño de la ventana de ejecucion
	//DECLARACION DE VARIABLES
	int Coef[3]; //arreglo para los valores de los coeficientes de la ecuacion cuadratica
	bool Repe = true; //variable que controla la repeticion del programa
	float Disc; //variable que representa el discriminante de la formula general
    float Sol1; //solucion real 1
    float Sol2; //solucion real 2
    float Srea; //parte real solucion 1 y 2 NUEVA VERSION CON NUMEROS IMAGINARIOS
    float Sima; //parte imaginaria solucion 1 y 2 imaginaria NUEVA VERSION CON NUMEROS IMAGINARIOS    
	//DESARROLLO DEL PROGRAMA
	while(Repe)
	{	
		presentacion();
		ingreso_valores(Coef);
		operaciones(Coef, Disc, Sol1, Sol2);
		operaciones_imaginarias(Coef, Disc, Srea, Sima); //NUEVA VERSION CON NUMEROS IMAGINARIOS
		impresion_resultados(Disc, Sol1, Sol2, Srea, Sima, Coef);
		repeticion(Repe);		
	}
	return(0);
}
//DESARROLLO DE FUNCIONES
void ajustar_ventana(int ancho, int alto) //funcion Fuente: ChatGPT
{
    // Obtiene el identificador de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);    
    // Ajusta el tamaño del búfer de pantalla
	COORD bufferSize;
    bufferSize.X = ancho + 1;  //Agrega 1 para evitar desplazamiento
    bufferSize.Y = alto + 1;
    SetConsoleScreenBufferSize(hConsola, bufferSize);    
    // Ajusta el tamaño de la ventana
    SMALL_RECT windowSize = {0, 0, ancho, alto};
    SetConsoleWindowInfo(hConsola, TRUE, &windowSize);
}
void presentacion() //funcion que controla el aspecto grafico del programa
{
	system("cls"); //limpia el contenido de la ventana de ejecucion
	system("color E0"); //regula el color de fondo (E = amarillo claro) y el color de fuente (0 = Negro). Fuente Video de youtube: https://www.youtube.com/watch?app=desktop&v=H2BZqEPVKYE
	cuadro(0, 0, 78, 24); //imprime un marco grande
	cuadro(1, 1, 77, 3); //imprime un marco pequeño
	gotoxy(10, 2); printf("PROGRAMA PARA OBTENER LAS RAICES DE UNA ECUACION CUADRATICA\n"); 
}
void ingreso_valores(int (&coef)[3]) //funcion que pide al usuario los valores de los coeficientes. Usa paso de por referencia del arreglo de coeficientes
{
	CONT = 4; //Reseteo de la variable global
	gotoxy(2, ++CONT); printf("Ax^2 + Bx + C = 0\n");
	char letr[3] = {'A', 'B', 'C'}; //arreglo que contiene las letras de los coeficientes
	char auxi[10]; //arreglo retine temporalmente los valores, en forma de cadena, ingresados por el usuario
	gotoxy(2, ++CONT); printf("Ingrese valores enteros para los coeficientes:\n");	
	for(int i = 0; i < 3; i++)
	{
		bool veri = true; //variable que controla el ciclo while
		while(veri)
		{
			gotoxy(2, ++CONT); printf("%c = ", letr[i]);
			gets(auxi);
			if(verificacion(auxi))
			{
				coef[i] = atoi(auxi);
				veri = false; //finalizacion del ciclo while
			}
			else
			{
				gotoxy(2, ++CONT); printf("Ingreso no valido. Intente nuevamente.\n");
			}
		}
	}
}
void operaciones(int (&coef)[3], float &disc, float &sol1, float &sol2) //funcion que hace las operaciones de la formula general
{
    //CALCULO DEL DISCRIMINANTE
    disc = pow(coef[1], 2) - (4 * coef[0] * coef[2]);
    //CALCULO DE LAS SOLUCIONES
    sol1 = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
    sol2 = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
}
void operaciones_imaginarias(int (&coef)[3], float &disc, float &srea, float &sima) //funcion que hace las operaciones cuando el discrimiante es negativo y por lo tanto las soluciones entran en el campo de los numeros complejos
{
	srea = (-1.0f * coef[1]) / (2.0f * coef[0]); //Porque el 1.0f y 2.0f? Solucion obtenida en ChatGPT
	sima = (sqrt(-disc)) / (2 * coef[0]);	
}
void impresion_resultados(float &disc, float &sol1, float &sol2, float &srea, float &sima, int (&coef)[3]) //funcion que imprime por pantalla las soluciones de la ecuacion sean reales o imaginarias
{
    CONT = 4; //Reseteo de la variable global
	presentacion();	
	gotoxy(2, ++CONT); printf("La ecuacion %sx^2 %sx %s = 0\n", imprimir_coeficiente(coef[0]), imprimir_coeficiente(coef[1]), imprimir_coeficiente(coef[2]));
	if(disc < 0)
    {
        gotoxy(2, ++CONT); printf("No tiene soluciones en los numeros reales.");
        gotoxy(2, ++CONT); printf("x_1 = %.2f + %.2fi", srea, sima);
        gotoxy(2, ++CONT); printf("x_2 = %.2f - %.2fi", srea, sima);
    }
    else if(disc == 0)
    {
        gotoxy(2, ++CONT); printf("Tiene solamente una solucion real.");
        gotoxy(2, ++CONT); printf("x = %.2f", sol1);
    }
    else if(coef[0] == 0)
    {
    	gotoxy(2, ++CONT); printf("No es cuadratica (A no debe ser igual a 0).");
	}
    else
    {
        gotoxy(2, ++CONT); printf("Tiene dos soluciones reales distintas.");
        gotoxy(2, ++CONT); printf("x_1 = %.2f", sol1);
        gotoxy(2, ++CONT); printf("x_2 = %.2f", sol2);
    }
    free(imprimir_coeficiente(coef[0])); //Fuente: ChatGPT
    free(imprimir_coeficiente(coef[1])); //Fuente: ChatGPT
    free(imprimir_coeficiente(coef[2])); //Fuente: ChatGPT
    gotoxy(2, 23); printf("Presione [ENTER] para continuar...");
    getche();
}
void repeticion(bool &repe) //funcion que pregunta al usuario si se desea salir o ingresar otra ecuacion
{
	CONT = 4; //Reseteo de la variable global
	presentacion();
	char auxi[3]; //variable auxiliar 
	int nume = 0; //variable que habilita la entrada al ciclo while de la siguietne linea
	while(nume < 1 || nume > 2)
	{
		gotoxy(2, ++CONT); printf("Desea ingresar una nueva ecuacion.");
		gotoxy(2, ++CONT); printf("[1] Si");
		gotoxy(2, ++CONT); printf("[2] No");
		gotoxy(2, ++CONT); printf("Elija una opcion: ");
		gets(auxi); //funcion que recepta lo que el usuario ingresa por teclado y lo guarda en la variable del parametro(auxi)
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
void cuadro(int x1,int y1,int x2,int y2) //Fuente Video de youtube: https://www.youtube.com/watch?app=desktop&v=H2BZqEPVKYE
{
	int i;
	
	for (i=x1;i<x2;i++)
	{
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
	}	
	for (i=y1;i<y2;i++)
	{
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}	
	gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
void gotoxy(int x,int y) //Fuente Video de youtube: https://www.youtube.com/watch?app=desktop&v=H2BZqEPVKYE
{  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
bool verificacion(char *cade) //Fuente: ChatGPT
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
char* imprimir_coeficiente(int coef) //funcion que muestra en la pantalla los coeficientes incluidos dentro de la ecuacion cuadratica
{
	char* resultado = (char*)malloc(12); //malloc() consultada en ChatGPT
	if(coef < 0)
	{
		sprintf(resultado, "- %d", -coef); //sprintf() consultada en ChatGPT
		return(resultado);
	}
	else
	{
		sprintf(resultado, "+ %d", coef); //sprintf() consultada en ChatGPT
		return(resultado);
	}
}

