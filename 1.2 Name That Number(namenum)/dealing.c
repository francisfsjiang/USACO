#include <stdio.h>
#include <string.h>
main()
{
	freopen("namenumdict.txt","rt+",stdin);
	freopen("namenumdicted.txt","wt+",stdout);
	int i,j,l,d,sum=0;
	char a[200];
	for(i=0;i<4617;i++)//4617
	{
        d=0;
		scanf("%s",a);
		l=strlen(a);
		for(j=0;j<l;j++)
		{
                        if(a[j]=='Z'){memset(a,0,sizeof(a));d=1;break;}
        }
        if(d==1)continue;
		printf("{");
		for(j=0;j<l;j++)
		{
			printf("%d",a[j]);
			if(j!=l-1)printf(",");
		}
		printf("},");
		sum++;
		memset(a,0,sizeof(a));
	}
	printf("\n%d",sum);
	return(0);
}

