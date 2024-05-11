#include <stdio.h>
void myswap(int *a,int *b){
    int temp = 0;
    temp = *a;//复制a地址里的值给temp，下面同理
    *a = *b;
    *b = temp;
}
void point_arr(){
    char name[10]="admin";
    char *p = name;
//    char *n = "admin"; 这跟上面的不一样，一个是字符数组，一个是地址是常量，是不能修改的
    printf("%s  %p\n",name,&name);
    printf("%s\n",p);
    //获取下标字符
    printf("%c  %p\n",name[1],&name[1]);
    printf("%c  %p\n",*(p+1),p+1);
    //元素访问
    //1.数组下标
//    2.指针+偏移量


}
int main() {
//    int num = 10;
//    int numa=10;
//    int numb=20;
//    int *pnum = &num;
//    int *pnuma = &numa;
//    int *pnumb = &numb;
//    printf("交换前numa = %d   numb=%d\n",numa,numb);
//
//    myswap(&numa,&numb);
//    printf("直接访问交换后numa = %d   numb=%d\n",numa,numb);
//    myswap(pnuma,pnumb);
//    printf("间接访问交换后numa = %d   numb=%d\n",numa,numb);
//
//    //间接访问法,定义一个指针变量，定义另一个变量地址
//
//    printf("num = %d,pos = %p\n",num,&num);
//    //修改地址对应的值
//    *pnum = 100;
//    printf("num = %d,pos = %p\n",num,&num);
//    printf("Hello, World!\n");
point_arr();
    return 0;
}
