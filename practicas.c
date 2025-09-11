#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 100

void cargar(int vec[],int cantidad){
	int i;
	for (i = 0; i < cantidad; i++){
		vec[i] = rand()% tam; //
	}
}


void mostrar(int vec[],int cantidad){
	for(int i  = 0; i< cantidad; i++){
		printf("%d\t", vec[i]);
	}printf("\n");
}

void ordenarVec(int vec[], int cantidad){
	int i = 0; // inicializa porque el while no lo hace
	int aux = 0;
	int contador = 0;
	int orden = 1; // se inicializa por fuera sino no entra al while
	
	while(i<cantidad && orden != 0){ // el while debe ser el primero ya que es el que tiene la condicion de corte
		
		orden = 0; 
		// se declara que tiene valor 0
		
		for(int j = 0; j< cantidad-1; j++){
			contador++;
			if (vec[j] > vec[j+1]){
				aux = vec [j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
				orden = 1; 
				//si se modifica algo orden es 1, sino es 0 y se corta
			}
			i++;	
		}
	}
	printf("Se itero %i veces para ordenar el vector\n", contador);
}

int main(){
	
	int cantidad = 100;
	int vec[cantidad];	
	
	cargar(vec, cantidad);
	mostrar(vec, cantidad);
	ordenarVec(vec, cantidad);
	mostrar(vec, cantidad);
	
	
	return 0;
}