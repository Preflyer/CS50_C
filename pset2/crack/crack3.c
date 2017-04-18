#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _XOPEN_SOURCE
#include <crypt.h>


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
        char salt[3];
        salt[0] = '5';
        salt[1] = '0';
        salt[2]= '\0';
        char key[5];
        key[0] = '\0';
        key[1] = '\0';
        key[2] = '\0';
        key[3] = '\0';
        key[4] = '\0';
        char post_hash[14];
        char alphabet_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        alphabet_set[52] = '\0';
        for (int i = 0; i <= 52; i++)
        {
            for (int j = 0; j <= 52; j++)
            {
                for (int k = 0; k <= 52; k++)
                {
                    for (int l = 0; l <= 52; l++)
                    {
                        key[0] = alphabet_set[i];
                        key[1] = alphabet_set[j];
                        key[2] = alphabet_set[k];
                        key[3] = alphabet_set[l];
                        
                        strcpy(post_hash, crypt(key, salt));
                        
                        if (strcmp(post_hash, hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                        
                    }
                }
            }
        }
    }
     
}
// ./crack3 503RHmlyy2lZE                 C
// ./crack3 50fkUxYHbnXGw                 rofl
// ./crack3 50.jPgLzVirkc                 ji
// ./crack3 50YHuxoCN9Jkc                 JH
// ./crack3 50QvlJWn2qJGE                 NOPE
// ./crack3 50CPlMDLT06yY                 ha
// ./crack3 50WUNAFdX/yjA                 Yale
// ./crack3 50fkUxYHbnXGw                 rofl
// ./crack3 50C6B0oz0HWzo                 FTW
// ./crack3 50nq4RV/NVU0I                 ABC
// ./crack3 50vtwu4ujL.Dk                 haha
// ./crack3 50i2t3sOSAZtk                 lol
