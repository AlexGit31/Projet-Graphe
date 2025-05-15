#include "minCapa.h"
#include "buildRG.h"
#include "shortestPath.h"
#include <stdio.h>
#define NILL (struct maillon *)0
#define INFINI 1000000

int minCapa(struct liste_succ *reseau,
            struct liste_chainee
                *chemin) { // ATTENTION : on travail avec le reseau et non le RG
  printf("--------------Debut minCapa------------\n");
  struct maillon *M = chemin->tete;
  // pour l'instant le premier maillon de chemin est le maillon de la source
  // donc on peut aller directement au suivant
  M = M->suivant;

  int min = INFINI;
  int sommet = reseau->source;

  struct maillon *current = reseau->tab[sommet]->tete;

  printf("Boucle while : \n");
  // current->sommet != RG->puits
  while (M != NILL) { // il est plus simple de regarder si le suivant de M est
                      // null car ici on doit parcourir tout le chemin
    printf("-----Nouvelle etape-----\n");
    printf("sommet courant : %d\n", current->sommet);
    printf("sommet de chemin : %d\n", M->sommet);

    while (current->sommet != M->sommet) {
      printf("J'avance\n");
      current = current->suivant;
    }
    // On affiche les informations de current :
    printf("current->sommet : %d\n", current->sommet);
    printf("current->capacite : %d\n", current->capacite);
    printf("current->flow : %d\n", current->flow);

    if (current->capacite - current->flow < min) {
      min = current->capacite - current->flow;
      printf("nouvelle min : %d\n", min);
    }

    printf("On update M et current repart de zero :\n");

    if (M->sommet == reseau->puits) {
      printf("Valeur de M : %d\n", M->sommet);
      M = NILL;
    } else {
      M = M->suivant;
      current = reseau->tab[current->sommet]->tete;
    }
    // printf("M->sommet : %d\n", M->sommet);
    // printf("current->sommet : %d\n", current->sommet);
  }

  return min;
}

// int main() {
//
//   // On commence par initialiser un graphe simple :
//   struct liste_succ *reseau;
//
//   reseau = init_liste_succ(5, 0, 4);
//   ajout_tete(reseau->tab[0], 1, 5, 1);
//   ajout_tete(reseau->tab[0], 2, 20, 0);
//   ajout_tete(reseau->tab[1], 2, 5, 2);
//   ajout_tete(reseau->tab[1], 3, 5, 0);
//   ajout_tete(reseau->tab[2], 3, 5, 0);
//   ajout_tete(reseau->tab[2], 4, 5, 0);
//   ajout_tete(reseau->tab[3], 4, 5, 0);
//
//   imprimer_liste_chainee(reseau->tab[0]);
//   imprimer_liste_chainee(reseau->tab[1]);
//   imprimer_liste_chainee(reseau->tab[2]);
//   imprimer_liste_chainee(reseau->tab[3]);
//   imprimer_liste_chainee(reseau->tab[4]);
//
//   struct liste_succ *RG = buildRG(reseau);
//
//   printf("RG construit\n");
//
//   imprimer_liste_chainee(RG->tab[0]);
//   imprimer_liste_chainee(RG->tab[1]);
//   imprimer_liste_chainee(RG->tab[2]);
//   imprimer_liste_chainee(RG->tab[3]);
//   imprimer_liste_chainee(RG->tab[4]);
//
//   struct liste_chainee *chemin = shortestPath(RG);
//   printf("Le chemin de capacité minimale est : ");
//   imprimer_liste_chainee(chemin);
//
//   printf("La capacité minimale du chemin est : %d", minCapa(reseau, chemin));
//
//   return 0;
// }
