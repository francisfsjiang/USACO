/*
ID:The One
TASK:stamps
LANG:C
*/
#include<stdio.h>
short data[2500000];
int main()
{
    FILE *in,*out;
    in=fopen("stamps.in","r");
    out=fopen("stamps.out","w");
    int quicksort(int date[],int s,int t);
    int i,j,n,k,max=0,sum,temp,maxstamp=0;
    int num[205];
    fscanf(in,"%d%d",&k,&n);
    for(i=0;i<=10000;i++)data[i]=0;
    for(i=0;i<n;i++)
    {
        fscanf(in,"%d",&num[i]);
        data[num[i]]=1;
    }
    quicksort(num,0,n-1);
    //for(i=0;i<n;i++)fprintf(out,"%d ",num[i]);
    //fprintf(out,"\n");
    for(i=0;i<n;i++)
    {
        for(j=num[i];j<=num[i]*k;j++)
        {
            if(data[j]>data[j-num[i]]+1&&data[j-num[i]]!=0||data[j]==0)data[j]=data[j-num[i]]+1;
        }
    /*for(j=0;j<=num[i]*k;j++)fprintf(out,"%2d ",j);
    fprintf(out,"\n");
    for(j=0;j<=num[i]*k;j++)fprintf(out,"%2d ",data[j]);
    fprintf(out,"\n\n\n");*/

    }
    /*for(i=0;i<=num[n-1]*k;i++)fprintf(out,"%5d ",i);
    fprintf(out,"\n");
    for(i=0;i<=num[n-1]*k;i++)fprintf(out,"%5d ",data[i]);
    fprintf(out,"\n");*/
    sum=0;
    for(i=1;i<=num[n-1]*k;i++)
    {
        if(data[i]>k||data[i]==0)continue;
        temp=0;
        for(j=i;j<=num[n-1]*k;j++)
        {
            if(data[j]>k||data[j]==0)break;
            else temp++;
        }
        if(temp>sum)sum=temp;
        i=j+1;
    }
    fprintf(out,"%d\n",sum);
    return 0;
}


int quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m;
     i=s;
     j=t+1;
     y=date[s];
     for(;i<j;)
     {
                 for(i++;date[i]<y;i++);
                 for(j--;date[j]>y;j--);
                 if(i<j)
                 {
                        temp=date[i];
                        date[i]=date[j];
                        date[j]=temp;
                 }
     }
     date[s]=date[j];
     date[j]=y;
     if(s<j-1)quicksort(date,s,j-1);
     if(j+1<t)quicksort(date,j+1,t);
}
