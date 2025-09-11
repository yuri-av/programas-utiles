/*Realizar un programa que, dada una matriz 
cuadrada con valores enteros entre 1 y 50 
(al azar), la muestra y se obtenga su traspuesta 
(permutación de filas y columnas, utilizando un 
procedimiento que permuta dos elementos), y la muestre nuevamente.
*/
#include <stdlib.h>
#include <stdio.h>
#define COLUMNAS 3 
#define FILAS 3
#include <time.h>


int mostrarMatriz(int matriz[FILAS][COLUMNAS], int fils, int cols){
    int c, f;
    for (f= 0; f < fils; f++ ){
        printf("\n");
        for(c = 0; c< cols; c++){
            printf("%i\t", matriz[f][c]);
        }
    }
    return 0;
}

//recorrer la matriz e intercambiar valores de c por valores de f
// idea for ... matriz [f]= matriz[c];

int transponer(int matriz[FILAS][COLUMNAS], int fils, int cols){
    int c, f, aux;
    // Necesito inicializar una variable auxiliar para poder transponer los elementos
    // Igual que un vector pero con la matriz
    for(f = 0; f<fils; f++){
        for ( c = f+1; c < cols; c++)
        {
            aux = matriz[f][c];
            matriz[f][c] = matriz[c][f];
            matriz[c][f] = aux;
        }
    }
    for (f= 0; f < fils; f++ ){
        printf("\n");
        for(c = 0; c< cols; c++){
            printf("%i\t", matriz[f][c]);
        }
    }
    return 0;
}


int main(){
    int numeros[FILAS][COLUMNAS] = {{5, 7, 3},
                                    {2, 3, 4},
                                    {8, 6, 4}};
    int fils = 3;
    int cols = 3;

    mostrarMatriz(numeros, fils, cols); //muestra matriz
    printf("\n");
    transponer(numeros, fils, cols);

    return 0;
}