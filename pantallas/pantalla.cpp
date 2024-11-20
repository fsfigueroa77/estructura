/*
DESARROLLADOR: FELIPE FIGUEROA CEVALLOS
TEMA: ELABORACION DE PANTALLA
*/

//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
//DECLARACION DE FUNCIONES DE USUARIO
void pantalla_bienvenida();
void marco_personalizado(int col1, int fil1, int col2, int fil2, int cola, int colb);
//CUERPO DEL PROGRAMA
int main()
{
	pantalla_bienvenida();	
	getch();
}
//FUNCIONES DE USUARIO
void pantalla_bienvenida()
{	
	marco_personalizado(0, 0, 160, 40, 3, 4);
	letrare("TRENDXPRESS", 4, 41, 17);
	ct(3); etiqueta("-Innovando la moda con tecnologia-", 'I', 41, 23, 156);
	ct(2); etiqueta("Creado por: Felipe Figueroa Cevallos", 'I', 2, 38, 156);
	ct(3); etiqueta("Presione [ENTER] para continuar...", 'D', 81, 38, 76);
	
}
void marco_personalizado(int col1, int fil1, int col2, int fil2, int cola, int colb)
{
	int colu;
	int fila;
	for(colu = col1; colu < col2; colu++)
	{
		for(fila = fil1; fila < fil2; fila++)
		{
			if(colu == col1 || colu == (col1 + 1) || fila == fil1)
			{
				if(colu < ((col1 + col2 + 1) / 2)  && fila < ((fil1 + fil2) / 2))
				{
					ct(colb);
					poscf(colu, fila); printf("%c",219);
				}
				else
				{
					ct(cola);
					poscf(colu, fila); printf("%c",219);
				}
			}
			if(colu == (col2 - 1) || colu == (col2 - 2) || fila == (fil2 - 1))
			{
				if(colu > ((col1 + col2 - 1) / 2)  && fila > ((fil1 + fil2 - 1) / 2))
				{
					ct(colb);
					poscf(colu, fila); printf("%c",219);
				}
				else
				{
					ct(cola);
					poscf(colu, fila); printf("%c",219);
				}
			}
		}
	}
}

