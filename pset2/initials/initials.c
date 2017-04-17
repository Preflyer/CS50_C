#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    // ask for name and save the whole name as one string

    string name = get_string();
    int n = strlen(name);
    
    // iterate through each character concat to name array replacing spaces with \0
    for (int i = 0; i < n; i++)
    {
        // check if non-space character and uppercase
        if (name[i] >= 41 && name[i] <= 90)
        {
            // check if previous character was space or NUL and print if TRUE
            if (name[i-1] == 32 || name[i-1] == '\0')
            {
                printf("%c", name[i]);
            }
            else 
            {
                // do nothing
            }
        }
        // check if non-space character and lowercase
        if (name[i] >= 97 && name[i] <= 122)
        {
            // check if previous character was space or Nul, turn to 
            // capital and print if TRUE
            if (name[i-1] == 32 || name[i-1] == '\0')
            {

                printf("%c", name[i]-32);

            }
            else
            {
                // do nothing
            }
        }
        else
        {
            // do nothing
        }
    }
    printf("\n");
}
 



