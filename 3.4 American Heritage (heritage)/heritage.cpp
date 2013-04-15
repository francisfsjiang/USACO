/*
ID:The One
TASK:heritage
LANG:C++
*/
#include<iostream>
#include<cstdio>
#define bug(s) cout<<#s<<"="<<s<<endl
using namespace std;
string in,pre,post(20000,0);

void search(int in_s,int in_t,int pre_s,int pre_t,int fa)
{
  /*bug(in_s);
  bug(in_t);
  bug(pre_s);
  bug(pre_t);
  bug(fa);
  cout<<"------"<<endl;*/
  int pos;
  post[fa]=pre[pre_s];
  if(in_s==in_t)return;
  for(pos=in_s;pos<in.size();pos++)if(in[pos]==pre[pre_s])break;
  if(in_s<=pos-1)search(in_s,pos-1,pre_s+1,pre_s+pos-in_s,(fa+1)*2-1);
  if(pos+1<=in_t)search(pos+1,in_t,pre_t+pos+1-in_t,pre_t,(fa+1)*2);
}

void print(int x)
{
  if(post[x]==0)return;
  print((x+1)*2-1);
  print((x+1)*2);
  cout<<post[x];
}

int main()
{
  freopen("heritage.in","r",stdin);
  freopen("heritage.out","w",stdout);
  cin>>in>>pre;
  //cout<<in.size();
  //cout<<in<<endl<<pre<<endl;
  search(0,in.size()-1,0,pre.size()-1,0);
  //for(int i=0;i<15;i++)if(post[i]!=0)cout<<post[i];
  //cout<<post<<endl;
  print(0);
  cout<<endl;
  return (0);
}
