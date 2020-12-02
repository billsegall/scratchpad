/* Copyright (C) Bill Segall 2020, All rights Reserved */
#if !defined(CALLBACK_H)
#define CALLBACK_H
#include <stdbool.h>

/*
 * Setup the threads and state
 *
 * Returns true on success
 */
bool setup(void);

/*
 * Send nmgs containing the int sendme, possibly in a separate thread
 *
 * Returns true on success
 */
bool callf(int sendval, int count, bool threaded);

/*
 * Callback signature
 */
typedef void (*callback_int_t)(int value);

/*
 * Register a callback
 *
 * Returns true on success
 */
bool register_recv_int(callback_int_t cb);

#endif // PERF_H
