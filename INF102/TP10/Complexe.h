#ifndef _COMPLEXE_H_
#define _COMPLEXE_H_

typedef struct{
    double re;
    double im;
}complexe;

double partieReel(complexe z);
double partieImag(complexe z);
void afficheComplexe(complexe *z);
double moduleComplexe(complexe *z);
complexe saisitComplexe();
complexe multiComplexe(complexe a, complexe b);
void remplitTableau(complexe *tab);

#endif
