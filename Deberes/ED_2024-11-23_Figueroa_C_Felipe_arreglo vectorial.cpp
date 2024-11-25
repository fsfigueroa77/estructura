/*PROGRAMADOR: FELIPE SANTIAGO FIGUEROA CEVALLOS
TEMA: PROGRAMA QUE PERMITE REALIZAR LOS SIGUIENTE
1.- CREACION DE UNA FUNCION DE USUARIO GENERACION QUE PERMITA GENERAR NUMEROS ALEATORIOS
    Y QUE ESTOS SEAN ALMACENADOS EN UN ARREGLO UNA DIRECCION
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
//DEFINICION DE CONSTANTE
const int TAMA=30; //TAMAÑO
//DECLARACION DE DATOS
int nume[TAMA];
//DECLARACION DE FUNCIONES DE USUARIO
void generacion();
void presentacion();
void proceso();
//CUERPO DEL PROGRAMA
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
//DESARROLLO DE LAS FUNCIONES DE USUARIO
void generacion()
{
	int valo=0;
	int cont=0;
	int con1=0;
	int band=0;
	srand(time(NULL));//PERMITE REINICIAR LA SECUENCIA ALEATORIA
	while(cont<TAMA)
	{	
		do
		{
			band=0;
			valo = rand() % 200;  //GERERO EL NUMERO ALETORIO
			for(con1=0;con1<cont;con1++)
			{
				if(nume[con1] ==valo)	
				{
					band=1;				
				}
			}
		}while(band==1);
		nume[cont]=valo;	//COPIO EL NUMERO GENERADO AL ARREGLO
	
		cont++;//CONTROLDO QUE SE GENERO Y ASIGNO EL NUMERO AL ARREGLO
	}
}
void presentacion()
{
	int cont=0;
	int fila=0;
	int colu=0;
	etiqueta("PRESENTACION DE LOS NUMEROS QUE ESTAN EN EL ARREGLO",'C',0,6,159);
	for(cont=0;cont<TAMA;cont++)
	{
		poscf(10+colu,8+fila);printf("Numero %i: %i",cont+1,nume[cont]);
		fila++;
		if(fila==6)
		{
			colu=colu+30;
			fila=0;
		}
	}
}
void proceso()
{
	int cont=0;
	int cpar=0;
	int cimp=0;
	int suma=0;
	float prom=0;
	for(cont=0;cont<TAMA;cont++)
	{
		if((nume[cont] % 2)==0)	
		{
			cpar=cpar+1;
		}
		else
		{
			cimp=cimp+1;
		}
		suma=suma+nume[cont];
		prom=suma/(TAMA*1.0);
	}
	poscf(60,15);printf("Cantidad de numeros pares..: %i",cpar);	
	poscf(60,16);printf("Cantidad de numeros impares: %i",cimp);
	poscf(60,17);printf("Sumatoria..................: %i",suma);
	poscf(60,18);printf("promedio...................: %.2f",prom);
	letra("ESTRUCTURA DE DATO",17,25);
}
