#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define HUNGRY 0
#define EATING 1
#define THINKING 2
#define LEFT (i + 4)%N
#define RIGHT (i + 1)%N

int state[N];
int Phi[N] = {0,1,2,3,4};

sem_t mutex;
sem_t s[N];

void test(int i){
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
        state[i] = EATING;
        sleep(2);
        printf("Triet gia %d lay duoc hai nia %d va %d\n",i+1,LEFT+1,i+1);
        printf("Triet gia %d dang an\n",i+1);
        sem_post(&s[i]);
    }
}

void take_forks(int i){
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Triet gia %d dang doi\n",i+1);
    test(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
    sleep(1);
}

void put_forks(int i){
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Triet gia %d dat ca 2 nia %d va %d xuong ban\n",i+1,LEFT+1,i+1);
    printf("Triet gia %d an xong va dang nghi\n",i+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void *Philosopher(void *num){
    while (1){
        int *i = num;
        sleep(1);
        take_forks(*i);
        sleep(0);
        put_forks(*i);
    }
}

int main(){
    sem_init(&mutex,0,1);
    pthread_t th[N];
    for (int i = 0; i < N; i++)
        sem_init(&s[i],0,0);
    for (int i = 0; i < N; i++){
        pthread_create(&th[i],NULL,Philosopher,&Phi[i]);
        printf("Triet gia %d dang nghi\n",i+1);
    }
    for (int i = 0; i < N; i++)
        pthread_join(th[i],NULL);
}