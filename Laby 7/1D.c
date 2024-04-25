#include <stdio.h>
#include <math.h>

int main(){
    int N=0;
    while(N<=0){
        printf("Podaj wielkosc tablicy: ");
        scanf("%d",&N);
    }
    float tab[N];
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        scanf("%f",&tab[i]);
    }
    printf("Tablica T: [%.2f",tab[0]);
    for(int i=1;i<N;i++)
        printf(",%.2f",tab[i]);
    printf("]\n");
    float iloczyn=1,suma=0,liczby=0;
    if(N>1){
        for(int i=0;i<N;i++){
            float liczba=tab[i];
            if(liczba<tab[N-1]){
                suma+=liczba;
                liczby++;
            }
            if(liczba>=tab[0]&&liczba<=tab[1])
                iloczyn*=liczba;
        }
        if(liczby==0)
            printf("W podanej tablicy nie ma liczb mniejszych od liczby T[N-1] (%.2f)\n",tab[N-1]);
        else
            printf("Srednia liczb mniejszych od %.2f jest rowna %.2f\n",tab[N-1],suma/liczby);
        printf("Iloczyn liczb z przedzialu <%.2f,%.2f> jest rowny %.2f\n",tab[0],tab[1],iloczyn);
    }
    else
        printf("Tablica o podanym rozmiarze nie moze byc wykorzystana do moich obliczen\n");
    
    float X[N],Y[N],A[N];
    for(int i=0;i<N;i++){
        X[i]=abs(tab[i]);
        Y[i]=tab[N-1-i];
    }
    printf("Tablica X: [%.2f",X[0]);
    for(int i=1;i<N;i++)
        printf(",%.2f",X[i]);
    printf("]\n");
    printf("Tablica Y: [%.2f",Y[0]);
    for(int i=1;i<N;i++)
        printf(",%.2f",Y[i]);
    printf("]\n");
    
    for(int i=0;i<N;i++){
        if(tab[i]<Y[i])
            A[i]=tab[i];
        else
            A[i]=Y[i];
    }
    printf("Tablica A: [%.2f",A[0]);
    for(int i=1;i<N;i++)
        printf(",%.2f",A[i]);
    printf("]\n");
    
    system("pause");
}