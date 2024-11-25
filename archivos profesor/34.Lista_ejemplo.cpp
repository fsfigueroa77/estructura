// ARCHIVO CABECERA
#include<stdio.h>
#include<conio.h>
#include<windows.h>
//DECLARACION DE VARIABLES
struct snodo
{
   int codi;
   char nomb[20];
   int edad;
   float peso;
   char eciv;
   struct snodo *sigu;
};
typedef struct snodo *LIST;
int secu=1;
//DECLARACION DE FUNCIONES DE USUARIO
void insertar_nodo_inicio(LIST &list);
void insertar_nodo_final(LIST &list);
void inserar_nodo_posicionx(LIST &list);
void eliminar_nodo_inicio(LIST &list);
void eliminar_nodo_final(LIST &list);
void eliminar_nodo_posicionx(LIST &list);
void vaciar_lista(LIST &list);
void modificar_elemento_lista(LIST &list);
void ordenar_lista(LIST &list);
void buscar_elemento_lista(LIST list);
void mostrar_lista(LIST list);
void poscf(int c, int f);
void ordenar_lista_nombre(LIST &list);
int main()
{
	//CREACION DE LISTA LOCAL PARA ALMACENAR LOS DATOS Y DECLARACION DE VARIABLES
	char opci;
	LIST list=NULL;
	do
	{
		system("cls");
		poscf(10, 3);printf("Menu principal");
		poscf(10, 4);printf("Mostrara lista........................[ 1 ]");
		poscf(10, 5);printf("Insertar nodo al inicio...............[ 2 ]");
		poscf(10, 6);printf("Insertar nodo al final................[ 3 ]");
		poscf(10, 7);printf("Insertar nodo a la posicion x.........[ 4 ]");
		poscf(10, 8);printf("Eliminar nodo al inicio...............[ 5 ]");
		poscf(10, 9);printf("Eliminar nodo al final................[ 6 ]");
		poscf(10,10);printf("Eliminar nodo a la posicion x.........[ 7 ]");
		poscf(10,11);printf("Consulta un nodo......................[ 8 ]");
		poscf(10,12);printf("Modificar datos de un nodo............[ 9 ]");
		poscf(10,13);printf("Ordenar lista por codigo..............[ A ]");
		poscf(10,14);printf("Vaciar la  lista......................[ B ]");
		poscf(10,14);printf("Ordenar lista por nombre..............[ C ]");
		poscf(10,15);printf("Salir.................................[ 0 ]");
		poscf(10,16);printf("Elija la Opcion:");
		opci=toupper(getch());
		//toupper().- TRANSFORMA EL CARACTER A MAYUSCULA
		//tolower().- TRANSFORMA EL CARACTER A MINUSCULA
		switch(opci)
		{
			case '1':
				mostrar_lista(list);
				break;
			case '2':
				insertar_nodo_inicio(list);
				break;
			case '3':
				insertar_nodo_final(list);
				break;
			case '4':
				inserar_nodo_posicionx(list);
				break;
			case '5':
				eliminar_nodo_inicio(list);
				break;
			case '6':
				eliminar_nodo_final(list);
				break;
			case '7':
				eliminar_nodo_posicionx(list);
				break;
			case '8':
				buscar_elemento_lista(list);
				break;
			case '9':
				modificar_elemento_lista(list);
				break;
			case 'A':
				ordenar_lista(list);
				break;
			case 'B':
				vaciar_lista(list);
				break;
			case 'C':
				ordenar_lista_nombre(list);
				
		}
	}while(opci!='0');
}
//DESARROLLO DE FUNCIONES
void insertar_nodo_inicio(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES
	int codi;
	char auxi[10];
	char nomb[20];
   	int edad;
   	float peso;
   	char eciv;
   	poscf(10,2);printf("INGRESO DE UN NODO AL INICIO:");
   
   	//INGRESODE DATOS A VARIABLES
	poscf(10,3);printf("INGRESO DE DATOS:");
	poscf(10,5);printf("Codigo..........: %i", secu);
	poscf(10,6);printf("Nombre..........:");
	gets(nomb);
	poscf(10,7);printf("Edad............:");
	gets(auxi);	
	edad=atoi(auxi);
	poscf(10,8);printf("Peso............:");
	gets(auxi);	
	peso=atof(auxi);
	poscf(10,9);printf("Estado civil....:");
	eciv=toupper(getche());
	
	//CREAR ENTORNOS DE LISTA Y NODO
	LIST lis1;
	lis1=new(struct snodo);
	
	
	//ASIGNACION DE DATOS AL NODO
	lis1->codi=secu;
	strcpy(lis1->nomb,nomb);
	lis1->edad=edad;
	lis1->peso=peso;
	lis1->eciv=eciv;
	
	//ACTUALIZACION DE LA LISTA
	lis1->sigu=list;
	list=lis1;
	
	secu++;
}

