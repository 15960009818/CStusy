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
        printf("ËÑË÷³É¹¦:%p\n", strstr(idstr,input_str));
    } else{
        printf("Æ¥ÅäÊ§°Ü");
    }


}
int main() {
   demo1();


}