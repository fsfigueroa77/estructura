/*********************************************************************
****   PROYECTO ROSIAN                                        ********
**** DESARROLLADOR: PADILLA GOMEZ RENZO ROGELIO    *******************/

//ARCHIVO CABECERA
#include<stdio.h> 
#include<conio.h> 
#include<rosian.h> 
#pragma GCC diagnostic ignored "-Wwrite-strings"
//DECLARACION DE VARIABLES Y ESTRUCTURA
struct spais
{
	int codi;
	char desc[30];
	char esta;
};
struct spais pais[100];

int inde=0;//CONTADOR INDICA LA CANTIDAD DE REGISTROS INGRESADOS
int secu=1; //SECUENCIAL
int inic=0;// PAGINACION VALOR DE INICIO
int fin=24;// PAGINACION VALOR DE FINAL
//DECLARACION DE LAS FUNCIONES DE USUARIO
char menu();
void nuevo();
void modificar();
void eliminar();
void ordenar_descripcion();
void guardar();
void cargar();
void consulta_general();
void consulta_individual();
void filtrar();
int main()
{
	char opci;
	system("title ROSIAN PC [Pais]");
	system("mode con: cols=160 lines=40");
	pantalla("ASESORAMIENTO ACADEMICO <ROSIAN PC>","Ruc:1234567890001  Tel:0982788880","Guayaquil - Ecuador", "PAIS");
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
				ordenar_descripcion();
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
	etiqueta("MENU DE PAIS",'C',0,10,80);
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
	pais[inde].codi=secu;
	etiqueta("Codigo............:",'I',15,14,0);
	etiqueta("Descripcion.......:",'I',15,16,0);
	etiqueta("Estado............:",'I',15,18,0);
	entrada_secuencia(35,14,secu);
	strcpy(pais[inde].desc,entrada_cadena(35,16));
	poscf(35,18);
	do
	{
		opci=toupper(getch());
	}while(opci!='A' && opci!='I');
	poscf(35,18);printf("%c",opci);
	pais[inde].esta=opci;
	

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
	char desc[30];
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
		if(dato==pais[cont].codi)
		{
			if(pais[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}
			poscf(15,16);printf("Descripcion.......: %s",pais[cont].desc);
			poscf(15,18);printf("Estado............: %c - %s",pais[cont].esta,auxi);
			band=1;
			mensaje('P',"¿Desea modificar el registro?");
			opci=toupper(getch());
			bp(3);
			if(opci=='S')
			{
				poscf(15,16);printf("                                              ");
				poscf(15,16);printf("Descripcion.......: ");
				strcpy(desc,entrada_cadena(35,16));
				
				poscf(15,18);printf("                                              ");
				poscf(15,18);printf("Estado............: ");
				esta=toupper(getche());
				
				mensaje('P',"¿Esta seguro de Modificar el registro?");	
				opci=toupper(getch());
				bp(3);
				if(opci=='S')	
				{
					strcpy(pais[cont].desc,desc);
					pais[cont].esta=esta;
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
	char desc[30];
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
		if(dato==pais[cont].codi)
		{
			if(pais[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}	 
			poscf(15,16);printf("Descripcion.......: %s",pais[cont].desc);
			poscf(15,18);printf("Estado............: %c - %s",pais[cont].esta,auxi);
			band=1;
			mensaje('P',"¿Desea Eliminar el registro?");
			opci=toupper(getch());
			bp(3);
			if(opci=='S')
			{
				while(cont<inde)
				{
					pais[cont].codi=pais[cont+1].codi;
					strcpy(pais[cont].desc,pais[cont+1].desc);
					pais[cont].esta=pais[cont+1].esta;	
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
		if(dato==pais[cont].codi)
		{
			if(pais[cont].esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}	 
			poscf(15,14);printf("Descripcion.......: %s",pais[cont].desc);
			poscf(15,16);printf("Estado............: %c - %s",pais[cont].esta,auxi);
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

void ordenar_descripcion()
{
	char pal1[30];
	char pal2[30];
	int con1=0;
	int con2=0;
	int con3=0;
	int codi=0;
	char desc[30];
	char esta;
	for(con1=0;con1<inde;con1++)
    {
        for(con2=con1+1;con2<inde;con2++)
        {
            strcpy(pal1,pais[con1].desc);
			for(con3=0;con3<strlen(pal1);con3++)
			{
				pal1[con3]=toupper(pal1[con3]);
			}
			strcpy(pal2,pais[con2].desc);
			for(con3=0;con3<strlen(pal2);con3++)
			{
				pal2[con3]=toupper(pal2[con3]);
			}	
			if(strcmp(pal1,pal2)>0)
            {
               	codi=pais[con2].codi;
               	pais[con2].codi=pais[con1].codi;
               	pais[con1].codi=codi;
				strcpy(desc,pais[con2].desc);
				strcpy(pais[con2].desc,pais[con1].desc);
				strcpy(pais[con1].desc,desc);
				esta=pais[con2].esta;
				pais[con2].esta=pais[con1].esta;
				pais[con1].esta=esta;
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
	poscf(90,8);printf("Descripcion");
	poscf(145,8);printf("Estado");
	for(cont=inic;cont<inde && cont<fin ;cont++)
	{
		poscf(83,fila);printf("%i",pais[cont].codi);
		poscf(90,fila);printf("%s",pais[cont].desc);
		if(pais[cont].esta=='A')
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
			pal2[con1]=toupper(pais[cont].desc[con1]);
			pal2[con1+1]='\0';
		}
		if(strcmp(pal1,pal2)==0)
		{
			poscf(83,fila);printf("%i",pais[cont].codi);
			poscf(90,fila);printf("%s",pais[cont].desc);
			if(pais[cont].esta=='A')
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
	int cont=0;
	char auxi[50];
	fichero=fopen("TBPAIS.txt","w+");
	if (fichero != NULL) 
	{
		while(cont<inde)
		{
			strcpy(auxi,pais[cont].desc);
			strcpy(auxi,compactar(auxi));
			fprintf(fichero, "%d\t%s\t%c\n",pais[cont].codi, auxi, pais[cont].esta);
			cont++;
		}
		fclose(fichero);
	} 
	else 
	{
        mensaje('X',"No se pudo abrir el archivo en forma de lectura.");
    }	
}
void cargar()  //CARGAR LA INFORMACION DEL FICHERO AL ARREGLO DE ESTRUCTURA
{
	FILE *fichero; //VARIABLE TIPO FICHERO
	struct spais dato;
	inde=0;
	fichero=fopen("TBPAIS.txt","r");
	if (fichero != NULL) 
	{
		while (fscanf(fichero, "%d %s %c\n",&pais[inde].codi, pais[inde].desc,&pais[inde].esta) != EOF)
		{
			secu=pais[inde].codi+1;
			strcpy(pais[inde].desc,descompactar(pais[inde].desc));
			inde++;
		}
		fclose(fichero);
	} 
	else 
	{
        mensaje('X',"No se pudo abrir el archivo de forma de escritura.");
    }	
}


