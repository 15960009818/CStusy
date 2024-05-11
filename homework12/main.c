#include <stdio.h>
#include "Cstuaff.h"
#include "CRegWin.h"
#include "CLogin.h"
#include "Screen.h"
#include <windows.h>
int staffCount = 3;
STAFF_T staffArr[10] = {
        {1001, "admin", "123456", ADMIN},
        {1002, "manager", "123456", MANAGER},
        {1003, "waiter", "123456", WAITER}
};

int main() {
    loginWin();
    regWin();
    return 0;
}
