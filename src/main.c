#include<stdio.h>
#include "fretboard.h"

int main()
{
    int string, fret;

    printf("🎸 Guitar S2S Engine - Basic Test\n");

    printf("Enter string number (1-6): ");
    scanf("%d", &string);

    printf("Enter fret number (1-12): ");
    scanf("%d", &fret);

    const char * note = get_note(string, fret);

    if(NULL != note)
        printf("Note played: %s\n", note);
    else    
        printf("Invalid input!\n");

    return 0;
}


/*compiler as 
gcc src/*.c -Iinclude -o s2s 
*/
