#include <stdio.h>
#include <stdlib.h>

int tablica(int X, int Y,float tab[],int indeksy[]){
    float max=tab[0][0];
    int wystapienia=1;
    int wiersz=1;
    indeksy[0][0]=0;
    indeksy[0][1]=0;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(i==0&&j==0)
                continue;
            if(tab[i][j]>max){
                max=tab[i][j];
                wystapienia=1;
                wiersz=1;
                indeksy=(int**)realloc(indeksy,wiersz*sizeof(int*));
                indeksy[wiersz-1][0]=i;
                indeksy[wiersz-1][1]=j;
            }
            else if(tab[i][j]==max){
                wystapienia++;
                wiersz++;
                indeksy=(int**)realloc(indeksy,wiersz*sizeof(int*));
                indeksy[wiersz-1]=(int*)malloc(2*sizeof(int));
                indeksy[wiersz-1][0]=i;
                indeksy[wiersz-1][1]=j;
            }
        }
    }
    return wystapienia;
}

int main(){
    int X,Y;
    printf("Pobiore od ciebie tablice o wymiarach X x Y\nPodaj X: ");
    scanf("%d",&X);
    printf("Podaj Y: ");
    scanf("%d",&Y);
    float **tab=(float**)malloc(X*sizeof(float*));
    for(int i=0;i<X;i++){
        tab[i]=(float*)malloc(Y*sizeof(float));
    }
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            printf("Podaj liczbe w polu %d x %d: ",i,j);
            scanf("%f",&tab[i][j]);
        }
    }
    int **indeksy=(int**)malloc(wiersz*sizeof(int*));
    indeksy[wiersz-1]=(int*)malloc(2*sizeof(int));
    int wystapienia=tablica(X,Y,*tab,*indeksy);
    printf("Wartosc max: %f, wystapienia: %d\nIndeksy wartosci maksymalnych:\n",max,wystapienia);
    for(int i=0;i<wiersz;i++){
        printf("(%d,%d)\n",indeksy[i][0],indeksy[i][1]);
    }

    system("pause");
}