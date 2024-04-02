#include <stdio.h>

#define row  6
#define column  7

int turn=0;
char player1[20];
char player2[20];
char board[row][column];
char header[]="       ***CONNECT 4***\n  1   2   3   4   5   6   7  ";
char lines[]= "|   |   |   |   |   |   |   |";
char player= 'X';
int number = 0;

void names() {
	printf("Name of Player 1: \n");
    scanf("%s", player1);
    printf("Name of Player 2: \n");
    scanf("%s", player2);
}

void reset_board() {
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            board[i][j] = ' ';
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}


void fill(){
    int level ;     // lowest level 

    for (level = row-1; level >= 0; level--)
    {
        if (board[level][number] == ' ')
        {
            board[level][number] = player;
            break;
        }
    }
}


void draw(){
    printf("%s\n", header);
    printf("%s\n", lines);

    int i, j;

    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++){
            printf("| %c ", board[i][j]);
			}
			printf("|\n");
        	printf("%s\n", lines);
    }
    printf("\n\n");
}


void choose(){
    // choose 1 2 3 4 5 6 7:
    char n;

    while (1)
    {
        printf("Choose a column: ");
        scanf(" %d", &n);
        switch(n)
        {
            case 1:
                number = 0;
                break;
            case 2:
                number = 1;
                break;
            case 3:
                number = 2;
                break;
            case 4:
                number = 3;
                break;
            case 5:
                number = 4;
                break;
            case 6:
                number = 5;
                break;
            case 7:
                number = 6;
                break;
            default:
                number = 7;
                printf("\nInvalid Move! Try again.\n\n");
                draw();
           }
        // break out of while loop if the right letter was chosen:
        if ((number >= 0 && number <= 6) && (board[0][number] == ' ')) //2. if it is not full or taken.
        {
            fill();
           // variable = (condition) ? expressionTrue : expressionFalse;
            player = (player == 'X') ? 'O' : 'X';
            break;
        }
    }
}


int check(char player){
    int i, j;
	//row
    for (i = 0; i < row; i++){
        for (j = 0; j < 4; j++){ // 4 = column-3
            if (board[i][j] == player &&
                board[i][j+1] == player &&
                board[i][j+2] == player &&
                board[i][j+3] == player){
				return 1;
                }
            }
        }
	//column
    for (i = 0; i < 4; i++){ //4 = row-3
        for (j = 0; j < column; j++){
            if (board[i][j] == player &&
                board[i+1][j] == player &&
                board[i+2][j] == player &&
                board[i+3][j] == player) {
            	return 1;
			}
		}
    }
    //diagonals upward
    for (i = 3; i < row; i++){
        for (j = 0; j < 4; j++){ //column-3
            if (board[i][j] == player &&
                board[i-1][j+1] == player &&
                board[i-2][j+2] == player &&
                board[i-3][j+3] == player){
            	return 1;
			}
		}
	}
	//diagonals downward
    for (i = 0; i < 4; i++){ //4 = row-3
        for (j = 0; j < 4; j++){ //4 = column-3
                if (board[i][j] == player && 
				board[i+1][j+1] == player && 
				board[i+2][j+2] == player && 
				board[i+3][j+3] == player){
                return 1;
            }
        }
    }
    return 0;
}

main() {
    char winner=' ';
    names();
    reset_board();
    draw();

   while (1)
    {
    	while (1){
    	turn++;
        if (turn % 2 != 0) {
        printf("%s, YOUR TURN!\n", player1);
        choose();
        printf("\n\n");
        draw();
        if (check('X'))
        {
            printf("\n\n$$%s, YOU WON!$$\n", player1);
            return 0;
        }
    }
        else {
        printf("%s, YOUR TURN!\n", player2);
        choose();
        printf("\n\n");
        draw();
        if (check('O'))
        {
            printf("\n\n$$%s, YOU WON!$$\n", player2);
            return 0;
        }
    }
}
}
    return 0;
}
