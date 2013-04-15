/*
ID: The One
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
struct men
{
    char name[20];
}men[12];

main () 
{
     FILE *fin = fopen ("gift1.in","r");
     FILE *fout = fopen ("gift1.out","w");
     int i,n,sum[15]={0},money,a,j,k,c,d,w;
     char temp[15];
     fscanf(fin,"%d",&n);
     for(i=0;i<n;i++)fscanf(fin,"%s",men[i].name);
     for(i=0;i<n;i++)
     {
                     fscanf(fin,"%s%d%d",temp,&money,&a);
                     for(k=0;k<n;k++)
                     {
                                     w=strcmp(temp,men[k].name);
                                     if(w==0)
                                     {
                                             break;
                                     }
                     }
                     if(d==0||a==0)continue;
                     else d=money/a;
                     for(j=0;j<a;j++)
                     {
                                     fscanf(fin,"%s",temp);
                                     for(c=0;c<n;c++)
                                     {
                                                     w=strcmp(temp,men[c].name);
                                                     if(w==0)
                                                     {
                                                            sum[c]+=d;
                                                            sum[k]-=d;
                                                            break;
                                                     }
                                     }
                     }
     }
     for(i=0;i<n;i++){fprintf(fout,"%s %d\n",men[i].name,sum[i]);}
     exit(0);
}
