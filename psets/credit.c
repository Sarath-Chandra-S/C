// Check For Valid Credit Card or Not.
// Implementation of Luhn's Algorithm

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string getCardType(long long a);
int getDigitCount(long long b);
int getChecksum(long long c);
bool isLastDigitOfChecksumZero(int d);
char getCardIndicator(long long e);
string getStringType(string f);

int main(void)
{
    long long ccNumber = get_long_long("Number: ");
    string type = getCardType(ccNumber);
    printf("%s", type);
    printf("\n");
    return 0;
}

string getCardType(long long number)
{
    string type = "INVALID";
    int noOfDigits = getDigitCount(number);
    int checksum = getChecksum(number);
    char cardIndicator = getCardIndicator(number);

    if(cardIndicator != 'I')
    {
        bool isValidChecksumDigit = isLastDigitOfChecksumZero(checksum);

        if(isValidChecksumDigit)
        {
            if(noOfDigits == 15 && cardIndicator == 'A')
            {
                type = "AMEX";
            }
            else if(noOfDigits == 16 && cardIndicator == 'M')
            {
                type = "MASTERCARD";
            }
             else if((noOfDigits == 13 || noOfDigits == 16) && cardIndicator == 'V')
            {
                type = "VISA";
            }
        }
    }

    return type;
}

// Done
// Returns No. of Digits in given Number

int getDigitCount(long long number)
{
    long long dividend = number;
    int cardLength = 0;

    for(int i = 0, divisor = 10; dividend > 0 ;i++)
    {
        dividend = dividend / divisor;
        cardLength++;
    }

    return cardLength;
}

// Done
// Returns True or False depending on digit in Units Place of checksum

bool isLastDigitOfChecksumZero(int checksum)
{
    return (((checksum % 10) == 0) ? true: false);
}

// Done
// Returns Card Indicator -> I : Invalid, A : Amex, M : Master, V : Visa

char getCardIndicator(long long number)
{
    long long dividend = number;
    int cardLength = 0;
    int cardDigitArray[20];
    int divisor = 10;

    for(int i = 0; dividend > 0 ;i++)
    {
        int currDigit = dividend % divisor;
        cardDigitArray[i] = currDigit;
        dividend = dividend / divisor;
        cardLength++;
    }


    char indicator = 'I';

    for(int i = 0; i < cardLength; i++)
    {
        int firstIndex = cardLength-1-i;
        int secondIndex = firstIndex - 1; // navigate in reverse to retrieve, as above storage happens in reverse in storing given number

        if(cardDigitArray[firstIndex] == 3 && (cardDigitArray[secondIndex] == 4 || cardDigitArray[secondIndex] == 7))
        {
            indicator = 'A';
        }
        else if(cardDigitArray[firstIndex] == 5
                && (cardDigitArray[secondIndex] == 1 || cardDigitArray[secondIndex] == 2
                    || cardDigitArray[secondIndex] == 3 || cardDigitArray[secondIndex] == 4
                    || cardDigitArray[secondIndex] == 5))
        {
            indicator = 'M';
        }
        else if(cardDigitArray[firstIndex] == 4)
        {
            indicator = 'V';
        }

        // Break the loop after first iteration, as subsequent iterations are not required.
        break;

    }
    return indicator;
}


// Done
// Checksum Logic
/*
    1. Identify every second digit and save in memory
    2. Multiply each digit in step 1 by factor 2 and save individually.
    3. If any of individual results in step 2 are multiple digits,
        a. then, split those digits individually and add them
            Ex: if in step 2, result is 18, then 1 and 8 shoud be saved separately.
    4. Add all the single digit results in step 2 to multiple digits result and save to memory.
    5. Identify all the left out digits which are not included in step 1.
    6. Add all the digits in step 5 and store the result.
    7. Sum the result obtained in Step 4 to Step 6, which is checksum for the number given and return it.

*/

int getChecksum(long long number)
{
    int checksum = 0;
    long long dividend = number;
    int len = 0;
    int arr[20];
    int divisor = 10;

    for(int i = 0; dividend > 0 ;i++)
    {
        int rmndr = dividend % divisor;
        arr[i] = rmndr;
        dividend = dividend / divisor;
        len++;
    }

    for(int j=0;j < len;j++)
    {

        int currentIndex = len-1-j;
        //printf("Current Index: %i\n", currentIndex);

        // Logic For Even Index - No Special Logic, Just take that value from Card Number and add to checksum

        if(currentIndex % 2 == 0)
        {
             checksum += arr[currentIndex];

            /*printf("Even | No Digit Consideration |  value -> %i | doubledValue -> %s | dividendInDblVal -> %s | currentDigitSum -> %i | checksum -> %i\n",
                    arr[currentIndex],
                    "nothing",
                    "nothing",
                    arr[currentIndex],
                    checksum);*/
        }

        // Logic for Odd Index / Indices
        else
        {
            int oddIndexDoubledVal = 2 * arr[currentIndex];

            if(oddIndexDoubledVal >= 10)
            {
                int dividend2 = oddIndexDoubledVal;
                int digitsSum = 0;
                int currentDigit = 0;

                // repetetive logic by dividing 10 till the dividend decreases to zero. Put in function
                for (int k = 0; dividend2 > 0; k++)
                {
                    currentDigit = dividend2 % 10;
                    digitsSum += currentDigit;
                    dividend2 = dividend2 / 10;
                }

                checksum += digitsSum;

                /*printf("Odd | Double Digit |  value -> %i | doubledValue -> %i | dividendInDblVal -> %i | currentDigitSum -> %i | checksum -> %i\n",
                    arr[currentIndex],
                    oddIndexDoubledVal,
                    dividend2,
                    digitsSum,
                    checksum);*/
            }

            // when doubledValue is single digit. No special work, add to checksum
            else
            {
                checksum += oddIndexDoubledVal;

                /*printf("Odd | Single Digit |  value -> %i | doubledValue -> %i | dividendInDblVal -> %s | currentDigitSum -> %i | checksum -> %i\n",
                    arr[currentIndex],
                    oddIndexDoubledVal,
                    "nothing",
                    oddIndexDoubledVal,
                    checksum);*/
            }
        }
    }

    //printf("Checksum Value: %i\n", checksum);

    return checksum;

}
