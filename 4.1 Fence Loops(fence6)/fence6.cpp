/*
ID:The One
TASK:fence6
LANG:C++
*/
#include<iostream>
#include<cstdio>
#define MAX 999999
using namespace std;

int map[105][105]={0};
int oldmap[105][105]={0};
int f[105][105]={0};

int main()
{
  freopen("fence6.in","r",stdin);
  freopen("fence6.out","w",stdout);
  int n,n1s,n2s,x,y,p;
  int temp[10];
  int len,tp;
  int sign=0;
  cin>>n;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(map[i][j]==0)
  {
    map[i][j]=MAX;
    oldmap[i][j]=MAX;
  }
  for(int i=1;i<=n;i++)
  {
    cin>>p>>len>>n1s>>n2s;
    for(int j=0;j<n1s;j++)cin>>temp[j];
    temp[n1s]=p;
    if(f[temp[0]][temp[1]]==0)
    {
      sign++;
      for(int ii=0;ii<=n1s;ii++)for(int jj=0;jj<=n1s;jj++)
      {
	if(ii==jj)continue;
	f[temp[ii]][temp[jj]]=sign;
      }
    }
    x=f[temp[0]][temp[1]];
    for(int j=0;j<n2s;j++)cin>>temp[j];
    temp[n2s]=p;
    if(f[temp[0]][temp[1]]==0)
    {
      sign++;
      for(int ii=0;ii<=n2s;ii++)for(int jj=0;jj<=n2s;jj++)
      {
	if(ii==jj)continue;
	f[temp[ii]][temp[jj]]=sign;
      }
    }
    y=f[temp[0]][temp[1]];
    map[x][y]=len;
    map[y][x]=len;
    oldmap[x][y]=len;
    oldmap[y][x]=len;
  }
  /*for(int i=1;i<=sign;i++)
  {
    for(int j=1;j<=sign;j++)cout<<map[i][j]<<" ";
    cout<<endl;
  }*/
  int mincircle=MAX;
  for(int k=1;k<=sign;++k)
  {
    //新增部分:
    for(int i=1;i<=k;++i)
    {
      for(int j=i+1;j<=k;++j)
      {
	tp=map[i][j]+oldmap[i][k]+oldmap[j][k];
	if(tp<mincircle)mincircle=tp;
      }
    }
    //通常的 floyd 部分:
    for(int i=1;i<=sign;i++)for(int j=1;j<=sign;j++)
    {
      tp=map[i][k]+map[k][j];
      if(tp<map[i][j])
      {
	map[i][j]=tp;
	//map[j][i]=tp;
      }
    }
  }
  cout<<mincircle<<endl;
  /*for(int i=1;i<=sign;i++)
  {
    for(int j=1;j<=sign;j++)cout<<map[i][j]<<" ";
    cout<<endl;
  }*/
  return 0;
}
