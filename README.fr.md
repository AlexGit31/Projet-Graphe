# Projet Graphe — Algorithme de Flot Maximum

Ce projet en langage C implémente un algorithme de flot maximum dans un réseau
en utilisant un **graphe d’écart (graphe résiduel)**.
Le programme lit un fichier d’entrée au format **DIMACS**,
construit le graphe correspondant, et calcule un flot maximal
entre une source et un puits à l’aide d’un algorithme basé sur
la recherche de chemins augmentants.

## ⚙️ Compilation

Ce projet peut être compilé à l'aide de `gcc` :

```bash
gcc main.c src/\*.c -Iinclude -o graphe -Wall -Wextra
```

## 📚 Utilisation

L’exécutable graphe s’utilise de la façon suivante :

```bash
./graphe [fichier dimacs] [source] [puits]
```

    •	<fichier.dimacs> : Fichier d’entrée contenant la définition du graphe au format DIMACS.
    •	[affichage_etapes] (optionnel) :
    •	"true" ou "1" pour activer l’affichage des étapes intermédiaires.
    •	Sinon, l’algorithme s’exécute en mode silencieux.

## 📄 Format d’entrée

Le fichier DIMACS doit respecter le format standard suivant :

```text
c commentaire
p max N M         # N sommets, M arcs
n <num> s|t       # s = source, t = puits
a u v c           # arc de u vers v de capacité c
a ...
```

## 📝 Exemples

```text
p max 4 5
n 1 s
n 4 t
a 1 2 10
a 1 3 5
a 2 4 10
a 3 2 15
a 3 4 10
```

## 🧪 Débogage et affichage

Utilisez le deuxième argument "true" pour :

    • Visualiser les structures internes du graphe (listes de successeurs)
    • Suivre les étapes de mise à jour des flots
    • Aider au débogage ou à la compréhension pédagogique de l'algorithme
