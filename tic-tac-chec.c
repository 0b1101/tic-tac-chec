/* includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to print the board */
void board(char square[3][3]) {
    printf("          1       2       3    \n");
    printf("       _______________________\n");
    printf("      |       |       |       |\n");
    printf("   1  |   %c   |   %c   |   %c   |\n", square[0][0], square[0][1], square[0][2]);

    printf("      |_______|_______|_______|\n");
    printf("      |       |       |       |\n");

    printf("   2  |   %c   |   %c   |   %c   |\n", square[1][0], square[1][1], square[1][2]);

    printf("      |_______|_______|_______|\n");
    printf("      |       |       |       |\n");

    printf("   3  |   %c   |   %c   |   %c   |\n", square[2][0], square[2][1], square[2][2]);

    printf("      |_______|_______|_______|\n\n");

    return;
}

/* function to check player 1 win */
void win1(char square[3][3]) {
    int k, j;  // counters for the squares of the board

    for (k = 0; k < 3; k++) {  // win horizontally
        j = 0;
        if ('A' <= square[k][j] && square[k][j] <= 'Z' && 'A' <= square[k][j + 1] && square[k][j + 1] <= 'Z' && 'A' <= square[k][j + 2] && square[k][j + 2] <= 'Z') {
            printf("Player 1 wins!");

            exit(0);
        }
    }

    for (j = 0; j < 3; j++) {  // win vertically
        k = 0;
        if ('A' <= square[k][j] && square[k][j] <= 'Z' && 'A' <= square[k + 1][j] && square[k + 1][j] <= 'Z' && 'A' <= square[k + 2][j] && square[k + 2][j] <= 'T') {
            printf("Player 1 wins!");

            exit(0);
        }
    }

    /* win diagonally1 */
    if ('A' <= square[0][0] && square[0][0] <= 'Z' && 'A' <= square[1][1] && square[1][1] <= 'Z' && 'A' <= square[2][2] && square[2][2] <= 'T') {
        printf("Player 1 wins!");

        exit(0);
    }

    /* win diagonally2 */
    if ('B' <= square[0][2] && square[0][2] <= 'T' && 'B' <= square[1][1] && square[1][1] <= 'T' && 'B' <= square[2][0] && square[2][0] <= 'T') {
        printf("Player 1 wins!");

        exit(0);
    }
}

/*function to check player 2 win*/
void win2(char square[3][3]) {
    int k, j;  // counters for the squares of the board

    for (k = 0; k < 3; k++) {  // win horizontally
        j = 0;
        if ('a' <= square[k][j] && square[k][j] <= 'z' && 'a' <= square[k][j + 1] && square[k][j + 1] <= 'z' && 'a' <= square[k][j + 2] && square[k][j + 2] <= 'z') {
            printf("Player 2 wins!");

            exit(0);
        }
    }

    for (j = 0; j < 3; j++) {  // win vertically
        k = 0;
        if ('a' <= square[k][j] && square[k][j] <= 'z' && 'a' <= square[k + 1][j] && square[k + 1][j] <= 'z' && 'a' <= square[k + 2][j] && square[k + 2][j] <= 'z') {
            printf("Player 2 wins!");

            exit(0);
        }
    }

    /* win diagonally1 */
    if ('a' <= square[0][0] && square[0][0] <= 'z' && 'a' <= square[1][1] && square[1][1] <= 'z' && 'a' <= square[2][2] && square[2][2] <= 'z') {
        printf("Player 2 wins!");

        exit(0);
    }

    /* win diagonally2 */
    if ('a' <= square[0][2] && square[0][2] <= 'z' && 'a' <= square[1][1] && square[1][1] <= 'z' && 'z' <= square[2][0] && square[2][0] <= 'z') {
        printf("Player 2 wins!");

        exit(0);
    }
}

