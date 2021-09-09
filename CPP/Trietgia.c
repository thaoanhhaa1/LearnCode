#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
 
#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (i + 4) % N
#define RIGHT (i + 1) % N
 
int state[N];
int phil[N] = {0,1,2,3,4};
 
sem_t mutex;
sem_t S[N];
 
void test(int i){
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING; //Triết gia i ăn
        sleep(2);
        printf("Triet gia %d lay 2 nia %d va %d\n",i + 1, LEFT + 1, i + 1);
        printf("Triet gia %d dang an\n", i + 1);
        sem_post(&S[i]);
    }
}
 
void take_fork(int i){
    sem_wait(&mutex); //Vào miền găng
    state[i] = HUNGRY; //Ghi nhận triết gia i đã đói
    printf("Triet gia %d dang doi\n", i + 1); 
    test(i); //Cố gắng lấy 2 nĩa
    sem_post(&mutex); //Ra khỏi miền găng
    sem_wait(&S[i]); //Chờ nếu không đủ 2 nĩa
    sleep(1);
}
 
void put_fork(int i){
    sem_wait(&mutex); //Vào miền găng
    state[i] = THINKING; //Ghi nhận triết gia i đã ăn xong
    printf("Triet gia %d dat ca 2 nia %d va %d xuong ban\n",i + 1, LEFT + 1, i + 1);
    printf("Triet gia %d an xong va dang nghi\n", i + 1);
    test(LEFT); //Kiểm tra người bên trái đã có thể ăn?
    test(RIGHT); //Kiểm tra người bên phải đã có thể ăn?
    sem_post(&mutex); //Ra khỏi miền găng
}

void* philospher(void* num){
    while (1) {
        int* i = num;
        sleep(1);
        take_fork(*i); //Yêu cầu cho đến khi có đủ 2 nĩa
        sleep(0);
        put_fork(*i); //Đặt cả 2 nĩa lên bàn lại
    }
}
 
int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL,philospher, &phil[i]);
        printf("Triet gia %d dang nghi\n", i + 1);
    }
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}