#include <stdio.h>

void menu(void) {
    printf("1. Enter the values into the array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the minimum value\n");
    printf("4. Determine the maximum value\n");
    printf("5. Determine the average value\n");
    printf("6. Determine the median value\n");
    printf("0. EXIT\n");
    printf("Select an option:\n");
}

void ReadArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Podaj liczbe [%d]: ", i);
        scanf("%d", &numbers[i]);
    }
}

void PrintArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Number[%d] = %d\n", i, numbers[i]);
    }
}

int FindMaximum(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int FindMinimum(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int SumArray(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}

float CalculateAverage(int numbers[], int size) {
    return (float)SumArray(numbers, size) / size;
}

void CopyArray(int numbers[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = numbers[i];
    }
}

void SortArray(int copy[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (copy[j] > copy[j + 1]) {
                int temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
            }
        }
    }
}

float CalculateMedian(int numbers[], int size) {
    if (size % 2 == 0) {
        return (numbers[size/2 - 1] + numbers[size/2]) / 2.0f;
    } else {
        return numbers[size/2];
    }
}

int main() {
    int SIZE;
    int number[SIZE];
    int copy[SIZE];
    int option = 0;
    printf("Arrays\n");


    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("Podaj rozmiar tablicy: ");
                scanf("%d", &SIZE);
                printf("Wprowadz %d liczb:\n", SIZE);
                ReadArray(number, SIZE);
                break;
            case 2:
                PrintArray(number, SIZE);
                break;
            case 3:
                printf("Min number: %d\n", FindMinimum(number, SIZE));
                break;
            case 4:
                printf("\nMax number: %d\n", FindMaximum(number, SIZE));
                break;
            case 5:
                printf("Average number: %.2f\n", CalculateAverage(number, SIZE));
                break;
            case 6:
                CopyArray(number, copy, SIZE);
                SortArray(copy, SIZE);
                printf("Mediana: %.2f\n\n", CalculateMedian(copy, SIZE));
            default:
                printf("Choose the right option...\n\n");
        }

    } while (option != 0);


    printf("THE END!\n");

    return 0;
}