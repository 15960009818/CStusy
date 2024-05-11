//
// Created by 1 on 2024/5/5.
//

#include "h/SelectScreen.h"
#include <stdio.h>
#include "../commmon/h/CRole.h"
#include "../commmon/h/CTools.h"
#include "../commmon/h/Screen.h"
void selectScreen(){

    WIN_T sel = {10, 5, 60, 20};
    CONTROL_T title = {20,10,10,10,LABEL,"查询"};
    CONTROL_T select = {20,10,10,10,EDIT,""};
    CONTROL_T res = {30,20,10,10,LABEL,"查询结果"};
    CONTROL_T result = {30,20,10,10,EDIT,""};
    CONTROL_T exit = {50,20,10,10,BUTTON,"退出"};

    addCtrl(sel.ctrlArr, &sel.ctrlCount, title);
    addCtrl(sel.ctrlArr, &sel.ctrlCount, select);
    addCtrl(sel.ctrlArr, &sel.ctrlCount, res);
    addCtrl(sel.ctrlArr, &sel.ctrlCount, result);
    addCtrl(sel.ctrlArr, &sel.ctrlCount, exit);

    printf("控件个数%d\n", sel.ctrlCount );
    showWin(&sel);


    sel = *winRun(&sel);
    showWin(&sel);
}
