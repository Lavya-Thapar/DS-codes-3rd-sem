#include <stdio.h>
void minor(int i,int j,int arr[3][3])
{
    int arr2[2][2];
    int row2=0;int column2=0;
    for(int column=0;column<3;column++)
    {
        arr[i][column]=0;
    }
    for(int row=0;row<3;row++)
    {
        arr[row][j]=0;
    }
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            if(arr[x][y]!=0)
            {
                arr2[row2][column2]=arr[x][y];
                
                column2++;
            }

        }
        row2++;
        column2=0;
        
    }
    for(int x=0;x<2;x++)
    {
        for(int y=0;y<2;y++)
        {
            printf("%d ",arr2[x][y]);
        }
        printf("\n");
    }
    
}
int main()
{
    int arr[3][3];
    printf("enter array elements :\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("enter array element a%d%d",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    
    
    minor(1,2,arr);
}