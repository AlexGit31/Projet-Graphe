/*
 *  buildGraph.c
 *
 *  Created by Bernard Carré
 *
 *  Squelette de code C de la fonction buildGraph.
 *  Ce code ne fait que lire les données d'un fichier au format DIMACS et les
 * reafficher. Inscruster les lignes de code necessaires pour construire votre
 * SD a partir des donnees ainsi obtenues.
 *
 *  Avec un main de test : fournir un fichier DIMACS en parametre.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buildRG.h"
#include "liste-successeurs.h"
#include "minCapa.h"
#include "shortestPath.h"

#define MAX_LINE_SIZE 256

struct liste_succ *buildGraph(char *file_name) {

  char ligne[MAX_LINE_SIZE]; // pour le passage de ligne
  int n_nodes;               // nombre de sommets
  int m_arcs;                // nombre d'arcs
  int source;                // numero de la source
  int puits;                 // numero du puits

  // Ouverture du fichier si possible sinon exit on error
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    fprintf(stderr, "%s non accessible\n", file_name);
    exit(1);
  }

  // Lecture du fichier
  // c Pb de ﬂot max : ligne de commentaire, on passe ...
  fgets(ligne, MAX_LINE_SIZE, fp);

  // c pb lines (nodes, links) : ligne de commentaire, on passe ...
  fgets(ligne, MAX_LINE_SIZE, fp);

  // p NODES ARCS
  getc(fp);
  getc(fp); // on passe l'entete 'p '
  // nombre de sommets
  fscanf(fp, "%d", &n_nodes);
  printf("%d nodes\n", n_nodes);

  // nombre d'arcs
  fscanf(fp, "%d", &m_arcs);
  printf("%d arcs\n", m_arcs);
  // terminer le traitement de cette ligne :
  fgets(ligne, MAX_LINE_SIZE, fp);

  // c source : ligne de commentaire, on passe ...
  fgets(ligne, MAX_LINE_SIZE, fp);
  // n ID s : determine la source
  getc(fp);
  getc(fp); // on passe l'entete 'n '
  fscanf(fp, "%d", &source);
  printf("source=%d\n", source);
  // terminer le traitement de cette ligne :
  fgets(ligne, MAX_LINE_SIZE, fp);

  // c sink : ligne de commentaire, on passe ...
  fgets(ligne, MAX_LINE_SIZE, fp);
  // n ID t : determine le puits
  getc(fp);
  getc(fp); // n
  fscanf(fp, "%d", &puits);
  printf("puits=%d\n", puits);
  // terminer le traitement de cette ligne :
  fgets(ligne, MAX_LINE_SIZE, fp);

  // c arc (from, to, capa) : ligne de commentaire, on passe ...
  fgets(ligne, MAX_LINE_SIZE, fp);

  // lire les m_arcs lignes au format "a SRC DST CAP" de DIMACS pour obtenir les
  // donnees d'arcs

  // Initialisation de la liste de successeurs avec n_nodes sommets
  struct liste_succ *reseau = init_liste_succ(
      n_nodes, source - 1,
      puits - 1); // Attention il faut faire attention à mettre -1

  {
    int a;             // pour iterer sur les arcs
    int src, dst, cap; // donnees correspondantes (SRC DST CAP)

    for (a = 1; a <= m_arcs; a++) {
      getc(fp);
      getc(fp); // on passe l'entete 'a '
      fscanf(fp, "%d", &src);
      fscanf(fp, "%d", &dst);
      fscanf(fp, "%d", &cap);
      printf("arc %d de %d a %d, capa=%d\n", a, src, dst, cap);

      // on ajoute les sommets un à un
      // ATTENTION : notre tableau commence à l'indice 0, donc on fait un -1.
      // Pareil on ajoute -1 à dst.
      ajout_tete(reseau->tab[src - 1], dst - 1, cap, 0);
      // imprimer_liste_chainee(graph->tab[src - 1]);
    }
  }

  fclose(fp);

  // Affichage du graphe
  printf("---------<<>>\n");
  imprimer_liste_chainee(reseau->tab[0]);
  imprimer_liste_chainee(reseau->tab[1]);
  imprimer_liste_chainee(reseau->tab[2]);
  imprimer_liste_chainee(reseau->tab[3]);
  imprimer_liste_chainee(reseau->tab[4]);
  imprimer_liste_chainee(reseau->tab[5]);
  printf("---------<<>>\n");

  return reseau; // On retourne notre graphe
}

void imprimer_reseau(struct liste_succ *reseau) {
  int i;
  for (i = 0; i < reseau->N; i++) {
    imprimer_liste_chainee(reseau->tab[i]);
  }
}
// Main de test
// Usage : fournir un fichier DIMACS en parametre
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: fournir un fichier DIMACS en parametre\n");
    exit(1);
  }
  struct liste_succ *reseau = buildGraph(argv[1]);

  reseau->tab[0]->tete->flow = 10; // ici on sature l'arc 0->2
  reseau->tab[0]->tete->suivant->flow =
      2; // ici on donne 2 de flow sur 5 de capacité sur  l'arc 0->1

  printf("Nouveau reseau avec des flots : \n");

  imprimer_reseau(reseau);

  printf("---------\n");
  struct liste_succ *RG;
  RG = buildRG(reseau);

  printf("-------------------------\n");
  imprimer_liste_chainee(RG->tab[0]);
  imprimer_liste_chainee(RG->tab[1]);
  imprimer_liste_chainee(RG->tab[2]);
  imprimer_liste_chainee(RG->tab[3]);
  imprimer_liste_chainee(RG->tab[4]);
  imprimer_liste_chainee(RG->tab[5]);

  printf("-------------------------\n");
  struct liste_chainee *chemin = shortestPath(RG);
  imprimer_liste_chainee(chemin);

  printf("-------------------------\n");

  printf("minCapa=%d\n", minCapa(reseau, chemin));

  printf("finnnnn\n");
  clear_liste_succ(reseau);
  clear_liste_succ(RG);

  return (0);
}
