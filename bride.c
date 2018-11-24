#include "main.h"

void *bride(void *arg){

	printf("Bride has been created\n");

	sem_wait(&semaphore);/* Mutex amacıyla critical regionları lock etmek için kullanıyorum */
	numberOfBride++;	/* queue de ki bride sayısı */
	totalGeneratedBrideNumber++;
	printf("Total Number Of Bride: %d\n", totalGeneratedBrideNumber);
	sem_post(&semaphore);

	if(numberOfGroom > 0){
		if(numberOfRegisters > 0){

			sem_post(&brideSemaphore);	/* Signal groom for hey i am here for marrying, pls come here!*/
			sem_wait(&semaphore);
			numberOfRegisters--;
			printf("Number Of Register: %d\n", numberOfRegisters);
			sem_post(&semaphore);
			sem_post(&officer);	/*Signal the registrar hey we are couple now marry us */
		}
		else{
			printf("Waiting Because officers are not ready\n");
			printf("Number of Waiting Brides: %d\n", numberOfBride);
			sem_wait(&officer);	/* She will wait for registrar if registrar is not ready */
		}
	}
	else{

		printf("Number of Waiting Brides: %d\n", numberOfBride);/* eğer buraya geldiyse zaten waiting state geçecektir */
		sem_wait(&groomSemaphore);	/* No groom or no registrar */
	}
	pthread_exit(NULL);
}
