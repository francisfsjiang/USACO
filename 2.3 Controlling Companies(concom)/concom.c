/*
ID: The One
LANG: C
TASK: concom
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#define NCOM 101
 
int owns[NCOM][NCOM];        /* [i,j]: i直接、间接拥有了j的多少股份？ */
int controls[NCOM][NCOM];    /* [i, j]: i是否控制j？ */
 
/* 更新信息：现在i控制了j */
void
addcontroller(int i, int j)
{
    int k;
 
    if(controls[i][j])        /* 控制关系已知 */
        return;
 
    controls[i][j] = 1;
 
    /* 现在i控制了j，把j拥有的股份都加到i上 */
	for(k=0; k<NCOM; k++)
        owns[i][k] += owns[j][k];
 
    /* 记录：i的控制者现在也控制了j */
	for(k=0; k<NCOM; k++)
        if(controls[k][i])
            addcontroller(k, j);
 
    /* 如果现在i控制了更多的公司，则记录 */
    for(k=0; k<NCOM; k++)
        if(owns[i][k] > 50)
            addcontroller(i, k);
}
 
/* 更新信息：i拥有j的p%股份 */
void
addowner(int i, int j, int p)
{
    int k;
 
    /* 给每个i的控制者增加j的p%股份 */
	for(k=0; k<NCOM; k++)
        if(controls[k][i])
            owns[k][j] += p;
 
    /* 寻找j的新控制者 */
	for(k=0; k<NCOM; k++)
        if(owns[k][j] > 50)
            addcontroller(k, j);
}
 
void
main(void)
{
    FILE *fin, *fout;
    int i, j, n, a, b, p;
 
    fin = fopen("concom.in", "r");
    fout = fopen("concom.out", "w");
    assert(fin != NULL && fout != NULL);
 
    for(i=0; i<NCOM; i++)
        controls[i][i] = 1;
 
    fscanf(fin, "%d", &n);
    for(i=0; i<n; i++) {
        fscanf(fin, "%d %d %d", &a, &b, &p);
        addowner(a, b, p);
    }
 
    for(i=0; i<NCOM; i++)
    for(j=0; j<NCOM; j++)
        if(i != j && controls[i][j])
            fprintf(fout, "%d %d\n", i, j);
    exit(0);
}
