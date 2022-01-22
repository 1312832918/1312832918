#include <stdio.h>

int main()
{
    int x = 10;
    int result = 0;
    int f = x / 100;
    printf("%d\n", f);
    int s = (x % 100) / 10;
    printf("%d\n", s);
    int t = x % 10;
    printf("%d\n", t);
    //int result = t * 100 + s * 10 + f;

    if (f == 0)
    {
        if (s == 0)
        {
            result = t;
        }
        else
        {
            result = t * 10 + s;
        }
    }
    else
    {
        result = t * 100 + s * 10 + f;
    }
    printf("%d\n", result);
}