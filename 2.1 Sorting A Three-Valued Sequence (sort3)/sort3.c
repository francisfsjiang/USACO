/*
ID: The One
LANG: C
TASK: sort3
*/
#include <stdio.h>

main () 
{
     FILE *in = fopen ("sort3.in","r");
     FILE *out = fopen ("sort3.out","w");
     int date[2000],date2[2000],temp[2000]={0},n,i,j,k,x,sum=0;
     fscanf(in,"%d",&n);
     for(i=0;i<n;i++){fscanf(in,"%d",&date[i]);date2[i]=date[i];}
     //for(i=0;i<n;i++)fprintf(out,"%2d ",i);
     //fprintf(out,"\n");
     //for(i=0;i<n;i++)fprintf(out,"%2d ",date[i]);
     //fprintf(out,"\n");
     for(i=0;i<n;i++)for(j=0;j<n-i-1;j++)
     {
                                       if(date2[j]>date2[j+1])
                                       {
                                                              x=date2[j];
                                                              date2[j]=date2[j+1];
                                                              date2[j+1]=x;
                                       }
     }
     //for(i=0;i<n;i++)fprintf(out,"%2d ",date2[i]);
     //fprintf(out,"\n");
     for(i=0;i<n;i++)if(date[i]==date2[i])temp[i]=1;
     //for(i=0;i<n;i++)fprintf(out,"%2d ",temp[i]);
     //fprintf(out,"\n");
     for(i=0;i<n;i++)
     {
                     if(temp[i]==0)
                     {
                                   for(j=0;j<n;j++)
                                   {
                                                   if(i!=j&&temp[j]==0&&date2[i]==date[j]&&date2[j]==date[i])
                                                   {
                                                                sum++;
                                                                temp[i]=1;
                                                                temp[j]=1;
                                                                //fprintf(out,"%d-%d\n",i,j);
                                                                 break;
                                                   }

                                   }
                     }
     }
     for(i=0;i<n;i++)
     {
                     if(temp[i]==0)
                     {
                                   for(j=0;j<n;j++)
                                   {
                                                   if(i!=j&&temp[j]==0&&date2[i]==date[j])
                                                   {
                                                               for(k=0;k<n;k++)
                                                               {
                                                                   if(k!=i&&k!=j&&temp[k]==0&&date[k]==date2[j]&&date2[k]==date[i])
                                                                   {
                                                                       sum+=2;
                                                                       temp[i]=1;
                                                                       temp[j]=1;
                                                                       temp[k]=1;
                                                                       //fprintf(out,"%d-%d-%d\n",i,j,k);
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                   }
                                   }
                     }
     }
     fprintf(out,"%d\n",sum);
     return 0;
}
