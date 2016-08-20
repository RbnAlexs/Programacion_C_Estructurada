#include <stdio.h>
#include <conio.h>
#define TAM 6
#define MAX TAM-1
 
typedef struct
{
   int tope;
   int item[TAM];
}pila;
 
 
int llena(pila *);
int vacia(pila *);
void push(pila *, int);
void pop(pila *,int *);
 
 
int main()
{
   pila p,t;
   int dato,opc,elemento,flag=0;
   p.tope=0;
   do
   {
      printf("\n\t\t\t\tMENU-PILA");
      printf("\n\t\t\t1. Insertar elemento");
      printf("\n\t\t\t2. Eliminar elemento de la pila");
      printf("\n\t\t\t3. Eliminar elemento X");
      printf("\n\t\t\t4. Visualizar");
      printf("\n\t\t\t5. Salir");
      printf("\n\n\t\t\topcion : ");
      scanf("%d",&opc);
      switch(opc)
      {
         case 1:
            if(!llena(&p)) // si pila no esta llena
            {
              printf("\nDato a insertar: ");
              scanf("%d",&dato);
              push(&p,dato);
              printf("\nElemento insertado...");
            }
            else
            {
              printf("\nERROR: Pila llena");
            }
         break;
 
         case 2:
            if(!vacia(&p))
            {
              pop(&p,&dato);
              printf("\nEl elemento eliminado es %d",dato);
            }
            else
            {
              printf("\nERROR: Pila vac¡a");
            }
         break;
 
         case 3:
            if(!vacia(&p))
            {
              printf("eliminar elemento seleccionado: ");
              scanf("%d",&elemento);
 
              if(p.tope != 1)
              {
                 t.tope=0;
                 do
                 {
                    pop(&p,&dato);
                    if (dato != elemento)
                    {                 
                    push(&t,dato);
                    } 
                 }while(!vacia(&p));
    
                do
                {
                    pop(&t,&dato);    
                    push(&p,dato);
                }while(!vacia(&t));
                printf("\nElemento eliminado...");
              } 
             else if(dato == elemento)
             {
                  pop(&p,&dato);
             }
             else 
              {
                  printf("el elemento no se encuentra en la pila");
               }
            }
             else
             {
                  printf("\nERROR: Pila vac¡a");
             }
         break;
 
         case 4:
            printf("\n\nELEMENTOS DE LA PILA\n\n");  
            if(!vacia(&p))
            {
              t.tope=0;
              do
              {
                 pop(&p,&dato);
                 printf("\n%d",dato);
                 push(&t,dato);
              }while(!vacia(&p));
              do
              {
                 pop(&t,&dato);
                 push(&p,dato);
              }while(!vacia(&t));
            }
            else
            {
              printf("\nERROR: Pila vac¡a");
            }
         break;
         
         case 5:
            flag=1;
            break;

         default:
         printf("\nOpcion no valida...");
      }// termina el switch
      if(!flag)
      {
         printf("\n\nPresione una tecla para continuar...");
         getch();
      }
   }while(!flag);
   return 0;
}







 
int llena(pila *p)
{
   return(p->tope==MAX);
}
 
int vacia(pila *p)
{
   return(p->tope==0);
}
 
void push(pila *p,int dato)
{
   if(!llena(p))
   {
      (p->tope)++;
      p->item[p->tope]=dato;  //elemento[1]=dato
   }
   else
      printf("\nOVERFLOW");
}
 
void pop(pila *p,int *dato)
{
   if(!vacia(p))
   {
      *dato=p->item[p->tope];
      (p->tope)--;
   }
   else
      printf("\nUNDERFLOW");
}
