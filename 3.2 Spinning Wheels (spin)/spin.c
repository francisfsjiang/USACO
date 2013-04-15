/*
ID:The One
TASK:spin
LANG:C
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

int speed[5];
int wedgest[5][5];
int wedglen[5][5];
int pos[5];
int t;
int light[360];
void mark_light(int w)
{
    int lv, lv2;
    int wpos;
    for (lv = 0; lv < 5; lv++)
    {
        if (wedglen[w][lv] < 0)
        break;
    wpos = (pos[w] + wedgest[w][lv]) % 360;

    for (lv2 = 0; lv2 <= wedglen[w][lv]; lv2++)
     {
      light[wpos] |= (1 << w);
      wpos = (wpos + 1) % 360;
     }
   }
 }

int main(int argc, char **argv)
 {
    FILE *fp;
    FILE *fout;
    int w,f;
    int lv,lv2;
    fp=fopen("spin.in","r");
    fout=fopen("spin.out","w");
    for(lv=0;lv<5;lv++)
    {
        fscanf(fp,"%d%d",&speed[lv],&w);
        for(lv2=0;lv2<w;lv2++)
        fscanf(fp,"%d%d",&wedgest[lv][lv2],&wedglen[lv][lv2]);
        for (; lv2 < 5; lv2++)
        wedglen[lv][lv2] = -1;
    }
    f=0;
    while(t<360)
    {
        memset(light,0,sizeof(light));
        for(lv=0;lv<5;lv++)
        mark_light(lv);
        for(lv=0;lv<360;lv++)
        if(light[lv]==31)
        f=1;
        if(f)break;
        t++;
        for(lv=0;lv<5;lv++)
        pos[lv]=(pos[lv]+speed[lv])%360;
    }
    if(t>=360)fprintf (fout,"none\n");
    else fprintf(fout,"%i\n",t);
    return 0;
}
