/*
ID: The One
LANG: C
TASK: ttwo
*/
//.46  *42  Cow67  Farmer70
#include<stdio.h>
main()
{
      FILE *in=fopen("ttwo.in","r"),*out=fopen("ttwo.out","w");
      int i,j,n,cx=0,cy=0,fx=0,fy=0,cxs,cys,fxs,fys,date[12][12],movex[4]={-1,0,1,0},movey[4]={0,1,0,-1},cd=0,fd=0,sum=0;
      char x;
      for(i=0;i<=11;i++)for(j=0;j<=11;j++)date[i][j]=42;
      for(i=1;i<=10;i++)for(j=1;j<=10;j++)
      {
                                          
                                          fscanf(in,"%c",&x);
                                          if(x==10)j--;
                                          else date[i][j]=x;
      }
      //for(i=0;i<=11;i++){for(j=0;j<=11;j++)fprintf(out,"%c ",date[i][j]);fprintf(out,"\n");}
      for(i=1;i<=10;i++)for(j=1;j<=10;j++)
      {
                                          if(date[i][j]==67){cx=i;cy=j;cxs=i;cys=j;}
                                          else if(date[i][j]==70){fx=i;fy=j;fxs=i;fys=j;}
      }
      date[cx][cy]=46;
      date[fx][fy]=46;
      //for(i=0;i<=11;i++){for(j=0;j<=11;j++)fprintf(out,"%c ",date[i][j]);fprintf(out,"\n");}
      while(sum<5000000)
      {
              /*for(i=0;i<=11;i++)
              {
                                for(j=0;j<=11;j++)
                                {
                                                  if(i==cx&&j==cy)fprintf(out,"C ");
                                                  else if(i==fx&&j==fy)fprintf(out,"F ");
                                                  else fprintf(out,"%c ",date[i][j]);
                                }
                                fprintf(out,"\n");
              }*/
              if(date[cx+movex[cd]][cy+movey[cd]]==42)
              {
                                                      cd++;
                                                      if(cd==4)cd=0;
              }
              else
              {
                  cx+=movex[cd];
                  cy+=movey[cd];
              }
              if(date[fx+movex[fd]][fy+movey[fd]]==42)
              {
                                                      fd++;
                                                      if(fd==4)fd=0;
              }
              else
              {
                  fx+=movex[fd];
                  fy+=movey[fd];
              }
              sum++;
              if(cx==fx&&cy==fy)
              {
                              break;
              }
              if(sum!=1&&cd==fd&&cx==cxs&&cy==cys&&fx==fxs&&fy==fys)
              {
                                                         fprintf(out,"0\n");
                                                         sum=0;
                                                         break;
              }
      }
      if(sum==5000000)fprintf(out,"0\n");
      else if(sum!=0)fprintf(out,"%d\n",sum);
      
      return 0;
}
