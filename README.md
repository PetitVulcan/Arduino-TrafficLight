# Feu de signalisation avec Arduino

Ce projet simule un feu tricolore avec une carte Arduino. Il utilise la fonction `millis()` pour gérer les transitions de manière non bloquante.

## Fonctionnalités

- Simulation d'un feu tricolore avec des LEDs.
- Utilisation de `millis()` pour un timing non bloquant.
- Facilement configurable pour ajuster les délais de chaque signal.

## Matériel nécessaire

- Arduino Uno ou similaire
- 3 LEDs (rouge, jaune, vert)
- Résistances (220Ω)
- Breadboard et fils de connexion

## Schéma de câblage
Feu1
- LED rouge : Broche 2
- LED jaune : Broche 3
- LED verte : Broche 4
Feu2
- LED rouge : Broche 8
- LED jaune : Broche 9
- LED verte : Broche 10
  
- GND : Connecter les GND des LEDs à la broche GND de l’Arduino.

## Code

Voici le code utilisé pour gérer le feu tricolore :

```cpp
// Definir les pins pour les LED des deux feux tricolores
TrafficLight road1(2, 3, 4, true);  // Rue 1
TrafficLight road2(8, 9, 10, true); // Rue 2

void setup()
{
  Serial.begin(9600); // Initialisation du moniteur serie

  // Initialisation et test des feux Tricolor
  road1.init();
  road2.init();
  // Extinction de tous les feux
  allOff();
}

void loop()
{
  road1.runIntersectionCycle(road1, road2, greenTime, orangeTime, redTime, pauseTime);
}

```

## Installation
Clonez ce dépôt :
```bash
git clone https://github.com/PetitVulcan/Arduino-TrafficLight.git
```
1-Ouvrez le fichier TrafficLight.ino dans l'IDE Arduino.
2-Téléversez le code sur votre carte Arduino.

## Contribution
Les contributions sont les bienvenues. Pour contribuer :

Forkez ce dépôt.
Créez une branche pour vos modifications :
```bash
git checkout -b ma-branche
```

Faites vos changements et validez-les :
```bash
git commit -m "Ajout d'une nouvelle fonctionnalité"
```

Poussez votre branche :
```bash
git push origin ma-branche
```
Ouvrez une pull request pour révision.

## Licence
Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.
