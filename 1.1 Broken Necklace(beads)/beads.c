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
    int n,w=0,a=0,b=0,m=0,i;                //wӛ���Ŀǰ��ֹ֮��ɫ���Ӕ�(�ɽ�ǰ��ɶ�),a����һ�����Ӕ�,b�鱾�����Ӕ�,m��Ŀǰ��ֹa+b֮���ֵ
    char s[701]={0},nowc=0;                 //nowcӛ�Ŀǰ�ɫ
    fscanf(fin,"%d%*c",&n);
    fgets(s,351,fin);
    memcpy(s+n,s,n);                        //���ɗl�倽���һ��
    for (i=0;s[i]&&m<n;++i){
        if (s[i]=='w')++w,++b;
        else if (nowc!=s[i]){
             if (a+b>m)m=a+b;               //�ɫ׃�Q�r����ж�a+b�Ƿ���m
             a=b-w,b=w+1,w=0,nowc=s[i];     //�ɫ׃�Q�r������ӛ䛔���
        }
        else ++b,w=0;
    }
    if (a+b>m)m=a+b;
    fprintf(fout,"%d\n",m>n?n:m);           //��m>n���������ӽԿ�ȡ��
    return 0;
}
