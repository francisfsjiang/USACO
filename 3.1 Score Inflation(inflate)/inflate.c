/*
ID: The One
LANG: C
TASK: inflate
*/
#include<stdio.h>
main()
{
      FILE *in=fopen("inflate.in","r"),*out=fopen("inflate.out","w");
      int i,j,data[10002][2],time,num=0,sum,temp,f[10005];
      fscanf(in,"%d%d",&time,&sum);
      memset(f,0,sizeof(f));
      //fprintf(out,"%d %d\n",time,sum);
      for(i=0;i<sum;i++)
      {
                        fscanf(in,"%d%d",&data[i][0],&data[i][1]);
      }
      for(i=0;i<sum;i++)
      {
                        for(j=data[i][1];j<=time;j++)
                        {
                                            temp=f[j-data[i][1]]+data[i][0];
                                            if(temp>f[j])f[j]=temp;
                        }
                        //for(j=0;j<=time;j++)fprintf(out,"%d ",f[j]);
                        //fprintf(out,"\n");
      }
      for(i=0;i<=time;i++)
      {
                          if(f[i]>num)num=f[i];
      }
      fprintf(out,"%d\n",num);
      return(0);
}
