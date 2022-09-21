#include <stdio.h>
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &r);

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);	


	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
		
do
{
	printf("\n Max matrix:\tAllocation matrix:\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", alloc[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)//if not completed
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(need[i][j]>avail[j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion!", process + 1);
		safeSequence[count] = process ;
		count++;
		for(j = 0; j < r; j++)
		{
			avail[j] += alloc[process][j];
			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);


if(count == p)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( i = 0; i < p; i++)
			printf("%d  ", safeSequence[i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
return 0;
}


// Enter the no of processes : 3


// Enter the no of resources : 3


// Enter the Max Matrix for each process : 
// For process 1 : 3
// 3
// 3

// For process 2 : 3
// 3
// 3

// For process 3 : 3
// 3
// 3


// Enter the allocation for each process : 
// For process 1 : 3
// 2
// 1

// For process 2 : 2
// 2
// 2

// For process 3 : 
// 3
// 3
// 3


// Enter the Available Resources : 4
// 1
// 2

//  Max matrix:	Allocation matrix:
// 3  3  3  		3  2  1  
// 3  3  3  		2  2  2  
// 3  3  3  		3  3  3  

// Process 1 runs to completion!
//  Max matrix:	Allocation matrix:
// 0  0  0  		0  0  0  
// 3  3  3  		2  2  2  
// 3  3  3  		3  3  3  

// Process 2 runs to completion!
//  Max matrix:	Allocation matrix:
// 0  0  0  		0  0  0  
// 0  0  0  		0  0  0  
// 3  3  3  		3  3  3  

// Process 3 runs to completion!
// The system is in a safe state!!
// Safe Sequence : < 0  1  2  >

// GEEKS FOR GEEKS BANKERS ALGORITHM
// Banker's Algorithm
// #include <stdio.h>
// int main()
// {
// 	// P0, P1, P2, P3, P4 are the Process names here

// 	int n, m, i, j, k;
// 	n = 5; // Number of processes
// 	m = 3; // Number of resources
// 	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
// 						{ 2, 0, 0 }, // P1
// 						{ 3, 0, 2 }, // P2
// 						{ 2, 1, 1 }, // P3
// 						{ 0, 0, 2 } }; // P4

// 	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
// 					{ 3, 2, 2 }, // P1
// 					{ 9, 0, 2 }, // P2
// 					{ 2, 2, 2 }, // P3
// 					{ 4, 3, 3 } }; // P4

// 	int avail[3] = { 3, 3, 2 }; // Available Resources

// 	int f[n], ans[n], ind = 0;
// 	for (k = 0; k < n; k++) {
// 		f[k] = 0;
// 	}
// 	int need[n][m];
// 	for (i = 0; i < n; i++) {
// 		for (j = 0; j < m; j++)
// 			need[i][j] = max[i][j] - alloc[i][j];
// 	}
// 	int y = 0;
// 	for (k = 0; k < 5; k++) {
// 		for (i = 0; i < n; i++) {
// 			if (f[i] == 0) {

// 				int flag = 0;
// 				for (j = 0; j < m; j++) {
// 					if (need[i][j] > avail[j]){
// 						flag = 1;
// 						break;
// 					}
// 				}

// 				if (flag == 0) {
// 					ans[ind++] = i;
// 					for (y = 0; y < m; y++)
// 						avail[y] += alloc[i][y];
// 					f[i] = 1;
// 				}
// 			}
// 		}
// 	}

// 	int flag = 1;
	
// 	for(int i=0;i<n;i++)
// 	{
// 	if(f[i]==0)
// 	{
// 		flag=0;
// 		printf("The following system is not safe");
// 		break;
// 	}
// 	}
	
// 	if(flag==1)
// 	{
// 	printf("Following is the SAFE Sequence\n");
// 	for (i = 0; i < n - 1; i++)
// 		printf(" P%d ->", ans[i]);
// 	printf(" P%d", ans[n - 1]);
// 	}
	

// 	return (0);
// }

