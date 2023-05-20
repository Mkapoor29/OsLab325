#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int buffer = 0;
pthread_mutex_t mutex;

void *producer()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (buffer == 0)
        {
            buffer = 1;
            printf("Producer produced 1 item \n");
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (buffer == 1)
        {
            buffer = 0;
            printf("Consumer consumed 1 item \n");
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread1, NULL, producer, NULL);
    pthread_create(&thread2, NULL, consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
