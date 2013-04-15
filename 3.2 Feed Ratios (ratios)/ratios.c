/*
ID: The One
LANG: C
TASK: ratios
*/

#include <stdio.h>
int main()
{
    FILE *in,*out;
    in=fopen("ratios.in","r");
    out=fopen("ratios.out","w");
    int data[4][4];
    int i,j,k,x,y,z,a,b,c,rex=0,rey,rez,sum=99999999,tempa,tempb,tempc;
    fscanf(in,"%d%d%d",&x,&y,&z);
    if(x==0&&y==0&z==0)
    {
        fprintf(out,"0 0 0 0\n");
    }
    for(i=1;i<=3;i++)for(j=1;j<=3;j++)fscanf(in,"%d",&data[i][j]);
    for(i=1;i<=100;i++)for(j=1;j<=100;j++)for(k=1;k<=100;k++)
    {
        //fprintf(out,"i=%d j=%d k=%d\n",i,j,k);
        a=i*data[1][1]+j*data[2][1]+k*data[3][1];
        b=i*data[1][2]+j*data[2][2]+k*data[3][2];
        c=i*data[1][3]+j*data[2][3]+k*data[3][3];
        if((x==0&&a!=0)||(x!=0&&a==0))continue;
        if((y==0&&b!=0)||(y!=0&&b==0))continue;
        if((z==0&&c!=0)||(z!=0&&c==0))continue;
        tempa=-1;
        tempb=-1;
        tempc=-1;
        if(x==0&&a==0)tempa=0;
        else if(a%x==0)tempa=a/x;
        if(y==0&&b==0)tempb=0;
        else if(b%y==0)tempa=b/y;
        if(z==0&&c==0)tempc=0;
        else if(c%z==0)tempa=c/z;
        if(tempa==tempc&&tempa==tempb&&tempb==tempc)
        {
            //fprintf(out,"i=%d j=%d k=%d\n",i,j,k);
            rex=i;
            rey=j;
            rez=k;
            sum=i+j+k;
        }
    }
    if(rex==0)fprintf(out,"NONE\n");
    else fprintf(out,"%d %d %d %d\n",rex,rey,rez,(rex*data[1][1]+rey*data[2][1]+rez*data[3][1])/x);
    return 0;
}
