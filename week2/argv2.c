#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // iterate over strings in argv
    for (int i = 0; i < argc; i++)
    {
        //iterate over characters in current string
        // , between j and n.  I've used a semicolon and thats 
        // wrong for obious reasons
        for (int j = 0, n = strlen(argv[i]); j<n; j++)
        {
            printf("%c\n", argv[i][j]);
        }
    }
    
}

