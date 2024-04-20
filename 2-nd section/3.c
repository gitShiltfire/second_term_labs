#include <stdio.h>

int is_number_prime(int number)
{
    int i = 2, count = 0;
    while (i < number)
    {
        if (number % i == 0)
            ++count;
        ++i;    
    }
    if (count == 0)
        return 1;
    else
        return 0;
}


int main ()
{
    int j = 2, number;
    scanf("%d", &number);
    while (j <= number)
    {
        if (is_number_prime(j) == 1)
        {
            printf("%d %c", j, ' ');
        }
        ++j;
    }
    return 0;
}