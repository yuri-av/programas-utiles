/*
Realizar una función que determine si 
dos vectores cargados con números naturales,
 de igual cantidad de elementos, son idénticos. */


// recorrer los dos vectores simultaneamente para saber si tienen el mismo contenido
// si no, tirar un resultado que lo demuestre

// longitud1 = sizeof(vec1) / sizeof(vec1[0])
// longitud2 = sixeof(vec2) / sizeof(vec2[0])

// if longitud1 == longitud2
// while vec1[i] == vec[i] && bandera = 0
// si hay uno distinto bandera = 1

#include <stdio.h>
#include <stdlib.h>
#define Len 10

int contenido(int vec1[], int vec2[]){
    int i, bandera;
    i = 0; 
    bandera = 0;

    while (bandera != 1 && i < Len)
    {
        if (vec1[i] != vec2[i])
        {
            bandera = 1;
        }
        i++;
    }
    if (bandera == 1)
    {
        printf("Las listas no son iguales.\n");
    }else
    {
        printf("Las listas son iguales.\n");
    }
}

int main()
{

    int naturales1[] = {1,5,2,5,12,54,2,3,45,8};
    int naturales2[] = {1,5,2,5,12,54,2,3,45,8};

    contenido(naturales1, naturales2);

    return 0;
}
