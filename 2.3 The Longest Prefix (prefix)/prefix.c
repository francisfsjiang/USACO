/*
ID: The One
LANG: C++
TASK: prefix
*/
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
string hash[20001];
long len=0;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
bool find(string st){
	for(long i=1;i<=len;i++)
		if(hash[i]==st)return true;
	return false;
}
int main(int argc,char** argv){
	string st,ss;
	fin >>ss;
	bool f[200002]={false};
	while(ss!=".")
		if(ss.length()){
			hash[++len]=ss;
			fin >>ss;
		}
	f[0]=1;
	fin.get();
	getline(fin,ss);
	while(ss!="**"){
		st=st+ss;
		ss="**";
		getline(fin,ss);
	}
	st="8"+st;//很关键的一步，实在受不了c++的string下标从0开始
	for(long i=1;i<=st.length();i++)
		for(long j=1;j<=len;j++)
			if(i>hash[j].length()-1){
			f[i]=f[i-hash[j].length()]&(hash[j]==st.substr(i-hash[j].length()+1,hash[j].length()));
			if(f[i])break;
		}
	for(long p=st.length();p>=1;p--)
		if(f[p]){fout <<p<<endl;	fin.close();fout.close();exit(0);}
	fout <<0<<endl;
		fin.close();fout.close();
	return 0;
}
