/*
dimensiones: 160x40
*/

//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
//DECLARACION DE FUNCIONES DE USUARIO
void pantalla_bienvenida();
void marco_personalizado();
//CUERPO DEL PROGRAMA
int main()
{
	pantalla_bienvenida();
	getch();
}
//FUNCIONES DE USUARIO
void pantalla_bienvenida()
{
	marco_personalizado();
}

void marco_personalizado()
{
	int hori;
	int vert;	
	
	for(hori = 0; hori < 160; hori++)
	{
		for(vert = 0; vert < 40; vert++)
		{
			if(hori == 0 || vert == 0)
			{
				if(hori < 80 && vert < 20)
				{
					ct(11);
					poscf(hori, vert); printf("%c",178);
				}
				else
				{
					ct(1);
					poscf(hori, vert); printf("%c",178);
				}
								
			}
			if(hori == 159 || vert == 39)
			{
				if(hori > 80 && vert > 20)
				{
					ct(11);
					poscf(hori, vert); printf("%c",178);
				}
				else
				{
					ct(1);
					poscf(hori, vert); printf("%c",178);
				}				
			}			
		}		
	}
}
