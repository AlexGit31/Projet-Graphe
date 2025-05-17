#ifndef UPDATEFLOWINNET_H
#define UPDATEFLOWINNET_H

#include "liste-successeurs.h"

//-----------------updateFlowInNet-----------------//
//                                                 //
// Action qui permet de mettre à jour le flow dans //
// le réseau originel à partir du graphe résiduel. //
//-------------------------------------------------//
extern void updateFlowInNet(struct liste_succ *reseau, struct liste_succ *RG);

#endif
