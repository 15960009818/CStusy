#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"
//设置一个初始id
//int ID = 1001;
// 菜品结构体
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
        printf("1. 打印菜单信息\n");
        printf("2. 添加菜品\n");
        printf("3. 修改菜品\n");
        printf("4. 删除菜品\n");
        printf("5. 释放菜单\n");
        printf("请输入选项: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ID\t菜单名称\t菜品价格\t备注说明\n");
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

                printf("请输入菜品名称: ");
                scanf("%s", newMenu->name);

                printf("请输入菜品价格: ");
                scanf("%lf", &newMenu->price);

                printf("请输入菜品备注说明: ");
                scanf("%s", newMenu->info);

                newMenu->next = NULL;

                
                printf("请输入要插入的位置: ");
                scanf("%d", &pos);

                insertMenuList(menuList, pos, *newMenu);

                printf("菜单添加成功\n");
                count++;
                break;
            }
            case 3:
                printf("\n请输入id: ");
                scanf("%d", &id);
                menuToModify = getMenuInfoById(menuList, id);
                if (menuToModify != NULL) {
                    printf("输入菜品名称: ");
                    scanf("%s", menuToModify->name);
                    printf("输入菜品价格: ");
                    scanf("%f", &menuToModify->price);
                    printf("输入菜品备注说明: ");
                    scanf("%s", menuToModify->info);
                    printf("修改成功!\n");

                } else {
                    printf("id错误请重试!\n");
                }
                break;
            case 4:
                printf("\n请输入删除菜品名称 ");
                scanf("%s", name);
                deleteMenu(menuList, 1);
                printf("删除成功!\n");
                break;
            case 5:
                // 释放菜单
//                freeMenuList(menuList);
//                menuList = NULL; // 将指针设置为NULL
                printf("菜单已释放\n");
                count = 0; // 重置计数器
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("无效输入请重试\n");
        }
    } while (choice != 0);
    return 0;
}
