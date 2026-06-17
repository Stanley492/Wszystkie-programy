#include <stdio.h>

int main() {
    printf("simple calc\n");
    while (1) {

        int Number1 = 0;
        printf("Enter Number_1\n");
        scanf("%d", &Number1);
        if (Number1==0) {
            break;
        }

        int Number2 = 0;
        printf("Enter Number_2:\n");
        scanf("%d", &Number2);
        if (Number2==0) {
            break;
        }

        // Wykonanie obliczeń
        printf("%d + %d = %d\n", Number1, Number2, Number1 + Number2);
        printf("%d - %d = %d\n", Number1, Number2, Number1 - Number2);
        printf("%d * %d = %d\n", Number1, Number2, Number1 * Number2);
        printf("%d / %d = %d\n", Number1, Number2, Number1 / Number2);
        printf("%d %% %d = %d\n", Number1, Number2, Number1 % Number2);
        printf("\n");
    }

    return 0;
}