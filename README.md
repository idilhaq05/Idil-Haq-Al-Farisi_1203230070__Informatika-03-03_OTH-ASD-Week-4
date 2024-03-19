```sh
#include <stdio.h>
#include <stdlib.h>

void printCards(int *cards, int N, int swapNum) {
    printf("Perurutan ke-%d: ", swapNum);
    for(int i = 0; i < N; i++) {
        if(cards[i] == 11) printf("J ");
        else if(cards[i] == 12) printf("Q ");
        else if(cards[i] == 13) printf("K ");
        else printf("%d ", cards[i]);
    }
    printf("\n");
}

int main() {
    int N, i, j, temp, swaps = 0;
    char input[3];

    scanf("%d", &N);
    int *cards = malloc(N * sizeof(int));

    for(i = 0; i < N; i++) {
        scanf("%s", input);
        if(input[0] == 'J') cards[i] = 11;
        else if(input[0] == 'Q') cards[i] = 12;
        else if(input[0] == 'K') cards[i] = 13;
        else cards[i] = atoi(input);
    }
    for(i = 0; i < N-1; i++) {
        int min_idx = i;
        for(j = i+1; j < N; j++) {
            if(cards[j] < cards[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            temp = cards[min_idx];
            cards[min_idx] = cards[i];
            cards[i] = temp;
            swaps++;
            printCards(cards, N, swaps);
        }
    }
    printf(" %d\n", swaps);
    free(cards);
    return 0;
}
```
```sh
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
```
