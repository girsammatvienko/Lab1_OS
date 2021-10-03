#include <stdio.h>

int printGameResults(int nums, int gain) {
    int f1 = nums / 1000;
    int f2 = nums % 1000;
    int arr[6] = {f1 / 100, f1 / 10 % 10, f1 % 10, f2 / 100, f2 / 10 % 10, f2 % 10};
    int i;
    for(i = 0;i < 6;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Your gain: %d\n\n", gain);
}