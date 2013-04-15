/*
ID: The One
LANG: C
TASK: namenum
*/
#include <stdio.h>
int name[4619][15];
int b[10][4]={{0},{0},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R'},{'S','T','U'},{'V','W','X'}};
main()
{
      FILE *in,*out;
      int i,j,l,d=0;
      char n[20];
      in=fopen("dict.txt","r");
      out=fopen("namenum.out","w");
      //memset(name,0,sizeof(name));
      for(i=0;i<4617;i++)
      {
                         fscanf(in,"%s",n);
                         l=strlen(n);
                         for(j=0;j<l;j++)
                         {
                                         name[i][j]=n[j];
                         }
      }
      in=fopen("namenum.in","rt+");
      fscanf(in,"%s",n);
      d=0;
      l=strlen(n);
      for(i=0;i<l;i++)
      {
                      n[i]=n[i]-48;
      }
      for(i=0;i<4617;i++)
      {
                         for(j=0;j<l;)
                         {
                                      if(name[i][j]==b[n[j]][0]||name[i][j]==b[n[j]][1]||name[i][j]==b[n[j]][2])j++;
                                      else break;
                         }
                         if(j==l&&name[i][l]==0)
                         {
                               for(j=0;j<l;j++)
                               {
                                      fprintf(out,"%c",name[i][j]);
                                      d=1;
                               }
                               fprintf(out,"\n");
                         }
      }
      if(d==0)fprintf(out,"NONE\n");
      exit(0);
}
