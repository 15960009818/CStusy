#include "CLogin.h"
#include "../static/Screen.h"
#include <stdio.h>
#include "CTools.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "../controller/CStaff.h"
extern int staffCount;
extern STAFF_T staffArr[10];
int authenticate(char *username, char *password) {
	int i = 0;
    for (i = 0; i < staffCount; i++) {
        if (strcmp(username, staffArr[i].name) == 0 && strcmp(password, staffArr[i].pwd) == 0) {
            return 1; // ��֤ͨ��
        }
    }
    return 0; // ��֤ʧ��
}
int loginWin() {
    WIN_T login = {10, 5, 60, 20}; // ����������ʼ���﷨
    CONTROL_T title = {20, 2, 0, 0, LABEL, "OrderDish���ϵͳ"};
    CONTROL_T nameLabel = {15, 9, 5, 0, LABEL, "�˺ţ�"};
    CONTROL_T pwdLabel = {15, 12, 5, 0, LABEL, "���룺"};
    CONTROL_T nameEdit = {20, 9, 20, 3, EDIT, "admin", 3, 1, 6};
    CONTROL_T pwdEdit = {20, 12, 20, 3, EDIT, "123456", 3, 0, 6};
    CONTROL_T loginBtn = {20, 17, 15, 3, BUTTON, "��¼"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"�˳�"};

    // ���� addCtrl �����Ѿ���ȷʵ��
    addCtrl(login.ctrlArr, &login.ctrlCount, title);
    addCtrl(login.ctrlArr, &login.ctrlCount, nameLabel);
    addCtrl(login.ctrlArr, &login.ctrlCount, pwdLabel);
    addCtrl(login.ctrlArr, &login.ctrlCount, nameEdit);
    addCtrl(login.ctrlArr, &login.ctrlCount, pwdEdit);
    addCtrl(login.ctrlArr, &login.ctrlCount, loginBtn);
    addCtrl(login.ctrlArr, &login.ctrlCount, exitBtn);

    printf("�ؼ�����%d\n", login.ctrlCount );
    showWin(&login);
    
    // ���� winRun ������������ֵ���� result ����
    winRun(&login);

    if(login.ctrlIndex == 4) {
        // ��¼��ť�������ִ�е�¼����
        char username[21], password[21];
        strcpy(username, login.ctrlArr[3].content);
        strcpy(password, login.ctrlArr[4].content);
        printf("�û�����%s\n", username);
        printf("���룺%s\n", password);
    } else {
        // �������������˳���
        printf("����ȡ�����˳���\n");
    }
    if(login.ctrlIndex == 5) {
        printf("��¼\n");
    } else if(login.ctrlIndex == 6) {
        printf("����\n");
    }
	
	return 0;
	
}



