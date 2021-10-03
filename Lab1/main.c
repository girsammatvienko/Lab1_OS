#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumbersSequence();
int pow(int n, int degree);
int evaluateResult(int n, int stake);
int countSevens(int n);
int isAllNumsIdentical(int n);
int countIdentical(int n);

int main(int argc, char *argv[]) {
	int nums;
	int gain = 0;
	int choice;
	while(1) {
		choice = getChoice();
		switch(choice) {
			case 1:
			nums = generateNumbersSequence();
			gain = evaluateResult(nums, getStake());
			printGameResults(nums, gain);
				break;
			case 2:
				return 0;
		}
	}
}

int countIdentical(int n) {
int f1 = n / 1000;
int f2 = n % 1000;
int arr[6] = {f1 / 100, f1 / 10 % 10, f1 % 10, f2 / 100, f2 / 10 % 10, f2 % 10};
int i, j;
for(i = 0;i < 6;i++) {
	for(j = i + 1;j < 6;j++) {
		if(arr[i] == arr[j]) return 1;
	}
}
return 0;
}

int evaluateResult(int n, int stake) {
	int sevensAmount = countSevens(n);

	if(sevensAmount == 1 || countIdentical(n) >= 1) return stake;
	if(isAllNumsIdentical(n) && sevensAmount == 6) return stake * 3;
	if(isAllNumsIdentical(n)) return stake * 2;
	return 0;
}

int isAllNumsIdentical(int n) {
	int f1 = n / 1000;
	int f2 = n % 1000;
	int arr[6] = {f1 / 100, f1 / 10 % 10, f1 % 10, f2 / 100, f2 / 10 % 10, f2 % 10};
	int i;
	for(i = 1; i < 6; ++i) {
        if(arr[i] != arr[0]) return 0;
    }
	return 1;
}

int countSevens(int n) {
	int f1 = n / 1000;
	int f2 = n % 1000;
	int arr[6] = {f1 / 100, f1 / 10 % 10, f1 % 10, f2 / 100, f2 / 10 % 10, f2 % 10};
	int i;
	int counter = 0;
	for(i = 0;i < 6;i++) {
		if(arr[i] == 7) counter++;
	}
	return counter;
}

int generateNumbersSequence() {
srand(time(NULL));
	int amount = 6;
	int i;
	int nums[amount];
	int result = 0;
	for(i = 0; i < amount;i++) {
		nums[i] = 1 + rand() % 9;
		result += nums[i] * (pow(10, i));
	}
	return result;
}

int pow(int n, int degree) {
	int result = 1;
	int i;
	for(i = 1;i < degree+1;i++) result *= n;
	return result;
}
