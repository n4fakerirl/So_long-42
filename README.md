# so\_long - 42

## 📚 Description

`so_long` est un projet graphique de l'école 42 qui consiste à créer un petit jeu en 2D avec la librairie graphique MiniLibX. L'objectif est de déplacer un personnage sur une carte, récupérer tous les objets (collectibles), et atteindre la sortie pour gagner. Le projet permet d'apprendre à gérer des fichiers, des entrées clavier, une boucle d'événement, ainsi que les bases du rendu graphique.

---

## 🏠 Objectifs

* Charger une carte à partir d'un fichier `.ber`
* Valider que la carte est rectangulaire, encadrée de murs, contient une sortie, un joueur et des collectibles
* Implémenter les déplacements du joueur avec les touches WASD
* Gérer l'affichage en 2D de chaque tuile (sol, mur, joueur, collectible, sortie)
* Fermer correctement la fenêtre avec la croix ou la touche `ESC`
* Optionnel : ajouter des ennemis, un compteur de pas, des animations...

---

## 🎮 Fonctionnement

* Le programme lit et analyse le fichier de carte
* Il génère une fenêtre en pixel art via MiniLibX
* Chaque déplacement du joueur met à jour la fenêtre
* Quand tous les collectibles sont ramassés, la sortie devient accessible

---

## ⚙️ Compilation

| Commande      | Description                         |
| ------------- | ----------------------------------- |
| `make`        | Compile le jeu avec MiniLibX        |
| `make clean`  | Supprime les fichiers objets (`.o`) |
| `make fclean` | Supprime les objets et l'exécutable |
| `make re`     | Recompile proprement le projet      |

---

## 🖼️ Note du projet

---

## 🥐 Auteur

* Océane (ocviller)
* Projet réalisé à 42 Paris, 2025
