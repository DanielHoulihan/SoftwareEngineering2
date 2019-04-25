/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "game_init.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            printf("Please select a square:\n ");
            scanf("%d", &selectedSquare);
            token *t = malloc(sizeof(token));
            t->col = players[i].col;
            t->next = board[selectedSquare][0].stack;
            board[selectedSquare][0].stack = t;
            print_board(board);

        }
    }

//

}



/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */

    void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers) {
        //TO BE IMPLEMENTED
    };

void print_player(struct player p) {
    printf("Player %s has colour %c\n", p.name, print_colour(p.col));
}
