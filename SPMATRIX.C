//IMPLEMENT SPARSE MATRIX USING ARRAY
#include<stdio.h>
#include<windows.h>
int main()
{
    int q,i,j,m,n,t=0,b[10][10],a[10][10];
    printf("\n Enter the size of matrix (rows and columns)");
    scanf("%d%d",&m,&n);
    printf("\n Enter matrix");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            if (a[i][j]!=0)
                t++;
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=t;
    q=1;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            if (a[i][j]!=0)
            {
                b[q][0]=i+1;
                b[q][1]=j+1;
                b[q][2]=a[i][j];
                q++;
            }
    printf("\n Sparse Matrix is: ");
    for(i=0; i<t+1; i++)
    {
        printf("\n ");
        for(j=0; j<3; j++)
            printf(" %d",b[i][j]);
    }
    printf("\n Kushdeep Singh");
    Sleep(10000);
    return 0;
}
