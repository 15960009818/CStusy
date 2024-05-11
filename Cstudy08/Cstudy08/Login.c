#include <stdio.h>
#include <string.h>
#include "Login.h"
#include "CTools.h"
extern int numAccounts;
extern char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
void login(char *username, char *password) {
	int i;
    if(strcmp(username, "") == 0 || strcmp(password, "") == 0) {
        printf("账号或密码为空，请重新输入\n");
    } else {
        for (i = 0; i < MAX_ACCOUNTS; i++) {
            if(strcmp(username, accounts[i][0]) == 0 && strcmp(password, accounts[i][1]) == 0) {
                printf("登录成功！\n");
                return;
            }
        }
        printf("账号密码错误，请重新输入\n");
		
    }
}
void loginScreen() {
    system("cls"); // 清屏
    drawTable(0, 0, 40, 15); // 绘制登录窗口
	gotoxy(7,2);
	printf("登陆系统");
    gotoxy(7, 5);
    printf("账号: ");
    gotoxy(7, 6);
    printf("密码: ");
}