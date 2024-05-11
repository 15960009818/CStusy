//
// Created by 1 on 2024/4/6.
//
#include <stdio.h>
#include <math.h>
#include <conio.h>

// ������������
void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �������뱣��nλС��
double roundDecimal(double num, int n) {
    double multiplier = pow(10.0, n);
    return round(num * multiplier) / multiplier;
}

// ���������ε��ܳ�
double calculatePerimeter(double a, double b, double c) {
    return a + b + c;
}

// ���������ε����
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// �����ֺܷ�ƽ����
void calculateTotalAndAverage(int scores[], int numSubjects, int *total, float *average) {
    *total = 0;
    for (int i = 0; i < numSubjects; i++) {
        *total += scores[i];
    }
    *average = (float)(*total) / numSubjects;
}

// �ַ���Сдת��
char convertCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return (ch - 'a' + 4) % 26 + 'A';
    } else if (ch >= 'A' && ch <= 'Z') {
        return (ch - 'A' + 22) % 26 + 'a';
    } else {
        return ch;
    }
}
// ���ƾ��ο�
void drawRectangle(int rows, int cols) {
    int i, j;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            if ((i == 1 && j == 1) || (i == 1 && j == cols) || (i == rows && j == 1) || (i == rows && j == cols))
                printf("��");
            else if (i == 1 && j != 1 && j != cols)
                printf("��");
            else if (i == rows && j != 1 && j != cols)
                printf("��");
            else if (j == 1 && i != 1 && i != rows)
                printf("��");
            else if (j == cols && i != 1 && i != rows)
                printf("��");
            else if (i == 1 && j == cols)
                printf("��");
            else if (i == rows && j == 1)
                printf("��");
            else if (i == rows && j == cols)
                printf("��");
            else
                printf(" ");
        }
        printf("\n");
    }
}
// ��ȡ�û���������
void getUsernameAndPassword(char *username, char *password) {
    printf("�������û�����8λ��ĸ��: ");
    scanf("%s", username);
    printf("���������루6λ���֣�: ");
    scanf("%s", password);
}
int main() {
//    // 1. ������������������
//    int num1, num2;
//    printf("����������������");
//    scanf("%d %d", &num1, &num2);
//    printf("�������������Ϊ��%d %d\n", num1, num2);
//    swapIntegers(&num1, &num2);
//    printf("���������������Ϊ��%d %d\n\n", num1, num2);
//
//    // 2. ����һ��double�������ݲ�����nλС��
//    double doubleNum;
//    int n;
//    printf("������һ��double�������ݺ���Ҫ������С��λ����");
//    scanf("%lf %d", &doubleNum, &n);
//    printf("���� %d λС����Ľ��Ϊ��%.lf\n\n", n, roundDecimal(doubleNum, n));
//
//    // 3. ���������ε��ܳ������
//    double side1, side2, side3;
//    printf("�����������ε������߳���");
//    scanf("%lf %lf %lf", &side1, &side2, &side3);
//    double perimeter = calculatePerimeter(side1, side2, side3);
//    double area = calculateArea(side1, side2, side3);
//    printf("�����ε��ܳ�Ϊ��%.2lf\n", perimeter);
//    printf("�����ε����Ϊ��%.3lf\n\n", area);
//
//    // 4. �����ֺܷ�ƽ����
//    int scores[5];
//    int totalScore;
//    float averageScore;
//    printf("����������ѧ�Ƶĳɼ�����������");
//    for (int i = 0; i < 5; i++) {
//        scanf("%d", &scores[i]);
//    }
//    calculateTotalAndAverage(scores, 5, &totalScore, &averageScore);
//    printf("�ܷ�Ϊ��%d\n", totalScore);
//    printf("ƽ����Ϊ��%.1f\n\n", averageScore);

    // 5. �ַ���Сдת��
   // char ch;
   // printf("������һ���ַ���");
   // scanf(" %c", &ch); // ע��ո�
  //  printf("ת����Ľ��Ϊ��%c\n", convertCase(ch));
// ��һ��10��10�еľ��ο�
    drawRectangle(10, 10);

    char username[9]; // 8λ��ĸ + '\0'
    char password[7]; // 6λ���� + '\0'

    // ��ȡ�û���������
 //   getUsernameAndPassword(username, password);

 //   printf("�û���: %s\n", username);
 //   printf("����: %s\n", password);

 //   getch(); // �ȴ��û�����������˳�
    return 0;
}
