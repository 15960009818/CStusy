#include <stdio.h>
#include <conio.h>
void drawTable(int length, int width, int cellLength, int cellWidth) {
	int i = 0;
	int j = 0;
    int k = 0;
	int l = 0;
	// ��ӡ���Ķ����߿�
    printf("+");
    for (i = 0; i < width; ++i) {
        for (j = 0; j < cellWidth; ++j)
            printf("-");
        printf("+");
    }
    printf("\n");

    // ��ӡ����ڲ�����
    for (i = 0; i < length; ++i) {
        for (j = 0; j < cellLength; ++j) {
            // ��ӡ������߿�
            printf("|");
            // ��ӡÿ����Ԫ���ڲ������ݣ������ȼ򵥵��ÿո����
            for (k = 0; k < width; ++k) {
                for (l = 0; l < cellWidth; ++l)
                    printf(" ");
                printf("|");
            }
            printf("\n");
        }
        // ��ӡ������֮���ˮƽ�ָ���
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
    
    // ��ȡ�û�����
    printf("��������ĳ��ȣ�");
    scanf("%d", &length);
    printf("��������Ŀ�ȣ�");
    scanf("%d", &width);
    printf("������ÿ����Ԫ��ĳ��ȣ�");
    scanf("%d", &cellLength);
    printf("������ÿ����Ԫ��Ŀ�ȣ�");
    scanf("%d", &cellWidth);
    
    // ���Ʊ��
	drawTable(length, width, cellLength, cellWidth);
    printf("���� 'q' ���˳�...\n");
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q')
                break;
        }
    }
    return 0;
}
