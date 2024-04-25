#include <stdio.h>
#include <math.h>

int main(){
    int A,B,N;
    printf("Podaj N liczb do wpisania: ");
    scanf("%d",&N);
    printf("Podaj liczbe A przedzialu <A,B>: ");
    scanf("%d",&A);
    printf("Podaj liczbe B przedzialu <A,B>: ");
    scanf("%d",&B);
    float suma=0;
    for(int i=0;i<N;i++){
        float liczba;
        printf("Podaj liczbe: ");
        scanf("%f",&liczba);
        if(liczba>=A&&liczba<=B)
            suma+=liczba;
    }
    printf("Suma liczb nalezacych do przedzialu <%d,%d> jest rowna %.2f\n",A,B,suma);
    system("pause");
}