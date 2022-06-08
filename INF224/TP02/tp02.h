#ifndef TP02_H_
#define TP02_H_

typedef struct personneInfo {
    char *prenom;
    char *nom;
    char *info;
    char *ville;
    long int numeroFixe;
    long int numeroMobile;
    int codeVille;
    struct personneInfo *next;
    struct personneInfo *prev;
} Personne;

int personCounter(int mode);
void afficherEle(Personne *person);
Personne *initEle(char *prenom, char *nom, char *info, char *ville, long int numeroFixe, long int numeroMobile, int codeVille);
void delList(Personne **list, int mode);

void ajouterLU(Personne **list, Personne *new);
Personne **trouverPersonnesLU(Personne *list, char *search);
void supprimerEleLU(Personne **list, char *prenom);

void ajouterCU(Personne **list, Personne *new);
Personne **trouverPersonnesCU(Personne *list, char *search);
void supprimerEleCU(Personne **list, char *prenom);

void ajouterLB(Personne **list, Personne *new);
Personne **trouverPersonnesLB(Personne *list, char *search);
void supprimerEleLB(Personne **list, char *prenom);

void ajouterCB(Personne **list, Personne *new);
Personne **trouverPersonnesCB(Personne *list, char *search);
void supprimerEleCB(Personne **list, char *prenom);

#endif