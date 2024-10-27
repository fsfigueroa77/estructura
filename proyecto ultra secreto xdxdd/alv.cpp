//ARCHIVOS CABECERA
#include <stdio.h>
#include <windows.h>
//PROTOTIPO DE FUNCIONES
void ajustar_ventana(int ancho, int alto);
//CUERPO DEL PROGRAMA
int main()
{
	ajustar_ventana(50, 50);
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
