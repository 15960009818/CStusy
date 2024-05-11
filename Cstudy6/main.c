#include <stdio.h>

void drawBorder(int width, int height) {
    // 绘制顶部边框
    printf("+");
    for (int i = 0; i < width; ++i) {
        printf("-");
    }
    printf("+\n");

    // 绘制中间部分
    for (int i = 0; i < height; ++i) {
        printf("|");
        for (int j = 0; j < width; ++j) {
            printf(" ");
        }
        printf("|\n");
    }

    // 绘制底部边框
    printf("+");
    for (int i = 0; i < width; ++i) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    int width, height;

    printf("请输入矩形的宽度和高度：\n");
    scanf("%d %d", &width, &height);

    drawBorder(width, height);

    return 0;
}