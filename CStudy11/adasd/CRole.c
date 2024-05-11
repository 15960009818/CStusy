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
            return "����Ա";
        case MANAGER:
            return "����";
        case WAITER:
            return "����Ա";
        default:
            return "δ֪";
    }
}
void usermanageWin() {
    WIN_T user = {10, 5, 60, 20}; 
    CONTROL_T title = {20, 2, 0, 0, LABEL, "��Ա����"};
    CONTROL_T adduserBtn = {20, 9, 20, 3, BUTTON, "�����û�"};
    CONTROL_T getuserBtn = {20, 12, 20, 3, BUTTON, "��ѯ�û���Ϣ"};
    CONTROL_T updateuserBtn = {20, 17, 15, 3, BUTTON, "�޸��û���Ϣ"};
    CONTROL_T exitBtn = {40,17,15,3,BUTTON,"����"};


    addCtrl(user.ctrlArr, &user.ctrlCount, title);
    addCtrl(user.ctrlArr, &user.ctrlCount, adduserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, getuserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, updateuserBtn);
    addCtrl(user.ctrlArr, &user.ctrlCount, exitBtn);

    printf("�ؼ�����%d\n", user.ctrlCount );
    showWin(&user); 

    winRun(&user); 

}



void queryWin() {
	    int key;
// ��ȡ�����Ա��ID
      int queryId;              
        int i;
    // �������ںͿؼ�
    WIN_T queryWin = {10, 5, 80, 25};
    CONTROL_T titleLabel = {35, 2, 0, 0, LABEL, "��ѯҳ��"};
    CONTROL_T idLabel = {20, 6, 0, 0, LABEL, "������Ҫ��ѯ��Ա��ID"};
    CONTROL_T idInput = {50, 6, 20, 3, EDIT, "", 3, 1, 6};
    CONTROL_T queryBtn = {40, 10, 15, 3, BUTTON, "��ѯ"};
    CONTROL_T exitBtn = {40, 14, 15, 3, BUTTON, "����"};

    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, titleLabel);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, idLabel);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, idInput);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, queryBtn);
    addCtrl(queryWin.ctrlArr, &queryWin.ctrlCount, exitBtn);

    showWin(&queryWin);

    // �¼�ѭ��

    do {
        key = getkey(); // ��ȡ��������
        switch (key) {
            case KEY_ENTER: // ��ѯ��ť

                sscanf(idInput.content, "%d", &queryId);


                for (i = 0; i < staffCount; i++) {
                    if (staffArr[i].id == queryId) {
                        // ��ʾ��ѯ���
                        paintTable(15, 16, 1, 4, 20); // ���
                        gotoxy(16, 17);
                        printf("ID��%d", staffArr[i].id);
                        gotoxy(36, 17);
                        printf("�û�����%s", staffArr[i].name);
                        gotoxy(56, 17);
                        printf("��ɫ��%s", roleToStr(staffArr[i].role));
                        break;
                    }
                }
                if (i == staffCount) {
                    gotoxy(15, 16);
                    printf("δ�ҵ���Ա����");
                }
                break;
            case KEY_ESC: // ���ذ�ť
                return;
        }
    } while (1);
}