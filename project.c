#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int duplicate(int arr[]) // 숫자 중복 검사 함수
{
    int check[10] = { 0 };
    int i;

    for (i = 0; i < 4; i++)
    {
        if (check[arr[i]] == 1)
        {
            return 1; // 중복 존재
        }

        check[arr[i]] = 1;
    }

    return 0; // 중복 없음
}

// 정답 생성 함수
void make_answer(int answer[])
{
    int check[10] = { 0 };
    int i = 0;
    int num;

    while (i < 4) 
    {
        num = rand() % 10; // 0~9 랜덤 숫자 생성

        if (check[num] == 0) // 아직 사용 안 한 숫자라면
        {
            check[num] = 1;

            answer[i] = num;// 정답 저장

            i++; // 다음 위치 이동
        }
       
    }
}

// 입력값 검사 함수
int invalid_input(char input[])
{
    int i;

    for (i = 0; i < 4; i++)
    {
        // 숫자 이외 잘못된 입력
        if (input[i] < '0' || input[i] > '9')
        {
            return 0;
        }
    }

    return 1; // 정상 입력
}

int main(void)
{
    int answer[4], guess[4];
    int i, j, strike, ball;
    int life = 3, count = 0;
    char input[5];

    srand(time(NULL));

    // 정답 생성 함수 호출
    make_answer(answer);
  
    printf("=== 숫자 야구 게임 ===\n");
    printf("=== 숫자 4개를 입력하여 정답을 맞추시오 ===\n");

    while (life > 0)
    {
        strike = 0;
        ball = 0;
        

        printf("\n숫자 입력 : ");
        scanf_s("%4s", input, (unsigned)_countof(input));

        // 입력 검사 함수 호출
        if (!invalid_input(input))
        {
            printf("잘못된 입력입니다.\n");
            continue;
        }

        // 문자열을 숫자 변환
        for (i = 0; i < 4; i++)
        {
            guess[i] = input[i] - '0'; // 아스키코드 이용한 뺄셈
        }

        // 중복 검사
        if (duplicate(guess))
        {
            printf("중복된 숫자가 있습니다.\n");
            continue;
        }

        count++;

        // strike, ball 계산
        int check[10] = { 0 };

        for (i = 0; i < 4; i++)
        {
            check[answer[i]] = 1;
        }

        strike = 0;
        ball = 0;

        for (i = 0; i < 4; i++)
        {
            if (check[guess[i]] == 1)
            {
                if (answer[i] == guess[i])
                    strike++;
                else
                    ball++;
            }
        }

        // 정답 확인
        if (strike == 4)
        {
            printf("정답입니다!\n");
            printf("시도 횟수 : %d번\n", count);
            break;
        }

        // 결과 출력
        else if (ball == 0 && strike == 0)
        {
            printf("Out\n");
        }
        else
        {
            if (ball > 0)
            {
                printf("%dBall ", ball);
            }

            if (strike > 0)
            {
                printf("%dStrike", strike);
            }

            printf("\n");
        }

        life--;

        printf("남은 목숨 : %d\n", life);
    }

    // 게임 오버
    if (life == 0)
    {
        printf("\n게임 오버!\n정답 : ");

        for (i = 0; i < 4; i++)
        {
            printf("%d", answer[i]);
        }
    }
    printf("\n");
    return 0;
}