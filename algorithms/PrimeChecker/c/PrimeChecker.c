#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(long);

int main()
{
    long num;

    printf("Enter a number and I'll check if it is a prime number. ");
    scanf(" %ld", &num);

    printf("\n");

    /*
      We are going by the standard definition in which primes are integers greater than one with no positive divisors
      besides one and itself.
    */
    if(num > 1 && isPrime(num))
    {
      printf("This number is a prime number. \n");
    }
    else
        printf("This number is not a prime number. \n");

    return 0;
}

int isPrime(long num)
{
    int i;
    int sqrt_limiter = (int)sqrt(num) + 1;

    if(num == 2 || num == 3)
    {
        return 1;
    }
    else if(num % 2 == 0 || num % 3 == 0)
    {
        return 0;
    }

    /*
      The reason why it is efficient to go up to the square root of n is because if there isn't an a and b, such that a and b 
      are positive numbers besides 1 and n, then by the time we reach square root of n, it is guaranteed that we 
      will never find an a and b that is not 1 and n. Take 36 for example, our cofactors are {1, 36}, {2, 18}, {3, 12}, {4. 9}, {6, 6}, {9, 4}, 
      {12, 3}, {18, 2}, {36, 1}. Notice how after {6, 6} all of our factors started to repeat. This is why we don't go past 
      the square of n(or 6 in this case).

      Here we are doing an important optimization to make a trial division a little bit more efficient
      such as checking if the number is divisible by 2 or 3. This check eliminates the need to check numbers
      that have the number 2 or 3 as its prime factor. This means that only prime factors that we have to look
      out for are 5 and 7. This also means that we can simply start at 6 and add plus and minus one to check if the
      current number that we are checking is a prime factor of 5 and 7.
    */
    for(i = 6; i <= sqrt_limiter; i+=6)
    {
       if((num % (i - 1) == 0) || (num % (i + 1) == 0))
       {
           return 0;
       }
    }

    return 1;
}
