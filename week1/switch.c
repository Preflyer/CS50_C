#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* local variable definition */
    printf("Provide y/n: ");
    char c = get_char();
    
    switch(c)
    {
        case 'y':
        case 'Y':
            printf("yes\n");
            break;
            
        case 'n':
        case 'N':
            printf("no\n");
            break;
            
        default:
            printf("error\n");
        
    }
}