#include <stdio.h>
#include <string.h>
#include "Login.h"
#include "CTools.h"
extern int numAccounts;
extern char accounts[MAX_ACCOUNTS][2][MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
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
void loginScreen() {
    system("cls"); // ����
    drawTable(0, 0, 40, 15); // ���Ƶ�¼����
	gotoxy(7,2);
	printf("��½ϵͳ");
    gotoxy(7, 5);
    printf("�˺�: ");
    gotoxy(7, 6);
    printf("����: ");
}