/*
ID:The One
TASK:fact4
LANG:C
*/
#include<stdio.h>
int main()
{
    FILE *in,*out;
    in=fopen("fact4.in","r");
    out=fopen("fact4.out","w");
    int n,i,j,sum;
    fscanf(in,"%d",&n);
    sum=1;
    for(;n>0;n--)
    {
        sum=sum*n;
        for(;sum%10==0;)
        {
            sum=sum/10;
        }
        sum=sum%10000;
    }
    fprintf(out,"%d\n",sum%10);
    return 0;
}
