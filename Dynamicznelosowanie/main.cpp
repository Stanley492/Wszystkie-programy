#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int *numbers = NULL;   // dynamiczna tablica
    int size = 0;          // aktualna liczba elementów
    int count, min, max;   // ile losować i zakres
    time_t t;

    srand((unsigned) time(&t));

    while (1) {
        printf("\nIle liczb chcesz wylosowac? (0 = koniec): ");
        scanf("%d", &count);

        if (count == 0) {
            printf("Koniec programu. Czyszczenie pamieci...\n");
            free(numbers);
            return 0;
        }

        printf("Podaj dolny zakres: ");
        scanf("%d", &min);
        printf("Podaj gorny zakres: ");
        scanf("%d", &max);

        // powiększamy tablicę o count elementów
        int *tmp = (int *) realloc(numbers, (size + 1) * sizeof(int));
        // int *tmp = realloc(numbers, (size + count) * sizeof(int));
        if (tmp == NULL) {
            printf("Blad alokacji pamieci!\n");
            free(numbers);
            return 1;
        }
        numbers = tmp;

        // losowanie nowych liczb
        for (int i = 0; i < count; i++) {
            numbers[size + i] = (rand() % (max - min + 1)) + min;
        }
        size += count;

        // obliczanie min, max, średniej
        int smallest = numbers[0];
        int biggest = numbers[0];
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            if (numbers[i] < smallest) smallest = numbers[i];
            if (numbers[i] > biggest) biggest = numbers[i];
            sum += numbers[i];
        }

        float average = (float)sum / size;

        // wypisanie wyników
        printf("\nAktualna tablica (%d elementow):\n", size);
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }

        printf("\n\nStatystyki:\n");
        printf("Najmniejsza liczba: %d\n", smallest);
        printf("Najwieksza liczba: %d\n", biggest);
        printf("Srednia: %.2f\n", average);
    }

    return 0;
}