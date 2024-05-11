#include "../controller/CLogin.h"
#include "../static/Screen.h"
#include <stdio.h>
#include "../controller/CTools.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "../controller/CStaff.h"

extern int staffCount;
extern STAFF_T staffArr[10];
const char* roleToStr(int role) {
    switch (role) {
        case ADMIN:
            return "管理员";
        case MANAGER:
            return "经理";
        case WAITER:
            return "服务员";
        default:
            return "未知";
    }
}
void usermanageWin() {
    WIN_T user = {10, 5, 60, 20}; 
    CONTROL_T title = {20, 2, 0, 0, LABEL, "人员管理"};
    CONTROL_T adduserBtn = {20, 9, 20, 3, BUTTON, "新增用户"};
    CONTROL_T getuserBtn = {20, 12, 20, 3, BUTTON, "查询用户信息"};
    CONTROL_T updateuserBtn = {20, 17, 15, 3, BUTTON, "修改用户信息"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"返回"};


    addCtrl(user.ctrlArr, &user.ctrlCount, title);
    addCtrl(user.ctrlArr, &user.ctrlCount, adduserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, getuserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, updateuserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, exitBtn);

    printf("控件个数%d\n", user.ctrlCount );
    showWin(&user); 

    winRun(&user); 

}



void queryWin() {
	    int key;
// 获取输入的员工ID
      int queryId;              
        int i;
    // 创建窗口和控件
    WIN_T queryWin = {10, 5, 80, 25};
    CONTROL_T titleLabel = {35, 2, 0, 0, LABEL, "查询页面"};
    CONTROL_T idLabel = {20, 6, 0, 0, LABEL, "请输入要查询的员工ID"};
    CONTROL_T idInput = {50, 6, 20, 3, EDIT, "", 3, 1, 6};
    CONTROL_T queryBtn = {40, 10, 15, 3, BUTTON, "查询"};
    CONTROL_T exitBtn = {40, 14, 15, 3, BUTTON, "返回"};

    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, titleLabel);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, idLabel);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, idInput);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, queryBtn);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, exitBtn);

    showWin(&queryWin);

    // 事件循环

    do {
        key = getkey(); // 获取键盘输入
        switch (key) {
            case KEY_ENTER: // 查询按钮

                sscanf(idInput.content, "%d", &queryId);


                for (i = 0; i < staffCount; i++) {
                    if (staffArr[i].id == queryId) {
                        // 显示查询结果
                        paintTable(15, 16, 1, 4, 20); // 表格
                        gotoxy(16, 17);
                        printf("ID：%d", staffArr[i].id);
                        gotoxy(36, 17);
                        printf("用户名：%s", staffArr[i].name);
                        gotoxy(56, 17);
                        printf("角色：%s", roleToStr(staffArr[i].role));
                        break;
                    }
                }
                if (i == staffCount) {
                    gotoxy(15, 16);
                    printf("未找到该员工！");
                }
                break;
            case KEY_ESC: // 返回按钮
                return;
        }
    } while (1);
}