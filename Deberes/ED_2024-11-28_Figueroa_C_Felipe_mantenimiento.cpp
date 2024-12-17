/*
DESARROLLADOR: FELIPE SANTIAGO FIGUEROA CEVALLOS
TEMA: ELABORACION DE UN MANTENIMIENTO
*/
/*
COMENTARIO ACERCA DEL FUNCIONAMIENTO DEL PROGRAMA: ESTAN DESHABILITADAS POR COMENTARIOSLAS VARIABLES RUC Y TELEFONO DENTRO DE LA ESTRUCTURA, 
ADEMAS DE SUS INTERACCIONES EN EL CODIGO YA QUE AL SER GUARDADAS DENTRO DEL FICHERO HAY UN CONFLICTO DE ESCRITURA QUE DAÑA DICHO ARCHIVO.
*/
//ARCHIVOS CABECERA
#include <rosian.h> //CABECERAS STDIO, CONIO Y WINDOWS YA INCLUIDAS
#pragma GCC diagnostic ignored "-Wwrite-strings"
//DECLARACION DE VARIABLES Y ESTRUCTURA
struct sproveedor
{
	int codi; //CODIGO DE PROVEEDOR
	char nomb[20]; //NOMBRE DE PROVEEDOR
	//char nruc[13]; //NUMERO DE RUC //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char dire[40]; //DIRECCION
	char ciud[20]; //CIUDAD
	//char tele[10]; //TELEFONO //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char mail[25]; //EMAIL
	char esta; //ESTADO
};
struct sproveedor prov[100];
int inde=0;//CONTADOR INDICA LA CANTIDAD DE REGISTROS INGRESADOS
int secu=1; //SECUENCIAL
int inic=0;// PAGINACION VALOR DE INICIO
int fin=24;// PAGINACION VALOR DE FINAL
//DECLARACION DE LAS FUNCIONES DE USUARIO
char menu(); //.............................................................................................HECHO
void nuevo(); //............................................................................................HECHO
void modificar(); //........................................................................................HECHO
void eliminar(); //.........................................................................................HECHO
void ordenar_nombre(); //...................................................................................HECHO
void guardar(); //..........................................................................................HECHO
void cargar(); //...........................................................................................HECHO
void consulta_general(); //.................................................................................HECHO
void consulta_individual(); //..............................................................................HECHO
void filtrar(); //..........................................................................................HECHO
char* entrada_cadena_modificada(int colu, int fila, int caso, int limi); //FUNCION CUSTOM
//CUERPO DEL PROGRAMA
int main()
{
	char opci;
	system("title TRENDXPRESS [PROVEEDOR]");
	system("mode con: cols=160 lines=40");
	pantalla("TIENDA DE ROPA <TRENDXPRESS>","Ruc:1234567890001  Tel:0982788880","Guayaquil - Ecuador", "PROVEEDOR");
	cargar();// MOVEMOS LA INFORMACION DEL ARCHIVO A ARREGLO DE ESTRUCTURA
	char cade[50];
	do
	{
		bp(4);
		consulta_general();
		opci=menu();
		switch(opci)
		{
			case '1':
				nuevo();
				break;
			case '2':
				modificar();
				break;
			case '3':
				eliminar();
				break;
			case '4':
				consulta_individual();
				break;
			case '5':
				ordenar_nombre();
				break;
			case '6':
				filtrar();
				break;
			case 'A':
				if(inic>0)
				{
					inic=inic-24;
					fin=fin-24;
					bp(4);
				}
				break;
			case 'S':
				if(fin<inde)
				{
					inic=inic+24;
					fin=fin+24;
					bp(4);
				}
		}
	}while(opci!='0');	
	//FIN DEL PROGRAMA
	getch();
}
//DESARROLLOS DE FUNCIONES
char menu()
{
	char opci;
	bp(2);
	etiqueta("MENU DE PROVEEDOR",'C',0,10,80);
	etiqueta("Nuevo...........................[ 1 ]",'C',0,12,80);
	etiqueta("Modificar.......................[ 2 ]",'C',0,14,80);
	etiqueta("Eliminar........................[ 3 ]",'C',0,16,80);
	etiqueta("Mostrar.........................[ 4 ]",'C',0,18,80);
	etiqueta("Ordenar.........................[ 5 ]",'C',0,20,80);
	etiqueta("Filtrar.........................[ 6 ]",'C',0,22,80);
	etiqueta("Regresar al menu................[ 0 ]",'C',0,24,80);
	etiqueta("Elija la opcion: ",'C',0,26,80);
	opci=toupper(getch());
	return opci;
} 
//FUNCIONES DE USUARIO
void nuevo()//FUNCION DE INGRESO DE REGISTRO
{
	char opci;
	char cade[50];
	char auxi[50];
	bp(2);
	etiqueta("INGRESANDO NUEVO REGISTRO",'C',1,10,80);
	prov[inde].codi=secu;
	etiqueta("Codigo............:",'I',15,12,0);
	etiqueta("Nombre............:",'I',15,14,0);
	//etiqueta("Numero RUC........:",'I',15,16,0); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	etiqueta("Direccion.........:",'I',15,18,0);
	etiqueta("Ciudad............:",'I',15,20,0);
	//etiqueta("Telefono..........:",'I',15,22,0); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	etiqueta("Email.............:",'I',15,24,0);
	etiqueta("Estado............:",'I',15,26,0);
	entrada_secuencia(35,12,secu); //SECUENCIA AUTOMATICA DE INGRESO NUEVO PARA EL NUMERO DE CODIGO DE PROVEEDOR	
	/**********FUNCION ENTRADA_CADENA MODIFICADA**********/
	strcpy(prov[inde].nomb, entrada_cadena_modificada(35, 14, 1, 20));
	//strcpy(prov[inde].nruc, entrada_cadena_modificada(35, 16, 2, 13)); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	strcpy(prov[inde].dire, entrada_cadena_modificada(35, 18, 3, 40));
	strcpy(prov[inde].ciud, entrada_cadena_modificada(35, 20, 1, 20)); 
	//strcpy(prov[inde].tele, entrada_cadena_modificada(35, 22, 2, 10)); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	strcpy(prov[inde].mail, entrada_cadena_modificada(35, 24, 4, 25));
	/*****************************************************/
	poscf(35,26);
	do
	{
		opci=toupper(getch());
	}while(opci!='A' && opci!='I');
	poscf(35, 26); printf("%c",opci);
	prov[inde].esta=opci;
	mensaje('P',"¿Esta seguro de guardar el registro?");
	do
	{
		opci=toupper(getch());
	}while(opci!='S' && opci!='N');
	
	bp(3);	
	if(opci=='S')
	{
		inde++;	
		secu++;
		mensaje('I',"Registro guardado con exito");
	    bp(3);
	    guardar();// FUNCION QUE MUEVE LOS DATOS DEL ARREGLO DE ESTRUCTURA AL FICHERO
	}		
}
void modificar()//FUNCION QUE MODIFICA LOS REGISTRO
{
	int band=0;
	int dato=0;
	int cont=0;
	char auxi[10];
	
	char nomb[20]; //NOMBRE DE PROVEEDOR
	//char nruc[13]; //NUMERO DE RUC //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char dire[40]; //DIRECCION
	char ciud[20]; //CIUDAD
	//char tele[10]; //TELEFONO //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char mail[25]; //EMAIL
	
	char esta;
	char opci;
	char cade[50];
	bp(2);
	etiqueta("MODIFICANDO REGISTRO",'C',1,10,80);
	
	poscf(15,14);printf("Codigo a modificar: ");
	gets(auxi);
	dato=atoi(auxi);	

	for(cont=0;cont<inde;cont++)
	{
		if(dato==prov[cont].codi)
		{
			if(prov[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}
			poscf(15,16);printf("Nombre............: %s",prov[cont].nomb);
			//poscf(15,18);printf("RUC...............: %s",prov[cont].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,20);printf("Direccion.........: %s",prov[cont].dire);
			poscf(15,22);printf("Ciudad............: %s",prov[cont].ciud);
			//poscf(15,24);printf("Telefono..........: %s",prov[cont].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,26);printf("Email.............: %s",prov[cont].mail);			
			poscf(15,28);printf("Estado............: %c - %s",prov[cont].esta,auxi);
			
			band=1;
			mensaje('P',"¿Desea modificar el registro?");
			opci=toupper(getch());
			bp(3);
			if(opci=='S')
			{
				poscf(15,16);printf("                                              ");
				poscf(15,16);printf("Nombre............: ");
				strcpy(nomb,entrada_cadena_modificada(35,16,1,20));
				/*DESABILITADA POR FUNCIONAMIENTO INESPERADO
				poscf(15,18);printf("                                              ");
				poscf(15,18);printf("RUC...............: ");
				strcpy(nruc,entrada_cadena_modificada(35,18,2,13));
				*/
				poscf(15,20);printf("                                              ");
				poscf(15,20);printf("Direccion.........: ");
				strcpy(dire,entrada_cadena_modificada(35,20,3,40));
				
				poscf(15,22);printf("                                              ");
				poscf(15,22);printf("Ciudad............: ");
				strcpy(ciud,entrada_cadena_modificada(35,22,1,20));
				/*DESABILITADA POR FUNCIONAMIENTO INESPERADO
				poscf(15,24);printf("                                              ");
				poscf(15,24);printf("Telefono..........: ");
				strcpy(tele,entrada_cadena_modificada(35,24,2,10));
				*/
				poscf(15,26);printf("                                              ");
				poscf(15,26);printf("Email.............: ");
				strcpy(mail,entrada_cadena_modificada(35,26,4,25));
				
				poscf(15,28);printf("                                              ");
				poscf(15,28);printf("Estado............: ");
				esta=toupper(getche());
				
				mensaje('P',"¿Esta seguro de Modificar el registro?");	
				opci=toupper(getch());
				bp(3);
				if(opci=='S')	
				{
					strcpy(prov[cont].nomb,nomb);
					
					//strcpy(prov[cont].nruc,nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
					strcpy(prov[cont].dire,dire); 
					strcpy(prov[cont].ciud,ciud);
					//strcpy(prov[cont].tele,tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
					strcpy(prov[cont].mail,mail);
					
					prov[cont].esta=esta;
					mensaje('I',"Registro guardado con exito");
				    bp(3);
				    guardar();	
				}
			}
			bp(3);
		}
	}
}
void eliminar()
{
	int band=0;
	int dato=0;
	int cont=0;
	char auxi[10];
	
	char nomb[20]; //NOMBRE DE PROVEEDOR
	//char nruc[13]; //NUMERO DE RUC //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char dire[40]; //DIRECCION
	char ciud[20]; //CIUDAD
	//char tele[10]; //TELEFONO //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char mail[25]; //EMAIL	
	
	char esta;
	char opci;
	int vcol; //VALOR DE CONLUMNA
	char cade[50];
	bp(2);
	etiqueta("ELIMINANDO REGISTRO",'C',1,10,80);
	
	poscf(15,14);printf("Codigo a eliminar.: ");
	gets(auxi);
	dato=atoi(auxi);	

	for(cont=0;cont<inde;cont++)
	{
		if(dato==prov[cont].codi)
		{
			if(prov[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}	 
			poscf(15,16);printf("Nombre............: %s",prov[cont].nomb);
			//poscf(15,18);printf("RUC...............: %s",prov[cont].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,20);printf("Direccion.........: %s",prov[cont].dire);
			poscf(15,22);printf("Ciudad............: %s",prov[cont].ciud);
			//poscf(15,24);printf("Telefono..........: %s",prov[cont].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,26);printf("Email.............: %s",prov[cont].mail);			
			poscf(15,28);printf("Estado............: %c - %s",prov[cont].esta,auxi);
			
			band=1;
			mensaje('P',"¿Desea Eliminar el registro?");
			opci=toupper(getch());
			bp(3);
			if(opci=='S')
			{
				while(cont<inde)
				{
					prov[cont].codi=prov[cont+1].codi;
					
					strcpy(prov[cont].nomb,prov[cont+1].nomb);
					//strcpy(prov[cont].nruc,prov[cont+1].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
					strcpy(prov[cont].dire,prov[cont+1].dire);
					strcpy(prov[cont].ciud,prov[cont+1].ciud);
					//strcpy(prov[cont].tele,prov[cont+1].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
					strcpy(prov[cont].mail,prov[cont+1].mail);					
					prov[cont].esta=prov[cont+1].esta;	
					cont++;
				}
				inde--;
				mensaje('I',"Registro eliminado con exito");
			    bp(3);
			    guardar();	
			}
			bp(3);
		}
	}
}
void consulta_individual()//FUNCION QUE MUESTRA LOS DATOS DE UN REGISTRO
{
	int band=0;
	int dato=0;
	int cont=0;
	char auxi[10];
	int vcol; //VALOR DE CONLUMNA
	char cade[50];
	bp(2);
	etiqueta("CONSULTA INDIVIDUAL REGISTRO",'C',1,10,80);
	
	poscf(15,12);printf("Codigo a buscar...: ");
	gets(auxi);
	dato=atoi(auxi);	

	for(cont=0;cont<inde;cont++)
	{
		if(dato==prov[cont].codi)
		{
			if(prov[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}	 
			
			
			poscf(15,16);printf("Nombre............: %s",prov[cont].nomb);
			//poscf(15,18);printf("RUC...............: %s",prov[cont].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,20);printf("Direccion.........: %s",prov[cont].dire);
			poscf(15,22);printf("Ciudad............: %s",prov[cont].ciud);
			//poscf(15,24);printf("Telefono..........: %s",prov[cont].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			poscf(15,26);printf("Email.............: %s",prov[cont].mail);			
			poscf(15,28);printf("Estado............: %c - %s",prov[cont].esta,auxi);
			
			band=1;
			mensaje('I',"Registro encontrado");
			bp(3);
		}	
	}
	if(band==0)
	{
		mensaje('I',"Registro no encontrado");
		bp(3);
	}
}
void ordenar_nombre()
{
	char pal1[30];
	char pal2[30];
	int con1=0;
	int con2=0;
	int con3=0;
	
	int codi; //CODIGO DE PROVEEDOR
	char nomb[20]; //NOMBRE DE PROVEEDOR
	//char nruc[13]; //NUMERO DE RUC //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char dire[40]; //DIRECCION
	char ciud[20]; //CIUDAD
	//char tele[10]; //TELEFONO //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char mail[25]; //EMAIL
	char esta; //ESTADO
	
	for(con1=0;con1<inde;con1++)
    {
        for(con2=con1+1;con2<inde;con2++)
        {
            strcpy(pal1,prov[con1].nomb);
			for(con3=0;con3<strlen(pal1);con3++)
			{
				pal1[con3]=toupper(pal1[con3]);
			}
			strcpy(pal2,prov[con2].nomb);
			for(con3=0;con3<strlen(pal2);con3++)
			{
				pal2[con3]=toupper(pal2[con3]);
			}	
			if(strcmp(pal1,pal2)>0)
            {
               	codi=prov[con2].codi;
               	prov[con2].codi=prov[con1].codi;
               	prov[con1].codi=codi;
               	
				strcpy(nomb,prov[con2].nomb);
				strcpy(prov[con2].nomb,prov[con1].nomb);
				strcpy(prov[con1].nomb,nomb);
				/*DESABILITADA POR FUNCIONAMIENTO INESPERADO
				strcpy(nruc,prov[con2].nruc);
				strcpy(prov[con2].nruc,prov[con1].nruc);
				strcpy(prov[con1].nruc,nruc);
				*/
				strcpy(dire,prov[con2].dire);
				strcpy(prov[con2].dire,prov[con1].dire);
				strcpy(prov[con1].dire,dire);
				
				strcpy(ciud,prov[con2].ciud);
				strcpy(prov[con2].ciud,prov[con1].ciud);
				strcpy(prov[con1].ciud,ciud);
				/*DESABILITADA POR FUNCIONAMIENTO INESPERADO
				strcpy(tele,prov[con2].tele);
				strcpy(prov[con2].tele,prov[con1].tele);
				strcpy(prov[con1].tele,tele);
				*/
				strcpy(mail,prov[con2].mail);
				strcpy(prov[con2].mail,prov[con1].mail);
				strcpy(prov[con1].mail,mail);
				
				esta=prov[con2].esta;
				prov[con2].esta=prov[con1].esta;
				prov[con1].esta=esta;
            }
        }
    }
}
void consulta_general()
{
	int fila=10;
	int cont=0;
	int vcol; //VALOR DE CONLUMNA
	char cade[50];
	poscf(80,8);printf("Codigo");
	poscf(90,8);printf("Nombre");
	poscf(120,8);printf("Ciudad");
	poscf(145,8);printf("Estado");
	for(cont=inic;cont<inde && cont<fin ;cont++)
	{
		poscf(83,fila);printf("%i",prov[cont].codi);
		poscf(90,fila);printf("%s",prov[cont].nomb);
		poscf(120,fila);printf("%s",prov[cont].ciud);
		if(prov[cont].esta=='A')
		{
			poscf(145,fila);printf("Activo");
		}
		else
		{
			poscf(145,fila);printf("Inactivo");
		}
		
		fila++;
	}
}
void filtrar()
{
	int con1=0;
	int fila=10;
	int cont=0;
	char pal1[50];
	char pal2[50];
	poscf(104,6);gets(pal1);
	bp(4);
	for(con1=0;con1<strlen(pal1);con1++)
	{
		pal1[con1]=toupper(pal1[con1]);
	}
	for(cont=0;cont<inde;cont++)
	{
		for(con1=0;con1<strlen(pal1);con1++)
		{
			pal2[con1]=toupper(prov[cont].nomb[con1]);
			pal2[con1+1]='\0';
		}
		if(strcmp(pal1,pal2)==0)
		{
			poscf(83,fila);printf("%i",prov[cont].codi);
			poscf(90,fila);printf("%s",prov[cont].nomb);
			poscf(120,fila);printf("%s",prov[cont].ciud);
			if(prov[cont].esta=='A')
			{
				poscf(145,fila);printf("Activo");
			}
			else
			{
				poscf(145,fila);printf("Inactivo");
			}
			fila++;
		}
	}
	mensaje('I',"Filtrado realizado");		
	bp(4);
	poscf(104,6);printf("                              ");
}
void guardar() 
{
    FILE *fichero;
    int cont = 0;
    char auxi[50];
    
    char nomb[50];
	//char nruc[50]; //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char dire[50];
	char ciud[50];
	//char tele[50]; //DESABILITADA POR FUNCIONAMIENTO INESPERADO
	char mail[50];

    fichero = fopen("TBPROVEEDOR.txt", "w+");
    if (fichero != NULL)
	{
        while (cont < inde)
		{
            strcpy(nomb, prov[cont].nomb);
            strcpy(nomb, compactar(nomb));

            //strcpy(nruc, prov[cont].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO

            strcpy(dire, prov[cont].dire);
            strcpy(dire, compactar(dire));

            strcpy(ciud, prov[cont].ciud);
            strcpy(ciud, compactar(ciud));

            //strcpy(tele, prov[cont].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO

            strcpy(mail, prov[cont].mail);

            fprintf(fichero, "%d\t%s\t%s\t%s\t%s\t%c\n", prov[cont].codi, nomb, dire, ciud, mail, prov[cont].esta);
            //fprintf(fichero, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%c\n", prov[cont].codi, nomb, nruc, dire, ciud, tele, mail, prov[cont].esta); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
            cont++;
        }
        fclose(fichero);
    }
	else
	{
        mensaje('X', "No se pudo abrir el archivo en forma de escritura.");
    }
}
void cargar()  //CARGAR LA INFORMACION DEL FICHERO AL ARREGLO DE ESTRUCTURA
{
	FILE *fichero; //VARIABLE TIPO FICHERO
	struct sproveedor dato;
	inde=0;
	fichero=fopen("TBPROVEEDOR.txt","r");
	if (fichero != NULL) 
	{
		//while (fscanf(fichero, "%d %s %s %s %s %s %s %c\n",&prov[inde].codi, prov[inde].nomb, prov[inde].nruc, prov[inde].dire, prov[inde].ciud, prov[inde].tele, prov[inde].mail, &prov[inde].esta) != EOF) //DESABILITADA POR FUNCIONAMIENTO INESPERADO
		while (fscanf(fichero, "%d %s %s %s %s %c\n",&prov[inde].codi, prov[inde].nomb, prov[inde].dire, prov[inde].ciud, prov[inde].mail, &prov[inde].esta) != EOF)
		{
			secu=prov[inde].codi+1;
			strcpy(prov[inde].nomb, descompactar(prov[inde].nomb));
			//strcpy(prov[inde].nruc, prov[inde].nruc); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			//strcpy(prov[inde].dire, descompactar(prov[inde].dire));
			//strcpy(prov[inde].ciud, descompactar(prov[inde].ciud));
			//strcpy(prov[inde].tele, prov[inde].tele); //DESABILITADA POR FUNCIONAMIENTO INESPERADO
			//strcpy(prov[inde].mail, prov[inde].mail);
			inde++;
		}
		fclose(fichero);
	} 
	else 
	{
        mensaje('X',"No se pudo abrir el archivo de forma de escritura.");
    }	
}
char* entrada_cadena_modificada(int colu, int fila, int caso, int limi) //FUNCION DE ENTRADA DE CADENA MODIFICADA PARA RECIBIR CARACTERES DATOS COMO NUMERO, LETRAS, CARACTERES PARA CORREO.
{
	char auxi[limi];
	char cara = 0;
	int cont = 0;
	int back = 8; //BACKSPACE
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
	poscf(colu, fila);
	while(cara != 13)
	{
		cara = getch();
		if(caso == 1) //CASO DE ENTRADA DE NOMBRE QUE RECIBE SOLAMENTE LETRAS Y EL ESPACIO
		{
			gui1 = min1;
			punt = min1;
			num1 = min1;
			num2 = min1;
			arro = min1;
			gui2 = min1;
		}
		else if(caso == 2) //CASO DE ENTRADA QUE RECIBE NUMEROS SOLAMENTE
		{
			espa = num1;
			gui1 = num1;
			punt = num1;
			arro = num1;
			may1 = num1;
			may2 = num1;
			gui2 = num1;
			min1 = num1;
			min2 = num1;
		}
		else if(caso == 3) //CASO DE ENTRADA QUE RECIBE CARACTERES DE NUMEROS Y LETRAS PARA LA DIRECCION
		{
			punt = min1;
			arro = min1;
			gui2 = min1;
		}
		else if(caso == 4) //CASO DE ENTRADA QUE RECIBE CARACTERES PARA EMAIL
		{
			espa = min1;
			may1 = min1;
			may2 = min1;
		}
		if((cara == back) || (cara == espa) || (cara == gui1) || (cara == punt) || (cara >= num1 && cara <= num2) || (cara == arro) || (cara >= may1 && cara <= may2) || (cara == gui2) || (cara >= min1 && cara <= min2))
		{
			if(cara == 8)
			{
				if(cont > 0)
				{
					auxi[cont - 1] = '\0';
					cont--;
					poscf(colu+cont,fila);printf(" ");
					poscf(colu+cont,fila);
				}
			}
			else if(cont < limi)
			{
				poscf(colu+cont,fila);printf("%c", cara);
				auxi[cont]=cara;
				auxi[cont+1]='\0';
				cont++;
			}
		}
	}
	return(auxi);
}
