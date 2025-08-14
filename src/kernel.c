#include "screen.h"
#include "power.h"
#include "input.h"
#include <stdio.h>

int battery_level = 100; // Заряд батареи

void show_battery() {
    print("\nBattery Status:\n[");
    int bars = battery_level / 10;
    for(int i = 0; i < 10; i++) {
        if(i < bars) print("|");
        else print(" ");
    }
    print("] ");
    
    char buf[5];
    int len = snprintf(buf, sizeof(buf), "%d%%\n", battery_level);
    for(int i=0; i<len; i++) print_char(buf[i]);
}

void show_menu() {
    print("\nBreadOS Main Menu:\n");
    print("1. Battery Status\n");
    print("2. Device Info\n");
    print("3. Sleep Mode\n");
    print("Select an option: ");
}

void handle_selection(char key) {
    switch(key) {
        case '1':
            show_battery();
            break;
        case '2':
            print("\nDevice: Headphone Case v1.0\n");
            break;
        case '3':
            print("\nEntering Sleep Mode...\n");
            idle_loop();
            break;
        default:
            print("\nInvalid option!\n");
            break;
    }
}

void kernel_main() {
    print_logo();

    while(1) {
        show_menu();
        char key = get_key();
        print("\n");
        handle_selection(key);
    }
}
