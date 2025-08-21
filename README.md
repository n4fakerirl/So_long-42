# so_long - 42

## 📚 Description

`so_long` est un projet graphique de l'école 42 qui utilise la bibliothèque **MiniLibX**.  
Le but est de créer un petit jeu 2D où le joueur doit ramasser tous les collectibles et atteindre la sortie, tout en respectant les règles de la carte.  

Une version **bonus** ajoute des ennemis et des animations et un compteur de mouvements sur la fenêtre.

---

## 📦 Objectifs

* Charger et vérifier une carte au format `.ber`
* Afficher une map 2D avec des sprites
* Gérer les déplacements du joueur et la collecte des objets
* Bonus : animations et ennemis

---

## 🔁 Symboles de la carte

| Symbole | Signification         |
| ------- | --------------------- |
| `1`     | Mur                   |
| `0`     | Sol                   |
| `P`     | Position du joueur    |
| `C`     | Collectible           |
| `E`     | Sortie                |
| `M`     | Ennemi (bonus)        |

---

## ⌨️ Contrôles

| Touche | Action         |
| ------ | -------------- |
| `W ou ↑`  | Haut           |
| `S ou ↓`  | Bas            |
| `A ou ←`  | Gauche         |
| `D ou →`  | Droite         |
| `ESC`  | Quitter le jeu |

---

## ⚙️ Compilation

| Commande      | Description                                 |
| ------------- | ------------------------------------------- |
| `make`        | Compile `so_long`                          |
| `make bonus`  | Compile la version bonus                   |
| `make clean`  | Supprime les fichiers objets (`.o`)         |
| `make fclean` | Supprime objets et exécutable              |
| `make re`     | Nettoie puis recompile entièrement          |

---

## 🚀 Exemple d'exécution

```bash
./so_long maps/map1.ber || ./so_long_bonus bonus/maps/map4.ber
```
---

## 🖼️ Note du projet

<p align="center">
  <img width="199" height="169" alt="image" src="https://github.com/user-attachments/assets/0f81d37f-0483-4001-948e-bc940ce6b006" />
</p>

---

## 🫐 Auteur

* Océane (ocviller)
* Projet réalisé à 42 Paris, 2025
