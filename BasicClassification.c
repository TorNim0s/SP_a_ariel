#include <stdio.h>
#include "NumClass.h"

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int isStrong(int num)
{
    if (num <= 0)
        return 0;
    int temp = num, sum = 0;
    while (temp > 0)
    {
        int a = temp % 10;
        sum += factorial(a);
        temp = temp / 10;
    }
    if (sum == num)
        return 1;
    else
        return 0;
}

int factorial(int num)
{
    if (num <= 0)
        return 0;
    return factorial(num - 1) * num;
}