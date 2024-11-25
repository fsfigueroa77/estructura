#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
char* entrada_cadenas(int colu, int fila);
int main()
{
	//entrada_cadena(0, 0);
	//entrada_cadena(70, 20);
	char prue[50] = "fsfigueroa77"; //VARIABLE DE PRUEBA PARA COMPARAR LA CADENA INGRESADA
	if(strcmp(prue, entrada_cadenas(70, 21)) == 0)
	{
		poscf(70, 22); printf("correcto");
	}
	else
	{
		poscf(70, 22); printf("incorrecto");
	}
	getch();
}
char* entrada_cadenas(int colu, int fila)
{
	int tama = 50;
	char auxi[tama];
	for(int i = 0; i < tama; i++)
	{
		auxi[i] = '\0';
    }
	char cara = 0;
	int cont = 0;
	poscf(colu, fila);
	while(cara != 13) //ENTER: CICLO QUE FINALIZA CUANDO SE PRESIONE LA TECLA DE RETORNO DE CARRO
	{
		cara = getch();
		if((cara >= 48 && cara <= 57) || (cara >= 97 && cara <= 122) || (cara == 8) || (cara == 32))
		{
			if(cara == 8) //BACKSPACE
			{
				if(cont > 0) //CONDICION QUE NO PERMITE RETROCEDER MAS ALLA DEL PRINCIPIO DE LA CADENA
				{
					auxi[--cont] = '\0'; //INDICA EL FIN DE LA CADENA EN LA POSICION ANTERIOR DEL ARREGLO
					poscf(colu + cont, fila); printf(" ");
					poscf(colu + cont, fila);
				}
				else
				{
					auxi[cont] = '\0';
				}
			}
			else if((cont < tama - 1) && ((cara >= 48 && cara <= 57) || (cara >= 97 && cara <= 122) || (cara == 32))) //CONDICION QUE NO PERMITE AVANZAR MAS ALLA DEL FIN DE LA CADENA
			{
				poscf(colu+cont,fila); printf("%c", cara);
				auxi[cont] = cara;
				auxi[++cont] = '\0';
			}
		}
	}
	return(auxi);
}
