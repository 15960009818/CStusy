#include "CRole.h"
#include "../controller/CLogin.h"
#include "../static/Screen.h"
#include <stdio.h>
#include "../controller/CTools.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "../controller/CStaff.h"
void usermanageWin() {
    WIN_T user = {10, 5, 60, 20}; // ����������ʼ���﷨
    CONTROL_T title = {20, 2, 0, 0, LABEL, "��Ա����"};
    CONTROL_T adduserBtn = {20, 9, 20, 3, BUTTON, "�����û�"};
    CONTROL_T getuserBtn = {20, 12, 20, 3, BUTTON, "��ѯ�û���Ϣ"};
    CONTROL_T updateuserBtn = {20, 17, 15, 3, BUTTON, "�޸��û���Ϣ"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"����"};

    // ���� addCtrl �����Ѿ���ȷʵ��
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, title);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, adduserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, getuserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, updateuserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, exitBtn);

    printf("�ؼ�����%d\n", user.ctrlCount );
    showWin(&user); // �޸�������� user �ṹ��ĵ�ַ

    user = *winRun(&user); // ��ȡ winRun �����ķ���ֵ������ user �ṹ��

    showWin(&user); // �ٴ���ʾ���º�� user �ṹ��
}

