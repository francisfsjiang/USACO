/*
ID: The One
LANG: C++
TASK: dualpal
*/
#include<fstream>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
int main()
{
    int n,i,j,k,m,t;
    int a[1000]={0},b[1000]={0};
    fin>>n>>m;
    int e=0,d,o;
    for(i=m+1;e<n;i++)
    {
        o=0;
        for(j=2;j<=10;j++)
        {
            
            for(k=0;k<1000;k++){a[k]=0;b[k]=0;}
            t=0;d=i;
            while(d>0)
            {  
                a[t]=d%j;
                t++;d=d/j;           
            }           
             d=0;
            for(k=0;k<=t-1;k++)
            {
                if(a[k]!=a[t-1-k]){d=1;break;}    
            }
            if(d==0)o++;
            if(o==2){e++;fout<<i<<endl;break;}
        }
    }
    return 0;    
}
