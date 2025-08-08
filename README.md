# 🎮 so_long

Projet graphique de l'école 42 utilisant la bibliothèque **MiniLibX**.  
Le but est de créer un petit jeu 2D où le joueur doit collecter tous les objets sur la carte avant de rejoindre la sortie.

---

## 📚 Description

`so_long` charge une carte `.ber` et affiche un environnement 2D.  
Le joueur peut se déplacer, collecter des objets, éviter des obstacles et atteindre la sortie.  
Une version **bonus** ajoute des ennemis mobiles et des animations.

---

## 🗺️ Format de la carte

La carte doit être au format `.ber` et respecter les règles suivantes :
- Rectangle
- Encadrée de murs (`1`)
- Contient au moins :
  - 1 sortie (`E`)
  - 1 joueur (`P`)
  - 1 collectible (`C`)

### Symboles :
| Symbole | Signification |
| ------- | ------------- |
| `1` | Mur |
| `0` | Sol |
| `P` | Position de départ |
| `C` | Collectible |
| `E` | Sortie |
| `M` | Ennemi (bonus) |

---

## ⌨️ Contrôles

| Touche | Action |
| ------ | ------ |
| `↑` / `W` | Haut |
| `↓` / `S` | Bas |
| `←` / `A` | Gauche |
| `→` / `D` | Droite |
| `ESC` | Quitter le jeu |

---

## ⚙️ Compilation

```bash
make        # Compile la version obligatoire
make bonus  # Compile la version bonus
make clean  # Supprime les fichiers objets
make fclean # Supprime objets et exécutable
make re     # Recompile tout
