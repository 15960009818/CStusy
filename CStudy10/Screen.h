#ifndef _CWINDOW_H_
#define _CWINDOW_H_

// UI���ڼ��ؼ���װ
enum ctrltype {
    LABEL = 1,
    EDIT,
    BUTTON
};

// �ؼ��ṹ��
typedef struct ctrl_t {
    int x, y, width, height;
    enum ctrltype ctrlType;
    char content[20];
    int inputType;
    int mode;
    int maxLen;
    // ���磺bool visible; // �ؼ��Ƿ�ɼ�
    // ���磺bool enabled; // �ؼ��Ƿ����
} CONTROL_T;

// ���ڽṹ��
typedef struct win_t {
    int x, y, width, height;
	int ctrlCount;
	CONTROL_T ctrlArr[20];
} WIN_T;


int addCtrl(CONTROL_T ctrlArr[20], int ctrlCount, CONTROL_T ctrl);

void showLabel(CONTROL_T ctrl);
void showEdit(CONTROL_T ctrl);
void showButton(CONTROL_T ctrl);
void showWin(WIN_T win);
void winRun
#endif
