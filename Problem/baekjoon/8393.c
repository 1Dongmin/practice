#include <stdio.h>
int main()
{
    unsigned int a, b, i = 1;
    scanf("%d", &a);
    b = a;
    sum:
    if (b > i){
        a = a + i;
        i++;
        goto sum;
    }
    printf("%d", a);
}
/*
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d", &a);
    b = a;
    for(int i = 1; i < a; i++)
    {
        b = b + i;
    }
    printf("%d", b);
}
*/
