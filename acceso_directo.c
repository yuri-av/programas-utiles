#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_DNI 9
#define MAX_NOMBRE 100

typedef struct rpersona
{
    int i;
    char dni[MAX_DNI];
    char nombre[MAX_NOMBRE];
    int sexo; // 1 Hombre 2 Mujer
    int edad;
}rpersona;

void cargar_archivo(char archivo[], char modo[]){
    scanf("%*[^\n]%*c");
    rpersona persona;
    persona.i = 0;
    FILE *pf;
    pf = fopen(archivo, modo);
    if (pf == NULL)
    {
        printf("Se produjo un error al abrir el archivo\n");
    }
    else{
        /*preguntar por fuera el indice, de manera que si es == -1
        no entre, si es distinto pregunta el resto de los datos y vuelve a preguntar el indice*/
        printf("Ingrese el indice: ");
        scanf("%i", &persona.i);
        scanf("%*[^\n]%*c");

        // si es != -1 entra sino no
        while (persona.i != -1)
        {
            /*Si pongo un fgets tengo que reemplazar el \n por un \0
            Si pongo un scanf tengo que limpiar el buffer del teclado*/
            printf("Ingrese el nombre: ");
            fgets(persona.nombre, MAX_NOMBRE, stdin);
            scanf("%*[^\n]%*c");
            printf("%s", persona.nombre);
            printf("Ingrese el DNI: ");
            fgets(persona.dni, MAX_DNI, stdin);
            printf("%s", persona.dni);
            scanf("%*[^\n]%*c");

            printf("Ingrese el sexo: ");
            scanf("%i", &persona.sexo);
            scanf("%*[^\n]%*c");

            printf("Ingrese la edad: ");
            scanf("%i", &persona.edad);
            scanf("%*[^\n]%*c");
            
            //Pido donde escribir el registro en el archivo
            //calcula los bytes
            fseek(pf, sizeof(rpersona)*persona.i, SEEK_SET); 
            //escribe el archivo 
            fwrite(&persona, sizeof(rpersona), 1,pf); 
            printf("Ingrese el indice: ");
            scanf("%i", &persona.i);
        }
    fclose(pf);
    }
}

void leer_archivo_binario(char archivo[], char modo[]){
    int buscador = 0;
    rpersona persona;
    FILE * pf;
    pf = fopen(archivo, modo);
    if (pf == NULL){
        printf("No se pudo abrir el archivo\n");
    }else{
        printf("Donde quiere buscar: ");
        scanf("%i", &buscador);
        scanf("%*[^\n]%*c");

        fseek(pf, sizeof(rpersona)*buscador, SEEK_SET);
        fread(&persona, sizeof(rpersona), 1, pf);
        printf("I: %i\tNombre: %s\t DNI: %s\tSexo: %i\tEdad: %i\n",persona.i, persona.nombre, persona.dni,persona.sexo, persona.edad);
    }
    fclose(pf);
}

int main(){
    int leer = 0;
    char archivo[MAX_NOMBRE] = {"personas.dat"};
    char modo[10];
    printf("\tModo\nwb, rb: ");
    fgets(modo, 2, stdin);

    cargar_archivo(archivo, modo);
    printf("Quiere leer? 1 SI 2 NO: ");
    scanf("%i", &leer);
    if (leer == 1)
    {
        strcpy(modo, "rb");
        leer_archivo_binario(archivo, modo);
    }
    return 0;
}
