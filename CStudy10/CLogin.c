#include "CLogin.h"
#include "Screen.h"
#include <stdio.h>
#include "CTools.h"
void loginWin(){
    int i = 0;
    WIN_T login = {10, 5, 60, 20}; // ����������ʼ���﷨
    CONTROL_T title = {40, 7, 0, 0, LABEL, "OrderDish���ϵͳ"};
    CONTROL_T nameEdit = {40, 9, 20, 3, EDIT, "admin", 3, 1, 6};
    CONTROL_T pwdEdit = {40, 12, 20, 3, EDIT, "123456", 3, 0, 6};
    CONTROL_T loginBtn = {30, 17, 15, 3, BUTTON, "��¼"};

    // ���� addCtrl �����Ѿ���ȷʵ��
    addCtrl(login.ctrlArr, &(login.ctrlCount), &title);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &nameEdit);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &pwdEdit);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &loginBtn);
    printf("�ؼ�����%d\n", login.ctrlCount );

    // ���ƴ��ڼ��ؼ�
    // ���� paintWindow �����Ѿ���ȷʵ��
/*    paintWindow(login.x, login.y, login.width, login.height);
	
	for(i=0;i<login.ctrlCount;i++)
	{
		switch(login.ctrlArr[i].ctrlType)
		{
			case LABEL:showLabel(login.ctrlArr[i]);break;
			case EDIT:showEdit(login.ctrlArr[i]);break;
			case BUTTON:showButton(login.ctrlArr[i]);break;
		}
	}*/
	showWin(login);
	(i=0;i<login.ctrlCount;i++)
	{
		if(login.ctrlArr[i].ctrlType==EDIT|| login.ctrlArr[i].ctrIType==BUTTON)
		{
		gotoxy(login.ctrlArr[i].x+2, login.ctrlArr[i].y+1);
		break;
		}
	}
	getch();
/*    // �����������
    // ���� gotoxy �����Ѿ���ȷʵ��
    gotoxy(title.x, title.y);
    printf("%s", title.content);

    // �����û����༭��
    paintWindow(nameEdit.x, nameEdit.y, nameEdit.width, nameEdit.height);
    gotoxy(nameEdit.x + 2, nameEdit.y + 1);
    printf("%s", nameEdit.content);

    // ��������༭��
    paintWindow(pwdEdit.x, pwdEdit.y, pwdEdit.width, pwdEdit.height);
    gotoxy(pwdEdit.x + 2, pwdEdit.y + 1);
    printf("*********");

    // ���Ƶ�¼��ť
    paintWindow(loginBtn.x, loginBtn.y, loginBtn.width, loginBtn.height);
    gotoxy(loginBtn.x + 2, loginBtn.y + 1);
    printf("%s", loginBtn.content);*/
}
