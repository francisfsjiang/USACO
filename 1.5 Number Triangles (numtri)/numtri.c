/*
ID: The One
LANG: C
TASK: numtri
*/
#include<stdio.h>
int date[1002][1002];
main()
{    
     FILE *fin=fopen("numtri.in","r");
     FILE *fout=fopen("numtri.out","w");
     int n,i,j;
     fscanf(fin,"%d",&n);
     for (i=0;i<n;i++)
     {
         for (j=0;j<=i;j++)
         {
         fscanf(fin,"%d",&date[i][j]);
         }
     }
     for (i=n-2;i>=0;i--)
     {
         for (j=i+1;j>=0;j--)
         {
             if(date[i+1][j]>=date[i+1][j+1])
             {
                   date[i][j]+=date[i+1][j];
             }                              
             else 
             {
                  date[i][j]+=date[i+1][j+1];
             }     
         
         }
     }
     fprintf(fout,"%d\n",date[0][0]);
     return(0);
}

