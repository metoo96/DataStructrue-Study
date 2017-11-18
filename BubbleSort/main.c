#include <stdio.h>
#include <stdlib.h>
/**
*内容 冒泡排序
*作者 Guozhu Zhu
*时间 2017/11/18
*/
int main()
{
    int arr[] = {1, 2, 5, 3, 2, 7, 1, 4, 7, 8, 5, 4, 10 , 22, 44, 88};
    int i, j, k, l, temp;
    //最多需要循环n-1次
    for (i = 0; i < （16-1）; i++) {
        //比较范围逐渐缩小
        for (j = 0; j < （16-1）-i; j++) {
            //相邻的两个元素进行比较，如前一个比后一个大就调换次序
            if ( arr[j] > arr[j+1] ) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        printf("排了%d次\n", i);
        for (k = 0; k < 16; k++) {
            printf("%d\n", arr[k]);
        }
    }
    printf("排序后\n");
    for (l = 0; l < 16; l++) {
        printf("%d\n", arr[l]);
    }
    return 0;
}
