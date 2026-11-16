# il1
inspiron linux tinyconfig

```
make -j 16 CC="ccache gcc" KBUILD_BUILD_TIMESTAMP='' && qemu-system-x86_64 -kernel ./arch/x86/boot/bzImage -bios /usr/share/ovmf/OVMF.fd
```

```
make KCPPFLAGS="-dD" drivers/video/fbdev/efifb.i
```
