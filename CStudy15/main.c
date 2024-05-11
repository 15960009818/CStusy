#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"
//����һ����ʼid
//int ID = 1001;
// ��Ʒ�ṹ��
/*typedef struct Menu {
    int id;
    char name[100];
    float price;
    char info[100];
    struct Menu *next;
} MENU_T;*/

extern int ID;

int main() {
    MENU_T *menuList = menuList_init();
    int count=0;
    int choice;
    char name[100];
    int id;
    float price;
    char info[100];
	int pos;
    MENU_T *newMenu = NULL;
    MENU_T *menuToModify = NULL;
    MENU_T *newMenu1 = (MENU_T*)malloc(sizeof(MENU_T));
	MENU_T *newMenu2 = (MENU_T*)malloc(sizeof(MENU_T));
    newMenu1->id = 1001;
    strcpy(newMenu1->name, "APPLE");
    newMenu1->price = 13.0;
    strcpy(newMenu1->info, "GOOD");
    newMenu1->next = NULL;
    menuList_add(menuList, newMenu1);

    // Add the second menu item
    
    if (newMenu2 == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newMenu2->id = 1002;
    strcpy(newMenu2->name, "BANANA");
    newMenu2->price = 14.0;
    strcpy(newMenu2->info, "DELICIOUS");
    newMenu2->next = NULL;
    menuList_add(menuList, newMenu2);
    do {
        printf("\nMenu:\n");
        printf("1. ��ӡ�˵���Ϣ\n");
        printf("2. ��Ӳ�Ʒ\n");
        printf("3. �޸Ĳ�Ʒ\n");
        printf("4. ɾ����Ʒ\n");
        printf("5. �ͷŲ˵�\n");
        printf("������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ID\t�˵�����\t��Ʒ�۸�\t��ע˵��\n");
                printMenuList(menuList);
                break;
            case 2: {
                MENU_T *newMenu = (MENU_T *) malloc(sizeof(MENU_T));
                if (newMenu == NULL) {
                    printf("Memory allocation failed.\n");
                    exit(EXIT_FAILURE);
                }

                // Increment ID and assign it to the new menu item
                newMenu->id = ++ID;

                printf("�������Ʒ����: ");
                scanf("%s", newMenu->name);

                printf("�������Ʒ�۸�: ");
                scanf("%lf", &newMenu->price);

                printf("�������Ʒ��ע˵��: ");
                scanf("%s", newMenu->info);

                newMenu->next = NULL;

                
                printf("������Ҫ�����λ��: ");
                scanf("%d", &pos);

                insertMenuList(menuList, pos, *newMenu);

                printf("�˵���ӳɹ�\n");
                count++;
                break;
            }
            case 3:
                printf("\n������id: ");
                scanf("%d", &id);
                menuToModify = getMenuInfoById(menuList, id);
                if (menuToModify != NULL) {
                    printf("�����Ʒ����: ");
                    scanf("%s", menuToModify->name);
                    printf("�����Ʒ�۸�: ");
                    scanf("%f", &menuToModify->price);
                    printf("�����Ʒ��ע˵��: ");
                    scanf("%s", menuToModify->info);
                    printf("�޸ĳɹ�!\n");

                } else {
                    printf("id����������!\n");
                }
                break;
            case 4:
                printf("\n������ɾ����Ʒ���� ");
                scanf("%s", name);
                deleteMenu(menuList, 1);
                printf("ɾ���ɹ�!\n");
                break;
            case 5:
                // �ͷŲ˵�
//                freeMenuList(menuList);
//                menuList = NULL; // ��ָ������ΪNULL
                printf("�˵����ͷ�\n");
                count = 0; // ���ü�����
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("��Ч����������\n");
        }
    } while (choice != 0);
    return 0;
}
