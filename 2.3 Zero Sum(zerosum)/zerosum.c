/*
ID: The One
LANG: C
TASK: zerosum
*/
#include <stdio.h>
#include <stdlib.h>
FILE *fout;
int k[20];
long n;
long a,b;
 
int  out()
{long i;
fprintf(fout,"1");
 for(i=1;i<n;i++)
 {
  if(k[i+1]==1)fprintf(fout,"+");
  if(k[i+1]==2)fprintf(fout,"-");
  if(k[i+1]==3)fprintf(fout," ");
  fprintf(fout,"%d",i+1);
}
fprintf(fout,"\n");
}
 
int  begin(long x,long y,long v,int s)
{if(v<=n)
{k[v]=3;
 begin(x,y*10+v,v+1,s);
 if(s==1)x+=y;
 else x-=y;
 k[v]=1;begin(x,v,v+1,1);
 k[v]=2;begin(x,v,v+1,2);
 
}
else {if(s==1)x+=y;
else x-=y;
if (x==0&&k[1]==1)out();}}
 
int main(int argc, char *argv[])
{FILE *fin=fopen("zerosum.in","r");
 fout=fopen("zerosum.out","w");
 fscanf(fin,"%d",&n);
 a=0;
 begin(0,0,1,1);
  return 0;
}
