#if !defined(LISTE_SUCC_H)
#define LISTE_SUCC_H

#include "liste-chainee.h"

//----------------- Structure de liste de successeurs ------------------//
//                                                                      //
//              Structure qui permet de représenter un Graphe,          //
//                      plus précisement un réseau.                     //
//                 On l'utilise pour représenter le réseau              //
//                          et son graphe d'écart.                      //
//                                                                      //
// N      : nombre de sommets du graphe                                 //
// tab    : tableau de liste chainée contenant les successeurs          //
//          de chaque sommet                                            //
// source : sommet source du graphe                                     //
// puits  : sommet puits du graphe                                      //
//----------------------------------------------------------------------//
struct liste_succ {
  int N;                      // nombre de sommets du réseau
  struct liste_chainee **tab; // attention c'est un tableau de pointeurs
  int source;                 // la source du réseau
  int puits;                  // le puit du réseau
};

//-----------------------Prototypes des fonctions-----------------------//

//------------------------Clear liste successeurs-----------------------//
//                                                                      //
//  Permet de libérer l'espace occupé par une liste de successeurs      //
//----------------------------------------------------------------------//
extern void clear_liste_succ(struct liste_succ *l);

//------------------------Init liste successeurs------------------------//
//                                                                      //
//  Permet d'initialiser une liste de successeurs vide avec N sommets,  //
//                 le sommet source et le sommet puits                  //
//                     et de la retourner.                              //
//----------------------------------------------------------------------//
extern struct liste_succ *init_liste_succ(int N, int source, int puits);

#endif
