#include <stdio.h>

int main()
{
 int a, b;
 float x;
 printf("Program oblicza wartosc wyrazenia: (2a+b)/3");
 printf("\nPodaj liczbe a:");
 scanf("%d", &a);
 printf("Podaj liczbe b:");
 scanf("%d", &b);
 x=(2*a+b)/3.0;         // znak mnożenia, licznik w nawiasach ()!
 printf("Wynik: %f\n", x);
 return 0;
}