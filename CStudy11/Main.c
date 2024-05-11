#include <stdio.h>
#include "controller/CStaff.h"
#include "controller/CRegWin.h"
#include "controller/CLogin.h"
#include "static/Screen.h"
#include <windows.h>
#include "CRole.h"
int staffCount = 3;
STAFF_T staffArr[10] = {
        {1001, "admin", "123456", ADMIN},
        {1002, "manager", "123456", MANAGER},
        {1003, "waiter", "123456", WAITER}
};

int main() {
    loginWin();
    regWin();
	modifyWin();
	usermanageWin();
	queryWin();
    return 0;
	/*int (*funs[10]()={
		loginWin,
			regWin,
		queryWin(),
	};

	int winIndex = 1;
	while(1)
	{
		switch(winIndex){
		case -1:
			winIndex = loginWin();
			break;
		default:
			break;
		}
	}*/
	return 0;
}
