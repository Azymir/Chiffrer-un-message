
typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
int en_tete(Liste*liste);

int elem_un(Liste*liste);
int elem_deux(Liste*liste);
int elem_trois(Liste*liste);
int elem_quatre(Liste*liste);
int elem_cinq(Liste*liste);
int elem_sept(Liste*liste);
int elem_onze(Liste*liste);