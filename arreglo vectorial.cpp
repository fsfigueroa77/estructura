/*
DESARROLLADOR: FELIPE FIGUEROA CEVALLOS
TEMA: SE PIDE REALIZAR UN PROGRAMA PERMITA LLENAR UN ARREGLO BIDIMENSIONAL DE CADENA QUE TENGA
10 FILAS Y 2 COLUMNAS Y EN LA PRIMERA COLUMNA SE INGRESE EL NOMBRE Y EN LA SEGUNDA COLUMNA 
EL APELLIDO DE LOS ESTUDIANTES DE LA CARRERA DE TECNOLOGIA DE LA INFORMACION.
*/
//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
#include <string.h>
//DECLARACION DE FUNCIONES DE USUARIO
void interfaz();
void pantalla_bienvenida();
void pantalla_ingreso();
void pantalla_presentacion();
void ingreso_estudiantes();
void mostrar_estudiantes();
void borrar_pantalla(int iniF, int iniC, int finF, int finC);
//DECLARACION DE VARIABLES
const int FILA = 10;
const int COLU = 2;
const int PROF = 20;
char NOMB[FILA][COLU][PROF];
//CUERPO DEL PROGRAMA
int main()
{
	interfaz();
	pantalla_bienvenida();
	pantalla_ingreso();
	pantalla_presentacion();
	
	getch();
}
//FUNCIONES DE USUARIO
void interfaz()
{
	fondo(0, 0, 159, 39, 7, 7); //FONDO DEL PROGRAMA
	ct(3); //COLOR AMARILLO
	marcoli(0, 0, 159, 39, 219); //MARCO GRANDE
	ct(4); //COLOR AZUL
	marcoli(34, 3, 125, 36, 219); //MARCO PEQUEÑO
}
void pantalla_bienvenida()
{	
	int line = 12; //VARIABLE QUE REPRESENTA LA FILA DE INICIO DE IMPRESION DE LAS LETRAS
	borrar_pantalla(35, 4, 124, 35); //BORRADO DE PANTALLA		
	ct(7); //COLOR BLANCO
	etiqueta("UNIVERSIDAD DE GUAYAQUIL", 'C', 35, line += 2, 124 - 35);
	etiqueta("FACULTAD DE CIENCIAS MATEMATICAS Y FISICAS", 'C', 35, line += 2, 123 - 34);
	etiqueta("TECNOLOGIA DE LA INFORMACION", 'C', 35, line += 2, 123 - 34);
	etiqueta("FELIPE SANTIAGO FIGUEROA CEVALLOS", 'C', 35, line += 2, 123 - 34);
	etiqueta("SEGUNDO SEMESTRE", 'C', 35, line += 2, 123 - 34);
	etiqueta("TIN-S-VE-2-9", 'C', 35, line += 2, 123 - 34);
	etiqueta("Presione [ENTER] para continuar...", 'D', 35, 35, 124 - 35);
	getch();
}
void pantalla_ingreso()
{
	borrar_pantalla(35, 4, 124, 35);
	etiqueta("ESTUDIANTES DE LA CARRERA DE TECNOLOGIA DE LA INFORMACION", 'C', 35, 6, 89);
	ct(3); //COLOR AMARILLO
	marcold(35, 4, 124, 8);
	marcold(35, 9, 124, 35);
	ct(7); //COLOR BLANCO
	ingreso_estudiantes();
	etiqueta("INGRESOS EXITOSOS", 'C', 36, 30, 123 - 36);
	etiqueta("Presione [ENTER] para continuar...", 'D', 36, 34, 123 - 36);
	getch();
}
void pantalla_presentacion()
{
	borrar_pantalla(35, 9, 124, 35);
	ct(3); //COLOR AMARILLO	
	marcold(35, 9, 64, 13);
	marcold(65, 9, 94, 13);
	marcold(95, 9, 124, 13);
	marcold(35, 14, 64, 35);
	marcold(65, 14, 94, 35);
	marcold(95, 14, 124, 35);	
	ct(7); //COLOR BLANCO
	
	etiqueta("ESTUDIANTE", 'C', 35, 11, 29);
	etiqueta("NOMBRE", 'C', 65, 11, 29);
	etiqueta("APELLIDO", 'C', 95, 11, 29);
	mostrar_estudiantes();
}
void ingreso_estudiantes()
{
	int fila;
	int colu;
	int cont = 1;
	char auxi[20];
	
	for(fila = 0; fila < FILA; fila++)
	{
		for(colu = 0; colu < COLU; colu++)
		{			
			poscf(36, 13); printf("ESTUDIANTE %d", cont++);
			etiqueta("Ingrese el nombre: ", 'I', 36, 15, 30);
			etiqueta("                    ", 'I', 36, 16, 30);
			etiqueta("Ingrese el apellido: ", 'I', 36, 18, 30);
			etiqueta("                    ", 'I', 36, 19, 30);
			poscf(36, 16);
			gets(auxi);
			strcpy(NOMB[fila][colu], auxi);			
			poscf(36, 19);
			gets(auxi);
			strcpy(NOMB[fila][colu], auxi);			
		}
	}
}
void mostrar_estudiantes()//FALTA ESTO DE AQUI
{
	bp(0);
	int fila;
	int colu;
	int cont = 0;
	char auxi[50];
	for(fila = 0; fila < FILA; fila++)
	{
		for(colu = 0; colu < COLU; colu++)
		{
			strcpy(auxi, NOMB[fila][colu]);
			strcat(auxi, " ");
			colu++;
			strcat(auxi, NOMB[fila][colu]);
			colu++;
			etiqueta(auxi, 'I', 0, cont++, 160);			
		}
	}
}
void borrar_pantalla(int iniF, int iniC, int finF, int finC)
{
	int con1;
	int con2;	
	for(con1 = iniF; con1 <= finF; con1++)
	{
		for(con2 = iniC; con2 <= finC; con2++)
		{
			poscf(con1, con2); printf(" ");
		}
	}
}

