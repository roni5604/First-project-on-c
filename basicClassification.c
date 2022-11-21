#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int isStrong(int num)
{
    int sum=0 , demo = num , factorial , temp;
    while (demo > 0)
    {
        factorial = 1;
        temp = demo % 10;
        for (int i = 1; i <= temp; i++)
        {
            factorial *= i;
        }
        sum =sum+ factorial;
        demo /= 10;
    }
    if (sum == num)
    {
        return 1;
    }
    return 0;
}