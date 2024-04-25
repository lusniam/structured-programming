#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    printf("Podaj dlugosc kwadratowej tabeli: ");
    scanf("%d",&n);
    float**tab=(float**)malloc(n*sizeof(float*));
    for (int i=0;i<n;i++){
        tab[i]=(float*)malloc(n*sizeof(float));
        for (int j=0;j<n;j++){
            printf("Podaj liczbe w miejscu (%d,%d): ",i,j);
            scanf("%f",&tab[i][j]);
        }
    }

    printf("\nTabela przed zmianami:\n");
    for (int i=0;i<n;i++){
        printf("%f",tab[i][0]);
        for (int j=1;j<n;j++){
            printf(", %f",tab[i][j]);
        }
        printf("\n");
    }

    for(int i=0;2*i<n;i++){
        for(int j=0;2*j<n;j++){
            if(j>=i){
                float tym=tab[n-1-i][j];
                tab[n-1-i][j]=tab[i][j];
                tab[i][j]=tym;
                if(j!=n-1-j){
                    tym=tab[n-1-i][n-1-j];
                    tab[n-1-i][n-1-j]=tab[i][n-1-j];
                    tab[i][n-1-j]=tym;
                }
            }
        }
    }

    printf("\nTabela po zmianach:\n");
    for (int i=0;i<n;i++){
        printf("%f",tab[i][0]);
        for (int j=1;j<n;j++){
            printf(", %f",tab[i][j]);
        }
        printf("\n");
    }
    system("pause");
}