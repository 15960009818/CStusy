#include <stdio.h>
#include <conio.h>
#include "CTools.h"
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
void drawTable(int x, int y, int width, int height) {
    int i;

    // �������Ͻ�
    gotoxy(x, y);
    printf("��");

    // �����ϱ߿�
    for (i = 1; i < width - 1; i++) {
        printf("��");
    }
    printf("��");

    // ������߿���ұ߿�
    for (i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
        printf("��");
        gotoxy(x + width - 1, y + i);
        printf("��");
    }

    // �������½�
    gotoxy(x, y + height - 1);
    printf("��");
    for (i = 1; i < width - 1; i++) {
        printf("��");
    }
    printf("��");
}
void input_check(int inputType, int maxLen, int mode, char arr[10]) {
    int i = 0;
    char ch;


    while (1) {
        ch = getch(); // �ӿ���̨��ȡ�ַ��������Ե���Ļ
        if (ch == 13) // ���»س����˳�ѭ��
            break;

        // ����������Ͳ���������
        switch (inputType) {
            case 1:
                if (ch >= '0' && ch <= '9')
                    break;
                else
                    continue;
            case 2:
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    break;
                else
                    continue;
            case 3:
                if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    break;
                else
                    continue;
            default:
                printf("Invalid input type\n");
                return;
        }

        // ����Ƿ񳬳���󳤶�
        if (i < maxLen) {
            // ���ݴ洢ģʽ�洢�����ַ�
            if (mode == 0) // ����
                printf("*");
            arr[i++] = ch;
        } else {
            printf("\n������󳤶�\n");
            break;
        }
    }

    // ����ַ�����ֹ��
    arr[i] = '\0';
}