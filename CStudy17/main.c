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
        printf("�ļ���ʧ��");
        exit(0);
    }
    printf("��ַ��%p\n",fp);
    //�ļ�ָ��
    //�ڶ�����ƫ��������������ƫ�Ƹ�������ƫ��
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
        printf("�ļ���ʧ��");
        exit(0);
    }
    printf("��ַ��%p\n",fp);
    fseek(fp,0,SEEK_SET);
    //��ȡ�ļ�
    while (fread(pmenu,sizeof (MENU_T),1,fp)>0){
        printf("%d %s %s %d\n ",pmenu->id,pmenu->name,pmenu->info,pmenu->price);
        list_add(menuList,pmenu);
        pmenu = (MENU_T*) malloc(sizeof (MENU_T));
        if(pmenu == NULL) exit(0);
    }
    printMenuInfo(menuList);
    fclose(fp);
}
void demo_ftell(){//�����ļ�ָ��
    FILE*fp = NULL;
    int num = 0;
    fp = fileopen("abc.txt");

    //�����þ���·�������·��
    //w+�����Ƿ���ڶ��Ḳ�����´�����������ھ�Ҫ��r+
    if(fp == NULL){
        printf("��ʧ��");
        exit(0);
    }
    fseek(fp,0,SEEK_END);
    num = ftell(fp);
    printf("size = %d\n",num);
    fclose(fp);
}