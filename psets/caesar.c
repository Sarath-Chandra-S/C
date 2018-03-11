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
    int keyHash;
    int status;
    string plainText;

    if(argc == 2)
    {
        // Logic
        keyHash = atoi(argv[1]); // 0th index is for the program name;
        plainText = get_string("plaintext: ");
        int  plainTextLength = strlen(plainText);
        char cipherText[plainTextLength];
        int circleBackFromLowerCaseA = LOWER_CASE_a_ASCII_CODE - LOWER_CASE_z_ASCII_CODE - 1; // Upper Bound of Lower Case Letter [a-z] => [97-122]
        int circleBackFromUpperCaseA = UPPER_CASE_A_ASCII_CODE - UPPER_CASE_Z_ASCII_CODE - 1; // Upper Bound of Upper Case Letter [A-Z] => [65-90]

        /*
            1. Upper Case
            2. Lower Case
            3. Edge Cases - Rotate them.
            4. If Not Alphabet - Leave
        */

        if(keyHash > ALPHABETS_COUNT){
            keyHash = keyHash % ALPHABETS_COUNT;
        }

        for(int i = 0; i < plainTextLength;i++)
        {
            char currentLetter = plainText[i];
            char currentCipherLetter = currentLetter;

            if(isalpha(currentLetter))
            {
                int cipherLetterAscii = ((int)currentLetter) + keyHash;

                currentCipherLetter = (isupper(currentLetter) && (cipherLetterAscii > UPPER_CASE_Z_ASCII_CODE))
                                        ? (char)(cipherLetterAscii + circleBackFromUpperCaseA)
                                        : ((islower(currentLetter) && (cipherLetterAscii > LOWER_CASE_z_ASCII_CODE))
                                            ? (char)(cipherLetterAscii + circleBackFromLowerCaseA)
                                            : (char)(cipherLetterAscii));

            }

            cipherText[i]=currentCipherLetter;
        }

        printf("ciphertext: %s\n", cipherText);
        status = 0; // No Error
    }
    else
    {
        printf("Usage: ./caesar key\n");
        status = 1; // Signifies Error
    }

    return status;
}