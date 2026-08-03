#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int MoonAsleep = 0;
int StarAsleep = 0;

sem_t SleepToMeet;
pthread_mutex_t mutex;

void* moon(void* arg) {

    while (1) {

        sleep(2);

        pthread_mutex_lock(&mutex);

        MoonAsleep = 1;
        printf("🌙 Moon is asleep\n");

        sem_post(&SleepToMeet);

        pthread_mutex_unlock(&mutex);

        sleep(3);
    }

    return NULL;
}

void* star(void* arg) {

    while (1) {

        sleep(3);

        pthread_mutex_lock(&mutex);

        StarAsleep = 1;
        printf("⭐ Star is asleep\n");

        sem_post(&SleepToMeet);

        pthread_mutex_unlock(&mutex);

        sleep(2);
    }

    return NULL;
}

void* whisper(void* arg) {

    while (1) {

        sem_wait(&SleepToMeet);

        pthread_mutex_lock(&mutex);

        if (MoonAsleep == 1 && StarAsleep == 1) {

            printf("🦉 Whisper: Both Moon and Star are asleep! They meet in Dream Park 💫\n");

            MoonAsleep = 0;
            StarAsleep = 0;
        }
        else if (MoonAsleep == 1) {
            printf("🦉 Whisper: Moon is asleep, waiting for Star ⭐\n");
        }
        else if (StarAsleep == 1) {
            printf("🦉 Whisper: Star is asleep, waiting for Moon 🌙\n");
        }

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

int main() {

    pthread_t t1, t2, t3;

    sem_init(&SleepToMeet, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, moon, NULL);
    pthread_create(&t2, NULL, star, NULL);
    pthread_create(&t3, NULL, whisper, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    sem_destroy(&SleepToMeet);
    pthread_mutex_destroy(&mutex);

    return 0;
}