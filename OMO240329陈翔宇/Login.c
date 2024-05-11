#include<stdio.h>

void check() {
    strcpy(accounts[0][0], "user1");
    strcpy(accounts[0][1], "password1");
    strcpy(accounts[1][0], "user2");
    strcpy(accounts[1][1], "password2");
}
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
void registerAccount(char *username, char *password) {
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i][0], "") == 0) { // Find an empty slot
            strcpy(accounts[i][0], username);
            strcpy(accounts[i][1], password);
            printf("注册成功！\n");
            return;
        }
    }
    printf("无法注册，账号已满。\n");
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
                printf("已有账号，请重试。\n");
                return;
            }
        }
        // Register account if username is unique
        registerAccount(username, password);
		printf("注册成功");
		
    } else {
        printf("两次输入的密码不匹配，请重新注册。\n");
    }
}