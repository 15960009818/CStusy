#include <stdio.h>
#include <string.h>
void demo(){
    static int i = 0;
    i++;
    printf("%d\n",i);
}
void demo1(){
    char input_str[10]={"01"};
    char idstr[10]={"1001"};
    if(strstr(idstr, input_str) !=NULL){
        printf("�����ɹ�:%p\n", strstr(idstr,input_str));
    } else{
        printf("ƥ��ʧ��");
    }


}
int main() {
   demo1();


}