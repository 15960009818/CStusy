#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义用户名和密码
char names[3][10] = {"lily123", "admins", "kity123"};
char pwds[3][10] = {"123456", "123123", "111111"};

// 画框函数
void paintWindow() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
    printf("┌──────────────────────────────┐\n");
    printf("│     Orderdish     点菜系统     │\n");
    printf("├──────────────────────────────┤\n");
    printf("│   用户名：                    │\n");
    printf("│   密码：                      │\n");
    printf("├                              ┤\n");
    printf("│   1. 登录        2. 返回       │\n");
    printf("│                              │\n");
    printf("└──────────────────────────────┘\n");

    // 光标定位到用户名输入位置
    printf("\033[4;10H");
    fflush(stdout);
}

// 登录函数
int login() {
    char username[10];
    char password[10];
    int i;

    paintWindow();

    scanf("%s", username);

    // 光标定位到密码输入位置
    printf("\033[5;10H");
    fflush(stdout);
    scanf("%s", password);

    // 验证用户名和密码
    for (i = 0; i < 3; i++) {
        if (strcmp(username, names[i]) == 0 && strcmp(password, pwds[i]) == 0) {
            printf("登录成功！\n");
            return 1; // 登录成功
        }
    }

    printf("用户名或密码错误，请重试！\n");
    return 0; // 登录失败
}

// 清屏函数
void clearScreen() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
}

// 点菜系统页面函数
void orderDish() {
    printf("点菜系统页面\n");
}

// 主菜单函数
void mainMenu() {
    int choice;
    while (1) {
        paintWindow();
        printf("请选择功能:\n");
        printf("1. 点菜系统\n");
        printf("2. 退出\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                orderDish(); // 进入点菜系统页面
                break;
            case 2:
                printf("退出程序。\n");
                exit(0);
            default:
                printf("无效的选择，请重新选择。\n");
        }
    }
}

int main() {
    while (1) {
        // 登录验证
        if (login()) {
            clearScreen();
            mainMenu(); // 进入主菜单
        } else {
            printf("登录失败，请重试。\n");
        }
    }

    return 0;
}
