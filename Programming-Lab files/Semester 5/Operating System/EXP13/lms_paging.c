#include<stdio.h>
#define MAX 50
int main()
{
int page[MAX],i,n,f,ps,off,pno;
printf("\nEnter the no of  pages in memory: ");
scanf("%d",&n);
printf("\nEnter page size: ");
scanf("%d",&ps);
printf("\nEnter no of frames: ");
scanf("%d",&f);
for(i=0;i<n;i++)
page[i]=-1;
printf("\nEnter the page table\n");
printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
printf("\npageno\tframeno\n-------\t-------");
for(i=0;i<n;i++)
{
printf("\n\n%d\t\t",i);
scanf("%d",&page[i]);
}
printf("\n\nEnter the logical address(i.e,page no & offset):");
scanf("%d%d",&pno,&off);
if(page[pno]==-1)
printf("\n\nThe required page is not available in any of frames");
else
printf("%d,%d",page[pno],off);
return (1);
}

// Output:
// Test case 1:

// 4
// 10
// 10
// 2
// 4
// 6
// 5
// 1
// 100

// 4,100

// Test case 2
// 3
// 10
// 10
// 2
// 3
// 1
// 0
// 100

// 2,100
