#include <stdio.h>
int main(){
    long a, b, c;
    double times;
    scanf("%ld\n%ld\n%ld", &a, &b, &c, 4);

    if(b >= c){
        printf("-1");
        return 0;
    }
    times = a / (c - b) * 1.0;
    printf("%.0f", times + 1);
    return 0;
}
