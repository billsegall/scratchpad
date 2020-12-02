# Copyright (C) Bill Segall 2020 All Rights Reserved

cmake_minimum_required (VERSION 3.10.1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library (callback callback.c)

add_executable(perf perf.c)
target_link_libraries(perf callback)
target_link_libraries(perf ${CMAKE_THREAD_LIBS_INIT})
