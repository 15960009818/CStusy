//
// Created by 1 on 2024/4/23.
//

#include "CTools.h"
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

void input_check(int inputType,int maxlen,int mode,char arr[]){
    int i = 0;
    char ch;

    while (i < maxlen) {
        ch = getch();

        // 根据输入类型验证字符
        if (inputType == 1) {
            if (!isdigit(ch)) {
                printf("请输入数字。\n");
                continue;
            }
        } else if (inputType == 2) {
            if (!isalpha(ch)) {
                printf("请输入字母。\n");
                continue;
            }
        } else if (inputType == 3) {
            if (!isalnum(ch)) {
                printf("请输入数字或字母。\n");
                continue;
            }
        }

        // 根据显示模式处理字符
        if (mode == 0) {
            arr[i] = '*'; // 密文模式
        } else {
            arr[i] = ch; // 明文模式
        }

        i++;
    }

    arr[i] = '\0'; // 添加字符串结束符
}


//void paintTbale(int x,int y,int row,int col,int col_width);
int getkey(){
    int key = getch();  // 获取键盘输入的字符

    switch (key) {
        case KEY_UP:
            return KEY_UP;
        case KEY_DOWN:
            return KEY_DOWN;
        case KEY_LEFT:
            return KEY_LEFT;
        case KEY_RIGHT:
            return KEY_RIGHT;
        case KEY_ENTER:
            return KEY_ENTER;
        case KEY_ESC:
            return KEY_ESC;
        default:
            return (int)key; // 默认返回ASCII值
    }
}
