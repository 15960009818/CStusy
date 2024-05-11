#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "File.h"
#include "Link.h"
#include "Menu.h"

void demo_open();
void demo_write();
void demo_read();
void demo_ftell();
LIST_T * menuList =NULL;
int main() {
   demo_open();
    demo_write();
    demo_read();
    demo_ftell();
    return 0;
}
void demo_write(){
    int i = 0;
    MENU_T menu[3] ={ {1001,"apple", "good",18},
    };

    MENU_T menu1 = {1004,"test","test",21};
    FILE * fp = NULL;
    fp = fileopen("abc.txt");
    if(fp == NULL) {
        printf("文件打开失败");
        exit(0);
    }
    printf("地址：%p\n",fp);
    //文件指针
    //第二个是偏移量，整数向右偏移负数向左偏移
    fseek(fp,sizeof (MENU_T),0);
    
        fwrite(&menu, sizeof(MENU_T), 1, fp);
    
    fclose(fp);
}
void demo_read(){
    FILE * fp = NULL;
    MENU_T m = {0};
    MENU_T *pmenu = (MENU_T*) malloc(sizeof (MENU_T));
    LIST_T * menuList = list_init();
    fp = fileopen("abc.txt");
    if(fp == NULL) {
        printf("文件打开失败");
        exit(0);
    }
    printf("地址：%p\n",fp);
    fseek(fp,0,SEEK_SET);
    //读取文件
    while (fread(pmenu,sizeof (MENU_T),1,fp)>0){
        printf("%d %s %s %d\n ",pmenu->id,pmenu->name,pmenu->info,pmenu->price);
        list_add(menuList,pmenu);
        pmenu = (MENU_T*) malloc(sizeof (MENU_T));
        if(pmenu == NULL) exit(0);
    }
    printMenuInfo(menuList);
    fclose(fp);
}
void demo_ftell(){//创建文件指针
    FILE*fp = NULL;
    int num = 0;
    fp = fileopen("abc.txt");

    //可以用绝对路径或相对路径
    //w+无论是否存在都会覆盖重新创建，如果存在就要用r+
    if(fp == NULL){
        printf("打开失败");
        exit(0);
    }
    fseek(fp,0,SEEK_END);
    num = ftell(fp);
    printf("size = %d\n",num);
    fclose(fp);
}