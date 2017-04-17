#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


// implement a program that encrypts messages using Caesar's cipher 
int main(int argc, string argv[])
{
    // Throw error if not 1 argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else
    {
        // request plain text
        printf("plaintext: ");
        string plaintext = get_string();
        int k = atoi(argv[1]);
        // reduce k by 26 until betweek 0-26
        if (k > 26)
        {
            do
            {
                k -= 26;
            }
            while (k > 26);
        }
        
        int n = strlen(plaintext);
        string ciphertext = plaintext;
        // iterate over each character leaving non-alphabets unchanged
        for (int i = 0; i < n; i++)
        {
            // cipher uppercase
            if (plaintext[i] >= 65 && plaintext[i] <= 90)
            {
                if (plaintext[i] + k > 90)
                {
                    ciphertext[i] = plaintext[i] + k - 26;
                    
                }
                else 
                {
                    ciphertext[i] = plaintext[i] + k;
                }
            }
            // cipher lowercase
            else if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
                if (plaintext[i] + k > 122)
                {
                    ciphertext[i] = plaintext[i] + k -26;
                }
                else
                {
                    ciphertext[i] = plaintext[i] +k;
                }
            }
            // non-alphabets
            else
            {
                // do nothing
            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    return 0;
}
    
    
    