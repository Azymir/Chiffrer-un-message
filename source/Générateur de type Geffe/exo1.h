
#include "liste.h"

void remplir_LFSR(Liste* maListe, char *c);
/*
Cette méthode remplit dans l'ordre de droite à gauche le mot donner en entrer.
*/
int chartoi(char c);
/*
Cette méthode renvoie l'entier du caractère donner en entrée, s'applique à ce qu'aux bits et renvoie 2 si erreur.
*/
int fonction_F(int x1, int x2, int x3, char *c);
/*
Cette méthode applique la substitution de la fonction f donner en entrée.
*/
int calcul_s(Liste *LFSR1, Liste *LFSR2, Liste *LFSR3,char *c);
/*
Cette méthode recupere les premiers éléments des listes et renvoie le résultat de la fonction f.
*/
int calcul_nv_elem(int a,int b,int c);
/*
Cette méthode renvoie le calcul des XOR des 3 entier donner en entré.
*/
void remplir_LFSR_L0(Liste* maListe);
/*
Cette méthode retire le premier element de la liste et insère le nouvel element à la fin du calcul des XOR
*/
void remplir_LFSR_L1(Liste* maListe);
/*
Cette méthode retire le premier element de la liste et insère le nouvel element à la fin du calcul des XOR
*/
void remplir_LFSR_L2(Liste* maListe);
/*
Cette méthode retire le premier element de la liste et insère le nouvel element à la fin du calcul des XOR
*/

void exo11(int n, char *c, char *k0, char *k1, char *k2);
/*
Initialisation des listes, LFSR1, 2 et 3.
On calcul la suite chiffrant de taille n, 
grace a la fonction calcul_s et 
on utilise les methodes remplir_LFSR_LX pour organiser la liste.
on
*/


float calcul_sim2(int x,char s[8], int n);
/* 
Renvoie le resultat du calcul la correlation 
*/

void exo12(char *k0, char *k1, char *k2);
/* 
Grâce au fichier generateur_binaire py on possède un fichier fonction avec les 256 possibilités de la fonction F.
On lit le fichier ligne par ligne, nous permettant de récupérer une possibilité de la fonction f, 
puis on applique la corrélation avec les clés.
*/

void exo121(char *c, char *k0, char *k1, char *k2);
/* 
Calcul la corrélation pour chacun des bits des LFSR et les affichent.
*/