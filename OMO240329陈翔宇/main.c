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
    printf("*             ��¼ϵͳ                     *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* �˺�:                                    *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* ����:                                   *\n");
    printf("******************************************\n");

    gotoxy(9, 5); // Set cursor position to (9, 5)
}
void registerScreen(){
	printf("******************************************\n");
    printf("*             ע��ϵͳ                     *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("* �˺�:                                    *\n");
    printf("* ����:                                   *\n");
	printf("* ȷ������:                               *\n");
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
	printf("���� 'L' ���е�¼������ 'R' ����ע�᣺\n");

    ch = getch();
	
    if (ch == 'L' || ch == 'l') {
        // ��¼����
    } else if (ch == 'R' || ch == 'r') {
        registerProcess();
    } else {
        printf("��Ч�����룬�����˳���\n");
        return 1;
    }

    return 0;
}

