# Compiling and Linking for ARM Cortex M0+
[See tutorial @ EdwinFairchild.com](https://www.edwinfairchild.com/2022/04/no-ide-for-me.html)
To compile the `main.c` file located in the `src` directory and the `myStartUp.c` file in root directory, follow the steps below:

1. Open a terminal and navigate to the project directory.
2. Run the following command to compile `main.c`:

```shell
arm-none-eabi-gcc -g -c -std=gnu11 -mcpu=cortex-m0plus -mthumb -c src/main.c -o outputs/main.o
```

3. Run the following command to compile `myStartUp.c`:

```shell
arm-none-eabi-gcc -g -c -std=gnu11 -mcpu=cortex-m0plus -mthumb -c myStartUp.c -o outputs/myStartUp.o
```

To link the compiled object files with `myLinkerScript.ld` and generate the final output, use the following command:

```shell
arm-none-eabi-ld -g -nostdlib -T myLinkerScript.ld outputs/*.o  -o outputs/boot.elf -Wl,-Map=outputs/boot.map
```


All the output files will be generated in the `outputs` directory.
