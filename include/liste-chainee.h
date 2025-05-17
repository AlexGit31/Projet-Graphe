#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H
//-------------------------Stucture de maillon-------------------------//
//                                                                     //
// Sturcture de maillon utilisée pour la structure de liste chainée    //
//                                                                     //
// sommet   : indice du sommet du graphe, l'indexage                   //
//            des sommets commence à zero                              //
//                                                                     //
// capacite : capacite du maillon, cette capacité est celle de l'arc   //
//            entre le sommet d'origine et le sommet du maillon        //
//                                                                     //
// flow     : flow du maillon, ce flow correspond au flow de l'arc     //
//            entre le sommet d'origine et le sommet du maillon        //
//                                                                     //
// (c'est trois premier paramètres sont des entiers)                   //
//                                                                     //
// suivant  : pointeur vers le maillon suivant                         //
//---------------------------------------------------------------------//
struct maillon {
  int sommet;
  int capacite;
  int flow;
  struct maillon *suivant;
};

//--------------------Stucture de liste chainée------------------------//
//                                                                     //
//         Sturcture de liste chainée utilisée pour représenter        //
//             les successeurs d'un sommet dans le graphe,             //
//          ces successeurs sont représentés par des maillons          //
//                                                                     //
//                                                                     //
// tete     : pointeur vers le maillon tete de la liste chainée        //
//                                                                     //
// taille   : taille de la liste chainée                               //
//---------------------------------------------------------------------//
struct liste_chainee {
  struct maillon *tete;
  int taille;
};

//-----------------------Prototypes des fonctions-----------------------//

//----------------------------Clear maillon-----------------------------//
//                                                                      //
//  Permet de supprimer uniquement un maillon dans une liste chainée    //
//  donnée. Il est supposé que le maillon est contenu dans la liste.    //
//      L'espace occupé par le maillon est libérer.                     //
//----------------------------------------------------------------------//
extern void clear_maillon(struct liste_chainee *, struct maillon *);

//---------------------------Ajout tete---------------------------------//
//                                                                      //
//      Permet d'ajouter un maillon en tete d'une liste chainée.        //
//      Il suffit de donner en paramètres le sommet, la capacité        //
//        et le flow du nouveau maillon que l'on veut créer.            //
//                                                                      //
//      Il est supposé que le maillon n'existe pas dans le liste,       //
//                il n'effectue aucune vérification.                    //
//----------------------------------------------------------------------//
extern void ajout_tete(struct liste_chainee *, int sommet, int capacite,
                       int flow);

//------------------------Clear liste chainée---------------------------//
//                                                                      //
//    Permet de libérer l'espace occupé par une liste chainée           //
//    et celle de tous les maillons contenu dans la liste.              //
//----------------------------------------------------------------------//
extern void clear_liste_chainee(struct liste_chainee *);

//--------------------------Init liste chainée--------------------------//
//                                                                      //
//    Permet d'initialiser une liste chainée vide et de la retourner.   //
//----------------------------------------------------------------------//
extern struct liste_chainee *init_liste_chainee();

//-------------------------Imprimer liste chainée-----------------------//
//                                                                      //
//              Fonction d'affichage d'une liste chainée,               //
//              affiche les maillons contenu dans la liste.             //
//              (L'affichage se fait dans l'ordre inverse)              //
//----------------------------------------------------------------------//
extern void imprimer_liste_chainee(struct liste_chainee *);

// Pour l'instant cette fonction n'est pas utilisée, elle risque d'être
// supprimée
extern void init_maillon(struct maillon *m, int sommet, int capacite, int flow);

//-------------------------Enfiler et defiler---------------------------//
//                                                                      //
//      Pour l'algorithme shortestPath pour utilisons une File          //
//            qui est aussi implémentée par une liste chainée.           //
//                                                                      //
//  Enfiler : permet d'ajouter sommet à la File l.                      //
//                                                                      //
//  Defiler : permet de supprimer le premier sommet de la File l.       //
//----------------------------------------------------------------------//
extern void enfiler(struct liste_chainee *l, int sommet);

extern int defiler(struct liste_chainee *l);

#endif
