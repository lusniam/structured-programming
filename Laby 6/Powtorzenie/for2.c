#include <stdio.h>
#include <math.h>

int main(){
    int N,suma=0,nd=0,bdb=0;
    float srednia=0;
    printf("Podaj N ocen do wpisania: ");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        float liczba;
        printf("Podaj liczbe: ");
        scanf("%f",&liczba);
        if(liczba>=3){
            suma+=liczba;
            srednia++;
            if(liczba>4){
                bdb++;
            }
        }
        else if(liczba==2)
            nd++;
    }
    printf("Srednia ocen>3: %.1f\nLiczba ocen 2.0: %d\nLiczba ocen >4.0: %d\n",suma/srednia,nd,bdb);
    system("pause");
}