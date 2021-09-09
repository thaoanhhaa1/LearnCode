#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int x = 0;

void* thread1(void *arg){
    //sem_wait(&mutex);
   do{
      x++;
      printf("A%d ",x);
      if (x > 20)
         _getch();
      if (x == 20)
         x = 0;
   }while(1);
   //sem_post(&mutex);
}

void* thread2(void *arg){
    //sem_wait(&mutex);
   do{
      x++;
      printf("B%d ",x);
      if (x > 20)
         _getch();
      if (x == 20)
         x = 0;
   }while(1);
   //sem_post(&mutex);
}

int main() {
   sem_init(&mutex, 0, 1);
   pthread_t th1,th2;
   pthread_create(&th1,NULL,thread1,NULL);
   sleep(2);
   pthread_create(&th2,NULL,thread2,NULL);
   pthread_join(th1,NULL);
   pthread_join(th2,NULL);
   sem_destroy(&mutex);
}
