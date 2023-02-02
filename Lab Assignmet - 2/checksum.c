#include <stdio.h>
#include <string.h>
int main()
{
    char s1[10], s2[10];
    char sum[10], comp[10];
    int i, length;
    printf("Enter 1st binary sequence: ");
    scanf("%s", &s1);
    printf("Enter 2nd binary sequence: ");
    scanf("%s", &s2);
    if (strlen(s1) == strlen(s2))
    {
        length = strlen(s1);
        char carry = '0';
        for (i = length - 1; i >= 0; i--)
        {
            if (s1[i] == '0' && s2[i] == '0' && carry == '0')
            {
                sum[i] = '0';
                carry = '0';
            }
            else if (s1[i] == '0' && s2[i] == '0' && carry == '1')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (s1[i] == '0' && s2[i] == '1' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (s1[i] == '0' && s2[i] == '1' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (s1[i] == '1' && s2[i] == '0' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (s1[i] == '1' && s2[i] == '0' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (s1[i] == '1' && s2[i] == '1' && carry == '0')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (s1[i] == '1' && s2[i] == '1' && carry == '1')
            {
                sum[i] = '1';
                carry = '1';
            }
            else
                break;
        }
        printf("\nSum= %c%s", carry, sum);
        for (i = 0; i < length; i++)
        {
            if (sum[i] == '0')
                comp[i] = '1';
            else
                comp[i] = '0';
        }
        if (carry == '1')
            carry = '0';
        else
            carry = '1';
        printf("\nChecksum= %c%s\n", carry, comp);
    }
    else
    {
        printf("\nVerdict: Incorrect input strings");
    }
}