#ifndef _CTools_
#define _CTools_
#include <stdio.h>
#include <conio.h>
#include <windows.h>


void gotoxy(int x, int y);
void drawTable(int x, int y, int width, int height);
void input_check(int inputType, int maxLen, int mode, char arr[10]);

#endif