#include <stdio.h>
int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){ //scanf 함수는 입력받은 인수의 개수를 리턴함.
        printf("%d\n", a + b);
    }
}
// scanf != EOF (엔드 오프 파일) 로 처리 가능하다.
// scanf != -1 상수로 처리도 가능하다.
// <iostream> 의 cin.eof() == TURE 로도 처리가 가능하다.
