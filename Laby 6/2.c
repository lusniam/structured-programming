#include <stdio.h>
#include <math.h>
int main(){
    float p,X;
    printf("Oblicze po jakim czasie podwoisz swoje pieniadze wplacone na lokate\n");
    printf("Podaj oprocentowanie lokaty: ");
    scanf("%f",&p);
    printf("Podaj wplacone pieniadze: ");
    scanf("%f",&X);
    if(p<=0)
        printf("Przy niedodatnim procencie nie bedzie zysku!\n");
    else if(X<=0)
        printf("Nie wplacono pieniedzy!\n");
    else{
        int czas=0;
        float w=X;
        while(w<2*X){
            w*=(100+p/2)/100;
            czas++;
        }
        printf("Wyplacono %.2f zl po %d odnowieniach lokaty\n",w,czas);
    }
    system("pause");
}