#ifndef NOTE_ENGINE_H
#define NOTE_ENGINE_H

/*
 * Calculate the frequency of a note in a given octave.
 * The note string should be one of the standard names:
 *   C, C#, D, D#, E, F, F#, G, G#, A, A#, B
 * A4 is assumed to be 440.0 Hz; octaves follow scientific pitch notation.
 * Returns 0.0 on invalid input.
 */

double get_frequency(const char *note, int octave);

#endif /* NOTE_ENGINE_H */
