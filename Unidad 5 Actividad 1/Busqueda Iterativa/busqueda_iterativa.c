#include <stdio.h>
#define TAMANIO 15

/* prototipos de las funciones */
void despliegaEncabezado( void );
void despliegaLinea( const int b[], int bajo, int medio, int alto );
int busquedaBinaria(const int[], int, int); //arreglo, tamano, clave


/* la función main comienza la ejecución del programa */
int main() {
    int a[ TAMANIO ]; /* crea el arreglo a */
    int i; /* contador para inicializar los elementos de 0 a 14 del arreglo a */
    int llave; /* valor a localizar en el arreglo a */
    int resultado; /* variable para almacenar la ubicación de la llave o -1 */

    /* crea los datos */
    for ( i = 0; i < TAMANIO; i++ ) {
        a[ i ] = i * 2; //Llenar al arreglo 'a' con numeros multiplos de 2 hasta llegar a TAMANIO que es igual a 15
    } /* fin de for */


    printf( "Introduzca un numero entre 0 y 28: " );
    scanf( "%d", &llave );
    /* busca la llave en el arreglo a */
    despliegaEncabezado();

    resultado = busquedaBinaria( a, TAMANIO, llave);

    /* despliega los resultados */
    if ( resultado != -1 ) {
        printf( "\n%d se encuentra en el elemento %d del arreglo\n", llave, resultado );
    } /* fin de if */
    else {
        printf( "\n%d no se encuentra\n", llave );
    } /* fin de else */

    system("pause");
    return 0; /* indica terminación exitosa */

} /* fin de main */

/* función para realizar la búsqueda binaria en un arreglo */
    /* int b[] = arreglo 'a', TAMANIO, llave */
int busquedaBinaria(const int arreglo[], int tamano, int clave){
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;

  int central = ( Iabajo + Iarriba ) / 2;
  despliegaLinea( arreglo, Iabajo, central, Iarriba );

  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}

/* Imprime un encabezado para la salida */
void despliegaEncabezado( void ) {
    int i; /* contador */

    printf( "\nSubindices:\n" );

    /* muestra el encabezado de la columna */
    for ( i = 0; i < TAMANIO; i++ ) {
        printf( "%3d ", i );
    } /* fin de for */

    printf( "\n" ); /* comienza la nueva línea de salida */

    /* muestra una línea de caracteres  - */
    for ( i = 1; i <= 4 * TAMANIO; i++ ) {
        printf( "-" );
    } /* fin de for */

    printf( "\n" ); /* inicia una nueva línea de salida */
} /* fin de la función despliegaEncabezado */

/* Imprime una línea de salida que muestra la parte actual
   del arreglo que se esta procesando. */
void despliegaLinea( const int b[], int baj, int cen, int alt ) {
    int i; /* contador para la iteración a través del arreglo b */

    /* ciclo a través del arreglo completo */
    for ( i = 0; i < TAMANIO; i++ ) {

        /* despliega espacios si se encuentra fuera del rango actual del subarreglo */
        if ( i < baj || i > alt ) {
            printf( "    " );
        } /* fin de if */
        else if ( i == cen ) { /* despliega el elemento central */
            printf( "%3d*", b[ i ] ); /* marca el valor central */
        } /* fin de else if */
        else { /* despliega otros elementos en el subarreglo */
            printf( "%3d ", b[ i ] );
        } /* fin de else */

    } /* fin de for */

    printf( "\n" ); /* inicia la nueva línea de salida */
} /* fin de la función despliegaLinea */
