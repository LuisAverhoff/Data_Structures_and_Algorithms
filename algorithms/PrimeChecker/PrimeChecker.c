#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main()
{
    int num;

    printf("Enter a number and I'll check if it is a prime number. ");
    scanf(" %d", &num);

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

int isPrime(int num)
{
    int i;

    /*
      We only have to go up to the square root of n because once we past the square root of n,
      all the cofactors of n will repeat. That is why it is efficient to go up to square root of n
      because if we have not found an a and b, where a and b are other positive numbers besides 1 and n,
      then by the time we reach square root of n, it is guaranteed that we will never find a and b.
      Take 36 for example, our cofactors are {1, 36}, {2, 18}, {3, 12}, {4. 9}, {6, 6}, {9, 4}, {12, 3}, {18, 2}, {36, 1}.
      Notice how after {6, 6} all of our factors started to repeat. This is why we don't go past the square of
      n(or 6 in this case).
    */
    for(i = 2; i < sqrt(num); i++)
    {
       if((num % i) == 0)
       {
           return 0;
       }
    }

    return 1;
}
