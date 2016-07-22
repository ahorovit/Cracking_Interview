/*
    Given Two Strings, write a method for checking if
    one is a permutation of the other
*/

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{

    // Check correct number arguments
    if (argc != 3)
    {
        printf("Must enter two strings to test for permutation\n"); 
        return -1;
    }

    int i, thisChar;
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);
    short tally1[128];      // Assume ASCII characters
    short tally2[128];

    /* 
        Space optimization: Count up with string one, count down with string 2.
        This way, only one tally array is needed.
    */


    // Initialize tallies to 0
    for (i = 0; i <= 127; i++)
    {
        tally1[i] = 0;
        tally2[i] = 0;
    }

    // If strings are different lengths, exit
    if (len1 != len2)
    {
        printf("Inputs are not permutations (len1 != len2)\n");
        return 0;
    }

    // If strings are identical, exit
    if (!strcmp(argv[1], argv[2]))
    {
        printf("strings are identical. Not permutations.\n");
        return 0;
    }


    // Tally characters in str1
    for (i = 0; i < strlen(argv[1]); i++)
    {
        thisChar = argv[1][i];
        tally1[thisChar]++;
    }

    // DEBUG
//    for (i = 0; i <= 127; i++)
//        printf("%c: %d\n", (char)i, tally1[i]);



    // Scan second string and check for inconsistencies
    for (i = 0; i < len2; i++)
    {
        thisChar = argv[2][i];
        tally2[thisChar]++;

        // Check if this character count exceeds that from tally1
        if (tally2[thisChar] > tally1[thisChar])
        {
            printf("Inputs != permutations. Too many %c\n", (char)thisChar);
            return 0;
        }
    }

    // If control reaches this point, strings are permutations
    printf("Inputs are permutations!\n");
    return 1;
}
