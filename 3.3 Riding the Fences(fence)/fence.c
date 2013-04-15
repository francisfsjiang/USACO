/*
ID: The One
LANG: C
TASK: fence
*/
#include<stdio.h>
int list[1030];
int data[502][502]={0};
int n;
int sign=0;
int maxpoint=0,minpoint=99999999;
FILE *in,*out;
int main()
{
    in=fopen("fence.in","r");
    out=fopen("fence.out","w");
    int search(int x);
    int i,j,k,x,y,start,sum,min;
    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(in,"%d%d",&x,&y);
        data[x][y]++;
        data[y][x]++;
        if(x>maxpoint)maxpoint=x;
        if(y>maxpoint)maxpoint=y;
        if(x<minpoint)minpoint=x;
        if(y<minpoint)minpoint=y;
    }
    if(n==1)
    {
        if(x<y)fprintf(out,"%d\n%d\n",x,y);
        else fprintf(out,"%d\n%d\n",y,x);
        return 0;
    }
    min=9999999;
    for(i=1;i<=maxpoint;i++)
    {
        sum=0;
        for(j=1;j<=maxpoint;j++)
        {
            if(data[i][j]>0)sum+=data[i][j];
        }
        //fprintf(out,"%d=%d\n",i,sum);
        if(sum%2==1&&i<min)
        {
            min=i;
        }
    }
    if(min==9999999)min=minpoint;
    fprintf(out,"%d\n",min);
    fprintf(out,"%d %d\n",minpoint,maxpoint);
    list[1]=min;
    search(1);
    for(i=1;i<=n+1;i++)fprintf(out,"%d ",list[i]);
    return 0;
}

int search(int x)
{
    if(x==n+1)
    {
        sign=1;
        return;
    }
    if(sign==1)return;
    int i,j;
    for(i=minpoint;i<=maxpoint;i++)
    {
        if(data[list[x]][i]>0&&sign==0)
        {
            //if(list[x]==273)fprintf(out,"%d     %d-%d\n",x,list[x],i);
            data[list[x]][i]--;
            data[i][list[x]]--;
            list[x+1]=i;
            if(list[x+1]==269){
            for(j=450;j<=x+1;j++)fprintf(out,"%d ",list[j]);
            fprintf(out,"\n");}
            search(x+1);
            data[list[x]][i]++;
            data[i][list[x]]++;
        }
    }
    return;
}
