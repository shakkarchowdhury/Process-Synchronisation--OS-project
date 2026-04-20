#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>



sem_t SleepToMeet;
pthread_mutex_t mutex; 
int MoonAsleep = 0;
int StarAsleep = 0;


void *moon(void *arg)
{
   for (int i = 1; i <= 10; i++)
   {


       pthread_mutex_lock(&mutex);
       MoonAsleep = 1;
       pthread_mutex_unlock(&mutex);
       sem_post(&SleepToMeet);


       sleep(1);
   }
   return NULL;
}
void *star(void *arg)
{
   for (int i = 1; i <= 10; i++)
   {
      

       pthread_mutex_lock(&mutex);
       StarAsleep = 1;
       pthread_mutex_unlock(&mutex);
       sem_post(&SleepToMeet);


       sleep(2);
   }
   return NULL;
}


void *whisper(void *arg)
{
   for (int i = 1; i <= 10; i++)
   {
       sem_wait(&SleepToMeet);


       pthread_mutex_lock(&mutex);


       if (MoonAsleep == 1 && StarAsleep == 1)
       {
           printf("Moon & Star meet in Dream Park. \n");
           MoonAsleep = 0;
           StarAsleep = 0;
       }
       else
       {
           printf("Star wait for Moon.\n");
       }


       pthread_mutex_unlock(&mutex);


       sleep(2);
   }
   return NULL;
}


int main()
{



   pthread_t moon_thread, star_thread, whisper_thread;
   sem_init(&SleepToMeet, 0, 0);



   pthread_mutex_init(&mutex, NULL);


   
   pthread_create(&moon_thread, NULL, moon, NULL);
   pthread_create(&star_thread, NULL, star, NULL);
   pthread_create(&whisper_thread, NULL, whisper, NULL);



   pthread_join(moon_thread, NULL); 
   pthread_join(star_thread, NULL); 
   pthread_join(whisper_thread, NULL);



   sem_destroy(&SleepToMeet);



   pthread_mutex_destroy(&mutex);


   return 0;
}