void insertar_nodo_final(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES
	int codi;
	char auxi[10];
	char nomb[20];
   	int edad;
   	float peso;
   	char eciv;	
   	
	poscf(10,2);printf("INGRESO DE UN NODO AL FINAL:");
	//INGRESO DE DATOS A VARIABLES
	poscf(10,3);printf("INGRESO DE DATOS:");
	poscf(10,5);printf("Codigo..........: %i", secu);
	poscf(10,6);printf("Nombre..........:");
	gets(nomb);
	poscf(10,7);printf("Edad............:");
	gets(auxi);	
	edad=atoi(auxi);
	poscf(10,8);printf("Peso............:");
	gets(auxi);	
	peso=atof(auxi);
	poscf(10,9);printf("Estado civil....:");
	eciv=toupper(getche());
	
	//CREAR ENTORNOS DE LISTA Y NODO
	LIST lis1;
	LIST lis2;
	lis1=new(struct snodo);
	
	//ASIGNACION DE DATOS AL NODO
	lis1->codi=secu;
	strcpy(lis1->nomb,nomb);
	lis1->edad=edad;
	lis1->peso=peso;
	lis1->eciv=eciv;

	//ACTUALIZACION DE LA LISTA
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
	
	secu++;
}

void inserar_nodo_posicionx(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES
	int codi;
	char auxi[10];
	char nomb[20];
   	int edad;
   	int posi=0;
   	int band=0;
   	float peso;
   	char eciv;	
	poscf(10,2);printf("INGRESO DE UN NODO EN LA POSICION X:");
	
	//INGRESODE DATOS A VARIABLES
	poscf(10,3);printf("INGRESO DE DATOS:");
	poscf(10,5);printf("Codigo..........: %i", secu);
	poscf(10,6);printf("Nombre..........:");
	gets(nomb);
	poscf(10,7);printf("Edad............:");
	gets(auxi);	
	edad=atoi(auxi);
	poscf(10,8);printf("Peso............:");
	gets(auxi);	
	peso=atof(auxi);
	poscf(10,9);printf("Estado civil....:");
	eciv=toupper(getche());	
	
	poscf(10,10);printf("insertar en Posicion:");
	gets(auxi);
	
	posi=atoi(auxi);
	//CREAR ENTORNOS DE LISTA Y NODO
	LIST lis1;
	LIST lis2;
	lis1=new(struct snodo);
	int cont=0;
		
//ASIGNACION DE DATOS AL NODO
	lis1->codi=secu;
	strcpy(lis1->nomb,nomb);
	lis1->edad=edad;
	lis1->peso=peso;
	lis1->eciv=eciv;
	
	
	
	//ACTUALIZACION DE LA LISTA
	if(list==NULL)
	{
		poscf(10,21);printf("Lista Vacia");
		poscf(10,22);printf("Al no haber  datos en lista sus datos sera el primer elemento");
		lis1->sigu=list;
		list=lis1;
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		cont=1;
		lis2=list;
		band=0;
		while(lis2->sigu!=NULL)
		{
			if(posi-1==cont) 
			{
				band=1;
				break;
			}
			cont++;
			lis2=lis2->sigu;
			
		}	
		if(band==0)
		{
			lis1->sigu=NULL;
			lis2->sigu=lis1;
			poscf(10,22);printf("La posicion esta fuera rango por lo tanto se lo asignara al final");
			poscf(10,23);printf("presione cualquier tecla para continuar");
			getch();
		}
		else
		{
			lis1->sigu = lis2->sigu;
			lis2->sigu = lis1;
		}

	}
}

