#include <stdio.h>

int main(void) {
    char text[68][40];
    int length = sizeof(text) / sizeof(text[0]);
    int i;

    for (i = 0; i < length; i++) {
        scanf("%39s", text[i]);
    }

    for (i = length - 1; i >= 0; i--) {
        printf("%s ", text[i]);
    }

    return 0;
}
