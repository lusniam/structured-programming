#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    printf("Podaj tablice o wymiarach {a,b}\nPodaj liczbe a: ");
    scanf("%d",&a);
    printf("Podaj liczbe b: ");
    scanf("%d",&b);
    system("clear");

    float tab[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("Podaj liczbe z pola {%d,%d}: ",j,i);
            scanf("%f",&tab[i][j]);
            system("clear");
        }
    }

    printf("Przyjeta tabela:\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%f",tab[i][j]);
            printf("|");
        }
        printf("\n");
        for(int j=0;j<b;j++){
            printf("---------");
        }
        printf("\n");
    }

    int s;
    printf("\nPodaj kolumne, z ktorej mam policzyc srednia: ");
    scanf("%d",&s);
    if(s>0&&s<=a){
        float srednia=0;
        for(int i=0;i<b;i++){
            srednia+=tab[i][s-1];
        }
        srednia/=b;
        printf("Srednia liczb z kolumny %d wynosi %f\n",s,srednia);
    }
    else{
        printf("Nie ma takiej kolumny!\n");
    }

    for(int i=0;i<b;i++){
        float o=tab[0][i];
        tab[0][i]=tab[a-1][i];
        tab[a-1][i]=o;
    }
        printf("\nTabela po zmianie liczb z brzegowych wierszy:\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%f",tab[i][j]);
            printf("|");
        }
        printf("\n");
        for(int j=0;j<b;j++){
            printf("---------");
        }
        printf("\n");
    }

    bool Czy0=false;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(tab[i][j]==0)
                Czy0=true;
            if(Czy0)
                break;
        }
        if(Czy0)
            break;
    }
    if(Czy0){
        printf("\nW tablicy jest liczba 0.\n");
    }
    else{
        printf("\nW tablicy nie ma liczby 0.\n");
    }

    if(b%2!=0){
        bool CzySym=true;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(tab[i][j]==0)
                    CzySym=false;
                if(not(CzySym))
                    break;
            }
            if(not(CzySym))
                break;
        }
        if(CzySym){
            printf("\nTablica jest symetryczna wzgledem kolumny %d",(b+1)/2);
        }
        else{
            printf("\nTablica nie jest symetryczna wzgledem kolumny %d",(b+1)/2);
        }
    }
    else{
        printf("Tabela nie posiada srodkowej kolumny");
    }
    printf("\n\n");
    system("pause");
    
    return 0;
}