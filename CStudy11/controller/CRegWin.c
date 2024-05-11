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
    char name[10] = {0}, pwd[10] = {0}, pwd2[10] = {0}; // 修改初始化语法

    int id = 0, role = 0, i = 0, flag = 0; // 定义并初始化 flag 变量

    paintWindow(10,5,60,20);

    gotoxy(40,7);
    printf("添加用户");
    gotoxy(30,9);
    printf("用户名");
    gotoxy(40,11);
    id = staffArr[staffCount-1].id + 1; // 修正 id 的计算方式
    printf("%d", id);
    gotoxy(30,13);
    printf("密码");
    gotoxy(30,15);
    printf("确认密码");
    gotoxy(30,17);
    printf("角色");

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
    if(strcmp(pwd, pwd2) != 0){ // 修改条件判断
        printf("两次密码不一致");
        return;
    }
    if(role < 1 || role > 3){
        printf("没有这种角色");
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
        strcpy(newStaff.name, name); // 修正函数名为 strcpy
        strcpy(newStaff.pwd, pwd); // 修正函数名为 strcpy
        newStaff.role = role;
        addStaff(staffArr, staffCount, newStaff); // 修正函数参数
        printf("注册成功");
        printStaffInfo(staffArr, staffCount);
		Sleep(3000); // 延迟3秒
        loginWin(); // 注册成功后执行登录窗口方法
    } else{
        printf("注册失败");
    }
}

void modifyWin() {
    int id = 0, role = 0, i = 0, flag = 0;
	
    char name[10];
	char newPwd[10];
	    char newPwd2[10];
    paintWindow(10, 5, 60, 20);

    gotoxy(40, 7);
    printf("修改用户信息");
    gotoxy(30, 9);
    printf("输入要修改的用户名：");

    gotoxy(30, 11);
    input_check(3, 6, 1, name);

    for (i = 0; i < staffCount; i++) {
        if (strcmp(name, staffArr[i].name) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("未找到该用户！");
        return;
    }

    gotoxy(30, 13);
    printf("新密码：");

    gotoxy(40, 13);
    input_check(1, 6, 0, newPwd);

    gotoxy(30, 15);
    printf("确认新密码：");

    gotoxy(40, 15);
    input_check(1, 6, 0, newPwd2);

    if (strcmp(newPwd, newPwd2) != 0) {
        printf("两次密码不一致");
        return;
    }

    gotoxy(30, 17);
    printf("新角色：");
    gotoxy(40, 17);
    scanf("%d", &role);

    if (role < 1 || role > 3) {
        printf("无效的角色");
        return;
    }

    // 更新用户信息
    strcpy(staffArr[i].pwd, newPwd);
    staffArr[i].role = role;

    printf("用户信息修改成功");
    printStaffInfo(staffArr, staffCount);
    Sleep(3000); // 延迟3秒
    loginWin(); // 修改成功后执行登录窗口方法
}