void eliminar_nodo_inicio(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTAS
	char auxi[10];
	LIST lis1;
	
	poscf(10,2);printf("ELIMINAR UN NODO AL INICIO:");
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		lis1=list;
		list=list->sigu;
		delete(lis1);
	}

}
void eliminar_nodo_final(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTAS
	LIST lis1;
	LIST lis2;
	int band=0;
	poscf(10,2);printf("ELIMINAR UN NODO AL FINAL:");

	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		lis1=list;
		while(lis1->sigu!=NULL)
		{
			lis2=lis1;
			lis1=lis1->sigu;
			band=1;
		}
		if(band==1)
		{
			lis2->sigu=NULL;
			delete(lis1);
		}
		else
		{
			lis2=list;
			list=list->sigu;
			delete(lis2);
		}
			
	}
}
void eliminar_nodo_posicionx(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTAS
	LIST lis1;
	LIST lis2;
	char auxi[10];
	int posi=0;
	int cont=0;
	poscf(10,2);printf("ELIMINAR UN NODO A LA POSICION X:");

	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		poscf(10,6);printf("Posicion:");
		gets(auxi);
		posi=atoi(auxi);
		
		lis2=list;
		while(lis2!=NULL)
		{
			if(posi-1==cont)
			{
				if(lis2==list)	
					list=list->sigu;
				else
					lis1->sigu=lis2->sigu;
				delete(lis2);
				break;
			}
			cont++;
			lis1=lis2;
			lis2=lis2->sigu;
		}
	}
}

void mostrar_lista(LIST list)
{
	system("cls");
	poscf(10,3);printf("LISTADO DE NUMEROS");
	int fila=0;
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
	}
	else
	{
		while(list!=NULL)
 		{
  			poscf(10,4+fila);printf("%i",list->codi);
  			poscf(15,4+fila);printf("%s",list->nomb);
  			poscf(40,4+fila);printf("%i",list->edad);
  			poscf(55,4+fila);printf("%.2f",list->peso);
  			poscf(65,4+fila);printf("%c",list->eciv);
  			fila++;
    		list=list->sigu;
    	}
	}
	poscf(10,23);printf("Presione cualquier tecla para continuar");
	getch();
}

void vaciar_lista(LIST &list)
{
	system("cls");
	poscf(10,3);printf("VACIAR LISTA :");
	LIST lis1;
	char auxi[10];
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("<presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		while(list!=NULL)
		{
			lis1=list;
			list=list->sigu;
			delete(lis1);
		}
		
	}
	poscf(10,22);printf("VACIADO DE LISTA");
	poscf(10,23);printf("<presione cualquier tecla para continuar");
	getch();
}

void buscar_elemento_lista(LIST list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTAS
	int codi;
	char auxi[10];
	char nomb[20];
   	int edad;
   	bool band;
   	float peso;
	LIST lis1;
	poscf(10,3);printf("BUSCAR UN ELEMENTO DE LA LISTA:");

	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		poscf(10,6);printf("Codigo:");
		gets(auxi);
		codi=atoi(auxi);
		
		lis1=list;
		band=false;
		while(lis1!=NULL)
		{
			if(codi==lis1->codi)
			{
				poscf(10,10);printf("Datos encontrados");
				poscf(10,11);printf("Nombre.......: %s",lis1->nomb);
				poscf(10,12);printf("Edad.........: %i",lis1->edad);
				poscf(10,13);printf("Peso.........: %.2f",lis1->peso);
				poscf(10,14);printf("Estado Civi..: %c",lis1->eciv);
				poscf(10,23);printf("presione cualquier tecla para continuar");
				getch();
				band=true;
				break;
			}
			lis1=lis1->sigu;
		}
		if (band==false)
		{
			poscf(10,22);printf("Registro de datos no encontrado!!!!");
			poscf(10,23);printf("presione cualquier tecla para continuar");
			getch();
		}
	}
}

