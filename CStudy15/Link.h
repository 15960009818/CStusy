#ifndef _LINK_
#define _LINK_

typedef struct Menu {
    int id;
    char name[100];
    float price;
    char info[100];
    struct Menu *next;
} MENU_T;

MENU_T* menuList_init();
void menuList_add(MENU_T *head, MENU_T *menu);
int getListCount(MENU_T *head);
MENU_T* getMenuInfoByName(MENU_T *head, char *name);
MENU_T* getMenuInfoById(MENU_T *head, int id);
MENU_T* getMenuInfoByPos(MENU_T *head, int pos);
void deleteMenu(MENU_T *head, int pos);
void printMenuList(MENU_T *head);
void insertMenuList(MENU_T *head,int pos,MENU_T menu);
void freeMenuList(MENU_T * head);
void modifyMenu(MENU_T *menu, int id, char *name, float price, char *info);
#endif