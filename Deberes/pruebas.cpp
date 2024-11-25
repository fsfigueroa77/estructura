//ARCHIVOS CABECERA
#include <rosian.h>
//DECLARACION DE FUNCIONES DE USUARIO
int suma(int num1, int num2);
//CUERPO DEL PROGRAMA
int main()
{
	//system("mode con: cols=160 lines=40");
	marcold(0,0,159,39);
	letra("")
	int num1 = 5;
	int num2 = 10;
	
	//int sumas = suma(num1, num2);
	//printf("%d", sumas);
	return(0);
}
//FUNCIONES DE USUARIO
int suma(int num1, int num2) 
{
	int resultado = num1 + num2;
	return(resultado);
}

