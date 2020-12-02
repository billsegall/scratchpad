/* Copyright (C) Bill Segall 2020, All rights Reserved */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "callback.h"

static int64_t counter = 0;

void recv_int(int num) {
    counter++;
    return;
}

// Tuned locally for now
#define NUM_ITERATIONS_A (2*1000*1000*1000L)
#define NUM_ITERATIONS_B (1000*1000*1000L)

#define NANOS (1000L*1000*1000)

/*
 * Thread used to send notifications
 */
int
main(int arcg, char *argv[]) {
  clock_t start, end;
  int64_t seconds;
  double nanos;
  

  // Setup
  if (!setup()) {
    fprintf(stderr, "setup() failed\n");
    exit(1);
  }
  if (!register_callback(recv_int)) {
      fprintf(stderr, "register_callback() failed\n");
      exit(1);
  }

  // 1. A straight C call
  start = clock();
  for (int64_t i = 0; i < NUM_ITERATIONS_A; i++) {
      if (!callf(0x0BADBEEF, 0, 0)) {
          fprintf(stderr, "callf() failed\n");
          exit(1);
      }
  }
  end = clock();
  seconds = (end - start) / CLOCKS_PER_SEC;
  nanos = (double)seconds / NUM_ITERATIONS_A * NANOS;
  fprintf(stdout, "%ld simple calls takes %ld seconds or %g nanos/call\n",
          NUM_ITERATIONS_A, seconds, nanos);

  // 2. A one-to-one call back
  start = clock();
  for (int64_t i = 0; i < NUM_ITERATIONS_B; i++) {
      if (!callf(0x0BADBEEF, 1, 0)) {
          fprintf(stderr, "callf() failed\n");
          exit(1);
      }
  }
  end = clock();
  seconds = (end - start) / CLOCKS_PER_SEC;
  nanos = (double)seconds / NUM_ITERATIONS_B * NANOS;
  fprintf(stdout, "%ld 1-to-1 callbacks takes %ld seconds or %g nanos/call\n",
          NUM_ITERATIONS_B, seconds, nanos);

  // 3. a one-to-n simple call me back
  start = clock();
  if (!callf(0x0BADBEEF, NUM_ITERATIONS_A, 0)) {
      fprintf(stderr, "callf() failed\n");
      exit(1);
  }
  end = clock();
  seconds = (end - start) / CLOCKS_PER_SEC;
  nanos = (double)seconds / NUM_ITERATIONS_A * NANOS;
  fprintf(stdout, "%ld 1-to-n callbacks takes %ld seconds or %g nanos/call\n",
          NUM_ITERATIONS_A, seconds, nanos);

  // 4. a one-to-n threaded call me back
  start = clock();
  if (!callf(0x0BADBEEF, NUM_ITERATIONS_A, 0)) {
      fprintf(stderr, "callf() failed\n");
      exit(1);
  }
  end = clock();
  seconds = (end - start) / CLOCKS_PER_SEC;
  nanos = (double)seconds / NUM_ITERATIONS_A * NANOS;
  fprintf(stdout, "%ld 1-to-n threaded callback takes %ld seconds or %g nanos/call\n",
          NUM_ITERATIONS_A, seconds, nanos);

  
}
