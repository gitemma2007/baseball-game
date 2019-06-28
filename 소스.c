#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SetNum(int*);
void SelectNum(int*);
void Result(int*, int*, int*, int*);

int main()
{
	printf("Start Game!\n");

	int strike = 0, ball = 0, guessNum =0;
	int comNum[3];
	int myNum[3];
	
	SetNum(comNum);
	printf("%d %d %d\n", comNum[0], comNum[1], comNum[2]);
	while (strike != 3) {
		strike = 0; ball = 0;
		SelectNum(myNum);
		printf("%d -result : ", ++guessNum);
		Result(comNum, myNum, &strike, &ball);
	}
	printf("\nGame Over!\n");
	return 0;
}

void SetNum(int*comNum)
{
	int random[10];

	srand((int)time(NULL));

	for (int i = 0; i < 3; i++) {
		again:;
		comNum[i] = rand() % 10;
		for (int j = 0; j < i; j++)
			if (comNum[i] == random[j])
				goto again;
		random[i] = comNum[i];
	}	
}
void SelectNum(int*myNum)
{
	printf("select 3 numbers: ");
	for (int i = 0; i < 3; i++)
		scanf_s("%d", myNum + i);
}

void Result(int* comNum, int* myNum, int*strike, int*ball)
{
	for (int i = 0; i < 3; i++) {
		if (comNum[i] == myNum[i])
			(*strike)++;
		else
			for (int j = 0; j < 3; j++)
				if (myNum[i] == comNum[j])
					(*ball)++;
	}
	printf("%dstrike, %dball!!\n", *strike, *ball);

}