#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "TextButton.h"
#include "Util.h"

enum KeyCode{
	ENTER = 13 
};

enum Boolean{
	False, True
};

void TextButton_Create(TextButton* textButton, char* text, int startPositionXToPrint, int startPositionYToPrint){
	TextItem_Create(&textButton->text, text);
	textButton->width = TextItem_GetTotalByte(textButton->text);
	textButton->height = 1;
	textButton->startPositionToPrint.x = startPositionXToPrint;
	textButton->startPositionToPrint.y = startPositionYToPrint;
}

void TextButton_Print(TextButton* textButton, int color){
	int i;
	int j;
	Point startPositionToPrint = textButton->startPositionToPrint;
	textButton->width = textButton->width % 2 == 1 ? textButton->width + 1 : textButton->width;
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	FontUtil_ChangeFontColor(WHITE);
	printf("旨");
	for (i = 0; i < textButton->width / 2; i++){
		printf("收");
	}
	printf("旬");
	for (i = 0; i < textButton->height; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
		FontUtil_ChangeFontColor(WHITE);
		printf("早");
		FontUtil_ChangeFontColor(color);
		printf("%s", TextItem_GetText(&textButton->text));
		for (j = 0; j < textButton->width - TextItem_GetTotalByte(textButton->text); j++){
			printf(" ");
		}
		FontUtil_ChangeFontColor(WHITE);
		printf("早");
	}
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	printf("曲");
	for (i = 0; i < textButton->width / 2; i++){
		printf("收");
	}
	printf("旭");
}

const char* TextButton_ProcessKey(TextButton* textButton){
	while (True){
		if (_kbhit()){
			int key = _getch();
			if (key == ENTER){
				break;
			}
		}
	}
	TextButton_Print(textButton, WHITE_INVERSION);
	Sleep(100); // button click effect time
	TextButton_Print(textButton, WHITE);
	return TextItem_GetText(&textButton->text);
}
