#include "CLogin.h"
#include "Screen.h"
#include <stdio.h>
#include "CTools.h"
void loginWin(){
    int i = 0;
    WIN_T login = {10, 5, 60, 20}; // 修正变量初始化语法
    CONTROL_T title = {40, 7, 0, 0, LABEL, "OrderDish点菜系统"};
    CONTROL_T nameEdit = {40, 9, 20, 3, EDIT, "admin", 3, 1, 6};
    CONTROL_T pwdEdit = {40, 12, 20, 3, EDIT, "123456", 3, 0, 6};
    CONTROL_T loginBtn = {30, 17, 15, 3, BUTTON, "登录"};

    // 假设 addCtrl 函数已经正确实现
    addCtrl(login.ctrlArr, &(login.ctrlCount), &title);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &nameEdit);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &pwdEdit);
    addCtrl(login.ctrlArr, &(login.ctrlCount), &loginBtn);
    printf("控件个数%d\n", login.ctrlCount );

    // 绘制窗口及控件
    // 假设 paintWindow 函数已经正确实现
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
/*    // 输出标题内容
    // 假设 gotoxy 函数已经正确实现
    gotoxy(title.x, title.y);
    printf("%s", title.content);

    // 绘制用户名编辑框
    paintWindow(nameEdit.x, nameEdit.y, nameEdit.width, nameEdit.height);
    gotoxy(nameEdit.x + 2, nameEdit.y + 1);
    printf("%s", nameEdit.content);

    // 绘制密码编辑框
    paintWindow(pwdEdit.x, pwdEdit.y, pwdEdit.width, pwdEdit.height);
    gotoxy(pwdEdit.x + 2, pwdEdit.y + 1);
    printf("*********");

    // 绘制登录按钮
    paintWindow(loginBtn.x, loginBtn.y, loginBtn.width, loginBtn.height);
    gotoxy(loginBtn.x + 2, loginBtn.y + 1);
    printf("%s", loginBtn.content);*/
}
