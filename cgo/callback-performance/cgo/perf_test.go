package cgo_callback

import (
	"os"
	"testing"
)

// Local tuning
var hundredthousand int = 100 * 1000
var million int = 1000 * 1000

func TestMain(m *testing.M) {
	Setup()
	os.Exit(m.Run())
}

func BenchmarkSingleCall(b *testing.B) {
	// Avoid most of the parent call overhead by lots at a time
	for n := 0; n < b.N; n += million {
		SingleCallN(million)
	}
}

func BenchmarkOneToOne(b *testing.B) {
	// Avoid most of the parent call overhead by lots at a time
	for n := 0; n < b.N; n += hundredthousand {
		OneToOneN(hundredthousand)
	}
}

func BenchmarkOneToMillion(b *testing.B) {
	for n := 0; n < b.N; n += hundredthousand {
		OneToN(hundredthousand)
	}
}
