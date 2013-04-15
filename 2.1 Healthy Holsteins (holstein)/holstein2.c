/*
ID: The One
LANG: C
TASK: holstein
*/
#include<stdio.h>
FILE *in,*out;
int n,m,date[20][30],temp[20]={0},ss[30],sum[30];
main()
{
      in=fopen("holstein.in","r");
      out=fopen("holstein.out","w");
      int i,j,mix=0;
      fscanf(in,"%d",&n);
      for(i=0;i<n;i++)fscanf(in,"%d",&ss[i]);
      fscanf(in,"%d",&m);
      for(i=0;i<m;i++)for(j=0;j<n;j++)fscanf(in,"%d",&date[i][j]);
      //for(i=0;i<m;i++){for(j=0;j<n;j++)fprintf(out,"%d ",date[i][j]);fprintf(out,"\n");}
      for(i=0;i<m;i++)for(j=0;j<n;j++)
      {
                                      sum[j]+=date[i][j];
      }
      //for(i=0;i<n;i++)fprintf(out,"%d ",sum[i]);
      //fprintf(out,"\n");
      search();
      for(i=0;i<m;i++)fprintf(out,"%d ",temp[i]);
      fprintf(out,"\n");
      for(i=0;i<m;i++)if(temp[i]==0)mix++;
      fprintf(out,"%d ",mix);
      for(i=0;i<m;i++)if(temp[i]==0){fprintf(out,"%d",i+1);break;}
      for(i++;i<m;i++)if(temp[i]==0)fprintf(out," %d",i+1);
      fprintf(out,"\n");
      return 0;
}

int search()
{
    int i,j,t[30],d;
    for(i=m-1;i>=0;i--)
    {
                       d=0;
                       for(j=0;j<n;j++)t[j]=sum[j]-date[i][j];
                       for(j=0;j<n;j++)if(t[j]<ss[j]){d=1;break;}
                       for(j=0;j<n;j++)fprintf(out,"%d ",sum[j]);
                       fprintf(out,"\n");
                       for(j=0;j<n;j++)fprintf(out,"%d ",t[j]);
                       fprintf(out,"\n");
                       if(d==0)
                       {
                               temp[i]=1;
                               for(j=0;j<n;j++)sum[j]-=date[i][j];
                       }
    }
}
