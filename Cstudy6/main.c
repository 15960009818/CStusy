#include <stdio.h>

void drawBorder(int width, int height) {
    // ���ƶ����߿�
    printf("+");
    for (int i = 0; i < width; ++i) {
        printf("-");
    }
    printf("+\n");

    // �����м䲿��
    for (int i = 0; i < height; ++i) {
        printf("|");
        for (int j = 0; j < width; ++j) {
            printf(" ");
        }
        printf("|\n");
    }

    // ���Ƶײ��߿�
    printf("+");
    for (int i = 0; i < width; ++i) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    int width, height;

    printf("��������εĿ�Ⱥ͸߶ȣ�\n");
    scanf("%d %d", &width, &height);

    drawBorder(width, height);

    return 0;
}