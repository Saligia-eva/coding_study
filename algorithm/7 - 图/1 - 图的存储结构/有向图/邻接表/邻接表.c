#include <stdio.h>
#include "algraph.h"

int main ()
{
	int a ;
	int i ;
	pVNode one;
	pArcNode p;

	puts ("请输入顶点数量 :");
	scanf ("%d",&a);
	getchar();

	InitAlGraph (&one , a); 

	for (i = 0 ; i < a ; i++)
	{
		printf (" %c : ",one[i].data);
		p = one[i].first;
		while (p!= NULL)
		{
			printf (" %d ",p->adjvex);
			p = p->nextarc;
		}

		printf ("\n");
	}
	return 0;
}