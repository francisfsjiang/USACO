/*
ID: The One
LANG: C
TASK: concom
*/
#include<stdio.h>
main()
{
      FILE *in=fopen("concom.in","r"),*out=fopen("concom.out","w");
      int i,j,n,date[102][102]={0},x,y,max=0,tempi,tempj,used[102][102]={0};
      fscanf(in,"%d",&n);
      for(i=0;i<n;i++)
      {
                      fscanf(in,"%d%d",&x,&y);
                      fscanf(in,"%d",&date[x][y]);
                      if(x>max)max=x;
                      if(y>max)max=y;
      }
      n=max;
      //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(out,"%d ",date[i][j]);fprintf(out,"\n");}
      x=0;
      for(i=1;i<=n;i++)
      {
                       for(j=1;j<=n;j++)
                       {
                                        if(date[i][j]>50){x=i;y=j;used[x][y]=1;break;}
                       }
                       if(x!=0)break;
      }
      //fprintf(out,"i=%d  j=%d\n",x,y);
      while(1)
      {
                       //fprintf(out,"i=%d  j=%d\n",x,y);
                       for(i=1;i<=n;i++)date[x][i]+=date[y][i];
                       
                       for(i=1;i<=n;i++)if(date[i][x]>50&&i!=y)
                       {
                                                             for(j=1;j<=n;j++)if(date[i][y]<=50)date[i][j]+=date[x][j];
                       }
                       //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(out,"%d ",date[i][j]);fprintf(out,"\n");}
                       //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(out,"%d ",used[i][j]);fprintf(out,"\n");}
                       x=0;
                       for(i=1;i<=n;i++)
                       {
                                   for(j=1;j<=n;j++)
                                   if(date[i][j]>50&&used[i][j]==0)
                                   {
                                        x=i;
                                        y=j;
                                        used[x][y]=1;
                                        //fprintf(out,"i=%d  j=%d\n",x,y);
                                        break;
                                   }
                                  if(x!=0)break;
                       }
                       if(x==0)break;
      }
      //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(out,"%d ",date[i][j]);fprintf(out,"\n");}
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(date[i][j]>50)fprintf(out,"%d %d\n",i,j);
      return 0;
}
