#include <stdio.h>
int main(){
    int time, stack = 0, sum = 0;
    char oxox[80], O = 'O', X = 'X';
    scanf("%d", &time);
    for(int i = 0; i < time; i++){
        scanf("%s", &oxox);
        for(int k = 0; oxox[k] != NULL; k++){
            if(oxox[k] == 'O'){
                stack++;
                sum += stack;
            }
            if(oxox[k] == 'X'){
                stack = 0;
            }
        }
        printf("%d\n", sum);
        sum = 0;
        stack = 0;
    }
}
