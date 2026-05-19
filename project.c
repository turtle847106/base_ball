#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int duplicate(int arr[]) // 숫자가 중복이 되었는지 검사하는 함수
{
    int check[10] = { 0 }; // 0~9
    int i;

    for (i = 0; i < 4; i++)
    {
        if (check[arr[i]] == 1)
        {
            return 1; //중복 존재 함수 종료 후 1로 변환
        }

        check[arr[i]] = 1; // 현재 숫자가 이미 사용이 되었는지 확인
    }

    return 0;
}

int main(void)
{
    int answer[4], guess[4];
    int check[10] = { 0 };
    int i, j, strike, ball;
    int life = 8, count = 0;
    char input[5];

    srand(time(NULL));

    for (i = 0; i < 4;)
    {
        int num = rand() % 10;

        if (check[num] == 0) //사용 안 된 숫자 저장
        {
            check[num] = 1; // 숫자가 사용되어 
            answer[i] = num; //num에 저장함
            i++; // for문 안에 있으면 중복이 있어도 다음 칸으로 이동
        }
    }

    printf("=== 숫자 야구 게임 ===\n");

    while (life > 0)
    {
        strike = 0;
        ball = 0;

        printf("\n숫자 입력 : ");
        scanf_s("%4s", input, (unsigned)_countof(input)); // 숫자 4개만 입력 받음, input에 배열크기를 알려줌

        for (i = 0; i < 4; i++)
        {
            if (input[i] < '0' || input[i] > '9')// 아스키코드 0(48)~9(58) 이외에 잘못된 입력값
            {
                break;
            }

            guess[i] = input[i] - '0'; // 아스키코드 0=48, 3=51 -> 51-48=3
        }

        if (i != 4 || duplicate(guess))
        {
            printf("잘못된 입력입니다.\n");
            continue;
        }

        count++;

        for (i = 0; i < 4; i++) //strike or ball 검사
        {
            for (j = 0; j < 4; j++)
            {
                if (answer[i] == guess[j])
                {
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        if (strike == 4)
        {
            printf("정답입니다!\n");
            printf("시도 횟수 : %d번\n", count);
            break;
        }

        if (ball == 0 && strike == 0)
        {
            printf("Out\n"); // 입력한 숫자가 하나라도 존재 X
        }
        else
        {
            if (ball > 0) //strike or ball count
            {
                printf("%d Ball ", ball);
            }

            if (strike > 0)
            {
                printf("%d Strike", strike);
            }

            printf("\n");
        }

        life--;
        printf("남은 목숨 : %d\n", life);
    }

    if (life == 0)
    {
        printf("\n게임 오버!\n정답 : "); //게임오버 시 정답 도출

        for (i = 0; i < 4; i++)
        {
            printf("%d", answer[i]);
        }
    }

    return 0;
}