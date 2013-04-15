/*
ID: The One
TASK: nuggets
LANG: C++
*/
#include<iostream>
#include<cstdio>
#define bug(s) cout<<#s<<"="<<s<<endl;
using namespace std;
bool can[2000000]={false};

int gcd(int x,int y)
{
  if(y>x)
  {
    int temp=x;
    x=y;
    y=temp;
  }
  if(x%y==0)return y;
  else return gcd(y,x%y);
}

int main()
{
  freopen("nuggets.in","r",stdin);
  freopen("nuggets.out","w",stdout);
  int n,i,j;
  int data[15];
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>data[i];
    if(data[i]==1)
    {
      cout<<"0"<<endl;
      return 0;
    }
  }
  int temp=gcd(data[0],data[1]);
  for(int i=2;i<n;i++)temp=gcd(temp,data[i]);
  if(temp!=1)
  {
    cout<<"0"<<endl;
    return 0;
  }
  //bug(temp);
  int max1=0,max2=0;
  for(int i=0;i<n;i++)if(data[i]>max1)max1=data[i];
  for(int i=0;i<n;i++)if(data[i]>max2&&data[i]!=max1)max2=data[i];
  //bug(max1);
  //bug(max2);
  can[0]=1;
  int max=max1*max2;
  for(int i=0;i<n;i++)
  {
    for(int j=data[i];j<=max;j++)if(can[j-data[i]]==1)can[j]=1;
  }
  /*for(int i=0;i<=max;i++)printf("%2d ",i);
  printf("\n");
  for(int i=0;i<=max;i++)printf("%2d ",can[i]);*/
  for(int i=0;i<=max;i++)if(can[i]==0)max1=i;
  cout<<max1<<endl;
  return 0;
}

