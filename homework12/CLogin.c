//
// Created by 1 on 2024/4/27.
//

#include "CLogin.h"
#include "CLogin.h"
#include "Screen.h"
#include <stdio.h>
#include "CTools.h"
void loginWin(){
    int i = 0;
    WIN_T login = {10, 5, 60, 20}; // 修正变量初始化语法
    CONTROL_T title = {10, 2, 0, 0, LABEL, "点菜系统"};
    CONTROL_T nameEdit = {10, 9, 20, 5, EDIT, "admin", 3, 1, 6};
    CONTROL_T pwdEdit = {10, 12, 20, 5, EDIT, "123456", 3, 0, 6};
    CONTROL_T loginBtn = {20, 17, 15, 5, BUTTON, "登录"};
    CONTROL_T exitBtn = {30,17,15,5,BUTTON,"退出"};
    // 假设 addCtrl 函数已经正确实现
    login.ctrlCount = addCtrl(login.ctrlArr, login.ctrlCount, title);
    login.ctrlCount =addCtrl(login.ctrlArr, login.ctrlCount, nameEdit);
    login.ctrlCount = addCtrl(login.ctrlArr, login.ctrlCount, pwdEdit);
    login.ctrlCount = addCtrl(login.ctrlArr, login.ctrlCount, loginBtn);
    login.ctrlCount = addCtrl(login.ctrlArr,login.ctrlCount,exitBtn);
    printf("控件个数%d\n", login.ctrlCount );
    showWin(login);
    login = winRun(login);
    if(login.ctrlIndex==3){
//        strcpy(name,login,ctrlArr[1].content);
//        strcpy(pwd,login,ctrlArr[1].content);
        printf("登录");
    } else if(login.ctrlIndex ==4){
        printf("返回");
    }
    showWin(login);

}
