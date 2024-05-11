#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ID = 0;
// �����Ʒ�ṹ��
typedef struct {
    int id;
    char name[50];
    char info[100];
    float price;
} MENU_T;

// ��������ڵ�ṹ��
typedef struct list_node {
    void *data;
    struct list_node *next;
} LIST_T;

// �ļ���������������ļ��������򴴽����������ȡ
FILE *file_open(char *fname) {
    FILE *fp = fopen(fname, "r+");
    if (fp == NULL) {
        fp = fopen(fname, "w+");
        printf("�ļ������ڣ��Ѵ���\n");
    }
    return fp;
}

// ��ʼ������
LIST_T *list_init() {
    LIST_T *head = (LIST_T *)malloc(sizeof(LIST_T));
    if (head == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    memset(head, 0, sizeof(LIST_T));
    head->next = NULL;
    return head;
}

// ����������ӽڵ�
void list_add(LIST_T *head, void *data) {
    LIST_T *newNode = (LIST_T *)malloc(sizeof(LIST_T));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
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

// �ͷ������ڴ�
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

// д��˵����ݵ��ļ�
void write_menu_to_file(LIST_T *menu_list, char *filename) {
    FILE *fp = file_open(filename);
    if (fp == NULL) {
        printf("�ļ���ʧ��\n");
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

// ���ļ���ȡ�˵����ݵ�����
void read_menu_from_file(LIST_T *menu_list, char *filename) {
    FILE *fp = file_open(filename);
    if (fp == NULL) {
        printf("�ļ���ʧ��\n");
        exit(EXIT_FAILURE);
    }

    MENU_T *menu = (MENU_T *)malloc(sizeof(MENU_T));
    while (fread(menu, sizeof(MENU_T), 1, fp) > 0) {
        MENU_T *new_menu = (MENU_T *)malloc(sizeof(MENU_T));
        if (new_menu == NULL) {
            printf("�ڴ����ʧ��\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new_menu, menu, sizeof(MENU_T));
        list_add(menu_list, new_menu);
        menu = (MENU_T *)malloc(sizeof(MENU_T));
    }

    fclose(fp);
    free(menu);
}

// ��Ӳ�Ʒ
void add_menu(LIST_T *menu_list, MENU_T *menu) {
    menu->id = ++ID; // Assuming ID is a global variable
    list_add(menu_list, menu);
}

// ɾ����Ʒ
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
    printf("��Ʒδ�ҵ�\n");
}

// �޸Ĳ�Ʒ��Ϣ
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
    printf("��Ʒδ�ҵ�\n");
}

// ��ӡ�˵���Ϣ
void print_menu_info(LIST_T *menu_list) {
    LIST_T *current = menu_list->next;
    printf("�˵���Ϣ��\n");
    while (current != NULL) {
        MENU_T *menu = (MENU_T *)current->data;
        printf("ID: %d, ����: %s, ����: %s, �۸�: %.2f\n", menu->id, menu->name, menu->info, menu->price);
        current = current->next;
    }
}

int main() {
    LIST_T *menu_list = list_init();

    // ���ļ��ж�ȡ�˵����ݵ�����
    read_menu_from_file(menu_list, "menu.txt");

    // ��Ӳ�Ʒ
    MENU_T *menu1 = (MENU_T *)malloc(sizeof(MENU_T));
    strcpy(menu1->name, "����");
    strcpy(menu1->info, "�ó�");
    menu1->price = 9.99;
    add_menu(menu_list, menu1);

    // ɾ����Ʒ
    delete_menu(menu_list, 1001);

    // �޸Ĳ�Ʒ��Ϣ
    modify_menu(menu_list, 1002, "ţ��", "����", 12.99);

    // ��ӡ�˵���Ϣ
    print_menu_info(menu_list);

    // ���˵�����д���ļ�
    write_menu_to_file(menu_list, "menu.txt");

    // �ͷ������ڴ�
    list_free(menu_list);

    return 0;
}
