/*
ID: The One
LANG: C
TASK: crypt1
*/
#include<stdio.h>
#include<string.h>
int hash[10];
int main(void)
{
    FILE *fin = fopen("crypt1.in","r");
    FILE *fout = fopen("crypt1.out","w");
    int n,ans=0,i,j,k,p,e;
    int num[10];
    int t1,t2,t3,c1=0,c2=0,c3=0;
    fscanf(fin,"%d",&n);
    memset(hash,0,sizeof(hash));
    for(i=1;i<=n;i++)fscanf(fin,"%d",&num[i]);
    for(i=1;i<=n;i++)hash[num[i]]=1;
    for(i=1;i<=n;i++)
    {
     for(j=1;j<=n;j++)
     {
      for(k=1;k<=n;k++)
      {
       for(p=1 ; p<=n ; p++)
       {
        for(e=1 ; e<=n ; e++)
        {
            int pos;
                t3 = (num[i]*100+num[j]*10+num[k]);
                t1 = c1 = num[p]*t3;
                t2 = c2 = num[e]*t3;
                int t=0;
                while(t1>0)
                {
                    ++t;
                    pos=t1%10;
                    if(!hash[pos]){t=44;break;}
                    t1=t1/10;
                }
                if(t>=4) continue;
                t=0;
                while(t2>0)
                {
                    ++t;
                    pos=t2%10;
                    if(!hash[pos]){t=44;break;}
                    t2=t2/10;
                }
                if(t>=4) continue;
                t=0;
                c2=c2*10;
                c3=c1+c2;
                while(c3>0)
                {
                    ++t;
                    pos=c3%10;
                    if(!hash[pos]){t=0;break;}
                    c3=c3/10;
                }
                if(t==4) ans++;
        }
       }
      }
     }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
