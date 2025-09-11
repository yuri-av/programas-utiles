#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define Max 30

int cargar_lista_random(int vector[], int cantidad){
    int dia;
    srand(time(NULL));
    for (dia = 0; dia < cantidad; dia++)
    {
        vector[dia] = rand() % 46;
    }
    return 0;    
}

int mostrarLista(int vector[], int cantidad){
    int i;
    printf("[");
    for (i = 0; i < cantidad; i++)
    {
        printf("%i\t", vector[i]);
    }
    printf("]\n");
    return 0;
}

int promedio(int vector[], int cantidad){
    int dias, contador;
    for (dias = 0; dias < cantidad; dias++)
    {
        contador += vector[dias]; // sumo todo para encontrar la sumatoria
    }
    printf("Promedio = %d\n", contador/Max);
    return 0;    
}

int MaxMin(int vector[], int cantidad){
    int dias, diaMax, diaMin, TempMax, TempMin;
    diaMax = 0;
    diaMin = 0;
    TempMax = vector[0];
    TempMin = vector[0];
//Busco mayor
    for (dias = 0; dias < cantidad; dias++)
    {
        if (vector[dias] > TempMax)
        {
            TempMax = vector[dias];
            diaMax = dias;
        }
    }
    
//Busco menor 
    for ( dias = 0; dias < cantidad; dias++)
    {
        if (vector[dias] < TempMin)
        {
            TempMin = vector[dias];
            diaMin = dias;
        }
    }
    printf("El dia con mayor temperatura fue: %i, con %i Celsius\n", diaMax+1, TempMax);
    printf("El dia con menor temperatura fue: %i, con %i Celsius\n", diaMin+1, TempMin);
    
    return 0;
}

int main(){

    int temperaturas_mes[Max];
    int cantidad = Max;

    cargar_lista_random( temperaturas_mes, cantidad);
    mostrarLista(temperaturas_mes, cantidad);
    promedio(temperaturas_mes, cantidad);
    MaxMin(temperaturas_mes, cantidad);

    return 0;
}