#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t mutex1, mutex2;
  
void* threadA(void* arg)
{
    printf("\nA1 bat dau\n");
    printf("A1 thuc hien\n");
    printf("A1 ket thuc\n");
    sem_wait(&mutex1);
    sem_post(&mutex2);
    printf("\nA2 bat dau\n");
    printf("A2 thuc hien\n");
    printf("A2 ket thuc\n");
}

void* threadB(void* arg)
{
    printf("\nB1 bat dau\n");
    printf("B1 thuc hien\n");
    printf("B1 ket thuc\n");
    sem_wait(&mutex2);
    sem_post(&mutex1);
    printf("\nB2 bat dau\n");
    printf("B2 thuc hien\n");
    printf("B2 ket thuc\n");
}
  
  
int main()
{
    sem_init(&mutex1, 0, 0);
    sem_init(&mutex2, 0, 0);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,threadA,NULL);
    //sleep(2);
    pthread_create(&t2,NULL,threadB,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex1);
    sem_destroy(&mutex2);
    return 0;
}