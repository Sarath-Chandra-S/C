// Read Input and print it to Output

#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1
#define QUIT -1


int main()
{
    int c;

    /*  Why int c is declared and assigned with  getchar(),
        because, char can hold oly a single value, but EOF,
        which is being used to differentiate is more than
        size of char. Thus int type is being used.

        EOF = Ctrl+D in Unix and Ctrl+Z in Windows
    */

    printf("Press \"Ctrl+D\" for EOF\n");

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    printf("\"Ctrl+D\" was Pressed. Exitting Program\n");
    return SUCCESS;
}