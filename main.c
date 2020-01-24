#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 12000;

void Play(int bet){

    // char C[3] = {'J','Q','K'}; created on the stack
    char *C = malloc(3*sizeof(char)); // creating char array on the heap
    C[0] = 'J'; C[1] = 'Q'; C[2] = 'K';
    printf("Shuffling ... \n");
    srand(time(NULL)); // seeding random number generator

    for(int i = 0; i < 5; i++){
        int x = rand() % 3; // random number from 0 to 2 including
        int y = rand() % 3; // random number from 0 to 2 including
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp; // swaps characters at position x and y
    }

    int playersGuess;
    printf("What's the position of queen - 1, 2 or 3:: ");
    scanf("%d", &playersGuess);

    if(C[playersGuess - 1] == 'Q'){
        cash += 3*bet;
        printf("You win ! result = \"%c %c %c\" Total Cash= %d\n", C[0], C[1], C[2], cash);
    }
    else{
        cash -= bet;
        printf("You Loose ! Result = \"%c %c %c\" Total Cash= %d\n", C[0], C[1], C[2], cash);
    }

    free(C); // deallocated the memory

}

int main()
{
    int bet;
    printf("**Welcome to the Virtual Casino**\n\n");
    printf("Total cash= $%d\n", cash);
    while(cash > 0){
        printf("What is your bet? $");
        scanf("%d", &bet);
        if(bet == 0 || bet > cash) break;
        Play(bet);
        printf("\n**************************\n");
    }
}
