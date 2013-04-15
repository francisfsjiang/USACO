/*
ID: The One
LANG: C
TASK: checker
*/
#include<stdio.h>
int n,date[20],cross[14]={0},obilque[30]={0},obilque2[40]={0},sum=0;
FILE *in,*out;
main()
{
      in=fopen("checker.in","r");
      out=fopen("checker.out","w");
      int search(int x);
      fscanf(in,"%d",&n);
      search(1);
      fprintf(out,"%d\n",sum);
      return 0;
}

int search(int x)
{
    int i;
    if(x==n+1)
    {
              sum++;
              if(sum<=3)
              {
              fprintf(out,"%d",date[1]);
              for(i=2;i<=n;i++)fprintf(out," %d",date[i]);
              fprintf(out,"\n");
              }
              return;
    }
    for(i=1;i<=n;i++)
    {
                     if(obilque[x+i]==1||cross[i]==1||obilque2[20+x-i]==1)continue;
                     date[x]=i;
                     obilque[x+i]=1;
                     cross[i]=1;
                     obilque2[20+x-i]=1;
                     search(x+1);
                     obilque[x+i]=0;
                     cross[i]=0;
                     obilque2[20+x-i]=0;
    }
}
                     
