#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char **argv){
	
	int elementos = 0;
	char c = 0;
	
	
	//Aqui manejamos las opciones.
	//El argumento -p tiene un argumento, que es 
	//el numero de elementos a pedir (por eso el :)
	while ((c = getopt (argc, argv, "p:")) != -1){
		switch(c){
			case 'p':
				elementos = atoi(optarg);
				break;
			default:
				printf("Argumento invalido\n");
				exit(1);
		}
	}
	
	if(elementos<=0){
	printf("Numero de personas invalido\n");
	exit(1);}
	
	float peso[elementos];
	float altura[elementos];
	float imc[elementos];
	int i;
	for(i=0; i<elementos; i++){
	
		printf("Peso: ");
		scanf("%f", &peso[i]);
			if(peso[i]<0){
			printf("Número invalido\n");
				exit(1);
			}
			
		printf("Altura: ");
		scanf("%f", &altura[i]);
			if(altura[i]<0){
			printf("Número invalido\n");
				exit(1);
			}
			
		imc[i]=peso[i]/(altura[i] * altura[i]);
	}

	//Los resultados de sus calculos van en estas variables.
	//Puede declarar más variables si lo necesita.
	float sum = 0.0f;
	float max_imc = imc[0];
		for(i=0; i<elementos; i++){
		sum = sum + imc[i];
		if(imc[i]>max_imc){
			max_imc=imc[i];
		}
	}
	sum=sum/elementos;
	
	
	//No modifique estas lineas
	//Guarde los resultados en las 
	//variables sum y max_imc
	printf("\npromedio IMC: %.1f\n", sum);
	printf("maximo IMC: %.1f\n", max_imc);
	}
