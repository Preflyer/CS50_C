#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Number: \n");
    long long cc = get_long_long();
    printf("bool is %lu\n", sizeof(bool));
    printf("char is %lu\n", sizeof(char));
    printf("double is %lu\n", sizeof(double));
    printf("float is %lu\n", sizeof(float));
    printf("int is %lu\n", sizeof(int));
    printf("long long is %lu\n", sizeof(long long));
    printf("string is %lu\n", sizeof(string));
    printf("cc is %lu\n", sizeof(cc));
}