void modificar_elemento_lista(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTA
	int codi;
	char auxi[10];
	char nomb[20];
   	int edad;
   	bool band;
   	float peso;
   	char eciv;
	LIST lis1;	
	poscf(10,3);printf("MODIFICAR UN ELEMENTO DE LA LISTA:");
	if(list==NULL)
	{
		poscf(10,22);printf("Lista Vacia");
		poscf(10,23);printf("presione cualquier tecla para continuar");
		getch();
	}
	else
	{
		poscf(10,6);printf("Codigo:");
		gets(auxi);
		codi=atoi(auxi);
		
		lis1=list;
		band=false;
		while(lis1!=NULL)
		{
			if(codi==lis1->codi)
			{
				poscf(10,10);printf("Datos encontrados");
				poscf(10,11);printf("Nombre.......: %s",lis1->nomb);
				poscf(10,12);printf("Edad.........: %i",lis1->edad);
				poscf(10,13);printf("Peso.........: %.2f",lis1->peso);
				poscf(10,14);printf("Estado Civi..: %c",lis1->eciv);
				
				poscf(10,16);printf("Nuevo datos");
				//INGRESO DE DATOS
				poscf(10,17);printf("Nombre..........:");
				gets(nomb);
				poscf(10,18);printf("Edad............:");
				gets(auxi);	
				edad=atoi(auxi);
				poscf(10,19);printf("Peso............:");
				gets(auxi);	
				peso=atof(auxi);
				poscf(10,20);printf("Estado civil....:");
				eciv=toupper(getche()); //tupper() TRANFORMA UN CARACTER A MAYUSCULA
										//tolower() TRANFORMA UN CARACTER A MINUSCULA
				//ASIGNACION DE DATOS AL NODO
				strcpy(lis1->nomb,nomb);
				lis1->edad=edad;
				lis1->peso=peso;
				lis1->eciv=eciv;
				
				poscf(10,23);printf("presione cualquier tecla para continuar");
				getch();
				band=true;
				break;
			}
			lis1=lis1->sigu;
		}
		if (band==false)
		{
			poscf(10,22);printf("Registro de datos no encontrado!!!!");
			poscf(10,23);printf("presione cualquier tecla para continuar");
			getch();
		}
	}
}





void ordenar_lista(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTA
	LIST lis1=NULL;
	LIST lis2;
	LIST lis3;
	int valo;
	int codi;
	char nomb[20];
   	int edad;
   	float peso;
   	char eciv;
	poscf(10,3);printf("ORDENAR LISTA:");

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
                			//INTERCAMBIO
							//CODIGO		
							codi=lis2->codi;
      						lis2->codi=lis3->codi;
                			lis3->codi=codi;
 							//NOMBRE		
							strcpy(nomb,lis2->nomb);
      						strcpy(lis2->nomb,lis3->nomb);
                			strcpy(lis3->nomb,nomb); 
 							//EDAD		
							edad=lis2->edad;
      						lis2->edad=lis3->edad;
                			lis3->edad=edad;   
 							//PESO		
							peso=lis2->peso;
      						lis2->peso=lis3->peso;
                			lis3->peso=peso; 
 							//PESO		
							eciv=lis2->eciv;
      						lis2->eciv=lis3->eciv;
                			lis3->eciv=eciv;  							             	
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
	poscf(10,22);printf("LISTA ORDENADA");
	poscf(10,23);printf("presione cualquier tecla para continuar");
	getch();
}
void ordenar_lista_nombre(LIST &list)
{
	system("cls");
	//DECLARACION DE VARIABLES Y LISTA
	LIST lis1=NULL;
	LIST lis2;
	LIST lis3;
	int valo;
	int codi;
	char nomb[20];
   	int edad;
   	float peso;
   	char eciv;
	poscf(10,3);printf("ORDENAR LISTA:");

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
                		if (strcmp(lis2->nomb,lis3->nomb)>0)
               			{
                			//INTERCAMBIO
							//CODIGO		
							codi=lis2->codi;
      						lis2->codi=lis3->codi;
                			lis3->codi=codi;
 							//NOMBRE		
							strcpy(nomb,lis2->nomb);
      						strcpy(lis2->nomb,lis3->nomb);
                			strcpy(lis3->nomb,nomb); 
 							//EDAD		
							edad=lis2->edad;
      						lis2->edad=lis3->edad;
                			lis3->edad=edad;   
 							//PESO		
							peso=lis2->peso;
      						lis2->peso=lis3->peso;
                			lis3->peso=peso; 
 							//PESO		
							eciv=lis2->eciv;
      						lis2->eciv=lis3->eciv;
                			lis3->eciv=eciv;  							             	
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
	poscf(10,22);printf("LISTA ORDENADA");
	poscf(10,23);printf("presione cualquier tecla para continuar");
	getch();
}
void poscf(int c, int f)
{
	COORD coord;
	coord.X = c;
	coord.Y = f;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
