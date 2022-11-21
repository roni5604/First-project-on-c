#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int length(int num){
    if (num == 0)
    {
        return 1;
    }
    int numOfDigits = 0;
    while (num != 0)
    {
        numOfDigits++;
        num /= 10;
    }
    return numOfDigits;
}

int isPalindrome(int num)
{
    int demo = num;
    int numOfDigits = length(num);
    int reverse = 0;
    for (int i = 0; i < numOfDigits; i++)
    {
        reverse = (reverse * 10) + (demo % 10);
        demo /= 10;
    }
    if (reverse == num)
    {
        return 1;
    }
    return 0;
}

int isArmstrong(int num)
{
    double sum = 0, demo = num;
    double numOfDigits = length(num);
    for (int i = 0; i < numOfDigits; i++)
    {
        sum += pow(((int)demo % 10), numOfDigits);
        demo /= 10;
    }
    if (sum == num)
    {
        return 1;
    }
    return 0;
}