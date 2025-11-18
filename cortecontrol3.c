/*3- Producir un informe con los sueldos de los empleados de una compañía, 
emitiendo subtotales por departamento y por sucursal. Cada empleado tiene un
único registro en el archivo maestro de nómina con los siguientes datos:

• Código de sucursal (cod_suc:entero)
• Código de departamento  (cod_dpto:entero)
• Código de empleado  (cod_emp:entero)
• Sueldo mensual (sueldo:real)
El archivo está ordenado en forma ascendente por código de sucursal y, dentro de sucursal por departamento (Archivo sueldos2.txt)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
//=======================//=======================//=======================//
typedef struct rsubtotal
{
    int sucursal;
    int depto;
    int empleado;
    float sueldo;
}rsubtotal;
//=======================//=======================//=======================//

void subtotales(char archivo[]){
    //Variables
    //=======================//=======================//=======================//
    rsubtotal subtotal;
    FILE * pf;
    int sub_depto;
    int sub_sucur;
    int sucursal_actual;
    int depto_actual;
    int hay_datos;
    int lectura_exitosa;
    pf = fopen(archivo, "r");
    //=======================//=======================//=======================//
    //Apertura de archivo
    //=======================//=======================//=======================//
    if (pf == NULL)
    {
        printf("***ERROR AL ABRIR EL ARCHIVO***\n");
        fclose(pf);
    }
    //=======================

    //=======================
    lectura_exitosa = fscanf(pf, "%i,%i,%i,%f", &subtotal.sucursal, &subtotal.depto, &subtotal.empleado, &subtotal.sueldo);
    if (lectura_exitosa == 4)
    {
        hay_datos = 1;
    }
    else
    {
        hay_datos = 0;
        printf("Archivo vacio o formato incorrecto\n");
    }
    //=======================//=======================//=======================//
    // Empezamos lectura con corte de control
    //=======================//=======================//=======================//
    while (hay_datos)
    {
        sucursal_actual = subtotal.sucursal;
        sub_sucur = 0;
        printf("\n===== SUCURSAL: %d =====\n", sucursal_actual);
        printf("-------------------\n");
        //=======================//=======================//=======================//
        // Lectura por Sucursal
        //=======================//=======================//=======================//
        while (hay_datos && sucursal_actual == subtotal.sucursal)
        {
            depto_actual = subtotal.depto;
            sub_depto = 0;
        
            printf("=====   DEPARTAMENTO: %d =====\n", depto_actual);
            //=======================//=======================//=======================//
            // Lectura por depto
            //=======================//=======================//=======================//
            while (hay_datos && sucursal_actual == subtotal.sucursal && 
                depto_actual == subtotal.depto)
            {
                sub_depto += subtotal.sueldo;
                sub_sucur += subtotal.sueldo;

                lectura_exitosa = fscanf(pf, "%d,%d,%d,%f", &subtotal.sucursal, &subtotal.depto, &subtotal.empleado, &subtotal.sueldo);
                
                if (lectura_exitosa != 4)
                {
                    hay_datos = 0;
                }
            }
            //=======================//=======================//=======================//
            printf("Subtotal depto %i: $%i\n", depto_actual, sub_depto);
        }
        printf("\nSubtotal sucursal %i: $%i\n", sucursal_actual, sub_sucur);
    }
    //=======================//=======================//=======================//
    // Fin corte de control
    //=======================//=======================//=======================//
    printf("Fin de lectura...\n");
    fclose(pf);
}

int main(){
    char archivo[MAX_LEN] = "sueldos2.txt";
    subtotales(archivo);
    return 0;
}