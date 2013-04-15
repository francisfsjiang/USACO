/*
ID: The One
LANG: C
TASK: comehome
*/
#include<stdio.h>
main()
{
      FILE *in=fopen("comehome.in","r"),*out=fopen("comehome.out","w");
      int date[60][60]={0},n,dist[60],i,j,t,head,end,sign[60]={0},tempi=0,tempj,max;
      char x,y,rub;
      fscanf(in,"%d",&n);
      for(i=0;i<n;i++)
      {
                      fscanf(in,"%c%c%c%c%c%d",&rub,&x,&rub,&y,&rub,&t);
                      if(x>95)x-=6;
                      if(y>95)y-=6;
                      if(date[x-65][y-65]==0||t<date[x-65][y-65]){date[x-65][y-65]=t;date[y-65][x-65]=t;}
      }
      //for(i=0;i<=51;i++){for(j=0;j<=51;j++)fprintf(out,"%d ",date[i][j]);fprintf(out,"\n");};
      sign[25]=1;
      while(1)
      {
              tempj=-1;
              max=10000000;
              for(i=0;i<=51;i++)
              {
                  if(sign[i]==1)
                  {
                       for(j=0;j<=51;j++)
                       {
                           if(date[i][j]!=0&&sign[j]==0&&date[i][j]<max)
                           {
                                tempi=i;
                                tempj=j;
                                max=date[i][j];
                           }
                       }
                  }
              }
              if(tempj==-1)break;
              sign[tempj]=1;
              dist[tempj]=dist[tempi]+max;
      }
      //fprintf(out,"--------------------------------------------------\n");
      for(i=0;i<=51;i++)fprintf(out,"%d ",sign[i]);
      fprintf(out,"\n");
      for(i=0;i<=51;i++)fprintf(out,"%d ",dist[i]);
      fprintf(out,"\n");
      max=1000000;
      for(i=0;i<=25;i++)
      {
          if(dist[i]!=0&&dist[i]<max)
          {
               tempi=i;
               max=dist[i];
          }
      }
      fprintf(out,"%c %d\n",tempi+65,max);
      return 0;
}
