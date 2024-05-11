//
// Created by 1 on 2024/4/23.
//

#include "../controller/CTools.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "CLogin.h"
void gotoxy(int x,int y){
        HANDLE hOut;
        COORD pos= {x,y};
// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}

void paintWindow(int startX, int startY, int width, int height) {
     int x, y;

    // ���ƶ����߿�
	gotoxy(startX,startY);
    printf("��");
    for (x = 0; x < width - 2; x++) {
        printf("��");
    }
    printf("��\n");
	
    // ���Ʋ�߱߿�
    for (y = startY + 1; y < startY + height - 1; y++) {
		gotoxy(startX,y);
        printf("��");
        for (x = 0; x < width - 2; x++) {
            printf(" ");
        }
        printf("��\n");
    }
	gotoxy(startX,y);
    // ���Ƶײ��߿�
    printf("��");
    for (x = startX + 1; x < startX + width - 1; x++) {
		
        printf("��");
    }
    printf("��\n");
}


void input_check(int inputType, int maxlen, int mode, char arr[]) {
    int i = 0;
    char ch;

    while ((ch = getch()) != '\r' && i < maxlen) { // ѭ����ȡ�ַ���ֱ���û�����س���ﵽ��󳤶�
        // ��������������֤�ַ�
        if (inputType == 1) {
            if (!isdigit(ch)) {
                printf("���������֡�\n");
                return;
            }
        } else if (inputType == 2) {
            if (!isalpha(ch)) {
                printf("��������ĸ��\n");
                return;
            }
        } else if (inputType == 3) {
            if (!isalnum(ch)) {
                printf("���������ֻ���ĸ��\n");
                return;
            }
        }

        // ������ʾģʽ�����ַ�
        if (mode == 0) {
            arr[i] = '*'; // ����ģʽ
        } else {
            arr[i] = ch; // ����ģʽ
        }

        putchar(arr[i]); // ��ӡ���Ļ������ַ�
        i++;
    }

    arr[i] = '\0'; // ����ַ���������
}


//void paintTbale(int x,int y,int row,int col,int col_width);
int getkey() {
    int key = getch();  // ��ȡ����������ַ�

    // �����һ���ַ��Ƿ�����룬��ȡ��һ���ַ�
    if (key == 224 || key == -32) {
        key = getch(); // ��ȡ��һ���ַ�
        switch (key) {
            case 72: // ��
                return KEY_UP;
            case 80: // ��
                return KEY_DOWN;
            case 75: // ��
                return KEY_LEFT;
            case 77: // ��
                return KEY_RIGHT;
        }
    } else if (key == 13 || key == 27) {
        switch (key) {
            case 13:
                return KEY_ENTER;
            case 27:
                return KEY_ESC;
        }
    }
    return 0;
}

// ���Ʊ��
void paintTable(int x, int y, int row, int col, int col_width) {
    int i = 0;
	int j = 0;
	int k = 0;

    // ���Ʊ�ͷ
    gotoxy(x, y);
    printf("��");
    for (i = 0; i < col - 1; i++) {
        for (j = 0; j < col_width; j++) printf("��");
        printf("��");
    }
    for (j = 0; j < col_width; j++) printf("��");
    printf("��\n");

    // ���Ʒָ���
    for (i = 0; i < row - 1; i++) {
        gotoxy(x, y + i * 2 + 1);
        printf("��");
        for (j = 0; j < col - 1; j++) {
            for (k = 0; k < col_width; k++) printf("��");
            printf("��");
        }
        for (k = 0; k < col_width; k++) printf("��");
        printf("��\n");
    }

    // ���Ʊ�β
    gotoxy(x, y + (row - 1) * 2 + 1);
    printf("��");
    for (i = 0; i < col - 1; i++) {
        for (j = 0; j < col_width; j++) printf("��");
        printf("��");
    }
    for (j = 0; j < col_width; j++) printf("��");
    printf("��\n");
}