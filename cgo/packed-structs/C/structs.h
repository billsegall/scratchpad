// Copyright (C) Bill Segall 2020, All rights reserved

// The same structures I want to check cgo usage of with three
// different (2, 4, 8) packing pragmas

#include <stdint.h>


#pragma pack(push)
#pragma pack(2)

typedef struct {
    int32_t i32;
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    int32_t i32a;
    int32_t i32b;
    int32_t i32c;
    int32_t i32d;
    int64_t i64;
} t1_p2_t;

typedef struct {
    int64_t i64a;
    int64_t i64b;
    int64_t i64c;
    uint8_t pad1[(2 * 64u) - (3 * sizeof(int64_t))];
} t2_p2_t;

typedef struct {
    int8_t  i8a;
    int32_t i32;
    int8_t  i8n;
    int16_t i16;
} t3_p2_t;

#pragma pack(pop)

#pragma pack(push)
#pragma pack(4)

typedef struct
{
    int32_t i32;
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    int32_t i32a;
    int32_t i32b;
    int32_t i32c;
    int32_t i32d;
    int64_t i64;
}
t1_p4_t;

typedef struct
{
    int64_t i64a;
    int64_t i64b;
    int64_t i64c;
    uint8_t pad1[(2 * 64u) - (3 * sizeof(int64_t))];
}
t2_p4_t;

typedef struct {
    int8_t  i8a;
    int32_t i32;
    int8_t  i8n;
    int16_t i16;
} t3_p4_t;

#pragma pack(pop)

#pragma pack(push)
#pragma pack(8)

typedef struct
{
    int32_t i32;
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    int32_t i32a;
    int32_t i32b;
    int32_t i32c;
    int32_t i32d;
    int64_t i64;
} t1_p8_t;

typedef struct
{
    int64_t i64a;
    int64_t i64b;
    int64_t i64c;
    uint8_t pad1[(2 * 64u) - (3 * sizeof(int64_t))];
} t2_p8_t;

typedef struct {
    int8_t  i8a;
    int32_t i32;
    int8_t  i8n;
    int16_t i16;
} t3_p8_t;

#pragma pack(pop)
    
