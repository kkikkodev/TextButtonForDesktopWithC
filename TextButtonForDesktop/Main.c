#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TextButton.h"
#include "Util.h"

int main(int argc, char* argv[]){
	TextButton textButton = { 0, };
	char text[TEXT_SIZE] = { '\0', };
	int startPositionXToPrint;
	int startPositionYToPrint;
	printf("버튼 문자열 출력 시작 위치 입력 (x, y)\n콘솔 창 크기 벗어나지 않도록 주의 : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("버튼 문자열 입력 : ");
	fgets(text, TEXT_SIZE, stdin);
	text[strlen(text) - 1] = '\0';
	system("cls");
	TextButton_Create(&textButton, text, startPositionXToPrint, startPositionYToPrint);
	TextButton_Print(&textButton, WHITE);
	printf("\n\n누른 버튼 문자열 내용 : %s\n", TextButton_ProcessKey(&textButton));
	return 0;
}