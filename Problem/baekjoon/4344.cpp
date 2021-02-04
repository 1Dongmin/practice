#include <stdio.h>
int main(){
    int rep, times, score[100], sum = 0, winner = 0;
    double avr;
    scanf("%d", &rep);
    for(int i = 0; i < rep; i++){
        scanf("%d", &times);
        for(int k = 0; k < times; k++){
            scanf("%d", &score[k]);
            sum += score[k];
        }
        avr = ((sum * 1.0) / (times * 1.0));
        for(int t = 0; t < times; t++){
            if(avr < score[t]) winner++;
        }
        printf("%lf%%\n", (winner * 1.0) / (times * 1.0) * 100.0);
        sum = 0, winner = 0, avr = 0;
    }
    for(int i = 0; i < times; i++){
        avr = (sum / times) * 1.0;
    }
}
