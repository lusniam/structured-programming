#include <stdlib.h>
#include <stdio.h>

struct hurt{
    char nazwa[30];
    float ilosc;
    float cena;
};


int main(){
    struct hurt towar;
    printf("Podaj nazwe towaru: ");
    gets(towar.nazwa);
    printf("Podaj ilosc towaru: ");
    scanf("%f",&towar.ilosc);
    printf("Podaj cene towaru: ");
    scanf("%f",&towar.cena);

    printf("Wartosc towaru %s: %.2f\n",towar.nazwa,towar.cena*towar.ilosc);

    system("pause");
}