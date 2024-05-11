#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

// ����λ��
int snake[100][2] = {{10, 10}, {10, 11}};
int snakeLength = 2;

// ʳ��λ��
int food[2] = {0, 0};

// ���Ʊ�����ͼ
void drawMap() {
    system("clear"); // For Unix/Linux
    //system("cls"); // For Windows
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                printf("��"); // ����ǽ��
            } else {
                printf(" "); // ���ƿյ�
            }
        }
        printf("\n");
    }
}

// ���������ͷ��ʳ��ĳ�ʼλ��
void generateRandomPositions() {
    srand(time(NULL));
    // ��ͷλ��
    snake[0][0] = rand() % (MAP_HEIGHT - 2) + 1;
    snake[0][1] = rand() % (MAP_WIDTH - 2) + 1;
    // ʳ��λ��
    food[0] = rand() % (MAP_HEIGHT - 2) + 1;
    food[1] = rand() % (MAP_WIDTH - 2) + 1;
}

// ������ƶ���ָ��λ��
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
    fflush(stdout);
}

int main() {
    char direction = 'd'; // ��ʼ��������
    int i;
    drawMap();
    generateRandomPositions();
    gotoxy(snake[0][0], snake[0][1]);
    printf("��"); // ��ӡ��ͷ
    gotoxy(food[0], food[1]);
    printf("��"); // ��ӡʳ��

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

        // �����ͷ�Ե�ʳ��
        if (snake[0][0] == food[0] && snake[0][1] == food[1]) {
            // ����������
            snakeLength++;
            // �����µ�ʳ��λ��
            food[0] = rand() % (MAP_HEIGHT - 2) + 1;
            food[1] = rand() % (MAP_WIDTH - 2) + 1;
        }

        // ��ӡ��ͷ��ʳ��
        drawMap();
        gotoxy(snake[0][0], snake[0][1]);
        printf("��"); // ��ӡ��ͷ
        gotoxy(food[0], food[1]);
        printf("��"); // ��ӡʳ��

        // �ӳ�һ��ʱ��
        for (i = 0; i < 100000000; i++);
    }

    return 0;
}
