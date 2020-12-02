// Copyright (C) Bill Segall 2020, All rights reserved
package go_callback

import (
	"testing"
)

var numcalls int

func callback(recvme int) {
	numcalls++
}

func callf(sendme int, count int, threaded bool) bool {
	if count <= 0 {
		return true
	}

	if !threaded {
		for i := 0; i < count; i++ {
			callback(sendme)
		}
		return true
	}
	return false
}

func BenchmarkSingleCall(b *testing.B) {
	for n := 0; n < b.N; n++ {
		callf(0x0BADBEEF, 0, false)
	}
}

func BenchmarkOneToOne(b *testing.B) {
	for n := 0; n < b.N; n++ {
		callf(0x0BADBEEF, 1, false)
	}
}

func BenchmarkOneToMillion(b *testing.B) {
	OneMillion := 1000 * 1000
	for n := 0; n < b.N; n += OneMillion {
		callf(0x0BADBEEF, OneMillion, false)
	}
}
