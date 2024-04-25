#include <stdio.h>
#include <math.h>

int main(){
    char t='t';
    while(){
        char a;
        printf("Zamiana:\n\tA) Predkosc w m/sek i km/godz\n\tB) Miara kata w stopniach i radianach\nWybierz opcje: ");
        scanf(" %c",&a);
        while(a!='A'&&a!='B'){
            printf("Podano zly znak! Wpisz znak A lub B: ");
            scanf(" %c",&a);
        }
        switch(a){
            case 'A':{
                printf("Zamiana:\n\tA) m/sek -> km/godz\n\tB) km/godz -> m/sek\nWybierz opcje: ");
                char b;
                scanf(" %c",&b);
                while(b!='A'&&b!='B'){
                    printf("Podano zly znak! Wpisz znak A lub B: ");
                    scanf(" %c",&b);
                }
                    switch(b){
                        case 'A':{
                            printf("Wpisz wartosc w m/sek: ");
                            float wartosc;
                            scanf("%f",&wartosc);
                            wartosc*=3.6;
                            printf("Podana wartosc jest rowna %f",wartosc);
                            printf(" km/godz");
                        break;
                        }
                        case 'B':{
                            printf("Wpisz wartosc w km/godz: ");
                            float wartosc;
                            scanf("%f",&wartosc);
                            wartosc/=3.6;
                            printf("Podana wartosc jest rowna %f",wartosc);
                            printf(" m/sek");
                            break;
                        }
                        default: break;
                    }
                break;
            }
            case 'B':{
                printf("Zamiana:\n\tA) stopnie -> radiany\n\tB) radiany -> stopnie\nWybierz opcje: ");
                char b;
                scanf(" %c",&b);
                while(b!='A'&&b!='B'){
                    printf("Podano zly znak! Wpisz znak A lub B: ");
                    scanf(" %c",&b);
                }
                    switch(b){
                        case 'A':{
                            printf("Wpisz wartosc w stopniach:");
                            float wartosc;
                            scanf("%f",&wartosc);
                            wartosc*=(M_PI/180);
                            printf("Podana wartosc jest rowna %f",wartosc);
                            printf(" w radianach");
                            break;
                        }
                        case 'B':{
                            printf("Wpisz wartosc w radianach:");
                            float wartosc;
                            scanf("%f",&wartosc);
                            wartosc/=(M_PI/180);
                            printf("Podana wartosc jest rowna %f",wartosc);
                            printf(" stopni");
                            break;
                        }
                        default: break;
                    }
                break;
            }
            default: break;
        }
    }
    return 0;
}
