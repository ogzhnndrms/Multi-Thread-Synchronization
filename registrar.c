#include "main.h"


void * registrar(void *arg){

	int sleepTime = 0;

	while(1){

		if(numberOfGroom > 0 && numberOfBride > 0){

			sem_wait(&semaphore);	/*Critical Region */
			printf("The registrar %d is busy now!\n", (int) arg);
			numberOfMarriedCouples++;
			printf("Number of Married Couples: %d\n", numberOfMarriedCouples);
			numberOfGroom--;
			numberOfBride--;
			sem_post(&semaphore);	/* Release */
			srand (time(NULL));
			sleepTime = rand()%10;
			sleep(sleepTime);

			sem_wait(&semaphore);	/* Critical Region */
			numberOfRegisters++;
			printf("The registrar %d is not busy now!\n", (int) arg);
			sem_post(&semaphore);
			sem_post(&officer);	/* If anyone is sleeping because of i was busy, i will signal the last came */	/* Ayrıca registrarsızlık yüzünden uyuyan varsa onu da uyandırıyor */
		}
		else{

			sem_wait(&officer);	/* Wait if no couple is here */
		}
	}

	pthread_exit(NULL);
}
