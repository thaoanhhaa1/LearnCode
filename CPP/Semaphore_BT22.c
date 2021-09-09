#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex1, mutex2;

void A(char *a){
    printf("\nTien trinh %s thuc hien\n",a);
    printf("...\n");
    printf("Tien trinh %s ket thuc\n\n",a);
}

void *Process1(){
    while(1){
        sem_wait(&mutex1);
        printf("\nTien trinh A1 thuc hien\n");
        printf("...\n");
        printf("Tien trinh A1 ket thuc\n\n");
        sem_post(&mutex2);
        sleep(4);
        printf("\nTien trinh A2 thuc hien\n");
        printf("...\n");
        printf("Tien trinh A2 ket thuc\n\n");
        break;
    }
}

void *Process2(){
    while(1){
        sem_wait(&mutex2);
        printf("\nTien trinh B1 thuc hien\n");
        printf("...\n");
        printf("Tien trinh B1 ket thuc\n\n");
        sem_post(&mutex1);
        sleep(4);
        printf("\nTien trinh B2 thuc hien\n");
        printf("...\n");
        printf("Tien trinh B2 ket thuc\n\n");
        break;
    }
}

int main() {
    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 1);
    pthread_t th1,th2;
    pthread_create(&th1,NULL,Process1,NULL);
    sleep(2);
    pthread_create(&th2,NULL,Process2,NULL);
    //Join threads with the main thread
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    sem_destroy(&mutex1);
    sem_destroy(&mutex2);
}