/*
ID: The One
LANG: C
TASK: sprime
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int n;
 
int check(int a)
{
    if(a==1)
        return 1;
    if(a==2)
        return 0;
    int i,e;
    e=(int)sqrt(a);
    for(i=2;i<=e;i++)
        if(a%i==0)
            return 1;
    return 0;
}
 
void dfs(int num,int deep)
{
    if(deep>n)
        return;
    if(check(num)==0)
        if(deep==n)
            printf("%d\n",num);
        else
        {
            dfs(num*10+1,deep+1);
            dfs(num*10+3,deep+1);
            dfs(num*10+5,deep+1);
            dfs(num*10+7,deep+1);
            dfs(num*10+9,deep+1);
        }
    else
        return;
}
 
int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&n);
    dfs(1,1);   
    dfs(2,1);   
    dfs(3,1);   
    dfs(4,1);   
    dfs(5,1);   
    dfs(6,1);   
    dfs(7,1);   
    dfs(8,1);   
    dfs(9,1);   
    return 0;
}
