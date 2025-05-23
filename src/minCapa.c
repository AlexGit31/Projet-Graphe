#include "../include/minCapa.h"
// #include "../include/buildRG.h"
// #include "../include/shortestPath.h"
#include <stdio.h>
#define NILL (struct maillon *)0
#define INFINI 9999999

//---------------------------------Nouvelle
// version-----------------------------------------------------

int minCapa(struct liste_succ *RG, struct liste_chainee *chemin) {
  // printf("--------------Debut minCapa------------\n");
  // printf("Source : %d\n", RG->source);
  // printf("Puits : %d\n", RG->puits);

  // int i = 0;
  int min = INFINI;
  struct maillon *M = chemin->tete;
  struct maillon *current;
  M = M->suivant; // Attention : il est important de commencer par le 2e
                  // maillon, car le premier maillon est la source
  int sommet = RG->source;

  while (M->sommet != RG->puits) { // M->sommet != RG->puits
    // i++;
    // printf("min = %d\n", min);
    // printf("M->sommet = %d\n", M->sommet);

    current = RG->tab[sommet]->tete;

    // printf("current->sommet = %d\n", current->sommet);

    while (current->sommet != M->sommet) {
      current = current->suivant;
      // printf("current->sommet = %d\n", current->sommet);
    }

    // printf("current->sommet = %d\n", current->sommet);
    // Remarque : il n'y a pas besoin de regarder si l'arc est saturé car
    // le chemin assure de ne passer que par des arcs non saturés.

    // printf("current->flow = %d\n", current->flow);
    if (current->flow < min) {
      min = current->flow;
      // printf("nouveau min = %d\n", min);
      // printf("La nouvelle min est de %d\n", min);
    }

    sommet = current->sommet;
    M = M->suivant;
  }
  // printf("min = %d\n", min);
  return min;
}

//------------------------------------Ancienne version qui possède un
// poroblème------------------------------------
// int minCapa(struct liste_succ *reseau,
//             struct liste_chainee
//                 *chemin) { // ATTENTION : on travail avec le reseau et non le
//                 RG
//   // printf("--------------Debut minCapa------------\n");
//   struct maillon *M = chemin->tete;
//   // pour l'instant le premier maillon de chemin est le maillon de la source
//   // donc on peut aller directement au suivant
//   M = M->suivant;
//
//   int min = INFINI;
//   int sommet = reseau->source;
//
//   struct maillon *current = reseau->tab[sommet]->tete;
//
//   // printf("Boucle while : \n");
//   // current->sommet != RG->puits
//   while (M != NILL) { // il est plus simple de regarder si le suivant de M
//   est
//                       // null car ici on doit parcourir tout le chemin
//     // printf("-----Nouvelle etape-----\n");
//     // printf("sommet courant : %d\n", current->sommet);
//     // printf("sommet de chemin : %d\n", M->sommet);
//
//     while (current->sommet != M->sommet) {
//       // printf("J'avance\n");
//       current = current->suivant;
//     }
//     // On affiche les informations de current :
//     // printf("current->sommet : %d\n", current->sommet);
//     // printf("current->capacite : %d\n", current->capacite);
//     // printf("current->flow : %d\n", current->flow);
//
//     if (current->capacite - current->flow < min) {
//       min = current->capacite - current->flow;
//       // printf("nouvelle min : %d\n", min);
//     }
//
//     // printf("On update M et current repart de zero :\n");
//
//     if (M->sommet == reseau->puits) {
//       // printf("Valeur de M : %d\n", M->sommet);
//       M = NILL;
//     } else {
//       M = M->suivant;
//       current = reseau->tab[current->sommet]->tete;
//     }
//     // printf("M->sommet : %d\n", M->sommet);
//     // printf("current->sommet : %d\n", current->sommet);
//   }
//
//   return min;
// }

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
