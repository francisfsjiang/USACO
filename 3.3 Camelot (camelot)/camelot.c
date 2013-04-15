/*
ID: The One
LANG: C
TASK: camelot
*/

#include<stdio.h>
#include<string.h>
#define INF 9999999
#define MAX 32
#define XX 2
int result[MAX][MAX];
int distking[MAX][MAX];
int distknight[MAX][MAX][MAX][MAX];
int knightposx[MAX*MAX];
int knightposy[MAX*MAX];
int knightnum;
int used[MAX][MAX];
int bfsx[200000];
int bfsy[200000];
int movex[8]={-2,-1,1,2,2,1,-1,-2};
int movey[8]={1,2,2,1,-1,-2,-2,-1};

int abs(int a)
{
    if(a<0)return -a;
    else return a;
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int main()
{
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    int n,m,i,j,k,kingx,kingy,temp,startx,starty,tempx,tempy,head,end;
    char col[5];
    scanf("%d%d",&n,&m);
    scanf("%s",col);
    kingy=col[0]-'A'+1;
    scanf("%d",&kingx);
    memset(distking,0,sizeof(distking));
    for(k=1;k<=max(m,n);k++)for(i=-k;i<=k;i++)for(j=-k;j<=k;j++)
    {
        if(kingx+i>=1&&kingx+i<=n&&kingy+j>=1&&kingy+j<=m&&distking[kingx+i][kingy+j]==0)distking[kingx+i][kingy+j]=k;
    }
    distking[kingx][kingy]=0;
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)printf("%d ",distking[i][j]);
        printf("\n");
    }*/
    knightnum=0;
    while(scanf("%s",col)!=EOF)
    {
        scanf("%d",&temp);
        knightposx[knightnum]=temp;
        knightposy[knightnum]=col[0]-'A'+1;
        //printf("%d %d\n",knightposx[knightnum],knightposy[knightnum]);
        knightnum++;
    }
    for(startx=1;startx<=n;startx++)for(starty=1;starty<=m;starty++)for(i=1;i<=n;i++)for(j=1;j<=m;j++)distknight[startx][starty][i][j]=INF;
    for(startx=1;startx<=n;startx++)for(starty=1;starty<=m;starty++)
    {
        memset(used,0,sizeof(used));
        distknight[startx][starty][startx][starty]=0;
        used[startx][starty]=1;
        head=0;
        end=1;
        bfsx[head]=startx;
        bfsy[head]=starty;
        while(head<end)
        {
            tempx=bfsx[head];
            tempy=bfsy[head];
            for(i=0;i<8;i++)
            {
                if(tempx+movex[i]>=1&&
                    tempx+movex[i]<=n&&
                    tempy+movey[i]>=1&&
                    tempy+movey[i]<=m&&
                    used[tempx+movex[i]][tempy+movey[i]]==0)
                {
                    distknight[startx][starty][tempx+movex[i]][tempy+movey[i]]=distknight[startx][starty][tempx][tempy]+1;
                    used[tempx+movex[i]][tempy+movey[i]]=1;
                    bfsx[end]=tempx+movex[i];
                    bfsy[end]=tempy+movey[i];
                    end++;
                }
            }
            head++;
        }
    }
    /*for(startx=1;startx<=n;startx++)for(starty=1;starty<=m;starty++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)printf("%d ",distknight[startx][starty][i][j]);
            printf("\n");
        }
        printf("\n");
    }*/
    int togex,togey,temp1,temp2,origin,min=INF;
    for(togex=1;togex<=n;togex++)for(togey=1;togey<=m;togey++)
    {
        result[togex][togey]=0;
        for(i=0;i<knightnum;i++)result[togex][togey]+=distknight[knightposx[i]][knightposy[i]][togex][togey];
        result[togex][togey]+=distking[togex][togey];
        origin=result[togex][togey];
        //printf("%d\n",origin);
        for(i=0;i<knightnum;i++)
        {
            temp1=origin-distknight[knightposx[i]][knightposy[i]][togex][togey]-distking[togex][togey];
            for(j=-XX;j<=XX;j++)for(k=-XX;k<=XX;k++)
            {
                if(kingx+j>=1&&kingx+j<=n&&kingy+k>=1&&kingy+k<=m&&distknight[knightposx[i]][knightposy[i]][kingx+j][kingy+k]!=INF&&distknight[kingx+j][kingy+k][togex][togey]!=INF)
                {
                    temp2=distknight[knightposx[i]][knightposy[i]][kingx+j][kingy+k]+distknight[kingx+j][kingy+k][togex][togey]+distking[kingx+j][kingy+k];
                    if(temp1+temp2<result[togex][togey])result[togex][togey]=temp1+temp2;
                }
            }
        }
        if(result[togex][togey]<min)min=result[togex][togey];
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)printf("%d ",result[i][j]);
        printf("\n");
    }*/
    printf("%d\n",min);
    return 0;
}
