//  Builds Half-Pyramid For Mario following the algorithm mentioned as follows.
//
// Algorithm :
//
//    1. Gets the Required Height between the given constraint. Else, it keeps prompting untill right number is inputted
//    2. Prints the Spaces
//    3. Prints the Steps
//    4. Go To Next Line
//    5. Repeat till Given Height is reached.


#include <stdio.h>
#include <cs50.h>

int getRequiredHeight(int minHeight, int maxHeight);
void printSpaces(int spacesCount);
void printSteps(int stepsCount);

int main(void)
{
    int height = getRequiredHeight(0, 23);
    int line = 0;

    for (int row = 0; row < height; row++)
    {
        line = height - row;
        printSpaces(line);
        printSteps(row);
        printf("  ");
        printSteps(row);
        //printSpaces(line);
        printf("\n");

    }
}

// Gets the Height Between Given Range

int getRequiredHeight(int minimumValue, int maximumValue)
{
    int height = -1;

    do
    {
        height = get_int("Height: ");

    } while(height < minimumValue || height > maximumValue);

    return height;
}

// Prints Spaces in a Row

void printSpaces(int spacesCount)
{
    for (int spacePos = 1; spacePos < spacesCount; spacePos++)
    {
        printf(" ");
    }
}

// Prints Steps in a Row

void printSteps(int stepsCount)
{
    for (int stepPos = 0; stepPos <= stepsCount; stepPos++)
    {
        printf("#");
    }
}