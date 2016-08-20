#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


main(void)
{
      int ipcion;
      int micola[10];
      int dato;
      char salir;
      int a, b, c, x;
      int op;
      system("cls");
      printf("\n\n\n\t\t\t PROGRAMA DE COLAS \n\n");
      do
      {
        
           printf("\n\n\n\n1.-Inicializar cola");
           printf("\n2.-Meter un elemento a la cola");
           printf("\n3.-Mostrar la cola");
           printf("\n4.-Eliminar elemento de cola");
           printf("\n5.-Salir");
           printf("\n\n\n\t\tElija una opcion: ");
           scanf("%d",&op);
           printf("\n");
           switch(op)
           {
                     case 1:
                         //inicializar cola
                         a=0;
                         b=0;
                         printf("La cola ya ha sido inicializada");
                         break;

                     case 2:
                          if(b<10)
                          {
                                  printf("Dame el dato: ");
                                  scanf("%d",&x);
                                  micola[b]=x;
                                  b=b+1;
                          }
                          else
                          {
                              printf("Cola llena");
  
                           }
                           if (b==10)
                           {
        
                                     printf("Cola llena:");
                           }
                     break;


                     case 3: //Mostrar datos de cola
                          if(b!=0)
                          {
                              
                               printf("Los elementos de la cola son... ");
                               int z;
                               for(z=a;z<=b-1;z++)
                               {
                                    
                                       printf("%d",micola[z]);
                               }
                          }
                         else
                               {
                                
                                   printf("Cola Vacia") ;
                                 }


                         break;

                          case 4:
                               if(b==a)
                               {
                                       printf("La cola esta vacia");
                                       }
                               else
                               {
                                   printf("Elemento eliminado");
                                   printf("%d",micola[a]);
                                   int i;
                                   for (i=a ; i<b; i++)

                                   {
                                   micola[i]=micola[i+1];}
                                   micola[b]=0;
                                   b--;
                                   }
                                   break;

                               case 5:

                                   default: printf("salir!");
                                   break;

                          }// cierra llave del switch
                     }while(op<5);

           getchar();

           }















