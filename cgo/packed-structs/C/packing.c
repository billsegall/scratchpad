/* Copyright (C) Bill Segall 2020, All rights Reserved */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "structs.h"

/*
 * Print sizeof packed struct and the offsets in it
 */
int
main(int arcg, char *argv[]) {

    t1_p2_t t1p2;
    t1_p4_t t1p4;
    t1_p8_t t1p8;

    t2_p2_t t2p2;
    t2_p4_t t2p4;
    t2_p8_t t2p8;

    t3_p2_t t3p2;
    t3_p4_t t3p4;
    t3_p8_t t3p8;
    

    fprintf(stdout,
            "sizeof(t1_p2_t) == %ld, offsets:\n"
            "\tint32_t\t%ld\n"
            "\tint8_t\t%ld\n"
            "\tuint8_t\t%ld\n"
            "\tint16_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint64_t\t%ld\n",

            sizeof(t1p2),
            (uintptr_t)&t1p2.i32 - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i8 - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.u8 - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i16 - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i32a - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i32b - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i32c - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i32d - (uintptr_t)&t1p2,
            (uintptr_t)&t1p2.i64 - (uintptr_t)&t1p2);

    fprintf(stdout,
            "sizeof(t1_p4_t) == %ld, offsets:\n"
            "\tint32_t\t%ld\n"
            "\tint8_t\t%ld\n"
            "\tuint8_t\t%ld\n"
            "\tint16_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint64_t\t%ld\n",

            sizeof(t1p4),
            (uintptr_t)&t1p4.i32 - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i8 - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.u8 - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i16 - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i32a - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i32b - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i32c - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i32d - (uintptr_t)&t1p4,
            (uintptr_t)&t1p4.i64 - (uintptr_t)&t1p4);

    fprintf(stdout,
            "sizeof(t1_p8_t) == %ld, offsets:\n"
            "\tint32_t\t%ld\n"
            "\tint8_t\t%ld\n"
            "\tuint8_t\t%ld\n"
            "\tint16_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint32_t\t%ld\n"
            "\tint64_t\t%ld\n",

            sizeof(t1p8),
            (uintptr_t)&t1p8.i32 - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i8 - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.u8 - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i16 - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i32a - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i32b - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i32c - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i32d - (uintptr_t)&t1p8,
            (uintptr_t)&t1p8.i64 - (uintptr_t)&t1p8);

        fprintf(stdout,
                "sizeof(t2_p2_t) == %ld\n"
                "sizeof(t2_p4_t) == %ld\n"
                "sizeof(t2_p8_t) == %ld\n",
                
                sizeof(t2p2),
                sizeof(t2p4),
                sizeof(t2p8));

        fprintf(stdout,
                "sizeof(t3_p2_t) == %ld\n"
                "sizeof(t3_p4_t) == %ld\n"
                "sizeof(t3_p8_t) == %ld\n",
                
                sizeof(t3p2),
                sizeof(t3p4),
                sizeof(t3p8));
}
