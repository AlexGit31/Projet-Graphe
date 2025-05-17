#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "liste-successeurs.h"

//-----------------------shortestPath---------------------------//
// Fonction qui permet de trouver le plus court chemin          //
// en nombre d'arcs dans un graphe residuel.                    //
// Le chemin commence à la source et finit au puits             //
//                                                              //
// Rappel : le source et le puits sont des informations         //
// stockées dans la structure du graphe résiduel.               //
//                                                              //
// Cette fonction prend en argument une liste de successeurs    //
// qui implémente un graphe résiduel et retourne une liste      //
// chainée qui implémente le chemin.                            //
//---------------------------------------------------------------
extern struct liste_chainee *
shortestPath(struct liste_succ *RG); // RG un graphe résiduel

#endif
