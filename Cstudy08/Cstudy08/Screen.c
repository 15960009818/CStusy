#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "CTools.h"
#include "Login.h"
void drawLoginSystem() {
    paintWindow(5, 5, 30, 10); // ���Ƶ�¼����
    gotoxy(10, 7);
    printf("Username: ");
    gotoxy(10, 9);
    printf("Password: ");
}

void drawRegisterSystem() {
    paintWindow(5, 5, 30, 10); // ����ע�ᴰ��
    gotoxy(10, 7);
    printf("New Username: ");
    gotoxy(10, 9);
    printf("New Password: ");
}