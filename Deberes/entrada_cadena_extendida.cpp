/*
DESCRIPCION DE LA FUNCION
NOMBRE: "entrada_cadena_modificada"
FUNCIONAMIENTO: LA FUNCION MODIFICADA DE LA FUNCION "entrada_cadena" ORIGINAL DEL ARCHIVO CABECERA "rosian.h"
LA FUNCION RECIBE DOS PARAMETROS ADICIONALES EN COMPARACION DE LA ORIGINAL. EL TERCER PARAMETRO DETERMINA EL CASO DE ENTRADA QUE SE NECESITA SEGUN LA SITUACION. EL CUARTO PARAMETRO
RECIBE EL TAMANIO DE CADENA QUE SE VA A INGRESAR POR TECLADO.
ADEMAS MEJORA UN ASPECTO QUE NO TENIA LA FUNCION ORIGINAL QUE ES DE LIMITAR EL BORRADO DE LA CADENA QUE SE INGRESA PARA QUE NO RETROCEDA MAS DE LA CUENTA Y TAMBIEN EL LIMITAR EL FIN DE LA 
CADENA PARA QUE NO SE PASE DEL FINAL.
*/
//ARCHIVOS CABECERA
#include <rosian.h>
//DECLARACION DE FUNCIONES DE USUARIO
char* entrada_cadena_extendida(int colu, int fila, int caso, int limi);
//CUERPO DEL PROGRAMA
int main()
{
	entrada_cadena_extendida(1, 1, 0, 50);
	return(0);
}
//FUNCIONES DE USUARIO
char* entrada_cadena_extendida(int colu, int fila, int caso, int tama) //FUNCION DE ENTRADA DE CADENA MODIFICADA PARA RECIBIR CARACTERES DATOS COMO NUMERO, LETRAS, CARACTERES PARA CORREO.
{
	char auxi[tama]; //TAMA ES EL PARAMETRO QUE RECIBE LA FUNCION Y ESTE DETERMINA EL TAMANIO DE LA CADENA
	char cara = 0; //VARIABLE QUE RECIBE EL CODIGO ASCII DE LA TECLA QUE SE HA PRESIONADO
	int cont = 0; //CONTADOR QUE DETERMINA EL INDICE DE LA CADENA AUXI	
	/*VARIABLES QUE REPRESENTAN EL CODIGO ASCII DE CADA UNA DE LAS TECLAS PERMITIDAS EN LA FUNCION*/
	int back = 8; //BACKSPACE
	int ente = 13; //ENTER
	int espa = 32; //ESPACIO
	int gui1 = 45; //GUION
	int punt = 46; //PUNTO
	int num1 = 48; //INICIO RANGO PARA NUMEROS
	int num2 = 57; //FINAL RANGO PARA NUMEROS
	int arro = 64; //ARROBA
	int may1 = 65; //INICIO RANGO PARA MAYUSCULAS
	int may2 = 90; //FINAL RANGO PARA MAYUSCULAS
	int gui2 = 95; //GUION BAJO
	int min1 = 97; //INICIO RANGO PARA MINUSCULAS
	int min2 = 122; //FINAL RANGO PARA MINUSCULAS
	/***************************************************************************/	
	poscf(colu, fila); //POSICION DEL CURSOR DETERMINADA POR LOS PARAMETROS DE LA FUNCION
	while(cara != ente) //CONDICION QUE ROMPE EL CICLO CUANDO LA TECLA PRESIONADA ES "ENTER"
	{
		cara = getch(); //CAPTURA DE LA TECLA PRESIONADA PERO SIN SER MOSTRADA POR PANTALLA

		bool vali = false; 
		
		if(caso == 0) //CASO 0: ENTRADA CADENA ORIGINAL EN DONDE HACIA MAYUSCULA TODAS LAS LETRAS QUE ESTABAN AL PRINCIPIO DE UNA PALABRA
		{
			vali = (cara >= may1 && cara <= may2) || (cara >= min1 && cara <= min2) || (cara == espa);
			cara = toupper(cara);
		}
		else if(caso == 1) //CASO 1: ENTRADA DE NOMBRE QUE RECIBE SOLAMENTE LETRAS Y EL ESPACIO
		{
			vali = (cara >= may1 && cara <= may2) || (cara >= min1 && cara <= min2) || (cara == espa);
		}
		else if(caso == 2) //CASO 2: ENTRADA QUE RECIBE NUMEROS SOLAMENTE
		{
			vali = (cara >= num1 && cara <= num2);
		}
		else if(caso == 3) //CASO 3: ENTRADA QUE RECIBE CARACTERES DE NUMEROS Y LETRAS PARA LA DIRECCION
		{
			vali = (cara >= num1 && cara <= num2) || (cara >= may1 && cara <= may2) || (cara >= min1 && cara <= min2) || (cara == espa);
		}
		else if(caso == 4) //CASO 4: ENTRADA QUE RECIBE CARACTERES PARA EMAIL
		{
			vali = (cara == gui1) || (cara == punt) || (cara >= num1 && cara <= num2) || (cara == arro) || (cara == gui2) || (cara >= min1 && cara <= min2);
		}
		if(vali  || (cara == back))
		{
			if(cara == back) //CONDICION QUE DETERMINA EL FUNCIONAMIENTO DE LA FUNCION EN EL MOMENTO QUE SE PRESIONA BACKSPACE PARA BORRAR
			{
				if(cont > 0) //CONDICION QUE PERMITE EL USO DEL BACKSPACE SIEMPRE Y CUANDO EL CURSOR NO ESTE AL INICIO DE LA CADENA
				{
					auxi[cont - 1] = '\0';
					cont--;
					poscf(colu + cont, fila); printf(" ");
					poscf(colu + cont, fila);
				}
			}
			else if(cont < tama) //CONDICION QUE PERMITE LIMITA EL INGRESO DE NUEVOS CARACTERES HASTA EL PENULTIMO INDICE DE LA CADENA
			{
				if((cont != 0) && (auxi[cont - 1] != espa) && (caso == 0))
				{
					cara = tolower(cara);
				}				
				poscf(colu + cont, fila); printf("%c", cara);
				auxi[cont] = cara; 
				auxi[cont+1] = '\0'; //DETERMINA EL FIN DE LA CADENA EN EL SIGUIENTE INDICE DEL ULTIMO CARACTER QUE SE INGRESO
				cont++;
			}
		}
	}
	return(auxi);
}

