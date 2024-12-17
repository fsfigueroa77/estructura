//ARCHIVO CABECERA
#include<stdio.h> 
#include<conio.h> 
#include<rosian.h> 
#pragma GCC diagnostic ignored "-Wwrite-strings"
//DECLARACION DE VARIABLES Y ESTRUCTURA
//NODO PAIS
struct spais
{
	int codi;
	char desc[25];
	char esta;
	struct spais *sigu;
};
//DECLARACION DE LA LISTA SIMPLE
typedef struct spais *LIST;

int indi=0;
int secu=1; //SECUENCIAL
int inic=0;// PAGINACION VALOR DE INICIO
int fin=24;// PAGINACION VALOR DE FINAL
int pagi=0;
//DECLARACION DE FUNCIONES DE USUARIO
char menu();
void nuevo(LIST &list);
void modificar(LIST &list);
void eliminar(LIST &list);
void ordenar_codigo(LIST &list);
void ordenar_descripcion(LIST &list);
void guardar(LIST list);
void cargar(LIST &list);
void consulta_general(LIST list);
void consulta_individual(LIST list);
void filtrar(LIST list);
void filtrar(LIST list);
//CUERPO DEL PROGRAMA
int main()
{
	LIST lpai=NULL;
	char opci;
	char cade[50];
	system("title ROSIAN PC [Pais]");
	system("mode con: cols=160 lines=40");
	system("title ROSIAN PC [Usuario]");
	cargar(lpai);
	pantalla("ASESORAMIENTO ACADEMICO <ROSIAN PC>","Ruc:1234567890001  Tel:0982788880","Guayaquil - Ecuador", "USUARIO");
	do
	{
		bp(4);
		consulta_general(lpai);		
		opci=menu();
		switch(opci)
		{
			case '1':
				nuevo(lpai);
				break;
			case '2':
				modificar(lpai);
				break;
			case '3':
				eliminar(lpai);
				break;
			case '4':
				consulta_individual(lpai);
				break;
			case '5':
				ordenar_descripcion(lpai);
				break;
			case '6':
				filtrar(lpai);
				break;
			case 'A':
				if(inic>0)
				{
					pagi--;
					inic=inic-24;
					fin=fin-24;
					bp(4);
				}
				break;
			case 'S':
				
				if(fin<indi)
				{
					pagi++;
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
	etiqueta("MENU DE USUARIO",'C',0,10,80);
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
void nuevo(LIST &list)//FUNCION DE INGRESO DE REGISTRO
{
	char opci;
	char cade[50];
	char auxi[50];
	int codi;
	char desc[25];
	char esta;
	bp(2);
	etiqueta("INGRESANDO NUEVO REGISTRO",'C',1,10,80);
	/*1.-INGRESANDO LOS DATOS A VARIABLES*/
	codi=secu;
	etiqueta("Codigo............:",'I',15,14,0);
	etiqueta("Pais..............:",'I',15,15,0);
	etiqueta("Estado............:",'I',15,16,0);
	entrada_secuencia(35,14,secu);
	strcpy(desc,entrada_cadena(35,15));
	poscf(35,16);
	do
	{
		opci=toupper(getch());
	}while(opci!='A' && opci!='I');
	poscf(35,16);printf("%c",opci);
	esta=opci;
	mensaje('P',"¿Esta seguro de guardar el registro?");
	do
	{
		opci=toupper(getch());
	}while(opci!='S' && opci!='N');
	bp(3);	
	if(opci=='S')
	{
		/*2.- CREANDO LA LISTA*/
		LIST lis1;
		lis1=new(struct spais);
		/*3.-ASIGNANDO LOS DATOS DE LA VARIABLE AL NODO*/
		lis1->codi=secu;
		strcpy(lis1->desc,desc);
		lis1->esta=esta;
		/*4.- ACTUALIZACION DE LA LISTA*/
		lis1->sigu=list;
		list=lis1;
		
		secu++;
		indi++;
		mensaje('I',"Registro guardado con exito");
	    bp(3);
	    ordenar_codigo(list);
	    guardar(list);// FUNCION QUE MUEVE LOS DATOS DEL ARREGLO DE ESTRUCTURA AL FICHERO
	}		
}
void modificar(LIST &list)//FUNCION QUE MODIFICA LOS REGISTRO
{
	LIST lis1;
	lis1=list;
	int band=0;
	int dato=0;
	int cont=0;
	int codi;
	char auxi[10];
	char desc[25];
	char esta;
	char opci;
	char cade[50];
	bp(2);
	etiqueta("MODIFICANDO REGISTRO",'C',1,10,80);
	
	poscf(15,14);printf("Codigo a modificar: ");
	gets(auxi);
	dato=atoi(auxi);	

	for(cont=0;cont<indi;cont++)
	{
		if(dato==lis1->codi)
		{
			if(lis1->esta=='A') 
			{
				strcpy(auxi,"Activo");
			}
			else
			{
				strcpy(auxi,"Inactivo");
			}
			poscf(15,16);printf("Pais..............: %s",lis1->desc);
			poscf(15,17);printf("Estado............: %c - %s",lis1->esta,auxi);
			band=1;
			mensaje('P',"¿Desea modificar el registro?");
			opci=toupper(getch());
			bp(3);
			if(opci=='S')
			{
				poscf(15,16);printf("                                              ");
				poscf(15,16);printf("pais..............: ");
				strcpy(desc,entrada_cadena(35,16));
								
				poscf(15,17);printf("                                              ");
				poscf(15,17);printf("Estado............: ");
				esta=toupper(getche());
				
				mensaje('P',"¿Esta seguro de Modificar el registro?");	
				opci=toupper(getch());
				bp(3);
				if(opci=='S')	
				{
					strcpy(lis1->desc,desc);
					lis1->esta=esta;
					mensaje('I',"Registro guardado con exito");
				    bp(3);	
				}
			}
			bp(3);
		}
		lis1=lis1->sigu;
	}
	guardar(list);
}
void eliminar(LIST &list)
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
	LIST lis1;
	LIST lis2;
	bp(2);
	etiqueta("ELIMINANDO REGISTRO",'C',1,10,80);
	if(list==NULL)
	{
		mensaje('X',"Lista vacia.");
	}
	else
	{
		poscf(15,14);printf("Codigo a eliminar.: ");
		gets(auxi);
		dato=atoi(auxi);	
		lis2=list;
		for(cont=0;cont<indi;cont++)
		{
			if(dato==lis2->codi)
			{
				if(lis2->esta=='A') 
				{
					strcpy(auxi,"Activo");
				}
				else
				{
					strcpy(auxi,"Inactivo");
				}	 
				poscf(15,16);printf("Pais..............: %s",lis2->desc);
				poscf(15,17);printf("Estado............: %c - %s",lis2->esta,auxi);
				band=1;
				mensaje('P',"¿Desea Eliminar el registro?");
				opci=toupper(getch());
				bp(3);
				if(opci=='S')
				{
					if(lis2==list)	
						list=list->sigu;
					else
						lis1->sigu=lis2->sigu;
					delete(lis2);
					indi--;
					mensaje('I',"Registro eliminado con exito");
				    bp(3);
					break;	
				}
				bp(3);
			}
			lis1=lis2;
			lis2=lis2->sigu;
		}
		guardar(list);
	}
}
void consulta_individual(LIST list)//FUNCION QUE MUESTRA LOS DATOS DE UN REGISTRO
{
	int band=0;
	int dato=0;
	int cont=0;
	char auxi[10];
	int vcol; //VALOR DE CONLUMNA
	char cade[50];
	LIST lis1;
	bp(2);
	etiqueta("CONSULTA INDIVIDUAL REGISTRO",'C',1,10,80);
	if(list==NULL)
	{
		mensaje('X',"Lista vacia.");
	}
	else
	{	
		poscf(15,12);printf("Codigo a buscar...: ");
		gets(auxi);
		dato=atoi(auxi);	
		lis1=list;
		for(cont=0;cont<indi;cont++)
		{
			if(dato==lis1->codi)
			{
				if(lis1->esta=='A') 
				{
					strcpy(auxi,"Activo");
				}
				else
				{
					strcpy(auxi,"Inactivo");
				}	 
				poscf(15,16);printf("Apellido..........: %s",lis1->desc);
				poscf(15,17);printf("Estado............: %c - %s",lis1->esta,auxi);
				band=1;
				mensaje('I',"Registro encontrado");
				bp(3);
				break;
			}
			lis1=lis1->sigu;	
		}
		if(band==0)
		{
			mensaje('I',"Registro no encontrado");
			bp(3);
		}
	}
}

void ordenar_descripcion(LIST &list)
{
	LIST lis1=NULL;
	LIST lis2;
	LIST lis3;
	char pal1[30];
	char pal2[30];
	int con1=0;
	int codi;
	char desc[25];
	char esta;
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		while(list->sigu!=lis1)
  		{  
			lis2=list;
   			lis3=lis2->sigu;
      		while(lis3!=lis1)
            {
        		strcpy(pal1,lis2->desc);
        		strcpy(pal2,lis3->desc);
        		for(con1=0;con1<strlen(pal1);con1++)
				{
					pal1[con1]=toupper(pal1[con1]);
				}
				for(con1=0;con1<strlen(pal2);con1++)
				{
					pal2[con1]=toupper(pal2[con1]);
				}	
				if (strcmp(pal1,pal2)>0)
       			{	
	               	//CODIGO		
					codi=lis2->codi;
					lis2->codi=lis3->codi;
        			lis3->codi=codi;
	
	
					//NOMBRE		
					strcpy(desc,lis2->desc);
					strcpy(lis2->desc,lis3->desc);
        			strcpy(lis3->desc,desc); 
					
					esta=lis2->esta;
					lis2->esta=lis3->esta;
        			lis3->esta=esta;  
				}
         		else
          		{
           			lis2=lis3;
           			lis3=lis3->sigu; 
				}
            }
            lis1=lis2;
        }
    }
    mensaje('I',"LISTA ORDENADA");
}

void ordenar_codigo(LIST &list)
{
	LIST lis1=NULL;
	LIST lis2;
	LIST lis3;
	char pal1[30];
	char pal2[30];
	int con1=0;
	int con2=0;
	int con3=0;
	int codi;
	char desc[25];
	char esta;
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		while(list->sigu!=lis1)
  		{  
			lis2=list;
   			lis3=lis2->sigu;
      		while(lis3!=lis1)
            {
        		if (lis2->codi>lis3->codi)
       			{	
	               	//CODIGO		
					codi=lis2->codi;
					lis2->codi=lis3->codi;
        			lis3->codi=codi;
	
	
					//NOMBRE		
					strcpy(desc,lis2->desc);
					strcpy(lis2->desc,lis3->desc);
        			strcpy(lis3->desc,desc); 
					
					esta=lis2->esta;
					lis2->esta=lis3->esta;
        			lis3->esta=esta;  
				}
         		else
          		{
           			lis2=lis3;
           			lis3=lis3->sigu; 
				}
            }
            lis1=lis2;
        }
    }
}

void consulta_general(LIST list)
{
	int fila=10;
	int cont=0;
	int vcol; //VALOR DE CONLUMNA
	char cade[50];
	poscf(80,8);printf("Codigo");
	poscf(90,8);printf("Pais");
	poscf(130,8);printf("Estado");
	if(list!=NULL)
	{
		for(cont=0; cont<pagi*24 ;cont++)
		{
			list=list->sigu;
		}
		for(cont=inic;cont<indi && cont<fin ;cont++)
		{
			poscf(83,fila);printf("%i",list->codi);
			poscf(90,fila);printf("%s",list->desc);
			if(list->esta=='A')
			{
				poscf(130,fila);printf("Activo");
			}
			else
			{
				poscf(130,fila);printf("Inactivo");
			}
			list=list->sigu;
			fila++;
		}
	}
}

void filtrar(LIST list)
{
	int con1=0;
	int fila=10;
	int cont=0;
	char pal1[50];
	char pal2[50];
	char cade[50];
	LIST lis1;
	lis1=list;
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		poscf(104,6);gets(pal1);
		bp(4);
		for(con1=0;con1<strlen(pal1);con1++)
		{
			pal1[con1]=toupper(pal1[con1]);
		}
		for(cont=0;cont<indi;cont++)
		{
			strcpy(cade,lis1->desc);
			for(con1=0;con1<strlen(pal1);con1++)
			{
				pal2[con1]=toupper(cade[con1]);
				pal2[con1+1]='\0';
			}
			if(strcmp(pal1,pal2)==0)
			{
				poscf(83,fila);printf("%i",lis1->codi);
				poscf(90,fila);printf("%s",lis1->desc);
				if(lis1->esta=='A')
				{
					poscf(150,fila);printf("Activo");
				}
				else
				{
					poscf(150,fila);printf("Inactivo");
				}
				fila++;
			}
			lis1=lis1->sigu;
		}
		mensaje('I',"Filtrado realizado");		
		bp(4);
		poscf(104,6);printf("                              ");
	}	
}

