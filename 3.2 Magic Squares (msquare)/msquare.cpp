/*
ID: The One
LANG: C++
TASK: msquare
*/
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#define OPERATE_A 0
#define OPERATE_B 1
#define OPERATE_C 2

struct Plate
{
	long data[9];
	long& operator[] (long p) {return data[p];};
}stk[50000];

ifstream fin("msquare.in");
ofstream fout("msquare.out");
ostringstream sout;
string ans;

long pre[50000];
long dist[50000];
long method[50000];
bool b[50000] = {0};

long get_num(Plate& p)
{
	static const long mul[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
	long i, j;
	long cr = 0;
	for (i = 1; i < 8; ++i)
	{
		long ct = 0;
		for (j = i+1; j <= 8; ++j) if (p[i] > p[j]) ++ct;
		cr += ct * mul[8-i];
	}
	return cr+1;
}

void operate(Plate& dest, Plate& src, long op)
{
	switch(op)
	{
		case OPERATE_A:
			dest[1] = src[8]; dest[2] = src[7]; dest[3] = src[6]; dest[4] = src[5];
			dest[8] = src[1]; dest[7] = src[2]; dest[6] = src[3]; dest[5] = src[4];
			break;
		case OPERATE_B:
			dest[1] = src[4]; dest[2] = src[1]; dest[3] = src[2]; dest[4] = src[3];
			dest[8] = src[5]; dest[7] = src[8]; dest[6] = src[7]; dest[5] = src[6];
			break;
		case OPERATE_C:
			dest[1] = src[1]; dest[2] = src[7]; dest[3] = src[2]; dest[4] = src[4];
			dest[8] = src[8]; dest[7] = src[6]; dest[6] = src[3]; dest[5] = src[5];
			break;
	}
}

void output(long oi)
{
	if (pre[oi] != oi) output(pre[oi]);
	if (method[oi] >= 0) sout << (char)('A' + method[oi]);
}

int main()
{
	long i, j;
	Plate dest;
	for (i = 1; i <= 8; ++i) fin >> dest[i];
	long did = get_num(dest);
	if (did == 1) {fout << "0\n" << endl; return 0;}
	for (i = 1; i <= 8; ++i) stk[1][i] = i;
	pre[1] = 1; method[1] = -1;
	b[get_num(stk[1])] = true; dist[get_num(stk[1])] = 0;
	i = 1; j = 2;
	while (i < j)
	{
		long dk;
		long iid = get_num(stk[i]);
		if (iid == did)
		{
			output(i);
			break;
		}
		for (dk = 0; dk < 3; ++dk)
		{
			operate(stk[j], stk[i], dk);
			long jid = get_num(stk[j]);
			if (!b[jid])
			{
				b[jid] = true;
				dist[jid] = dist[iid] + 1;
				pre[j] = i;
				method[j] = dk;
				++j;
			}
		}
		++i;
	}
	fout << dist[did] << "\n";
	ans = sout.str();
	long times = ans.length() / 60;
	long remain = ans.length() % 60;
	for (i = 0; i < times; ++i) fout << ans.substr(i*60, 60) << "\n";
	if (remain) fout << ans.substr(times*60, remain) << "\n";
	return 0;
}
