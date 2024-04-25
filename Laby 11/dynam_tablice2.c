#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    //int *t=(int*)malloc(n*sizeof(int));
    int N;
    printf("Pobiore od ciebie tablice o dlugosci N\nPodaj N: ");
    scanf("%d",&N);
    int*tab=(int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++){
        printf("Podaj liczbe: ");
        scanf("%d",&tab[i]);
    }
    if(N>0){
        int **wystapienia=(int**)malloc(1*sizeof(int*));
        wystapienia[0]=(int*)malloc(2*sizeof(int));
        int wiersz=0;
        wystapienia[0][0]=tab[0];
        wystapienia[0][1]=1;
    
        for(int i=1;i<N;i++){
            bool CzyWystepuje=false;
            for(int j=0;j<=wiersz;j++){
                if(wystapienia[j][0]==tab[i]){
                    CzyWystepuje=true;
                    wystapienia[j][1]++;
                    break;
                }
            }
            if(CzyWystepuje==false){
                wiersz++;
                wystapienia=(int**)realloc(wystapienia, (wiersz+1)*sizeof(int*));
                wystapienia[wiersz]=(int*)malloc(2*sizeof(int));
                wystapienia[wiersz][0]=tab[i];
                wystapienia[wiersz][1]=1;
            }
        }

        for(int i=0;i<=wiersz;i++)
            printf("(%d,%d razy)\n",wystapienia[i][0],wystapienia[i][1]);
    }

    system("pause");
}