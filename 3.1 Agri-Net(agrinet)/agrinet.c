/*
ID: The One
LANG: C
TASK: agrinet
*/
#include<stdio.h>
main()
{
      FILE *in=fopen("agrinet.in","r"),*out=fopen("agrinet.out","w");
      int date[102][102],sign[102]={0},n,i,j,sum=0,max,temp;
      fscanf(in,"%d",&n);
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)fscanf(in,"%d",&date[i][j]);
      sign[1]=1;
      while(1)
      {
              max=10000000;
              temp=0;
              for(i=1;i<=n;i++)
              {
                  if(sign[i]==1)
                  {
                       for(j=1;j<=n;j++)
                       {
                           if(sign[j]==0&&date[i][j]<max)
                           {
                               max=date[i][j];
                               temp=j;
                           }
                       }
                  }
              }
              if(temp==0)break;
              sign[temp]=1;
              sum+=max;
      }
      fprintf(out,"%d\n",sum);
      return 0;
}
