#include <stdio.h>
int parity_check();
void main()
{
    unsigned int num ;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Given number is %s parity", (parity_check(num) ? "odd" : "even"));
}
int parity_check(unsigned int n)
{
    int parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }
    return parity;
}