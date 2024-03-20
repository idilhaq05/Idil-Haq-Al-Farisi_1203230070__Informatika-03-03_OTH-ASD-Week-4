#include <stdio.h>
#include <stdlib.h>

void printBoard(int size, int *chessBoard) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", *((chessBoard+i*size) + j));
        }
        printf("\n");
    }
}

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for(int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        if(new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            *((chessBoard+new_i*size) + new_j) = 1;
        }
    }
}

int main() {
    int i, j;
    
    scanf("%d %d", &i, &j);
    int size = 8;
    int *chessBoard = (int *)calloc(size*size, sizeof(int));
    koboImaginaryChess(i, j, size, chessBoard);
    printBoard(size, chessBoard);
    free(chessBoard);
    return 0;
}
