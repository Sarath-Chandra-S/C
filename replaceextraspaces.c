// Replace Tabs with Single Spaces till EOF
// EOF = Ctrl+D

#include <stdio.h>

#define SUCCESS 0
#define EMPTY_CHARACTER '\0'

int main(void)
{
    int c;
    double tabCount, spaceCount;
    tabCount = spaceCount = 0;

    while( (c = getchar())  != EOF)
    {
        /*
            Find out the First Space, if there are
            extra spaces after that, replace all those
            extras with Sentinal Value, which is Empty Character.
            Finally, if countered with next non-space character,
            reset the count value
        */

        // Logic for Handling Tabs and extra tabs and spaces

        if( c == '\t' && tabCount == 0)
        {
            c = ' ';
            tabCount++;
        }
        else if( c == '\t' && tabCount > 0)
        {
            c = EMPTY_CHARACTER;
        }
        else if(tabCount > 0)
        {
            tabCount = 0;

            // Relation to handle if Tabs and Spaces Come together
            if( c == ' ')
                spaceCount++;
        }



        // Logic for Handling all Extra Spaces

        if( c == ' ' && spaceCount == 0)
        {
            spaceCount++;
        }
        else if( c == ' ' && spaceCount > 0)
        {
             c = EMPTY_CHARACTER;
        }
        else if (spaceCount > 0)
        {
            spaceCount = 0;
        }

        putchar(c);
    }

    return SUCCESS;
}