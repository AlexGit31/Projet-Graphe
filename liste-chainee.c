#include "liste-chainee.h"
#include <stdio.h>
#include <stdlib.h>

#define NILL (struct maillon *)0

void ajout_tete(struct liste_chainee *l, int sommet, int capacite, int flow) {

  struct maillon *M;
  M = (struct maillon *)malloc(sizeof(struct maillon));

  M->sommet = sommet;
  M->capacite = capacite;
  M->flow = flow;
  M->suivant = l->tete;
  l->tete = M;
  l->taille++;
}

void clear_maillon(struct liste_chainee *l, struct maillon *M) {
  struct maillon *P;
  P = l->tete;

  while (P->suivant != M) {
    P = P->suivant;
  }
  if (P && P->suivant == M) {
    P->suivant = M->suivant;
    l->taille--;
    free(M);
  }

  free(M);
}

void clear_liste_chainee(struct liste_chainee *l) {
  struct maillon *M;
  M = l->tete;
  while (M != NILL) {
    struct maillon *P = M;
    M = M->suivant;
    free(P);
  }
  l->tete = NILL; // Sécuriser
  l->taille = 0;
}

struct liste_chainee *init_liste_chainee() {
  struct liste_chainee *l;
  l = (struct liste_chainee *)malloc(
      sizeof(struct liste_chainee)); // ATTENTION à cette ligne
  l->tete = NILL;
  l->taille = 0;
  return l;
}

void imprimer_liste_chainee(struct liste_chainee *l) {
  struct maillon *current = l->tete;
  while (current != NILL) {
    printf("(Sommet: %d, Capacité: %d, Flow: %d) -> ", current->sommet,
           current->capacite, current->flow);
    current = current->suivant;
  }
  printf("NULL\n");
}

void init_maillon(struct maillon *m, int sommet, int capacite, int flow) {
  m->capacite = capacite;
  m->flow = flow;
  m->sommet = sommet;
  m->suivant = NILL;
}

int defiler(struct liste_chainee *l) {
  struct maillon *M = l->tete;
  l->tete = M->suivant;
  l->taille--;
  return M->sommet;
}

void enfiler(struct liste_chainee *l, int sommet) {
  struct maillon *M = malloc(sizeof(struct maillon));
  init_maillon(M, sommet, 0, 0);
  M->suivant = NILL;

  if (l->tete == NILL) {
    // Cas de la file vide : on insère en tête
    l->tete = M;
  } else {
    // Cas classique : on insère à la fin
    struct maillon *current = l->tete;
    while (current->suivant != NILL) {
      current = current->suivant;
    }
    current->suivant = M;
  }

  l->taille++;
}
