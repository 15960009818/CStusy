#include "../static/Screen.h"  // ������Ļ������ص�ͷ�ļ�
#include "../controller/CLogin.h"  // �����¼������ص�ͷ�ļ�
#include <stdio.h>  // �����׼�������ͷ�ļ�
#include <conio.h>  // �������̨�������ͷ�ļ�
#include "string.h"  // �����ַ�������ͷ�ļ�
#include "../controller/CTools.h"  // ���빤�ߺ�����ص�ͷ�ļ�
#include <ctype.h>
int i = 0;  // ȫ�ֱ���������ѭ������

// ��ӿؼ����ؼ�������
// ��ӿؼ����ؼ�������
void addCtrl(CONTROL_T *ctrlArr, int *ctrlCount, CONTROL_T ctrl) {
    // �߽���
    if (*ctrlCount < 20) {
        // ���¿ؼ���ӵ������У������¿ؼ�����
        ctrlArr[*ctrlCount] = ctrl;
        (*ctrlCount)++;
    } else {
        printf("�ؼ������Ѵﵽ���ޣ��޷�����¿ؼ���\n");
    }
}



// ��ʾ��ǩ�ؼ�����
void showLabel(CONTROL_T ctrl){
    gotoxy(ctrl.x, ctrl.y);
    printf("%s",ctrl.content);
}

// ��ʾ�༭��ؼ�����
void showEdit(CONTROL_T ctrl){

    unsigned int i=0;
    paintWindow(ctrl.x, ctrl.y, ctrl.width, ctrl.height);
    gotoxy(ctrl.x + 2, ctrl.y + 1);
    if (ctrl.mode == 1) {
        printf("%s", ctrl.content);
    } else if (ctrl.mode == 0) {
        for (i = 0; i < strlen(ctrl.content); i++) {
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

void showWin(WIN_T *win) {
	int i;
    gotoxy(win->ctrlArr[i].x + 2, win->ctrlArr[i].y + 1);

    
    for (i = 0; i < win->ctrlCount; i++) {
        switch (win->ctrlArr[i].ctrlType) {
            case LABEL: showLabel(win->ctrlArr[i]); break;
            case EDIT: showEdit(win->ctrlArr[i]); break;
            case BUTTON: showButton(win->ctrlArr[i]); break;
        }
    }
    // ���ù��λ��Ϊ��ǰ����ؼ�
    gotoxy(win->ctrlArr[i].x + 2, win->ctrlArr[i].y + 1);
}


// �༭����̼���
void editKeyListen(char ch,CONTROL_T ctrl,char str[]){
   int len = strlen(str);
    if (ch == '\b' && len > 0) {
        printf("\b \b");
        str[--len] = '\0';
        return;
    }
    if ((ctrl.inputType == 1 && isdigit(ch)) ||
        (ctrl.inputType == 2 && isalpha(ch)) ||
        (ctrl.inputType == 3 && (isdigit(ch) || isalpha(ch)))) {
        if (len < ctrl.maxLen) {
            ctrl.mode == 1 ? putch(ch) : putch('*');
            str[len] = ch;
            str[len + 1] = '\0';
        }
    }
}

// ��������
// ��������
//ָ�봫�κ�Ͳ�Ҫ���ش�����
void winRun(WIN_T* winT) {
    int key = 0;
    int i = 0; // ���岢��ʼ��ѭ������
    int j = 0;

    // ��ѭ����ʼǰ���ҵ�һ���༭���ť����������ƶ�����λ��
    for (i = 0; i < winT->ctrlCount; i++) {
        if (winT->ctrlArr[i].ctrlType == EDIT || winT->ctrlArr[i].ctrlType == BUTTON) {
            gotoxy(winT->ctrlArr[i].x + 2, winT->ctrlArr[i].y + 1);
            break;
        }
    }

    while (1) {
        key = getkey();
        switch (key) {
            case KEY_UP:
                i--; // �����ƶ�����
                if (i < 0) i = winT->ctrlCount - 1;
                while (winT->ctrlArr[i].ctrlType != EDIT && winT->ctrlArr[i].ctrlType != BUTTON) {
                    i--; // ���������ƶ�������ֱ���ҵ��༭���ť
                    if (i < 0) i = winT->ctrlCount - 1;
                }
                gotoxy(winT->ctrlArr[i].x + 2, winT->ctrlArr[i].y + 1);
                break;
            case KEY_DOWN:
                // ʹ��һ���µı��� j �����ؼ����飬������� i ��ֵ
                for (j = i + 1; j < winT->ctrlCount; j++) {
                    if (winT->ctrlArr[j].ctrlType == EDIT || winT->ctrlArr[j].ctrlType == BUTTON) {
                        i = j; // ��������Ϊ�ҵ��Ŀؼ�������
                        gotoxy(winT->ctrlArr[i].x + 2, winT->ctrlArr[i].y + 1);
                        break;
                    }
                }
                break;
            case KEY_ENTER:
                if (winT->ctrlArr[i].ctrlType == BUTTON) {
                    //printf("i=%d",i);
                    winT->ctrlIndex = i;
                    return;
                } /*else if (winT->ctrlArr[i].ctrlType == BUTTON) {
					winT->ctrlIndex = i;
                    // ����ǰ�ť��ִ����Ӧ�İ�ť����
                    if (strcmp(winT->ctrlArr[i].content, "��¼") == 0) {
                        // ִ�е�¼����
                        char username[21], password[21];
                        strcpy(username, winT->ctrlArr[3].content); // ��ȡ�˺ű༭�������
                        strcpy(password, winT->ctrlArr[4].content); // ��ȡ����༭�������
                        if (authenticate(username, password)) {
                            printf("��¼�ɹ�\n");
							
                        } else {
                            printf("��¼ʧ��\n");
                            
                        }
                    } else if (strcmp(winT->ctrlArr[i].content, "�˳�") == 0) {
                        // ִ���˳�����
                        printf("�˳�\n");
                    }*/
                    
                
            default:
                // ������������
                break;
        }
    }
    return winT;
}

