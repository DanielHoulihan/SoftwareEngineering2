<<<<<<< HEAD

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


void print_player(struct player p);
/*
 *  * Manages the logic of the game
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
int play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);
//_Bool IsValid(square board[NUM_ROWS][0], int selectedSquare);


int SquareSize_stack(square board[NUM_ROWS][NUM_COLUMNS], int Row, int Column);

bool Obstacle(square board[NUM_ROWS][NUM_COLUMNS], int dice, int SelectedColumn);

void error_Msg();
  
int diceRoll();
=======

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


void print_player(struct player p);
/*
 *  * Manages the logic of the game
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
int play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);
//_Bool IsValid(square board[NUM_ROWS][0], int selectedSquare);


int SquareSize_stack(square board[NUM_ROWS][NUM_COLUMNS], int Row, int Column);

bool Obstacle(square board[NUM_ROWS][NUM_COLUMNS], int dice, int SelectedColumn);

int diceRoll();
void error_Msg();

>>>>>>> 3f84f286c1da71680a0bba8b36fbdcbd716eebc2
