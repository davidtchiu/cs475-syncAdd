#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "rtclock.h"

int x = 0;
pthread_spinlock_t *lock;

void *doStuff(void *);

int main()
{
  double start = rtclock(); // start stopwatch

  // initialize the lock
  lock = (pthread_spinlock_t *)malloc(sizeof(pthread_spinlock_t));
  pthread_spin_init(lock, PTHREAD_PROCESS_SHARED);

  pthread_t t1, t2;
  pthread_create(&t1, NULL, doStuff, NULL);
  pthread_create(&t2, NULL, doStuff, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("Value of x is %d\n", x);
  pthread_spin_destroy(lock);

  double end = rtclock(); // end stopwatch

  printf("Time: %.6f sec\n", ((end - start)));
  return 0;
}

void *doStuff(void *args)
{
  int i;
  for (i = 0; i < 1000000; i++)
  {
    pthread_spin_lock(lock);
    x++;
    pthread_spin_unlock(lock);
  }
  return NULL;
}