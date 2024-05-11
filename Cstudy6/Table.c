#include <stdio.h>
#include <conio.h>
void drawTable(int length, int width, int cellLength, int cellWidth) {
	int i = 0;
	int j = 0;
    int k = 0;
	int l = 0;
	// 打印表格的顶部边框
    printf("+");
    for (i = 0; i < width; ++i) {
        for (j = 0; j < cellWidth; ++j)
            printf("-");
        printf("+");
    }
    printf("\n");

    // 打印表格内部的行
    for (i = 0; i < length; ++i) {
        for (j = 0; j < cellLength; ++j) {
            // 打印表格的左边框
            printf("|");
            // 打印每个单元格内部的内容，这里先简单地用空格填充
            for (k = 0; k < width; ++k) {
                for (l = 0; l < cellWidth; ++l)
                    printf(" ");
                printf("|");
            }
            printf("\n");
        }
        // 打印行与行之间的水平分隔线
        printf("+");
        for (j = 0; j < width; ++j) {
            for (k = 0; k < cellWidth; ++k)
                printf("-");
            printf("+");
        }
        printf("\n");
    }
}

int main() {
    int length, width, cellLength, cellWidth;
    
    // 获取用户输入
    printf("请输入表格的长度：");
    scanf("%d", &length);
    printf("请输入表格的宽度：");
    scanf("%d", &width);
    printf("请输入每个单元格的长度：");
    scanf("%d", &cellLength);
    printf("请输入每个单元格的宽度：");
    scanf("%d", &cellWidth);
    
    // 绘制表格
	drawTable(length, width, cellLength, cellWidth);
    printf("按下 'q' 键退出...\n");
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q')
                break;
        }
    }
    return 0;
}
