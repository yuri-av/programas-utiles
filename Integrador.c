/*
Además, debe crear un archivo binario llamado cajeros.dat que almacene un listado de cajeros en la estructura “cajero” con los siguientes campos:
Cada campo posee las siguientes características:
cajero: Número identificador del cajero (un entero).
operacion: Tipo de operación realizada, que puede ser 1 (depósito) o 2 (extracción).
monto: Valor de la transacción en pesos (un número entero).


3. Eliminar la cantidad de movimientos del último cajero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct rcajero
{
    int cajero;               // Número del cajero
    char direccion[MAX];      // Dirección del cajero
    int cantidad_movimientos; // Cantidad de movimientos realizados
} rcajero;

typedef struct rmovimientos
{
    int id_cajero;
    int operacion; // 1 ingreso || 2 egreso
    float monto;
} rmovimientos;

void totales_modificacion(char archivo_m[], char archivo_b[MAX])
{
    float total;
    int cajero_actual, mov_total;
    rcajero cajero;
    rmovimientos movimiento;
    //============== APERTURA DE ARCHIVOS Y MANEJOR DE ERRORES ==================
    FILE *mov;
    FILE *caj;
    mov = fopen(archivo_m, "r");
    caj = fopen(archivo_b, "r+b");
    if (mov == NULL || caj == NULL)
    {
        printf("El archivo %s no existe\n", archivo_m);
    }
    else
    {
        //================= LECTURA Y ACTUALIZACION DE ARCHIVOS =====================
        int scan = fscanf(mov, "%i %i %f", &movimiento.id_cajero, &movimiento.operacion, &movimiento.monto);

        while (scan == 3)
        {
            total = 0;
            cajero_actual = movimiento.id_cajero;
            mov_total = 0;

            while (scan == 3 && cajero_actual == movimiento.id_cajero)
            {
                if (movimiento.operacion == 1)
                {
                    total += movimiento.monto;
                }
                else
                {
                    total -= movimiento.monto;
                }
                mov_total++;
                scan = fscanf(mov, "%i %i %f", &movimiento.id_cajero, &movimiento.operacion, &movimiento.monto);
            }
            //============== ESCRITURA EN EL ARCHIVO BINARIO ==================
            fseek(caj, sizeof(rcajero) * (cajero_actual - 100), SEEK_SET);
            cajero.cajero = cajero_actual;
            strcpy(cajero.direccion, "----");
            cajero.cantidad_movimientos = mov_total;
            fwrite(&cajero, sizeof(rcajero), 1, caj);
            fseek(caj, sizeof(rcajero) * (cajero_actual - 100), SEEK_SET);
            fread(&cajero, sizeof(rcajero), 1, caj);
            printf("ID: %i | Direc: %s | Mov: %i | Total: $%.2f\n",
                   cajero.cajero, cajero.direccion, cajero.cantidad_movimientos, total);
            printf("====================================================\n");
        }
        fclose(mov);
        fclose(caj);
    }
}

void eliminar_mov(char archivo_b[])
{
    //============== VARIABLES NECESARIAS ==================
    rcajero cajero;
    FILE *pf;
    int confirmacion;
    //============== APERTURA DE ARCHIVO BINARIO ==================
    pf = fopen(archivo_b, "r+b");
    if (pf != NULL)
    {
        //============== BUSCANDO REGISTRO ==================
        printf("Buscando registro...\n");
        fseek(pf, -(long)sizeof(rcajero), SEEK_END);
        fread(&cajero, sizeof(rcajero), 1, pf);
        printf("Cajero: %i\n", cajero.cajero);
        printf("Direc: %s\n", cajero.direccion);
        printf("Movimientos: %i\n===============\n", cajero.cantidad_movimientos);

        //============== CONFIRMACION DE MODIFICACION ==================
        printf("Desea modificarlo? 1:si | 2:no: ");
        scanf("%i", &confirmacion);
        if (confirmacion == 1)
        {
            printf("Modificando...\n");
            fseek(pf, -(long)sizeof(rcajero), SEEK_END);
            cajero.cantidad_movimientos = 0;
            fwrite(&cajero, sizeof(rcajero), 1, pf);
            printf("Registro modificado exitosamente!\n===============\n");
            fseek(pf, -(long)sizeof(rcajero), SEEK_END);
            fread(&cajero, sizeof(rcajero), 1, pf);

            printf("Cajero: %i\n", cajero.cajero);
            printf("Direc: %s\n", cajero.direccion);
            printf("Movimientos: %i\n===============\n", cajero.cantidad_movimientos);
        }
        else
        {
            printf("Cerrando programa...\n");
        }
        //============== CIERRE DE ARCHIVO ==================
        fclose(pf);
        printf("Gracias por usar nuestro programa!\n");
    }
    //============== MANEJO DE ERRORES ==================
    else
    {
        printf("ERROR AL ABRIR EL ARCHIVO\n");
    }
}

int main()
{
    char archivo_m[MAX] = "movimientos.txt";
    char archivo_b[MAX] = "cajeros.dat";
    totales_modificacion(archivo_m, archivo_b);
    eliminar_mov(archivo_b);
    return 0;
}