/*
ID: The One
LANG: C
TASK: frac1
*/
#include<stdio.h>
#include<math.h>
float date[10000],temp2;
int datei[10000],datej[10000],temp;
main()
{
      FILE *in=fopen("frac1.in","r"),*out=fopen("frac1.out","w");
      int check(int x,int y);
      int i,j,n,sum=0;
      fscanf(in,"%d",&n);
      for(i=1;i<=n;i++)for(j=1;j<i&&j<(float)i/2;j++)
      {
                                          if(check(j,i)==0)continue;
                                          else 
                                          {
                                               sum++;
                                               datei[sum]=i;
                                               datej[sum]=j;
                                               date[sum]=(float)j/(float)i;
                                          }
      }
      //for(i=1;i<=sum;i++)fprintf(out,"%d %d %f\n",datej[i],datei[i],date[i]);
      for(i=1;i<=sum;i++)
      {
                         for(j=1;j<=sum-i;j++)
                         {
                         if(date[j]>date[j+1])
                         {
                                            temp2=date[j+1];
                                            date[j+1]=date[j];
                                            date[j]=temp2;
                                            temp=datei[j+1];
                                            datei[j+1]=datei[j];
                                            datei[j]=temp;
                                            temp=datej[j+1];
                                            datej[j+1]=datej[j];
                                            datej[j]=temp;
                         }
                         }
      }
      //for(i=1;i<=sum;i++)fprintf(out,"%d %d %f\n",datej[i],datei[i],date[i]);
      fprintf(out,"0/1\n",datej[i],datei[i]);
      for(i=1;i<=sum;i++)fprintf(out,"%d/%d\n",datej[i],datei[i]);
      if(n!=1)fprintf(out,"1/2\n",datej[i],datei[i]);
      for(i=sum;i>=1;i--)fprintf(out,"%d/%d\n",datei[i]-datej[i],datei[i]);
      fprintf(out,"1/1\n",datej[i],datei[i]);
      return 0;
}

int check(int x,int y)
{
    int i;
    for(i=2;i<=x;i++)
    {
                     if(x%i==0&&y%i==0)return 0;
    }
    return 1;
}
