#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define POR 100

typedef struct rpobladores
{
    int sexo; //1 H | 2 M
    int edad;
    int estciv; // 1  S | 2 C | 3 Otros
    int trabajo;// 1 si | 0 no
    int estudio;// 1 si | 0 no

}rpobladores;

void cargar_registros(rpobladores *poblador, bool *bandera){

    printf("Ingrese el sexo (1 Hombre, 2 Mujer, -1 para cortar): ");
    scanf("%i", &poblador->sexo);
    scanf("%*[^\n]%*c");

    if (poblador->sexo == -1)
    {
        *bandera = false;
    }
    else if (poblador->sexo == 1 || poblador->sexo == 2)
    {
        printf("Ingrese la edad: ");
        scanf("%i", &poblador->edad);
        scanf("%*[^\n]%*c");

        printf("Ingrese el estado civil (1 Soltero, 2 casado, 3 otros): ");
        scanf("%i", &poblador->estciv);
        scanf("%*[^\n]%*c");

        printf("¿Trabaja? (1 si, 2 no) : ");
        scanf("%i", &poblador->trabajo);
        scanf("%*[^\n]%*c");

        printf("¿Estudia? (1 si, 2 no) : ");
        scanf("%i", &poblador->estudio);
        scanf("%*[^\n]%*c");
    }
}

// crear un archivo que contenga todos los datos condition

int main(){

    // variables importantes
    int contador = 0;
    bool bandera = true;
    rpobladores poblador;

    //contadores
    int total;
    float m,h, m18t, solt, cas, te, mt;
    m = 0; //mujeres
    h = 0; // hombres
    m18t = 0; //menores que trabajan
    solt = 0; //solteros
    cas = 0; //casados
    te = 0; //trabajan y estudian
    mt = 0; // mujeres que trabajan
    total = 0;

    //definicion de archivo y apertura
    char archivo[] = {"pobladores.txt"};
    FILE *f;
    f = fopen(archivo, "w");
  
    
    if (f==NULL)
        printf("El fichero no se ha podido abrir correctamente\n");
    else
    {
        //cargo el registro hasta poner -1
        while (bandera)
        {
            cargar_registros(&poblador, &bandera);
            if (bandera)
            {
                fprintf(f,"%i Sexo: %i\t Edad: %i\t Estado civil: %i\t Trabaja: %i\t Estudia: %i\n",
                    contador, poblador.sexo,poblador.edad, poblador.estciv, poblador.trabajo, poblador.estudio);    
                contador++;
            }
        }
        fclose(f);
        printf("Cerrando archivo...\n\n");
    }
    // apertura de lectura
    printf("Iniciando lectura...\n\n");
    f = fopen(archivo, "r");
    
    if (f==NULL)
        printf("El fichero no se ha podido abrir correctamente\n");
    else{
        while (fscanf(f, "%i Sexo: %i\t Edad: %i\t Estado civil: %i\t Trabaja: %i\t Estudia: %i\n", 
        &contador, &poblador.sexo,&poblador.edad, &poblador.estciv, &poblador.trabajo, &poblador.estudio) == 6)
        {  
            // evalua sexo y si es mujer si trabaja
            if(poblador.sexo == 1){
                h++;
            }else if(poblador.sexo == 2){
                m++;
                if(poblador.trabajo == 1){
                    mt++;
                }
            }
            // menores que trabajan
            if(poblador.edad < 18 && poblador.trabajo == 1){
                m18t++;
            }
            // trabaja/estudia
            if(poblador.trabajo == 1 && poblador.estudio == 1){
                te++;
            }
            //estado civil
            if (poblador.estciv == 1){
                solt++;
            }else if(poblador.estciv == 2){
                cas++;
            }
            total++;
        }
        fclose(f);
    }

    printf("Cerrando archivo...\n\n");
    printf("====== ESTADITICAS ======\n");
    printf("Total: %i\n", total);
    printf("Mujeres: %.2f\t Hombres: %.2f\n", (m*POR/total), (h*POR / total));
    printf("Mujeres que trabajan: %.2f\n", (mt*POR/total));
    printf("Trabajan (menores): %.2f\n", (m18t*POR/total));
    printf("Trabajan y estudian: %.2f\n", (te*POR/total));
    printf("Estado civil: %.2f Solteros\t %.2f Casados\n", (solt*POR/total), (cas*POR/total));
    return 0;
}
