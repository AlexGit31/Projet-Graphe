// Stucture de maillon

struct maillon {
  int sommet;
  int capacite;
  int flow;
  struct maillon *suivant;
};

// Stucture de liste chainée

struct liste_chainee {
  struct maillon *tete;
  int taille;
};

extern void clear_maillon(struct liste_chainee *, struct maillon *);

extern void ajout_tete(struct liste_chainee *, int sommet, int capacite,
                       int flow);

extern void clear_liste_chainee(struct liste_chainee *);

extern struct liste_chainee *init_liste_chainee();

extern void imprimer_liste_chainee(struct liste_chainee *);

extern void init_maillon(struct maillon *m, int sommet, int capacite, int flow);

extern void enfiler(struct liste_chainee *l, int sommet);

extern int defiler(struct liste_chainee *l);
