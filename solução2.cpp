#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	printf("\nola 1 = Fora de regiao paralela....\n\n");

	omp_set_num_threads(8);  //o programa vai dar prioridade ao numero de threads especificado, sem chamar esta função com um valor especifico o programa entende que é para usar o numero de threads da variavel de ambiente

#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		printf("Sou a thread %d de um total %d \n", id, nt);
	}

	printf("\nola 2 = Fora de regiao paralela....\n\n");

    #pragma omp parallel    //construtor paralelo(vai buscar no sistema operacional o numero de threads, variavel ambiente)
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		printf("Sou a thread %d de um total %d \n", id, nt);
	}

	return 0;
}