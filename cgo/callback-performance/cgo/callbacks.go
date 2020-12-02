package cgo_callback

/*

#include <stdio.h>

// The gateway function
void callback_cgo(int in)
{
        // printf("C.callback_cgo(): called with arg = %d\n", in);
        void callback(int); //declaration
        callback(in);
	return;
}
*/
import "C"
