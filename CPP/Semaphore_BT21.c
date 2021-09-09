#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int x = 0;

void* thread(){
   do{
      sem_wait(&mutex);
      x++;
      printf("%d ",x);
      if (x > 20)
         _getch();
      if (x == 20)
         x = 0;
      sem_post(&mutex);
   }while(1);
}

int main() {
   sem_init(&mutex, 0, 1);
   pthread_t th1,th2;
   pthread_create(&th1,NULL,thread,NULL);
   sleep(2);
   pthread_create(&th2,NULL,thread,NULL);
   pthread_join(th1,NULL);
   pthread_join(th2,NULL);
   sem_destroy(&mutex);
}