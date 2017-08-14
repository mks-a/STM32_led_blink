:: -g generate debug information
:: -c compile only
cls
"E:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-as" -mcpu=cortex-m3 -g .\code\main.s -o main.o
::"E:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-ld" -Map=main.map -Ttext=0x0 -o main.elf main.o
"E:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-ld" -T stm32f103c8t6_link_map.ld -o main.elf main.o
"E:\ARM_Toolchain\gcc-arm-none-eabi-6-2017-q2-update-win32\bin\arm-none-eabi-objcopy" -O binary main.elf main.bin

