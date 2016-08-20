// Este programa implementará la estructura de grafos
 
#include <stdio.h>
//  -> Rubén Alejandro Sánchez Colín, tercer semestre de la licenciatura en informática SUAYED FCA UNAM
#include <stdlib.h>
 
// Creamos una estructura lista enlazada 
struct Nodo
{
    int dest;
    struct Nodo* siguiente;
};
 
// Esta estructura nos demostrará la matriz en sí
struct NodoN
{
    struct Nodo *inicio;  //Este será el nodo "cabeza"
};
 
// El tamaño del arreglo será igual a V, que será el numero de nodos total a admitir.

struct grafo
{
    int V;
    struct NodoN* array;
};
 
// Crear lista
struct Nodo* newNodo(int dest)
{
    struct Nodo* newNode =
            (struct Nodo*) malloc(sizeof(struct Nodo));
    newNode->dest = dest;
    newNode->siguiente = NULL;
    return newNode;
}
 
// Crear grafo
struct grafo* creargrafo(int V)
{
    struct grafo* grafo = (struct grafo*) malloc(sizeof(struct grafo));
    grafo->V = V;
 
    //El tamaño del arreglo será deacuerdo a la variable V
    grafo->array = (struct NodoN*) malloc(V * sizeof(struct NodoN));
 
     // Inicializamos la lista como NULL
    int i;
    for (i = 0; i < V; ++i)
        grafo->array[i].inicio = NULL;
 
    return grafo;
}
 
// Agrega los nodos
void aristaN(struct grafo* grafo, int src, int dest)
{
    struct Nodo* newNode = newNodo(dest);
    newNode->siguiente = grafo->array[src].inicio;
    grafo->array[src].inicio = newNode;
 
    // Dirección del nodo (según variable ingresada por el usuario)
    newNode = newNodo(src);
    newNode->siguiente = grafo->array[dest].inicio;
    grafo->array[dest].inicio = newNode;
}
 
// Imprimir grafo
void imprimirgrafo(struct grafo* grafo)
{
    int v;
    for (v = 0; v < grafo->V; ++v)
    {
        struct Nodo* pCrawl = grafo->array[v].inicio;
        printf("\n Grafo con matriz de adyacencias %d\n inicio ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->siguiente;
        }
        printf("\n");
    }
}
 
// Programa princial
int main()
{
    /*

    Estas son las variables necesarias para iniciar los ciclos que nos permitiran escribir 
    y guardar las variables en los arreglos necesarias para los aristas. Tal como se solicita en la tarea,
    estas le serán solicitadas al usuario, en este caso al inicio del programa.*/
    int i = 1;
    int z = 2;
    int bandera;
    int vertice_x[10], vertice_y[10];
    //El números de nodos lo definiremos en esta variable
    int V = 5;
    //El numero de aristas lo definiremos en esta otra variable:
    int A = 7;
    struct grafo* grafo = creargrafo(V);
    //Mensaje de bienvenida
    printf("\nBienvenido al programa de grafos!\n\n\t Actividad 2 de la Unidad 3 del temario de Programacion Estructurada de la\n\t Licenciatura en informatica - FCA UNAM\n");
    //Le pediremos al usuario los nodos que serán adyacentes para poder formar la matriz
    printf("\n A continuacion ingresa los nodos adyacentes de cada elemento para poder formar el grafo: \n");
    printf("(*nota: los nodos serán del numero 0 al 5, ingresa los nodos adyacentes de cada uno)\n");
    
	for(i; i <= A; i++){
		do{
			printf("\n\n\t %i de %d", i, A);
	        printf("\n\n Nodo 'a': " );
	        scanf("%d",&vertice_x[i]);
        	printf("\n al Nodo 'b': " );
        	scanf("%d",&vertice_y[i]);
	        	
			//Verificamos si el usuario esta ingresando los nodos correspondientes entre el 0  y el 5
	        if( ((vertice_x[i]>=0)&&(vertice_x[i]<=5)) && ((vertice_x[i]>=0)&&(vertice_x[i]<=5)) ){
	        		printf("\n\t -----> Arista no %d: %d , %d \n",i,vertice_x[i],vertice_y[i]);
        			bandera = 1;
	        }else{
	        	printf("\n\n\tError! Uno de las dos variables es superior a los numeros requeridos. Ingresa un numero entre el 0 y el 5 \n\n");
	        	bandera = 0;
			}
	        
		}while(bandera == 0 );
    }
    
    for(z; z <= A;z++){
        aristaN(grafo, vertice_x[z], vertice_y[z]);
    }
 
    // Enviamos nuestra estructura a nuestra función para generar e imprimir nuestro grafo.
    imprimirgrafo(grafo);
 
    return 0;
}
