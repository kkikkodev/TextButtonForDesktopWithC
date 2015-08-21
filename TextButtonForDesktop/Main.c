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
	printf("��ư ���ڿ� ��� ���� ��ġ �Է� (x, y)\n�ܼ� â ũ�� ����� �ʵ��� ���� : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("��ư ���ڿ� �Է� : ");
	fgets(text, TEXT_SIZE, stdin);
	text[strlen(text) - 1] = '\0';
	system("cls");
	TextButton_Create(&textButton, text, startPositionXToPrint, startPositionYToPrint);
	TextButton_Print(&textButton, WHITE);
	printf("\n\n���� ��ư ���ڿ� ���� : %s\n", TextButton_ProcessKey(&textButton));
	return 0;
}