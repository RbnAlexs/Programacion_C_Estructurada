#include <stdio.h>
#define TAMANIO 15

/* prototipos de las funciones */
int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto );
void despliegaEncabezado( void );
void despliegaLinea( const int b[], int bajo, int medio, int alto );

/* la funci�n main comienza la ejecuci�n del programa */
int main() {
    int a[ TAMANIO ]; /* crea el arreglo a */
    int i; /* contador para inicializar los elementos de 0 a 14 del arreglo a */
    int llave; /* valor a localizar en el arreglo a */
    int resultado; /* variable para almacenar la ubicaci�n de la llave o -1 */

    /* crea los datos */
    for ( i = 0; i < TAMANIO; i++ ) {
        a[ i ] = 2 * i; //Llenar al arreglo 'a' con numeros multiplos de 2 hasta llegar a TAMANIO que es igual a 15
    } /* fin de for */

    printf( "Introduzca un numero entre 0 y 28: " );
    scanf( "%d", &llave );
    despliegaEncabezado();
    /* busca la llave en el arreglo a */
    resultado = busquedaBinaria( a, llave, 0, TAMANIO - 1 );

    /* despliega los resultados */
    if ( resultado != -1 ) {
        printf( "\n%d se encuentra en el elemento %d del arreglo\n", llave, resultado );
    } /* fin de if */
    else {
        printf( "\n%d no se encuentra\n", llave );
    } /* fin de else */

    system("pause");
    return 0; /* indica terminaci�n exitosa */

} /* fin de main */

/* funci�n para realizar la b�squeda binaria en un arreglo */
    /* int b[] = arreglo 'a', int claveDeBusqueda = llave, int bajo = 0, int alto = TAMANIO (15) -1*/
int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto ) {
    int central = ( bajo + alto ) / 2;
    despliegaLinea( b, bajo, central, alto );


    if ( bajo > alto ) {
        printf("\ncentral = %d", central);
        return -1;
    }

    if ( claveDeBusqueda == b[ central ] ) {
        printf("\ncentral = %d", central);
        return central;
    }

    if ( claveDeBusqueda < b[ central ] ) {
        return busquedaBinaria( b, claveDeBusqueda, bajo, central - 1 );
    }

    if(claveDeBusqueda > b[central] ) {
        return busquedaBinaria (b, claveDeBusqueda, central + 1, alto);
    }

} /* fin de la funcipon busquedaBinaria */

/* Imprime un encabezado para la salida */
void despliegaEncabezado( void ) {
    int i; /* contador */

    printf( "\nSubindices:\n" );

    /* muestra el encabezado de la columna */
    for ( i = 0; i < TAMANIO; i++ ) {
        printf( "%3d ", i );
    } /* fin de for */

    printf( "\n" ); /* comienza la nueva l�nea de salida */

    /* muestra una l�nea de caracteres  - */
    for ( i = 1; i <= 4 * TAMANIO; i++ ) {
        printf( "-" );
    } /* fin de for */

    printf( "\n" ); /* inicia una nueva l�nea de salida */
} /* fin de la funci�n despliegaEncabezado */

/* Imprime una l�nea de salida que muestra la parte actual
   del arreglo que se esta procesando. */
void despliegaLinea( const int b[], int baj, int cen, int alt ) {
    int i; /* contador para la iteraci�n a trav�s del arreglo b */

    /* ciclo a trav�s del arreglo completo */
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

    printf( "\n" ); /* inicia la nueva l�nea de salida */
} /* fin de la funci�n despliegaLinea */
