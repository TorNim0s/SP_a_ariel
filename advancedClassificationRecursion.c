#include <stdio.h>
#include <math.h>
#include "NumClass.h"
int reverse(int,int);
int isArmstrongRec(int,int);

int isPalindrome(int num)
{
    int temp = reverse(num, 0);
    if (num == temp)
        return 1;
    else
        return 0;
}

int reverse(int num, int temp)
{
    if (num == 0)
        return temp;
    temp = (temp * 10) + (num % 10);
    return reverse(num / 10, temp);
}

int isArmstrong(int num)
{
    int sum = 0, count = 0, temp;
    temp = num;
    while (temp != 0)
    {
        count = count + 1;
        temp = temp / 10;
    }
    sum = isArmstrongRec(num, count);
    if (sum == num)
        return 1;
    else
        return 0;
}

int isArmstrongRec(int num, int count)
{
    int reminder, sum = 0;
    if (num > 0)
    {
        reminder = num % 10;
        sum = sum + pow(reminder, count);
        sum += isArmstrongRec(num / 10, count);
        return sum;
    }
    else
        return 0;
}

