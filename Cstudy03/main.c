//
// Created by 1 on 2024/4/6.
//
#include <stdio.h>
#include <math.h>
#include <conio.h>

// 交换两个整数
void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 四舍五入保留n位小数
double roundDecimal(double num, int n) {
    double multiplier = pow(10.0, n);
    return round(num * multiplier) / multiplier;
}

// 计算三角形的周长
double calculatePerimeter(double a, double b, double c) {
    return a + b + c;
}

// 计算三角形的面积
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// 计算总分和平均分
void calculateTotalAndAverage(int scores[], int numSubjects, int *total, float *average) {
    *total = 0;
    for (int i = 0; i < numSubjects; i++) {
        *total += scores[i];
    }
    *average = (float)(*total) / numSubjects;
}

// 字符大小写转换
char convertCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return (ch - 'a' + 4) % 26 + 'A';
    } else if (ch >= 'A' && ch <= 'Z') {
        return (ch - 'A' + 22) % 26 + 'a';
    } else {
        return ch;
    }
}
// 绘制矩形框
void drawRectangle(int rows, int cols) {
    int i, j;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            if ((i == 1 && j == 1) || (i == 1 && j == cols) || (i == rows && j == 1) || (i == rows && j == cols))
                printf("┌");
            else if (i == 1 && j != 1 && j != cols)
                printf("─");
            else if (i == rows && j != 1 && j != cols)
                printf("─");
            else if (j == 1 && i != 1 && i != rows)
                printf("│");
            else if (j == cols && i != 1 && i != rows)
                printf("│");
            else if (i == 1 && j == cols)
                printf("┐");
            else if (i == rows && j == 1)
                printf("└");
            else if (i == rows && j == cols)
                printf("┘");
            else
                printf(" ");
        }
        printf("\n");
    }
}
// 获取用户名和密码
void getUsernameAndPassword(char *username, char *password) {
    printf("请输入用户名（8位字母）: ");
    scanf("%s", username);
    printf("请输入密码（6位数字）: ");
    scanf("%s", password);
}
int main() {
//    // 1. 输入两个整数并交换
//    int num1, num2;
//    printf("请输入两个整数：");
//    scanf("%d %d", &num1, &num2);
//    printf("输入的两个整数为：%d %d\n", num1, num2);
//    swapIntegers(&num1, &num2);
//    printf("交换后的两个整数为：%d %d\n\n", num1, num2);
//
//    // 2. 输入一个double类型数据并保留n位小数
//    double doubleNum;
//    int n;
//    printf("请输入一个double类型数据和需要保留的小数位数：");
//    scanf("%lf %d", &doubleNum, &n);
//    printf("保留 %d 位小数后的结果为：%.lf\n\n", n, roundDecimal(doubleNum, n));
//
//    // 3. 计算三角形的周长和面积
//    double side1, side2, side3;
//    printf("请输入三角形的三条边长：");
//    scanf("%lf %lf %lf", &side1, &side2, &side3);
//    double perimeter = calculatePerimeter(side1, side2, side3);
//    double area = calculateArea(side1, side2, side3);
//    printf("三角形的周长为：%.2lf\n", perimeter);
//    printf("三角形的面积为：%.3lf\n\n", area);
//
//    // 4. 计算总分和平均分
//    int scores[5];
//    int totalScore;
//    float averageScore;
//    printf("请输入五门学科的成绩（整数）：");
//    for (int i = 0; i < 5; i++) {
//        scanf("%d", &scores[i]);
//    }
//    calculateTotalAndAverage(scores, 5, &totalScore, &averageScore);
//    printf("总分为：%d\n", totalScore);
//    printf("平均分为：%.1f\n\n", averageScore);

    // 5. 字符大小写转换
   // char ch;
   // printf("请输入一个字符：");
   // scanf(" %c", &ch); // 注意空格
  //  printf("转换后的结果为：%c\n", convertCase(ch));
// 画一个10行10列的矩形框
    drawRectangle(10, 10);

    char username[9]; // 8位字母 + '\0'
    char password[7]; // 6位数字 + '\0'

    // 获取用户名和密码
 //   getUsernameAndPassword(username, password);

 //   printf("用户名: %s\n", username);
 //   printf("密码: %s\n", password);

 //   getch(); // 等待用户按下任意键退出
    return 0;
}
