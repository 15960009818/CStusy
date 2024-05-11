#include <stdio.h>
#include <string.h>
#include "CTools.h"
#include "Login.h"
extern int numAccounts;
extern char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
void registerScreen(){
	system("cls"); // ����
    drawTable(0, 0, 40, 15); // ���Ƶ�¼����
	gotoxy(7,2);
	printf("ע��ϵͳ");
    gotoxy(7, 5);
    printf("�˺�: ");
    gotoxy(7, 6);
    printf("����: ");
	gotoxy(7,7);
	printf("ȷ������");
}
void registerAccount(char *username, char *password) {
    if (numAccounts < MAX_ACCOUNTS) { // ȷ�����п�����˺�λ��
        strcpy(accounts[numAccounts][0], username);
        strcpy(accounts[numAccounts][1], password);
        numAccounts++; // ������ע���˺�����
        printf("ע��ɹ���\n");
    } else {
        printf("�޷�ע�ᣬ�˺�������\n");
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

    gotoxy(15, 5); // ���ù��λ���� (15, 5)

    // �����û���
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // �˸�
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
    gotoxy(15, 6); // ���ù��λ���� (15, 6)

    // ��������
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // �˸�
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
    gotoxy(15, 7); // ���ù��λ���� (15, 7)

    // ȷ������
    while ((ch = getch()) != '\r') {
        if (ch == 8) { // �˸�
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
        printf("ע��ɹ�\n");

        printf("���� 'L' ���е�¼������ 'R' ����ע�᣺\n");
        ch = getch();

        if (ch == 'L' || ch == 'l') {
            loginScreen(); 
        } else if (ch == 'R' || ch == 'r') {
            registerScreen(); 
        } else {
            printf("��Ч�����룬�����˳���\n");
        }
    } else {
        printf("������������벻ƥ�䣬������ע�ᡣ\n");
    }
}
