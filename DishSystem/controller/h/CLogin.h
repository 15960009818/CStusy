//
// Created by 1 on 2024/5/3.
//

#ifndef DISHSYSTEM_CLOGIN_H
#define DISHSYSTEM_CLOGIN_H
enum role {
    ADMIN = 1,
    MANAGER,
    WAITER
};

typedef struct user {
    int id;
    char username[10];
    char password[10];
    int role;
} UserInfo;
void login();
#endif //DISHSYSTEM_CLOGIN_H
