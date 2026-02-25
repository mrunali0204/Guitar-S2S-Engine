#include "spectrum.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#else
#include <unistd.h>
#endif

int get_color_code(const char *note)
{
    if (note == NULL || note[0] == '\0')
        return 37;
    char base = note[0];
    switch (base) {
    case 'C': return 31;
    case 'D': return 32;
    case 'E': return 33;
    case 'F': return 34;
    case 'G': return 35;
    case 'A': return 36;
    case 'B': return 37;
    default:  return 37;
    }
}

void print_colored_note(const char *note)
{
    int code = get_color_code(note);
    printf("\033[%dm%s\033[0m", code, note);
}

void animate_note_color(const char *note)
{
    if (note == NULL)
        return;
    int base = get_color_code(note);
    for (int i = 0; i < 8; ++i) {
        printf("\033[H\033[J");
        int code = base + i;
        if (code > 37)
            code = 30 + (code - 38);
        printf("\033[%dm%s\033[0m\n", code, note);
        usleep(80000);
    }
}