void guardar(LIST list)
{
	FILE *fichero;
	int cont=0;
	char desc[25];
	fichero=fopen("TBPAIS.txt","w+");
	if (fichero != NULL) 
	{
		while(cont<indi)
		{
			strcpy(desc,list->desc); 
			strcpy(desc,compactar(desc));						
			fprintf(fichero, "%d\t%s\t%c\n",list->codi, desc,list->esta);
			cont++;
			if(list!=NULL)
				list=list->sigu;
		}
		fclose(fichero);
	} 
	else 
	{
        mensaje('X',"No se pudo abrir el archivo en forma de lectura.");
    }	
}
void cargar(LIST &list)  //CARGAR LA INFORMACION DEL FICHERO AL ARREGLO DE ESTRUCTURA
{
	FILE *fichero; //VARIABLE TIPO FICHERO
	indi=0;
	int codi;
	char desc[25];
	char esta;
	fichero=fopen("TBPAIS.txt","r");
	if (fichero != NULL) 
	{
		while (fscanf(fichero, "%d %s %c\n",&codi, &desc,&esta) != EOF)
		{
			LIST lis1;
			LIST lis2;
			lis1=new(struct spais);
			lis1->codi=codi;
			strcpy(lis1->desc,descompactar(desc));
			lis1->esta=esta;
			secu=codi+1;
			indi++;
			if(list==NULL)
			{
				lis1->sigu=list;
				list=lis1;
			}
			else
			{
				lis1->sigu=NULL;
				lis2=list;
				while(lis2->sigu!=NULL)
				{
					lis2=lis2->sigu;
				}
				lis2->sigu=lis1;
			}
		}
		fclose(fichero);
	} 
	else 
	{
        mensaje('X',"No se pudo abrir el archivo de forma de escritura.");
    }	
}
