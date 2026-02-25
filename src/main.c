#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fretboard.h"
#include "spectrum.h"
#include "note_engine.h"

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#endif

int main(void)
{
    char buf[32];
    int string, fret;
    /* octave of open strings from low E (6) to high E (1) */
    const int base_octaves[6] = {2, 2, 3, 3, 3, 4};

    printf("🎸 Guitar String‑to‑Spectrum Engine\n");

    for (;;) {
        printf("\nEnter string (1-6, 0 to quit): ");
        if (!fgets(buf, sizeof buf, stdin))
            break;
        if (sscanf(buf, "%d", &string) != 1)
            continue;
        if (string == 0)
            break;

        printf("Enter fret (0-12): ");
        if (!fgets(buf, sizeof buf, stdin))
            break;
        if (sscanf(buf, "%d", &fret) != 1)
            continue;

        const char *note = get_note(string, fret);
        if (note == NULL) {
            printf("Invalid string/fret combination\n");
            continue;
        }

        /* octave increments by one at the 12th fret */
        int octave = base_octaves[string - 1] + (fret == 12 ? 1 : 0);
        double freq = get_frequency(note, octave);

        printf("Note: %s%d\n", note, octave);
        printf("Frequency: %.2f Hz\n", freq);

        animate_note_color(note);
    }

    printf("Goodbye!\n");
    return 0;
}
