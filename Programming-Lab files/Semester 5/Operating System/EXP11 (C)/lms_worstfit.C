#include<stdio.h>
#define max 25

int main()
{
 int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
 static int bf[max],ff[max];


 printf("\n\tMemory Management Scheme - Worst Fit");
 printf("\nEnter the number of blocks:");
 scanf("%d",&nb);
 printf("Enter the number of process:");
 scanf("%d",&nf);
 printf("\nEnter the size of the blocks:-\n");
 for(i=1;i<=nb;i++)
 {
     printf("Block %d:",i);
    scanf("%d",&b[i]);
     
 }
 printf("Enter the size of the process :-\n");
 for(i=1;i<=nf;i++)
 {
     printf("Process %d:",i);
     scanf("%d",&f[i]);
     
 }

 for(i=1;i<=nf;i++)
 {
  for(j=1;j<=nb;j++)
  {
   if(bf[j]!=1)    //if bf[j] is not allocated
   {
    temp=b[j]-f[i];
    if(temp>=0)
    if(highest<temp)
    {
     ff[i]=j;
     highest=temp;
    }
   }
  }
  frag[i]=highest;
  bf[ff[i]]=1;
  highest=0;
 }
 printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragment");
 for(i=1;i<=nf;i++)
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
 return(0);
}

// output:
// Test case 1:

// 3
// 3
// 100
// 500
// 200
// 20
// 300
// 150

// Process_no:	Process_size :	Block_no:	Block_size:	Fragment
// 1		20		2		500		480
// 2		300		0		1		0
// 3		150		3		200		50


// Test case 2:

// 4
// 4
// 1000
// 2000
// 150
// 300
// 50
// 1500
// 500
// 20

// Process_no:	Process_size :	Block_no:	Block_size:	Fragment
// 1		50		2		2000		1950
// 2		1500		0		1		0
// 3		500		1		1000		500
// 4		20		4		300		280


