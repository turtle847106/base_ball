#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int answer[4];
    int guess[4];
    int i, j;
    int count = 0;

    srand(time(NULL));

    // 정답 난수 생성
    i = 0;
    int check[10] = { 0 };


    i = 0;
    while (i < 4)
    {
        int num = rand() % 9 + 1;

        if (check[num] == 1)
        {
            continue;
        }
        else
        {
            check[num] = 1;
            answer[i] = num;
            i++;
        }
    }

    printf("=== 숫자 야구 게임 ===\n");
    printf("1부터 9까지 서로 다른 숫자 4개를 입력하세요.\n");

    while (1)
    {
        int input;
        int There_is = 0;
        int Seat = 0;

        printf("\n숫자 입력: ");
        scanf_s("%d", &input);

        // 예: input이 1234이면
        // guess[0] = 1
        // guess[1] = 2
        // guess[2] = 3
        // guess[3] = 4
        guess[0] = input / 1000;
        guess[1] = (input / 100) % 10;
        guess[2] = (input / 10) % 10;
        guess[3] = input % 10;

        int reinput = 0;

        for (i = 0; i < 4; i++)
        {
            for (j = i + 1; j < 4; j++)
            {
                if (guess[i] == guess[j])
                {
                    reinput = 1;
                }
            }
        }

        if (reinput == 1)
        {
            printf("중복된 숫자 발견! 다시 입력하세요.\n");
            continue;
        }


        count++;

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (answer[i] == guess[j])
                {
                    There_is++;

                    if (i == j)
                    {
                        Seat++;
                    }
                }
            }
        }

        printf("숫자 %d개 맞음, 자리 %d개 맞음\n", There_is, Seat);

        if (Seat == 4)
        {
            printf("\n정답입니다!\n");
            printf("시도 횟수: %d번\n", count);
            break;
        }
    }

    return 0;
}
