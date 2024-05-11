#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ID = 0;
// 定义菜品结构体
typedef struct {
    int id;
    char name[50];
    char info[100];
    float price;
} MENU_T;

// 定义链表节点结构体
typedef struct list_node {
    void *data;
    struct list_node *next;
} LIST_T;

// 文件操作函数，如果文件不存在则创建，存在则读取
FILE *file_open(char *fname) {
    FILE *fp = fopen(fname, "r+");
    if (fp == NULL) {
        fp = fopen(fname, "w+");
        printf("文件不存在，已创建\n");
    }
    return fp;
}

// 初始化链表
LIST_T *list_init() {
    LIST_T *head = (LIST_T *)malloc(sizeof(LIST_T));
    if (head == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    memset(head, 0, sizeof(LIST_T));
    head->next = NULL;
    return head;
}

// 向链表中添加节点
void list_add(LIST_T *head, void *data) {
    LIST_T *newNode = (LIST_T *)malloc(sizeof(LIST_T));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    LIST_T *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 释放链表内存
void list_free(LIST_T *head) {
    LIST_T *current = head->next;
    while (current != NULL) {
        LIST_T *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(head);
}

// 写入菜单数据到文件
void write_menu_to_file(LIST_T *menu_list, char *filename) {
    FILE *fp = file_open(filename);
    if (fp == NULL) {
        printf("文件打开失败\n");
        exit(EXIT_FAILURE);
    }

    LIST_T *current = menu_list->next;
    while (current != NULL) {
        MENU_T *menu = (MENU_T *)current->data;
        fwrite(menu, sizeof(MENU_T), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

// 从文件读取菜单数据到链表
void read_menu_from_file(LIST_T *menu_list, char *filename) {
    FILE *fp = file_open(filename);
    if (fp == NULL) {
        printf("文件打开失败\n");
        exit(EXIT_FAILURE);
    }

    MENU_T *menu = (MENU_T *)malloc(sizeof(MENU_T));
    while (fread(menu, sizeof(MENU_T), 1, fp) > 0) {
        MENU_T *new_menu = (MENU_T *)malloc(sizeof(MENU_T));
        if (new_menu == NULL) {
            printf("内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new_menu, menu, sizeof(MENU_T));
        list_add(menu_list, new_menu);
        menu = (MENU_T *)malloc(sizeof(MENU_T));
    }

    fclose(fp);
    free(menu);
}

// 添加菜品
void add_menu(LIST_T *menu_list, MENU_T *menu) {
    menu->id = ++ID; // Assuming ID is a global variable
    list_add(menu_list, menu);
}

// 删除菜品
void delete_menu(LIST_T *menu_list, int id) {
    LIST_T *prev = menu_list;
    LIST_T *current = menu_list->next;
    while (current != NULL) {
        MENU_T *menu = (MENU_T *)current->data;
        if (menu->id == id) {
            prev->next = current->next;
            free(menu);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("菜品未找到\n");
}

// 修改菜品信息
void modify_menu(LIST_T *menu_list, int id, char *name, char *info, float price) {
    LIST_T *current = menu_list->next;
    while (current != NULL) {
        MENU_T *menu = (MENU_T *)current->data;
        if (menu->id == id) {
            strcpy(menu->name, name);
            strcpy(menu->info, info);
            menu->price = price;
            return;
        }
        current = current->next;
    }
    printf("菜品未找到\n");
}

// 打印菜单信息
void print_menu_info(LIST_T *menu_list) {
    LIST_T *current = menu_list->next;
    printf("菜单信息：\n");
    while (current != NULL) {
        MENU_T *menu = (MENU_T *)current->data;
        printf("ID: %d, 名称: %s, 描述: %s, 价格: %.2f\n", menu->id, menu->name, menu->info, menu->price);
        current = current->next;
    }
}

int main() {
    LIST_T *menu_list = list_init();

    // 从文件中读取菜单数据到链表
    read_menu_from_file(menu_list, "menu.txt");

    // 添加菜品
    MENU_T *menu1 = (MENU_T *)malloc(sizeof(MENU_T));
    strcpy(menu1->name, "鸡肉");
    strcpy(menu1->info, "好吃");
    menu1->price = 9.99;
    add_menu(menu_list, menu1);

    // 删除菜品
    delete_menu(menu_list, 1001);

    // 修改菜品信息
    modify_menu(menu_list, 1002, "牛肉", "香甜", 12.99);

    // 打印菜单信息
    print_menu_info(menu_list);

    // 将菜单数据写入文件
    write_menu_to_file(menu_list, "menu.txt");

    // 释放链表内存
    list_free(menu_list);

    return 0;
}
