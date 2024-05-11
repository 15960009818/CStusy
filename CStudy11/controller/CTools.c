//
// Created by 1 on 2024/4/23.
//

#include "../controller/CTools.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "CLogin.h"
void gotoxy(int x,int y){
        HANDLE hOut;
        COORD pos= {x,y};
// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}

void paintWindow(int startX, int startY, int width, int height) {
     int x, y;

    // 绘制顶部边框
	gotoxy(startX,startY);
    printf("┌");
    for (x = 0; x < width - 2; x++) {
        printf("─");
    }
    printf("┐\n");
	
    // 绘制侧边边框
    for (y = startY + 1; y < startY + height - 1; y++) {
		gotoxy(startX,y);
        printf("│");
        for (x = 0; x < width - 2; x++) {
            printf(" ");
        }
        printf("│\n");
    }
	gotoxy(startX,y);
    // 绘制底部边框
    printf("└");
    for (x = startX + 1; x < startX + width - 1; x++) {
		
        printf("─");
    }
    printf("┘\n");
}


void input_check(int inputType, int maxlen, int mode, char arr[]) {
    int i = 0;
    char ch;

    while ((ch = getch()) != '\r' && i < maxlen) { // 循环获取字符，直到用户输入回车或达到最大长度
        // 根据输入类型验证字符
        if (inputType == 1) {
            if (!isdigit(ch)) {
                printf("请输入数字。\n");
                return;
            }
        } else if (inputType == 2) {
            if (!isalpha(ch)) {
                printf("请输入字母。\n");
                return;
            }
        } else if (inputType == 3) {
            if (!isalnum(ch)) {
                printf("请输入数字或字母。\n");
                return;
            }
        }

        // 根据显示模式处理字符
        if (mode == 0) {
            arr[i] = '*'; // 密文模式
        } else {
            arr[i] = ch; // 明文模式
        }

        putchar(arr[i]); // 打印明文或密文字符
        i++;
    }

    arr[i] = '\0'; // 添加字符串结束符
}


//void paintTbale(int x,int y,int row,int col,int col_width);
int getkey() {
    int key = getch();  // 获取键盘输入的字符

    // 如果第一个字符是方向键码，读取下一个字符
    if (key == 224 || key == -32) {
        key = getch(); // 读取下一个字符
        switch (key) {
            case 72: // 上
                return KEY_UP;
            case 80: // 下
                return KEY_DOWN;
            case 75: // 左
                return KEY_LEFT;
            case 77: // 右
                return KEY_RIGHT;
        }
    } else if (key == 13 || key == 27) {
        switch (key) {
            case 13:
                return KEY_ENTER;
            case 27:
                return KEY_ESC;
        }
    }
    return 0;
}

// 绘制表格
void paintTable(int x, int y, int row, int col, int col_width) {
    int i = 0;
	int j = 0;
	int k = 0;

    // 绘制表头
    gotoxy(x, y);
    printf("┌");
    for (i = 0; i < col - 1; i++) {
        for (j = 0; j < col_width; j++) printf("─");
        printf("┬");
    }
    for (j = 0; j < col_width; j++) printf("─");
    printf("┐\n");

    // 绘制分隔线
    for (i = 0; i < row - 1; i++) {
        gotoxy(x, y + i * 2 + 1);
        printf("├");
        for (j = 0; j < col - 1; j++) {
            for (k = 0; k < col_width; k++) printf("─");
            printf("┼");
        }
        for (k = 0; k < col_width; k++) printf("─");
        printf("┤\n");
    }

    // 绘制表尾
    gotoxy(x, y + (row - 1) * 2 + 1);
    printf("└");
    for (i = 0; i < col - 1; i++) {
        for (j = 0; j < col_width; j++) printf("─");
        printf("┴");
    }
    for (j = 0; j < col_width; j++) printf("─");
    printf("┘\n");
}