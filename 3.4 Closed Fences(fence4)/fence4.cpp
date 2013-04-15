/*
ID:The One
TASK: fence4
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;
int max(int x,int y)
{
  if(x>y)return x;
  else return y;
}
int min(int x,int y)
{
  if(x>y)return y;
  else return x;
}
struct point
{
  int x,y;
}looker;


int direction(struct point a,struct point b,struct point c)
{
  return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}

double dist(struct point a,struct point b)
{
  return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void crosspoint(struct point a,struct point b,struct point c,struct point d,double *x,double *y)
{
  double k1,k2;
  k1=(double)(a.y-b.y)/(a.x-b.x);
  k2=(double)(c.y-d.y)/(c.x-d.x);
  *x=(k1*a.x-k2*c.x-a.y+c.y)/(k1-k2);
  *y=k1*(*x)-k1*a.x+a.y;
}

int quickexclude(struct point a,struct point b,struct point c,struct point d)
{
  if(max(min(a.x,b.x),min(c.x,d.x))>
     min(max(a.x,b.x),max(c.x,d.x))||
     max(min(a.y,b.y),min(c.y,d.y))>
     min(max(a.y,b.y),max(c.y,d.y)))return false;
  else return true;
}

int meet(struct point a,struct point b,struct point c,struct point d)
{
  if(!quickexclude(a,b,c,d))return false;
  else
  {
    int d1=direction(c,d,a),d2=direction(c,d,b),d3=direction(a,b,c),d4=direction(a,b,d);
    if(d1*d2<0&&d3*d4<0)
    {
      cout<<endl<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
      return true;
    }
    else return false;
  }
}

int main()
{
  freopen("fence4.in","r",stdin);
  freopen("fence4.out","w",stdout);
  vector<point> map;
  int n,x,y,targetx,targety;
  int viewed[300]={0};
  double mm,ml,mr,s1,s2;
  struct point temp;
  cin>>n;
  cin>>looker.x>>looker.y;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    temp.x=x;
    temp.y=y;
    map.push_back(temp);
  }
  map.push_back(map[0]);
  //for(int i=0;i<n;i++)cout<<i<<" "<<map[i].x<<" "<<map[i].y<<" "<<map[i+1].x<<" "<<map[i+1].y<<endl;
  for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(meet(map[i],map[i+1],map[j],map[j+1]))
  {
    cout<<"NOFENCE"<<endl;
    return 0;
  }
  struct point target;
  int temp1,temp2,viewedone;
  double crossx,crossy;
  //crosspoint(map[0],map[1],map[2],map[3],&crossx,&crossy);
  //cout<<crossx<<" "<<crossy;
  //s1=dist(map[i],map[i+1]);
  for(int j=0;j<n;j++)
  {
    int sign;
    if(j-1<0)sign=n-1;
    else sign=j-1;
    //if(j-n<0)
    //{
      target.x=map[j].x;
      target.y=map[j].y;
    /*}
    else
    {
      target.x=(map[j-n].x+map[j-n+1].x)/2;
      target.y=(map[j-n].y+map[j-n+1].y)/2;
      if(target.x<0)target.x=-target.x;
      if(target.y<0)target.y=-target.y;
    }*/
    mm=mr=ml=-1;
      cout<<"*******************************"<<endl<<looker.x<<" "<<looker.y<<" "<<target.x<<" "<<target.y<<endl<<"***********************************************"<<endl;
    for(int i=0;i<n;i++)
    {
      if(i==sign||i==j)continue;
      temp1=direction(looker,target,map[i]);
      temp2=direction(looker,target,map[i+1]);
      s1=dist(looker,map[i]);
      s2=dist(looker,map[i+1]);
      if((map[i].x-looker.x)*(target.x-looker.x)<=0&&(map[i].y-looker.y)*(target.y-looker.y)<=0)s1=-1;
      if((map[i+1].x-looker.x)*(target.x-looker.x)<=0&&(map[i+1].y-looker.y)*(target.y-looker.y)<=0)s2=-1;
      //cout<<"*"<<temp1<<" "<<temp2<<" "<<s1<<" "<<s2<<" "<<endl;
      if(temp1*temp2<0)
      {
	if(s1==-1&&s2==-1)continue;
	if(looker.x==target.x)
	{
	  s2=(map[i].y-map[i+1].y)/(map[i].x-map[i+1].x)*(looker.x-map[i].x)+map[i].y;
	  if(s2>looker.y)s1=s2-looker.y;
	  else s1=looker.y-s2;
	  if(s1<mm||mm==-1)
	  {
	    mm=s1;
	    viewedone=i;
	  }
	}
	else
	{
	  crosspoint(looker,target,map[i],map[i+1],&crossx,&crossy);
	  //cout<<crossx<<" "<<crossy<<endl;
	  if((target.x-looker.x)*(crossx-looker.x)<0.00000001)continue;
	  s1=sqrt((crossx-looker.x)*(crossx-looker.x)+(crossy-looker.y)*(crossy-looker.y));
	  //cout<<s1<<endl;
	  if(s1<mm||mm==-1)
	  {
	    mm=s1;
	    viewedone=i;
	  }
	}
      }
      else if(temp1==0&&temp2==0)
      {
	if(s1<s2)s1=s2;
	if(ml<s1)ml=s1;
	if(mr<s1)mr=s1;
      }
      else if(temp1==0)
      {
	if(temp2>0)mr=s1;
	else ml=s1;
      }
      else if(temp2==0)
      {
	if(temp1>0)mr=s2;
	else mr=s2;
      }
    }
    cout<<mm<<" "<<mr<<" "<<ml<<" "<<viewedone<<endl<<"--------------------------------"<<endl;
    if(mm==-1)
    {
      int last,d1,d2;
      if(j-1<0)last=n-1;
      else last=j-1;
      if(mr==-1&&ml==-1)
      {
        viewed[last]=1;
        viewed[j]=1;
      }
      else
      {
	d1=direction(looker,target,map[last]);
	d2=direction(looker,target,map[j]);
	if(mr==-1)
	{
	  if(d1>0)viewed[last]=1;
	  else viewed[j]=1;
	}
	else if(ml==-1)
	{
	  if(d1<0)viewed[last]=1;
	  else viewed[j]=1;
	}
      }
    }
    else
    {
      if((mm<ml||ml==-1)||(mm<mr||mr==-1))
      {
	viewed[viewedone]=1;
      }
    }
    for(int i=0;i<n;i++)cout<<i<<" "<<viewed[i]<<endl;
  }
  int prints[250],printt[250],printd[250]={0},sum=0;
  for(int i=0;i<n;i++)if(viewed[i]==1)sum++;
  for(int i=0;i<n-2;i++)
  {
    prints[i]=i;
    printt[i]=i+1;
    printd[i]=viewed[i];
  }
  prints[n-2]=n;
  printt[n-2]=n-1;
  printd[n-2]=viewed[n-1];
  prints[n-1]=n-2;
  printt[n-1]=n-1;
  printd[n-1]=viewed[n-2];
  cout<<sum<<endl;
  for(int i=0;i<n;i++)
  {
    if(printd[i]==1)
    {
      cout<<map[prints[i]].x<<" "<<map[prints[i]].y<<" "<<map[printt[i]].x<<" "<<map[printt[i]].y<<endl;
    }
  }
  return 0;
}
