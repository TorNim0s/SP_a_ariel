#include <stdio.h>
#include "NumClass.h"

int isPalindrome(int num)
{
    int temp = num;
    char word;
    while (temp > 0)
    {
        word += temp % 10;
        temp = temp / 10;
    }
    if (word == num)
        return 1;
    else
        return 0;
}

int isArmstrong(int num)
{
    int temp = num, counter = 0;
    while (temp > 0)
    {
        counter++;
        temp = temp / 10;
    }
    temp = num;
    int sum = 0;
    while (temp > 0)
    {
        int a = temp % 10;
        sum += pow(a, counter);
        temp = temp / 10;
    }
    if (sum == num)
        return 1;
    else
        return 0;
}