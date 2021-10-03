#include <stdio.h>

int getStake() {
    printf("How many do you want to bet?:\n> ");
    int stake;
    scanf("%d", &stake);
    return stake;
}

int getChoice() {
    int choice;
    printf("1 Start game\n2 Exit\n");
    printf("> ");
    scanf("%d", &choice);
    return choice;
}