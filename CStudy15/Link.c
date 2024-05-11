#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Link.h"


int ID = 1001;
// 初始化链表
MENU_T* menuList_init() {
     MENU_T *head = (MENU_T*) malloc(sizeof (MENU_T));
    if(head == NULL){
        printf("error");
        exit(0);

    }
    memset(head,0,sizeof (MENU_T));
    head ->next = NULL;
    return head;
}
//void menuList_append(MENU_T *head,MENU_T *menu){
//    MENU_T *temp = (MENU_T*) malloc(sizeof (MENU_T));
//    if(head == NULL){
//        printf("error");
//        exit(0);
//
//    }
//    memset(head,0,sizeof (MENU_T));
//    head ->next = NULL;
//    return head;
//}
/**
 * 添加菜品到链表末尾
 * @param head  头节点
 * @param menu  菜单信息
 * @updatetime 2024.5.7
 * @author xiangjun
 */
// 添加菜品到链表末尾
void menuList_add(MENU_T *head, MENU_T *menu) {
    menu->id = ID++;

    if (head == NULL) {
        head = menu;
    } else {
        MENU_T *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = menu;
    }
}
/**
 * 统计节点个数
 * @param head 头节点
 * @return count 节点数量
 * @updatetime 2024.5.7
 * @author xiangjun
 */
// 统计节点个数
int getListCount(MENU_T *head) {
    int count = 0;
    MENU_T *current = head;
    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
/**
 * 根据名称获取菜品信息
 * @param head   头节点
 * @param name  菜品名字
 * @return
 */
// 根据名称获取菜品信息
MENU_T* getMenuInfoByName(MENU_T *head, char *name) {
    MENU_T *current = head;
    while (current != NULL) {
        current = current->next;
        if (strcmp(current->name, name) == 0) {
            return current;
        }

    }
    return NULL;
}

// 根据ID获取菜品信息
MENU_T* getMenuInfoById(MENU_T *head, int id) {
    MENU_T *current = head;
    while (current->next != NULL) {
		 current = current->next;
        if (current->id == id) {
            return current;
        }
        
    }
    return NULL;
}

// 根据位置获取菜品信息
MENU_T* getMenuInfoByPos(MENU_T *head, int pos) {
    MENU_T *current = head;
    int count = 0;
    while (current != NULL) {

        current = current->next;
//        头节点算0所以先往下再+1
        count++;
        if (count == pos) {
            return current;
        }

    }
    return NULL;
}
/**
 * 删除菜品
 * @param head 头节点
 * @param name 菜品名称
 * @updatetime 2024.5.7
 * @author xiangjun
 * * @updatetime 2024.5.8
 * @author xiangjun
 */
// 删除菜品
void deleteMenu(MENU_T *head, int pos) {
    int count = 0;
    MENU_T *pre = head,*current = head->next;
    while (current != NULL) {
        count++;
        if(pos == count){
        pre->next = current->next;
            free(current);
            return;
        }
    }


        /*while (current->next != NULL) {
            if (strcmp(current->name, name) == 0) {
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }*/
}
/**
 * 插入节点,尾插法
 * @param head 头节点
 * @param pos   节点
 * @param menu 菜单内容
 * @updatetime 2024.5.7
 * @author xiangjun
 */
void insertMenuList(MENU_T *head,int pos,MENU_T menu){
    MENU_T *current = head,*newNode=NULL;
    int count = 0;
    while (current->next!=NULL){
        current = current->next;
        count++;
        if(count == pos-1){
            newNode=(MENU_T *) malloc(sizeof (MENU_T));
            if(newNode == NULL){
                printf("creat error");
                exit(0);
            }
            memset(newNode,0,sizeof (MENU_T));

            memcpy(newNode,&menu,sizeof (MENU_T));
            newNode->next = current->next;
            current->next = newNode;
            return;

        }
    }
}
void freeMenuList(MENU_T *head) {
    MENU_T *current = head;
    while (current != NULL) {
        head = head->next;

        free(current);
    }
    printf("释放成功");
}
// 打印菜品链表
// 打印菜品链表
void printMenuList(MENU_T *head) {
    MENU_T *current = head;

    while (current != NULL) {
        printf("%d\t%s\t%.2lf\t%s\n", current->id, current->name, current->price, current->info);
        current = current->next;
    }
}


// 修改菜品信息
void modifyMenu(MENU_T *menu, int id, char *name, float price, char *info) {
    menu->id = id;
    strcpy(menu->name, name);
    menu->price = price;
    strcpy(menu->info, info);
}
