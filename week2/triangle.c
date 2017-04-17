#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    printf("Enter triangel length a: \n");
    int a = get_int();
    printf("Enter triangel length b: \n");
    int b = get_int();
    printf("Enter triangel length c: \n");
    int c = get_int();
    
    
    if (valid_triangle(a, b, c))
    {
        printf("This is a triangle\n");
    }
    else
    {
        printf("This is NOT a triangle\n");
    }
    
    
}



bool valid_triangle(int a, int b, int c)
{

    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if (a + b <= c || b + c <= a || c + a <= b)
    {
        return false;
    }
        
    return true;

    
}
