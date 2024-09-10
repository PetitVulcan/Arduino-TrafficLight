# Feu de signalisation avec Arduino

![Vue 3D du Feu Tricolor](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/TrafficLight-1.png)

![Vue 3D du Feu Tricolor](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/TrafficLight.png)![image](https://github.com/user-attachments/assets/c27b71cc-7e14-4479-8527-98cde31b5d3e)


Ce projet simule un feu tricolore avec une carte Arduino. Il utilise la fonction `millis()` pour gérer les transitions de manière non bloquante.

## Fonctionnalités

- Simulation d'un feu tricolore avec des LEDs.
- Utilisation de `millis()` pour un timing non bloquant.
- Facilement configurable pour ajuster les délais de chaque signal.
- Le projet s'appuie sur la librairie TraficLight et ne gere que des instances de feu issues de cette librairie.

## Matériel nécessaire

- Arduino Nano ou similaire
- 6 LEDs (2 rouges, 2 jaunes, 2 vertes)
- Résistances (150Ω)
- Breadboard et fils de connexion

## Schéma de câblage
Feu1
- LED orange : Broche 2
- LED verte : Broche 3
- LED rouge : Broche 4

Feu2
- LED orange : Broche 8
- LED verte : Broche 9
- LED rouge : Broche 10

## Fichier pour impréssion 3D
[![Aperçu du modèle 3D - Light Stand](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/LightStand.png)](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/LightStand.stl)

[![Aperçu du modèle 3D - Pole](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/Pole.png)](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/Pole.stl)

[![Aperçu du modèle 3D - Head](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/head.png)](https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/head.stl)
![image](https://github.com/user-attachments/assets/f5f2721b-ce85-4d4f-a4dc-558c2def58a2)

## Code

Voici le code utilisé pour gérer le feu tricolore :

```cpp
// Definir les pins pour les LED des deux feux tricolores
TrafficLight road1(2, 3, 4, true);  // Rue 1
TrafficLight road2(8, 9, 10, true); // Rue 2

// Duree des differentes phases
const int greenTime = 30000; // duree pour le vert
const int orangeTime = 5000; // duree pour l'orange
const int redTime = 30000;   // duree où les deux rues sont au rouge
const int pauseTime = 3000;  // 3 secondes où les deux rues sont au rouge

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
- Ouvrez le fichier TrafficLight.cpp dans l'IDE VsCode.
- Téléversez le code sur votre carte Arduino.

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
