#include "library.h"

#include <stdio.h>
void bubbleSort()
{
    int n[10] = {25,35,68,79,21,13,98,7,16,62};
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    for(i = 1;i<10;i++)
    {
        for (j = 0;j<10-i;j++)
        {
            if(n[j]>n[j+1]) {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
        printf("第%d趟排序完成后的数据排序:\n",i);
        for (k = 0;k < 10; k++)
            printf("%-4d", n[i]);
        printf("\n");
    }
    printf("排序过后的数顺序:\n");
    for (i = 0; i < 10; i++)
        printf("%-4d", n[i]);
    printf("\n");
}


int main()
{
    bubbleSort();
}