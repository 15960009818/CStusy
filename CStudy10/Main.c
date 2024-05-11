#include <stdio.h>
#include "CStaff.h"
#include "CRegWin.h"
#include "CLogin.h"
#include <windows.h>
int staffCount = 3;
STAFF_T staffArr[10] = {
        {1001, "admin", "123456", ADMIN},
        {1002, "manager", "123456", MANAGER},
        {1003, "waiter", "123456", WAITER}
};

int main() {
    regWin();
    return 0;
}
