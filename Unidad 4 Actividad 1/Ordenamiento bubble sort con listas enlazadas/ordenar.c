/*RUBEN ALEJANDRO SANCHEZ COLIN LIC EN INFORMATICA SUAYED*/

/* INSTRUCCIONES: 
  Hacer un ordenamiento descendente para 30 empleados.
. Hacer un ordenamiento ascendente para 20 nombres de empleados con 15 caracteres c/u
. Hacer un programa en C.

----------------------------------------------------
Especificaciones: Sólo utilizar Lenguaje C estándar que es el Lenguaje del curso, como ya
sabes.
Elaboración del programa Bubble Sort, como se indica en la plataforma; es decir, tomar en
cuenta los elementos que hay que ordenar y realizar el ordenamiento ascendente y
descendente.
IMPORTANTE: Este programa debe estar elaborado con listas dinámicas(apuntadores); la
estructura de datos utilizada debe ser una lista enlazada, que ya hicieron en un programa
anterior; de hecho la deben reutilizar.
El resto de las especificaciones de entrega, son las mismas que para los programas anteriores*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//TAMAÑO PARA LA FORMA DESCENDIENTE
#define SIZE 30
//TAMAÑO PARA LA FORMA ASCENDIENTE
#define SIZE_ASC 20

//variable para opcion del menu
int op;

//Declaracion de listas
struct listNode {
char data[SIZE];
struct listNode *siguiente_puntero;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODE_puntero;

/* Declaracion de punteros */
void insertar_lista ( LISTNODE_puntero *, char[SIZE] );
void insertar_lista_des ( LISTNODE_puntero *, char[SIZE] );
void imprimir_lista ( LISTNODE_puntero );
int count ( LISTNODE_puntero );


int main( ){
printf("\tProgramacion Estructurada, Metodos de Ordenamiento\n\n");
//numero de empleados (definido en una constante) con maximo 15 caracteres
char nuevo_nombre[15];
//variables i para el ciclo for.
int i = 0;
LISTNODE_puntero start_puntero = NULL;


printf("\n\t 1) Ordenar de forma descendente.");
printf("\n\t 2) Ordenar de forma ascendente. ");
printf("\n\n\tEliga una opcion -> ");
scanf("%d",&op);

if(op==1){
	//llamar la funcion para ordenar e imprimir la lista de nombres ordenada de forma descendente
	
	for(i=0;i<SIZE;i++){
		getchar();
		printf("\n\tIngresa el nombre del empleado (Apellido y Nombre) %d: ",i+1);
		//gets para leer espacios entre el nombre y apellido (si llegan a ingresar los dos)
		gets(nuevo_nombre);
		insertar_lista_des ( &start_puntero, nuevo_nombre );
	}
	
}else if(op==2){
	//llamar la funcion para ordenar e imprimir la lista de nombres ordenada de forma ascendente
	for(i=0;i<SIZE_ASC;i++){
		getchar();
		printf("\n\tIngresa el nombre del empleado (Apellido y Nombre) %d: ",i+1);
		//gets para leer espacios entre el nombre y apellido (si llegan a ingresar los dos)
		gets(nuevo_nombre);
		insertar_lista ( &start_puntero, nuevo_nombre );
	}
}else{
printf("\n Opcion no valida!");
}


imprimir_lista(start_puntero);

return 0;
}

/* insertar_lista es un numero nombre en la lista para ordenar*/
void insertar_lista ( LISTNODE_puntero *s_puntero, char registro[SIZE] ){
	
	LISTNODE_puntero nuevo_puntero, anterior_puntero, actual_puntero;
	int cmp;
	
	nuevo_puntero = malloc(sizeof(LISTNODE));
	
	if ( nuevo_puntero != NULL ) {
	strcpy(nuevo_puntero->data, registro);
	nuevo_puntero->siguiente_puntero = NULL;
	anterior_puntero = NULL;
	actual_puntero = *s_puntero;

/* Bubble sort compara y ordena */
while ( actual_puntero != NULL ) {
	//para strcmp es necesario la libreria string.h
	cmp = strcmp(registro, actual_puntero->data);
	// --------------------- Desendente o ascendente -------------------------------
	if (cmp > 0) {
	/* condicional para ordenar en forma descendente o ascendente  */
	break;
	} else  if (cmp==0) {
	/* Si el registro esta duplicado, se lo advertimos al usuario */
	printf(" '%s' Registro duplicado.\n", registro);
	//return;
	}
	anterior_puntero = actual_puntero;
	actual_puntero = actual_puntero->siguiente_puntero;
}

if ( anterior_puntero == NULL ) {
nuevo_puntero->siguiente_puntero = *s_puntero;
*s_puntero = nuevo_puntero;
}
else{
anterior_puntero->siguiente_puntero = nuevo_puntero;
nuevo_puntero->siguiente_puntero = actual_puntero;
}
}
else
printf("%s No se ha insertado en la lista.\n", registro);
}


void insertar_lista_des ( LISTNODE_puntero *s_puntero, char registro[SIZE] ){
	
	LISTNODE_puntero nuevo_puntero, anterior_puntero, actual_puntero;
	int cmp;
	
	nuevo_puntero = malloc(sizeof(LISTNODE));
	
	if ( nuevo_puntero != NULL ) {
	strcpy(nuevo_puntero->data, registro);
	nuevo_puntero->siguiente_puntero = NULL;
	anterior_puntero = NULL;
	actual_puntero = *s_puntero;

/* Bubble sort compara y ordena */
while ( actual_puntero != NULL ) {
	//para strcmp es necesario la libreria string.h
	cmp = strcmp(registro, actual_puntero->data);
	// --------------------- Desendente o ascendente -------------------------------
	if (cmp < 0) {
	/* condicional para ordenar en forma descendente o ascendente  */
	break;
	} else  if (cmp==0) {
	/* Si el registro esta duplicado, se lo advertimos al usuario */
	printf(" '%s' Registro duplicado.\n", registro);
	//return;
	}
	anterior_puntero = actual_puntero;
	actual_puntero = actual_puntero->siguiente_puntero;
}

if ( anterior_puntero == NULL ) {
nuevo_puntero->siguiente_puntero = *s_puntero;
*s_puntero = nuevo_puntero;
}
else{
anterior_puntero->siguiente_puntero = nuevo_puntero;
nuevo_puntero->siguiente_puntero = actual_puntero;
}
}
else
printf("%s No se ha insertado en la lista.\n", registro);
}


/* Imprimir la lista */
void imprimir_lista ( LISTNODE_puntero actual_puntero )
{
int i = 1;
if ( actual_puntero == NULL )
printf("\n\nLa lista esta vacia.\n\n");
else{
printf("\n\nLa lista ordenada es:\n\n");
while ( actual_puntero != NULL ){
printf(" %d) %s \n",i, actual_puntero->data);
actual_puntero = actual_puntero->siguiente_puntero;
i++;
}

printf("\nFIN\n\n");
}
}
