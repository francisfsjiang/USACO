/*
ID:The One
TASK:contact
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
int a,b,n,t,x,y,val[16385],c[200020];
string tostring(int ord,int length){
    string tempstr;
    int aaa=ord;
    char j[12]={'\0'};
    for(int i=length-1;i>=0;i--){
        if ((aaa&1)==1){j[i]='1';}
        else{j[i]='0';}
        aaa>>=1;
    }
    return tempstr=j;
}
inline int cmp(string a1,string a2){
    if (a1.length() > a2.length() ) return 1;
    if (a1.length() < a2.length() ) return 0;
    return a1.compare(a2);
}
int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    std::ios::sync_with_stdio(false);
    char temp='1';
    cin>>a>>b>>n;
    while ( cin>>temp ){
        if (temp==49){
            c[t]=1;
            t++;
        }
        else if (temp==48){
            c[t]=0;
            t++;
        }
    };
    for (int i=a;i<=b;i++)
        for(int j=0;j<t-i+1;j++){
            x=0;
            for(int k=0;k<i;k++)
                (x<<=1)+=c[j+k];
            val[x+(1<<i)]++;
        }
    while(n--){
        int max=0,temp[16385],z=0;
        string output[16384];
        for (int i=0;i<16385;i++)
            if (max<val[i]){max=val[i];}
        if (max==0) return 0;
        for (int i=0;i<16385;i++)
            if (max==val[i]){
                temp[z]=i;
                z++;
                val[i]=0;
            }
        cout<<max<<endl;
        for (int i=0;i<z;i++)
            output[i]=tostring(temp[i],(int)(log(temp[i])/log(2)+0.0001));
        for(int i=0;i<z-1;i++)
            for(int j=0;j<z-i-1;j++)
                if (cmp(output[j],output[j+1])>0) swap(output[j],output[j+1]);
        for(int i=0;i<z-1;i++){
            cout<<output[i];
            if (i%6==5) cout<<endl;
            else cout<<' ';
        }
        cout<<output[z-1]<<endl;
    }
    return 0;
}
