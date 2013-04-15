/*
ID: The One
LANG: C
TASK: friday
*/
#include <stdio.h>

main () 
{
     FILE *fin = fopen ("friday.in","r");
     FILE *fout = fopen ("friday.out","w");
     int n,i,j,k,p,week=1,s[8]={0},m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     fscanf(fin,"%d",&n);
     for(i=1900;i<1900+n;i++)
     {
                     if(i%100==0)
                     {
                                 if(i%400==0)m[2]=29;
                                 else m[2]=28;
                     }
                     else
                     {
                         if(i%4==0)m[2]=29;
                         else m[2]=28;
                     }
                     for(j=1;j<=12;j++)
                     {
                                       for(k=1;k<=m[j];k++)
                                       {
                                                           if(k==13)s[week]++;
                                                           week++;
                                                           if(week==8)week=1;
                                       }
                     }
     }
     fprintf(fout,"%d %d",s[6],s[7]);
     for(p=1;p<=5;p++)fprintf(fout," %d",s[p]);
     fprintf(fout,"\n");
     exit(0);
}
                                                           
                                                                   
     
