# Zephyr Bonjour

A minimal Zephyr RTOS application that prints "bonjour" every 2 seconds on the
console.

## Prerequisites

- [Zephyr SDK](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)
- [West](https://docs.zephyrproject.org/latest/develop/west/index.html)
  (Zephyr's meta-tool)
- QEMU (for emulated targets)

## Setup

```sh
west init -l .
west update
```

## Build & Run

### Cortex-M3 (QEMU)

```sh
west build -b qemu_cortex_m3
west build -t run
```

### Tensilica Xtensa (QEMU)

```sh
west build -b qemu_xtensa/dc233c
west build -t run
```

> Note: Switching boards requires a pristine build. Use
> `west build -p -b <board>` to auto-pristine, or manually clean with
> `west build -t clean` before rebuilding for a different target.
