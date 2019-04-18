int numPlayers;
printf("How many players?: ");
scanf("%d", &numPlayers);


//Chosing colour    
int colour, x;

printf("This game has %d players\n\n", numPlayers);
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

for(int j=0; j<3; j++){
    printf("Player %d\n", j+1);
    for(int i=0; i<4; i++){
    while(x!=1 ||x!=2 ||x!=3 ||x!=4 ||x!=5){
    printf("Which row would you like to place token %d (1-6): ", i+1);
    scanf("%d", &x);

    if(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6){
        printf("Must be 1-6\n"); 
    }

    else if(x==1){
        printf("You have placed it in row 1\n");
        break;
        }
    
    else if(x==2){
        printf("You have placed it in row 2\n");
        break;
        }
    
    else if(x==3){
        printf("You have placed it in row 3\n");
        break;
        }
    
    else if(x==4){
        printf("You have placed it in row 4\n");
        break;
        }
    
    else if(x==5){
        printf("You have placed it in row 5\n");
        break;
        }
    else if(x==6){
        printf("You have placed it in row 6\n");
        break;    
        }
    }
    }   
}