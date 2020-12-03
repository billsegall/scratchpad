package main

/*
#cgo CFLAGS: -I ../C
#include "../C/structs.h"

*/
import "C"

import (
	"fmt"
	"go/types"
	"unsafe"
)

type GoT1 struct {
	i32  int32
	i8   int8
	u8   uint8
	i16  int16
	i32a int32
	i32b int32
	i32c int32
	i32d int32
	i64  int64
}

type GoT2 struct {
	i64a int64
	i64b int64
	i64c int64
	pad1 [(2 * 64) - (3 * unsafe.Sizeof(types.Int64))]byte
}

type GoT3 struct {
	i8a int8
	i32 int32
	i8b int8
	i16 int16
}

func main() {
	var got1 GoT1
	var got2 GoT2
	var got3 GoT3
	var ct1_4 C.t1_p4_t
	var ct2_2 C.t2_p2_t
	var ct2_4 C.t2_p4_t
	var ct2_8 C.t2_p8_t
	var ct3_2 C.t3_p2_t
	var ct3_4 C.t3_p4_t
	var ct3_8 C.t3_p8_t

	fmt.Printf("sizeof(got1) = %d, offsets:\n"+
		"\tint32_t\t%d\n"+
		"\tint8_t\t%d\n"+
		"\tuint8_t\t%d\n"+
		"\tint16_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint64_t\t%d\n\n",

		unsafe.Sizeof(got1),
		unsafe.Offsetof(got1.i32),
		unsafe.Offsetof(got1.i8),
		unsafe.Offsetof(got1.u8),
		unsafe.Offsetof(got1.i16),
		unsafe.Offsetof(got1.i32a),
		unsafe.Offsetof(got1.i32b),
		unsafe.Offsetof(got1.i32c),
		unsafe.Offsetof(got1.i32d),
		unsafe.Offsetof(got1.i64))

	fmt.Printf("sizeof(ct1_4) = %d, offsets:\n"+
		"\tint32_t\t%d\n"+
		"\tint8_t\t%d\n"+
		"\tuint8_t\t%d\n"+
		"\tint16_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint32_t\t%d\n"+
		"\tint64_t\t%d\n\n",
		unsafe.Sizeof(ct1_4),
		unsafe.Offsetof(ct1_4.i32),
		unsafe.Offsetof(ct1_4.i8),
		unsafe.Offsetof(ct1_4.u8),
		unsafe.Offsetof(ct1_4.i16),
		unsafe.Offsetof(ct1_4.i32a),
		unsafe.Offsetof(ct1_4.i32b),
		unsafe.Offsetof(ct1_4.i32c),
		unsafe.Offsetof(ct1_4.i32d),
		unsafe.Offsetof(ct1_4.i64))

	fmt.Printf("sizeof(got2) = %d\n"+
		"sizeof(ct2_2) = %d\n"+
		"sizeof(ct2_4) = %d\n"+
		"sizeof(ct2_8) = %d\n\n",
		unsafe.Sizeof(got2),
		unsafe.Sizeof(ct2_2),
		unsafe.Sizeof(ct2_4),
		unsafe.Sizeof(ct2_8),
	)

	fmt.Printf("sizeof(got3) = %d\n"+
		"sizeof(ct3_2) = %d\n"+
		"sizeof(ct3_4) = %d\n"+
		"sizeof(ct3_8) = %d\n",
		unsafe.Sizeof(got3),
		unsafe.Sizeof(ct3_2),
		unsafe.Sizeof(ct3_4),
		unsafe.Sizeof(ct3_8))
}
