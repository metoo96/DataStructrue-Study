#include <stdio.h>
#include <stdlib.h>
/**
*���� ð������
*���� Guozhu Zhu
*ʱ�� 2017/11/18
*/
int main()
{
    int arr[] = {1, 2, 5, 3, 2, 7, 1, 4, 7, 8, 5, 4, 10 , 22, 44, 88};
    int i, j, k, l,temp;
    //����ѭ��n-1��
    for (i = 0; i < 16-1; i++) {
        for (j = 0; j < 16-1-i; j++){
            if ( arr[j] > arr[j+1] ) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        printf("����%d��\n", i);
        for(k = 0; k < 16; k++){
            printf("%d\n", arr[k]);
        }
    }
    printf("�����\n");
    for(l = 0; l < 16; l++){
        printf("%d\n", arr[l]);
    }
    return 0;
}
