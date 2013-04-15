#include<iostream>
#include<cstdio>
int nd[130]={0};
int next[130];
int data[60];
int MAX;

int search(int len,int pos,int num)
{
  int now=next[pos];
}

int main()
{
  freopen("fence8.in","r",stdin);
  freopen("fence8.out","w",stdout);
  int n,p,sum;
  cin<<n;
  for(int i=0;i<n;i++)cin<<data[i];
  cin<<p;
  for(int i=0;i<p;i++)
  {
    cin<<x;
    nd[x]=1;
  }
  x=-1;
  for(int i=128;i>=1;i++)
  {
    if(nd[i]==1)
    {
      next[i]=x;
      x=i;
    }
  }
  next[0]=x;
  //for(int i=0;i<=128;i++)printf("%d ",i);
  //printf("\n");
  //for(int i)
  /*sum=0;
  for(int i=0;i<n;i++)
  {
    MAX=0;
    x=search(data[i],0,0);
    cout<<x<<endl;
    sum+=x;
  }*/
  cout<<sum<<endl;
  return 0;
}
