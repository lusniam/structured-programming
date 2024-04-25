#include <stdio.h>
#include <stdlib.h>

float F1(int N,float tab[],float *iloczyn){
    float suma=0,wynik=1;
    for(int i=0;i<N;i++){
        suma+=tab[i];
        wynik*=tab[i];
    }
    *iloczyn=wynik;
    return suma;
}

float F2(int N,float tab[],int *w_srednia){
    float wynik=0,o=2,srednia;
	srednia=F1(N,tab,&o)/(float)N;
    for(int i=0;i<N;i++){
        if(tab[i]>srednia)
            wynik++;
    }
    *w_srednia=wynik;
    return srednia;
}

float *F3(int N,float tab[],int *zast){
    int wynik=0;
    for(int i=0;i<N;i++){
        if(tab[i]<0){
            tab[i]=0;
            wynik++;
        }
    }
    *zast=wynik;
    return tab;
}

int main(){
    int N;
    printf("Podaj liczbe N: ");
    scanf("%d",&N);
    float tab[N];
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        scanf("%f",&tab[i]);
    }
    float iloczyn;
    float suma;
	suma=F1(N,tab,&iloczyn);
    printf("Suma liczb w tabeli jest rowna %f\nIloczyn tych liczb jest rowny %f\n",suma,iloczyn);

    int wieksze;
    float srednia=F2(N,tab,&wieksze);
    printf("Srednia liczb w tablicy jest rowna %f\n%d liczb jest wiekszych od sredniej\n",srednia,wieksze);

    int zastapienia;
    float *t;
    t=F3(N,tab,&zastapienia);
    printf("Zmieniona tablica:\n[%f",tab[0]);
    for(int i=1;i<N;i++){
        printf(",%f",tab[i]);
    }
    printf("]\nZastapiono %d liczb\n",zastapienia);
    system("Pause");
    return 0;
}