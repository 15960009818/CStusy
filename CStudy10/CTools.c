//
// Created by 1 on 2024/4/23.
//

#include "CTools.h"
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

void paintWindow(int startX,int startY,int width,int height){
    int i = 0;
    for(i=0;i<login.ctrlCount;i++)
    {
        switch(login.ctrlArr[i].ctrlType)
        {
            case LABEL:showLabel(login.ctrlArr[i]);break;
            case EDIT:showEdit(login.ctrlArr[i]);break;
            case BUTTON:showButton(login.ctrlArr[i]);break;
        }

}
void input_check(int inputType,int maxlen,int mode,char arr[]){
        int i = 0;
        char ch;

        while (i < maxlen) {
            ch = getch();

            // ��������������֤�ַ�
            if (inputType == 1) {
                if (!isdigit(ch)) {
                    printf("���������֡�\n");
                    continue;
                }
            } else if (inputType == 2) {
                if (!isalpha(ch)) {
                    printf("��������ĸ��\n");
                    continue;
                }
            } else if (inputType == 3) {
                if (!isalnum(ch)) {
                    printf("���������ֻ���ĸ��\n");
                    continue;
                }
            }

            // ������ʾģʽ�����ַ�
            if (mode == 0) {
                arr[i] = '*'; // ����ģʽ
            } else {
                arr[i] = ch; // ����ģʽ
            }

            i++;
        }

        arr[i] = '\0'; // ����ַ���������
    }


void paintTbale(int x,int y,int row,int col,int col_width);