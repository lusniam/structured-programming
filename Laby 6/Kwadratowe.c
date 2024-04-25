#include <stdio.h>
#include <math.h>

float Delta(float a, float b, float c){
    return pow(b,2)-4*a*c;
}

float PierwiastekDelta0(float a, float b, float c){
    return -b/(2*a);
}

float PierwiastekDeltaPlus(float a, float b, float c){
    return (-b+sqrt((double)Delta(a,b,c)))/(2*a);
}

float PierwiastekDeltaMinus(float a, float b, float c){
    return (-b-sqrt((double)Delta(a,b,c)))/(2*a);
}

int main(){
    while(1>0){
        float a,b,c;
        printf("Dane jest rownanie kwadratowe a*x^2+b*x+c=0.\nZnajde jego pierwiastki.\nPodaj a:");
        scanf("%f",&a);
        printf("Podaj b:");
        scanf("%f",&b);
        printf("Podaj c:");
        scanf("%f",&c);

        if(a==0){
            if(b==0)
                printf("Rownanie jest sprzeczne.");
            else
                printf("Rownanie jest liniowe, x=%f",-c/b);
        }
        else if(Delta(a,b,c)<0)
            printf("Rownanie nie ma pierwiastkow, jest sprzeczne.");
        else if(Delta(a,b,c)==0)
            printf("Rownanie ma jeden pierwiastek, x0=%.2f",PierwiastekDelta0(a,b,c));
        else
            printf("Rownanie ma dwa pierwiastki: x1=%.2f, x2=%.2f",PierwiastekDeltaPlus(a,b,c),PierwiastekDeltaMinus(a,b,c));
        char w;
        printf("\nCzy wyjsc z programu? (Wpisz 't' aby wyjsc, 'n' aby zostac)");
        scanf(" %c",&w);
        if(w=='t')
            break;
        system("clear");
    }
    return 0;
}