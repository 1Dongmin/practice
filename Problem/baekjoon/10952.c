#include <stdio.h>
int main()
{
    int a, b;
    back:
    scanf("%d %d", &a, &b);
    if(a == 0 && b == 0)
        return 0;
    if(a != 0 || b != 0){
        printf("%d\n", a + b);
        goto back;
    }
}
