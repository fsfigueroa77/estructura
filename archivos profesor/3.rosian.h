/*FUNCION DE USUARIO QUE PERMITE LA COLOCACION DEL CURSOR EN LA PANTALLA*/
//ARCHIVO CABEBECERA
#include<stdio.h>
#include<conio.h>
#include<windows.h>
//POSICIONAR EL CURSOR 
void poscf(int colu, int fila)
{
	COORD coord;
	coord.X = colu;
	coord.Y = fila;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void etiqueta(char* mens,char alin,int colu,int fila,int anch)
{
		int vcol=0; //VALOR DE CONLUMNA
		if(alin=='D') vcol=colu+(anch-strlen(mens));
		if(alin=='C') vcol=colu+((anch-strlen(mens))/2);
		if(alin=='I') vcol=colu;
		poscf(vcol,fila);printf("%s",mens);
}
//MARCO CON PARAMETRO ENTERO
void marcoli(int col1, int fil1, int col2, int fil2,int nume)
{
	int colu;
	int fila;
	for(colu=col1;colu<col2;colu++)
	{
		poscf(colu,fil1);printf("%c",nume);
		poscf(colu,fil2);printf("%c",nume);	
	}
	for(fila=fil1;fila<=fil2;fila++)
	{
		poscf(col1,fila);printf("%c",nume);
		poscf(col2,fila);printf("%c",nume);	
	}
}
//MARCO CON LINEA DOBLE
void marcold(int col1, int fil1, int col2, int fil2)
{
	int colu;
	int fila;
	for(colu=col1;colu<col2;colu++)
	{
		poscf(colu,fil1);printf("%c",205);
		poscf(colu,fil2);printf("%c",205);	
	}
	for(fila=fil1;fila<fil2;fila++)
	{
		poscf(col1,fila);printf("%c",186);
		poscf(col2,fila);printf("%c",186);	
	}
	poscf(col2,fil2);printf("%c",188);
	poscf(col1,fil1);printf("%c",201);
	poscf(col2,fil1);printf("%c",187);
	poscf(col1,fil2);printf("%c",200);
}
//MARCO LINEA SIMPLE
void marcols(int col1, int fil1, int col2, int fil2)
{
	int colu;
	int fila;
	for(colu=col1;colu<col2;colu++)
	{
		poscf(colu,fil1);printf("%c",196);
		poscf(colu,fil2);printf("%c",196);	
	}
	for(fila=fil1;fila<fil2;fila++)
	{
		poscf(col1,fila);printf("%c",179);
		poscf(col2,fila);printf("%c",179);	
	}
	poscf(col2,fil2);printf("%c",217);
	poscf(col1,fil1);printf("%c",218);
	poscf(col2,fil1);printf("%c",191);
	poscf(col1,fil2);printf("%c",192);
}
//MARCO LINEA GRUESA
void marcolg(int col1,int fil1,int col2,int fil2)
{
	int fila;
	int colu;
	for(fila=fil1;fila<=fil2;fila=fila+1)
	{
		poscf(col1,fila);printf("%c",178);
		poscf(col2,fila);printf("%c",178);
	}
	for(colu=col1;colu<=col2;colu=colu+1)
	{
		poscf(colu,fil1);printf("%c",178);
		poscf(colu,fil2);printf("%c",178);
	}
	poscf(col1,fil1);printf("%c",178);
	poscf(col2,fil1);printf("%c",178);
	poscf(col1,fil2);printf("%c",178);
	poscf(col2,fil2);printf("%c",178);
}
//MARCO CON PARAMETRO CADENA 6 CARACTERES
void marcolp(int col1,int fil1,int col2,int fil2,char cade[6])
{
	int fila;
	int colu;
	for(fila=fil1;fila<=fil2;fila=fila+1)
	{
		poscf(col1,fila);printf("%c",cade[1]);
		poscf(col2,fila);printf("%c",cade[1]);
	}
	for(colu=col1;colu<=col2;colu=colu+1)
	{
		poscf(colu,fil1);printf("%c",cade[0]);
		poscf(colu,fil2);printf("%c",cade[0]);
	}
	poscf(col1,fil1);printf("%c",cade[2]);
	poscf(col2,fil1);printf("%c",cade[3]);
	poscf(col1,fil2);printf("%c",cade[4]);
	poscf(col2,fil2);printf("%c",cade[5]);
}
void ct(int n)
{	
	if(n==0) printf("\033[0;30m");//negro-negro
	if(n==1) printf("\033[0;31m");//negro-rojo
	if(n==2) printf("\033[0;32m");//negro-verde
	if(n==3) printf("\033[0;33m");//negro-amarillo
	if(n==4) printf("\033[0;34m");//negro-azul
	if(n==5) printf("\033[0;35m");//negro-morado
	if(n==6) printf("\033[0;36m");//negro-celeste
	if(n==7) printf("\033[0;37m");//negro-blanco
	if(n==8) printf("\033[1;30m");//claro-negro
	if(n==9) printf("\033[1;31m");//claro-rojo
	if(n==10) printf("\033[1;32m");//claro-verde
	if(n==11) printf("\033[1;33m");//claro-amarillo
	if(n==12) printf("\033[1;34m");//claro-azul
	if(n==13) printf("\033[1;35m");//claro-morado 
	if(n==14) printf("\033[1;36m");//claro-celeste
	if(n==15) printf("\033[1;37m");//claro-blanco
}
//DIBUJO DE LETRAS
void letra(char cade[50],int colu, int fila)
{
	int cont=0;
	char cara;
	do
	{
		cara=cade[cont];
		switch(cara)
		{
			case 'Q':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@    @");
				ct(12);poscf(colu,fila+2); printf("@    @");
			    ct(12);poscf(colu,fila+3); printf("@  @ @");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'W':
				ct(11);poscf(colu,fila);   printf("@    @");
			    ct(11);poscf(colu,fila+1); printf("@    @");
				ct(12);poscf(colu,fila+2); printf("@ @@ @");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@    @");
			    break;
			case 'E':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'R':
				ct(11);poscf(colu,fila);   printf("@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@   @");
				ct(12);poscf(colu,fila+2); printf("@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @");
				ct(9); poscf(colu,fila+4); printf("@@   @");
			    break;
			case 'T':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@@@@@");
				ct(12);poscf(colu,fila+2); printf("  @@");
			    ct(12);poscf(colu,fila+3); printf("  @@");
				ct(9); poscf(colu,fila+4); printf("  @@");
			    break;
			case 'Y':
				ct(11);poscf(colu,fila);   printf("@    @");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf(" @@@@");
			    ct(12);poscf(colu,fila+3); printf("  @@");
				ct(9); poscf(colu,fila+4); printf("  @@");
			    break;
			case 'U':
				ct(11);poscf(colu,fila);   printf("@@  @@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@  @@");
			    ct(12);poscf(colu,fila+3); printf("@@@@@@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'I':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("  @@  ");
				ct(12);poscf(colu,fila+2); printf("  @@  ");
			    ct(12);poscf(colu,fila+3); printf("  @@  ");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'O':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@  @@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'P':
				ct(11);poscf(colu,fila);   printf("@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@   @");
				ct(12);poscf(colu,fila+2); printf("@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@");
				ct(9); poscf(colu,fila+4); printf("@@");
			    break;
			case 'A':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@  @@");
			    break;
			case 'S':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'D':
				ct(11);poscf(colu,fila);   printf("@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@   @");
				ct(12);poscf(colu,fila+2); printf("@@   @");
			    ct(12);poscf(colu,fila+3); printf("@@   @");
				ct(9); poscf(colu,fila+4); printf("@@@@@");
			    break;
			case 'F':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@");
				ct(9); poscf(colu,fila+4); printf("@@");
			    break;
			case 'G':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@");
				ct(12);poscf(colu,fila+2); printf("@  @@@");
			    ct(12);poscf(colu,fila+3); printf("@    @");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'H':
				ct(11);poscf(colu,fila);   printf("@@  @@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@  @@");
			    break;
			case 'J':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("   @@");
				ct(12);poscf(colu,fila+2); printf("   @@");
			    ct(12);poscf(colu,fila+3); printf("@  @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@");
			    break;
			case 'K':
				ct(11);poscf(colu,fila);   printf("@@   @");
			    ct(11);poscf(colu,fila+1); printf("@@  @");
				ct(12);poscf(colu,fila+2); printf("@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @");
				ct(9); poscf(colu,fila+4); printf("@@   @");
			    break;
			case 'L':
				ct(11);poscf(colu,fila);   printf("@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@");
			    ct(12);poscf(colu,fila+3); printf("@@@@@@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'Ñ':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("      ");
				ct(12);poscf(colu,fila+2); printf("@@   @");
			    ct(12);poscf(colu,fila+3); printf("@  @ @");
				ct(9); poscf(colu,fila+4); printf("@   @@");
			    break;
			case 'Z':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("   @@");
				ct(12);poscf(colu,fila+2); printf("  @@");
			    ct(12);poscf(colu,fila+3); printf(" @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'X':
				ct(11);poscf(colu,fila);   printf("@    @");
			    ct(11);poscf(colu,fila+1); printf(" @  @");
				ct(12);poscf(colu,fila+2); printf("  @@");
			    ct(12);poscf(colu,fila+3); printf(" @  @");
				ct(9); poscf(colu,fila+4); printf("@    @");
			    break;
			case 'C':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@");
			    ct(12);poscf(colu,fila+3); printf("@@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'V':
				ct(11);poscf(colu,fila);   printf("@    @");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@  @@");
			    ct(12);poscf(colu,fila+3); printf(" @@@@");
				ct(9); poscf(colu,fila+4); printf("  @@");
			    break;
			case 'B':
				ct(11);poscf(colu,fila);   printf("@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case 'N':
				ct(11);poscf(colu,fila);   printf("@@  @@");
			    ct(11);poscf(colu,fila+1); printf("@@@ @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@ @@@");
				ct(9); poscf(colu,fila+4); printf("@@  @@");
			    break;
			case 'M':
				ct(11);poscf(colu,fila);   printf("@    @");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@ @@ @");
			    ct(12);poscf(colu,fila+3); printf("@    @");
				ct(9); poscf(colu,fila+4); printf("@    @");
			    break;
			case '0':
				ct(11);poscf(colu,fila);   printf(" @@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@  @@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf(" @@@@");
			    break;
			case '1':
				ct(11);poscf(colu,fila);   printf("  @@@@");
			    ct(11);poscf(colu,fila+1); printf(" @@ @@");
				ct(12);poscf(colu,fila+2); printf("@@  @@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("    @@");
			    break;
			case '2':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("    @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '3':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("    @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '4':
				ct(11);poscf(colu,fila);   printf("@@  @@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("    @@");
			    break;
			case '5':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '6':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '7':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@@@@@");
				ct(12);poscf(colu,fila+2); printf("    @@");
			    ct(12);poscf(colu,fila+3); printf("   @@");
				ct(9); poscf(colu,fila+4); printf("  @@");
			    break;
			case '8':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("@@  @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '9':
				ct(11);poscf(colu,fila);   printf("@@@@@@");
			    ct(11);poscf(colu,fila+1); printf("@@  @@");
				ct(12);poscf(colu,fila+2); printf("@@@@@@");
			    ct(12);poscf(colu,fila+3); printf("    @@");
				ct(9); poscf(colu,fila+4); printf("@@@@@@");
			    break;
			case '-':
				ct(11);poscf(colu,fila);   printf("");
			    ct(11);poscf(colu,fila+1); printf("");
				ct(12);poscf(colu,fila+2); printf(" @@@@");
			    ct(12);poscf(colu,fila+3); printf("");
				ct(9); poscf(colu,fila+4); printf("");
		} 
		cont++;
		colu=colu+7;
	}while(cont<strlen(cade));
}

/*
FUNCION QUE PERMITE DIBUJAR UN MARCO CON 3 LINEAS DE COLORES 
*/
void marco3l(int col1, int fil1, int col2,int fil2,int limi,int cola,int colb,int colc)
{
	int cont=0;
	for(cont=0;cont<limi*3;cont++)
	{
		if(cont==0 && limi==1) ct(cola);
		if(cont==1 && limi==1) ct(colb);
		if(cont==2 && limi==1) ct(colc);
		if(cont==0 && limi!=1) ct(cola);
		if(cont==1*limi && limi!=1) ct(colb);
		if(cont==2*limi && limi!=1) ct(colc);
		marcoli(col1+cont,fil1+cont,col2-cont,fil2-cont,219);
	}
	ct(colb);
}

void pantalla(char empr[50],char rute[50],char ubic[50],char pant[50])
{
	char text[50];
	marco3l(0,0,159,39,1,2,15,6);
	marcold(3,3,78,8);
	marcold(3,9,78,30);
	marcold(3,31,78,36);
	etiqueta(empr,'C',0,4,80);
	etiqueta(rute,'C',0,5,80);
	etiqueta(ubic,'C',0,6,80);
	strcpy(text,"PANTALLA ");
	strcat(text,pant);
	etiqueta(text,'C',0,7,80);
	marcold(79,3,156,36);
	strcpy(text,"LISTADO DE ");
	strcat(text,pant);
	etiqueta(text,'C',80,4,80);
	poscf(80,5); printf("============================================================================");
	poscf(80,6); printf("Filtar por descripcion: ");
	poscf(80,7); printf("============================================================================");
	poscf(80,9); printf("============================================================================");
	poscf(80,34);printf("============================================================================");
	poscf(80,35);printf("Anterior                                                           Siguiente");
	
}
void bp(int sect)
{
	int fila=0;
	if(sect==0)
	{
		system("cls");
	}
	if(sect==2)
	{
		for(fila=10;fila<=29;fila++)
		{
			poscf(4,fila);printf("                                                                         ");
		}
	}
	if(sect==3)
	{
		for(fila=32;fila<=35;fila++)
		{
			poscf(4,fila);printf("                                                                          ");
		}
	}
	if(sect==4)
	{
		for(fila=10;fila<=33;fila++)
		{
			poscf(81,fila);printf("                                                                           ");
		}
	}
}
void mensaje(char tipo,char* mens)
{
	if(tipo=='X')	//MENSAJE ERROR CRITICO
	{
		poscf(5,32);printf("ERROR");
		poscf(5,33);printf("%s",mens);	
    	poscf(5,34);printf("Presione cualquier tecla para continuar");
		getch();
		poscf(5,32);printf("                                           ");
		poscf(5,33);printf("                                           ");	
		poscf(5,34);printf("                                           ");
	}
	if(tipo=='P')	//MENSAJE DE PREGUNTA
	{
		poscf(5,32);printf("                                           ");
		poscf(5,33);printf("                                           ");	
		poscf(5,34);printf("                                           ");
		poscf(5,32);printf("PREGUNTA");	
		poscf(5,33);printf("%s",mens);	
		poscf(5,34);printf("(S) si es SI o (N) si es NO");	
	}
	if(tipo=='I')	//MENSAJE DE INFORMACION
	{
		poscf(5,32);printf("INFORMACION");
		poscf(5,33);printf("%s",mens);	
	    poscf(5,34);printf("Presione cualquier tecla para continuar");
	    getch();
	    poscf(5,32);printf("                                           ");
		poscf(5,33);printf("                                           ");	
		poscf(5,34);printf("                                           ");
	}
}
char* compactar(char cade[50])
{
	int cont=0;
	for(cont=0;cont<strlen(cade);cont++)
	{
		if(cade[cont]==' ') cade[cont]='_';
	}
	return cade;
}
char* descompactar(char cade[50])
{
	int cont=0;
	for(cont=0;cont<strlen(cade);cont++)
	{
		if(cade[cont]=='_') cade[cont]=' ';
	}
	return cade;
}
void entrada_secuencia(int colu, int fila,int secu)
{
	poscf(colu,fila);printf("%i",secu);	
}
char* entrada_cadena(int colu, int fila)
{
	char auxi[50];
	char cara;
	int cont=0;
	poscf(colu,fila);
	do
	{
		cara=toupper(getch());
		if((cara>=65 && cara <=90)||cara ==32||cara ==8)
		{
			if(cara==8)
			{
				auxi[cont-1]='\0';
				cont--;
				poscf(colu+cont,fila);printf(" ");
				poscf(colu+cont,fila);
			}
			else
			{
				if(cont!=0 && auxi[cont-1]!=' ')
					cara=tolower(cara);			
				poscf(colu+cont,fila);printf("%c",cara);
				auxi[cont]=cara;
				auxi[cont+1]='\0';
				cont++;
			}

		}
		
	}while(cara!=13);
	return auxi;
}
void fondo(int col1, int fil1,int col2, int fil2,int colA, int colB)
{
	int colu;
	int fila;

	for(colu=col1;colu<col2;colu=colu+2)
	{
		for(fila=fil1;fila<fil2;fila=fila+1)
		{
			if(fila%2==0)
			{
				ct(colA);
				poscf(colu+1,fila); printf("%c",178);
			}	
			else
			{
				ct(colB);
				poscf(colu+2,fila); printf("%c",178);
			}
			
		}
	}
}
void letrare(char cade[50],int colo, int colu, int fila)
{
	int cont=0;
	char cara;
	do
	{
		cara=cade[cont];
		switch(cara)
		{
			case 'Q':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c    %c",219,219);
				ct(colo);poscf(colu,fila+2); printf("%c    %c",219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c  %c %c",219,219,219);
				ct(colo);poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
				break;
			case 'W':
				ct(colo);poscf(colu,fila);   printf("%c    %c",219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c    %c",219,219);
				ct(colo);poscf(colu,fila+2); printf("%c %c%c %c",219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c    %c",219,219);
			    break;
			case 'E':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c    ",219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c    ",219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'R':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c",219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c   %c",219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c   %c",219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c   %c",219,219,219);
			    break;
			case 'T':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("  %c%c",219,219);
			    ct(colo);poscf(colu,fila+3); printf("  %c%c",219,219);
				ct(colo); poscf(colu,fila+4); printf("  %c%c",219,219);
			    break;
			case 'Y':
				ct(colo);poscf(colu,fila);   printf("%c    %c",219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf(" %c%c%c%c",219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("  %c%c",219,219);
				ct(colo); poscf(colu,fila+4); printf("  %c%c",219,219);
			    break;
			case 'U':
				ct(colo);poscf(colu,fila);   printf("%c%c  %c%c",219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'I':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("  %c%c  ",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("  %c%c  ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("  %c%c  ",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'O':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'P':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c   %c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c    ",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c    ",219,219,219,219,219,219);
			    break;
			case 'A':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c  %c%c",219,219,219,219,219,219);
			    break;
			case 'S':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c    ",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'D':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c   %c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c   %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c   %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'F':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c",219,219,219,219,219,219);
			    break;
			case 'G':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c  %c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c    %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'H':
				ct(colo);poscf(colu,fila);   printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c  %c%c",219,219,219,219,219,219);
			    break;
			case 'J':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("   %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("   %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'K':
				ct(colo);poscf(colu,fila);   printf("%c%c   %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c   %c",219,219,219,219,219,219);
			    break;
			case 'L':
				ct(colo);poscf(colu,fila);   printf("%c%c   ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c   ",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c   ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c   ",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'Ñ':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("      ");
				ct(colo);poscf(colu,fila+2); printf("%c%c   %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c %c%c %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c   %c%c",219,219,219,219,219,219);
			    break;
			case 'Z':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("   %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf(" %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'X':
				ct(colo);poscf(colu,fila);   printf("%c    %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf(" %c  %c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf(" %c  %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c    %c",219,219,219,219,219,219);
			    break;
			case 'C':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c    ",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c    ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c    ",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'V':
				ct(colo);poscf(colu,fila);   printf("%c    %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf(" %c%c%c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("  %c%c",219,219,219,219,219,219);
			    break;
			case 'B':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c ",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case 'N':
				ct(colo);poscf(colu,fila);   printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c%c %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c %c%c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c%c  %c%c",219,219,219,219,219,219);
			    break;
			case 'M':
				ct(colo);poscf(colu,fila);   printf("%c    %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c %c%c %c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c    %c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4); printf("%c    %c",219,219,219,219,219,219);
			    break;
			case '0':
				ct(colo);poscf(colu,fila);   printf(" %c%c%c%c ",219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c  %c%c",219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf(" %c%c%c%c ",219,219,219,219);
			    break;
			case '1':
				ct(colo);poscf(colu,fila);   printf("  %c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("    %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("    %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("    %c%c",219,219,219,219,219,219);
			    break;
			case '2':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("    %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '3':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("    %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '4':
				ct(colo);poscf(colu,fila);   printf("%c%c  %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("    %c%c",219,219,219,219,219,219);
			    break;
			case '5':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '6':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '7':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("    %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("   %c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf(" %c%c",219,219,219,219,219,219);
			    break;
			case '8':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '9':
				ct(colo);poscf(colu,fila);   printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+1); printf("%c%c  %c%c",219,219,219,219,219,219);
				ct(colo);poscf(colu,fila+2); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("    %c%c",219,219,219,219,219,219);
				ct(colo); poscf(colu,fila+4);printf("%c%c%c%c%c%c",219,219,219,219,219,219);
			    break;
			case '-':
				ct(colo);poscf(colu,fila);   printf("");
			    ct(colo);poscf(colu,fila+1); printf("");
				ct(colo);poscf(colu,fila+2); printf(" %c%c%c%c",219,219,219,219,219,219);
			    ct(colo);poscf(colu,fila+3); printf("");
				ct(colo); poscf(colu,fila+4); printf("");
		} 
		cont++;
		colu=colu+7;
	}while(cont<strlen(cade));
}	
