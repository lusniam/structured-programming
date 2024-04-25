#include <stdio.h>
#include <stdlib.h>

float sumuj_kolumny(int n, int **tab,int new_tab[]){
    float srednia=0;
    for(int i=0;i<n;i++){
        int suma=0;
        for(int j=0;j<n;j++){
            suma+=tab[j][i];
        }
        new_tab[i]=suma;
        srednia+=suma;
    }
    return srednia/n;
}

int main(){
    int n;
    printf("Podaj dlugosc tablicy n x n: ");
    scanf("%d",&n);
    int **tab=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            printf("Liczba (%d,%d) = ",i,j);
            scanf("%d",&tab[i][j]);
        }
    }
    int new_tab[n];
    float srednia=sumuj_kolumny(n,tab,new_tab);
    printf("Nowa tablica to:\n%d",new_tab[0]);
    for(int i=1;i<n;i++){
        printf(",%d",new_tab[i]);
    }
    printf("\n\nSrednia otrzymanych sum jest rowna %f\n\n",srednia);

    system("pause");
}