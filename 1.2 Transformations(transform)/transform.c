/*
ID: The One
LANG: C
TASK: transform
*/
#include <stdio.h>
int n,date[12][12],s[12][12],temp[12][12],temp2[12][12];
main () 
{
    FILE *fin  = fopen ("transform.in","r");
    FILE *fout = fopen ("transform.out","w");
    int i,j,k,newx,newy,d;
    int check();
    int check2();
    fscanf(fin,"%d",&n);
    fscanf(fin,"%c",&d);
    for(i=1;i<=n;i++){for(j=1;j<=n;j++)fscanf(fin,"%c",&date[i][j]);fscanf(fin,"%c",&d);}
    //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(fout,"%d ",date[i][j]);fprintf(fout,"\n");}fprintf(fout,"\n");
    for(i=1;i<=n;i++){for(j=1;j<=n;j++)fscanf(fin,"%c",&s[i][j]);fscanf(fin,"%c",&d);}
    //for(i=1;i<=n;i++){for(j=1;j<=n;j++)fprintf(fout,"%d ",s[i][j]);fprintf(fout,"\n");}fprintf(fout,"\n");
for(k=0;k<1;k++)
{
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//顺时针转90° 
    {
                                      newx=j;
                                      newy=n+1-i;
                                      temp[newx][newy]=date[i][j];
    }
    if(check()==1){fprintf(fout,"%d\n",1);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//顺时针转180° 
    {
                                      newx=n+1-i;
                                      newy=n+1-j;
                                      temp[newx][newy]=date[i][j];
    }
    if(check()==1){fprintf(fout,"%d\n",2);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//顺时针转270° 
    {
                                      newx=n+1-j;
                                      newy=i;
                                      temp[newx][newy]=date[i][j];
    }
    if(check()==1){fprintf(fout,"%d\n",3);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//轴对称 
    {
                                      newx=i;
                                      newy=n+1-j;
                                      temp[newx][newy]=date[i][j];
    }
    if(check()==1){fprintf(fout,"%d\n",4);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//轴对称 顺时针转90°
    {
                                      newx=i;
                                      newy=n+1-j;
                                      temp[newx][newy]=date[i][j];
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    {
                                      newx=n+1-j;
                                      newy=i;
                                      temp2[newx][newy]=temp[i][j];
    }
    if(check2()==1){fprintf(fout,"%d\n",5);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//轴对称 顺时针转180°
    {
                                      newx=i;
                                      newy=n+1-j;
                                      temp[newx][newy]=date[i][j];
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++) 
    {
                                      newx=n+1-i;
                                      newy=n+1-j;
                                      temp2[newx][newy]=temp[i][j];
    }
    if(check2()==1){fprintf(fout,"%d\n",5);break;}
    memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)//轴对称 顺时针转270°
    {
                                      newx=i;
                                      newy=n+1-j;
                                      temp[newx][newy]=date[i][j];
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    {
                                      newx=j;
                                      newy=n+1-i;
                                      temp2[newx][newy]=temp[i][j];
    }
    if(check2()==1){fprintf(fout,"%d\n",5);break;}
    memset(temp,0,sizeof(temp));
}
    d=0;
    for(i=1;i<=n;i++)
    {
                     for(j=1;j<=n;j++)
                     {
                                      if(date[i][j]!=s[i][j])
                                      {
                                                          d=1;
                                                          break;
                                      }
                     }
    }
    if(k==1&&d==0)fprintf(fout,"%d\n",6);
    else if(k==1) fprintf(fout,"%d\n",7);
exit(0);
}

int check()
{
    int i,j,d=0;
    for(i=1;i<=n;i++)
    {
                     for(j=1;j<=n;j++)
                     {
                                      if(s[i][j]!=temp[i][j])
                                      {
                                                          d=1;
                                                          break;
                                      }
                     }
    }
    if(d==0)return(1);
    else return(0);
}

int check2()
{
    int i,j,d=0;
    for(i=1;i<=n;i++)
    {
                     for(j=1;j<=n;j++)
                     {
                                      if(s[i][j]!=temp2[i][j])
                                      {
                                                          d=1;
                                                          break;
                                      }
                     }
    }
    if(d==0)return(1);
    else return(0);
}
