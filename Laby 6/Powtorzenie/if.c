#include <stdio.h>
#include <math.h>

int main(){
    int liczba,max,rowne=0;
    
    printf("Podaj pierwsza liczbe: ");
    scanf("%d",&liczba);
    max=liczba;
    
    printf("Podaj druga liczbe: ");
    scanf("%d",&liczba);
    if(liczba==max)
        rowne++;
    else if(liczba>max)
        max=liczba;
    
    printf("Podaj trzecia liczbe: ");
    scanf("%d",&liczba);
    if(liczba==max)
        rowne++;
    else if(liczba>max){
        max=liczba;
        rowne=0;
    }

    if(rowne==0)
        printf("Najwieksza liczba jest rowna %d\n",max);
    else if(rowne==1)
        printf("Dwie liczby maja najwieksza wartosc rowna %d\n",max);
    else
        printf("Trzy liczby sa rowne, maja wartosc %d\n",max);

    system("pause");
}