# Feu de signalisation avec Arduino

<table>
  <tr>
    <td>
      <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/TrafficLight.png" alt="Aperçu du modèle 3D" height="600"/>
    </td>
    <td>
     <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/TrafficLight-1.png" alt="Aperçu du modèle 3D" height="600"/>
    </td>
  </tr>
</table>


Ce projet simule un feu tricolore avec une carte Arduino. Il utilise la fonction `millis()` pour gérer les transitions de manière non bloquante.

## Fonctionnalités

- Simulation d'un feu tricolore avec des LEDs.
- Utilisation de `millis()` pour un timing non bloquant.
- Facilement configurable pour ajuster les délais de chaque phase du cycle d'un feu tricolor.
- La librairie [TraficLight](https://github.com/PetitVulcan/ArduinoLibs-TrafficLight) permet de créer des instances de feu et d'organiser la syncronisation des feux d'un carrefour entre deux rues.

## Matériel nécessaire
<table>
  <tr>
    <td>
      <b>Qt</b>
    </td>
    <td>
     <b>Désignation</b>
    </td>
  </tr>
  <tr>
    <td>
      1
    </td>
    <td>
     Arduino Uno (ou similaire)
    </td>
  </tr>
   <tr>
    <td>
      12
    </td>
    <td>
     LEDs (4 rouges, 4 jaunes, 4 vertes)
    </td>
  </tr>
   <tr>
    <td>
      6
    </td>
    <td>
     Résistances (150Ω)
    </td>
  </tr>
   <tr>
    <td>
      1
    </td>
    <td>
     Breadboard 
    </td>
  </tr>
   <tr>
    <td>
      20
    </td>
    <td>
     Fils de connexion 
    </td>
  </tr>
</table>

## Schéma de câblage
<table>
  <tr>
    <td>
      <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/Pictures/ElectricalSchematic.png" alt="Scéma Electrique" height="400"/>
    </td>
    <td>
     <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/Pictures/WiringDiagram.png" alt="Aperçu du modèle 3D" height="400"/>
    </td>
  </tr>
</table>

Rue 1
- LED orange : Broche 3
- LED verte : Broche 4
- LED rouge : Broche 5

Rue 2
- LED orange : Broche 8
- LED verte : Broche 9
- LED rouge : Broche 10

## Fichier pour impréssion 3D

<table>
  <tr>
    <td>
      <a href="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/LightStand.stl">
        <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/LightStand.png" alt="Aperçu du modèle 3D - Light Stand" height="400"/>
      </a>
    </td>
    <td>
      <a href="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/Pole.stl">
         <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/Pole.png" alt="Aperçu du modèle 3D - Pole" height="400"/>
      </a>
    </td>
     <td>
      <a href="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/head.stl">
         <img src="https://github.com/PetitVulcan/Arduino-TrafficLight/blob/main/3D/stl/head.png" alt="Aperçu du modèle 3D" height="400"/>
      </a>
    </td>
  </tr>
</table>


## Code

Voici le code utilisé pour gérer le feu tricolore :

```cpp
// Definir les pins pour les LED des deux feux tricolores et les logs d'état dans le moniteur serie
TrafficLight road1(3, 4, 5, true);  // Rue 1
TrafficLight road2(8, 9, 10, true); // Rue 2

// Duree des differentes phases
const int greenTime = 30000; // duree pour le vert
const int orangeTime = 5000; // duree pour l'orange
const int redTime = 30000;   // duree pour le rouge
const int pauseTime = 3000;  // duree d'attente où les deux rues sont au rouge

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
