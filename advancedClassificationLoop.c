#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int num)
{
    int temp = num;
    int word = 0;
    while (temp > 0)
    {
        word *= 10;
        word += temp % 10;
        temp /= 10;
    }
    if (word == num){
        return 1;
    }
    else
        return 0;
}

int isArmstrong(int num)
{
    int save = num;
    int counter = 0;
    while (num != 0)
    {
        counter++;
        num /= 10;
    }
    num = save;
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sum += pow(digit, counter);
        num /= 10;
    }
    if (save == sum)
    {
        return 1;
    }
    return 0;
}