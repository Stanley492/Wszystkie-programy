#ifndef CAR_H
#define CAR_H

struct Samochod {
    char model[30];
    double cena_bazowa;

    char silnik[20];
    char kolor[20];
    char kolor_fabryczny[20];
    int dodatek_sport;
    int dodatek_salon;
    int dodatek_autonomiczny;

    double cena_koncowa;
};

double obliczCene(struct Samochod *s);
void wyswietlSamochod(struct Samochod *s);
void konfigurujSamochod(struct Samochod auta[], int n);
int znajdzNajtanszy(struct Samochod auta[], int n);
int znajdzNajdrozszy(struct Samochod auta[], int n);

#endif