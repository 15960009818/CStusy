#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_ACCOUNTS 10
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];




			



void screen() {
    printf("******************************************\n");
    printf("*             登录系统                     *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* 账号:                                    *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* 密码:                                   *\n");
    printf("******************************************\n");

    gotoxy(9, 5); // Set cursor position to (9, 5)
}
void registerScreen(){
	printf("******************************************\n");
    printf("*             注册系统                     *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* 账号:                                    *\n");
    printf("* 密码:                                   *\n");
	printf("* 确认密码:                               *\n");
    printf("******************************************\n");
}




int main() {
    int i =0; // Declare i here
	char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int username_index = 0;
    int password_index = 0;
    char ch;
    check();
    screen();

   

    while ((ch = getch()) != '\r') {
        if (ch == 8) { // Backspace
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
    gotoxy(7, 8); // Set cursor position to (7, 8)

    while ((ch = getch()) != '\r') {
        if (ch == 8) { // Backspace
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
    login(username, password);
	printf("按下 'L' 进行登录，按下 'R' 进行注册：\n");

    ch = getch();
	
    if (ch == 'L' || ch == 'l') {
        // 登录流程
    } else if (ch == 'R' || ch == 'r') {
        registerProcess();
    } else {
        printf("无效的输入，程序退出。\n");
        return 1;
    }

    return 0;
}

