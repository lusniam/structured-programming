#include <stdio.h>
#include <math.h>

float Opcja1(int N){
    float wynik=0;
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        float liczba;
        scanf("%f",&liczba);
        wynik+=pow(liczba,2);
    }
    return wynik;
}

float Opcja2(int N){
    float wynik=0;
    int liczby=0;
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        float liczba;
        scanf("%f",&liczba);
        if(liczba<0){
            wynik+=liczba;
            liczby++;
        }
    }
    if(liczby==0)
        liczby++;
    return wynik/liczby;
}

float Opcja3(int N){
    float wynik=0;
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        float liczba;
        scanf("%f",&liczba);
        if(liczba>=1&&liczba<=10)
            wynik+=liczba;
    }
    return wynik;
}

float Opcja4(int N){
    float wynik=1;
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        float liczba;
        scanf("%f",&liczba);
        if(i%2==0)
            wynik*=liczba;
    }
    return wynik;
}

void Opcja5(int N,float &SumaP,float &SumaNP){
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        int liczba;
        scanf("%d",&liczba);
        if(liczba%2==0)
            SumaP+=liczba;
        else
            SumaNP+=liczba;
    }
}

int Opcja6(int N){
    int zle=0,IleDoDobrej=1;
    float r=0,prev,dobra;
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        float liczba;
        scanf("%f",&liczba);
        if(i==0)
            r-=liczba;
        else if(i==1){
            r+=liczba;
            prev=liczba;
            dobra=liczba;
        }
        else{
            if(liczba-prev!=r){
                if(liczba-IleDoDobrej*r!=dobra){
                    zle++;
                    IleDoDobrej++;
                }
                else{
                    IleDoDobrej=1;
                    dobra=liczba;
                }
            }
            prev=liczba;
        }
    }
    return zle;
}


int main(){
    int N;
    printf("Podaj ilosc N liczb do wpisania: ");
    scanf("%d",&N);
    int wybor;
    while(true){
        system("clear");
        printf("Co mam dla ciebie zrobic?\n1. Oblicz sume kwadratow liczb\n2. Oblicz srednia liczb\n");
        printf("3. Oblicz sume liczb z przedzialu <1,10>\n4. Oblicz iloczyn co drugiej liczby\n");
        printf("5. Oblicz sume liczb parzystych i sume nieparzystych\n");
        printf("6. Sprawdz, czy liczby sa ciagiem arytmetycznym\n");
        scanf("%d",&wybor);
        if(wybor>=1||wybor<=6)
            break;
    }
    system("clear");
    if(wybor==1)
        printf("Suma kwadratow podanych liczb jest rowna %.2f",Opcja1(N));
    else if(wybor==2)
        printf("Srednia arytmetyczna podanych liczb ujemnych jest rowna %.2f",Opcja2(N));
    else if(wybor==3)
        printf("Suma podanych liczb z przedzialu <1,10> jest rowna %.2f",Opcja3(N));
    else if(wybor==4)
        printf("Iloczyn co drugiej podanej liczby jest rowny %.2f",Opcja4(N));
    else if(wybor==5){
        float SumaP=0,SumaNP=0;
        Opcja5(N,SumaP,SumaNP);
        printf("Suma liczb parzystych jest rowna %.2f, a nieparzystych %.2f",SumaP,SumaNP);
    }
    else if(wybor==6){
        int zle=Opcja6(N);
        if(zle==0)
            printf("Podane liczby sa ciagiem arytmetycznym");
        else
            printf("Podane liczby nie sa ciagiem arytmetycznym, nie pasuje %d liczb",zle);
    }
    printf("\n\n");
    system("pause");
}