#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hurt{
    char nazwa[30];
    float ilosc;
    float cena;
};

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
        float max_cena=towar[0].cena;
        int max_cena_i=0;
        float srednia=0;
        char szukana[30];
        float szukana_ilosc;
        printf("Podaj nazwe szukanego towaru: ");
        fflush(stdin);
        scanf("%s",&szukana);
        for(int i=0;i<n;i++){
            if(towar[i].cena>max_cena)
                max_cena=towar[i].cena;
                max_cena_i=i;
            srednia+=(towar[i].cena*towar[i].cena);
            if(strcmp(szukana,towar[i].nazwa)==0)
                szukana_ilosc=towar[i].ilosc;
        }
        srednia/=n;
        printf("Dane towaru, ktory ma najwieksza cene:\nNazwa: %s\nIlosc: %.2f\nCena: %.2f\n",towar[max_cena_i].nazwa,towar[max_cena_i].ilosc,towar[max_cena_i].cena);
        printf("Srednia wartosci wszytkich towarow jest rowna %.2f\nIlosc towaru o nazwie '%s' to %.2f\n",srednia,szukana,szukana_ilosc);
    }
    system("pause");
}