/* This function defines the movement of the bishop */
/* k and j assume the new values of the row and column
while k1 and j1 are the values of where the piece was before the movement */
int bishop(char square[3][3], int k, int j, int k1, int j1) {
    int a = 0;  // counter to check if the movement is valid or not

    if (abs(k1 - k) == abs(j1 - j) && square[k1 + 1][j1 + 1] == ' ') {  // movement in the main diagonal
        a = 1;                                                          // as this movement is valid, a assumes 1
        return a;
    }

    if (abs(k1 - k) == abs(j1 - j) && square[k1 - 1][j1 - 1] == ' ') {  // movement in the main diagonal
        a = 1;                                                          // as this movement is valid, a assumes 1
        return a;
    }

    if (abs(k1 - k) == abs(j1 - j) && square[k1 + 1][j1 - 1] == ' ') {  // movement in the secondary diagonal
        a = 1;                                                          // as this movement is valid, a assumes 1
        return a;
    }

    if (abs(k1 - k) == abs(j1 - j) && square[k1 - 1][j1 + 1] == ' ') {  // movement in the secondary diagonal
        a = 1;                                                          // as this movement is valid, a assumes 1
        return a;
    }

    return a;  // any other movement is invalid and therefore returns a = 0
}


/* This function is used to check if there are possible movements for player 1's bishop piece */
int movbishopB(char square[3][3]) {
    int k1, j1;  // used to save the old position of the piece
    int k, j;    // counters for possible new positions
    int a = 0;   // variable to check if the move is possible or not

    for (k = 0; k < 3; k++) {  // this for loop searches the board for the B piece
        for (j = 0; j < 3; j++) {
            if (square[k][j] == 'B') {  // when it finds it
                k1 = k;                 // saves the position it was in
                j1 = j;
            }
        }
    }

    /* here, as always, it is checked if the squares of valid movements are available
    also checks if the squares exist on the board, that is,
    any square that would result in square[-1][4] or similar is vetoed */

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {
            if (abs(k1 - k) == abs(j1 - j)) {
                /* here, the same logic as the movement function is used,
                but it checks if there is any square where the movement is valid */
                if ((k1 + 1) < 3 && (j1 + 1) < 3) {
                    if (square[k1 + 1][j1 + 1] == ' ') {
                        a = 1;  // and if it exists, a assumes 1
                    }
                }
                if ((k1 - 1) > (-1) && (j1 + 1) <= 3) {
                    if (square[k1 - 1][j1 + 1] == ' ') {
                        a = 1;
                    }
                }
                if ((k1 - 1) > (-1) && (j1 - 1) > (-1)) {
                    if (square[k1 - 1][j1 - 1] == ' ') {
                        a = 1;
                    }
                }
                if ((k1 + 1) < 3 && (j1 - 1) > (-1)) {
                    if (square[k1 + 1][j1 - 1] == ' ') {
                        a = 1;
                    }
                }
            }
        }
    }
    return a;  // any other movement is invalid and therefore returns a = 0
}


/* This function is used to check if there are possible movements for player 2's bishop piece */
int movbishopb(char square[3][3]) {
    int k1, j1;  // used to save the old position of the piece
    int k, j;    // counters for possible new positions
    int a = 0;   // variable to check if the move is possible or not

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {       // this for loop searches the board for the b piece
            if (square[k][j] == 'b') {  // when it finds it
                k1 = k;
                j1 = j;
            }
        }
    }

    /* here, as always, it is checked if the squares of valid movements are available
    also checks if the squares exist on the board, that is,
    any square that would result in square[-1][4] or similar is vetoed */

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {
            if (abs(k1 - k) == abs(j1 - j)) {
                /* here, the same logic as the movement function is used,
                but it checks if there is any square where the movement is valid */
                if ((k1 + 1) < 3 && (j1 + 1) < 3) {
                    if (square[k1 + 1][j1 + 1] == ' ') {  // and if it exists, a assumes 1
                        a = 1;
                    }
                }
                if ((k1 - 1) > (-1) && (j1 + 1) <= 3) {
                    if (square[k1 - 1][j1 + 1] == ' ') {
                        a = 1;
                    }
                }
                if ((k1 - 1) > (-1) && (j1 - 1) > (-1)) {
                    if (square[k1 - 1][j1 - 1] == ' ') {
                        a = 1;
                    }
                }
                if ((k1 + 1) < 3 && (j1 - 1) > (-1)) {
                    if (square[k1 + 1][j1 - 1] == ' ') {
                        a = 1;
                    }
                }
            }
        }
    }
    return a;  // any other movement is invalid and therefore returns a = 0
}


