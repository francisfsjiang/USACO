/*
ID: TheOne
LANG: C
TASK: palsquare
*/ 

#include<stdio.h>
int B,n,ns[100],s,ns1[100],s1;
main()
{
      freopen("palsquare.in","r",stdin);
      freopen("palsquare.out","w",stdout);
      int i,j;
      int change(int x,int a[],int y);
      int check(int a[],int y);
      int print(int a[],int y);
      scanf("%d",&B);
      for(i=1;i<=300;i++)
      {
                         s=change(i,ns,s);
                         s1=change(i*i,ns1,s1);
                         if(check(ns1,s1)==1)
                         {
                         //printf("*******************************\n");
                         //printf("%d\n",i);
                         //for(j=s-1;j>=0;j--)printf("%d ",ns[j]);
                         //printf("\n");
                         print(ns,s);
                         printf(" ");
                         //printf("%d\n",i*i);
                         
                         //for(j=s1-1;j>=0;j--)printf("%d ",ns1[j]);
                         //printf("\n");
                         print(ns1,s1);
                         printf("\n");
                         //printf("%d\n",check(ns1,s1));
                         }
      }
      return(0);
}

int check(int a[],int y)
{
    int i,j,d=1;
    for(i=0,j=y-1;i<=j;i++,j--)
    {
                               if(a[i]!=a[j])
                               {
                                              d=0;
                                              break;
                               }
    }
    if(d==1)return(1);
    else return(0);
}

int print(int a[],int y)
{
    int i;
    for(i=y-1;i>=0;i--)
    {
                       switch(a[i])
                       {
                       case 0:printf("0");break; 
                       case 1:printf("1");break; 
                       case 2:printf("2");break; 
                       case 3:printf("3");break; 
                       case 4:printf("4");break; 
                       case 5:printf("5");break; 
                       case 6:printf("6");break; 
                       case 7:printf("7");break; 
                       case 8:printf("8");break; 
                       case 9:printf("9");break; 
                       case 10:printf("A");break; 
                       case 11:printf("B");break; 
                       case 12:printf("C");break; 
                       case 13:printf("D");break; 
                       case 14:printf("E");break; 
                       case 15:printf("F");break;
                       case 16:printf("G");break;
                       case 17:printf("H");break;
                       case 18:printf("I");break;
                       case 19:printf("G");break;
                       }
    }
}
int change(int x,int a[],int y)
{
    int b,i;
    memset(a,0,sizeof(a));
    if(x<B){a[0]=x;y=-1;}
    else if (x==B){a[0]=0;a[1]=1;y=0;}
    else
    {
        for(y=0;;y++)
        {
                     b=x%B;
                     a[y]=b;
                     if(x-b==0){y--;break;}
                     else x=(x-b)/B;
                     if(x==1) 
                     {
                              a[y+1]=1;
                              break;
                     }
        }
    }
    y+=2;
    return(y);
}
