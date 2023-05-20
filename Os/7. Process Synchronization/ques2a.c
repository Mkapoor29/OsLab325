#include <stdio.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;
int readers = 0;

void *reader()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex);
        readers++;
        if (readers == 1)
        {
            pthread_mutex_lock(&mutex1);
        }
        pthread_mutex_unlock(&mutex);
        printf("Reader read %d \n", buffer);
        pthread_mutex_lock(&mutex);
        readers--;
        if (readers == 0)
        {
            pthread_mutex_unlock(&mutex1);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *writer()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        buffer++;
        printf("Writer wrote %d \n", buffer);
        pthread_mutex_unlock(&mutex1);
    }
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(&thread1, NULL, reader, NULL);
    pthread_create(&thread2, NULL, writer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
