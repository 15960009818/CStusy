#ifndef _CWINDOW_H_
#define _CWINDOW_H_

// UI窗口及控件封装
enum ctrltype {
    LABEL = 1,
    EDIT,
    BUTTON
};

// 控件结构体
typedef struct ctrl_t {
    int x, y, width, height;
    enum ctrltype ctrlType;
    char content[20];
    int inputType;
    int mode;
    int maxLen;
    // 例如：bool visible; // 控件是否可见
    // 例如：bool enabled; // 控件是否可用
} CONTROL_T;

// 窗口结构体
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
