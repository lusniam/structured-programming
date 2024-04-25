#include <stdio.h>
#include <stdlib.h>

int **new_tab(int n, int **tab){
    int** n_tab=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        n_tab[i]=(int*)malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            int k;
            if(j==0||j==n-1){
                k=n-1-j;
            }
            else
                k=j;
            n_tab[i][j]=tab[i][k];
        }
    }
    return n_tab;
}

int main()
{
    int n;
    printf("Tablica n x n\nPodaj n: ");
    scanf("%d",&n);
    int** tab=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i]=(int*)malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            printf("Podaj liczbe: ");
            scanf("%d",&tab[i][j]);
        }
    }

    printf("\nTablica przed zmianami:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d, ",tab[i][j]);
        }
        printf("\n");
    }

    int** n_tab=new_tab(n,tab);

    printf("\nTablica po zmianach:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d, ",n_tab[i][j]);
        }
        printf("\n");
    }
}
