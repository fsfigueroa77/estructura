/*
DESARROLLADOR: FELIPE SANTIAGO FIGUEROA CEVALLOS
TEMA: ELABORACION DE MENU DE OPCIONES
*/
//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
//DECLARACION DE FUNCIONES DE USUARIO
void interfaz();
void seleccion();
int validacion(int mini, int maxi);
int validacion();
void marco_personalizado(int col1, int fil1, int col2, int fil2, int cola, int colb);
//DECLARACION DE VARIABLES
const int COLI = 0; //COLUMNA INICIAL
const int FILI = 0; //FILA INICIAL
const int COLF = 159; //COLUMNA FINAL
const int FILF = 39; //FILA FINAL
const int AMAR = 3; //COLOR AMARILLO
const int AZUL = 4; //COLOR AZUL
const int BLAN = 7; //COLOR BLANCO
//CUERPO DEL PROGRAMA
int main()
{
	system("title MENU PRINCIPAL");
	system("mode con: cols=160 lines=40");
	interfaz();
	seleccion();
}
//FUNCIONES DE USUARIO
void interfaz()
{
	//DECLARACION DE VARIABLES LOCALES
	int foYI = 0;
	int foXI = 0;
	int foYF = 159;
	int foXF = 39;
	//DIBUJADO DE MARCOS
	marco_personalizado(COLI, FILI, COLF, FILF, AMAR, AZUL);
	while(foXI < 7)
	{
		marco_personalizado(foYI += 2, foXI += 1, foYF -= 2, foXF -= 1, BLAN, BLAN);
	}
	while(foYI < 28)
	{
		marco_personalizado(foYI += 2, foXI, foYF -= 2, foXF, BLAN, BLAN);
	}
	marco_personalizado(COLI + 30, FILI + 8, COLF - 30, FILF - 8, AZUL, AMAR);
	ct(BLAN);
	marcold(COLI + 65, FILI + 10, COLF - 65, FILI + 12);
	marcols(COLI + 55, FILI + 14, COLF - 55, FILI + 25);
	etiqueta("MENU PRINCIPAL", 'C', 0, 11, 160);
	etiqueta("Transaccion............................[1]", 'C', 0, 16, 160);
	etiqueta("Mantenimiento con arreglo..............[2]", 'C', 0, 17, 160);
	etiqueta("Mantenimiento con lista................[3]", 'C', 0, 18, 160);
	etiqueta("Consultas..............................[4]", 'C', 0, 19, 160);
	etiqueta("Salir del programa.....................[0]", 'C', 0, 20, 160);
	etiqueta("Elija la opcion: ", 'C', 0, 22, 160);
}
void seleccion()
{
	int opci = 0;
	while(opci == 0)
	{
		poscf(88, 22);
		opci = validacion(0, 4);
		switch(opci)
		{
			case 1:
				//system("transaccion.exe"); CODIGO DESHABILITADO POR FALTA DE ARCHIVO
				break;
			case 2:
				//system("mantenimiento con arreglo.exe"); CODIGO DESHABILITADO POR FALTA DE ARCHIVO
				break;
			case 3:
				//system("mantenimiento con lista.exe"); CODIGO DESHABILITADO POR FALTA DE ARCHIVO
				break;
			case 4:
				//system("consultas.exe"); CODIGO DESHABILITADO POR FALTA DE ARCHIVO
				break;
			case 0:
				etiqueta("Realmente desea salir del programa? [S/N]: ", 'C', 0, 23, 160);
				opci = validacion();				
				break;
		}
		if(opci == 0)
		{
			etiqueta("                                             ", 'C', 0, 23, 160);
			poscf(88, 22); printf(" ");
		}	
	}
}
int validacion(int mini, int maxi) //VALIDACION DE UN RANO DE NUMEROS
{
	int auxi = -1; 
	char cara = 0;	
	while(auxi < mini || auxi > maxi)
	{
		cara = getch();
		auxi = cara - '0';
	}
	printf("%d", auxi);
	return(auxi);
}
int validacion() //VALIDACION DE SI O NO
{
	int auxi = 0;
	char cara = 0;
	while(cara !=  's' && cara !=  'n' && cara !=  'S' && cara !=  'N')
	{
		cara = toupper(getch());		
	}
	printf("%c", cara);
	if(cara == 'S')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void marco_personalizado(int col1, int fil1, int col2, int fil2, int cola, int colb)
{
	int colu;
	int fila;
	for(colu = col1; colu <= col2; colu++)
	{
		for(fila = fil1; fila <= fil2; fila++)
		{
			if(((colu == col1 || colu == col1 + 1) && (fila < ((fil1 + fil2 + 1) / 2))) || ((fila == fil1) && colu < ((col1 + col2 + 1) / 2)) || ((colu == col2 || colu == col2 - 1) && (fila >= ((fil1 + fil2 + 1) / 2))) || ((fila == fil2) && (colu >= ((col1 + col2 + 1) / 2))))
			{
				ct(cola);
				poscf(colu, fila); printf("%c",219);
			}
			if(((colu == col1 || colu == col1 + 1) && (fila >= ((fil1 + fil2 + 1) / 2))) || ((fila == fil1) && colu >= ((col1 + col2 + 1) / 2)) || ((colu == col2 || colu == col2 - 1) && (fila < ((fil1 + fil2 + 1) / 2))) || ((fila == fil2) && (colu < ((col1 + col2 + 1) / 2))))
			{
				ct(colb);
				poscf(colu, fila); printf("%c",219);
			}
		}
	}
}
