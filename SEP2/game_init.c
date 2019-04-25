/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "game_init.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "game_logic.h"


/*
 * This function creates the board for the first time
 *
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]){

    for (int i =0; i< NUM_ROWS; i++){
        for(int j =0; j < NUM_COLUMNS; j++){
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4)
               || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)){
                board[i][j].type = OBSTACLE;
            } else{
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].stack = NULL;
        }
    }
}


/*
* This function creates players for the first time
*
* Input: the array of players to be initialized
* Output: The number of players of the game
*/
int initialize_players(struct player players[]) {

    int num;
    enum color col;
    col = BLU;
    int loop = true;

    while (loop) {

        printf("How many players are in this game?\n");
        scanf("%d", &num);
        if (num < 7 && num > 0) {
            break;
        }
        printf("Error max 6 players, try again\n\n");
    }

    for (int i = 0; i < num; ++i) {

        printf("Enter name of player %d\n", i + 1);
        scanf("%s", &players[i].name);

        printf("Enter the colour for %s  (1= Blue, 2= Green, 3= Yellow, 4= Pink, 5= Orange, 6=Red)\n",players[i].name);
        scanf("%d",&players[i].col);

    }

    for (int i = 0; i < num; ++i) {
//        printf(" You have chosen %u %s\n", players[i].col, players[i].name);
        print_player(players[i]);
    }
    //YOU WILL NEED TO IMPLEMENT THIS FUNCTION IN THIS LAB
    return num;
}
