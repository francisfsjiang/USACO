/*
ID: The One
LANG: C
TASK: fence
*/
#include <stdio.h>

int n;
int map[501][501];
int x;
int stack[2000];

void bfs(int v){
	int i;
	for(i=1;i<=500;i++)
		if(map[v][i]>0){
			map[v][i]--;
			map[i][v]--;
			bfs(i);
		}
	stack[x]=v;
	x++;
}

main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&j,&k);
		map[j][0]++;
		map[k][0]++;
		map[j][k]++;
		map[k][j]++;
	}
	for(i=1;i<=500;i++)
		if(map[i][0]%2==1){
			bfs(i);break;
		}
	if(i==501)bfs(1);
	for(i=x-1;i>=0;i--)
		printf("%d\n",stack[i]);
	return 0;
}
