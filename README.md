# Zephyr Bonjour

A minimal Zephyr RTOS application that prints "bonjour" every 2 seconds on the
console.

## Prerequisites

- [Zephyr SDK](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)
- [West](https://docs.zephyrproject.org/latest/develop/west/index.html)
  (Zephyr's meta-tool)
- QEMU (for emulated targets)

## Setup environment

Once you have cloned zephyr into the folder z/:
```
z$ ls
zephyr

z$ python3 -m venv .venv
z$ source .venv/bin/activate
z$ pip install west
z$ pip install -r zephyr/scripts/requirements.txt
```

```
z$ git clone https://github.com/vjardin/zephyr-bonjour.git
z$ cd zephyr-bonjour
zephyr-bonjour$ west init -l .
zephyr-bonjour$ west update
```

```
z$ west sdk install --toolchains arm-zephyr-eabi --install-dir $(pwd)/zephyr-sdk
z$ west sdk install --toolchains xtensa-dc233c_zephyr-elf --install-dir "$(pwd)/zephyr-sdk"
```

```
z$ export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
z$ export ZEPHYR_SDK_INSTALL_DIR=$(pwd)/zephyr-sdk/
```

## Compile & run

```
zephyr-bonjour$ west build -b qemu_cortex_m3
zephyr-bonjour$ west build -t run
```

# Setup NRF (Nordic)

```
z$ mkdir ../ncs && cd ../ncs
ncs$ west init -m https://github.com/nrfconnect/sdk-nrf
ncs$ cd ../z
z$ pip install -r ../ncs/nrf/scripts/requirements.txt
```

## Compile

```
z$ cd zephyr-bonjour
zephyr-bonjour$ west build -b nrf9151dk/nrf9151/ns
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
