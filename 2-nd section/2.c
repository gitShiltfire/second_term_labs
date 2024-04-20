#include <stdio.h>
#include <math.h>
int main() {
    int number = 90800706, i;
    double s = 0;
    //сначала уберём все нули с конца
    while (number % 10 == 0)
    {
        number = number / 10;
    }
    //теперь инвертируем, проверяя на нули
    while (number != 0)
    {
        i = 0;
        while (number % 10 == 0)
        {
            ++i;
            number = number / 10;
            //s = s * 10;
        }
        s = s * pow(10 , i);
        s = (s + (number % 10)) * 10;
        number = number / 10;
    }
    s = s / 10;
    printf("%d", s);
    return 0;
}