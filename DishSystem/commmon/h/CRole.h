//
// Created by 1 on 2024/5/5.
//

#ifndef DISHSYSTEM_CROLE_H
#define DISHSYSTEM_CROLE_H
enum role {
    ADMIN = 1,
    MANAGER,
    WAITER
};

typedef struct staff_t {
    int id;
    char name[10];
    char pwd[10];
    int role;
} STAFF_T;
void printStaffInfo(STAFF_T staffArr[],int staffCount);
#endif //DISHSYSTEM_CROLE_H
