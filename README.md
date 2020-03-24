# FAZOS

My attmempt to create OS (yes! operating system)

For now it's just a kernel (sort of)

## Kernel

Build:

```sh
$ ./setup.sh
$ ./make_in_docker.sh
```

Run:

```sh
$ qemu-system-i386 -kernel kernel/kernel.bin
```
