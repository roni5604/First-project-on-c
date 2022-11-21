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

int reverse(int num)
{
    int numOfDigits = length(num);
    if (num == 0)
    {
        return 0;
    }
    return ((num % 10 * pow(10, numOfDigits - 1)) + reverse(num / 10));
}

int isPalindrome(int num)
{
    if ((num == reverse(num)) || (num >= 0 && num < 10))
    {
        return 1;
    }
    return 0;
}

int isArmstrongHelper(int num, int numOfDigits)
{
    if (num > 0)
    {
        return (pow((num % 10), numOfDigits) + isArmstrongHelper(num / 10, numOfDigits));
    }
    return 0;
}

int isArmstrong(int num)
{
    int numOfDigits = length(num);
    if (isArmstrongHelper(num, numOfDigits) == num)
    {
        return 1;
    }
    return 0;
}