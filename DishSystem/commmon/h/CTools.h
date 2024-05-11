//
// Created by 1 on 2024/5/3.
//

#ifndef DISHSYSTEM_CTOOLS_H
#define DISHSYSTEM_CTOOLS_H
#define KEY_UP 172
#define KEY_DOWN 180
#define KEY_LEFT 175
#define KEY_RIGHT 177
#define KEY_ENTER 13
#define KEY_ESC 27
void gotoxy(int x,int y );
void paintWindow(int startX, int startY, int width, int height);
void input_check(int inputType,int maxlen,int mode,char arr[]);
int getkey();
#endif //DISHSYSTEM_CTOOLS_H
