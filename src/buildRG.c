#include "../include/buildRG.h"
#include "../include/liste-successeurs.h"
#include <stdio.h>
#include <stdlib.h>

#define NILL (struct maillon *)0 // pas besoin de le redefinir

struct liste_succ *buildRG(struct liste_succ *reseau) {
  int n;
  n = reseau->N;
  struct maillon *Q;
  struct liste_succ *RG;
  RG = init_liste_succ(n, reseau->source, reseau->puits);

  for (int i = 0; i < n; i++) {
    // printf("i : %d\n", i);
    Q = reseau->tab[i]->tete;
    while (Q != NILL) {
      // printf("Q->sommet : %d\n", Q->sommet);
      // struct maillon *m;
      // m = (struct maillon *)malloc(sizeof(struct maillon));
      if (Q->capacite - Q->flow > 0) {
        struct maillon *m1 = malloc(sizeof(struct maillon));
        // init_maillon(m, Q->sommet, Q->capacite - Q->flow, Q->flow);
        // printf("Q->capacite - Q->flow : %d\n", Q->capacite - Q->flow);
        m1->sommet = Q->sommet;
        m1->capacite = Q->capacite;
        m1->flow = Q->capacite - Q->flow;

        m1->suivant = RG->tab[i]->tete; // on met le maillon suivant
        RG->tab[i]->tete = m1;
      }
      if (Q->flow > 0) {
        // On affiche les infos de Q
        struct maillon *m2 = malloc(sizeof(struct maillon));
        // printf("i : %d\n", i);
        // printf("Q->sommet: %d, Q->capacite: %d, Q->flow: %d\n", Q->sommet,
        //        Q->capacite, Q->flow);

        m2->sommet = i;
        m2->flow = Q->flow;
        m2->capacite = Q->capacite;

        // Le problème vient certainement d'ici !
        m2->suivant = RG->tab[Q->sommet]->tete;

        RG->tab[Q->sommet]->tete = m2;
      }
      Q = Q->suivant;
    }
    // imprimer_liste_chainee(RG->tab[i]);
  }
  return RG;
}

// Fonction main temporaire
// int main() {
//   // Crée un petit graphe de test
//   struct liste_succ *reseau = init_liste_succ(3, 0, 1);
//   ajout_tete(reseau->tab[0], 2, 10, 5);
//   ajout_tete(reseau->tab[0], 1, 10, 0);
//   ajout_tete(reseau->tab[1], 2, 20, 10);
//
//   // Appelle buildRG
//   struct liste_succ *RG = buildRG(reseau);
//   //
//   // // Affiche le graphe de sortie
//   imprimer_liste_chainee(RG->tab[0]);
//   imprimer_liste_chainee(RG->tab[1]);
//   imprimer_liste_chainee(RG->tab[2]);
//
//   printf("Test terminé.\n");
//   clear_liste_succ(reseau);
//   printf("...");
//   return 0;
// }
