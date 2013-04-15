/*
ID:The One
LANG:C
TASK:castle
*/
#include<stdio.h>
FILE *in,*out;
int date[51][51]={0},ss[51][51]={0},sum=0,maxarea=0,area[2600],m,n;
main()
{
      in=fopen("castle.in","r");
      out=fopen("castle.out","w");
      int i,j;
      int maxx,maxx2,maxy,maxy2,max=0,max2=0,temp;
      int wellwest(int x);
      int wellnorth(int x);
      int welleast(int x);
      int wellsouth(int x);
      int search(int x,int y);
      fscanf(in,"%d%d",&m,&n);
      for(i=1;i<=n;i++)for(j=1;j<=m;j++)fscanf(in,"%d",&ss[i][j]);
      //for(i=1;i<=n;i++)
      //{
      //                 for(j=1;j<=m;j++)
      //                 fprintf(out,"%d ",ss[i][j]);
      //                 fprintf(out,"\n");
      //}
      for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(date[i][j]==0){sum++;search(i,j);}
      /*for(i=1;i<=n;i++)
      {
                       for(j=1;j<=m;j++)
                       fprintf(out,"%d ",date[i][j]);
                       fprintf(out,"\n");
      }*/
      fprintf(out,"%d\n",sum);
      max=0;
      for(i=1;i<=sum;i++)if(area[i]>max)max=area[i];
      fprintf(out,"%d\n",max);
      //for(i=1;i<=sum;i++)fprintf(out,"%d ",area[i]);
      //fprintf(out,"\n");
      max=0;
      max2=0;
      for(j=1;j<=m;j++)for(i=n;i>=1;i--)
      {
                                        if(i-1>=1&&date[i-1][j]!=date[i][j])
                                        {
                                                                            temp=area[date[i-1][j]]+area[date[i][j]];
                                                                            if(temp>max)
                                                                            {
                                                                                        max=temp;
                                                                                        maxx=i;
                                                                                        maxy=j;
                                                                            }
                                        }
                                        if(j+1<=m&&date[i][j+1]!=date[i][j])
                                        {
                                                                            temp=area[date[i][j+1]]+area[date[i][j]];
                                                                            if(temp>max2)
                                                                            {
                                                                                        max2=temp;
                                                                                        maxx2=i;
                                                                                        maxy2=j;
                                                                            }
                                        }
      }
      //fprintf(out,"%d\n%d %d N\n%d\n%d %d E\n",max,maxx,maxy,max2,maxx2,maxy2);
      if(max!=max2)
      {
                   if(max>=max2)fprintf(out,"%d\n%d %d N\n",max,maxx,maxy);
                   else fprintf(out,"%d\n%d %d E\n",max2,maxx2,maxy2);
      }
      else
      {
      if(maxy==maxy2)
      {
                     if(maxx>=maxx2)fprintf(out,"%d\n%d %d N\n",max,maxx,maxy);
                     else fprintf(out,"%d\n%d %d E\n",max2,maxx2,maxy2);
      }
      else
      {
      if(maxy<=maxy2)fprintf(out,"%d\n%d %d N\n",max,maxx,maxy);
      else fprintf(out,"%d\n%d %d E\n",max2,maxx2,maxy2);
      }
      }
      return 0;
}

int search(int x,int y)
{
    int d=0,i,j;
    date[x][y]=sum;
    area[sum]++;
    j=ss[x][y];
    if((y-1)>=1&&date[x][y-1]==0&&wellwest(j)==0)
    {
                                       d=1;
                                       search(x,y-1);
    }
    if((x-1)>=1&&date[x-1][y]==0&&wellnorth(j)==0)
    {
                                        d=1;
                                        search(x-1,y);
    }
    if(y+1<=m&&date[x][y+1]==0&&welleast(j)==0)
    {
                                       d=1;
                                       search(x,y+1);
    }
    if(x+1<=n&&date[x+1][y]==0&&wellsouth(j)==0)
    {
                                        d=1;
                                        search(x+1,y);
    }
}
    
int wellwest(int x)
{
    if(x>=8)x-=8;
    if(x>=4)x-=4;
    if(x>=2)x-=2;
    if(x==1)return 1;
    else return 0;
}
int wellnorth(int x)
{
    if(x>=8)x-=8;
    if(x>=4)x-=4;
    if(x>=2)return 1;
    else return 0;
}
int welleast(int x)
{
    if(x>=8)x-=8;
    if(x>=4)return 1;
    else return 0;
}
int wellsouth(int x)
{
    if(x>=8)return 1;
    else return 0;
}
