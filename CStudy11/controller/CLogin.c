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
            return 1; // 验证通过
        }
    }
    return 0; // 验证失败
}
int loginWin() {
    WIN_T login = {10, 5, 60, 20}; // 修正变量初始化语法
    CONTROL_T title = {20, 2, 0, 0, LABEL, "OrderDish点菜系统"};
    CONTROL_T nameLabel = {15, 9, 5, 0, LABEL, "账号："};
    CONTROL_T pwdLabel = {15, 12, 5, 0, LABEL, "密码："};
    CONTROL_T nameEdit = {20, 9, 20, 3, EDIT, "admin", 3, 1, 6};
    CONTROL_T pwdEdit = {20, 12, 20, 3, EDIT, "123456", 3, 0, 6};
    CONTROL_T loginBtn = {20, 17, 15, 3, BUTTON, "登录"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"退出"};

    // 假设 addCtrl 函数已经正确实现
    addCtrl(login.ctrlArr, &login.ctrlCount, title);
    addCtrl(login.ctrlArr, &login.ctrlCount, nameLabel);
    addCtrl(login.ctrlArr, &login.ctrlCount, pwdLabel);
    addCtrl(login.ctrlArr, &login.ctrlCount, nameEdit);
    addCtrl(login.ctrlArr, &login.ctrlCount, pwdEdit);
    addCtrl(login.ctrlArr, &login.ctrlCount, loginBtn);
    addCtrl(login.ctrlArr, &login.ctrlCount, exitBtn);

    printf("控件个数%d\n", login.ctrlCount );
    showWin(&login);
    
    // 调用 winRun 函数并将返回值赋给 result 变量
    winRun(&login);

    if(login.ctrlIndex == 4) {
        // 登录按钮被点击，执行登录操作
        char username[21], password[21];
        strcpy(username, login.ctrlArr[3].content);
        strcpy(password, login.ctrlArr[4].content);
        printf("用户名：%s\n", username);
        printf("密码：%s\n", password);
    } else {
        // 其他操作，如退出等
        printf("操作取消或退出。\n");
    }
    if(login.ctrlIndex == 5) {
        printf("登录\n");
    } else if(login.ctrlIndex == 6) {
        printf("返回\n");
    }
	
	return 0;
	
}



