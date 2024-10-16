/*ARCHIVOS CABECERA*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
/*DECLARACION DE FUNCIONES DE USUARIO*/
void poscf(int colu, int fila);
/*CUERPO DEL PROGRAMA*/
int main()
{
	int cont=0;
	int fila=20;
	int colu=0;
	int valo=1;
	while(cont<160)
	{
		poscf(colu,fila),printf("*");
		colu++;
		fila=fila+valo;
		if(fila==36)
			valo=-1;
		if(fila==5)
			valo=1;			
		cont++;
	}
	getch();
}
/******************************************
******DESARROLLO DE FUNCION DE USUARIO*****
*******************************************/
/*ESTA FUNCION PERMITE UBICAR EL TEXTO EN UNA
PARTE ESPECIFICA */
void poscf(int colu, int fila)
{
	COORD coord;
	coord.X = colu;
	coord.Y = fila;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*EL ARCHIVO CABECERA WINDOWS.H EN ESTE PROGRAMA PERMITE
RECONOCER LA STRUCTURA COOD DE BUFER DE PANTALLA DE CONSOLA EN
COORDENADAS (0,0)
typedef struct _COORD {
  SHORT X;
  SHORT Y;
} COORD;
EL ARCHIVO CABECERA STDIO.H APERTURA LA FUNCIONE LA FUNCION 
DE PROGRAMA PRINTF() QUE ES LA QUE PERMITE PRESENTAR INFORMACION
POR PANTALLA
EL ARCHIVO CABECERA CONIO.H APERTURA LA FUNCIONE LA FUNCION 
DE PROGRAMA GETTCH() QUE PERMITE INFRESAR UN CARACTER NO VISIBLE
Y ME PERMITE SIMULAR LA RETENCION DE PANTALLA*/
