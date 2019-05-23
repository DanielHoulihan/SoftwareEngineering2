
/*
 * Prints the board
 *
 * Input: the board to be printed.
 */
void print_board(square board[NUM_ROWS][NUM_COLUMNS]);


/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);

//int MoveToken(square board[NUM_ROWS][NUM_COLUMNS],int CurrRow, int CurrColumn, int NextRow, int NextColumn){
/*
struct MoveToken {
    struct stack_elem *next;
}Token;
*/




void print_player(struct player p);
/*
 *  * Manages the logic of the game
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
int play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);



