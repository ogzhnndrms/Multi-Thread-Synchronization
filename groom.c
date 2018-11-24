#include "main.h"

void *groom(void *arg){

	printf("Groom has been created\n");

	sem_wait(&semaphore);	/* Enter critical region */
	numberOfGroom++;
	totalGeneratedGroomNumber++;
	printf("Total Number Of Groom: %d\n", totalGeneratedGroomNumber);
	sem_post(&semaphore);

	if(numberOfBride > 0){
		if(numberOfRegisters > 0){

			sem_post(&groomSemaphore);
			sem_wait(&semaphore);
			numberOfRegisters--;
			printf("Number Of Register: %d\n", numberOfRegisters);
			sem_post(&semaphore);
			sem_post(&officer);
		}
		else
		{
			printf("Waiting Because officers are not ready\n");
			printf("Number Of Waiting Groom: %d\n", numberOfGroom);
			sem_wait(&officer);
		}
	}
	else{

		printf("Number Of Waiting Groom: %d\n", numberOfGroom);
		sem_wait(&brideSemaphore);	/* Evlenme şartını sağlayan son birey tarafından signal edilecek */
	}

	pthread_exit(NULL);
}

