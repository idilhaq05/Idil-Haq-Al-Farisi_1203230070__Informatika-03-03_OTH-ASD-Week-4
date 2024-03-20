#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, j, temp, swaps = 0;
    char input[3];
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &N);
    int *cards = malloc(N * sizeof(int));
    printf("Masukkan nilai kartu: ");
    for(i = 0; i < N; i++) {
        scanf("%s", input);
        if(input[0] == 'J') cards[i] = 11;
        else if(input[0] == 'Q') cards[i] = 12;
        else if(input[0] == 'K') cards[i] = 13;
        else cards[i] = atoi(input);
    }
    for(i = 0; i < N-1; i++) {
        for(j = 0; j < N-i-1; j++) {
            if(cards[j] > cards[j+1]) {
                temp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = temp;
                swaps++;
            }
        }
    }
    printf("Jumlah minimal langkah pertukaran: %d\n", swaps);
    free(cards);
    return 0;
}
