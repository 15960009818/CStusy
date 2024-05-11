#ifndef _SCREEN_H_
#define _SCREEN_H_

// UI窗口及控件封装
//这样返回值012就变成了值，增加可读性（其他未修改）
#define LOGINWIN 0
#define REGWIN 1
#define QUERYWIN 2
// 控件类型枚举
enum ctrltype {
    LABEL = 1,  // 标签控件
    EDIT,       // 编辑框控件
    BUTTON      // 按钮控件
};

// 控件结构体
typedef struct ctrl_t {
    int x, y;               // 控件左上角坐标
    int width, height;      // 控件宽度和高度
    enum ctrltype ctrlType; // 控件类型
    char content[20];       // 控件内容
    int inputType;          // 输入类型（例如，数字、文本）
    int mode;               // 控件模式（例如，只读、可编辑）
    int maxLen;             // 最大输入长度
    // 例如：bool visible; // 控件是否可见
    // 例如：bool enabled; // 控件是否可用
} CONTROL_T;

// 窗口结构体
typedef struct win_t {
    int x, y;           // 窗口左上角坐标
    int width, height;  // 窗口宽度和高度
    int ctrlCount;      // 控件数量
    int ctrlIndex;      // 当前焦点控件索引
    CONTROL_T ctrlArr[20]; // 控件数组
} WIN_T;


// 向控件数组中添加控件
void addCtrl(CONTROL_T *ctrlArr, int *ctrlCount, CONTROL_T ctrl);

// 显示标签控件
void showLabel(CONTROL_T ctrl);

// 显示编辑框控件
void showEdit(CONTROL_T ctrl);

// 显示按钮控件
void showButton(CONTROL_T ctrl);

// 显示窗口及其中的控件
void showWin(WIN_T *win);

/**
 * 编辑框监听器
 * @param ch 按键
 * @param ctrl 控件
 * @param str 存储字符串
 */
void editKeyListen(char ch, CONTROL_T ctrl, char str[]);

// 运行窗口事件循环
void winRun(WIN_T* winT);

#endif
