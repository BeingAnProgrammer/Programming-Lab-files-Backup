// ALGORITHM:
// 1. Initialize the state array S as 0, Si =0 if the philosopher i is thinking or 1 if
// hungry.
// 2. Associate two functions getfork(i) and putfork(i) for each philosopher i.
// 3. For each philosopher I call getfork(i) , test(i) and putfork(i) if i is 0
// 4. Stop

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define LEFT (i+4)%5
#define RIGHT (i+1)%5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[5];
void put_forks(int);
void test(int);
void take_forks(int);
void philosopher(int i)
{
if(state[i]==0)
{
take_forks(i);
if(state[i]==EATING)
printf("\n Eating in progress..");
put_forks(i);
}
}
void take_forks(int i)
{
    state[i]=HUNGRY;
test(i);
}
void put_forks(int i)
{
state[i]=THINKING;
printf("\nphilosopher %d has completed its work",i);
test(LEFT);
test(RIGHT);
}
void test(int i)
{
if(state[i]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
{
printf("\nphilosopher %d can eat",i);
state[i]=EATING;
}
}
void main()
{
int i;
for(i=1;i<=5;i++)
state[i]=0;
printf("\n\n\t\t\t DINING PHILOSOPHERS PROBLEM");
printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
printf("\n ALL THE PHILOSOPHERS ARE THINKING !!....\n",i);
for(i=1;i<=5;i++)
{
printf("\n\n the philosophers %d falls hungry\n",i);
philosopher(i);
getch();
}
}

// OUTPUT:
// DINNER’S PHILOSOPHERS PROBLEM
//  ALL THE PHILOSOPHERS ARE THINKING !!....
// The philosophers 1 falls hungry
// Philosopher 1 can eat
// Philosopher 1 has completed its work
// The philosophers 2 falls hungry
// Philosopher 2 can eat
// Philosopher 2 has completed its work
// The philosophers 3 falls hungry
// Philosopher 3 can eat
// Philosopher 3 has completed its work
// The philosopher 4 falls hungry
// Philosopher 4 can eat
// Philosopher 4 has completed its work
// The philosophers 5 falls hungry
// Philosopher 5 can Philosopher 5 has completed its word
