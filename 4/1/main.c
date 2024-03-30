#include <stdio.h>

void behind(int *, int);
int findMax(int *, int);

int main(void) {
    int array[10];
    int N, i;

    printf("Enter the number of players:\n");
    scanf("%d", &N);

    printf("Enter their scores:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    behind(array, N);
    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void behind(int * array, int length) {
    int max = findMax(array, length);

    for (int i = 0; i < length; i++) {
        array[i] = max - array[i];
    }
}

int findMax(int * array, int length) {
    int max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}