/* This function defines the movement of the rook */
/* Again, k and j take on the new values of the row and column
while k1 and j1 are the values of where the piece was before the movement */
int rook(char square[3][3], int k, int j, int k1, int j1) {
    int a = 0;  // once again, a is the variable to check if the move is possible or not

    if (k1 == k) {  // rook movement if the columns are different and the rows are the same
        if (j == j1 + 1) {
            a = 1;  // and again, if the move is valid, a = 1
            return a;
        }

        if (j == j1 - 1) {
            a = 1;
            return a;
        }

        if (j == j1 + 2 && square[k][j - 1] == ' ') {
            a = 1;
            return a;
        }

        if (j == j1 - 2 && square[k][j + 1] == ' ') {
            a = 1;
            return a;
        }

    } else if (j1 == j) {  // rook movement if the rows are different and the columns are the same
        if (k == k1 + 1) {
            a = 1;
            return a;
        }

        if (k == k1 - 1) {
            a = 1;
            return a;
        }

        if (k == k1 + 2 && square[k - 1][j] == ' ') {
            a = 1;
            return a;
        }

        if (k == k1 - 2 && square[k + 1][j] == ' ') {
            a = 1;
            return a;
        }
    }

    return a;  // and again, if no move changes the value of a, it means it's not valid
}

