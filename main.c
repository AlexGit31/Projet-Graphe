#include "./include/buildGraph.h"
#include "./include/buildRG.h"
#include "./include/liste-chainee.h"
#include "./include/liste-successeurs.h"
#include "./include/minCapa.h"
#include "./include/shortestPath.h"
#include "./include/updateFlowInNet.h"
#include "./include/updateFlowInRG.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUL (struct liste_chainee *)0

void imprimer_reseau(struct liste_succ *reseau) {
  int i;
  for (i = 0; i < reseau->N; i++) {
    printf("Sommet n° %d ", i);
    imprimer_liste_chainee(reseau->tab[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <fichier.dimacs> [affichage_etapes]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Par défaut, affichage désactivé
  int verbose = 0;
  int flow = 0;
  int m; // capacité du chemin augmentant

  // Si un 2e argument est fourni, on vérifie sa valeur
  if (argc >= 3) {
    if (strcmp(argv[2], "true") == 0 || strcmp(argv[2], "1") == 0) {
      verbose = 1;
    }
  }

  // Lecture du fichier passé en paramètre et construction du réseau
  struct liste_succ *reseau = buildGraph(argv[1]);
  struct liste_succ *RG = buildRG(reseau);

  // Utilisation du mode verbeux
  if (verbose) {
    printf("Affichage des étapes activé\n");
    printf("------------Graphe initial----------\n");
    imprimer_reseau(reseau);
    printf("-------Graphe résiduel associé-------\n");
    imprimer_reseau(RG);
  }

  // On cherhce le premier chemin augmentant
  struct liste_chainee *chemin = shortestPath(RG);

  // Tant qu'il existe un chemin augmentant on continue l'algorithme
  int i = 0;
  while (chemin != NUL) {
    if (verbose) {
      printf("---------- Etape de l'algorithme n° %d ----------\n", i);
    }

    // On cherche la capacité minimale du chemin augmentant

    m = minCapa(RG,
                chemin); // ATTENTION : on travail avec le RG et non le réseau

    flow += m; // on garde en mêmoire le flow total

    // On met à jour le flow dans le graphe residuel
    updateFlowInRG(RG, chemin, m);

    // On cherche un nouveau chemin augmentant
    chemin = shortestPath(RG);

    if (verbose) {
      printf("Le chemin de capacité minimale est : ");
      imprimer_liste_chainee(chemin);
      printf("La capacité minimale du chemin est : %d\n", m);
      printf("Le graph residuel est : \n");
      imprimer_reseau(RG);
    }
  }

  // On met à jour le flow dans le graphe initial
  updateFlowInNet(reseau, RG);

  if (verbose) {
    printf("------------Réseau Final-----------\n");
    imprimer_reseau(reseau);
  }
  printf("Flow total : %d\n", flow);

  return 0;
}
