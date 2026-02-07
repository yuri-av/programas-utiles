/*Crear un registro que permita almacenar información relacionada con un músico.
Cada músico cuenta con un nombre, una edad, un género músical e información sobre sus discos.
Cada disco, posee un título, un año de lanzamiento y su cantidad de canciones.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_DISCOS 50
typedef struct rdisco
{
    char nombre_disco[MAX];
    int lanzamiento;
    int canciones;
} rdisco;
typedef struct rmusico
{
    char nombre[MAX];
    int edad;
    char genero[MAX];
    rdisco discos[MAX_DISCOS];
    int cantidad_discos;
} rmusico;
/*Utilizando el registro del punto anterior, crear las siguientes funciones:
Una función que permita la carga de un vector de 20 músicos.
Una función que reciba el vector de músicos y retorne el nombre del músico con mayor cantidad de discos.
Una función que reciba el vector de músicos, una edad y retorne el promedio de discos para los músicos menores a la edad recibida.
Una función que reciba el vector de músicos, un año e imprima por pantalla el nombre de los
discos cuyo año de lanzamiento sea posterior al recibido cómo parámetro. Además, se debe
incluir el nombre del artista, el género y la cantidad de canciones del disco.
*/
void limpiar_buffer()
{
    while (getchar() != '\n')
        ;
}
void cargar_musicos(rmusico musicos[])
{
    int i, j, fin_discos;
    // Tengo que recorrer la longitud del vector, cargando los datos de cada uno de los musicos a mano
    /*Cada musico contiene:
    nombre
    edad
    genero de musica
    se le asigna al campo discos la info de cada uno de ellos llamando al registro rdisco*/

    for (i = 0; i < 20; i++)
    {
        printf("\n========== MUSICO %d ==========\n", i + 1);
        fin_discos = 1;
        printf("Nombre del artista: ");
        fgets(musicos[i].nombre, MAX, stdin);
        musicos[i].nombre[strcspn(musicos[i].nombre, "\n")] = '\0';

        printf("Edad: ");
        scanf("%i", &musicos[i].edad);
        limpiar_buffer();

        printf("Genero: ");
        fgets(musicos[i].genero, MAX, stdin);
        musicos[i].genero[strcspn(musicos[i].genero, "\n")] = '\0';

        printf("======INGRESAR DATOS DE DISCOS=======\n");
        musicos[i].cantidad_discos = 0;
        j = 0;
        while (fin_discos != 0 && j < MAX_DISCOS)
        {
            printf("Titulo disco: ");
            fgets(musicos[i].discos[j].nombre_disco, MAX, stdin);
            musicos[i].discos[j].nombre_disco[strcspn(musicos[i].discos[j].nombre_disco, "\n")] = '\0';

            printf("Lanzamiento del disco: ");
            scanf("%d", &musicos[i].discos[j].lanzamiento);
            limpiar_buffer();

            printf("Cantidad de canciones: ");
            scanf("%d", &musicos[i].discos[j].canciones);
            limpiar_buffer();
            musicos[i].cantidad_discos++;
            j++;

            if (j < MAX_DISCOS)
            {
                printf("¿Agregar otro disco? 1 (si) | 0 (no): ");
                scanf("%d", &fin_discos);
                limpiar_buffer();
            }
            else
            {
                printf("Limite de discos alcanzado.\n");
                fin_discos = 0;
            }
            printf("\nTotal de discos agregados: %d\n", musicos[i].cantidad_discos);
        }
    }
}
int mayor_cantidad_discos(rmusico musicos[], int *posicion_artista)
{
    int artista_mayor, i;
    artista_mayor = musicos[0].cantidad_discos;
    *posicion_artista = 0;

    for (i = 0; i < 20; i++)
    {
        if (musicos[i].cantidad_discos > artista_mayor)
        {
            artista_mayor = musicos[i].cantidad_discos;
            *posicion_artista = i;
        }
    }
    return artista_mayor;
}

float promedio_artistas_menores(rmusico musicos[], int edad)
{
    int i, artistas, cantidad_discos;
    float promedio_discos = 0;
    artistas = 0;
    cantidad_discos = 0;
    for (i = 0; i < 20; i++)
    {
        if (musicos[i].edad < edad)
        {
            artistas++;
            cantidad_discos += musicos[i].cantidad_discos;
        }
    }
    if (artistas == 0)
    {
        return 0.0;
    } // Evitar división por cero
    return (float)cantidad_discos / artistas;
}

/*Una función que reciba el vector de músicos, un año e imprima por pantalla el nombre de los
discos cuyo año de lanzamiento sea posterior al recibido cómo parámetro. Además, se debe
incluir el nombre del artista, el género y la cantidad de canciones del disco.*/
void imprimir_por_anio(rmusico musicos[], int anio)
{
    printf("\n--- DISCOS LANZADOS DESPUES DE %d ---\n", anio);
    for (int i = 0; i < 20; i++)
    {
        // Reiniciamos j para cada músico
        for (int j = 0; j < musicos[i].cantidad_discos; j++)
        {
            if (musicos[i].discos[j].lanzamiento > anio)
            {
                printf("\nArtista: %s\n", musicos[i].nombre);
                printf("Disco: %s | Año: %i | Canciones: %i | Genero: %s\n",
                       musicos[i].discos[j].nombre_disco,
                       musicos[i].discos[j].lanzamiento,
                       musicos[i].discos[j].canciones,
                       musicos[i].genero);
            }
        }
    }
}

int main()
{
    rmusico musicos[20];
    int posicion_artista = 0;
    int edad;
    int anio;
    cargar_musicos(musicos);
    int max_discos = mayor_cantidad_discos(musicos, &posicion_artista);
    printf("==========ARTISTA CON MAS DISCOS===========\n%s\n", musicos[posicion_artista].nombre);
    printf("Cantidad de discos: %i\n", max_discos);
    printf("=============================================\n");

    printf("Ingrese la edad maxima para calcular promedio: ");
    scanf("%i", &edad);
    limpiar_buffer();
    float promedio = promedio_artistas_menores(musicos, edad);
    printf("El promedio de discos para artistas menores a %i es de %.2f\n", edad, promedio);

    printf("Ingrese el anio del que quiere empezar a filtrar: ");
    scanf("%i", &anio);
    imprimir_por_anio(musicos, anio);
    return 0;
}
