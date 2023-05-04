#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}





char get_winner(char board[3][3]) {
    char winner = '-';
    int i = 0;
    bool dxx = true;
    bool doo = true;
    bool hxx = true;
    bool hoo = true;
    bool vxx = true;
    bool voo = true;

    //-------------------------------------
    while (i<3) {
        //diagonal ->
        if(board[i][i] != 'X') {
            dxx = false;
        }
        if(board[i][i] != 'O') {
            doo = false;
        }
        i = i + 1;
    }
    if(dxx) {
        winner = 'X';
    }
    if(doo) {
        winner = 'O';
    }




    

    //--------------------------------------
    i = 2;
    dxx = true;
    doo = true;
    int j = 0;
    while(j<3) {
        if(board[i][j]!= 'X') {
            dxx = false;
        }
        if(board[i][j] != 'O') {
            doo = false;
        }
        i = i - 1;
        j = j + 1;
    }

    if(dxx) {
        winner = 'X';
    }
    if(doo) {
        winner = 'O';
    }


    //filas
    //--------------------------------------
    i = 0;
    while(i<3) {
        int j = 0;
        hxx = true;
        hoo = true;
        while(j<3) {
            if (board[i][j] != 'X') {
                hxx = false;
            }
            if (board[i][j] != 'O') {
                hoo = false;
            }
            j = j + 1;
        }

        if(hxx) {
            winner = 'X';
            break;
        }
        if(hoo) {
            winner = 'O';
            break;
        }

        i = i + 1;
    }

    //-------------------------------------
    //verticales

    i = 0;
    while(i<3) {
        vxx = true;
        voo = true;
        int j = 0;
        while (j<3) {
            if(board[j][i] != 'X') {
                vxx = false;
            }
            if (board[j][i] != 'O') {
                voo = false;
            }
            j = j + 1;
        }
        if(vxx) {
            winner = 'X';
            break;
        }

        if(voo) {
            winner = 'O';
            break;
        }

        i = i + 1;
        
    }


    return winner;
}





bool has_free_cell(char board[3][3]) {
    bool free_cell=false;
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j<3) {
            if ((board[i][j]) == '-') {
                free_cell = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}



