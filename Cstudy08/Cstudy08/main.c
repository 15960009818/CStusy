#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "CTools.h"
#include "Login.h"
#include "Register.h"
int numAccounts = 2;
char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH] = {{"user1","123456"},{"user2","654321"}};
/*void check() {
    strcpy(accounts[0][0], "user1");
    strcpy(accounts[0][1], "password1");
    strcpy(accounts[1][0], "user2");
    strcpy(accounts[1][1], "password2");
	numAccounts = 2;
}*/
/*
void login(char *username, char *password) {
	int i;
    if(strcmp(username, "") == 0 || strcmp(password, "") == 0) {
        printf("�˺Ż�����Ϊ�գ�����������\n");
    } else {
        for (i = 0; i < MAX_ACCOUNTS; i++) {
            if(strcmp(username, accounts[i][0]) == 0 && strcmp(password, accounts[i][1]) == 0) {
                printf("��¼�ɹ���\n");
                return;
            }
        }
        printf("�˺������������������\n");
		
    }
}*/






int main() {
    int i =0; // Declare i here
	char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int username_index = 0;
    int password_index = 0;
    char ch;
    //check();
    loginScreen();
	gotoxy(15,5);
   

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
    gotoxy(15, 6); // Set cursor position to (7, 8)

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

