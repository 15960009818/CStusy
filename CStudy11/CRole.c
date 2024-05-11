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
    WIN_T user = {10, 5, 60, 20}; // 修正变量初始化语法
    CONTROL_T title = {20, 2, 0, 0, LABEL, "人员管理"};
    CONTROL_T adduserBtn = {20, 9, 20, 3, BUTTON, "新增用户"};
    CONTROL_T getuserBtn = {20, 12, 20, 3, BUTTON, "查询用户信息"};
    CONTROL_T updateuserBtn = {20, 17, 15, 3, BUTTON, "修改用户信息"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"返回"};

    // 假设 addCtrl 函数已经正确实现
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, title);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, adduserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, getuserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, updateuserBtn);
    user.ctrlCount = addCtrl(user.ctrlArr, user.ctrlCount, exitBtn);

    printf("控件个数%d\n", user.ctrlCount );
    showWin(&user); // 修改这里，传递 user 结构体的地址

    user = *winRun(&user); // 获取 winRun 函数的返回值并更新 user 结构体

    showWin(&user); // 再次显示更新后的 user 结构体
}

