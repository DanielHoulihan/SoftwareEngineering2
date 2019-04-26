/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "game_init.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printLine();



/*
 * Returns the first letter associated with the color of the token
 *
 * Input: t - pointer to a token
 * Output: initial of the color of the token
 */
char print_token(token *t){
    if((*t).col== PINK) return 'P';
    if((*t).col== RED) return 'R';
    if((*t).col== BLU) return 'B';
    if((*t).col== GREEN) return 'G';
    if((*t).col== ORANGE) return 'O';
    if((*t).col== YELLOW) return 'Y';
    return '\0';
}

char print_colour(int col){
    if(col== PINK) return 'P';
    if(col== RED) return 'R';
    if(col== BLU) return 'B';
    if(col== GREEN) return 'G';
    if(col== ORANGE) return 'O';
    if(col== YELLOW) return 'Y';
    return '\0';
}

/*
 * Prints the board
 *
 * Input: the board to be printed.
 */
void print_board(square board[NUM_ROWS][NUM_COLUMNS]){
    printf("                THE BOARD\n");
    for(int i =0; i < NUM_ROWS; i++){

        //prints an horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0' ;
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++){
            if(board[i][j].stack != NULL){
                c = print_token(board[i][j].stack);
            }
                //if the square (i,j) is empty
            else{
                //c is assigned 'X' if the square represents an obstacle
                if(board[i][j].type == OBSTACLE)
                    c = 'X';
                    //c is assigned an empty space otherwise
                else c = ' ';
            }
            printf("| %c ", c);
        }
        printf ("|\n");
    }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}

void printLine(){
    printf("   -------------------------------------\n");
}

/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers) {

    int minNumOfTokens = 0;
    int selectedSquare = 0;
    int placedTokens = 0;


    for (int j=0; j<4; j++) {
        for (int i=0; i<numPlayers; i++) {
            printf("Player %d please select a square for token %d\n", i+1, j+1);
            // code for placing token...
            printf("Please select a square: ");
            scanf("%d", &selectedSquare);
            
            
            
            
//            if(selectedSquare>=0&&selectedSquare<6){
            
//            bool valid;
//            if(board[selectedSquare][0].stack == NULL){
//                printf("The stack at %d 0 is null", selectedSquare  );
//                valid = true;
//             }  else {
//                valid = false;
//             }
//            
//            while(valid != true) {
//               
//                printf("Please select a valid square:\n ");
//                scanf("%d", &selectedSquare);
//                 
//                if(board[selectedSquare][0].stack == NULL){
//                   valid = true;
//                }    
//            }
            
            
//            token *t = malloc(sizeof(token));
//            t->col = players[i].col;
//            t->next = board[selectedSquare][0].stack;
//            board[selectedSquare][0].stack = t;
            
            //Placing tokens
            board[selectedSquare][0].stack = push(players[i].col, board[selectedSquare][0].stack);
            print_board(board);
           
            
    //Counts how many tokens in a given stack.
    int placedTokens = 0;
    token *t1 = board[selectedSquare][0].stack;
        while(t1 != NULL){
            placedTokens+= 1;//increment
            t1 = t1->next;
        }
    printf("stack height at (%d, 0) is %d\n", selectedSquare, placedTokens);
        }
    }
    //}
 
    
//    for(int i=0; i<6; i++){
//    if(placedTokens>board[i][0].count);
//    printf("Choose a different square");
//    }
//   
//    
//    if(moveAllowed(selectedSquare)){
//        
//    }

}



/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */

    void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers) {
        int dice;	
        srand(time(NULL));
	int i = 0;
        for(int j=0; j<numPlayers; j++){
	for (i = 0; i < 1; i++) {
		dice = (rand() % 6) + 1;
		printf("player %d rolls the dice and lands on %d\n", j+1, dice);
    }
  
        int move;
        printf("Would you like to sidestep this token on row %d?\n", dice);
        printf("Enter 1 to move up, 2 to move down or 3 to not move\n");
        scanf("%d", &move);
        
        if(move==1){
        
            board[dice][0].stack = pop(board[dice][0].stack);
            board[dice][1].stack = push(players[i].col, board[dice][1].stack);
            //print_board(board);
        }
        print_board(board);
//        if(move==2){
//            board[dice][0].stack=pop();
//            board[dice+1][0].stack=push();
//        }
//        
//        if(move==3){
//            printf("You have chosen not to sidestep");
//        }

        
        }
   }

void print_player(struct player p) {
    printf("Player %s has colour %c\n", p.name, print_colour(p.col));
}


 
//}



