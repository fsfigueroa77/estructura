/*PROGRAMADOR: FELIPE SANTIAGO FIGUEROA 
TEMA: SE PIDE REALIZAR UN PROGRAMA QUE PERMITA VISUALIZAR LOS VALORES DE
LAS RAICES DE UNA ECUACION CUADRATICA, CALCULADO POR MEDIO DE LA ECUACION CUADRATICA.*/
//ARCHIVOS CABECERAS
#include <stdio.h>
#include <conio.h>
#include <windows.h> //CABECERA QUE CONTIENE LA FUNCION SETCONSOLETITLE
#include <rosian.h>
//DEFINICION DE CONSTANTE

//DECLARACION DE FUNCIONES DE USUARIO
void ajustar_ventana(int ancho, int alto);
void pantalla_bienvenida();
void pantalla_calculos();
void ingreso_valores();
int verificacion_coeficiente(int colu);
//CUERPO DEL PROGRAMA
int main()
{    
	SetConsoleTitle("FELIPE SANTIAGO FIGUEROA CEVALLOS"); //FUNCION DE PROGRAMA COLOCA UN TEXTO PERSONALIZADO EN LA BARRA DE TITULO
    ajustar_ventana(78, 24);
	pantalla_bienvenida();
	pantalla_calculos();
    return(0);
}
//DESARROLLO DE LAS FUNCIONES DE USUARIO
void ajustar_ventana(int anch, int alt) //AJUSTA EL TAMANIO DE LA PANTALLA DE EJECUCION
{
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = anch + 1;
    bufferSize.Y = alt + 1;
    SetConsoleScreenBufferSize(hConsola, bufferSize);
    SMALL_RECT windowSize = {0, 0, anch, alt};
    SetConsoleWindowInfo(hConsola, TRUE, &windowSize);
}
void pantalla_bienvenida()
{    
	marco3l(1, 1, 77, 23, 1, 9, 10, 11);
    marcolg(0, 0, 78, 24);
    etiqueta("UNIVERSIDAD DE GUAYAQUIL", 'C', 0, 9, 77);
    etiqueta("FACULTAD DE CIENCIAS MATEMATICAS Y FISICAS", 'C', 0, 10, 78);
    etiqueta("TECNOLOGIA DE LA INFORMACION", 'C', 0, 11, 78);
    etiqueta("FELIPE SANTIAGO FIGUEROA CEVALLOS", 'C', 0, 12, 78);
    etiqueta("SEGUNDO SEMESTRE", 'C', 0, 13, 78);
    etiqueta("TIN-S-VE-2-9", 'C', 0, 14, 78);
    etiqueta("Presionar [ENTER] para ingresar al programa...", 'D', 0, 20, 74);
    getch();
}
void pantalla_calculos()
{	
	bp(0);
	marco3l(1, 1, 77, 23, 1, 9, 10, 11);
	marcolg(0, 0, 78, 24);
	marcold(4, 4, 74, 8);
	marcold(4, 9, 74, 20);
	etiqueta("PROGRAMA PARA OBTENER LAS RAICES DE UNA ECUACION CUADRATICA", 'C', 0, 6, 77);
	etiqueta("Ingrese valores enteros entre 1 y 99 para los coeficientes:", 'I', 5, 11, 78);
	marcols(18, 13, 23, 15);
	etiqueta("A", 'I', 21, 16, 3);
	etiqueta("x^2", 'I', 24, 14, 3);
	etiqueta("+", 'I', 30, 14, 1);
	marcols(37, 13, 42, 15);
	etiqueta("B", 'I', 40, 16, 1);
	etiqueta("x", 'I', 43, 14, 1);
	etiqueta("+", 'I', 49, 14, 1);
	marcols(56, 13, 61, 15);
	etiqueta("C", 'I', 58, 16, 1);	
	etiqueta("=0", 'I', 62, 14, 2);
	ingreso_valores();
}
void ingreso_valores()
{	
	int coef[3]; //ARREGLO DE COEFICIENTES
	int colu = 20;
	for(int reco = 0; reco < 3; reco++)
	{
		poscf(colu, 14);
		coef[reco] = verificacion_coeficiente(colu);
		colu += 19; // CORREGIR ESTE VALOR
	}
}
int verificacion_coeficiente(int colu)
{
	char auxi[3];
	bool veri = true;
	int Coef;
	while(veri)
	{
		gets(auxi);
		Coef = atoi(auxi);
		if(Coef < 1 || Coef > 99)
		{
			etiqueta("  ", 'I', colu, 14, 2);
			etiqueta("Valor no valido, intente nuevamente.", 'C', 5, 19, 68);
			poscf(colu, 14);
		}
		else
		{
			veri = false;			
			return(Coef);
		}
	}
	//operaciones
}
/*
void operaciones()
{
	float disc =
}
*/
