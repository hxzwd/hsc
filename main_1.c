
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#include "time.h"

#define N_SIZE 100
#define M_SIZE 80


uint32_t A[N_SIZE][M_SIZE];
uint32_t b[M_SIZE];
uint32_t c[N_SIZE];

uint32_t flag_show = 0;

void gen_A_b()
{
	for(uint32_t j = 0; j < M_SIZE; j++)
	{
		b[j] = 1 + rand() % 10;
		for(uint32_t i = 0; i < N_SIZE; i++)
			A[i][j] = 1 + rand() % 10;
	}
}

void show_A_b()
{
	printf("A:\n");
	for(uint32_t i = 0; i < N_SIZE; i++)
	{
		printf("[ ");
		for(uint32_t j = 0; j < M_SIZE; j++)
			printf("%d ", A[i][j]);
		printf("]\n");
	}
	printf("b:\n[ ");
	for(uint32_t i = 0; i < M_SIZE; i++)
		printf("%d ", b[i]);
	printf("]\n");
}

void show_c()
{
	printf("c:\n[ ");
	for(uint32_t i = 0; i < N_SIZE; i++)
		printf("%d ", c[i]);
	printf(" ]\n");
}


/*
void * thr_func(void *arg)
{
	uint32_t row_index = *((uint32_t *)arg);
	uint32_t row_len = M_SIZE;
	uint32_t *p = A[row_index];
	uint32_t result = 0;

	printf("[%d] THREAD START\n", row_index);

	for(uint32_t i = 0; i < row_len; i++)
		result += p[i] * b[i];
	c[row_index] = result;
}
*/

void mul_A_b()
{
	uint32_t num_of_rows = N_SIZE;
	uint32_t num_of_columns = M_SIZE;

	for(uint32_t i = 0; i < N_SIZE; i++)
	{
		uint32_t result = 0;
		for(uint32_t j = 0; j < M_SIZE; j++)
		{
			result += A[i][j] * b[j];
		}
		c[i] = result;
	}

}

int32_t main(void)
{

	srand(time(NULL));

	if(flag_show)
	{
		printf("MULTIPLY MATRIX A ON VECTOR COLUMN b [c = A*b]\n");
		printf("N = %d\nM = %d\n", N_SIZE, M_SIZE);
	}

	uint32_t num_of_rows = N_SIZE;
	uint32_t row_indexes[N_SIZE] = { 0 };
	pthread_t thrs[N_SIZE];

	for(uint32_t i = 0; i < N_SIZE; i++)
		row_indexes[i] = i;

	gen_A_b();

	if(flag_show)
		show_A_b();

//	uint32_t *p = A[1];
//	for(uint32_t i = 0; i < M_SIZE; i++)
//		printf("%d ", p[i]);


	mul_A_b();

	if(flag_show)
		show_c();

	return 0;
}
