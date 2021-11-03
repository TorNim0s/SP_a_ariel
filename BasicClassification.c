#include <stdio.h>
#include <math.h>
#include "NumClass.h"
int factorial(int);

int isPrime(int num)
{
    if (num < 1)
        return 0;
    if (num == 1)
        return 1;
    for (int i = 2; i <= sqrt(num); i++)
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
    int save = num;
    int sum = 0;
    while (num > 0)
    {
        sum = sum + factorial(num % 10);
        num /= 10;
    }
    if (sum == save)
    {
        return 1;
    }
    return 0;
}

int factorial(int num)
{
    if (num < 0){
        return 0;
    }
    if (num == 0)
        return 1;
    return factorial(num - 1) * num;
}