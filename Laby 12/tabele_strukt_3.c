#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hurt{
    char nazwa[30];
    float ilosc;
    float cena;
};

int max_cena(int n, struct hurt towar[]){
    float cena=towar[0].cena;
    int max_i=0;   
    for(int i=0;i<n;i++){
        if(towar[i].cena>cena){
            cena=towar[i].cena;
            max_i=i;
        }
    }
    return max_i;
}

float srednia_wartosci(int n,struct hurt towar[]){
    float srednia=0;
    for(int i=0;i<n;i++){
        srednia+=(towar[i].ilosc*towar[i].cena);
    }
    return srednia/n;
}

float znajdz_ilosc(int n,struct hurt towar[],char szukana[]){
    for(int i=0;i<n;i++){
        if(strcmp(szukana,towar[i].nazwa)==0)
            return towar[i].ilosc;
    }
    return 0;
}

int main(){
    int n;
    printf("Podaj ilosc towarow: ");
    scanf("%d",&n);
    struct hurt towar[n];
    if(n>0){
        for(int i=0;i<n;i++){
            printf("Podaj nazwe towaru, jego ilosc oraz cene:\n");
            scanf("%s%f%f",&towar[i].nazwa,&towar[i].ilosc,&towar[i].cena);
            fflush(stdin);
        }
        int max_i=max_cena(n,towar);
        char szukana[30];
        fflush(stdin);
        printf("Podaj nazwe szukanego towaru: ");
        scanf("%s",&szukana);
        printf("Dane towaru, ktory ma najwieksza cene:\nNazwa: %s\nIlosc: %.2f\nCena: %.2f\n",towar[max_i].nazwa,towar[max_i].ilosc,towar[max_i].cena);
        printf("Srednia wartosci wszytkich towarow jest rowna %.2f\n",srednia_wartosci(n,towar));
        printf("Ilosc towaru o nazwie '%s' to %.2f\n",szukana,znajdz_ilosc(n,towar,szukana));
    }
    system("pause");
}