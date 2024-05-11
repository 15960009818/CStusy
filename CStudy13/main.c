#include <stdio.h>

typedef struct USER_T{
    int id;
    char username[10];
    char password[10];
 
}USER_T;

void demo1(){
    int i = 0;
    int j=0;
    int nums[3][4] = {
            1,2,3,4,
            5,6,7,8,
            9,10,11,12
    };
    for (i = 0; i <3 ; i++) {

    for (j = 0;  j<4 ; j++) {
//        printf("num[%d][%d]=%d\t\n",i,j,nums[i][j]);
//        printf("num[%d][%d]=%d\t\n",i,j,*(nums[i]+j));//num[i]每一行的首地址
//        printf("num[%d][%d]=%d\t\n",i,j,*(nums+1)[j]);
//        printf("num[%d][%d]=%d\t\n",i,j,*((*nums+1)+j));
        printf("num[%d][%d]=%d\t\n",i,j,*(&nums[0][0]+i*4+j));


    }
}
}
void demo2(){
    int i = 0;
    int j=0;
    int nums[3][4] = {
            1,2,3,4,
            5,6,7,8,
            9,10,11,12
    };
    int (*pt)[4] = nums;
//    取第四个元素
    printf("%d\n",(*(pt+1))[3]);



}
void demo3(){
    int i = 0;
    char str[10]="apple";
//    用sizeof计算空间
    char strs[3][10]={"hello","world","apple"};
    char *pstr = str;
    //指针数组 元素：char *：指针
    char *pstrs[3] = {"hello","world","apple"};//3*4=12字节
    for (i = 0; i <3 ;i ++) {
        printf("%s\n", pstrs[i]);
    }
}
void demo4(){
    //结构体指针
    USER_T user={1001,"admin","123456"};
    USER_T userArr[3]={{1001,"admin","123456"},
                       {1002,"user","password"}};
    USER_T *puser = &user;
    USER_T *parr = &userArr;
//    printf("name=%s pwd=%s",user.username,user.password)
//    printf("name=%s pwd=%s",puser->username,puser->password)
    printf("name=%s pwd=%s\n",(*(parr+1)).username,(*(parr+1)).password);
    printf("name=%s pwd=%s\n",(parr+1)->username,(parr+1)->password);
}
int sum(int a,int b){
    return a+b;
}
void demo05(){
    int res = 0;
    int (*fun)(int a,int b) = sum;
    int (*funs[4])(int a,int b)={sum};
    int option = 0;
    while (1){
        scanf("%d",&option);
        funs[option-1](10,20);
        printf("res=%d\n",res);
    }
}
int main() {
    printf("Hello, World!\n");
//    demo1();
//    demo2();
//demo3();
//demo4();
demo05();
    return 0;
}
