/*PROGRAMADOR: RENZO ROGELIO PADILLA GOMEZ
TEMA: PROGRAMA QUE PERMITE REALIZAR LOS SIGUIENTE
1.- CREACION DE UNA FUNCION DE USUARIO GENERACION QUE PERMITA GENERAR NUMEROS ALEATORIOS
    Y QUE ESTOS SEAN ALMACENADOS EN UN ARREGLO DE DOS DIRECCIONES 
2.- CREACION DE UNA FUNCION DE USUARIO PRESENTACION QUE PERMITA MOSTRAR LOS ELEMENTOS 
    DEL ARREGLO
3.- CREACION DE UNA FUNCION DE USUARIO PROCESO QUE CALCULA CUANTOS NUMEROS PARES, CUANTOS
    NUMEROS IMPARES, LA SUMA, TOTAL Y EL PROMEDIO DE LOS NUMEROS GENERADOS*/
//ARCHIVOS CABECERAS
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <cstdlib> //FUNCION RAND
#include <rosian.h>
//DECLARACION DE DATOS
int nume[10][10];
//DECLARACION DE FUNCIONES DE USUARIO
void generacion();
void presentacion();
void proceso();

int main()
{
	bp(0);//BOORADO DE PANTALLA EL INDICE 0 INDICA BORRADO EN TODA LA PANTALLA
	marcold(0,0,159,39);
	marcolg(1,1,158,38);
	marco3l(2,2,157,37,1,1,2,3);
	marcold(5,5,154,34);
	generacion();
	presentacion();	
	proceso();	
	getch();
}
//DESARROLLO DE LAS FUNCIONES
void generacion()
{
	int valo=0;
	int con1=0;
	int con2=0;
	int band=0;
	srand(time(NULL));
	while(con1<10)
	{
		con2=0;
		while(con2<10)
		{	
			valo = rand() % 100;  //GERERO EL NUMERO ALETORIO
			nume[con1][con2]=valo;	//COPIO EL NUMERO GENERADO AL ARREGLO
			con2++;
		}
		con1++;
	}
}
void presentacion()
{
	int con1=0;
	int con2=0;
	int fila=0;
	int colu=0;
	etiqueta("PRESENTACION DE LOS NUMEROS QUE ESTAN EN EL ARREGLO",'C',0,6,159);
	for(con1=0;con1<=9;con1++)
	{
		for(con2=0;con2<=9;con2++)
		{
			poscf(10+colu,10+fila);printf("%i",nume[con1][con2]);
			colu=colu+15;
			if(colu>145)
			{
				colu=0;
				fila++;
			}
		}
	}
}
void proceso()
{
	int con1=0;
	int con2=0;
	int cpar=0;
	int cimp=0;
	for(con1=0;con1<=9;con1++)
	{
		for(con2=0;con2<=9;con2++)
		{
			if((nume[con1][con2] % 2)==0)	
			{
				cpar=cpar+1;
			}
			else
			{
				cimp=cimp+1;
			}
		}	
	}
	poscf(70,21);printf("Cantidad de pares..: %i",cpar);	
	poscf(70,22);printf("Cantidad de impares: %i",cimp);
	letra("ESTRUCTURA DE DATO",17,25);	
}
