/*Dada una matriz de 3 filas por 4 columnas, calcular la sumatoria de sus elementos:  ΣM(i,j)*/

#define COLUMNAS 4 
#define FILAS 3
#include <stdlib.h>
#include <stdio.h>

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

int sumatoria(int matriz[FILAS][COLUMNAS], int fils, int cols){
    int c, f, suma;
    suma = 0;

    for (f = 0; f < fils; f++)
    {
        for (c = 0; c < cols; c++)
        {
            suma += matriz[f][c];
        }
        
    }
    printf("Sumatoria = %i\n", suma);
    
    return 0;
}

int main(){
    int numeros[FILAS][COLUMNAS] = {{5, 7, 3, 9},
                                    {2, 3, 4, 1},
                                    {8, 6, 4, 2}};
    int fils = 3;
    int cols = 4;

    mostrarMatriz(numeros, fils, cols); //muestra matriz
    printf("\n");
    sumatoria(numeros, fils, cols); //muestra sumatoria de matriz

    return 0;
}