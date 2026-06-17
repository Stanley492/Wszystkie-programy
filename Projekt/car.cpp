#include <stdio.h>
#include <string.h>
#include "car.h"
#include "utils.h"

double obliczCene(struct Samochod *s) {
    double cena = s->cena_bazowa;

    if (strcmp(s->silnik, "Diesel") == 0) cena += 5000;
    else if (strcmp(s->silnik, "Elektryczny") == 0) cena += 20000;

    if (strcmp(s->kolor, s->kolor_fabryczny) != 0) {
        if (strcmp(s->kolor, "Czerwony") == 0) cena += 1500;
        else if (strcmp(s->kolor, "Bialy") == 0) cena += 1000;
        else if (strcmp(s->kolor, "Niebieski") == 0) cena += 1500;
        else if (strcmp(s->kolor, "Czarny") == 0) cena += 1000;
    }
    if (s->dodatek_sport) cena += 12000;
    if (s->dodatek_salon) cena += 8000;
    if (s->dodatek_autonomiczny) cena += 25000;

    return cena;
}

void wyswietlSamochod(struct Samochod *s) {
    printf("Model: %s\n", s->model);
    printf("Cena bazowa: %.2lf zl\n", s->cena_bazowa);
    printf("Silnik: %s\n", s->silnik);
    printf("Kolor: %s\n", s->kolor);

    printf("Dodatki:\n");
    if (s->dodatek_sport) printf("- Pakiet sportowy\n");
    if (s->dodatek_salon) printf("- Skorzana tapicerka\n");
    if (s->dodatek_autonomiczny) printf("- System autonomiczny\n");
    if (!s->dodatek_sport && !s->dodatek_salon && !s->dodatek_autonomiczny)
        printf("- Brak dodatkow\n");

    printf("Cena koncowa: %.2lf zl\n\n", s->cena_koncowa);
}

void konfigurujSamochod(struct Samochod auta[], int n) {

    printf("Wybierz model (1-%d): ", n);
    int id = getInt();

    if (id < 1 || id > n) {
        printf("Niepoprawny numer!\n");
        return;
    }
    id--;

    printf("\nWybierz silnik:\n");
    printf("1. Benzyna\n");
    printf("2. Diesel\n");
    printf("3. Elektryczny\n");
    int s = getInt();

    switch (s) {
        case 1: strcpy(auta[id].silnik, "Benzyna"); break;
        case 2: strcpy(auta[id].silnik, "Diesel"); break;
        case 3: strcpy(auta[id].silnik, "Elektryczny"); break;
        default: printf("Niepoprawny wybor.\n"); break;
    }

    printf("\nWybierz kolor:\n");
    printf("1. Czarny\n");
    printf("2. Czerwony\n");
    printf("3. Bialy\n");
    printf("4. Niebieski\n");
    int k = getInt();

    switch (k) {
        case 1: strcpy(auta[id].kolor, "Czarny"); break;
        case 2: strcpy(auta[id].kolor, "Czerwony"); break;
        case 3: strcpy(auta[id].kolor, "Bialy"); break;
        case 4: strcpy(auta[id].kolor, "Niebieski"); break;
        default: printf("Niepoprawny wybor.\n"); break;
    }

    printf("\nDodatki (0 = nie, 1 = tak):\n");

    printf("Pakiet sportowy: ");
    auta[id].dodatek_sport = getInt();

    printf("Skorzana tapicerka: ");
    auta[id].dodatek_salon = getInt();

    printf("System autonomiczny: ");
    auta[id].dodatek_autonomiczny = getInt();

    auta[id].cena_koncowa = obliczCene(&auta[id]);

    printf("\nKonfiguracja zapisana!\n");
}

int znajdzNajtanszy(struct Samochod auta[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++)
        if (auta[i].cena_koncowa < auta[minIndex].cena_koncowa)
            minIndex = i;
    return minIndex;
}
int znajdzNajdrozszy(struct Samochod auta[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (auta[i].cena_koncowa > auta[maxIndex].cena_koncowa)
            maxIndex = i;
    return maxIndex;
}