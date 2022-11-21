#include <stdio.h>
#include <math.h>
#include "NumClass.h"


int main(){
    int start, end;
    printf("Enter start and end range (with space between them): ");
    scanf("%d %d", &start, &end);

    printf("The Armstrong numbers are: ");
    for (int i = start; i <= end; i++)
    {
        if (isArmstrong(i)){
            printf("%d ", i);
        }
    }
    
    printf("\nThe Palindrome numbers are: ");
    for (int i = start; i <= end; i++)
    {
        if (isPalindrome(i)){
            printf("%d ", i);
        }
    }
    
    printf("\nThe Prime numbers are: ");
    for (int i = start; i <= end; i++)
    {
        if (isPrime(i)){
            printf("%d ", i);
        }
    }
    
    printf("\nThe Strong numbers are: ");
    for (int i = start; i <= end; i++)
    {
        if (isStrong(i)){
            printf("%d ", i);
        }
    }
    printf("\n Done ");
    return 0;
}