#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "commmon/h/Screen.h"

#include "commmon/h/CRole.h"
#include "commmon/h/CRole.h"
#include "commmon/h/CTools.h"
#include "commmon/h/Screen.h"
#include "Screen/h/SelectScreen.h"
int staffCount = 3;
STAFF_T staffArr[10] = {
        {1001, "admin", "123456", ADMIN},
        {1002, "manager", "123456", MANAGER},
        {1003, "waiter", "123456", WAITER}
};
typedef struct menu_t{
    int menu_id;
    char name[20];
    char info[20];
    double price;

}MENU_T;
typedef struct menut{
    int menu_id;
    char name[20];
    char info[20];
    double price;
    struct menut *pnext;//指针域
}CMENU_T;
//链表初始化,头节点
CMENU_T *list_init();
CMENU_T *list_init(){
    CMENU_T *head = (CMENU_T*) malloc(sizeof (CMENU_T));
    if(head == NULL){
        printf("error");

    }
    memset(head,0,sizeof (CMENU_T));
    head ->pnext = NULL;
    return head;
}
//追加节点
CMENU_T *addlist();
CMENU_T *addlist(CMENU_T *head, CMENU_T menu) {
    CMENU_T *ptemp = head;
    CMENU_T *newNode = (CMENU_T*)malloc(sizeof(CMENU_T));

    if (newNode == NULL) {
        printf("Memory allocation failed");

    }

    // Copy data from menu to newNode
    memcpy(newNode, &menu, sizeof(CMENU_T));
    newNode->pnext = NULL;

    // If the list is empty, make newNode the head
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse the list to the last node
    while (ptemp->pnext != NULL) {
        ptemp = ptemp->pnext;
    }

    // Append newNode to the end of the list
    ptemp->pnext = newNode;

    return head;
}
void printlist(CMENU_T *head) {
	    int count = 0;
		    CMENU_T *ptemp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }




    printf("Menu ID\tName\tInfo\tPrice\n");
    printf("---------------------------------\n");

    // Traverse the list and print each node's data
    while (ptemp != NULL) {
        printf("%d\t%s\t%s\t%.2lf\n", ptemp->menu_id, ptemp->name, ptemp->info, ptemp->price);
        ptemp = ptemp->pnext;
    }
}

int getNodePos(CMENU_T *head,int pose){
    int count = 0;
    CMENU_T * ptemp = head, * newcode = NULL;
    while (ptemp->pnext !=NULL){
        ptemp = ptemp->pnext;
        count++;
        if(count==pose){
            return pose;
        }

    }
    return count;
}
//遍历节点
void demo_malloc();
void demo_malloc1();
int main() {
//        demo_malloc1();
//        demo_malloc();
//    selectScreen();
    CMENU_T *menuT = list_init();
    CMENU_T menu1 = {1001, "milk", "nice", 18.5};
    CMENU_T menu2 = {1002,"rice","nice",18.5};
    addlist(menuT,menu1);
    addlist(menuT,menu2);
//    printf("%p\n",menuT);
//    printf("head is %p",menuT);
    printlist(menuT);
    return 0;
    /*int (*funs[10]()={
        loginWin,
            regWin,
        queryWin(),
    };

    int winIndex = 1;
    while(1)
    {
        switch(winIndex){
        case -1:
            winIndex = loginWin();
            break;
        default:
            break;
        }
    }*/
    return 0;
}
void demo_malloc(){
    int *p=NULL;
    p=(int *) malloc(sizeof (int ));
    if(p==NULL){
        printf("开辟失败");

    }
    *p=10;
    printf("p地址： %p  value=%d\n",p,*p);
}
//开辟空间步骤1.malloc/calloc2.if判定释放成功3.初始化memset4.空间释放
void demo_malloc1(){

    //强制转换  堆区
    MENU_T *pmenu = (MENU_T *)malloc(sizeof (MENU_T));
    //看是否开辟成功
    if(pmenu == NULL){
        printf("OPEN SPACE ERROR\n");

    }
    //内存初始化
    memset(pmenu,0,sizeof (MENU_T));
    //指针使用
    pmenu->menu_id= 1001;
    strcpy(pmenu->name,"noddle");
    strcpy(pmenu->info,"ok");
    pmenu->price = 18.5;

    printf("id: %d   name: %s\n   info:%s  price:%lf\n",pmenu->menu_id,pmenu->name,pmenu->info,pmenu->price);
    (pmenu+1)->menu_id= 1002;
    strcpy((pmenu+1)->name,"apple");
    strcpy((pmenu+1)->info,"nok");
    (pmenu+1)->price = 1.5;
    printf("id: %d   name: %s\n   info:%s  price:%lf\n",(pmenu+1)->menu_id,(pmenu+1)->name,(pmenu+1)->info,(pmenu+1)->price);

    //空间释放
//    free(pmenu);
    //realloc指定内存空间第二个参数为0等价于free，除了pmenu其他都释放了
    realloc(pmenu,0);
    printf("id: %d   name: %s\n   info:%s  price:%lf\n",pmenu->menu_id,pmenu->name,pmenu->info,pmenu->price);


}
