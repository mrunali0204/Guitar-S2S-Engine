# Guitar-S2S-Engine
Terminal-based Guitar String-to-Spectrum Simulation Engine written in C.


Guitar-S2S-Engine/
├── src/
│   ├── main.c            ← interactive driver + animation loop
│   ├── fretboard.c       ← string‑fret→note mapping (phase 1)
│   ├── spectrum.c        ← ANSI colour utilities & gradient animation (phase 2/5)
│   ├── note_engine.c     ← frequency calculator (phase 3)
├── include/
│   ├── fretboard.h
│   ├── spectrum.h
│   ├── note_engine.h
├── README.md
├── Makefile
└── .gitignore

🔧 Module summary
1. Fretboard
static const char * const fretboard[6][13] (standard tuning, 0–12 frets).
const char *get_note(int string, int fret) – returns note or NULL for invalid input.
Input is validated; data is const and immutable.

2. Spectrum
int get_color_code(const char *note) maps C‑B to ANSI codes (red, green, …).
void print_colored_note(const char *note) prints a note in colour.
void animate_note_color(const char *note) clears the screen and cycles
through ANSI shades with usleep() delays (wrapped for Windows).

3. Note Engine
Converts note name and octave to frequency using A4 = 440 Hz:
Recognises sharps and common enharmonic equivalents.
Uses twelve‑tone equal temperament formula.

4. Interactive main.c
Repeatedly prompts for string (1–6) and fret (0–12); 0 quits.
Derives octave from string & fret (open‑string octaves hard‑coded).
Displays note name, frequency and an animated coloured output.
Uses fgets/sscanf for safe input; handles invalid values gracefully.
Cross‑platform handling of usleep() for Windows.

5. Build infrastructure
Makefile with gcc flags (-Iinclude -Wall -Wextra -std=c11 -lm).
.gitignore excludes object files, executables.



contains:
Project overview
Architectural description of each module
Features list
Build/run instructions
Suggestions for future improvements



🎸 Guitar String‑to‑Spectrum Engine:

Enter string (1-6, 0 to quit): 6
Enter fret (0-12): 3
Note: G2
Frequency: 98.00 Hz