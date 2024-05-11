#ifndef _CWINDOW_H_
#define _CWINDOW_H_

// UI���ڼ��ؼ���װ

// �ؼ�����ö��
enum ctrltype {
    LABEL = 1,  // ��ǩ�ؼ�
    EDIT,       // �༭��ؼ�
    BUTTON      // ��ť�ؼ�
};

// �ؼ��ṹ��
typedef struct ctrl_t {
    int x, y;               // �ؼ����Ͻ�����
    int width, height;      // �ؼ���Ⱥ͸߶�
    enum ctrltype ctrlType; // �ؼ�����
    char content[20];       // �ؼ�����
    int inputType;          // �������ͣ����磬���֡��ı���
    int mode;               // �ؼ�ģʽ�����磬ֻ�����ɱ༭��
    int maxLen;             // ������볤��
    // ���磺bool visible; // �ؼ��Ƿ�ɼ�
    // ���磺bool enabled; // �ؼ��Ƿ����
} CONTROL_T;

// ���ڽṹ��
typedef struct win_t {
    int x, y;           // �������Ͻ�����
    int width, height;  // ���ڿ�Ⱥ͸߶�
    int ctrlCount;      // �ؼ�����
    int ctrlIndex;      // ��ǰ����ؼ�����
    CONTROL_T ctrlArr[20]; // �ؼ�����
} WIN_T;


// ��ؼ���������ӿؼ�
int addCtrl(CONTROL_T ctrlArr[20], int ctrlCount, CONTROL_T ctrl);

// ��ʾ��ǩ�ؼ�
void showLabel(CONTROL_T ctrl);

// ��ʾ�༭��ؼ�
void showEdit(CONTROL_T ctrl);

// ��ʾ��ť�ؼ�
void showButton(CONTROL_T ctrl);

// ��ʾ���ڼ����еĿؼ�
void showWin(WIN_T win);

/**
 * �༭�������
 * @param ch ����
 * @param ctrl �ؼ�
 * @param str �洢�ַ���
 */
void editKeyListen(char ch, CONTROL_T ctrl, char str[]);

// ���д����¼�ѭ��
WIN_T winRun(WIN_T winT);

#endif
