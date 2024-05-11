#include <stdio.h>
#include <string.h>

// �����ɫö������
enum Role {
    ADMIN,
    WAITER,
    MANAGER
};

// �����û��ṹ������
struct User {
    int id;
    char name[50];
    char password[20];
    enum Role role;
};

// ��ʼ���û���Ϣ
void initializeUsers(struct User users[]) {
    users[0].id = 1;
    strcpy(users[0].name, "Alice");
    strcpy(users[0].password, "pass123");
    users[0].role = ADMIN;

    users[1].id = 2;
    strcpy(users[1].name, "Bob");
    strcpy(users[1].password, "pass456");
    users[1].role = WAITER;
}

// ��ӡ�û���Ϣ
void printUserInfo(struct User users[], int size) {
		int i =0;
    printf("User Information:\n");

    for (i = 0; i < size; ++i) {
        printf("User %d:\n", i + 1);
        printf("ID: %d\n", users[i].id);
        printf("Name: %s\n", users[i].name);
        printf("Role: ");
        switch (users[i].role) {
            case ADMIN:
                printf("Admin\n");
                break;
            case WAITER:
                printf("Waiter\n");
                break;
            case MANAGER:
                printf("Manager\n");
                break;
        }
        printf("\n");
    }
}

// ע�����û�
void userAdd(struct User users[], int *size, int id, const char *name, const char *password, enum Role role) {
    users[*size].id = id;
    strcpy(users[*size].name, name);
    strcpy(users[*size].password, password);
    users[*size].role = role;
    (*size)++;
}

int main() {
    // �����û��ṹ������
    struct User users[10];
    int size = 0; // ��ǰ�û���

    // ��ʼ���û���Ϣ
    initializeUsers(users);
    size = 2; // ��ʼ�û���Ϊ2

    // ���Դ�ӡ�û���Ϣ����
    printUserInfo(users, size);

    // ����������û�����
    userAdd(users, &size, 3, "Charlie", "pass789", MANAGER);
    printf("New user added.\n");

    // ��ӡ���º���û���Ϣ
    printUserInfo(users, size);

    return 0;
}
