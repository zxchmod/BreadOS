#include "input.h"

char get_key() {
    char c;
    asm volatile(
        "xor %%ah, %%ah\n"  // BIOS: AH=0
        "int $0x16\n"       // BIOS keyboard interrupt
        "mov %%al, %0\n"
        : "=r"(c)
        :
        : "ah"
    );
    return c;
}
