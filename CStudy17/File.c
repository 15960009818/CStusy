//
// Created by 1 on 2024/5/11.
//

#include "File.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
FILE * fileopen(char *fname){
    FILE * fp = fopen(fname,"r+");
    if(fp == NULL){
        fp = fopen(fname,"w+");
        printf("没找到文件，已创建");
    }
    return fp;
}
void demo_open(){
    //创建文件指针
    FILE*fp = NULL;
    fp = fileopen("CMakeLists.txt");

    //可以用绝对路径或相对路径
    //w+无论是否存在都会覆盖重新创建，如果存在就要用r+
    if(fp == NULL){
        printf("打开失败");
        exit(0);
    }
    printf("打开成功，文件地址：%p\n",fp);
}