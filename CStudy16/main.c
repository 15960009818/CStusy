#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Link.h"
#include "Menu.h"
extern int ID;
int main() {
    LIST_T *menu_list = list_init();


    MENU_T *menu1 = (MENU_T*)malloc(sizeof(MENU_T));
    menu1->id = ID++;
    strcpy(menu1->name, "Chicken");
    menu1->price = 9.99;
    strcpy(menu1->info, "delicious");
    list_add(menu_list, menu1);

    MENU_T *menu2 = (MENU_T*)malloc(sizeof(MENU_T));
    menu2->id = ID++;
    strcpy(menu2->name, "Vegetable");
    menu2->price = 8.49;
    strcpy(menu2->info, "good");
    list_add(menu_list, menu2);



    list_free(menu_list);

    return 0;
}
