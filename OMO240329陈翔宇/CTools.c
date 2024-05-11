#include<stdio.h>
void gotoxy(int x, int y) {
    HANDLE hOut;
    COORD pos = {x, y};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void paintWindow(int startX,int startY, int width,int height){
	// ªÊ÷∆…œ±ﬂøÚ
    for (int i = 0; i < width; i++)
        printf("=");
    printf("\n");

    // ªÊ÷∆◊Û”“±ﬂøÚº∞ø’∞◊«¯”Ú
    for (int i = 0; i < height; i++) {
        printf("|");
        for (int j = 0; j < width - 2; j++)
            printf(" ");
        printf("|\n");
    }

    // ªÊ÷∆œ¬±ﬂøÚ
    for (int i = 0; i < width; i++)
        printf("=");
    printf("\n");
}