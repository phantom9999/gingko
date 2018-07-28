#include <pthread.h>
#include "minihttpd/spinlock.h"
#include "gtest/gtest.h"

using ::argus::common::SpinLock;
using ::argus::common::SpinLockGuard;

int64_t g_intVal1 = 0;
SpinLock lock1;

void *add_spinlock_thread(void *args) {
  for (int i = 0; i < 10000; i++) {
    SpinLockGuard lock_guard(lock1);
    g_intVal1++;
  }
  return (void *) 0;
}

TEST(SpinLockTest, SpinLockTest) {
  pthread_t threads[40];
  for (int i = 0; i < 40; i++) {
    int ret = pthread_create(&threads[i], NULL, add_spinlock_thread, NULL);
    assert(0 == ret);
  }

  for (int i = 0; i < 40; i++) {
    pthread_join(threads[i], NULL);
  }

  EXPECT_EQ(400000, g_intVal1);
}

