
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



/*lista enlazada cada elemento contiene un numero entero */

typedef struct datos //elementos de una lista de enteros
{
    int dato;
    struct datos *siguiente;
    }telemento;

/* Funciones */
void error(void)
{
perror("error: insuficiente espacio de memoria");
exit(1);
}

telemento *NuevoElemto()
{
    telemento *q = (telemento *)malloc(sizeof(telemento));
    if (!q) error();
    return(q);
    }

/* Funciones prototipo */
int menu(void);
void anadir(telemento **, int);
void borrar(telemento **, int);
telemento *buscar(telemento *, int);
void visualizar(telemento *);

main()
{
    telemento *cabecera = NULL;
    telemento *q;
    int opcion, dato;

    while (1)
    {
        opcion = menu();
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("\nANADIR DATO: ");
                scanf("%d", &dato);
                anadir(&cabecera, dato);
                break;

            case 2:
                printf("\nBORRAR DATO: ");
                scanf("&d", &dato);
                q= buscar(cabecera, dato);
                if(q)
                    borrar(&cabecera, dato);
                else
                    printf("\nEl valor %d no esta en la lista\n", dato);
                break;

            case 3:
                printf("\n BUSCA DATO: ");
                scanf("%d", &dato);
                q= buscar(cabecera,dato);
                if(q);
                {
                    printf("\nEl valor &d esta en la lista\n",q->dato);
                    printf("\n\n");
                }
            case 4:
                printf("\nELEMENTOS DE LA LISTA\n");
                visualizar(cabecera);
                break;

            case 5:
            //liberar la memoria ocupada por la lista
            q= cabecera; //q apunta l primer elemento de la lista
            while (q!=NULL)
            {
                cabecera = cabecera->siguiente;
                free(q);
                q=cabecera;
            }
            return 0;

          }//fin del switch
    }//fin del while

}//fin del main


int menu() /*Menu de opciones */
{

    int op = 0;
    do {

        printf("\n\t1. Anadir un elemento\n");
         printf("\n\t2. Borrar un elemento\n");
          printf("\n\t3. Buscar un elemento\n");
           printf("\n\t4. Visualizar un elemento\n");
            printf("\n\t5. Salir\n");
             printf("\n\t. Elija la opcion deseada: ");
             scanf("%d", &op);
             fflush(stdin);
    }

    while (op < 1 || op > 5);
    return op;
}

/* Introducir un elemento ordenadamente a la lista */
void anadir(telemento **cab, int dato)
{

    telemento *cabecera = *cab;
    telemento *actual = cabecera, *anterior=cabecera, *q;
    if (cabecera == NULL) //si esta vacia crear un elemento
    {
        cabecera = NuevoElemto();
        cabecera->dato=dato;
        cabecera->siguiente = NULL;
        *cab = cabecera;
        return;
    }

    /*entrar en la lista y encontrar el punto de insercion */
    while(actual != NULL && dato > actual ->dato)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    /*Dos casos:
    1) Insertar al principio de la lista
    2) Insertar despues de anterior (incluye insertar al final)*/

    q = NuevoElemto(); //se genera un nuevo elemento
    if(anterior == actual) //insertar al principio
    {
        q->dato = dato;
        q->siguiente = cabecera;
        cabecera = q;
    }

    else // insertar despues de anterior

    {

        q->dato = dato;
        q->siguiente = actual;
        anterior->siguiente = q;
    }
    *cab = cabecera;
}
//encontrar un dato y borrarlo

void borrar (telemento **cab, int dato)
{

    telemento *cabecera = *cab;
    telemento *actual = cabecera, *anterior=cabecera;
    if(cabecera == NULL)
    {
        printf("LISTA VACIA\n");
        return;
    }
    //entrar en la lista y encontrar el elemento a borrar

    while (actual != NULL && dato !=actual->dato)
    {
        anterior=actual;
        actual = actual ->siguiente;
    }

    /*Si el dato se encuentra, borrar el elemento */
    if(anterior ==actual)//borra el elemento de cabecera
    cabecera = cabecera -> siguiente;

    else
        anterior -> siguiente = actual -> siguiente;

        free(actual);
        printf("\nDATO BORRADO\n");
        *cab=cabecera;
        getch();
}

/*buscar un elemento determinado en la lista*/
telemento *buscar(telemento *cabecera, int dato)
{

    telemento *actual = cabecera;
    while(actual != NULL && dato != actual -> dato)
        actual = actual ->siguiente;
        return (actual);
}
    /*Visualizar la lista */
    void visualizar (telemento *cabecera)
    {
        telemento *actual = cabecera;
        if (cabecera == NULL)
        printf("LISTA VACIA\n");
        else
        {
            while (actual != NULL)
            {
                printf("%d\n", actual ->dato);
                actual = actual -> siguiente;
            }
            printf("\n");
        }
    }
