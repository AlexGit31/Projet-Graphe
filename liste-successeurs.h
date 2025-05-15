// Structure de données de liste de successeurs : permet de représenter les
// graphes

#if !defined(LISTE_SUCC_H)
#define LISTE_SUCC_H

#include "liste-chainee.h"

struct liste_succ {
  int N;                      // nombre de sommets du réseau
  struct liste_chainee **tab; // attention c'est un tableau de pointeurs
  int source;                 // la source du réseau
  int puits;                  // le puit du réseau
};

extern void clear_liste_succ(struct liste_succ *l);

extern struct liste_succ *init_liste_succ(int N, int source, int puits);

#endif
