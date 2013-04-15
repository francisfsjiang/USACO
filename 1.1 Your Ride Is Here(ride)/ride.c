/*
ID: The One
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <string.h>
main () 
{
    FILE *fin  = fopen ("ride.in","r");
    FILE *fout = fopen ("ride.out","w");
    int al,bl,as=1,bs=1,i;
    char a[10],b[10];
    fscanf (fin,"%s%s",a,b);
    al=strlen(a);
    bl=strlen(b);
    for(i=0;i<al;i++)as*=(a[i]-64);
    as=as%47;
    for(i=0;i<bl;i++)bs*=(b[i]-64);
    bs=bs%47;
    if(as==bs)fprintf (fout,"GO\n");
    else fprintf (fout,"STAY\n");
    exit(0);
}
