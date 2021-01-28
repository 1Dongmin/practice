#include <stdio.h>
int main()
{
    int a, f, s, temp, count = 0;
    scanf("%d", &a);
    f = a / 10;
    s = a % 10;
    while(1){
        temp = f + s;
        temp = temp%10;
        f = s;
        s = temp;
        count++;
	    if((f*10) + s == a)
	        break;
    }
    printf("%d", count);
}
//int 자릿수 자를 때는 10 으로 나누기
