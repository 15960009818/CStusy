#include <stdio.h>
#include <string.h>
#include "CTools.h"
#include "Login.h"
extern int numAccounts;
extern char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
void registerScreen(){
	system("cls"); // 清屏
    drawTable(0, 0, 40, 15); // 绘制登录窗口
	gotoxy(7,2);
	printf("注册系统");
    gotoxy(7, 5);
    printf("账号: ");
    gotoxy(7, 6);
    printf("密码: ");
	gotoxy(7,7);
	printf("确认密码");
}
void registerAccount(char *username, char *password) {
    if (numAccounts < MAX_ACCOUNTS) { // 确保还有空余的账号位置
        strcpy(accounts[numAccounts][0], username);
        strcpy(accounts[numAccounts][1], password);
        numAccounts++; // 更新已注册账号数量
        printf("注册成功！\n");
    } else {
        printf("无法注册，账号已满。\n");
    }
}

void registerProcess() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char confirm[MAX_PASSWORD_LENGTH];
    int username_index = 0;
    int password_index = 0;
    int confirm_index = 0;
    char ch;
    system("cls");
    registerScreen();

    gotoxy(15, 5); // 设置光标位置至 (15, 5)

    // 输入用户名
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // 退格
            if (username_index > 0) {
                username_index--;
                printf("\b \b");
            }
        } else {
            if (username_index < MAX_USERNAME_LENGTH - 1) {
                username[username_index++] = ch;
                putch(ch);
            }
        }
    }
    username[username_index] = '\0';

    printf("\n");
    gotoxy(15, 6); // 设置光标位置至 (15, 6)

    // 输入密码
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // 退格
            if (password_index > 0) {
                password_index--;
                printf("\b \b");
            }
        } else {
            if (password_index < MAX_PASSWORD_LENGTH - 1) {
                password[password_index++] = ch;
                putch('*');
            }
        }
    }
    password[password_index] = '\0';

    printf("\n");
    gotoxy(15, 7); // 设置光标位置至 (15, 7)

    // 确认密码
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // 退格
            if (confirm_index > 0) {
                confirm_index--;
                printf("\b \b");
            }
        } else {
            if (confirm_index < MAX_PASSWORD_LENGTH - 1) {
                confirm[confirm_index++] = ch;
                putch('*');
            }
        }
    }
    confirm[confirm_index] = '\0';

    printf("\n");
	
    if (strcmp(password, confirm) == 0) {

        registerAccount(username, password);
        printf("注册成功\n");

        printf("按下 'L' 进行登录，按下 'R' 进行注册：\n");
        ch = getch();

        if (ch == 'L' || ch == 'l') {
            loginScreen(); 
        } else if (ch == 'R' || ch == 'r') {
            registerScreen(); 
        } else {
            printf("无效的输入，程序退出。\n");
        }
    } else {
        printf("两次输入的密码不匹配，请重新注册。\n");
    }
}
