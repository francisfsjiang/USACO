/*
ID: The One
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <string.h>
main () {
    FILE *fin=fopen("beads.in","r");
    FILE *fout=fopen("beads.out","w");
    int n,w=0,a=0,b=0,m=0,i;                //w記錄至目前為止之白色珠子數(可接前後兩端),a為上一段珠子數,b為本段珠子數,m為目前為止a+b之最大值
    char s[701]={0},nowc=0;                 //nowc記錄目前顏色
    fscanf(fin,"%d%*c",&n);
    fgets(s,351,fin);
    memcpy(s+n,s,n);                        //將兩條項鍊接在一起
    for (i=0;s[i]&&m<n;++i){
        if (s[i]=='w')++w,++b;
        else if (nowc!=s[i]){
             if (a+b>m)m=a+b;               //顏色變換時方須判定a+b是否大於m
             a=b-w,b=w+1,w=0,nowc=s[i];     //顏色變換時操作各記錄數據
        }
        else ++b,w=0;
    }
    if (a+b>m)m=a+b;
    fprintf(fout,"%d\n",m>n?n:m);           //若m>n表所有珠子皆可取出
    return 0;
}
