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
 
int owns[NCOM][NCOM];        /* [i,j]: iֱ�ӡ����ӵ����j�Ķ��ٹɷݣ� */
int controls[NCOM][NCOM];    /* [i, j]: i�Ƿ����j�� */
 
/* ������Ϣ������i������j */
void
addcontroller(int i, int j)
{
    int k;
 
    if(controls[i][j])        /* ���ƹ�ϵ��֪ */
        return;
 
    controls[i][j] = 1;
 
    /* ����i������j����jӵ�еĹɷݶ��ӵ�i�� */
	for(k=0; k<NCOM; k++)
        owns[i][k] += owns[j][k];
 
    /* ��¼��i�Ŀ���������Ҳ������j */
	for(k=0; k<NCOM; k++)
        if(controls[k][i])
            addcontroller(k, j);
 
    /* �������i�����˸���Ĺ�˾�����¼ */
    for(k=0; k<NCOM; k++)
        if(owns[i][k] > 50)
            addcontroller(i, k);
}
 
/* ������Ϣ��iӵ��j��p%�ɷ� */
void
addowner(int i, int j, int p)
{
    int k;
 
    /* ��ÿ��i�Ŀ���������j��p%�ɷ� */
	for(k=0; k<NCOM; k++)
        if(controls[k][i])
            owns[k][j] += p;
 
    /* Ѱ��j���¿����� */
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
