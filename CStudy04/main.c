#include <stdio.h>
void array(){
    int array[5] = {0};
    int i = 0;
//    for (i = 0;i<sizeof (array)/sizeof (array[i] );i++){
    printf("������ǰ�����\n");

//    }

    for (i = 0;i<sizeof (array)/sizeof (int );i++){
        scanf("%d",&array[i]);
        printf("arr[%d] is %d\n",i,array[i]);
    }
}

void arrayFind(){
    int array[5] = {1,2,3,4,5};
    int i = 0;
    int num = 0 ,flag = 0;
    printf("��������ҵ�Ԫ��");
    scanf("%d",&num);
    for (i = 0;i<5;i++){
        if(array[i] == num){
            printf("�ҵ���Ԫ���±�%d\n",i);
            break;
        }
    }
    if(flag == 0)
    {
        printf("����������\n");
    }
    if(i==5){
        printf("����������\n");
    }
}
int main() {
    printf("Hello, World!\n");
    array();
//arrayFind();
    return 0;
}
