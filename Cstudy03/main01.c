#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//使用getch完成一个用户名[字母-8位]和密码[数字-6位]的输入。
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
    printf("请输入月份");
    scanf("%d",&month);
    switch (month) {
        case 1:
        case 2:
           
        case 3:
            printf("春季");
            break;
        case 4:
        case 5:
        case 6:
            printf("夏季");
            break;
        case 7:
        case 8:
        case 9:
            printf("秋季");
            break;
        case 10:
        case 11:
        case 12:
            printf("冬季");
            break;

    }
}
void login() {
    char ch = 0;
    int i = 0;
    printf("请输入用户名\n");
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
    printf("\n请输入密码\n");
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
    printf("请输入成绩：");
    scanf("%d",&score);
    if (0<=score&&score<=100){
    if (85<=score&&score <= 100)
    {
        printf("等级A\n");

    }else if(75<=score&&score < 85)
    {
        printf("等级B\n");
    }
    else if(60<=score&&score < 75)
    {
        printf("等级C\n");
    }
    else if(score < 60)
    {
        printf("不及格\n");
    }
    }else
    {
        printf("发生了未知的错误，请重新输入成绩");
    }

}
void game()
{
    int user=0;
    fflush(stdin);
    while (1) {
        printf("请玩家出示：");
        scanf("%d", &user);
        if (user == 1 || user == 2 || user == 3) {
            int ai = rand() % 3 + 1;
            printf("玩家：");
            switch (user) {
                case 1:
                    printf("石头");
                    break;
                case 2:
                    printf("剪刀");
                    break;
                case 3:
                    printf("布");
                    break;
            }
            printf("VSai:");
            switch (ai) {
                case 1:
                    printf("石头");
                    break;
                case 2:
                    printf("剪刀");
                    break;
                case 3:
                    printf("布");
                    break;
            }
            if ((user == 1 && ai == 2) || (user == 2 && ai == 3) || (user == 3 && ai == 1))
            {
                printf("玩家赢了\n");
            } else if ((user == 1 && ai == 1) || (user == 2 && ai == 2) || (user == 3 && ai == 3))
            {
                printf("平局\n");
            } else if((ai == 1 && user == 2) || (ai == 2 && user == 3) || (ai == 3 && user == 1))
            {
                printf("ai赢了\n");
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


