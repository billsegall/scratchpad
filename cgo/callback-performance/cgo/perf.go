// Copyright (C) Bill Segall 2020, All rights reserved
package cgo_callback

// We can't call cgo in go tests so we provide cgo wrapper functions here

/*
#cgo CFLAGS: -pthread
#cgo LDFLAGS: -L ../lib -lcallback
#include "../lib/callback.h"
int callback_cgo(int num); // Forward declaration
*/
import "C"

import (
	"fmt"
	"unsafe"
)

var counter int

//export callback
func callback(num int) {
	counter++
	return
}

func Setup() bool {
	if !C.setup() {
		fmt.Printf("setup failed\n")
		return false
	}

	if !C.register_callback((C.callback_int_t)(unsafe.Pointer(C.callback_cgo))) {
		fmt.Printf("register failed\n")
		return false
	}

	return true
}

func SingleCallN(n int) {
	for i := 0; i < n; i++ {
		C.callf(0x0BADBEEF, 0, false)
	}
}

func OneToOneN(n int) {
	for i := 0; i < n; i++ {
		C.callf(0x0BADBEEF, 1, false)
	}
}

func OneToN(n int) {
	C.callf(0x0BADBEEF, C.int(n), false)
}
