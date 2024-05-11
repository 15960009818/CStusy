#include "h/Screen.h"  // 引入屏幕控制相关的头文件
#include "../controller/h/CLogin.h"  // 引入登录窗口相关的头文件
#include <stdio.h>  // 引入标准输入输出头文件
#include <conio.h>  // 引入控制台输入输出头文件
#include "string.h"  // 引入字符串处理头文件
#include "h/CTools.h"  // 引入工具函数相关的头文件
#include <ctype.h>
int i = 0;  // 全局变量，用于循环计数

// 添加控件到控件数组中
// 添加控件到控件数组中
void addCtrl(CONTROL_T *ctrlArr, int *ctrlCount, CONTROL_T ctrl) {
    // 边界检查
    if (*ctrlCount < 20) {
        // 将新控件添加到数组中，并更新控件数量
        ctrlArr[*ctrlCount] = ctrl;
        (*ctrlCount)++;
    } else {
        printf("控件数量已达到上限，无法添加新控件。\n");
    }
}



// 显示标签控件内容
void showLabel(CONTROL_T ctrl){
    gotoxy(ctrl.x, ctrl.y);
    printf("%s",ctrl.content);
}

// 显示编辑框控件内容
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

// 显示按钮控件内容
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
    // 设置光标位置为当前焦点控件
    gotoxy(win->ctrlArr[i].x + 2, win->ctrlArr[i].y + 1);
}


// 编辑框键盘监听
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

// 窗口运行
// 窗口运行
 WIN_T* winRun(WIN_T* winT) {
    int key = 0;
    int i = 0; // 定义并初始化循环索引
    int j = 0;

    // 在循环开始前查找第一个编辑框或按钮，并将光标移动到该位置
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
                i--; // 向上移动索引
                if (i < 0) i = winT->ctrlCount - 1;
                while (winT->ctrlArr[i].ctrlType != EDIT && winT->ctrlArr[i].ctrlType != BUTTON) {
                    i--; // 继续向上移动索引，直到找到编辑框或按钮
                    if (i < 0) i = winT->ctrlCount - 1;
                }
                gotoxy(winT->ctrlArr[i].x + 2, winT->ctrlArr[i].y + 1);
                break;
            case KEY_DOWN:
                // 使用一个新的变量 j 迭代控件数组，避免混淆 i 的值
                for (j = i + 1; j < winT->ctrlCount; j++) {
                    if (winT->ctrlArr[j].ctrlType == EDIT || winT->ctrlArr[j].ctrlType == BUTTON) {
                        i = j; // 更新索引为找到的控件的索引
                        gotoxy(winT->ctrlArr[i].x + 2, winT->ctrlArr[i].y + 1);
                        break;
                    }
                }
                break;
            /*case KEY_ENTER:
                if (winT->ctrlArr[i].ctrlType == EDIT || winT->ctrlArr[i].ctrlType == BUTTON) {
                    //printf("i=%d",i);
                    winT->ctrlIndex = i;
                    break;
                } else if (winT->ctrlArr[i].ctrlType == BUTTON) {
                    // 如果是按钮，执行相应的按钮操作
                    if (strcmp(winT->ctrlArr[i].content, "登录") == 0) {
                        // 执行登录操作
                        char username[21], password[21];
                        strcpy(username, winT->ctrlArr[3].content); // 获取账号编辑框的内容
                        strcpy(password, winT->ctrlArr[4].content); // 获取密码编辑框的内容
                        if (authenticate(username, password)) {
                            printf("登录成功\n");

                        } else {
                            printf("登录失败\n");

                        }
                    } else if (strcmp(winT->ctrlArr[i].content, "退出") == 0) {
                        // 执行退出操作
                        printf("退出\n");
                    }
                    break;
                }*/
            default:
                // 其他按键处理
                break;
        }
    }
    return winT;
}
