#ifndef BUILDGRAPH_H
#define BUILDGRAPH_H

#include "liste-successeurs.h"

//-----------------------buildGraph----------------------//
//                                                       //
//  Fonction qui permet de construire un graphe à partir //
//  d'un fichier DIMACS.                                 //
//                                                       //
//  Le graphe est en fait un réseau,                     //
//  il est représenté par une liste de successeurs.      //
//-------------------------------------------------------//
extern struct liste_succ *buildGraph(char *file_name);

#endif
