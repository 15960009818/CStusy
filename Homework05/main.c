#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �����û���������
char names[3][10] = {"lily123", "admins", "kity123"};
char pwds[3][10] = {"123456", "123123", "111111"};

// ������
void paintWindow() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
    printf("����������������������������������������������������������������\n");
    printf("��     Orderdish     ���ϵͳ     ��\n");
    printf("����������������������������������������������������������������\n");
    printf("��   �û�����                    ��\n");
    printf("��   ���룺                      ��\n");
    printf("��                              ��\n");
    printf("��   1. ��¼        2. ����       ��\n");
    printf("��                              ��\n");
    printf("����������������������������������������������������������������\n");

    // ��궨λ���û�������λ��
    printf("\033[4;10H");
    fflush(stdout);
}

// ��¼����
int login() {
    char username[10];
    char password[10];
    int i;

    paintWindow();

    scanf("%s", username);

    // ��궨λ����������λ��
    printf("\033[5;10H");
    fflush(stdout);
    scanf("%s", password);

    // ��֤�û���������
    for (i = 0; i < 3; i++) {
        if (strcmp(username, names[i]) == 0 && strcmp(password, pwds[i]) == 0) {
            printf("��¼�ɹ���\n");
            return 1; // ��¼�ɹ�
        }
    }

    printf("�û�����������������ԣ�\n");
    return 0; // ��¼ʧ��
}

// ��������
void clearScreen() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
}

// ���ϵͳҳ�溯��
void orderDish() {
    printf("���ϵͳҳ��\n");
}

// ���˵�����
void mainMenu() {
    int choice;
    while (1) {
        paintWindow();
        printf("��ѡ����:\n");
        printf("1. ���ϵͳ\n");
        printf("2. �˳�\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                orderDish(); // ������ϵͳҳ��
                break;
            case 2:
                printf("�˳�����\n");
                exit(0);
            default:
                printf("��Ч��ѡ��������ѡ��\n");
        }
    }
}

int main() {
    while (1) {
        // ��¼��֤
        if (login()) {
            clearScreen();
            mainMenu(); // �������˵�
        } else {
            printf("��¼ʧ�ܣ������ԡ�\n");
        }
    }

    return 0;
}
