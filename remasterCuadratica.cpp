/*PROGRAMADOR: FELIPE SANTIAGO FIGUEROA 
TEMA: SE PIDE REALIZAR UN PROGRAMA QUE PERMITA VISUALIZAR LOS VALORES DE
LAS RAICES DE UNA ECUACION CUADRATICA, CALCULADO POR MEDIO DE LA ECUACION CUADRATICA.*/
//ARCHIVOS CABECERAS
#include <stdio.h>
#include <conio.h>
#include <windows.h> //CABECERA QUE CONTIENE LA FUNCION SETCONSOLETITLE
#include <rosian.h>
//DEFINICION DE CONSTANTE

//DECLARACION DE DATOS

//DECLARACION DE FUNCIONES DE USUARIO
void ajustar_ventana(int ancho, int alto);
void pantalla_bienvenida();
//CUERPO DEL PROGRAMA
int main()
{
    SetConsoleTitle("FELIPE SANTIAGO FIGUEROA CEVALLOS"); //FUNCION DE PROGRAMA COLOCA UN TEXTO PERSONALIZADO EN LA BARRA DE TITULO
    ajustar_ventana(78, 24);
	pantalla_bienvenida();
    return(0);
}
//DESARROLLO DE LAS FUNCIONES DE USUARIO
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
void pantalla_bienvenida()
{
    marcoli(0, 0, 78, 24, 178);
}
