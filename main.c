#include "main.h"

int numberOfGroom = 0;
int numberOfBride = 0;
int numberOfRegisters = 2;
int totalGeneratedGroomNumber = 0;
int totalGeneratedBrideNumber = 0;
int numberOfMarriedCouples = 0;
pthread_t endLoop;

char *endChar;

void *killIt(void *arg){

	while (1)
	{
		scanf("%s",endChar);
	}
	pthread_exit(NULL);
}

int main(void) {

	endChar= malloc(sizeof(char*));
	int error = 0;

	sem_init(&semaphore, 0, 1);
	sem_init(&officer, 0, 2);
	sem_init(&groomSemaphore, 0, 0);
	sem_init(&brideSemaphore, 0, 0);

	int count = 0;

	error = pthread_create(&registrar1, NULL, &registrar, (void *)1);	/* Create registrar 1 */
	if(error != 0){

		printf("Thread creation error: [%s]", strerror(error));
	}

	error = pthread_create(&registrar2, NULL, &registrar, (void *)2);	/* Create registrar 2 */
	if(error != 0){

		printf("Thread creation error: [%s]", strerror(error));
	}

	error = pthread_create(&endLoop, NULL, &killIt, (void *)endChar);	/* Another thread for killing process */
	if(error != 0){

		printf("Thread creation error: [%s]", strerror(error));
	}
	exit(EXIT_SUCCESS);

	while(1){

		if (strcmp(endChar, "q") == 0)
		{
			return 0;
		}

		int random;
		srand (time(NULL));
		random = rand()%15;

		if(random % 5 == 0){	/* randomly creating */

			error = pthread_create(&brideThread, NULL, &bride, (void *)(5 + 1));

			if(error != 0){

				printf("Thread creation error: [%s]", strerror(error));
			}
		}
	
		if(random % 7 == 0){

			error = pthread_create(&groomThread, NULL, &groom, (void *)(5 + 1));

			if(error != 0){

				printf("Thread creation error: [%s]", strerror(error));
			}
		}
		sleep(1);
		count++;
	}

	sem_destroy(&semaphore);
	sem_destroy(&officer);
	sem_destroy(&groomSemaphore);
	sem_destroy(&brideSemaphore);

	exit(EXIT_SUCCESS);
}



