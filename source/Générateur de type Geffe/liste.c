#include<stdlib.h>
#include<stdio.h>
#include "liste.h"

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    while (actuel->suivant->suivant != NULL)
    {
        actuel = actuel->suivant;
    }
    free(actuel->suivant);
    actuel->suivant = NULL;
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel->suivant != NULL)
    {
        printf("%d ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("\n");
}

int en_tete(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    while (actuel->suivant != NULL)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}

int elem_un(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=14;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_deux(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=13;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_trois(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=12;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_quatre(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=11;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_cinq(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=10;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_sept(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=8;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}
int elem_onze(Liste*liste)
{
	int n;
	if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    for (int i=0;i<=4;i++)
    {
        n = actuel->nombre;
        actuel = actuel->suivant;
    }
    return n;
}

    // int un = elem_un(LFSR1);
    // int deux = elem_deux(LFSR1);
    // int trois = elem_trois(LFSR1);
    // int quatre = elem_quatre(LFSR1);
    // int cinq = elem_cinq(LFSR1);
    // int sept = elem_sept(LFSR1);
    // int onze = elem_onze(LFSR1);

    // printf("%d %d %d %d %d %d %d\n",un,deux,trois,quatre,cinq,sept,onze);


