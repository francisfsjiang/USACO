/*
ID: The One
LANG: C
TASK: cowtour
*/
#include<stdio.h>
#include<math.h>
int n,signer,sign[152]={0},con[152][152];
main()
{
      FILE *in=fopen("cowtour.in","r"),*out=fopen("cowtour.out","w");
      int date[152][152],coordinate[152][2],i,j,x,y,max;
      char t[152];
      int search(int x);
      fscanf(in,"%d",&n);
      for(i=1;i<=n;i++)fscanf(in,"%d%d",&coordinate[i][0],&coordinate[i][1]);
      for(i=1;i<=n;i++)
      {
                       fscanf(in,"%s",t);
                       for(j=0;j<n;j++)
                       {
                                       con[i][j+1]=t[j]-48;
                       }
      }
      for(i=1;i<=n;i++)
      {
                       for(j=1;j<=n;j++)fprintf(out,"%d ",con[i][j]);
                       fprintf(out,"\n");
      }
      for(i=1;i<=n-1;i++)for(j=i+1;j<=n;j++)
      {
                                            x=abs(coordinate[i][0]-coordinate[j][0]);
                                            y=abs(coordinate[i][1]-coordinate[j][1]);
                                            date[i][j]=x*x+y*y;
      }
      for(i=1;i<=n;i++)
      {
                       for(j=1;j<=n;j++)fprintf(out,"%4d ",date[i][j]);
                       fprintf(out,"\n");
      }
      signer=1;
      for(i=1;i<=n;i++)if(sign[i]==0){search(i);signer++;}
      for(i=1;i<=n;i++)fprintf(out,"%d ",sign[i]);
      fprintf(out,"\n");
      max=0;
      for(i=1;i<signer-1;i++)for(j=i+1;j<signer;j++)
      {
                       for(x=1;x<=n;x++)if(sign[x]==i||sign[x]==j)
                       {
                            for(y=x+1;y<=n;y++)if(sign[y]==i||sign[y]==j)
                            {
                                  if(date[x][y]>max)max=date[x][y];
                            }
                       }
      }
      fprintf(out,"%ld\n",max);
      return 0;
}

int search(int x)
{
    int i;
    sign[x]=signer;
    for(i=1;i<=n;i++)
    {
                     if(sign[i]==0&&con[x][i]==1)
                     {
                                     search(i);
                     }
    }
}
