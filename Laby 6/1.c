#include <stdio.h>
#include <math.h>
int main(){
    int A,B,K;
    printf("Oblicze wartosc x^2+x=1 dla x z przedzialu <A,B> co krok K\n");
    printf("Podaj liczbe A: ");
    scanf("%d",&A);
    printf("Podaj liczbe B: ");
    scanf("%d",&B);
    printf("Podaj liczbe K: ");
    scanf("%d",&K);
    int x=A;
    while(x<=B){
        printf("x=%d, x2+x+1=%d\n",x,(int)pow(x,2)+x+1);
        x+=K;
    }
    system("pause");
}