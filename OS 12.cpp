#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 
#define LEFT (i+N-1)%N 
#define RIGHT (i+1)%N 
#define THINKING 0 
#define HUNGRY 1 
#define EATING 2 

int state[N]; 
sem_t mutex; 
sem_t s[N]; 

void *philosopher(void *arg);
void pickup_forks(int i);
void return_forks(int i);
void test(int i);

int main() {
    int i;
    pthread_t tid[N];

    
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++) {
        sem_init(&s[i], 0, 0);
    }

    
    for (i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, philosopher, (void*) i);
        printf("Philosopher %d is thinking\n", i);
    }

    
    for (i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

void *philosopher(void *arg) {
    int i = (int) arg;

    while (1) {
        sleep(1);
        pickup_forks(i);
        sleep(1);
        return_forks(i);
    }
}

void pickup_forks(int i) {
    sem_wait(&mutex); 
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry\n", i);
    test(i);
    sem_post(&mutex); 
    sem_wait(&s[i]); 
}

void return_forks(int i) {
    sem_wait(&mutex); 
    state[i] = THINKING;
    printf("Philosopher %d is thinking\n", i);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex); 
}

void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d is eating\n", i);
        sem_post(&s[i]);
    }
}

