#include "../include/shortestPath.h"
#include "../include/liste-successeurs.h"
#include <stdio.h>
#include <stdlib.h>
#define NILL (struct maillon *)0
#define NUL (struct liste_chainee *)0
// ATTENTION : cette fonction doit aussi gérer le cas ou il n'y a pas de chemin
struct liste_chainee *shortestPath(struct liste_succ *RG) {
  // printf("Debut OK.\n");
  struct liste_chainee *chemin = init_liste_chainee();
  // init_liste_chainee(chemin);
  if (!chemin) {
    // printf("ERREUR: malloc dans init_liste_chainee a échoué\n");
    exit(EXIT_FAILURE);
  }

  // printf("liste chainee OK.\n");
  int niveau[RG->N];
  for (int i = 0; i < RG->N; i++) {
    niveau[i] = -1;
  }

  // printf("niveau OK.\n");
  int pere[RG->N];
  for (int i = 0; i < RG->N; i++) {
    pere[i] = -1;
  }

  // printf("pere OK.\n");
  niveau[RG->source] = 0;
  pere[RG->source] = RG->source;

  // // Création d'une file, on utilise pour cela la structure liste_chainee
  // // c'est pourquoi il existe deux méthodes : enfiler et défiler

  struct liste_chainee *file;
  file = init_liste_chainee();
  // printf("File OK.\n");
  enfiler(file, RG->source);

  // printf("Init OK.\n");

  while (file->tete != NILL) {
    int sommet = defiler(file);
    struct maillon *current = RG->tab[sommet]->tete;
    while (current != NILL) {
      if (niveau[current->sommet] == -1) {
        niveau[current->sommet] = niveau[sommet] + 1;
        pere[current->sommet] = sommet;
        enfiler(file, current->sommet);
      }
      current = current->suivant;
    }
  }

  // Note : il doit y avoir un problème avec les index des sommets, les tableaux
  // commencent à 0 alors que les graphes ont leur premier sommet à 1

  // printf("while OK.\n");
  // Construction du chemin :

  int sommet = RG->puits;
  if (pere[sommet] == -1) {
    // Dans ce cas, il n'y a pas de chemin et on retourne NULL
    return NUL;
  }
  while (sommet != RG->source) {
    // printf("sommet : %d\n", sommet);
    ajout_tete(chemin, sommet, 0, 0);
    sommet = pere[sommet];
  }
  ajout_tete(chemin, RG->source, 0, 0);
  // printf("fin shortestPath OK.\n");
  return chemin;
}

// int main() {
//   // On va tester notre fonction sur un petit reseau :
//   printf("Bouya ?\n");
//   struct liste_succ *reseau =
//       init_liste_succ(2, 0, 1); // 2 sommets : 0 la source et 1 le puits
//   printf("init OK.\n");
//   // on ajoute des arcs
//   ajout_tete(reseau->tab[0], 2, 10, 5);
//   ajout_tete(reseau->tab[1], 1, 20, 0);
//   printf("ajout OK.\n");
//
//   imprimer_liste_chainee(reseau->tab[0]);
//   imprimer_liste_chainee(reseau->tab[1]);
//   printf("imprimer OK.\n");
//
//   struct liste_chainee *chemin = shortestPath(reseau);
//   printf("chemin OK.\n");
//
//   imprimer_liste_chainee(chemin);
//   printf("imprimer OK.\n");
//
//   return 0;
// }
