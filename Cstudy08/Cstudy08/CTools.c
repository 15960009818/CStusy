#include <stdio.h>
#include <conio.h>
#include "CTools.h"
#define MAX_ACCOUNTS 10
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
void gotoxy(int x, int y) {
    HANDLE hOut;
    COORD pos = {x, y};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
void drawTable(int x, int y, int width, int height) {
    int i;

    // 绘制左上角
    gotoxy(x, y);
    printf("┌");

    // 绘制上边框
    for (i = 1; i < width - 1; i++) {
        printf("─");
    }
    printf("┐");

    // 绘制左边框和右边框
    for (i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
        printf("│");
        gotoxy(x + width - 1, y + i);
        printf("│");
    }

    // 绘制左下角
    gotoxy(x, y + height - 1);
    printf("└");
    for (i = 1; i < width - 1; i++) {
        printf("─");
    }
    printf("┘");
}
void input_check(int inputType, int maxLen, int mode, char arr[10]) {
    int i = 0;
    char ch;


    while (1) {
        ch = getch(); // 从控制台读取字符，不回显到屏幕
        if (ch == 13) // 按下回车键退出循环
            break;

        // 检查输入类型并过滤输入
        switch (inputType) {
            case 1:
                if (ch >= '0' && ch <= '9')
                    break;
                else
                    continue;
            case 2:
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    break;
                else
                    continue;
            case 3:
                if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    break;
                else
                    continue;
            default:
                printf("Invalid input type\n");
                return;
        }

        // 检查是否超出最大长度
        if (i < maxLen) {
            // 根据存储模式存储输入字符
            if (mode == 0) // 密文
                printf("*");
            arr[i++] = ch;
        } else {
            printf("\n超出最大长度\n");
            break;
        }
    }

    // 添加字符串终止符
    arr[i] = '\0';
}