#ifndef _CSTAFF_H
#define _CSTAFF_H

//#define ADMIN 1
//#define MANAGER 2
//#define WAITER 3

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

void printStaffInfo(STAFF_T staffArr[], int staffCount);
int addStaff(STAFF_T staffArr[], int staffCount, STAFF_T newstaff);

#endif //CSTUDY09_CSTAFF_H
