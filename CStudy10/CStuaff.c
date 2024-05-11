//
// Created by 1 on 2024/4/23.
//
#include "CStuaff.h"
#include <stdio.h>
void printStaffInfo(STAFF_T staffArr[],int staffCount){
    int i = 0;
    printf("id\tname\tpwd\trole\n");
    for (i = 0;i<staffCount;i++){
        printf("%d\t%s\t%s\t",staffArr[i].id;staffArr[i].pwd);
        switch (staffArr[i],role) {
            case ADMIN:
                printf("管理员\n");
                break;
            case MANAGER:
                printf("经理\n");
                break;
            case WAITER:
                printf("服务员\n");
                break;
        }
    }
}
int addStaff(STAFF_T staffArr[],int staffCount,STAFF_T newstaff){
    staffArr[staffCount] = newstaff;
    staffCount++;
    return staffCount;
}
