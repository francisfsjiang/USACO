/*
ID: The One
LANG: C
TASK: clocks
*/
#include<stdio.h>
int a[9][9]= { {3,3,3,3,3,2,3,2,0},
               {2,3,2,3,2,3,1,0,1},
               {3,3,3,2,3,3,0,2,3},
               {2,3,1,3,2,0,2,3,1},
               {2,3,2,3,1,3,2,3,2},
               {1,3,2,0,2,3,1,3,2},
               {3,2,0,3,3,2,3,3,3},
               {1,0,1,3,2,3,2,3,2},
               {0,2,3,2,3,3,3,3,3} };
int v[9];
 
int main() 
{
    FILE *fin = fopen ("clocks.in","r");
    FILE *fout = fopen ("clocks.out","w");
    int i,j,k;
    for (i=0; i<9; i++) {
        fscanf(fin,"%d",&k);
        for(j=0; j<9; j++)
             v[j]=(v[j]+(4-k/3)*a[i][j])%4;
    }
    fclose(fin);
    k=0;
    for (i=0; i<9; i++)
        for (j=0; j<v[i]; j++)
            if (!k) { fprintf(fout,"%d",i+1); k=1; }
            else    fprintf(fout," %d",i+1);
    fprintf(fout,"\n");
    fclose(stdout);
    return 0;
}
