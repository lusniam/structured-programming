#include <stdio.h>
#include <math.h>
int main(){
    int liczby=0,SumaD=0,SumaND=0,limit=2000000;
    printf("Bede przyjmowac od ciebie liczby dopoki nie bedzie tyle samo liczb");
    printf("dodatnich i ujemnych\nUwaga: Moge przyjac maksymalnie %d liczb\n",limit);
    do{
        int liczba;
        printf("Podaj liczbe: ");
        scanf("%d",&liczba);
        if(liczba>0){
            liczby++;
            SumaD+=liczba;
        }
        else if(liczba<0){
            liczby--;
            SumaND+=liczba;
        }
        limit--;
    }
    while(liczby!=0&&limit>0);
    printf("Suma liczb dodatnich=%d,suma liczb ujemnych=%d\n",SumaD,SumaND);
    system("pause");
}