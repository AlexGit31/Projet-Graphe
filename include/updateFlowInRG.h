#ifndef UPDATEFLOWINRG_H
#define UPDATEFLOWINRG_H

#include "liste-successeurs.h"

//-------------------------updateFlowInRG-------------------------//
//                                                                //
// Action qui met à jour le flux dans le graphe résiduel          //
// (implémenté par une liste de successeurs) à partir du chemin   //
// augmentant chemin (implémenté par une liste chainée)           //
// et de la capacité m que l'on veut augmenter.                   //
//----------------------------------------------------------------//
extern void updateFlowInRG(struct liste_succ *RG, struct liste_chainee *chemin,
                           int m);

#endif
