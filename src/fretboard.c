#include "fretboard.h"
#include <stdio.h>

/*
Standard tuning:
String 6 → E
String 5 → A
String 4 → D
String 3 → G
String 2 → B
String 1 → E
*/

static const char* fretboard[6][13] = 
{
    // String 6 (Low E)
    {"E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E"},
    
    // String 5 (A)
    {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A"},
    
    // String 4 (D)
    {"D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D"},
    
    // String 3 (G)
    {"G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G"},
    
    // String 2 (B)
    {"B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"},
    
    // String 1 (High E)
    {"E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E"}
};

const char* get_note(int string, int fret) {

    // Validate input
    if (string < 1 || string > 6 || fret < 0 || fret > 12) {
        return NULL;
    }

    // Adjust for 0-based indexing
    return fretboard[string - 1][fret];
}