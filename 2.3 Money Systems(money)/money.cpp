
/*
ID: The One
LANG: C++
TASK: money
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
 
long long Dp[ 10001 ];
long V,N;
long Kind[ 26 ];
 
int main(){
    long i,j;
    fin >> V >> N;
    for(i = 1; i <= V; i ++) fin >> Kind[ i ];
    Dp[ 0 ] = 1;
 
    for(i = 1; i <= V; i ++)
        for(j = Kind[ i ]; j <= N; j ++)
                Dp[ j ] = Dp[ j ] + Dp[ j-Kind[i] ];
    fout << Dp[ N ] << endl;
    return 0;
}
