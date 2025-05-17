#include "../include/updateFlowInNet.h"
#include "../include/liste-successeurs.h"
#include <stdio.h>
#define NILL (struct maillon *)0

void updateFlowInNet(struct liste_succ *reseau, struct liste_succ *RG) {
  // printf("Debut updateFlowInNet\n");
  int n = reseau->N;
  struct maillon *Q;
  struct maillon *K;
  struct maillon *m;

  for (int i = 0; i < n; i++) {
    // printf(" Sommet i : %d\n", i);
    Q = RG->tab[i]->tete;
    // if (Q == NILL) {
    //   printf("Q est null\n");
    // }
    // On parcourt les sommets de RG
    int ref;
    while (Q != NILL) {
      // printf("--> Q->sommet : %d\n", Q->sommet);
      // On parcourt les successeurs du sommet i mais dans le réseau pour voir
      // les arcs qui appartiennent aux deux structures :
      K = reseau->tab[i]->tete;
      ref = 0;
      while (K != NILL && ref == 0) {
        // printf("K->sommet : %d, Q->sommet : %d\n", K->sommet, Q->sommet);
        if (K->sommet == Q->sommet) {
          // printf("Il y a égalité entre K et Q : on ne fait rien\n");
          ref =
              1; // ici cela veut dire que l'arc existe dans les deux structures
        } else {
          K = K->suivant;
        }
      }

      if (Q != NILL) {
        // printf("Q n'est pas null et ref = %d\n", ref);

        if (ref == 0) {
          // printf("REF: on met le flow à jour\n");
          // On met à jour le flow dans l'arc du réseau, il correspond au poids
          // de l'arc dans le graphe d'écart

          // Pour cela on doit aller chercher l'arc correspondant dans le graphe

          m = reseau->tab[Q->sommet]
                  ->tete; // ATTENTION ICI C'EST reseau et pas RG

          // printf("m->sommet : %d\n", m->sommet);
          while (m->sommet != i) {
            m = m->suivant;
          }
          m->flow = Q->flow;
          // printf("Le flot est mit à jour.");
        }
        // printf("on repart dans un tour de boucle\n");

        Q = Q->suivant;
      } else {
        printf("Q = NILL\n");
      }
    }
  }
}
