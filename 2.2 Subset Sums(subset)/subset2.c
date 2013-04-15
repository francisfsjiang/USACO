/*
ID: The One
LANG: C
TASK: subset
*/
#include<stdio.h>
int date[43]={0},n,sum,max=0,decision=2,set[43];
FILE *in,*out;
main()
{
      in=fopen("subset.in","r");
      out=fopen("subset.out","w");
      int i;
      int search(int x,int y);
      fscanf(in,"%d",&n);
      sum=n*(n+1)/2;
      fprintf(out,"%d  %d\n",sum,sum%2);
      for(i=1;i<=n;i++)set[i]=1;
      if(sum%2==1)
      {
                  fprintf(out,"0\n");
                  return 0;
      }
      else
      {
          sum=sum/2;
          search(0,1);
      if(max==0)fprintf(out,"0\n");
      else fprintf(out,"%d\n",max-1);
      }
      return 0;
}

int search(int x,int y)
{
    if(decision==0)return;
    int i,j,dd=0;
    for(i=y;i<=n;i++)
    {
                     if(date[i]==0)
                     {
                                   if(x+i>sum)continue;
                                   else if(x+i==sum)
                                   {
                                        //for(j=1;j<=n;j++)if(set[j]==1)fprintf(out,"%d ",j);
                                        //fprintf(out,"\n");
                                        for(j=1;j<=i;j++)if(date[j]==1&&set[j]==1){dd=1;break;}
                                        if(dd==0)
                                        {
                                                 decision=0;
                                        }
                                        memset(set,0,sizeof(set));
                                        date[i]=1;
                                        for(j=1;j<=i;j++)if(date[j]==1)set[j]=1;
                                        //for(j=1;j<=n;j++)if(date[j]==1)fprintf(out,"%d ",j);
                                        //fprintf(out,"\n-----------\n");
                                        max++;
                                        date[i]=0;
                                        continue;
                                   }
                                   else
                                   {
                                       date[i]=1;
                                       search(x+i,i+1);
                                       date[i]=0;
                                   }
                     }
    }
}
