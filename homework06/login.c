#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

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
void check() {
    strcpy(accounts[0][0], "user1");
    strcpy(accounts[0][1], "password1");
    strcpy(accounts[1][0], "user2");
    strcpy(accounts[1][1], "password2");
}

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
}

			



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

void registerAccount(char *username, char *password) {
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i][0], "") == 0) { // Find an empty slot
            strcpy(accounts[i][0], username);
            strcpy(accounts[i][1], password);
            printf("ע��ɹ���\n");
            return;
        }
    }
    printf("�޷�ע�ᣬ�˺�������\n");
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

    gotoxy(7, 5); // Set cursor position to (7, 5)

    // Input username
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
    gotoxy(7, 6); // Set cursor position to (7, 6)

    // Input password
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
    gotoxy(11, 7); // Set cursor position to (11, 7)

    // Confirm password
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // Backspace
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
        // Check if username already exists
        int i;
        for (i = 0; i < MAX_ACCOUNTS; i++) {
            if (strcmp(username, accounts[i][0]) == 0) {
                printf("�����˺ţ������ԡ�\n");
                return;
            }
        }
        // Register account if username is unique
        registerAccount(username, password);
		printf("ע��ɹ�");
		
    } else {
        printf("������������벻ƥ�䣬������ע�ᡣ\n");
    }
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

