#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>

void *groom(void *arg);
void *bride(void *arg);
void *registrar(void *arg);

sem_t semaphore;
sem_t officer;
sem_t brideSemaphore;
sem_t groomSemaphore;

pthread_t groomThread;
pthread_t brideThread;
pthread_t registrar1;
pthread_t registrar2;



extern int numberOfGroom;
extern int numberOfBride;
extern int numberOfRegisters;
extern int totalGeneratedGroomNumber;
extern int totalGeneratedBrideNumber;
extern int numberOfMarriedCouples;

