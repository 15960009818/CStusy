//
// Created by 1 on 2024/5/8.
//
#include "Link.h"
#ifndef CSTUDY16_MENU_H
#define CSTUDY16_MENU_H
typedef struct menu_t {
    int id;
    char name[100];
    char info[100];
    int price;
} MENU_T;
void printMenuInfo(LIST_T *menuList);
#endif //CSTUDY16_MENU_H
