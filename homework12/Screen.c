#include "Screen.h"  // 引入屏幕控制相关的头文件
#include "CLogin.h"  // 引入登录窗口相关的头文件
#include <stdio.h>  // 引入标准输入输出头文件
#include <conio.h>  // 引入控制台输入输出头文件
#include "string.h"  // 引入字符串处理头文件
#include "CTools.h"  // 引入工具函数相关的头文件

int i = 0;  // 全局变量，用于循环计数

// 添加控件到控件数组中
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

// 显示标签控件内容
void showLabel(CONTROL_T ctrl){
    gotoxy(ctrl.x, ctrl.y);
    printf("%s",ctrl.content);
}

// 显示编辑框控件内容
void showEdit(CONTROL_T ctrl){

    paintWindow(ctrl.x,ctrl.y,ctrl.width,ctrl.height);

    // 计算文本应该放置的位置，使其位于控件框内居中显示
    int textX = ctrl.x + (ctrl.width - strlen(ctrl.content)) / 2;
    int textY = ctrl.y + (ctrl.height - 1) / 2;

    // 显示文本
    gotoxy(textX, textY);
    if (ctrl.mode == 1) {
        printf("%s", ctrl.content);
    } else if (ctrl.mode == 0) {
        for (unsigned int i = 0; i < strlen(ctrl.content); i++) {
            putch('*');
        }
    }
}

// 显示按钮控件内容
void showButton(CONTROL_T ctrl){
    paintWindow(ctrl.x,ctrl.y,ctrl.width, ctrl.height);
    gotoxy(ctrl.x+2,ctrl.y+1);
    printf("%s", ctrl.content);
}

// 显示窗口及其中的控件
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

// 编辑框键盘监听
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

// 窗口运行
WIN_T winRun(WIN_T winT){
    // 运行后获取编辑框控件并调整光标
    // 上下按键选择，回车确定，其他按键报错提示
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
                while (1) {//直到找到编辑框
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
                while (1) {//直到找到编辑框
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
                // 其他按键处理
                break;

        }
    }
    return winT;
}
