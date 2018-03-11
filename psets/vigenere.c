// Printout Cipher text for the given Plain Text, with Key given in command line argument

#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define ALPHABETS_COUNT 26
#define UPPER_CASE_A_ASCII_CODE 65
#define UPPER_CASE_Z_ASCII_CODE 90
#define LOWER_CASE_a_ASCII_CODE 97
#define LOWER_CASE_z_ASCII_CODE 122

int main(int argc, string argv[])
{
    string keyword;
    int status;
    string plainText;

    if(argc == 2)
    {
        // Logic
        keyword = argv[1]; // 0th index is for the program name;
        int keywordLength = strlen(keyword);
        int *keyNumbers = malloc(keywordLength * sizeof(int));

        // Sanity Check for the keyHash to not to be non-alphabetic
        for(int i = 0; i < keywordLength; i++)
        {
            char tempChar = keyword[i];
            if(!isalpha(tempChar))
            {
                printf("Usage: ./vigenere key\n");
                status = 1; // Signifies Error
                return status;
            }
            else
            {
                // instead of Switch Case, use the Ascii Codes
                if(isupper(tempChar))
                {
                    keyNumbers[i] = (int)(tempChar) - UPPER_CASE_A_ASCII_CODE;
                }
                else
                {
                    keyNumbers[i] = (int)(tempChar) - LOWER_CASE_a_ASCII_CODE;
                }
                //printf("keyNumbers[%d] is: %d\n", i, keyNumbers[i]);
                //printf("address of keyNumbers[%d] is %p\n", i, (void*)&keyNumbers[i]);

            }
        }


        plainText = get_string("plaintext: ");
        int  plainTextLength = strlen(plainText);
        char *cipherText = malloc((plainTextLength+1) * (sizeof(char)));
        int circleBackFromLowerCaseA = LOWER_CASE_a_ASCII_CODE - LOWER_CASE_z_ASCII_CODE - 1; // Upper Bound of Lower Case Letter [a-z] => [97-122]
        int circleBackFromUpperCaseA = UPPER_CASE_A_ASCII_CODE - UPPER_CASE_Z_ASCII_CODE - 1; // Upper Bound of Upper Case Letter [A-Z] => [65-90]

        /*
            1. Upper Case
            2. Lower Case
            3. Edge Cases - Rotate them.
            4. If Not Alphabet - Leave
        */

        for(int currTextIndex = 0; currTextIndex < plainTextLength; currTextIndex++)
        {
            for(int keyTextIndex = 0; keyTextIndex < keywordLength; keyTextIndex++)
            {
                char currentPlainLetter = plainText[currTextIndex];
                int currentKeyNumberForKeyLetter = keyNumbers[keyTextIndex];
                char currentCipherLetter = currentPlainLetter;

                if(isalpha(currentPlainLetter))
                {
                    int cipherLetterAscii = ((int)currentPlainLetter) + currentKeyNumberForKeyLetter;

                    currentCipherLetter = (isupper(currentPlainLetter) && (cipherLetterAscii > UPPER_CASE_Z_ASCII_CODE))
                                            ? (char)(cipherLetterAscii + circleBackFromUpperCaseA)
                                            : ((islower(currentPlainLetter) && (cipherLetterAscii > LOWER_CASE_z_ASCII_CODE))
                                                ? (char)(cipherLetterAscii + circleBackFromLowerCaseA)
                                                : (char)(cipherLetterAscii));

                    // Edge Case
                    if(currTextIndex == plainTextLength) break;

                }
                else
                {
                    keyTextIndex--;
                }

                cipherText[currTextIndex] = currentCipherLetter;
                currTextIndex++;

                //printf("Current Text Index: %d | Current Key Index: %d | Current Plain Letter: %c | Current Cipher Letter: %c\n", currTextIndex, keyTextIndex, currentPlainLetter, currentCipherLetter);
            }

            // Decrement the Plain Text Value by 1, as there would be double increment and we will miss the single character
            currTextIndex--;
        }

        printf("ciphertext: %s\n", cipherText);
        status = 0; // No Error
    }
    else
    {
        printf("Usage: ./vigenere key\n");
        status = 1; // Signifies Error
    }

    return status;
}