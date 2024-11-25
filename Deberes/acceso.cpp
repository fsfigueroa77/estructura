/*
DESARROLLADOR: FELIPE FIGUEROA CEVALLOS
TEMA: ELABORACION DE ACCESO
*/
//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
//DECLARACION DE FUNCIONES DE USUARIO
void interfaz();
void ingreso_credenciales();
void entrada_credencial(int colu, int fila, int cred);
bool comprobacion(char (&usua)[16]);
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
	interfaz();
	ingreso_credenciales();
	system("menu.exe");
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
	etiqueta("ACCESO AL SISTEMA", 'C', 32, 11, 95);
	etiqueta("Usuario    :", 'I', 60, 18, 12);
	marcols(80, 17, 99, 19);
	etiqueta("Contrasenia:", 'I', 60, 21, 12);
	marcols(80, 20, 99, 22);
}
void ingreso_credenciales()
{
	entrada_credencial(82, 18, 1);
	entrada_credencial(82, 21, 2);
}
void entrada_credencial(int colu, int fila, int cred)
{
	char usua[16];
	char cara = 0;
	int cont = 0;
	poscf(colu, fila);
	while(cara != 13)
	{
		cara = getch();
		if(((cara >= 48 && cara <= 57) || (cara >= 65) && (cara <= 90)) || (cara >= 97 && cara <= 122) || (cara == 8))
		{
			if(cara == 8)
			{
				if(cont > 0)
				{
					usua[cont - 1] = '\0';
					cont--;
					poscf(colu+cont,fila);printf(" ");
					poscf(colu+cont,fila);
				}
			}
			else if(cont < 16 && cred == 1)
			{
				poscf(colu+cont,fila);printf("%c", cara);
				usua[cont]=cara;
				usua[cont+1]='\0';
				cont++;
			}
			else if(cont < 16 && cred == 2)
			{
				poscf(colu+cont,fila);printf("*");
				usua[cont]=cara;
				usua[cont+1]='\0';
				cont++;
			}
		}
	}
}
bool comprobacion(char (&usua)[16])
{
	poscf(82, 21);
	char usu1[16] = "fsfigueroa77";
	//char cont[2][16] = {"asdasd123", "contrasenia"};
	return(strcmp(usu1, usua) == 0);
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

