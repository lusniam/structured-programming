#include <stdio.h>
#include <math.h>

float W(float a1,float b1,float a2,float b2){
    return a1*b2-a2*b1;
}

float Wx(float c1,float b2,float c2,float b1){
    return c1*b2-c2*b1;
}

float Wy(float a1,float c2,float a2,float c1){
    return a1*c2-a2*c1;
}

int main(){
    printf("Mamy uklad rownan:\na1*x+b1*y=c1\na2*x+b2*y=c2\nOblicze x i y\n\n");
    float a1,a2,b1,b2,c1,c2;
    printf("Podaj a1:");
    scanf("%f",&a1);
    printf("Podaj b1:");
    scanf("%f",&b1);
    printf("Podaj c1:");
    scanf("%f",&c1);
    printf("Podaj a2:");
    scanf("%f",&a2);
    printf("Podaj b2:");
    scanf("%f",&b2);
    printf("Podaj c2:");
    scanf("%f",&c2);

    if(W(a1,b1,a2,b2)==0){
        if(c1==c2)
            printf("Rownanie jest nieoznaczone.");
        else
            printf("Rownanie jest sprzeczne.");
    }
    else{
        printf("x=%.2f, y=%.2f",Wx(c1,b2,c2,b1)/W(a1,b1,a2,b2),Wy(a1,c2,a2,c1)/W(a1,b1,a2,b2));
    }
    printf("\n\n");
    system("pause");
    return 0;
}