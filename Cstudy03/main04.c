//
// Created by 1 on 2024/4/7.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void findMaxAndSecondMax(int num[], int size, int *max, int *secondMax)
{
    *max = (num[0] > num[1]) ? num[0] : num[1];
    *secondMax = (num[0] > num[1]) ? num[1] : num[0];

    for (int i = 2; i < size; i++)
    {
        if (num[i] > *max)
        {
            *secondMax = *max;
            *max = num[i];
        } else if (num[i] > *secondMax)
        {
            *secondMax = num[i];
        }
    }
}
int nine(int a)
{

    int left = 0;
    int right = 0;
    int res = 0;
    for(a = 1;a<=9;++a)
    {
        right = a;
        for(left = 1;left<=a;left++)
        {
            if (left != a)
            {
                printf("%d * %d",left,right);
                res = left * right;
                printf("=%d   ",res);
            } else
            {
                printf("%d * %d",a,a);
                res = a*a;
                printf("=%d\n",res);
            }
        }
    }
}
void printTable(int rows, int cols, int colWidth, int x, int y)
{
    int totalWidth = (colWidth + 1) * cols + 1; 
    int i, j;


    printf("┌");
    for (i = 0; i < cols - 1; i++)
    {
        for (j = 0; j < colWidth; j++)
        {
            printf("─");
        }
        printf("┬");
    }
    for (j = 0; j < colWidth; j++)
    {

        printf("─");
    }
    printf("┐\n");


    for (i = 0; i < rows; i++)
    {
        printf("│");
        for (j = 0; j < cols - 1; j++) {
            for (int k = 0; k < colWidth; k++)
            {
                printf(" ");
            }
            printf("│");
        }
        for (int k = 0; k < colWidth; k++)
        {
            printf(" ");
        }
        printf("│\n");
    }


    printf("└");
    for (i = 0; i < cols - 1; i++)
    {
        for (j = 0; j < colWidth; j++)
        {
            printf("─");
        }
        printf("┴");
    }
    for (j = 0; j < colWidth; j++)
    {
        printf("─");
    }
    printf("┘\n");


    for (i = 0; i < rows; i++)
    {
        printf("%d", i);
        for (j = 0; j < colWidth - 1; j++)
        {
            printf(" ");
        }
        printf("  ");
        putchar('a' + i);
        printf("\n");
    }
}
void gotoxy(int x, int y)
{
    HANDLE hOut;
    COORD pos = {x, y};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void printSnakeMap(int x, int y)
{
    char snakeMap[7][14] = {
            "□▲●★■△○□",
            "□▲●★■△○□",
            "□▲●★■△○□",
            "□▲●★■△○□",
            "□▲●★■△○□",
            "□▲●★■△○□",
            "□▲●★■△○□"
    };

    for (int i = 0; i < 7; i++)
    {
        gotoxy(x, y + i);
        printf("%s", snakeMap[i]);
    }
}

void placeFoodAndHead(int *foodX, int *foodY, int *headX, int *headY)
{
    srand(time(NULL));

    // 随机生成食物位置
    *foodX = rand() % 10; // 0 到 9 的随机数
    *foodY = rand() % 7;

    // 随机生成蛇头位置
    *headX = rand() % 10;
    *headY = rand() % 7;
}
int main()
{   int num[4], max, secondMax;
//
//    printf("请输入四个整数：\n");
//    for (int i = 0; i < 4; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    findMaxAndSecondMax(num, 4, &max, &secondMax);
//    printf("最大数：%d\n", max);
//    printf("次大数：%d\n", secondMax);
//
//    nine(9);


    int rows, cols, colWidth, posX, posY;
    printf("请输入行数：");
    scanf("%d", &rows);
    printf("请输入列数：");
    scanf("%d", &cols);
    printf("请输入列宽：");
    scanf("%d", &colWidth);
    printf("请输入列宽：");
    scanf("%d", &colWidth);
    printf("请输入表格左上角位置的 x 坐标：");
    scanf("%d", &posX);
    printf("请输入表格左上角位置的 y 坐标：");
    scanf("%d", &posY);

//    printTable(rows, cols, colWidth, posX, posY);
//    int foodX, foodY, headX, headY;
//
//    // 设置控制台窗口大小
//    system("mode con cols=30 lines=10");
//
//    placeFoodAndHead(&foodX, &foodY, &headX, &headY);
//
//    printSnakeMap(0, 0);
//
//    // 打印食物
//    gotoxy(foodX * 3 + 1, foodY + 1);
//    printf("★");
//
//    // 打印蛇头
//    gotoxy(headX * 3 + 1, headY + 1);
//    printf("■");
    return 0;
}