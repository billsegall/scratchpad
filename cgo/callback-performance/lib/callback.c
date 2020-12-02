/* Copyright (C) Bill Segall 2020, All rights Reserved */

#include "callback.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Hold our state */
typedef struct {
    pthread_t thread;
    pthread_mutex_t mux;
    pthread_cond_t cv;
    callback_int_t cb;
    bool initialized;
    int sendme;
    int count;
} ctest_state_t;
static ctest_state_t state;

/*
 * I find these make things easier to read
 */
#define LOCK() if ((err = pthread_mutex_lock(&state.mux))) { \
        printf("pthread_mutex_lock() failed: %d\n", err);        \
  exit(err); \
}
#define UNLOCK() if ((err = pthread_mutex_unlock(&state.mux))) { \
        printf("pthread_mutex_unlock() failed: %d\n", err);          \
  exit(err); \
}
#define SIGNAL() if ((err = pthread_cond_signal(&state.cv))) { \
        printf("pthread_cond_signal() failed: %d\n", err);         \
  exit(err); \
}
#define WAIT() if ((err = pthread_cond_wait(&state.cv, &state.mux))) { \
        printf("pthread_cond_wait() failed: %d\n", err);                   \
  exit(err); \
}

/*
 * Thread used to send notifications
 */
static void *notify_main(void *arg) {
    int err = 0;

    // Loop awaiting a signal to send
    while (1) {

        // Let our initiator know we're running
        LOCK();
        state.initialized = true;
        SIGNAL();
        UNLOCK();

        // Await something to do
        while (state.count <= 0) {
            LOCK();
            WAIT();

            if (!state.cb) {
                fprintf(stderr, "callback is null\n");
            } else {
                while (state.count-- > 0) {
                    if (NULL != state.cb) {
                        (void) state.cb(state.sendme);
                    } else {
                        fprintf(stderr, "callback is null\n");
                    }
                }
            }
            UNLOCK();
        }
    }

    perror("notify_main:");
    exit(err);
 
}

bool setup(void) {
    int err = 0;

    
    // Lock and load
    pthread_mutex_init(&state.mux, NULL);
    pthread_cond_init(&state.cv, NULL);

    LOCK();
    state.initialized = false;
    pthread_create(&state.thread, NULL, notify_main, NULL);
    while (!state.initialized) {
        WAIT();
    }
    UNLOCK();
    
    return true;
}

bool register_callback(callback_int_t cb) {
    int err = 0;

    LOCK();
    state.cb = cb;
    UNLOCK();

    return 1;
}

bool callf(int sendme, int count, bool threaded) {
    int err = 0;

    if (count <= 0) {
        return true;
    }

    if (!threaded) {
        for (int i = 0; i < count; i++) {
            (void) state.cb(sendme);
        }
        return true;
    }

    // Set up and fire off the sender
    LOCK();
    state.sendme = sendme;
    state.count = count;
    UNLOCK();
    SIGNAL();

    // Wait for the sending to finish
    LOCK();
    WAIT();
    while (state.count > 0) {
        WAIT();
    }
    UNLOCK();
           
    return true;
}

