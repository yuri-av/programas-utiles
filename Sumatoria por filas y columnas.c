/*
Leer una matriz de tres filas por tres 
columnas y calcular la suma de cada una de sus 
filas y de sus columnas, colocando los 
resultados en dos vectores, uno para la suma 
de las filas y otro para la suma de las columnas. */

/*Dada una matriz de 3 filas por 4 columnas, calcular la sumatoria de sus elementos:  ΣM(i,j)*/

#define COLUMNAS 3
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
    int c, f, sumaFils, sumaCols;
    sumaFils = 0;
    sumaCols = 0;
    int sumaC[COLUMNAS], sumaF[FILAS];
    
    // suma fila por fila
    for (f = 0; f < fils; f++){

        for (c = 0; c < cols; c++)
        {
            sumaFils += matriz[f][c];
        }  
        sumaF[f] = sumaFils;
        sumaFils = 0;     
    }
    // Suma columna por columna
    for (c = 0; c < cols; c++){

        for (f = 0; f < fils; f++){
            sumaCols += matriz[f][c];
        }
        sumaC[c] = sumaCols; 
        sumaCols = 0;
    }

    int i;
    // mostrar los resultados
    for ( i = 0; i < fils; i++){
        printf("Fila %i = %i\t", i +1, sumaF[i]);
    }
    printf("\n");
    for ( i = 0; i < fils; i++){
        printf("Columna %i = %i\t", i+1, sumaC[i]);
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
    sumatoria(numeros, fils, cols); //muestra sumatoria de matriz

    return 0;
}