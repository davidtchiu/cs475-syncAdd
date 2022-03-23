#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int x = 0;
pthread_spinlock_t *lock;

void *doStuff(void *);

int main()
{
  // initialize the lock
  lock = (pthread_spinlock_t *)malloc(sizeof(pthread_spinlock_t));
  pthread_spinlock_init(lock, NULL);

  pthread_t t1, t2;
  pthread_create(&t1, NULL, doStuff, NULL);
  pthread_create(&t2, NULL, doStuff, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("Value of x is %d\n", x);
  pthread_spinlock_destroy(lock);
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