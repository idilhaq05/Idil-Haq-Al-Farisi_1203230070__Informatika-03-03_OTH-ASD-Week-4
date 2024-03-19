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
