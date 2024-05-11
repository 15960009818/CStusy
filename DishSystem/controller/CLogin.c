//
// Created by 1 on 2024/5/3.
//

#include "h/CLogin.h"
#include "../commmon/h/CTools.h"
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
void login(){
    UserInfo user;

    system("cls"); // 清屏

    // 绘制登录窗口
    paintWindow(20, 5, 40, 10);

    // 绘制用户名输入框
    gotoxy(25, 7);
    printf("Username: ");
    input_check(2, 10, 1, user.username);

    // 绘制密码输入框
    gotoxy(25, 9);
    printf("Password: ");
    input_check(3, 10, 0, user.password);

    // 绘制登录按钮
    gotoxy(30, 12);
    printf("Press ENTER to login");

    // 等待用户按下ENTER键
    while (getkey() != KEY_ENTER);
}
