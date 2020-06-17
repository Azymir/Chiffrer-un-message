#include<stdlib.h>
#include<stdio.h>
#include "exo1.h"
#include <string.h>

void remplir_LFSR(Liste* maListe, char *c)
{
	insertion(maListe,chartoi(c[15]));
	insertion(maListe,chartoi(c[14]));
	insertion(maListe,chartoi(c[13]));
	insertion(maListe,chartoi(c[12]));
	insertion(maListe,chartoi(c[11]));
	insertion(maListe,chartoi(c[10]));
	insertion(maListe,chartoi(c[9]));
	insertion(maListe,chartoi(c[8]));
	insertion(maListe,chartoi(c[7]));
	insertion(maListe,chartoi(c[6]));
	insertion(maListe,chartoi(c[5]));
	insertion(maListe,chartoi(c[4]));
	insertion(maListe,chartoi(c[3]));
	insertion(maListe,chartoi(c[2]));
	insertion(maListe,chartoi(c[1]));
	insertion(maListe,chartoi(c[0]));
}

int chartoi(char c)
{
	if(c == 49) return 1;
	if(c == 48) return 0;
	else return 2;

}

int fonction_F(int x1, int x2, int x3, char *c)
{
	if(x1 == 0 && x2 == 0 && x3 == 0) return chartoi(c[0]);
	else if(x1 == 1 && x2 == 0 && x3 == 0) return chartoi(c[1]);
	else if(x1 == 0 && x2 == 1 && x3 == 0) return chartoi(c[2]);
	else if(x1 == 1 && x2 == 1 && x3 == 0) return chartoi(c[3]);
	else if(x1 == 0 && x2 == 0 && x3 == 1) return chartoi(c[4]);
	else if(x1 == 1 && x2 == 0 && x3 == 1) return chartoi(c[5]);
	else if(x1 == 0 && x2 == 1 && x3 == 1) return chartoi(c[6]);
	else if(x1 == 1 && x2 == 1 && x3 == 1) return chartoi(c[7]);
	else return 2;
}

int calcul_s(Liste *LFSR1, Liste *LFSR2, Liste *LFSR3,char *c)
{
	int x1 = en_tete(LFSR1);
    int x2 = en_tete(LFSR2);
    int x3 = en_tete(LFSR3);
    // printf("x1=%d x2=%d x3=%d\n",x1,x2,x3);
    int s = fonction_F(x1,x2,x3,c);
    // printf("s=%d\n",s);
    return s;
}

int calcul_nv_elem(int a,int b,int c)
{
	int res = a^b^c;

	return res;
}

void remplir_LFSR_L0(Liste* maListe)
{
	// printf("************LFSR1**********************************\n");
	int L01 = elem_un(maListe);
    int LO4 = elem_quatre(maListe);
    int L07 = elem_sept(maListe);
    int NL0 = calcul_nv_elem(L01,LO4,L07);
    // printf("nr0=%d\n",NL0);
    insertion(maListe,NL0);
    suppression(maListe);
	// afficherListe(maListe);
	// printf("%d\n",en_tete(LFSR1));
}

void remplir_LFSR_L1(Liste* maListe)
{
	// printf("************LFSR2**********************************\n");
    int L11 = elem_un(maListe);
    int L17 = elem_sept(maListe);
    int L111= elem_onze(maListe);
	int NL1 = calcul_nv_elem(L11,L17,L111);
    // printf("nr1=%d\n",NL1);
    insertion(maListe,NL1);
    suppression(maListe);
	// afficherListe(maListe);
	// printf("%d\n",en_tete(LFSR2));
}

void remplir_LFSR_L2(Liste* maListe)
{
	// printf("************LFSR3**********************************\n");
    int L22 = elem_deux(maListe);
    int L23 = elem_trois(maListe);
    int L25 = elem_cinq(maListe);
    int NL2 = calcul_nv_elem(L22,L23,L25);
    // printf("nr2=%d\n",NL2);
    insertion(maListe,NL2);
    suppression(maListe);
	// afficherListe(maListe);
	// printf("%d\n",en_tete(LFSR3));
}

