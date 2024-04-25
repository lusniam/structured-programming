#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct uczelnia{
    char miasto[20];
    char typ[20]; //typ uczelni:uniwersytet, akademia, politechnika
    int L_s; // liczba studentów
    int L_w; //liczba wydziałów
};

int Ile_s(int n,struct uczelnia dane[]){
    int l_studentow=0;
    for(int i=0;i<n;i++){
        l_studentow+=dane[i].L_s;
    }
    return l_studentow;
}

struct uczelnia *Ucz_wydz(int n, struct uczelnia dane[],int &rozmiar){
    struct uczelnia *wydzialy=(struct uczelnia*)malloc(rozmiar*sizeof(struct uczelnia));
    for(int i=0;i<n;i++){
        if(dane[i].L_w>3){
            rozmiar++;
            wydzialy=(struct uczelnia*)realloc(wydzialy,rozmiar*sizeof(struct uczelnia));
            wydzialy[rozmiar-1]=dane[i];
        }
    }
    return wydzialy;
}

struct uczelnia *Ucz_m(int n, struct uczelnia dane[],int &rozmiar,char szuk_miasto[]){
    struct uczelnia *miasto=(struct uczelnia*)malloc(rozmiar*sizeof(struct uczelnia));
    for(int i=0;i<n;i++){
        if(strcmp(dane[i].miasto,szuk_miasto)==0){
            rozmiar++;
            miasto=(struct uczelnia*)realloc(miasto,rozmiar*sizeof(struct uczelnia));
            miasto[rozmiar-1]=dane[i];
        }
    }
    return miasto;
}

int main(){
    int n;
    printf("Podaj ilosc uczelni: ");
    scanf("%d",&n);
    struct uczelnia dane[n];
    for(int i=0;i<n;i++){
        printf("Podaj miasto uczelni %d: ",i+1);
        scanf("%s",&dane[i].miasto);
        printf("Podaj typ uczelni %d: ",i+1);
        scanf("%s",&dane[i].typ);
        printf("Podaj liczbe studentow uczelni %d: ",i+1);
        scanf("%d",&dane[i].L_s);
        printf("Podaj liczbe wydzialow uczelni %d: ",i+1);
        scanf("%d",&dane[i].L_w);
        fflush((stdin));
    }

    printf("\nNa wszystkich uczelniach jest %d studentow\n",Ile_s(n,dane));

    int rozmiar=0;
    struct uczelnia* wydzialy=Ucz_wydz(n,dane,rozmiar);
    printf("\nUczelnie na ktorych sa wiecej niz 3 wydzialy maja nastepujace dane:\n");
    for(int i=0;i<rozmiar;i++)
        printf("miasto: %s, typ: %s, liczba studentow: %d, liczba wydzialow: %d\n",wydzialy[i].miasto,wydzialy[i].typ,wydzialy[i].L_s,wydzialy[i].L_w);
    
    char szuk_miasto[20];
    printf("\nPodaj szukane miasto: ");
    scanf("%s",&szuk_miasto);
    rozmiar=0;
    struct uczelnia* miasto=Ucz_m(n,dane,rozmiar,szuk_miasto);
    printf("Uczelnie w miescie '%s' maja nastepujace dane:\n",szuk_miasto);
    for(int i=0;i<rozmiar;i++)
        printf("miasto: %s, typ: %s, liczba studentow: %d, liczba wydzialow: %d\n",miasto[i].miasto,miasto[i].typ,miasto[i].L_s,miasto[i].L_w);

    system("pause");
}