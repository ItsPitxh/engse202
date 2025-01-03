#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* Global variables */
int x = 0;
sem_t m;

/* Thread function */
void *thread(void *arg) {
    sem_wait(&m); // Lock the semaphore
    x = x + 1;    // Critical section
    sem_post(&m); // Unlock the semaphore
    return NULL;
}

int main() {
    pthread_t tid[10];
    int i;

    // Initialize semaphore with value 1
    if (sem_init(&m, 0, 1) == -1) {
        perror("Failed to initialize semaphore");
        exit(EXIT_FAILURE);
    }

    // Create TEN threads
    for (i = 0; i < 10; i++) {
        if (pthread_create(&tid[i], NULL, thread, NULL) != 0) {
            perror("Failed to create thread");
            sem_destroy(&m);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to terminate
    for (i = 0; i < 10; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Final value of x is %d\n", x);

    // Destroy semaphore
    sem_destroy(&m);

    return 0;
}