#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define N 4

int arr[N][N];
int counter;
int row = 0;
pthread_mutex_t lock;
void* doSomeThing(void *arg)
{

	pthread_mutex_lock(&lock);
	int sum = 0;
	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d started\n", counter);
	printf("elements of row %d: \n", row + 1);
	for (int col = 0; col < N; ++col)
	{
		printf("%d  ", arr[row][col]);
		sum += arr[row][col];
	}
	
	printf("\nthe sum of the elements of row %d: %d", row + 1, sum);

//	for (i = 0; i<(0x1AAADDDD); i++);

	printf("\n Job %d finished\n\n", counter);
	row++;
	pthread_mutex_unlock(&lock);

	return NULL;
}
int main(void)
{
	int i = 0;
	int err;
	for (int m = 0; m < N; ++m)
	{
		for (int n = 0; n < N; ++n)
		{
			arr[m][n] = rand() % 20;
		}
	
	}
	printf("Matrix:\n");

	  for (int m = 0; m < N; ++m)
        {
                for (int n = 0; n < N; ++n)
                {
                       printf("%d ", arr[m][n]);
                }
              printf("\n");
        }
	
	  pthread_t tid[N];

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init failed\n");
		return 1;
	}


	while (i < N)
	{
		err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		i++;
	}
	

	for (int k = 0; k < N; ++k)
	{
		pthread_join(tid[k], NULL);
	}
	pthread_mutex_destroy(&lock);


	return 0;
}
