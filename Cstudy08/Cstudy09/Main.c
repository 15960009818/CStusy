#include <stdio.h>
#include <string.h>

// 定义角色枚举类型
enum Role {
    ADMIN,
    WAITER,
    MANAGER
};

// 定义用户结构体类型
struct User {
    int id;
    char name[50];
    char password[20];
    enum Role role;
};

// 初始化用户信息
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

// 打印用户信息
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

// 注册新用户
void userAdd(struct User users[], int *size, int id, const char *name, const char *password, enum Role role) {
    users[*size].id = id;
    strcpy(users[*size].name, name);
    strcpy(users[*size].password, password);
    users[*size].role = role;
    (*size)++;
}

int main() {
    // 定义用户结构体数组
    struct User users[10];
    int size = 0; // 当前用户数

    // 初始化用户信息
    initializeUsers(users);
    size = 2; // 初始用户数为2

    // 测试打印用户信息函数
    printUserInfo(users, size);

    // 测试添加新用户函数
    userAdd(users, &size, 3, "Charlie", "pass789", MANAGER);
    printf("New user added.\n");

    // 打印更新后的用户信息
    printUserInfo(users, size);

    return 0;
}
