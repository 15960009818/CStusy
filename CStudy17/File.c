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
        printf("û�ҵ��ļ����Ѵ���");
    }
    return fp;
}
void demo_open(){
    //�����ļ�ָ��
    FILE*fp = NULL;
    fp = fileopen("CMakeLists.txt");

    //�����þ���·�������·��
    //w+�����Ƿ���ڶ��Ḳ�����´�����������ھ�Ҫ��r+
    if(fp == NULL){
        printf("��ʧ��");
        exit(0);
    }
    printf("�򿪳ɹ����ļ���ַ��%p\n",fp);
}