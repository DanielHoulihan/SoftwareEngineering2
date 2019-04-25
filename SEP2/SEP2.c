#include <stdio.h>


int main(void)
{
numPlayers=3
for(int i=0; i<numPlayers; i++){
printf("Player %d,  which colour do you choose (1= Blue, 2= Red, 3= Green, 4= Yellow, 5=Orange, 6=Black)?\n", i+1);
scanf("%d", &colour);
if(colour==1)
{
	printf("You have chosen Blue\n\n");
}

if(colour==2)
{
	printf("You have chosen Red\n\n");
}

if(colour==3)
{
	printf("You have chosen Green\n\n");
}

if(colour==4)
{
	printf("You have chosen Yellow\n\n");
}

if(colour==5)
{
	printf("You have chosen Orange\n\n");
}

if(colour==6)
{
	printf("You have chosen Black\n\n");
}
}
}
