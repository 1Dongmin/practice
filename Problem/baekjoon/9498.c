#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a>=90)
        printf("A");
    else if(80<=a||89<=a)
        printf("B");
    else if(70<=a||79<=a)
        printf("C");
    else if(60<=a||69<=a)
        printf("D");
    else
        printf("F");
}
