#ifndef SPECTRUM_H
#define SPECTRUM_H

/*
 * ANSI color helpers for notes.
 * The code values correspond to the standard 30-37/90-97 foreground colors.
 */

int get_color_code(const char *note);
void print_colored_note(const char *note);
void animate_note_color(const char *note);

#endif /* SPECTRUM_H */
