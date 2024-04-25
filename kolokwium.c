#include <stdio.h>
#include <stdlib.h>

float *nowa_tab(int n, float tab[], int& rozmiar, float &srednia){
    for(int i=0;i<n;i++){
        srednia+=tab[i];
    }
    srednia/=n;
    for(int i=0;i<n;i++){
        if(tab[i]>srednia){
            rozmiar++;
        }
    }
    //float new_tab[rozmiar];
    float* new_tab=(float*)malloc(rozmiar*sizeof(float));
    int x=0;
    for(int i=0;i<n;i++){
        if(tab[i]>srednia){
            new_tab[x]=tab[i];
            x++;
        }
    }
    return new_tab;
}

int main(){
    int n;
    printf("Podaj n:");
    scanf("%d",&n);
    float tab[n];
    for(int i=0;i<n;i++){
        printf("Podaj liczbe: ");
        scanf("%f",&tab[i]);
    }
    if(n>0){
        int rozmiar=0;
        float srednia=0;
        float *new_tab=nowa_tab(n,tab,rozmiar,srednia);
        printf("Srednia wpisanych liczb: %f\n",srednia);
        printf("Liczby wieksze od sredniej:");
        for(int i=0;i<rozmiar;i++){
            printf("%f,",new_tab[i]);
        }
    }
    system("pause");
}