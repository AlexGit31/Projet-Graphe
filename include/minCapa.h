#ifndef MINCAPA_H
#define MINCAPA_H

#include "liste-successeurs.h"

//------------------------------Fonction minCapa-----------------------------//
//                                                                           //
//     Fonction qui renvoie la capacité minimale du chemin augmentant à      //
//                  partir d'un chemin dans un graphe d'écart.               //
//---------------------------------------------------------------------------//
extern int minCapa(struct liste_succ *RG, struct liste_chainee *chemin);

#endif