/* This function is used to check for possible movements for the rook piece of player 1 */
int movrookR(char square[3][3]) {
    int k1, j1;  // used to save the old position of the piece
    int k, j;    // counters for possible new positions
    int a = 0;   // variable to check if the move is possible or not

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {       // this loop searches for the rook piece 'T' on the board
            if (square[k][j] == 'T') {  // saves the position it was in
                k1 = k;
                j1 = j;
            }
        }
    }

    /* as always, here it is checked if the squares of valid movements are available
    it is also checked if the squares exist on the board, i.e.,
    any square that would give square[-1][4] or similar is vetoed */

    if ((j1 - 1) > 0 || (j1 - 1) == 0) {  // for equal rows,
        if (square[k1][j1 - 1] == ' ') {  // it is checked if there is space in different columns
            a = 1;                        // if the movement is valid, a becomes 1
        }
    }

    if ((j1 + 1) < 3) {
        if (square[k1][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((k1 + 1) < 3) {                   // for equal columns,
        if (square[k1 + 1][j1] == ' ') {  // it is checked if there is space in different rows
            a = 1;                        // if the movement is valid, a becomes 1
        }
    }

    if ((k1 - 1) > 0 || (k1 - 1) == 0) {
        if (square[k1 - 1][j1] == ' ') {
            a = 1;
        }
    }
    return a;  // again, if no move changes the value of a, it means there are no possible moves
}


/* This function is used to check for possible movements for the rook piece of player 2 */
int movrookr(char square[3][3]) {
    int k1, j1;  // used to save the old position of the piece
    int k, j;    // counters for possible new positions
    int a = 0;   // variable to check if the move is possible or not

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {       // this loop searches for the rook piece 't' on the board
            if (square[k][j] == 't') {  // saves the position it was in
                k1 = k;
                j1 = j;
            }
        }
    }

    /* as always, here it is checked if the squares of valid movements are available
    it is also checked if the squares exist on the board, i.e.,
    any square that would give square[-1][4] or similar is vetoed */

    if ((j1 - 1) > 0 || (j1 - 1) == 0) {  // here the same logic as the previous function is used
        if (square[k1][j1 - 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 1) < 3) {
        if (square[k1][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((k1 + 1) < 3) {
        if (square[k1 + 1][j1] == ' ') {
            a = 1;
        }
    }

    if ((k1 - 1) > 0 || (k1 - 1) == 0) {
        if (square[k1 - 1][j1] == ' ') {
            a = 1;
        }
    }
    return a;  // again, if no move changes the value of a, it means there are no possible moves
}


/* This function defines the movement of the knight */
/* Again, k and j take on the new values of the row and column
while k1 and j1 are the values from where the piece was before the movement */
int knight(char square[3][3], int k, int j, int k1, int j1) {
    int a = 0;  // Again, 'a' is the variable to check for valid movement

    /* In this if statement, all possible moves for the knight are considered.
    The logic is: if it moves 1 square in one coordinate, it must move 2 in the other. */
    if ((j1 == j + 2 && k1 == k + 1) || (j1 == j + 2 && k1 == k - 1) || (j1 == j + 1 && k1 == k + 2) || (j1 == j + 1 && k1 == k - 2) || (j1 == j - 1 && k1 == k + 2) || (j1 == j - 1 && k1 == k - 2) || (j1 == j - 2 && k1 == k + 1) || (j1 == j - 2 && k1 == k - 1)) {
        a = 1;  // If the coordinates fit any of the conditions, the move is valid, and 'a' is set to 1
    }

    return a;
}

/* This function is used to check for possible movements for the knight piece of player 1 */
int movknightK(char square[3][3]) {
    int k1, j1;  // Used to save the old position of the piece
    int k, j;    // Counters for possible new positions
    int a = 0;   // Variable to check if the move is possible or not

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {       // This loop searches for the knight piece 'C' on the board
            if (square[k][j] == 'C') {  // Saves the position it was in
                k1 = k;
                j1 = j;
            }
        }
    }

    /* As always, here it is checked if the squares of valid movements are available
    It is also checked if the squares exist on the board, i.e.,
    any square that would give square[-1][4] or similar is vetoed */

    if ((k1 - 1) > (-1) && (j1 - 2) > (-1)) {
        if (square[k1 - 1][j1 - 2] == ' ') {
            a = 1;  // And if it is possible, a = 1
        }
    }

    if ((k1 + 1) < 3 && (j1 - 2) > (-1)) {
        if (square[k1 + 1][j1 - 2] == ' ') {
            a = 1;
        }
    }

    if ((k1 - 2) > (-1) && (j1 - 1) > (-1)) {
        if (square[k1 - 2][j1 - 1] == ' ') {
            a = 1;
        }
    }

    if ((k1 + 2) < 3 && (j1 - 1) > (-1)) {
        if (square[k1 + 2][j1 - 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 1) < 3 && (k1 + 2) < 3) {
        if (square[k1 + 2][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 1) < 3 && (k1 - 2) > (-1)) {
        if (square[k1 - 2][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 2) < 3 && (k1 - 1) > (-1)) {
        if (square[k1 - 1][j1 + 2] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 2) < 3 && (k1 + 1) < 3) {
        if (square[k1 + 1][j1 + 2] == ' ') {
            a = 1;
        }
    }

    return a;  // Again, if no move changes the value of a, it means there are no possible moves
}


/* This function is used to check for possible movements for the knight piece of player 2 */
int movknightk(char square[3][3]) {
    int k1, j1;  // Used to save the positions of the squares
    int k, j;    // Counters
    int a;       // True or false
    a = 0;
    for (k = 0; k < 3; k++) {  // Whenever the piece is 'c', this function checks if the possible moves are true
        for (j = 0; j < 3; j++) {
            if (square[k][j] == 'c') {  // If true, then this function is true
                k1 = k;
                j1 = j;
            }
        }
    }

    /* As always, here it is checked if the squares of valid movements are available
    It is also checked if the squares exist on the board, i.e.,
    any square that would give square[-1][4] or similar is vetoed */

    if ((k1 - 1) > (-1) && (j1 - 2) > (-1)) {
        if (square[k1 - 1][j1 - 2] == ' ') {
            a = 1;
        }
    }

    if ((k1 + 1) < 3 && (j1 - 2) > (-1)) {
        if (square[k1 + 1][j1 - 2] == ' ') {
            a = 1;
        }
    }

    if ((k1 - 2) > (-1) && (j1 - 1) > (-1)) {
        if (square[k1 - 2][j1 - 1] == ' ') {
            a = 1;
        }
    }

    if ((k1 + 2) < 3 && (j1 - 1) > (-1)) {
        if (square[k1 + 2][j1 - 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 1) < 3 && (k1 + 2) < 3) {
        if (square[k1 + 2][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 1) < 3 && (k1 - 2) > (-1)) {
        if (square[k1 - 2][j1 + 1] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 2) < 3 && (k1 - 1) > (-1)) {
        if (square[k1 - 1][j1 + 2] == ' ') {
            a = 1;
        }
    }

    if ((j1 + 2) < 3 && (k1 + 1) < 3) {
        if (square[k1 + 1][j1 + 2] == ' ') {
            a = 1;
        }
    }

    return a;  // Again, if no move changes the value of 'a', it means there are no possible moves
}


/* Game */
int main() {
    int i = 0;          // counter
    int a = 0;          // movement verifier (but a will also work as a counter)
    int n = 0;          // number of rounds
    int k, j, k1, j1;   // integers for the squares, the same logic as the functions above
    char piece;         // piece being used
    char square[3][3];  // game board
    char empty = ' ';   // empty squares

    for (k = 0; k < 3; k++) {  // loop to initialize empty squares
        for (j = 0; j < 3; j++) {
            square[k][j] = empty;
        }
    }

    printf("Welcome to Tic Tac Chec!\n \n");

    while (n < 3) {
        printf("Player 1, choose your piece:\n");

        i = 0;

        /* here, a loop is used for Player 1 to choose the pieces.
        It is important to note that it is checked whether the piece is not already on the board */
        for (k = 0; k < 3; k++) {
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'B') {  // each time the square has something other than B
                    i++;                    // increment the counter
                }
            }
        }

        if (i == 9) {  // if all squares are different from B, the option to choose the piece appears
            printf("Type 'B' for bishop\n");
        }

        i = 0;  // reset the counter

        for (k = 0; k < 3; k++) {
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'R') {  // same logic for the other pieces
                    i++;
                }
            }
        }

        if (i == 9) {
            printf("Type 'R' for rook\n");
        }

        i = 0;

        for (k = 0; k < 3; k++) {
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'K') {
                    i++;
                }
            }
        }

        if (i == 9) {
            printf("Type 'K' for knight\n");
        }

        scanf(" %c", &piece);  // get the value of the piece the player wants to move

        while (piece != 'B' && piece != 'R' && piece != 'K') {  // loop to prevent choice if it is different from the 3 options
            printf("Invalid piece. Try again.\n");
            scanf(" %c", &piece);
        }

        for (k = 0; k < 3; k++) {  // prevent the player from placing the same piece they are trying to choose
            for (j = 0; j < 3; j++) {
                if (square[k][j] != piece) {  // check if each square on the board has a piece equal to the one they are trying to place
                    a++;                      // if it is different from the piece, increment a++
                }
            }
        }

        while (a != 9) {  // while there is the piece that the player is trying to place on the board
            a = 0;
            printf("This piece is already on the board. Try again.\n");
            scanf(" %c", &piece);
            for (k = 0; k < 3; k++) {  // prevent the player from placing the same piece they are trying to choose
                for (j = 0; j < 3; j++) {
                    if (square[k][j] != piece) {  // check again if each square on the board has a piece equal to the one they are trying to place
                        a++;                      // if it is different from the piece, increment a++
                    }
                }
            }
            if (a == 9) {  // if the piece is not on the board, exit the loop
                break;
            }
        }

        a = 0;  // reset a to avoid issues in the next loop

        printf("\nNow choose the row and then the column where you want to place the piece:\n\n");

        board(square);

        scanf("%d %d", &k, &j);  // get the values of the squares the player wants to select

        while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {  // prevent the player from typing a square that does not exist
            printf("Invalid placement. Try again\n");
            scanf("%d %d", &k, &j);
        }

        while (square[k - 1][j - 1] != empty) {
            printf("Space occupied. Try again\n");  // prevent the player from typing a square that is already occupied
            scanf("%d %d", &k, &j);
        }

        getchar();  // get unnecessary characters

        square[k - 1][j - 1] = piece;  // place the piece on the board

        board(square);  // functions to print the board

        win1(square);  // check if player 1 has won

        printf("\nPlayer 2, choose your piece.\n");

        i = 0;

        /* For Player 2, a very similar code is used,
           the changes are limited to changes from uppercase pieces (Player 1) to lowercase pieces (Player 2).
           Since the code is already large, I will refrain from commenting in detail on each part. */

        for (k = 0; k < 3; k++) {  // loop to check for pieces already placed by Player 2.
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'b') {
                    i++;
                }
            }
        }

        if (i == 9) {
            printf("Type 'b' for bishop \n");
        }

        i = 0;

        for (k = 0; k < 3; k++) {
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'r') {
                    i++;
                }
            }
        }

        if (i == 9) {
            printf("Type 'r' for rook \n");
        }

        i = 0;

        for (k = 0; k < 3; k++) {
            for (j = 0; j < 3; j++) {
                if (square[k][j] != 'k') {
                    i++;
                }
            }
        }

        if (i == 9) {
            printf("Type 'k' for knight \n");
        }

        scanf(" %c", &piece);  // get the value of the piece the player wants to move.

        while (piece != 'b' && piece != 'r' && piece != 'k') {  // prevent the player from typing a piece that does not exist
            printf("Invalid piece. Try again.\n");
            scanf(" %c", &piece);
        }

        for (k = 0; k < 3; k++) {  // prevent the player from placing the same piece they are trying to choose, the same logic as for Player 1
            for (j = 0; j < 3; j++) {
                if (square[k][j] != piece) {
                    a++;
                }
            }
        }

        while (a != 9) {
            a = 0;
            printf("This piece is already on the board. Try again.\n");
            scanf(" %c", &piece);
            for (k = 0; k < 3; k++) {
                for (j = 0; j < 3; j++) {
                    if (square[k][j] != piece) {
                        a++;
                    }
                }
            }
            if (a == 9) {  // if the new piece meets the conditions, it exits the loop
                break;
            }
        }
        a = 0;

        printf("Now choose the row first and then the column where you want to place the piece:\n\n");

        board(square);

        scanf("%d %d", &k, &j);  // get the values of the squares the player wants to select

        while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {  // prevent the player from typing a square that does not exist
            printf("Invalid placement. Try again\n");
            scanf("%d %d", &k, &j);
        }

        while (square[k - 1][j - 1] != empty) {
            printf("Space occupied. Try again\n");  // prevent the player from typing a square that is already occupied
            scanf("%d %d", &k, &j);
        }

        getchar();  // get unnecessary characters

        square[k - 1][j - 1] = piece;  // place the piece on the board

        board(square);  // print the board

        win2(square);  // check for Player 2's victory

        n++;  // increment the counter for the change of rounds
    }

    printf("Now you can move your pieces.\n");  // after all the pieces are placed, the pieces can be moved

    n = 1;  // n becomes a counter to print the number of rounds

    while (n < 31) {
        /* Here we use the move verification functions.
           If all of them return 0,
           it means there are no possible moves with any of the player's pieces, therefore, a draw. */

        if (movbishopB(square) == 0 && movrookR(square) == 0 && movknightK(square) == 0) {  // draw condition
            printf("No more possible moves for Player 1.\n");
            printf("End of the game: draw.\n");
            return 0;
        }

        printf("ROUND %d", n);  // display the round number
        printf("\n\nPlayer 1, choose a piece to move.\n");

        if (movbishopB(square) == 1) {        // if it is possible to move the piece, the function will return 1
            printf("Type 'B' for bishop\n");  // and the printf for the respective piece will appear; if not possible, they won't
        }

        if (movrookR(square) == 1) {
            printf("Type 'R' for rook\n");
        }

        if (movknightK(square) == 1) {
            printf("Type 'K' for knight\n");
        }

        scanf(" %c", &piece);  // get the value of the piece

        while (piece != 'B' && piece != 'R' && piece != 'K') {  // lock the player until they choose a valid piece
            printf("Invalid piece. Try again.\n");
            scanf(" %c", &piece);
        }

        /* If the piece movement function is equal to 0,
           it will not be possible to select the piece */

        if (movbishopB(square) == 0) {
            while (piece == 'B') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        if (movrookR(square) == 0) {
            while (piece == 'R') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        if (movknightK(square) == 0) {
            while (piece == 'K') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        for (k = 0; k < 3; k++) {  // identify where the previously chosen piece is
            for (j = 0; j < 3; j++) {
                if (square[k][j] == piece) {
                    k1 = k;
                    j1 = j;
                }
            }
        }

        printf("Now choose the row first and then the column where you want to place the piece:\n\n");

        board(square);

        scanf("%d %d", &k, &j);  // get the values of rows and columns for the new position

        while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {  // lock the player until they choose a valid square
            printf("Invalid placement. Try again\n");
            scanf("%d %d", &k, &j);
        }

        while (square[k - 1][j - 1] != empty) {  // if the square is occupied, it cannot be chosen
            printf("Space occupied. Try again\n");
            scanf("%d %d", &k, &j);
        }

        getchar();  // get unnecessary characters

        k = k - 1;  // since the matrix starts at 0, subtract 1 from the value entered by the player
        j = j - 1;

        /* Here we use the functions to analyze the movement of the piece */
        if (piece == 'B') {
            a = bishop(square, k, j, k1, j1);
        }

        if (piece == 'R') {
            a = rook(square, k, j, k1, j1);
        }

        if (piece == 'K') {
            a = knight(square, k, j, k1, j1);
        }

        /* If the movement is invalid, the player will have to choose the movement again
           and here we repeat the process above for the verification of squares and movements */
        while (a == 0) {
            printf("Invalid movement. Try again.\n");
            scanf("%d %d", &k, &j);

            while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {  // loop to lock the player until they choose a valid square
                printf("Invalid placement. Try again\n");
                scanf("%d %d", &k, &j);
            }

            while (square[k - 1][j - 1] != empty) {
                printf("Space occupied. Try again\n");
                scanf("%d %d", &k, &j);
            }

            getchar();  // get unnecessary characters

            k = k - 1;
            j = j - 1;

            if (piece == 'B') {
                a = bishop(square, k, j, k1, j1);
            }

            if (piece == 'R') {
                a = rook(square, k, j, k1, j1);
            }

            if (piece == 'K') {
                a = knight(square, k, j, k1, j1);
            }
        }

        square[k1][j1] = ' ';  // placing an empty space where the piece was
        square[k][j] = piece;  // and placing the new piece

        board(square);  // print the board

        win1(square);  // check if there is a win for Player 1

        /* Repeat the process for Player 2 */
        /* If there are no more moves for Player 2, define it as a draw and end the program */

        if (movbishopb(square) == 0 && movrookr(square) == 0 && movknightk(square) == 0) {
            printf("No more possible moves for Player 2.\n");
            printf("End of the game: draw.\n");
            return 0;
        }

        printf("Player 2, choose a piece to move.\n");

        if (movbishopb(square) == 1) {        // if it is possible to move the piece, the function will return 1
            printf("Type 'b' for bishop\n");  // and the printf for the respective piece will appear; if not possible, they won't
        }

        if (movrookr(square) == 1) {
            printf("Type 'r' for rook\n");
        }

        if (movknightk(square) == 1) {
            printf("Type 'k' for knight\n");
        }

        scanf(" %c", &piece);  // get the value of the piece

        while (piece != 'b' && piece != 'r' && piece != 'k') {  // lock the player if they type an invalid piece
            printf("Invalid piece. Try again.\n");
            scanf(" %c", &piece);
        }

        /* If the piece movement function is equal to 0,
           it will not be possible to select the piece */

        if (movbishopb(square) == 0) {
            while (piece == 'b') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        if (movrookr(square) == 0) {
            while (piece == 'r') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        if (movknightk(square) == 0) {
            while (piece == 'k') {
                printf("Piece without valid moves. Try again.\n");
                scanf(" %c", &piece);
            }
        }

        for (k = 0; k < 3; k++) {  // identify the previous position of the chosen piece
            for (j = 0; j < 3; j++) {
                if (square[k][j] == piece) {
                    k1 = k;
                    j1 = j;
                }
            }
        }

        printf("Now choose the row first and then the column where you want to place the piece:\n\n");

        board(square);  // print the board

        scanf("%d %d", &k, &j);  // get the values of rows and columns for the new position

        while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {  // lock until the player chooses a valid square
            printf("Invalid placement. Try again\n");
            scanf("%d %d", &k, &j);
        }

        while (square[k - 1][j - 1] != empty) {
            printf("Space occupied. Try again\n");  // lock until the player chooses an unoccupied square
            scanf("%d %d", &k, &j);
        }

        k = k - 1;
        j = j - 1;


        /* Here, we use functions to analyze the movement of the piece */

        if (piece == 'b') {
            a = bishop(square, k, j, k1, j1);
        }

        if (piece == 'r') {
            a = rook(square, k, j, k1, j1);
        }

        if (piece == 'k') {
            a = knight(square, k, j, k1, j1);
        }

        /* If the movement is invalid, the player will have to choose the movement again
           and here we repeat the process above for the verification of squares and movements */

        while (a == 0) {
            printf("Invalid movement. Try again.\n");
            scanf("%d %d", &k, &j);

            while ((k != 1 && k != 2 && k != 3) || (j != 1 && j != 2 && j != 3)) {
                printf("Invalid placement. Try again\n");
                scanf("%d %d", &k, &j);
            }

            while (square[k - 1][j - 1] != empty) {
                printf("Space occupied. Try again\n");
                scanf("%d %d", &k, &j);
            }

            getchar();  // get unnecessary characters

            k = k - 1;
            j = j - 1;

            if (piece == 'b') {
                a = bishop(square, k, j, k1, j1);
            }

            if (piece == 'r') {
                a = rook(square, k, j, k1, j1);
            }

            if (piece == 'k') {
                a = knight(square, k, j, k1, j1);
            }
        }

        square[k1][j1] = ' ';  // placing an empty space where the piece was
        square[k][j] = piece;  // placing the new piece

        board(square);  // print the board

        win2(square);  // check if there is a win for Player 2

        n++;  // increment the ROUND counter
    }

    printf("End of moves.\n");  // if there are 30 moves, the program ends and prints a draw
    printf("Draw.\n");

    return 0;
}
