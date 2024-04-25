#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

float PoleProstokata(float a, float b){
	return a*b;
}

float ObwodProstokata(float a, float b){
	return 2*(a+b);
}

float PoleKola(float r){
	return M_PI*pow(r,2);
}

float ObwodKola(float r){
	return 2*M_PI*r;
}

float Srednia(float p, float u){
	return (p+u)/2;
}

float Wzory(int a, int b,char wzor){
	if(wzor=='A')
		return sqrt(2*a*a+b*b);
	if(wzor=='B')
		return (a*sin(b))/pow(27,1/3);
	if(wzor=='C')
		return sqrt(fabs(a-b))+pow(a,3);
	if(wzor=='D')
		return cos(2*b)-sqrt(pow(a,2))+1;
	if(wzor=='E')
		return (a+sin(b))/(fabs(pow(a,3))+1);
	if(wzor=='F')
		return pow(a-b*cos(a),1/3);
	if(wzor=='G')
		return a+sqrt(pow(a,2)+pow((pow(a,2)+a)/3,2));
	if(wzor=='H')
		return (2*pow(a+b,3))/3+sqrt(fabs(a))+10*b;
return 0;
}

int main(){
	printf("Witaj,\n");
	int zadanie=0;
	while(1>0)
	{
		printf("Podaj numer zadania, lub wpisz 5 aby zakonczyc program: ");
		scanf("%d", &zadanie);
		if(zadanie==1){
			float a,b;
			printf("Podaj dlugosc pierwszego boku prostokata: ");
			scanf("%f", &a);
			printf("Podaj dlugosc drugiego boku prostokata:  ");
			scanf("%f", &b);
			printf("Pole prostakata o podanych bokach jest rowne %.2f, a jego obwod %.2f",PoleProstokata(a,b),ObwodProstokata(a,b));
		}
		else if(zadanie==2){
			float r;
			printf("Podaj promien kola: ");
			scanf("%f", &r);
			printf("Pole kola o podanym promieniu jest rowne %.3f, a jego obwod %.3f",PoleKola(r),ObwodKola(r));
		}
		else if(zadanie==3){
			float p, u;
			printf("Podaj ocene z egzaminu pisemnego: ");
			scanf("%f", &p);
			printf("Podaj ocene z egzaminu ustnego: ");
			scanf("%f", &u);
			printf("Srednia arytmetyczna z podanych ocen jest rowna %.2f",Srednia(p,u));
		}
		else if(zadanie==4){
			char wzor=0;
			int a, b;
			while(1>0){
				printf("Wybierz wzor(A-H): ");
				scanf(" %c", &wzor);
				if(wzor>='A'&&wzor<='H')
					break;
				else
					printf("Podano bledny znak wzoru! Sprobuj jeszcze raz.");
					system("pause");
					system("clear");
			}
			printf("Podaj liczbe a: ");
			scanf("%d", &a);
			printf("Podaj liczbe b: ");
			scanf("%d", &b);
			printf("Z podanego wzoru x jest rowne %f",Wzory(a,b,wzor));
		}
		else if(zadanie==5)
			break;
		else
			printf("Podano zly numer zadania! Sprobuj jeszcze raz.");
		printf("\n");
		system("pause");
		system("clear");
	}
	return 0;
}
