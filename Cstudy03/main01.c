#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//ʹ��getch���һ���û���[��ĸ-8λ]������[����-6λ]�����롣
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
void demo_for()
{
    int i = 0;
    int sum = 0;
    for(i = 1; i < 11; ++i)
	{
        sum+=1;

    }
    printf("sum is : %d\n",sum);
}
void season(){
    int month = 0;
    printf("�������·�");
    scanf("%d",&month);
    switch (month) {
        case 1:
        case 2:
           
        case 3:
            printf("����");
            break;
        case 4:
        case 5:
        case 6:
            printf("�ļ�");
            break;
        case 7:
        case 8:
        case 9:
            printf("�＾");
            break;
        case 10:
        case 11:
        case 12:
            printf("����");
            break;

    }
}
void login() {
    char ch = 0;
    int i = 0;
    printf("�������û���\n");
    while (1) {
        ch = getch();
        if (i < 6 && (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            putch(ch);
            i++;
        } else if (ch == 'b' && i > 0) {
            printf("\b \b");
        } else if (i == 8 || (ch == '\r' && i >= 6)) {
            break;
        }
    }
    printf("\n����������\n");
    {
        while (1) {
            ch = getch();
            if (i < 6 && (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                putch('*');
                i++;
            } else if (ch == 'b' && i > 0) {
                printf("\b \b");
            } else if (i == 8 || (ch == '\r' && i >= 6)) {
                break;
            }
        }


    }
}
void exam()
{
    int score = 0;
    printf("������ɼ���");
    scanf("%d",&score);
    if (0<=score&&score<=100){
    if (85<=score&&score <= 100)
    {
        printf("�ȼ�A\n");

    }else if(75<=score&&score < 85)
    {
        printf("�ȼ�B\n");
    }
    else if(60<=score&&score < 75)
    {
        printf("�ȼ�C\n");
    }
    else if(score < 60)
    {
        printf("������\n");
    }
    }else
    {
        printf("������δ֪�Ĵ�������������ɼ�");
    }

}
void game()
{
    int user=0;
    fflush(stdin);
    while (1) {
        printf("����ҳ�ʾ��");
        scanf("%d", &user);
        if (user == 1 || user == 2 || user == 3) {
            int ai = rand() % 3 + 1;
            printf("��ң�");
            switch (user) {
                case 1:
                    printf("ʯͷ");
                    break;
                case 2:
                    printf("����");
                    break;
                case 3:
                    printf("��");
                    break;
            }
            printf("VSai:");
            switch (ai) {
                case 1:
                    printf("ʯͷ");
                    break;
                case 2:
                    printf("����");
                    break;
                case 3:
                    printf("��");
                    break;
            }
            if ((user == 1 && ai == 2) || (user == 2 && ai == 3) || (user == 3 && ai == 1))
            {
                printf("���Ӯ��\n");
            } else if ((user == 1 && ai == 1) || (user == 2 && ai == 2) || (user == 3 && ai == 3))
            {
                printf("ƽ��\n");
            } else if((ai == 1 && user == 2) || (ai == 2 && user == 3) || (ai == 3 && user == 1))
            {
                printf("aiӮ��\n");
            }
        }
    }
}
int main(){
//    login();
//    exam();
//   season();
//   demo_for();
    drawRectangle(10,60);
    }


