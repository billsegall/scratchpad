cgo struct packing
==================

It is confirmed that the cgo does not support the `#pragma pack(n)`
directive and so we need to check any packed structs and if not
conformant with the host platform, use byte slicing to work around the
`go` / `C` boundaries.

It's also confirmed that the structures of intererest are ok as they are.

Building and executing
----------------------
To build and execute the C test program:
```
    cmake
    make
    C/packing
```

To build and execute the cgo:
```
    go build
    ./cgo
```

TODO
----
 