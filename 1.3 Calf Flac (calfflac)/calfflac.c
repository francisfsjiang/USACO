/*
ID: TheOne
LANG: C
TASK: calfflac
*/
#include<stdio.h>
main()
{
      freopen("calfflac.in","r",stdin);
      freopen("calfflac.out","w",stdout);
      int i,j,k,n,sum,max=0,d,l,maxn,head,end;
      char date[20010],x;
      int date2[20010][2];
      for(i=0;;i++)
      {
             scanf("%c",&date[i]);
             //if(x>=97&&x<=122)x=x-32
             if(date[i]==0)break;
      }
      n=i;
      //printf("%d\n",n);
      //for(i=0;i<n;i++)printf("%c ",date[i]);
      //printf("\n");
      j=0;
      for(i=0;i<n;i++)
      {
             if(date[i]>=97&&date[i]<=122)
             {
                                          date2[j][0]=date[i]-32;
                                          date2[j][1]=i;
                                          j++;
             }
             else if(date[i]>=65&&date[i]<=90)
             {
                  date2[j][0]=date[i];
                  date2[j][1]=i;
                  j++;
             }
             
      }
      l=j;
      //for(j=0;j<l;j++)printf("%4d %4d\n",date2[j][0],date2[j][1]);
      for(i=1;i<l-1;i++)
      {
                      sum=0;
                      j=i-1;
                      k=i+1;
                      for(;j>=0&&k<l&&date2[j][0]==date2[k][0];j--,k++,sum++);
                      sum=sum*2+1;
                      //printf("%d=%d\n",i,sum);
                      if(sum>max)
                      {
                                 max=sum;
                                 maxn=i;
                      }
      }
      for(i=1;i<l-1;i++)
      {
                        if(date2[i][0]!=date2[i+1][0])continue;
                      sum=0;
                      j=i-1;
                      k=i+2;
                      for(;j>=0&&k<l&&date2[j][0]==date2[k][0];j--,k++,sum++);
                      sum=sum*2+2;
                      //printf("%d=%d  j=%d  k=%d\n",i,sum,j,k);
                      if(sum>=max)
                      {
                                 max=sum;
                                 maxn=i;
                      }
      }
      //printf("%d\n",max);
      if(max%2==1)
      {
                  printf("%d\n",max);
                  head=date2[maxn-(max-1)/2][1];
                  end=date2[maxn+(max-1)/2][1];
                  for(i=head;i<=end;i++)printf("%c",date[i]);
                  printf("\n");
      }
      else if(max!=0)
      {
                  printf("%d\n",max);
                  head=date2[maxn-(max-2)/2][1];
                  end=date2[maxn+1+(max-2)/2][1];
                  //printf("%d\n",maxn);
                  for(i=head;i<=end;i++)printf("%c",date[i]);
                  printf("\n");
      }
      else printf("0\n");
      exit(0);
}
