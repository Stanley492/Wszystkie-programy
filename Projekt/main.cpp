#include <stdio.h>
#include "car.h"
#include "utils.h"

int main() {

    struct Samochod auta[5] = {
        {"Peugeot 208", 70000, "Benzyna", "Zielony","Zielony", 0, 0, 0, 0},
        {"Peugeot 308", 90000, "Benzyna", "Czerwony","Czerwony", 0, 0, 0, 0},
        {"Peugeot 408", 150000, "Elektryczny", "Niebieski","Niebieski", 0, 0, 0, 0},
        {"Peugeot 508", 130000, "Benzyna", "Bialy","Bialy", 0, 0, 0, 0},
        {"Peugeot 607", 110000, "Diesel", "Szary","Szary", 0, 0, 0, 0}
    };

    for (int i = 0; i < 5; i++)
        auta[i].cena_koncowa = obliczCene(&auta[i]);

    int wybor;

    do {
        printf("\n========== SKLEP SAMOCHODOWY ==========\n");
        printf("1. Wyswietl modele\n");
        printf("2. Konfiguruj model\n");
        printf("3. Najtanszy\n");
        printf("4. Najdrozszy\n");
        printf("0. Wyjscie\n");
        printf("Twoj wybor: ");

        wybor = getInt();

        switch (wybor) {
            case 1:
                for (int i = 0; i < 5; i++)
                    wyswietlSamochod(&auta[i]);
                break;

            case 2:
                konfigurujSamochod(auta, 5);
                break;

            case 3: {
                int idx = znajdzNajtanszy(auta,5);
                wyswietlSamochod(&auta[idx]);
                break;
            }

            case 4: {
                int idx = znajdzNajdrozszy(auta,5);
                wyswietlSamochod(&auta[idx]);
                break;
            }

            case 0:
                printf("Koniec programu.\n");
                break;

            default:
                printf("Nie ma takiej opcji.\n");
        }

    } while (wybor != 0);

    return 0;
}