//����12��ڶ���
/*С�����
       1 1 1 1 1 1
       1 1 0 0 0 1
       1 0 0 0 1 0
       1 1 0 1 1 1
       0 1 0 1 0 0
       1 1 1 1 1 1
���������е�1�������ߣ�0����С������С�����������1�а�Χ��0�ĸ�������ע�⣺����������0��
��0�������б�����1��Χ����0�������б�����1��Χ��*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100

int main()
{
    int n;
    int arr [M][M] = {0};
    int row [M][2];
    int col [M][2];
    int result = 0;

    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&arr[i][j]);
    memset(row,-1,100*2*sizeof(int));//��Ҫ���Ǳ߽����� ����ֵΪ0
    memset(col,-1,100*2*sizeof(int));

    //��ÿ�еı߽�
    for(i=0;i<n;i++)//��i��
       {
           for(j=0;j<n;j++)
        {
            if(arr[i][j] == 1)
             {	//С���߽�
               row[i][0] = j;
               break;
             }
        }


        for(j=n-1;j>=0;j--)
        {
            if(arr[i][j] == 1)
             {	//С���߽�
               row[i][1] = j;
               break;
             }
        }

       // printf("%d,%d\n",row[i][0],row[i][1]);
       }

    //��ÿ�еı߽�
    for(j=0;j<n;j++)//��j��
       {
           for(i=0;i<n;i++)
        {
            if(arr[i][j] == 1)
             {	//С���߽�
               col[j][0] = i;
               break;
             }
        }


        for(i=n-1;i>=0;i--)
        {
            if(arr[i][j] == 1)
             {	//С���߽�
               col[j][1] = i;
               break;
             }
        }
       // printf("%d,%d\n",col[j][0],col[j][1]);
       }


       for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(arr[i][j] == 0){	//С���߽�
					if(j > row[i][0] && j < row[i][1] && i > col[j][0] && i < col[j][1]){
						result++;
					//	printf("i=%d,j=%d\n",i,j); //for debug
					}
				}
			}
       }

        printf("%d\n",result);


    return 0;
}
