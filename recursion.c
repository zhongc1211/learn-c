#include <stdio.h>

unsigned int factorial(unsigned int x)
{
    if (x == 0)
    {
        /* Terminating case */
        return 1;
    }
    else if (x > 0)
    {
        /* Recursive step */
        return x * factorial(x-1);
    }

    /* Catch scenario when x is zero */
    return 0;
}


int main() {
    /* testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */