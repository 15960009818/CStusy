#include <stdio.h>
void myswap(int *a,int *b){
    int temp = 0;
    temp = *a;//����a��ַ���ֵ��temp������ͬ��
    *a = *b;
    *b = temp;
}
void point_arr(){
    char name[10]="admin";
    char *p = name;
//    char *n = "admin"; �������Ĳ�һ����һ�����ַ����飬һ���ǵ�ַ�ǳ������ǲ����޸ĵ�
    printf("%s  %p\n",name,&name);
    printf("%s\n",p);
    //��ȡ�±��ַ�
    printf("%c  %p\n",name[1],&name[1]);
    printf("%c  %p\n",*(p+1),p+1);
    //Ԫ�ط���
    //1.�����±�
//    2.ָ��+ƫ����


}
int main() {
//    int num = 10;
//    int numa=10;
//    int numb=20;
//    int *pnum = &num;
//    int *pnuma = &numa;
//    int *pnumb = &numb;
//    printf("����ǰnuma = %d   numb=%d\n",numa,numb);
//
//    myswap(&numa,&numb);
//    printf("ֱ�ӷ��ʽ�����numa = %d   numb=%d\n",numa,numb);
//    myswap(pnuma,pnumb);
//    printf("��ӷ��ʽ�����numa = %d   numb=%d\n",numa,numb);
//
//    //��ӷ��ʷ�,����һ��ָ�������������һ��������ַ
//
//    printf("num = %d,pos = %p\n",num,&num);
//    //�޸ĵ�ַ��Ӧ��ֵ
//    *pnum = 100;
//    printf("num = %d,pos = %p\n",num,&num);
//    printf("Hello, World!\n");
point_arr();
    return 0;
}
