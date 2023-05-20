// Implement the reader writer problem using semaphore and mutex operations to
// synchronize n readers active in reader section at a same time, and one writer active at a
// time.
// (b) If one writer is writing no other writer should be allowed to read or write on the
// shared variable.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readcount = 0;

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("Data read by the reader%d is %d \n", f, readcount);
    sleep(1);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&wrt);
    readcount = readcount + 1;
    printf("Data writen by the writer%d is %d \n", f, readcount);
    sleep(1);
    sem_post(&wrt);
}

int main()
{
    int i, b;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    for (i = 0; i <= 2; i++)
    {
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for (i = 0; i <= 2; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
}
