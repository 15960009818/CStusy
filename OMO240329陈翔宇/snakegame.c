#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
//#include <synchapi.h>

#define MAP_WIDTH 20	//1-18
#define MAP_HEIGHT 20	//1-18

// 蛇身位置
int snake[100][2] = {{10, 10}, {10, 11}};
int snakeLength = 2;

// 食物位置
int food[2] = {0, 0};

// 将光标移动到指定位置
void  gotoxy(int x,int y)//形参
{
    HANDLE hOut;
	COORD pos= {x,y};                          
// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos); 
//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
// 绘制背景地图
void drawMap() {
    
    int i, j,k,isSnakeBody;
	system("cls"); // 清屏
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
			isSnakeBody = 0;
			for (k = 1; k < snakeLength; k++) {
                if (snake[k][0] == i && snake[k][1] == j) {
                    isSnakeBody = 1;
                    break;
                }
            }
            if (isSnakeBody) {
				gotoxy(j*2, i);
                printf("■"); // 绘制蛇身
            } else if (snake[0][0] == i && snake[0][1] == j) {
				gotoxy(j*2, i);
                printf("★"); // 绘制蛇头
            } else if (food[0] == i && food[1] == j) {
				gotoxy(j*2, i);
                printf("▲"); // 绘制食物
            } else {
				if (i == 0 || i == MAP_HEIGHT - 1 || j == 0) {
					printf("□"); // 绘制墙壁
				} 		
				else if(j == MAP_WIDTH - 1)
				{
					gotoxy((MAP_WIDTH - 1)*2, i);
					printf("□");
				}
				else
				{
					printf(" "); // 绘制空地
				}
            }     
        }
        printf("\n");
    }
}

// 随机生成蛇头和食物的初始位置
void generateRandomPositions() {
    srand(time(NULL));
    // 蛇头位置
    snake[0][0] = rand() % (MAP_HEIGHT - 2) + 1;	//1-18
    snake[0][1] = rand() % (MAP_WIDTH - 2) + 1;		//1-18
    // 食物位置
    food[0] = rand() % (MAP_HEIGHT - 2) + 1;
    food[1] = rand() % (MAP_WIDTH - 2) + 1;
}



int main() {
	  int i;
    char direction = 'd'; // 初始方向向右
	// 移动蛇身
    
    drawMap();
    generateRandomPositions();

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

        // 检测蛇是否吃到食物
        if (snake[0][0] == food[0] && snake[0][1] == food[1]) {
            // 增加蛇身长度
            snakeLength++;
            // 生成新的食物位置
            food[0] = rand() % (MAP_HEIGHT - 2) + 1;
            food[1] = rand() % (MAP_WIDTH - 2) + 1;
        }

        // 检测蛇是否撞到墙壁或自己的身体
        if (snake[0][0] == 0 || snake[0][0] == MAP_HEIGHT - 1 ||
            snake[0][1] == 0 || snake[0][1] == MAP_WIDTH - 1) {
            printf("\n游戏结束！蛇撞到墙壁！\n");
            break;
        }
      
        for (i = 1; i < snakeLength; i++) {
            if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
                printf("\n游戏结束！蛇撞到自己的身体！\n");
                return 0;
            }
        }

        
       
        for (i = snakeLength; i >0; i--) {//    [0,1] [0,2] [0,3]    
            snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
        }

        // 绘制地图
        drawMap();

        // 延迟一段时间
        Sleep(500); // 每100毫秒更新一次

    }

    return 0;
}

