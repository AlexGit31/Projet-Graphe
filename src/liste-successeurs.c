#include "../include/liste-successeurs.h"
#include <stdlib.h>
#define NILL (struct maillon *)0

void clear_liste_succ(struct liste_succ *l) {
  for (int i = 0; i < l->N; i++) {
    if (l->tab[i]->tete != NILL) {
      clear_liste_chainee(l->tab[i]);
      free(l->tab[i]);
    }
  }
  free(l->tab);
  free(l);
}

struct liste_succ *init_liste_succ(int N, int source, int puits) {
  struct liste_succ *l = (struct liste_succ *)malloc(sizeof(struct liste_succ));
  l->tab = (struct liste_chainee **)malloc(N * sizeof(struct liste_chainee *));

  l->N = N;
  l->source = source;
  l->puits = puits;
  for (int i = 0; i < N; i++) {
    l->tab[i] = (struct liste_chainee *)malloc(sizeof(struct liste_chainee));
    l->tab[i]->taille = 0;
    l->tab[i]->tete = NILL;
  }

  return l;
}
