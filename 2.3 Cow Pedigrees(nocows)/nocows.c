/*
ID: The One
LANG: C
TASK: nocows
*/
#include <stdio.h>
int MOD=9901;
 
int table[101][202],N,K,c;
int smalltrees[101][202];
 

 
int main()
{
    FILE *fin=fopen("nocows.in","r");
FILE *fout=fopen("nocows.out","w");
int i,j,k;
    fscanf (fin,"%d %d",&N,&K);
    table[1][1]=1;
    for (i=2;i<=K;i++) {
        for (j=1;j<=N;j+=2)
            for (k=1;k<=j-1-k;k+=2) {
                if (k!=j-1-k) c=2; else c=1;  //�ж����Ľṹ�Ƿ�Գ�  
                table[i][j]+=c*(
                        smalltrees[i-2][k]*table[i-1][j-1-k]  // ���������С��i-1
                        +table[i-1][k]*smalltrees[i-2][j-1-k]  // ���������С��i-1
                        +table[i-1][k]*table[i-1][j-1-k]);// ��Ϊi-1
                table[i][j]%=MOD;
            }
        for (k=0;k<=N;k++) { 
        // ȷ����������i�ε����е�smalltrees[i-2][j]���������С��i-1�ҽڵ���Ϊj�����ĸ���
            smalltrees[i-1][k]+=table[i-1][k]+smalltrees[i-2][k]; 
            smalltrees[i-1][k]%=MOD; 
        }
    }
 
    fprintf (fout,"%d\n",table[K][N]);
    return 0;
}
