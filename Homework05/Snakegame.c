#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

// 蛇身位置
int snake[100][2] = {{10, 10}, {10, 11}};
int snakeLength = 2;

// 食物位置
int food[2] = {0, 0};

// 绘制背景地图
void drawMap() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                printf("□"); // 绘制墙壁
            } else {
                printf(" "); // 绘制空地
            }
        }
        printf("\n");
    }
}

// 随机生成蛇头和食物的初始位置
void generateRandomPositions() {
    srand(time(NULL));
    // 蛇头位置
    snake[0][0] = rand() % (MAP_HEIGHT - 2) + 1;
    snake[0][1] = rand() % (MAP_WIDTH - 2) + 1;
    // 食物位置
    food[0] = rand() % (MAP_HEIGHT - 2) + 1;
    food[1] = rand() % (MAP_WIDTH - 2) + 1;
}

// 将光标移动到指定位置
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
    fflush(stdout);
}

int main() {
    char direction = 'd'; // 初始方向向右
    int i;
    drawMap();
    generateRandomPositions();
    gotoxy(snake[0][0], snake[0][1]);
    printf("★"); // 打印蛇头
    gotoxy(food[0], food[1]);
    printf("▲"); // 打印食物

    while (1) {
        if (_kbhit()) { // 判断是否有按键按下
            direction = _getch(); // 获取按下的键盘字符
        }

        // 根据按键更新蛇头位置
        switch (direction) {
            case 'w':
                snake[0][0]--;
                break;
            case 's':
                snake[0][0]++;
                break;
            case 'a':
                snake[0][1]--;
                break;
            case 'd':
                snake[0][1]++;
                break;
        }

        // 如果蛇头吃到食物
        if (snake[0][0] == food[0] && snake[0][1] == food[1]) {
            // 增加蛇身长度
            snakeLength++;
            // 生成新的食物位置
            food[0] = rand() % (MAP_HEIGHT - 2) + 1;
            food[1] = rand() % (MAP_WIDTH - 2) + 1;
        }

        // 打印蛇头和食物
        drawMap();
        gotoxy(snake[0][0], snake[0][1]);
        printf("★"); // 打印蛇头
        gotoxy(food[0], food[1]);
        printf("▲"); // 打印食物

        // 延迟一段时间
        for (i = 0; i < 100000000; i++);
    }

    return 0;
}
