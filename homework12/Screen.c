#include "Screen.h"  // ������Ļ������ص�ͷ�ļ�
#include "CLogin.h"  // �����¼������ص�ͷ�ļ�
#include <stdio.h>  // �����׼�������ͷ�ļ�
#include <conio.h>  // �������̨�������ͷ�ļ�
#include "string.h"  // �����ַ�������ͷ�ļ�
#include "CTools.h"  // ���빤�ߺ�����ص�ͷ�ļ�

int i = 0;  // ȫ�ֱ���������ѭ������

// ��ӿؼ����ؼ�������
int addCtrl(CONTROL_T ctrlArr[20], int ctrlCount, CONTROL_T ctrl) {
    // �߽���
    if (ctrlCount < 20) {
        // ���¿ؼ���ӵ������У������¿ؼ�����
        ctrlArr[ctrlCount] = ctrl;
        ctrlCount++;
    } else {
        printf("�ؼ������Ѵﵽ���ޣ��޷�����¿ؼ���\n");
    }
    return ctrlCount; // ���ظ��º�Ŀؼ�����
}

// ��ʾ��ǩ�ؼ�����
void showLabel(CONTROL_T ctrl){
    gotoxy(ctrl.x, ctrl.y);
    printf("%s",ctrl.content);
}

// ��ʾ�༭��ؼ�����
void showEdit(CONTROL_T ctrl){

    paintWindow(ctrl.x,ctrl.y,ctrl.width,ctrl.height);

    // �����ı�Ӧ�÷��õ�λ�ã�ʹ��λ�ڿؼ����ھ�����ʾ
    int textX = ctrl.x + (ctrl.width - strlen(ctrl.content)) / 2;
    int textY = ctrl.y + (ctrl.height - 1) / 2;

    // ��ʾ�ı�
    gotoxy(textX, textY);
    if (ctrl.mode == 1) {
        printf("%s", ctrl.content);
    } else if (ctrl.mode == 0) {
        for (unsigned int i = 0; i < strlen(ctrl.content); i++) {
            putch('*');
        }
    }
}

// ��ʾ��ť�ؼ�����
void showButton(CONTROL_T ctrl){
    paintWindow(ctrl.x,ctrl.y,ctrl.width, ctrl.height);
    gotoxy(ctrl.x+2,ctrl.y+1);
    printf("%s", ctrl.content);
}

// ��ʾ���ڼ����еĿؼ�
void showWin(WIN_T win){
    paintWindow(win.x, win.y, win.width, win.height);

    for(i=0;i<win.ctrlCount;i++)
    {
        switch(win.ctrlArr[i].ctrlType)
        {
            case LABEL:showLabel(win.ctrlArr[i]);break;
            case EDIT:showEdit(win.ctrlArr[i]);break;
            case BUTTON:showButton(win.ctrlArr[i]);break;
        }
    }
}

// �༭����̼���
void editKeyListen(char ch,CONTROL_T ctrl,char str[]){
    int len = strlen(str);
    if(ch == '\b' && len>0){
        printf("\b \b");
        str[--len] = '\0';
        return;
    }
    if(ch>='0'&&ch<='9'&&(ctrl.inputType==1||ctrl.inputType==3)||
       (ch>='a'&&ch<='z')&&(ctrl.inputType==2||ctrl.inputType==3)||
       (ch>='A'&&ch<='Z')&&(ctrl.inputType==2||ctrl.inputType==3)){
        if(len<ctrl.maxLen){
            ctrl.mode==1? putch(ch): putch('*');
            str[len]=ch;
        }
    }
}

// ��������
WIN_T winRun(WIN_T winT){
    // ���к��ȡ�༭��ؼ����������
    // ���°���ѡ�񣬻س�ȷ������������������ʾ
    int key = 0;
    for(i=0;i<winT.ctrlCount;i++)
    {
        if(winT.ctrlArr[i].ctrlType==EDIT|| winT.ctrlArr[i].ctrlType==BUTTON)
        {
            gotoxy(winT.ctrlArr[i].x+2, winT.ctrlArr[i].y+1);
            break;
        }
    }
    printf("i=%d",i);
    while (1) {
        key = getkey();
        switch (key) {
            case KEY_UP:
                i--;
                if (i < 0) i = winT.ctrlCount - 1;
                while (1) {//ֱ���ҵ��༭��
                    for (i = 0; i < winT.ctrlCount; i++) {
                        if (winT.ctrlArr[i].ctrlType == EDIT || winT.ctrlArr[i].ctrlType == BUTTON) {
                            gotoxy(winT.ctrlArr[i].x + 2, winT.ctrlArr[i].y + 1);
                            break;
                        }
                    }
                    i--;
                    if (i < 0) i = winT.ctrlCount - 1;
                }
                break;
            case KEY_DOWN:
                i++;
                if (i < 0) i = winT.ctrlCount - 1;
                while (1) {//ֱ���ҵ��༭��
                    for (i = 0; i < winT.ctrlCount; i++) {
                        if (winT.ctrlArr[i].ctrlType == EDIT || winT.ctrlArr[i].ctrlType == BUTTON) {
                            gotoxy(winT.ctrlArr[i].x + 2, winT.ctrlArr[i].y + 1);
                            break;
                        }
                    }
                    i++;
                    if (i < 0) i = winT.ctrlCount - 1;
                }
                break;
            case KEY_ENTER:
                if (winT.ctrlArr[i].ctrlType == EDIT || winT.ctrlArr[i].ctrlType == BUTTON) {
                    printf("i=%d",i);
                    winT.ctrlIndex=i;
                    break;
                }
            default:
                // ������������
                break;

        }
    }
    return winT;
}
