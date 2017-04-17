#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _XOPEN_SOURCE

char *crypt(char *key, char*salt);
// implement a program that cracks passwords
int main(int argc, string argv[])
{
    // return error if more or less than one argurent provided
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    // return password derived from hash
    else
    {
        char *hash = argv[1];
        char *salt = "50\0";
        char *key = "rofl\0";
        
        char *post_hash = crypt(key, salt);
        printf("hash: %s\n", hash);
        printf("post_hash: %s\n", post_hash);
        if (hash == post_hash)
        {
            printf("fuck yea\n");
        }
        else
        {
            printf("still busted\n");
        }

        
        
    }
}
