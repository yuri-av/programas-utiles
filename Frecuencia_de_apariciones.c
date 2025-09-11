/*
Ingresar 1000 edades en un vector e indicar
 cuál es la edad de mayor frecuencia (la que más se repite).
   Haga una función auxiliar que pruebe la correctitud del programa.  */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define len 1000

int carga(int vec[], int cantidad){
    int i;
    srand(time(NULL));
    for (i = 0; i < cantidad; i++){
        vec[i] = rand() % 101;
    }
    return 0;
}

// guardar en una variable la cantidad de veces que aparece una edad
// guardar en otra variable la cantidad maxima que aparecio una edad
// si el contador es mayor a la cantidad maxima que aparece, sustituir
// guardar el indice o la posicion de esa edad

int frecuencia(int vec[], int cantidad){
    int i, j, maximo, contador, edadActual, posicion;
    maximo = 0;
    
    for (i = 0; i < cantidad; i++)
    {
        edadActual = vec[i];
        contador = 0;
        for ( j = 0; j < cantidad; j++)
        {

            if (edadActual == vec[j])
            {
                contador+=1;
            }
        }
        if (contador > maximo)
        {
            maximo = contador;
            posicion = i;
        }
    }
    
    printf("La edad que mas aparece es: %d | %d veces\t %d", vec[posicion], maximo);
    return 0;

}

int main(){
    int edades[len];

    carga(edades, len);
    frecuencia(edades, len);
    return 0;
}