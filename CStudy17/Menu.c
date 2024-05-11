//
// Created by 1 on 2024/5/8.
//

#include <stdlib.h>
#include "Menu.h"
#include "Link.h"
void printMenuInfo(LIST_T *menuList){
    LIST_T *current = menuList;
    MENU_T *menu = NULL;
    while (current->next!=NULL){
        current = current->next;
        //强制转换成结构体指针类型
        menu=(MENU_T*)current->data;
        menu = (MENU_T*) malloc(sizeof (MENU_T));

    }
}