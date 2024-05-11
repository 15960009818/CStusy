#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
//#include <synchapi.h>

#define MAP_WIDTH 20	//1-18
#define MAP_HEIGHT 20	//1-18

// ����λ��
int snake[100][2] = {{10, 10}, {10, 11}};
int snakeLength = 2;

// ʳ��λ��
int food[2] = {0, 0};

// ������ƶ���ָ��λ��
void  gotoxy(int x,int y)//�β�
{
    HANDLE hOut;
	COORD pos= {x,y};                          
// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos); 
//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}
// ���Ʊ�����ͼ
void drawMap() {
    
    int i, j,k,isSnakeBody;
	system("cls"); // ����
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
                printf("��"); // ��������
            } else if (snake[0][0] == i && snake[0][1] == j) {
				gotoxy(j*2, i);
                printf("��"); // ������ͷ
            } else if (food[0] == i && food[1] == j) {
				gotoxy(j*2, i);
                printf("��"); // ����ʳ��
            } else {
				if (i == 0 || i == MAP_HEIGHT - 1 || j == 0) {
					printf("��"); // ����ǽ��
				} 		
				else if(j == MAP_WIDTH - 1)
				{
					gotoxy((MAP_WIDTH - 1)*2, i);
					printf("��");
				}
				else
				{
					printf(" "); // ���ƿյ�
				}
            }     
        }
        printf("\n");
    }
}

// ���������ͷ��ʳ��ĳ�ʼλ��
void generateRandomPositions() {
    srand(time(NULL));
    // ��ͷλ��
    snake[0][0] = rand() % (MAP_HEIGHT - 2) + 1;	//1-18
    snake[0][1] = rand() % (MAP_WIDTH - 2) + 1;		//1-18
    // ʳ��λ��
    food[0] = rand() % (MAP_HEIGHT - 2) + 1;
    food[1] = rand() % (MAP_WIDTH - 2) + 1;
}



int main() {
	  int i;
    char direction = 'd'; // ��ʼ��������
	// �ƶ�����
    
    drawMap();
    generateRandomPositions();

    while (1) {
        if (_kbhit()) { // �ж��Ƿ��а�������
            direction = _getch(); // ��ȡ���µļ����ַ�
        }

        // ���ݰ���������ͷλ��
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

        // ������Ƿ�Ե�ʳ��
        if (snake[0][0] == food[0] && snake[0][1] == food[1]) {
            // ����������
            snakeLength++;
            // �����µ�ʳ��λ��
            food[0] = rand() % (MAP_HEIGHT - 2) + 1;
            food[1] = rand() % (MAP_WIDTH - 2) + 1;
        }

        // ������Ƿ�ײ��ǽ�ڻ��Լ�������
        if (snake[0][0] == 0 || snake[0][0] == MAP_HEIGHT - 1 ||
            snake[0][1] == 0 || snake[0][1] == MAP_WIDTH - 1) {
            printf("\n��Ϸ��������ײ��ǽ�ڣ�\n");
            break;
        }
      
        for (i = 1; i < snakeLength; i++) {
            if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
                printf("\n��Ϸ��������ײ���Լ������壡\n");
                return 0;
            }
        }

        
       
        for (i = snakeLength; i >0; i--) {//    [0,1] [0,2] [0,3]    
            snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
        }

        // ���Ƶ�ͼ
        drawMap();

        // �ӳ�һ��ʱ��
        Sleep(500); // ÿ100�������һ��

    }

    return 0;
}

