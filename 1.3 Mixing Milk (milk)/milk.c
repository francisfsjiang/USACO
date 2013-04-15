/*
ID: The One
LANG: C
TASK: milk
*/
#include<stdio.h>
int date[5002][2];
main()
{
      freopen("milk.in","r",stdin);
      freopen("milk.out","w",stdout);
      int n,m,i,j,sum=0;
      int qsort(int s,int t);
      scanf("%d%d",&n,&m);
      for(i=0;i<m;i++)
      {
                      scanf("%d%d",&date[i][0],&date[i][1]);
      }
      if(m!=0)qsort(0,m-1);
      for(i=0;i<m;i++)
      {
                      if(date[i][1]<n)
                      {
                                      sum+=date[i][0]*date[i][1];
                                      n-=date[i][1];
                      }
                      else 
                      {
                           sum+=date[i][0]*n;
                           break;
                      }
      }
      printf("%d\n",sum);
      return(0);
}
int qsort(int s,int t)
{
     int i,j,y,y2,temp,m,k;
     m=rand()%(t+1-s)+s;
     i=s-1;
     j=t+1;
     y=date[m][0];
     y2=date[m][1];
     for(;i<j;)
     {
                 for(i++;i<=t&&date[i][0]<y;i++);
                 for(j--;j>=0&&date[j][0]>y;j--);
                 if(i==m){j++;continue;}
                 if(j==m){i--;continue;}
                 if(i<j)
                 {
                        temp=date[i][0];
                        date[i][0]=date[j][0];
                        date[j][0]=temp;
                        temp=date[i][1];
                        date[i][1]=date[j][1];
                        date[j][1]=temp;
                 }
     }
     if(m<j)
     {
            date[m][0]=date[j][0];
            date[m][1]=date[j][1];
            date[j][0]=y;
            date[j][1]=y2;
     }
     else if(m>j)
     {
          date[m][0]=date[j+1][0];
          date[m][1]=date[j+1][1];
          date[j+1][0]=y;
          date[j+1][1]=y2;
     }
     if(s<j-1)qsort(s,j-1);
     if(j+1<t)qsort(j+1,t);
}
