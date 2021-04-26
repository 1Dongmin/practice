#include <stdio.h>

int main(void)
{
    int prevSpl = 0, size, isGW = 0, alp[26] = {0};
    scanf("%d", &size);

    char arr[101] = {0};
    for (int i = 0; i < size; i++){                     //size 횟수만큼 반복해서 입력받기
        scanf("%s", arr);
        
        for (int k = 0; arr[k] != 0; k++){              //단어 길이만큼 반복하기
            if (prevSpl == arr[k]){ continue; }         //만약 방금전과 같은단어면 생략
            prevSpl = arr[k];                           //지금단어 기억
            if(alp[arr[k] - 97] == 1){ goto BPZERO; }   //만약 옛날에 나왔던 단어면 스킵
            alp[arr[k] - 97] = 1;                       //arr의 k 번째 단어의 알파벳의 존재 여부를 저장함

        }
        isGW++;                                         //무사히 반복문을 마치면 그룹단어가 맞음
    BPZERO:
    ;
        prevSpl = 0;                                    //지금단어 기억 소거
        for (int b = 0; b < 26; b++){ alp[b] = 0; }      //알파벳 저장한 기억 소거
    }
    
    printf("%d", isGW);
    return 0;
}