void exo11(int n, char *c, char *k0, char *k1, char *k2)
{
	printf("\n");
	/* INIT */
	int s[100];
	Liste *LFSR1 = initialisation();
	Liste *LFSR2 = initialisation();
	Liste *LFSR3 = initialisation();
	remplir_LFSR(LFSR1,k0);
	remplir_LFSR(LFSR2,k1);
	remplir_LFSR(LFSR3,k2);
	printf("k0:");
    afficherListe(LFSR1);
    printf("k1:");
    afficherListe(LFSR2);
    printf("k2:");
    afficherListe(LFSR3);

    /* BODY */
    for (int i = 0; i < n; ++i)
    {
		s[i] = calcul_s(LFSR1,LFSR2,LFSR3,c);
		remplir_LFSR_L0(LFSR1);
		remplir_LFSR_L1(LFSR2);
		remplir_LFSR_L2(LFSR3);
    }

    /* END */
    printf("si=");
    for (int i = 0; i < n; ++i)
    {
    	printf("%d",s[i]);
    }
    printf("\n");
}

float calcul_sim2(int x,char s[8], int n)
{
	float p = 0.0;
	for (int i = 0; i < n; ++i)
	{
		// printf("c[%d]=%d\n",i,chartoi(s[i]));
		if (chartoi(s[i]) == x)
		{
			p = p + 1.0;
		}
	}
	// printf("p=%f\n",p/8);
    return p/8.0;
}

void exo12 (char *k0, char *k1, char *k2)
{
	char c[8];
	FILE* f = NULL;
	f = fopen("fonction","r"); 			// Ouvre le fichier en mode lecture
	for (int i = 0; i < 256; ++i)
	{				// Colonnes
		for (int j = 0; j < 8; ++j)
		{			// Lignes
				c[j] = fgetc(f);
				// printf("%c\n",c[j]);
		}
		exo121(c,k0,k1,k2);
		fgetc(f);					// sauter le '\n'
	}
	fclose(f); 						//Ferme le fichier

	// char *c = "11111100";
	// exo121(c,k0,k1,k2);
}

void exo121(char *c, char *k0, char *k1, char *k2)
{
	printf("\n");
	/* INIT */
	int x1,x2,x3;
	int n = 8;
	float Px1,Px2,Px3;
    Liste *LFSR1 = initialisation();
	Liste *LFSR2 = initialisation();
	Liste *LFSR3 = initialisation();
	remplir_LFSR(LFSR1,k0);
	remplir_LFSR(LFSR2,k1);
	remplir_LFSR(LFSR3,k2);
	// printf("k0:");
 //    afficherListe(LFSR1);
 //    printf("k1:");
 //    afficherListe(LFSR2);
 //    printf("k2:");
 //    afficherListe(LFSR3);

    printf("f=");
    for (int i = 0; i < n; ++i)
    {
    	printf("%d",chartoi(c[i]));
    }
    printf("\n");

    /* BODY */
    for (int i = 0; i < 16; ++i)
    {
    	x1 = en_tete(LFSR1);
		x2 = en_tete(LFSR2);
		x3 = en_tete(LFSR3);
		printf("x1=%d x2=%d x3=%d\n",x1,x2,x3);
		Px1 = calcul_sim2(x1,c,n); // Px1
		Px2 = calcul_sim2(x2,c,n); // Px1
		Px3 = calcul_sim2(x3,c,n); // Px1
		printf("Px1=%f Px2=%f Px3=%f",Px1,Px2,Px3);
    	remplir_LFSR_L0(LFSR1);
		remplir_LFSR_L1(LFSR2);
		remplir_LFSR_L2(LFSR3);
		printf("\n\n");
    }

    /* END */
    printf("\n");

}