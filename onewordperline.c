// To Print One Word per line from Input

#include <stdio.h>

#define SUCCESS 1

int main(void)
{
    int c;
    int lineCount = 0;

    while ( (c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
        {
            // irrespective of no. of times spaces or tabs are repeated,
            // line break should happen only once.
            if(lineCount == 0)
                putchar('\n');

            lineCount++;
        }
        else
        {
            if(lineCount > 0)
            {
                lineCount = 0;
            }

            putchar(c);
        }
    }

    return SUCCESS;
}