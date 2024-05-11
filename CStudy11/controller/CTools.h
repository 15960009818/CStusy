//
// Created by 1 on 2024/4/23.
//

#ifndef _CTOOLS_H
#define _CTOOLS_H
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

void gotoxy(int ,int );

void paintWindow(int startX,int startY,int width,int height);

void input_check(int inputType,int maxlen,int mode,char arr[]);

//void paintTbale(int x,int y,int row,int col,int col_width);

int getkey();
#endif //CSTUDY09_CTOOLS_H
