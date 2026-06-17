#include <stdio.h>
#include "utils.h"

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int getInt() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Blad: podaj liczbe! ");
        clearInput();
    }
    clearInput();
    return x;
}