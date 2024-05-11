#include "CRegWin.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "CStaff.h"
#include "CTools.h"
#include "CLogin.h"
extern int staffCount;
extern STAFF_T staffArr[10];

void regWin(){
    STAFF_T newStaff;
    char name[10] = {0}, pwd[10] = {0}, pwd2[10] = {0}; // �޸ĳ�ʼ���﷨

    int id = 0, role = 0, i = 0, flag = 0; // ���岢��ʼ�� flag ����

    paintWindow(10,5,60,20);

    gotoxy(40,7);
    printf("����û�");
    gotoxy(30,9);
    printf("�û���");
    gotoxy(40,11);
    id = staffArr[staffCount-1].id + 1; // ���� id �ļ��㷽ʽ
    printf("%d", id);
    gotoxy(30,13);
    printf("����");
    gotoxy(30,15);
    printf("ȷ������");
    gotoxy(30,17);
    printf("��ɫ");

	gotoxy(30,20);
	printf("1---ADMIN,2---MANAGE,3--WAITER");

    gotoxy(40,9);
    input_check(3,6,1,name);
    gotoxy(40,13);
    input_check(1,6,0,pwd);
    gotoxy(40,15);
    input_check(1,6,0,pwd2);
    gotoxy(40,17);
    scanf("%d", &role);

    printf("%s %s %s %d\n", name, pwd, pwd2, role);
    if(strcmp(pwd, pwd2) != 0){ // �޸������ж�
        printf("�������벻һ��");
        return;
    }
    if(role < 1 || role > 3){
        printf("û�����ֽ�ɫ");
        return;
    }
    for (i = 0; i < staffCount; i++){
        if(strcmp(name, staffArr[i].name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        newStaff.id = id;
        strcpy(newStaff.name, name); // ����������Ϊ strcpy
        strcpy(newStaff.pwd, pwd); // ����������Ϊ strcpy
        newStaff.role = role;
        addStaff(staffArr, staffCount, newStaff); // ������������
        printf("ע��ɹ�");
        printStaffInfo(staffArr, staffCount);
		Sleep(3000); // �ӳ�3��
        loginWin(); // ע��ɹ���ִ�е�¼���ڷ���
    } else{
        printf("ע��ʧ��");
    }
}

void modifyWin() {
    int id = 0, role = 0, i = 0, flag = 0;
	
    char name[10];
	char newPwd[10];
	    char newPwd2[10];
    paintWindow(10, 5, 60, 20);

    gotoxy(40, 7);
    printf("�޸��û���Ϣ");
    gotoxy(30, 9);
    printf("����Ҫ�޸ĵ��û�����");

    gotoxy(30, 11);
    input_check(3, 6, 1, name);

    for (i = 0; i < staffCount; i++) {
        if (strcmp(name, staffArr[i].name) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("δ�ҵ����û���");
        return;
    }

    gotoxy(30, 13);
    printf("�����룺");

    gotoxy(40, 13);
    input_check(1, 6, 0, newPwd);

    gotoxy(30, 15);
    printf("ȷ�������룺");

    gotoxy(40, 15);
    input_check(1, 6, 0, newPwd2);

    if (strcmp(newPwd, newPwd2) != 0) {
        printf("�������벻һ��");
        return;
    }

    gotoxy(30, 17);
    printf("�½�ɫ��");
    gotoxy(40, 17);
    scanf("%d", &role);

    if (role < 1 || role > 3) {
        printf("��Ч�Ľ�ɫ");
        return;
    }

    // �����û���Ϣ
    strcpy(staffArr[i].pwd, newPwd);
    staffArr[i].role = role;

    printf("�û���Ϣ�޸ĳɹ�");
    printStaffInfo(staffArr, staffCount);
    Sleep(3000); // �ӳ�3��
    loginWin(); // �޸ĳɹ���ִ�е�¼���ڷ���
}