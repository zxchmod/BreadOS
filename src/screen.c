#include <stdint.h>
#include "screen.h"

#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x0F

volatile uint16_t* video = (uint16_t*) VIDEO_MEMORY;
int cursor_pos = 0;

void clear_screen() {
    for(int i = 0; i < 80*25; i++) {
        video[i] = ((uint16_t)WHITE_ON_BLACK << 8) | ' ';
    }
    cursor_pos = 0;
}

void print_char(char c) {
    if(c == '\n') {
        cursor_pos += 80 - (cursor_pos % 80);
    } else {
        video[cursor_pos++] = ((uint16_t)WHITE_ON_BLACK << 8) | c;
    }
}

void print(const char* str) {
    while(*str) {
        print_char(*str++);
    }
}

void print_logo() {
    clear_screen();
    const char* logo[] = {
        "   ______                 ",
        "  / ____/___ _____  ____ _",
        " / /   / __ `/ __ \\/ __ `/",
        "/ /___/ /_/ / / / / /_/ / ",
        "\\____/\\__,_/_/ /_/\\__,_/  ",
        NULL
    };
    for(int i = 0; logo[i] != 0; i++) {
        print(logo[i]);
        print("\n");
    }
    print("\nby NameSugar\n\n");
}
