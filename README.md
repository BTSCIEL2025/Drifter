# Projet Robot Autonome/Téléguidé

## Description du Projet

Ce projet consiste à développer un robot qui peut être contrôlé de deux manières : en autonomie ou via téléguidage Bluetooth. En mode autonome, le robot est capable de détecter la lumière, qui représente un feu, et de se diriger automatiquement vers cette source lumineuse. Lorsqu'il s'approche suffisamment du feu, il active une petite pompe à eau pour éteindre le feu. Le robot peut également être contrôlé manuellement à l'aide d'une manette via Bluetooth.

## Composants Principaux

- **Arduino**: Cerveau du robot pour le contrôle des fonctionnalités.
- **Petit écran **: Affiche les informations et les menus.
- **Capteurs de distance**: Détectent les obstacles autour du robot.
- **Capteurs de lumière**: Détectent les sources lumineuses.
- **4 roues motorisées**: Permettent le mouvement du robot.
- **Petits boutons**: Utilisés pour naviguer dans le menu principal.

## Fonctionnalités

- **Mode Autonomie**: Le robot navigue de manière autonome en détectant et en se dirigeant vers les sources de lumière.
- **Mode Téléguidé**: Contrôle du robot via une manette Bluetooth pour une navigation manuelle.
- **Mode Diagnostic**: Permet aux utilisateurs de vérifier le fonctionnement des capteurs et des systèmes embarqués.

## Menu Principal

Le menu principal affiché sur l'écran permet de choisir entre les modes Autonomie, Téléguidage et Diagnostic. Il est accessible via les petits boutons sur le robot.

## Installation

### Matériel requis

Assurez-vous d'avoir tous les composants listés ci-dessus. Les schémas de montage seront fournis dans le dossier `docs`.

### Configuration du logiciel

1. Installez l'IDE Arduino sur votre ordinateur.
2. Clonez ce dépôt GitHub.
3. Ouvrez le sketch Arduino fourni dans le dossier `src`.
4. Téléversez le sketch sur votre Arduino.

## Utilisation

1. Allumez le robot.
2. Utilisez les boutons pour naviguer dans le menu principal et sélectionner le mode désiré.
3. En mode téléguidé, utilisez la manette Bluetooth pour contrôler le robot.

- [BTS CIEL 2025]
