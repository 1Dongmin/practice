#include <stdio.h>

int main(void)
{
    int up1, down1, hight, days = 0;
    scanf("%d %d %d", &up1, &down1, &hight);

    days = (hight - down1 - 1) / (up1 - down1) + 1;
    //정상에서는 미끄러지지 않으므로 정상 - 미끄러지는 높이만큼만 올라가면 됨
    //정상 - 미끄러지는 높이 = 올라가야 할 높이
    //올라가야 할 높이 / 하루에 올라가는 높이 = 걸리는 일 수
    //걸리는 일 수가 소수점 없이 딱 나누어 떨어지면 -1일
    //만약 소수점으로 더럽게 나누어 떨어지면 그대로
    //그래서 그냥 올라가야 할 높이에 -1을 하고
    //대신 몫을 +1을 함
    printf("%d", days);
    return 0;
}
