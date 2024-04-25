#include <iostream>
#include <stdlib.h>
#include <string.h>


int funkcja(int n, int tab[], int *T)
{
	int i; 
	float srednia,suma=0;
	for(i=0;i<n;i++)
	{
		suma+=tab[i];
	}
	srednia=suma/n;
	int j=0;
	for(i=0;i<n;i++)
	{
		if(tab[i]>srednia)
		{
			T[j]=tab[i];
			j+=1;
			T=(int*)realloc(T,(j+1)*sizeof(int));
		}
	}
	return j;
}

int main() {
	int n,i;
	printf("Podaj liczbe: ");
	scanf("%i",&n);
	int tab[n];
	for(i=0; i<n;i++)
	{
		printf("Podaj liczbe: ");
		scanf("%i",&tab[i]);
	}
	int rozmiar=0;
	int*T=(int*)malloc(sizeof(int));
	printf("Liczby wieksze od średniej: \n");
	int z=funkcja(n,tab,T);
	for(i=0; i<z; i++)
	{
		printf("- %d \n", T[i]);
	}
    system("pause");
	return 0;
}