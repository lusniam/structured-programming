#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
void Zad1(){
    char imie[30],nazwisko[30];
    
    printf("Wpisz swoje imie: ");
    gets(imie);
    printf("Wpisz swoje nazwisko: ");
    gets(nazwisko);
    
    printf("Twoje inicjaly: %c%c\n\n",toupper(imie[0]),toupper(nazwisko[0]));
}
 
void Zad2(){
    char znak[255];
    printf("Wpisz ciag znakow: ");
    gets(znak);
    
    int liczby=0,litery=0;
    for(int i=0;i<strlen(znak);i++){
        if(isdigit(znak[i]))
            liczby++;
        else if(isalpha(znak[i]))
            litery++;
    }
    
    printf("W podanym ciagu jest %d liter oraz %d liczb\n\n",litery,liczby);
}
 
void Zad3(){
    int n;
    printf("Podaj liczbe n wierszy do wpisania: ");
    scanf("%d",&n);
    
    char tab[n][20];
    gets(tab[0]);
    for(int i=0;i<n;i++){
        printf("Podaj liczbe: ");
        gets(tab[i]);
    }
    
    printf("\nWczytana tablica:\n");
    for(int i=0;i<n;i++)
        printf("%s\n",tab[i]);
    
    int tabint[n];
    for(int i=0;i<n;i++)
        tabint[i]=atoi(tab[i]);
    
    printf("\nWczytana tablica jako int:\n");
    for(int i=0;i<n;i++)
        printf("%d\n",tabint[i]);
    
    int suma=0;
    for(int i=0;i<n;i++)
        suma+=tabint[i];
    
    printf("\nSuma wczytanych liczb to %d\n\n",suma);
}
 
void Zad4(){
    int n;
    printf("Podaj liczbe n wierszy do wpisania: ");
    scanf("%d",&n);
    
    char tab[n][100];
    gets(tab[0]);
    for(int i=0;i<n;i++){
        printf("Podaj dane w postaci: 'nr_grupy nazwisko imie'");
        gets(tab[i]);
    }
    
    printf("\nWczytana tablica:\n");
    for(int i=0;i<n;i++)
        printf("%s\n",tab[i]);
    
    int gr1=0,gr2=0;
    for(int i=0;i<n;i++){
        if(tab[i][0]=='1'){
            gr1++;
        }
        else if(tab[i][0]=='2'){
            gr2++;
        }
        else{
            printf("\nPodano zly numer grupy!");
            return;
        }
    }
    
    char tab1[gr1][100],tab2[gr2][100];
    gr1=0;
    gr2=0;
    
    for(int i=0;i<n;i++){
        if(tab[i][0]=='1'){
            for(int j=0;j<strlen(tab[i]);j++)
                tab1[gr1][j]=tab[i][j+2];
            gr1++;
        }
        else{
            for(int j=0;j<strlen(tab[i]);j++)
                tab2[gr2][j]=tab[i][j+2];
            gr2++;
        }
    }
    
    printf("\nTablica grupy 1:\n");
    for(int i=0;i<gr1;i++)
        printf("%s\n",tab1[i]);
    printf("\nTablica grupy 2:\n");
    for(int i=0;i<gr2;i++)
        printf("%s\n",tab2[i]);
}
 
int main(){
    printf("Wybierz zadanie (1-4): ");
    int wybor;
    scanf("%d",&wybor);
    if(wybor==1)
        Zad1();
    else if(wybor==2)
        Zad2();
    else if(wybor==3)
        Zad3();
    else if(wybor==4)
        Zad4();
    return 0;
}