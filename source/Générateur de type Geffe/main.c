#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"
#include "exo2.h"
#include <string.h>

int main(int argc, char *argv[]) {
	/* INIT */
	int a;
	int n;
	char *c = malloc(sizeof(char));
	char *k0 = malloc(sizeof(char));
	char *k1 = malloc(sizeof(char));
	char *k2 = malloc(sizeof(char));

	/* BODY */
	printf("\n\nPour lancer l'ecercice 1 q1 taper 1,\npour l'exercice 1 Q2 taper 2\n:");
	scanf("%d",&a);
	printf("\n\n(exemple n= 4),entrer n=");
	scanf("%d",&n);
	printf("(exemple f= 10001110),entrer f=");
	scanf("%s",c);
	printf("(exemple k0= 1111000011110000),entrer k0=");
	scanf("%s",k0);
	printf("(exemple k1= 1100110011001100),entrer k1=");
	scanf("%s",k1);
	printf("(exemple k2= 1010101010101010),entrer k2=");
	scanf("%s",k2);
	if(strlen(c) == 8 && strlen(k0) == 16 && strlen(k1) == 16 && strlen(k2) == 16)
	{
		exo11(n,c,k0,k1,k2);
	}
	else printf("error, taille des données incorrectes\n");

	/* END */
	return 0;
}