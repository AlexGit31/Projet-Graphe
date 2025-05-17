// Maintenant sachant le chemin le plus court en nombre d'arcs de la source au
// puits, la capacité minimale m et le graphe d'écrat RG, on veut mettre le
// graphe à jour.
#include "../include/liste-successeurs.h"
#include <stdio.h>
#include <stdlib.h>
#define NILL (struct maillon *)0
void updateFlowInRG(struct liste_succ *RG, struct liste_chainee *chemin,
                    int k) {

  // printf("Debut updateFlowInRG\n");
  struct maillon *Q = chemin->tete;
  struct maillon *P;
  int sommet = Q->sommet;
  // printf("init OK.\n");
  while (Q->suivant != NILL) {
    // printf("WHILE|------>Q->sommet : %d\n", Q->sommet);
    Q = Q->suivant;
    P = RG->tab[sommet]->tete;
    while (P->sommet != Q->sommet) {
      P = P->suivant;
    }
    // printf("P->sommet : %d\n", P->sommet);
    // printf("P->capacite %d, P->flow %d\n", P->capacite, P->flow);
    // TRAITEMENT DU FLOW :
    if (P->capacite == P->flow) {
      // printf("P->capacite %d, P->flow %d\n", P->capacite, P->flow);
      P->flow -= k;
      ajout_tete(RG->tab[P->sommet], sommet, P->capacite,
                 k); // Ajout de l'arc retour
    } else {
      if (P->capacite - P->flow > 0) {
        // printf("P->capacite - P->flow = %d\n", P->capacite - P->flow);
        P->flow -= k;
        // printf("P->flow = %d\n", P->flow);
        struct maillon *K = RG->tab[P->sommet]->tete;
        while (K->sommet != sommet) {
          K = K->suivant;
        }
        K->flow += k;
        // printf("FIN IF\n");
      }
    }

    // On regarde s'il faut retirer l'arc
    if (P->flow == 0) {
      // printf("On retire un arc\n");
      clear_maillon(RG->tab[sommet], P);
      // printf("L'arc a ete retire\n");
    }
    sommet = Q->sommet;
  }
}
