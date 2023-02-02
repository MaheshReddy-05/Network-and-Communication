#include <stdio.h>
int i, j, datalen, divlen, length, flag = 1;
char data[20], div[20], temp[5], total[50];
void check();
int main()
{
    printf("Enter total length of data: ");
    scanf("%d", &datalen);
    printf("Enter total length of divisor: ");
    scanf("%d", &divlen);
    length = datalen + divlen - 1;
    printf("Enter data: ");
    scanf("%s", &data);
    printf("Enter divisor: ");
    scanf("%s", div);
    for (i = 0; i < datalen; i++)
    {
        total[i] = data[i];
        temp[i] = data[i];
    }
    for (i = datalen; i < length; i++)
        total[i] = '0';
    check();
    for (i = 0; i < divlen; i++)
        temp[i + datalen] = data[i];
    printf("\nThe transmitted code word:%s", temp);
    printf("\n\nEnter the received code word:");
    scanf("%s", total);
    check();
    for (i = 0; i < divlen - 1; i++)
    {
        if (data[i] == '1')
        {
            flag = 0;
            break;
        }
        if (flag == 1)
            printf("\nResult: Correct tranmission\n");
        else
            printf("\nResult: Incorrect tranmission\n");
    }
}
void check()
{
    for (j = 0; j < divlen; j++)
        data[j] = total[j];
    while (j <= length)
    {
        if (data[0] == '1')
            for (i = 1; i < divlen; i++)
                data[i] = ((data[i] == div[i]) ? '0' : '1');
        for (i = 0; i < divlen - 1; i++)
            data[i] = data[i + 1];
        data[i] = total[j++];
    }
}