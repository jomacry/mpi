#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	float A[10];
	float B[10];
	float C[10];


	printf("\nola 1- fora da região paralela...\n\n");
	
	int id, i , nt;

	for (i = 0; i < 10; i++)
	{
		A[i] = 2;
		B[i] = 3;
	}

#pragma omp parallel private (id , nt) //faz com que a threads reconheçam onde deve começar e onde deve terminar
			
	{
		int id = omp_get_thread_num();   //retorna o numero da thread em especifico, esse numero é unico para cada thread, cada thread vai ter sua copia da variavel id, cada thread tera sua identificação unica
		int nt = omp_get_num_threads();   //total de threads disparadas durante a execução
		int size = (int)8 / nt;         //tamanho da thread, neste caso cada thread trabalha com duas posições do vetor, pois o vetor éde 8 posições e o numero de threads é 4 , logo 8/4 total de 2 posições para cada thread manipular
		int ini = id * size;             //recebe tamanho da thread, se a thread é a 0, 0*2=0 então a thread começa na posição 0, se a thread for a 1, 1*2=2 então a trhead vai começar na posição 2 etc.... 
		int fim = ini + size - 1;        //pega a variavel ini (inicio) e soma com o tamanho(size) -1, se a thread for a 0, 0+size(2)-1= 1, se a thread for a 1, ini(2) +size(2)-1=3, se a thread for a 2 com ini = 4, ini+size-1=5, assim a thread sabe seu fim e asim sucessivamente
 
	
		int i;

		for (i = ini; i <= fim; i++)
		{
			C[i] = A[i] + B[i];
		}
		printf("Sou a thread %d de um total %d \n", id, nt);
	}
	for (i = 0; i < 10; i++)                 //fora de região paralela
	{
		printf(" C [%d] = %f\n" , i , C[i]);
	}

	printf("\nola 2 - fora da região paralela.....\n\n");
	return 0;
}