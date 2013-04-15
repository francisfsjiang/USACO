/*
ID: The One
LANG: C
TASK: milk3
*/
#include<stdio.h>
int date[21]={0},dd[202030]={0};
int v[4]={0},iv[4]={0};
FILE *in;
FILE *out;
main()
{
      in=fopen("milk3.in","r");
      out=fopen("milk3.out","w");
      int search();
      int i;
      fscanf(in,"%d%d%d",&iv[1],&iv[2],&iv[3]);
      v[3]=iv[3];
      search();
      for(i=0;i<=20;i++)if(date[i]==1){fprintf(out,"%d",i);break;}
      for(i++;i<=20;i++)if(date[i]==1)fprintf(out," %d",i);
		  fprintf(out,"\n");
      return 0;
}

int search()
{
    int i,j,tempi,tempj,sum;
    sum=v[1]*10000+v[2]*100+v[3];
    if(dd[sum]==1)return 0;
    dd[sum]=1;
    if(v[1]==0)
    {
               date[v[3]]=1;
    }
    if((v[1]<iv[1]&&v[2]==0&&v[3]==0)||(v[2]<iv[2]&&v[1]==0&&v[3]==0)||(v[3]<iv[3]&&v[2]==0&&v[1]==0))return;
    for(i=1;i<=3;i++)
    {
                     if(v[i]!=0)
                     {
                                for(j=1;j<=3;j++)
                                {
                                                 if(i!=j)
                                                 {
                                                               tempi=v[i];
                                                               tempj=v[j];
                                                               v[j]=v[j]+v[i];
                                                               if(v[j]>iv[j]){v[i]=v[j]-iv[j];
                                                               v[j]-=v[i];}
															   else v[i]=0;
                                                               search();
                                                               v[j]=tempj;
                                                               v[i]=tempi;
                                                 }
                                }
                     }
    }
}
