#include "note_engine.h"
#include <string.h>
#include <math.h>

static int note_to_semitone(const char *note)
{
    if (note == NULL)
        return -1000;
    if (strcmp(note, "C") == 0) return 0;
    if (strcmp(note, "C#") == 0 || strcmp(note, "Db") == 0) return 1;
    if (strcmp(note, "D") == 0) return 2;
    if (strcmp(note, "D#") == 0 || strcmp(note, "Eb") == 0) return 3;
    if (strcmp(note, "E") == 0) return 4;
    if (strcmp(note, "F") == 0) return 5;
    if (strcmp(note, "F#") == 0 || strcmp(note, "Gb") == 0) return 6;
    if (strcmp(note, "G") == 0) return 7;
    if (strcmp(note, "G#") == 0 || strcmp(note, "Ab") == 0) return 8;
    if (strcmp(note, "A") == 0) return 9;
    if (strcmp(note, "A#") == 0 || strcmp(note, "Bb") == 0) return 10;
    if (strcmp(note, "B") == 0) return 11;
    return -1000;
}

double get_frequency(const char *note, int octave)
{
    int semitone = note_to_semitone(note);
    if (semitone < 0 || octave < -1 || octave > 9)
        return 0.0;
    int n = (octave - 4) * 12 + (semitone - 9);
    return 440.0 * pow(2.0, n / 12.0);
}
