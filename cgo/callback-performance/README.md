cgo performance
===============

Here are some small code fragments to measure the relative peformance
of function calls and callbacks.

Summary
-------

| Language | Simple call | Simple callback |
|----------|-------------|-----------------|
| C        | 2ns         | 2ns             |
| go       | 2ns         | 2ns             |
| cgo      | 56ns        | 187ns           |

Building and executing
----------------------

To build and execute the C library and test program:

```
    cmake
    make
    lib/perf
```

To build and execute the go and cgo:

```
    go test -bench=. ./...
```

TODO
----

Possible enhancments:

 * Add some more complex examples to measure argument and return value costs
 * Measure threaded performance