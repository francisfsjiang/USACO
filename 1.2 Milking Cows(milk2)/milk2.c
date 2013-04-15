/*
ID: The One
LANG: C
TASK: milk2
*/
#include <stdio.h>
int t[1000005]={0};
main () 
{
    FILE *fin  = fopen ("milk2.in","r");
    FILE *fout = fopen ("milk2.out","w");
    int i,d=0,n,x,y,max1=0,max1s=0,max2=0,max2s=0,end=0,start=1000000;
    fscanf (fin,"%d",&n);
    for(i=0;i<n;i++)
    {
                    fscanf (fin,"%d%d",&x,&y);
                    t[x]++;
                    if(x<start)start=x;
                    t[y]--;
                    if(y>end)end=y;
    }
    for(i=start;i<=end;i++)
    {
                       if(d==1&&t[i]==-1)
                       {
                                        if(max1>max1s)max1s=max1;
                                        max1=0;
                       }
                       if(d==0&&t[i]!=0)
                       {
                                        if(max2>max2s)max2s=max2;
                                        max2=0;
                       }
                       d+=t[i];
                       if(d>=1)max1++;
                       if(d==0)max2++;
    }
    fprintf (fout,"%d %d\n",max1s,max2s);
    exit(0);
}
