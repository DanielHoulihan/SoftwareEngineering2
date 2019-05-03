#include "game_init.h"
#include "game_logic.h"
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
    int selectedSquare = 0;


    for (int j=0; j<4; j++) {
        for (int i=0; i<numPlayers; i++) {
            printf("%s please select a square (0-5) for token %d\n", players[i].name, j+1);
            // code for placing token...
            printf("Please select a square:\n ");
            scanf("%d", &selectedSquare);

            //Placing tokens on board using push
            board[selectedSquare][0].stack = push(players[i].col, board[selectedSquare][0].stack);
            print_board(board);


            //code for counting stacks on each rows
            int placedTokens = 0;
            token *t1 = board[selectedSquare][0].stack;
            while(t1 != NULL){
                placedTokens+= 1;//increment
                t1 = t1->next;
            }
            printf("-------------------------------------\n");
            printf("Stack height at (%d,0) is %d\n",selectedSquare, placedTokens);
            printf("-------------------------------------\n");

        }
    }
}



/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */

int play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers) {
    int sidesteprow, sidestepcol, upordown;
    int tokenToMove;
    srand(time(NULL));
    int winner=0;
    while(winner!=1){
   
        
 
    for (int i = 0; i < numPlayers; i++) {
       
        //print horizontal line
        printLine();
        int dice=diceRoll();
        printf("%s rolls the dice and lands on %d \n",players[i].name, dice);
        printf("%s, select a token %c (row # and then column #) \n", players[i].name, print_colour(players[i].col));
        scanf("%d %d", &sidesteprow, &sidestepcol);

        while(board[sidesteprow][sidestepcol].stack == NULL){ // code if the user selects an empty square on row
            error_Msg();
            printf("%s, select a token %c (row # and then column #) \n", players[i].name, print_colour(players[i].col));
            scanf("%d %d", &sidesteprow, &sidestepcol);

        }

        // loop to check if the user selects their own token
        while (players[i].col != board[sidesteprow][sidestepcol].stack->col){
            error_Msg();
            printf("%s, select a token %c (row # and then column #) \n", players[i].name, print_colour(players[i].col));
            scanf("%d %d", &sidesteprow, &sidestepcol);
            continue;
        }

        //if the player approaches an obstacle
        if(board[sidesteprow][sidestepcol].type == OBSTACLE){
            Obstacle(board, sidesteprow, sidestepcol);
        }

        //condition if there are no obstacles then let the square = normal
        if (Obstacle(board,sidesteprow,sidestepcol) ==  true){
            board[sidesteprow][sidestepcol].type = NORMAL;
        }

        //condition if player chose correct token and not in obstacle
        if (players[i].col == board[sidesteprow][sidestepcol].stack->col && board[sidesteprow][sidestepcol].type == NORMAL) {
            printf("Enter 1 to move up, 2 to move down or 3 to not sidestep\n");
            scanf("%d", &upordown);

            switch (upordown) {
                case 1:
                {token *tempMoveDown = board[sidesteprow][sidestepcol].stack;
                    if (board[sidesteprow][sidestepcol].stack != NULL){
                    board[sidesteprow][sidestepcol].stack = board[sidesteprow][sidestepcol].stack->next;
                    tempMoveDown->next = board[sidesteprow-1][sidestepcol].stack;
                    board[sidesteprow-1][sidestepcol].stack = tempMoveDown;
                    }
                    print_board(board);
                }
                    printf("You must move a token in row %d, input col to move 1 square ahead?", dice);
                    scanf("%d", &tokenToMove);
                    {token *tempMoveForward = board[dice][tokenToMove].stack;
                    if (board[dice][tokenToMove].stack != NULL){
                    board[dice][tokenToMove].stack = board[dice][tokenToMove].stack->next;
                    tempMoveForward->next = board[dice][tokenToMove+1].stack;
                    board[dice][tokenToMove+1].stack = tempMoveForward;
                    }
                    print_board(board);
                    }
                    break;
                    

                case 2://moving down
                {token *tempMoveDown = board[sidesteprow][sidestepcol].stack;
                    if (board[sidesteprow][sidestepcol].stack != NULL){
                    board[sidesteprow][sidestepcol].stack = board[sidesteprow][sidestepcol].stack->next;
                    tempMoveDown->next = board[sidesteprow+1][sidestepcol].stack;
                    board[sidesteprow+1][sidestepcol].stack = tempMoveDown;
                    }
                    print_board(board);
                }
                    printf("You must move a token in row %d, input col to move 1 square ahead?", dice);
                    scanf("%d", &tokenToMove);
                    {token *tempMoveForward = board[dice][tokenToMove].stack;
                    if (board[dice][tokenToMove].stack != NULL){
                    board[dice][tokenToMove].stack = board[dice][tokenToMove].stack->next;
                    tempMoveForward->next = board[dice][tokenToMove+1].stack;
                    board[dice][tokenToMove+1].stack = tempMoveForward;
                    }
                    print_board(board);
                    }
                    break;

                case 3://not moving up or down

                    printf("You must move a token in row %d, input col to move 1 square ahead?", dice);
                    scanf("%d", &tokenToMove);
                    {token *tempMoveForward = board[dice][tokenToMove].stack;
                    if (board[dice][tokenToMove].stack != NULL){
                    board[dice][tokenToMove].stack = board[dice][tokenToMove].stack->next;
                    tempMoveForward->next = board[dice][tokenToMove+1].stack;
                    board[dice][tokenToMove+1].stack = tempMoveForward;
                    }
                    print_board(board);
                    }
                    default:
                break;
            }
        }

        continue;
    }


}
}



void print_player(struct player p) {
    printf("Player %s has colour %c\n", p.name, print_colour(p.col));
}

//this bool function should return true if there arent any approaching obstacles else it should output false
bool Obstacle(square board[NUM_ROWS][NUM_COLUMNS], int dice, int SelectedColumn) {
    for (int x = 0; x < 6; x++) {
        for (int y = 0; SelectedColumn; ++y) {
            if (board[x][y].stack != NORMAL) {
                printf("Error, you reached an obstacle");
                return false;
            }
        }
        return true;
  }
}

void error_Msg(){
    printf("Error, this move is invalid\n");
}

int diceRoll(){
    srand(time(NULL));
    int dice = (rand()%6);
    
    return dice;
}