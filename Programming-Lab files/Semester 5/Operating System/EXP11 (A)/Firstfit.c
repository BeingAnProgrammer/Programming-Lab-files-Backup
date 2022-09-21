#include<stdio.h>
 
int main()
{
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
	
	
	scanf("%d", &bno);
	

	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
 

	scanf("%d", &pno);
	
	
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)         //allocation as per first fit
		for(j = 0; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	
	//display allocation details
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < bno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
	return 0;
}

// output:
// 3
// 100
// 20
// 30
// 3
// 80
// 85
// 15

// Block no.	size		process no.		size
// 1		100		1			80
// 2		20		3			15
// 3		30		Not allocated



// Block no.	size		process no.		size
// 1		100		1			30
// 2		200		2			100
// 3		50		3			20
// 4		20		Not allocated

