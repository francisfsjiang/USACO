#include<stdio.h>
int main()
{
    int i,j,temp,n;
    int data[100];
    printf("These are the StudentID:\n");
    temp=1;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=10;j++)
        {
            printf("%-8d",temp);
            temp++;
        }
        printf("\n\n");
    }
    printf("GROUP SIZE IS :");
    scanf("%d",&n);
    printf("Method 1 : Directly Grouping.\n")
    return 0;
}
