#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {

    // Fill in your main function here
    int N;
    scanf("%d", &N);
    struct point * polygon = malloc(N * sizeof(struct point));

    initializePoly(polygon, N);
    printPoly(polygon, N);
    free(polygon);
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

// Write your initializePoly() function here
void initializePoly(struct point *ptr, int N) {
    for (int i = 0; i < N; i++) {
        ptr[i].x = -i;
        ptr[i].y = i * i;
    }
}
