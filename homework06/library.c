#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define SNAKE_MAX_LENGTH (WIDTH * HEIGHT)

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Position {
    int x;
    int y;
};

struct Snake {
    struct Position body[SNAKE_MAX_LENGTH];
    int length;
    enum Direction direction;
};

struct Position food;

void initialize(struct Snake *snake) {
    snake->length = 1;
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
    snake->direction = RIGHT;

    srand(time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

void draw(struct Snake *snake) {
    system("cls"); // 清屏

    // 绘制蛇头
    printf("+");
    for (int i = 1; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");

    // 绘制蛇身和食物
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            int isSnakeBody = 0;
            for (int i = 0; i < snake->length; i++) {
                if (snake->body[i].x == x && snake->body[i].y == y) {
                    printf("0");
                    isSnakeBody = 1;
                    break;
                }
            }
            if (!isSnakeBody && food.x == x && food.y == y) {
                printf("*");
            } else if (!isSnakeBody) {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // 绘制底部
    printf("+");
    for (int i = 1; i < WIDTH; i++) {
        printf("-");
    }
    printf("+\n");
}

void update(struct Snake *snake) {
    // 移动蛇身
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    // 根据方向移动蛇头
    switch (snake->direction) {
        case UP:
            snake->body[0].y -= 1;
            break;
        case DOWN:
            snake->body[0].y += 1;
            break;
        case LEFT:
            snake->body[0].x -= 1;
            break;
        case RIGHT:
            snake->body[0].x += 1;
            break;
    }

    // 检查是否吃到食物
    if (snake->body[0].x == food.x && snake->body[0].y == food.y) {
        snake->length++;
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    }
}

int main() {
    struct Snake snake;
    char input;

    initialize(&snake);

    while (1) {
        if (_kbhit()) { // 检测键盘输入
            input = _getch();
            switch (input) {
                case 'w':
                    if (snake.direction != DOWN)
                        snake.direction = UP;
                    break;
                case 's':
                    if (snake.direction != UP)
                        snake.direction = DOWN;
                    break;
                case 'a':
                    if (snake.direction != RIGHT)
                        snake.direction = LEFT;
                    break;
                case 'd':
                    if (snake.direction != LEFT)
                        snake.direction = RIGHT;
                    break;
                case 'x':
                    exit(0);
            }
        }

        update(&snake);
        draw(&snake);

        // 延时，控制游戏速度
        _sleep(100);
    }

    return 0;
}
