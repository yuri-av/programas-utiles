#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*En un archivo secuencial (por ejemplo “lluvias.txt”)
se almacenan datos sobre la lluvia caída en un cierto período. 
Cada línea corresponde a un día y contiene los siguientes datos: 

Día-Mes-Año-Precipitaciones (0 si no llovió)  

Preparar un algoritmo con los procedimientos necesarios para: 
Cargar los datos correspondientes a los 30 días del mes de septiembre del corriente año. 
Leer el archivo e informar por pantalla:cuántos días hubo sin lluvias, cuántos días llovió  menos de 50 mm y cuántos llovió 50 mm ó más.  
*/


typedef struct rprecip{
    int dia;
    int mes;
    int anio;
    float precipitaciones;
}rprecip;


void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void cargar_registro(rprecip *lluvia, bool *bandera){

    printf("Dia: ");
    scanf("%i", &lluvia->dia);
    if (lluvia->dia <= 0)
    {
        *bandera = false;
    }else if (lluvia->dia > 0)
    {
        
        limpiar_buffer();
        
        printf("Mes: ");
        scanf("%i", &lluvia->mes);
        limpiar_buffer();

        printf("Anio: ");
        scanf("%i", &lluvia->anio);
        limpiar_buffer();

        printf("Precipitacione: ");
        scanf("%f", &lluvia->precipitaciones);

    }
    
}

int main(){
    FILE *f;
    rprecip lluvia;
    int dia = 0;
    bool bandera = true;
    char archivo[] = {"lluvia.txt"};
    
    f = fopen(archivo, "a");
    printf("Abriendo el archivo...\n");

    if (f == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
    }
    printf("Cargando el archivo...\n");
    while (dia < 30 && bandera)
    {   
        cargar_registro(&lluvia, &bandera);
        fprintf(f,"Dia: %i -- Mes: %i -- Anio: %i -- Lluvia: %.2f \n",
             lluvia.dia, lluvia.mes, lluvia.anio, lluvia.precipitaciones);
        dia++;
    }
    printf("Carga finalizada.\n");
    printf("Cerrando el archivo...\n");
    fclose(f);

    f= fopen(archivo, "r");
    printf("Abriendo el archivo...\n");
    if (f == NULL) {        
        printf("Error al abrir el archivo\n");
        return 1;
    }
    int dias_sin_lluvia, dias_menos_50, dias_50omas;
    dias_sin_lluvia = 0;
    dias_menos_50 = 0;
    dias_50omas = 0;

    printf("Mostrando archivo...\n");
    while (fscanf(f, "Dia: %i -- Mes: %i -- Anio: %i -- Lluvia: %f \n",
         &lluvia.dia, &lluvia.mes, &lluvia.anio, &lluvia.precipitaciones) == 4)
    {
        if (lluvia.precipitaciones == 0)
        {
            dias_sin_lluvia++;
        }
        else if (lluvia.precipitaciones > 0 && lluvia.precipitaciones < 50)
        {
            dias_menos_50++;
        }
        else if (lluvia.precipitaciones >= 50)
        {
            dias_50omas++;
        }
    }
    fclose(f);
    printf("Dias sin lluvia: %i\n Dias con menos de 50mm: %i\n Dias con mas de 50mm: %i\n",
         dias_sin_lluvia, dias_menos_50, dias_50omas);

    return 0;
} 
