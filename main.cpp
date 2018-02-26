//北航12年第二题
/*小岛面积
       1 1 1 1 1 1
       1 1 0 0 0 1
       1 0 0 0 1 0
       1 1 0 1 1 1
       0 1 0 1 0 0
       1 1 1 1 1 1
上面矩阵的中的1代表海岸线，0代表小岛。求小岛面积（即被1中包围的0的个数）。注意：仅求这样的0，
该0所在行中被两个1包围，该0所在列中被两个1包围。*/

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
    memset(row,-1,100*2*sizeof(int));//需要考虑边界条件 返回值为0
    memset(col,-1,100*2*sizeof(int));

    //找每行的边界
    for(i=0;i<n;i++)//第i行
       {
           for(j=0;j<n;j++)
        {
            if(arr[i][j] == 1)
             {	//小岛边界
               row[i][0] = j;
               break;
             }
        }


        for(j=n-1;j>=0;j--)
        {
            if(arr[i][j] == 1)
             {	//小岛边界
               row[i][1] = j;
               break;
             }
        }

       // printf("%d,%d\n",row[i][0],row[i][1]);
       }

    //找每列的边界
    for(j=0;j<n;j++)//第j列
       {
           for(i=0;i<n;i++)
        {
            if(arr[i][j] == 1)
             {	//小岛边界
               col[j][0] = i;
               break;
             }
        }


        for(i=n-1;i>=0;i--)
        {
            if(arr[i][j] == 1)
             {	//小岛边界
               col[j][1] = i;
               break;
             }
        }
       // printf("%d,%d\n",col[j][0],col[j][1]);
       }


       for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(arr[i][j] == 0){	//小岛边界
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
