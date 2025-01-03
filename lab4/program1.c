#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* Global variables */
int x = 0;
sem_t sync;

/* Thread function */
void *my_func(void *arg) {
    sem_wait(&sync); // Wait for signal from main thread
    printf("X = %d\n", x);
    return NULL;
}

int main() {
    pthread_t thread;

    // Initialize semaphore with value 0
    if (sem_init(&sync, 0, 0) == -1) {
        perror("Failed to initialize semaphore");
        exit(EXIT_FAILURE);
    }

    // Create thread
    if (pthread_create(&thread, NULL, my_func, NULL) != 0) {
        perror("Failed to create thread");
        sem_destroy(&sync);
        exit(EXIT_FAILURE);
    }

    x = 55; // Perform some operation(s)

    sem_post(&sync); // Signal created thread

    // Wait for thread to finish
    pthread_join(thread, NULL);

    // Destroy semaphore
    sem_destroy(&sync);

    return 0;
}