#include "../includes/philo.h"

#define THREADS_NUM 40

int				shared = 0;

pthread_mutex_t	mutex;

void	thread_function(int n)
{
	int	a;
	int	b;

	printf("n = %d\n", n);
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		// We're fooling around to pretend that an variable is accessing the data
		a = shared;
		b = 1;
		shared = a + b;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(void)
{
	pthread_t	threads[THREADS_NUM];

	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < THREADS_NUM; i++)
		pthread_create(&threads[i], NULL, (void *)thread_function, (void *)2);
	for (int i = 0; i < THREADS_NUM; i++)
		pthread_join(threads[i], NULL);
	// Expected to be 4.000.000
	printf("shared = %d\n", shared);
	return (0);
}
