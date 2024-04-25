#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct hotel{
    char kod[3];
    float cena;
    int status;
};

float *koszt(int n,struct hotel pokoj[]){
    float*osoba=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        osoba[i]=pokoj[i].cena/(pokoj[i].kod[1]-(int)'0');
    return osoba;
}

struct hotel * wolne(int n, struct hotel pokoj[],int &rozmiar){
    struct hotel * wolny=(struct hotel*)malloc(rozmiar*sizeof(struct hotel));
    wolny[0].status=0;
    for(int i=0;i<n;i++){
        if(pokoj[i].status==1){
            wolny[rozmiar-1]=pokoj[i];
            rozmiar++;
            wolny=(struct hotel*)realloc(wolny,rozmiar*sizeof(struct hotel));
        }
    }
    rozmiar--;
    wolny=(struct hotel*)realloc(wolny,rozmiar*sizeof(struct hotel));
    return wolny;
}

float zysk(int n,struct hotel pokoj[]){
    float zysk=0;
    for(int i=0;i<n;i++)
        if(pokoj[i].status==2)
            zysk+=pokoj[i].cena;
    return zysk;
}

bool rezerwacja(int n, struct hotel pokoj[]){
    for(int i=0;i<n;i++){
        if(pokoj[i].status==1&&strcmp("p3",pokoj[i].kod)==0)
            return true;
    }
    return false;
}

int main(){
    int n;
    printf("Podaj liczbe pokoi: ");
    scanf("%d",&n);
    struct hotel pokoj[n];
    if(n>0){
        for(int i=0;i<n;i++){
            printf("Podaj kod pokoju, cene oraz jego status:\n");
            fflush(stdin);
            scanf("%s%f%d",&pokoj[i].kod,&pokoj[i].cena,&pokoj[i].status);
        }
        
        float *osoba=koszt(n,pokoj);
        for(int i=0;i<n;i++)
            printf("Cena za 1 osobe w pokoju %d jest rowna %.2f zl\n",i+1,osoba[i]);
        
        int rozmiar=1;
        struct hotel *pokoje=wolne(n,pokoj,rozmiar);
        if(pokoje[0].status==0)
            printf("W hotelu nie ma wolnych pokoi\n");
        else{
            printf("W hotelu zostaly wolne pokoje:\n");
            for(int i=1;i<rozmiar;i++)
                printf("Rozmiar: %s\nCena: %.2f\nStatus: %d\n\n",pokoje[i].kod,pokoje[i].cena,pokoje[i].status);
        }

        printf("Zysk ze wszytkich zajetych pokoi wynosi %.2f zl\n",zysk(n,pokoj));

        if(rezerwacja(n,pokoj))
            printf("W hotelu jest wolny pokoj trzyosobowy\n");
        else
            printf("W hotelu nie ma wolnego pokoju trzyosobowego");
    }
    system("pause");
}