/*
    There are three types of "edits" that can be performed: insert, remove, replace.
    Each is performed on a single character of the string. Write a function to check
    if two input strings are one edit (or zero) away
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

#define MIN(x, y) ((x > y) ? x : y)

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("ERROR: Requires two input strings\n");
        return 0;
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);
    int minLen = MIN(len1, len2);
    int edits = 0;


    // Check for too many insert/remove
    if (abs(len1 - len2) > 1)
    {
        printf("string lengths differ by >1\n");
        return 0;
    }

    int i = 0, j = 0; // pointers to strings 1, 2 characters
    int k;

    // Scan strings and tally edits
    for (k = 0; k < minLen; k++)
    {

        // DEBUG
//        printf("Comparing %c, %c. #edits = %d\n", argv[1][i], argv[2][j], edits);

        // parse mismatch
        if (argv[1][i] != argv[2][j])
        {
            edits++;

            // Check for "replace", increment both iterators
            if (argv[1][i+1] == argv[2][j+1])
            {
                i++;
                j++;
            }
            // Check for str1 "remove" AKA str2 "insert", increment i
            else if (argv[1][i+1] == argv[2][j])
                i++;
            // Check for str1 "insert" AKA str2 "remove", increment j
            else if(argv[1][i] == argv[2][j+1])
                j++;
            else
            {
                printf("too many edits\n");
                return 0;
            }
        }
        else
        {
            i++;
            j++;
        }

        // Check edit count
        if (edits > 1)
        {
            printf("too many edits\n");
            return 0;
        }
    }

    printf("One Away!\n");
    return 1;
}
