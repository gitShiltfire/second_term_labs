#include <stdio.h>
#include <math.h>
double absolute(double n)
{
    if (n < 0.0)
    {
        n = n * (-1.0);
    }
    return n;
}
int main()
{
    double x, eps, sum = 0.0;
    int n = 0;
    scanf("%lf", &x);
    scanf("%lf", &eps);
    do 
    {
        sum = sum + ( ( pow(-1.0, n) * pow(x, ((2.0*n) + 1)) ) / ( (2*n) + 1 ) );
        n = n + 1;    
        printf("%lf %c", sum, '\n');
    } while (absolute( ( ( pow(-1, n) * pow(x, ( (2*n) + 1) ) ) / ( (2*n) + 1) ) ) > eps);
    printf("%.5lf", sum);
    return 0;
}
