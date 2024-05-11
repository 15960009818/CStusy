#include "Screen.h"
#include "CLogin.h"
#include <stdio.h>
#include <conio.h>
int addCtrl(CONTROL_T ctrlArr[20], int ctrlCount, CONTROL_T ctrl) {
    // 边界检查
    if (ctrlCount < 20) {
        // 将新控件添加到数组中，并更新控件数量
        ctrlArr[ctrlCount] = ctrl;
        ctrlCount++;
    } else {
        printf("控件数量已达到上限，无法添加新控件。\n");
    }
    return ctrlCount; // 返回更新后的控件数量
}
void showLabel(CONTROL_T ctrl){
	gotoxy(ctrl x, ctrl y);
	printf("%s",ctrl,content);
}
void showEdit(CONTROL_T ctrl){
	
	unsigned int i=0;
	paintWindow(ctrl.x,ctrl.y,ctrl.width,ctrl.height);
	gotoxy(ctrl.x+2,ctrl.y+1);
	if (ctrl.mode==1){
		printf("%s", ctrl.content);

	}
//显示的模式

	else if(ctrl.mode==0){
		for (i=0;i<strlen(ctrl.content);i++){
			putch('*');
		}
	}
}
void showButton(CONTROL_T ctrl){
	paintWindow(ctrl.x,ctrl.y,ctrl.width, ctrl.height);
	gotoxy(ctrl.x+2,ctrl.y+1);
	printf("%s", ctrl.content);
}

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