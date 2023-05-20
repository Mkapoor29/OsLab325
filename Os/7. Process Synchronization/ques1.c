#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int in = 0;    // Index of next item to be added to the buffer
int out = 0;   // Index of next item to be removed from the buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* producer(void* arg) {
    int i;
    for (i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);
        if (count == BUFFER_SIZE) {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        buffer[in] = i;
        printf("Producer produced item %d at index %d\n", i, in);
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int i, item;
    for (i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            pthread_mutex_unlock(&mutex);
            continue;
        }}
        item = buffer[out];
        printf("Consumer consumed item %d at index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_mutex_unlock(&mutex);
    }
   

