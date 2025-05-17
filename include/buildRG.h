#if !defined(buildRG_H)
#define buildRG_H

#include "liste-successeurs.h"

//------------------------buildRG-----------------------//
// Fonction qui permet de construire le graphe d'écart  //
//                      d'un réseau.                    //
//                                                      //
// Remarque : lors de l'algorithme de DINIC,            //
//  l'initialisation du graphe d'écart se fait à        //
//  partir d'un réseau ayant pour flow null.            //
//  Mais la fonction buildRG fonctionne également       //
//  si le flow n'est initialement pas null              //
//------------------------------------------------------//
struct liste_succ *buildRG(struct liste_succ *reseau);

#endif
